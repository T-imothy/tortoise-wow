#include "scriptPCH.h"
#include "ScriptObjects.h"

#include <algorithm>
#include <vector>

enum MoonhoofCelebration
{
    QUEST_MOONHOOF_CELEBRATION       = 42085,

    NPC_ELDER_STARSTRIDER            = 63083,
    NPC_MOONHOOF_CELEBRATOR          = 63093,
    NPC_EMBODIMENT_OF_ANCESTORS      = 63202,

    SPELL_TARGETED_ARCANE_CHANNELING = 51187,

    TEXT_GATHER_MOONHOOF             = 2593100,
    TEXT_PREPARES_CELEBRATION        = 2593101,
    TEXT_CELEBRATOR_FIRST            = 2593102,
    TEXT_CELEBRATOR_LAST             = 2593104,
    TEXT_ANCESTOR_FIRST              = 2593105,
    TEXT_ANCESTOR_LAST               = 2593114,

    SUMMON_EVENT_LIFETIME            = 3 * MINUTE * IN_MILLISECONDS
};

enum MissingCaravans
{
    QUEST_THE_MISSING_CARAVANS       = 41970,

    MAP_KALIMDOR                     = 1,

    AREATRIGGER_SECOND_CARAVAN       = 5660,
    AREATRIGGER_THIRD_CARAVAN        = 5661,

    NPC_CREDIT_FIRST_CARAVAN         = 51691,
    NPC_CREDIT_SECOND_CARAVAN        = 51692,
    NPC_CREDIT_THIRD_CARAVAN         = 51693,

    FIRST_CARAVAN_CHECK_RADIUS       = 5
};

struct MoonwhisperPosition
{
    float x;
    float y;
    float z;
    float o;
};

static MoonwhisperPosition const firstCaravanPosition = { 8495.277344f, -5853.270996f, 0.196963f, 0.0f };

struct PendingCelebratorSpawn
{
    uint8 positionIndex;
    uint32 timer;
};

static MoonwhisperPosition const aCelebratorPositions[] =
{
    { 8313.31f, -5285.33f, 48.9957f, 5.5832f },
    { 8321.75f, -5288.21f, 48.9053f, 5.2376f },
    { 8314.87f, -5290.64f, 47.8030f, 5.8228f },
    { 8317.51f, -5298.32f, 46.5656f, 5.9995f },
    { 8307.52f, -5302.32f, 47.6486f, 6.2390f },
    { 8311.91f, -5302.39f, 47.3810f, 0.0304f },
    { 8317.24f, -5305.32f, 47.3404f, 0.1404f },
    { 8321.42f, -5309.38f, 47.65074f, 0.7569f }
};

static MoonwhisperPosition const ancestorPosition = { 8327.3f, -5299.56f, 46.6297f, 2.854f };

struct npc_elder_starstriderAI : public ScriptedAI
{
    npc_elder_starstriderAI(Creature* pCreature) :
        ScriptedAI(pCreature),
        m_eventTimer(0),
        m_originalNpcFlags(0),
        m_originalReactState(REACT_AGGRESSIVE),
        m_phase(0),
        m_spawnIndex(0),
        m_ancestorLineIndex(0),
        m_eventActive(false)
    {
        Reset();
    }

    ObjectGuid m_playerGuid;
    ObjectGuid m_ancestorGuid;
    std::vector<ObjectGuid> m_celebratorGuids;
    std::vector<PendingCelebratorSpawn> m_pendingCelebratorSpawns;

    uint32 m_eventTimer;
    uint32 m_originalNpcFlags;
    ReactStates m_originalReactState;
    uint8 m_phase;
    uint8 m_spawnIndex;
    uint8 m_ancestorLineIndex;
    bool m_eventActive;

    void Reset() override
    {
        if (m_eventActive)
            RestoreStarstrider();

        DespawnSummons();

        m_playerGuid.Clear();
        m_ancestorGuid.Clear();
        m_celebratorGuids.clear();
        m_pendingCelebratorSpawns.clear();
        m_eventTimer = 0;
        m_originalNpcFlags = m_creature->GetUInt32Value(UNIT_NPC_FLAGS);
        m_originalReactState = m_creature->GetReactState();
        m_phase = 0;
        m_spawnIndex = 0;
        m_ancestorLineIndex = 0;
        m_eventActive = false;
    }

    void AttackStart(Unit* /*pWho*/) override {}

    void StartEvent(Player* pPlayer)
    {
        if (m_eventActive)
            return;

        m_playerGuid = pPlayer->GetObjectGuid();
        m_originalNpcFlags = m_creature->GetUInt32Value(UNIT_NPC_FLAGS);
        m_originalReactState = m_creature->GetReactState();
        m_eventActive = true;
        m_phase = 1;
        m_eventTimer = 0;
        m_spawnIndex = 0;

        m_creature->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
        MakePassiveAndInvulnerable(m_creature);
        m_creature->MonsterYell(TEXT_GATHER_MOONHOOF);

        m_pendingCelebratorSpawns.clear();
        for (uint8 i = 0; i < sizeof(aCelebratorPositions) / sizeof(aCelebratorPositions[0]); ++i)
            m_pendingCelebratorSpawns.push_back({ i, urand(0, 15000) });

        std::sort(m_pendingCelebratorSpawns.begin(), m_pendingCelebratorSpawns.end(),
            [](PendingCelebratorSpawn const& left, PendingCelebratorSpawn const& right)
            {
                return left.timer < right.timer;
            });

        uint32 previousDelay = 0;
        for (PendingCelebratorSpawn& spawn : m_pendingCelebratorSpawns)
        {
            uint32 const absoluteDelay = spawn.timer;
            spawn.timer = absoluteDelay - previousDelay;
            previousDelay = absoluteDelay;
        }

        m_eventTimer = m_pendingCelebratorSpawns.empty() ? 0 : m_pendingCelebratorSpawns[0].timer;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_eventActive)
            return;

        if (m_eventTimer > uiDiff)
        {
            m_eventTimer -= uiDiff;
            return;
        }

        switch (m_phase)
        {
            case 1:
                SpawnCelebrators();
                break;
            case 2:
                SpawnAncestor();
                break;
            case 3:
                StartChanneling();
                break;
            case 4:
            case 5:
            case 6:
                SayRandomCelebratorLine();
                break;
            case 7:
                SayAncestorLine();
                break;
            case 8:
                BowAncestor();
                break;
            case 9:
                EndAncestor();
                break;
            case 10:
                DespawnNextCelebrator();
                break;
            default:
                FinishEvent();
                break;
        }
    }

    void SpawnCelebrators()
    {
        while (m_spawnIndex < m_pendingCelebratorSpawns.size())
        {
            MoonwhisperPosition const& pos = aCelebratorPositions[m_pendingCelebratorSpawns[m_spawnIndex].positionIndex];
            if (Creature* pCelebrator = m_creature->SummonCreature(NPC_MOONHOOF_CELEBRATOR, pos.x, pos.y, pos.z, pos.o, TEMPSUMMON_MANUAL_DESPAWN, SUMMON_EVENT_LIFETIME))
            {
                MakePassiveAndInvulnerable(pCelebrator);
                m_celebratorGuids.push_back(pCelebrator->GetObjectGuid());
            }

            ++m_spawnIndex;

            if (m_spawnIndex >= m_pendingCelebratorSpawns.size() || m_pendingCelebratorSpawns[m_spawnIndex].timer != 0)
                break;
        }

        if (m_spawnIndex >= m_pendingCelebratorSpawns.size())
        {
            m_creature->MonsterTextEmote(TEXT_PREPARES_CELEBRATION, nullptr);
            m_phase = 2;
            m_eventTimer = 8000;
            return;
        }

        m_eventTimer = m_pendingCelebratorSpawns[m_spawnIndex].timer;
    }

    void SpawnAncestor()
    {
        if (Creature* pAncestor = m_creature->SummonCreature(NPC_EMBODIMENT_OF_ANCESTORS, ancestorPosition.x, ancestorPosition.y, ancestorPosition.z, ancestorPosition.o, TEMPSUMMON_MANUAL_DESPAWN, SUMMON_EVENT_LIFETIME))
        {
            MakePassiveAndInvulnerable(pAncestor);
            m_ancestorGuid = pAncestor->GetObjectGuid();
        }

        m_phase = 3;
        m_eventTimer = 1000;
    }

    void StartChanneling()
    {
        if (Creature* pAncestor = GetAncestor())
            m_creature->CastSpell(pAncestor, SPELL_TARGETED_ARCANE_CHANNELING, false);

        m_phase = 4;
        m_eventTimer = 1000;
    }

    void SayRandomCelebratorLine()
    {
        if (Creature* pCelebrator = GetRandomCelebrator())
            pCelebrator->MonsterSay(urand(TEXT_CELEBRATOR_FIRST, TEXT_CELEBRATOR_LAST));

        ++m_phase;
        m_eventTimer = 1000;
    }

    void SayAncestorLine()
    {
        Creature* pAncestor = GetAncestor();
        if (!pAncestor)
        {
            FinishEvent();
            return;
        }

        if (m_ancestorLineIndex == 0)
        {
            pAncestor->MonsterSay(TEXT_ANCESTOR_FIRST);
            ++m_ancestorLineIndex;
            m_eventTimer = 10000;
            return;
        }

        uint32 const textId = TEXT_ANCESTOR_FIRST + m_ancestorLineIndex;
        if (textId == 2593107)
            pAncestor->MonsterTextEmote(textId, nullptr);
        else
            pAncestor->MonsterSay(textId);

        ++m_ancestorLineIndex;

        static uint32 const aLineDelays[] = { 10000, 10000, 5000, 15000, 10000, 15000, 10000, 15000, 8000 };
        if (m_ancestorLineIndex <= sizeof(aLineDelays) / sizeof(aLineDelays[0]))
            m_eventTimer = aLineDelays[m_ancestorLineIndex - 1];
        else
        {
            m_phase = 8;
            m_eventTimer = 8000;
        }
    }

    void BowAncestor()
    {
        if (Creature* pAncestor = GetAncestor())
            pAncestor->HandleEmote(EMOTE_ONESHOT_BOW);

        m_phase = 9;
        m_eventTimer = 10000;
    }

    void EndAncestor()
    {
        if (Creature* pAncestor = GetAncestor())
            pAncestor->DespawnOrUnsummon();

        m_ancestorGuid.Clear();
        m_creature->InterruptNonMeleeSpells(false, SPELL_TARGETED_ARCANE_CHANNELING);

        RandomizeCelebratorDespawnOrder();
        m_phase = 10;
        m_eventTimer = 1000;
    }

    void DespawnNextCelebrator()
    {
        while (!m_celebratorGuids.empty())
        {
            ObjectGuid guid = m_celebratorGuids.back();
            m_celebratorGuids.pop_back();

            if (Creature* pCelebrator = m_creature->GetMap()->GetCreature(guid))
            {
                pCelebrator->DespawnOrUnsummon();
                m_eventTimer = 1000;
                return;
            }
        }

        FinishEvent();
    }

    void FinishEvent()
    {
        if (Player* pPlayer = m_creature->GetMap()->GetPlayer(m_playerGuid))
        {
            if (pPlayer->GetQuestStatus(QUEST_MOONHOOF_CELEBRATION) == QUEST_STATUS_INCOMPLETE)
                pPlayer->CompleteQuest(QUEST_MOONHOOF_CELEBRATION);
        }

        RestoreStarstrider();
        DespawnSummons();

        m_playerGuid.Clear();
        m_ancestorGuid.Clear();
        m_celebratorGuids.clear();
        m_pendingCelebratorSpawns.clear();
        m_eventTimer = 0;
        m_phase = 0;
        m_spawnIndex = 0;
        m_ancestorLineIndex = 0;
        m_eventActive = false;
    }

    void MakePassiveAndInvulnerable(Creature* pCreature)
    {
        pCreature->SetReactState(REACT_PASSIVE);
        pCreature->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
        pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PLAYER | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NON_ATTACKABLE_2 | UNIT_FLAG_PACIFIED);
    }

    void RestoreStarstrider()
    {
        m_creature->SetUInt32Value(UNIT_NPC_FLAGS, m_originalNpcFlags);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PLAYER | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NON_ATTACKABLE_2 | UNIT_FLAG_PACIFIED);
        m_creature->SetReactState(m_originalReactState);
        m_creature->InterruptNonMeleeSpells(false, SPELL_TARGETED_ARCANE_CHANNELING);
    }

    Creature* GetAncestor()
    {
        return m_ancestorGuid ? m_creature->GetMap()->GetCreature(m_ancestorGuid) : nullptr;
    }

    Creature* GetRandomCelebrator()
    {
        std::vector<ObjectGuid> activeCelebrators;
        for (ObjectGuid const& guid : m_celebratorGuids)
        {
            if (m_creature->GetMap()->GetCreature(guid))
                activeCelebrators.push_back(guid);
        }

        if (activeCelebrators.empty())
            return nullptr;

        return m_creature->GetMap()->GetCreature(activeCelebrators[urand(0, uint32(activeCelebrators.size() - 1))]);
    }

    void RandomizeCelebratorDespawnOrder()
    {
        for (size_t i = 0; i < m_celebratorGuids.size(); ++i)
        {
            size_t const j = urand(uint32(i), uint32(m_celebratorGuids.size() - 1));
            std::swap(m_celebratorGuids[i], m_celebratorGuids[j]);
        }
    }

    void DespawnSummons()
    {
        if (Creature* pAncestor = GetAncestor())
            pAncestor->DespawnOrUnsummon();

        for (ObjectGuid const& guid : m_celebratorGuids)
        {
            if (Creature* pCelebrator = m_creature->GetMap()->GetCreature(guid))
                pCelebrator->DespawnOrUnsummon();
        }
    }
};

CreatureAI* GetAI_npc_elder_starstrider(Creature* pCreature)
{
    return new npc_elder_starstriderAI(pCreature);
}

bool QuestAccept_npc_elder_starstrider(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (!pPlayer || !pCreature || !pQuest || pQuest->GetQuestId() != QUEST_MOONHOOF_CELEBRATION)
        return false;

    if (npc_elder_starstriderAI* pAI = dynamic_cast<npc_elder_starstriderAI*>(pCreature->AI()))
        pAI->StartEvent(pPlayer);

    return true;
}

class player_moonwhisper_missing_caravans : public PlayerScript
{
    public:
        player_moonwhisper_missing_caravans() : PlayerScript("player_moonwhisper_missing_caravans", { PLAYERHOOK_ON_UPDATE }) {}

        void OnUpdate(Player* pPlayer, uint32 /*diff*/) override
        {
            if (!pPlayer || pPlayer->GetMapId() != MAP_KALIMDOR || !pPlayer->IsAlive() || pPlayer->IsGameMaster() || pPlayer->HasStealthAura())
                return;

            if (pPlayer->GetQuestStatus(QUEST_THE_MISSING_CARAVANS) != QUEST_STATUS_INCOMPLETE)
                return;

            if (pPlayer->GetPositionZ() < firstCaravanPosition.z - FIRST_CARAVAN_CHECK_RADIUS ||
                pPlayer->GetPositionZ() > firstCaravanPosition.z + FIRST_CARAVAN_CHECK_RADIUS)
                return;

            if (pPlayer->GetDistance2d(firstCaravanPosition.x, firstCaravanPosition.y) > FIRST_CARAVAN_CHECK_RADIUS)
                return;

            pPlayer->KilledMonsterCredit(NPC_CREDIT_FIRST_CARAVAN);
        }
};

class at_moonwhisper_missing_caravans : public AreaTriggerScript
{
    public:
        at_moonwhisper_missing_caravans() : AreaTriggerScript("at_moonwhisper_missing_caravans") {}

        bool OnTrigger(Player* pPlayer, AreaTriggerEntry const* pTrigger) override
        {
            if (!pPlayer || !pTrigger || !pPlayer->IsAlive() || pPlayer->IsGameMaster() || pPlayer->HasStealthAura())
                return false;

            if (pPlayer->GetQuestStatus(QUEST_THE_MISSING_CARAVANS) != QUEST_STATUS_INCOMPLETE)
                return false;

            switch (pTrigger->id)
            {
                case AREATRIGGER_SECOND_CARAVAN:
                    pPlayer->KilledMonsterCredit(NPC_CREDIT_SECOND_CARAVAN);
                    return true;
                case AREATRIGGER_THIRD_CARAVAN:
                    pPlayer->KilledMonsterCredit(NPC_CREDIT_THIRD_CARAVAN);
                    return true;
                default:
                    return false;
            }
        }
};

void AddSC_moonwhisper_coast()
{
    new player_moonwhisper_missing_caravans();
    new at_moonwhisper_missing_caravans();

    Script* pNewScript = new Script;
    pNewScript->Name = "npc_elder_starstrider";
    pNewScript->GetAI = &GetAI_npc_elder_starstrider;
    pNewScript->pQuestAcceptNPC = &QuestAccept_npc_elder_starstrider;
    pNewScript->RegisterSelf();
}
