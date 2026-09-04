
#include "playerbot/playerbot.h"
#include "AreaTriggerAction.h"
#include "playerbot/PlayerbotAIConfig.h"

using namespace ai;

bool ReachAreaTriggerAction::Execute(Event& event)
{
    Player* requester = event.getOwner() ? event.getOwner() : GetMaster();
    uint32 triggerId;

    if (ai->IsRealPlayer()) //Do not trigger own area trigger.
        return false;

    WorldPacket p(event.getPacket());
    p.rpos(0);
    p >> triggerId;

    AreaTriggerEntry const* atEntry = sAreaTriggerStore.LookupEntry(triggerId);
    if(!atEntry)
        return false;

    AreaTrigger const* at = sObjectMgr.GetAreaTrigger(triggerId);
    if (!at)
    {
        WorldPacket p1(CMSG_AREATRIGGER);
        p1 << triggerId;
        p1.rpos(0);
        bot->GetSession()->HandleAreaTriggerOpcode(p1);

        return true;
    }

    if (bot->GetMapId() != atEntry->mapid || bot->GetDistance(atEntry->x, atEntry->y, atEntry->z) > sPlayerbotAIConfig.sightDistance)
    {
        ai->TellError(requester, "I won't follow: too far away");
        return true;
    }

    if (::IsPointInAreaTriggerZone(atEntry, bot->GetMapId(), bot->GetPositionX(),
        bot->GetPositionY(), bot->GetPositionZ(), 0.5f))
    {
        WorldPacket triggerPacket(CMSG_AREATRIGGER);
        triggerPacket << triggerId;
        triggerPacket.rpos(0);
        bot->GetSession()->HandleAreaTriggerOpcode(triggerPacket);
        return true;
    }

    // Use the real navmesh path to the official trigger. Never accept a
    // straight-line shortcut through instance geometry; an incomplete path is
    // valid only when its actual endpoint lies inside the trigger volume.
    PathFinder path(bot);
    if (!path.calculate(atEntry->x, atEntry->y, atEntry->z, false, false))
    {
        context->GetValue<LastMovement&>("last area trigger")->Get().clear();
        ai->StopMoving();
        ai->TellError(requester, "I can't safely reach the instance portal");
        return true;
    }

    PathType const pathType = path.getPathType();
    PointsArray portalPath = path.getPath();
    Vector3 const pathEnd = path.getActualEndPosition();
    const bool safePath = !(pathType & (PATHFIND_NOPATH | PATHFIND_SHORTCUT | PATHFIND_NOT_USING_PATH)) &&
        portalPath.size() >= 2 && ::IsPointInAreaTriggerZone(atEntry, bot->GetMapId(),
            pathEnd.x, pathEnd.y, pathEnd.z, 0.5f);
    if (!safePath)
    {
        context->GetValue<LastMovement&>("last area trigger")->Get().clear();
        ai->StopMoving();
        ai->TellError(requester, "I can't safely reach the instance portal");
        return true;
    }

    float distance = 0.0f;
    for (size_t i = 1; i < portalPath.size(); ++i)
        distance += (portalPath[i] - portalPath[i - 1]).magnitude();

    MotionMaster& mm = *bot->GetMotionMaster();
#ifdef MANGOSBOT_TWO
    mm.MovePath(portalPath, FORCED_MOVEMENT_RUN, false);
#else
    mm.MovePath(portalPath, FORCED_MOVEMENT_RUN, false, false);
#endif
    const float duration = 1000.0f * distance / bot->GetSpeed(MOVE_RUN) + sPlayerbotAIConfig.reactDelay;
    ai->TellError(requester, "Wait for me");
    SetDuration(duration);
    context->GetValue<LastMovement&>("last area trigger")->Get().lastAreaTrigger = triggerId;

    return true;
}



bool AreaTriggerAction::Execute(Event& event)
{
    LastMovement& movement = context->GetValue<LastMovement&>("last area trigger")->Get();

    uint32 triggerId = movement.lastAreaTrigger;
    movement.lastAreaTrigger = 0;

    // Module gate: while an exit-sensitive run owns this bot, a teleport
    // trigger underfoot must NOT be relayed (the consume above still clears
    // it so the trigger cannot fire later either). Non-teleport triggers are
    // not this action's business anyway - it returns before the relay for
    // those below.
    if (ai->IsAreaTriggerRelaySuppressed())
        return false;

    AreaTriggerEntry const* atEntry = sAreaTriggerStore.LookupEntry(triggerId);
    if(!atEntry)
        return false;

    AreaTrigger const* at = sObjectMgr.GetAreaTrigger(triggerId);
    if (!at)
        return true;

    WorldPacket p(CMSG_AREATRIGGER);
    p << triggerId;
    p.rpos(0);
    bot->GetSession()->HandleAreaTriggerOpcode(p);
    return true;
}
