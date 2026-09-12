#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#define CHECK(x) do { if (!(x)) { std::cerr << __LINE__ << ": " #x << '\n'; std::exit(1); } } while (0)
class Map; class PlayerbotAI;
struct WorldSession { bool network = false; bool HasNetworkTransport() const { return network; } bool IsHeadless() const { return !network; } } humanSession{true}, botSession;
struct WorldObject { float x = 0; bool world = true; bool IsInWorld() const { return world; } };
struct Camera { WorldObject* body = nullptr; WorldObject* GetBody() { return body; } };
struct GroupReference;
struct Group { GroupReference* first = nullptr; GroupReference* GetFirstMember() { return first; } };
struct Player : WorldObject
{
    Map* map = nullptr; WorldSession* session = &botSession; Camera camera;
    bool gm = false, visible = true, teleport = false; PlayerbotAI* ai = nullptr; Group* group = nullptr;
    WorldSession* GetSession() const { return session; }
    Map* GetMap() const { return map; } unsigned GetMapId() const;
    bool IsGameMaster() const { return gm; } bool IsGMVisible() const { return visible; }
    bool IsBeingTeleported() const { return teleport; }
    Camera& GetCamera() { return camera; } Group* GetGroup() { return group; }
};
struct Ref { Player* player; Player* getSource() const { return player; } };
class Map { public: unsigned id = 0; std::vector<Ref> players;
    unsigned GetId() const { return id; } auto const& GetPlayers() { return players; } };
unsigned Player::GetMapId() const { return map ? map->id : 999; }
struct GroupReference { Player* player; GroupReference* following = nullptr;
    Player* getSource() { return player; } GroupReference* next() { return following; } };
struct WorldPosition
{
    unsigned map; float x;
    WorldPosition(Player* p) : map(p->GetMapId()),x(p->x) {}
    WorldPosition(WorldObject* p) : map(0),x(p->x) {}
    unsigned GetMapId() const { return map; } float getVisibilityDistance() const { return 80; }
    float sqDistance(WorldPosition p) const { return (p.x-x)*(p.x-x); }
};
namespace ai { using WorldPosition = ::WorldPosition; }
struct { float reactDistance = 20; } sPlayerbotAIConfig;
class PlayerbotAI { public: Player* bot = nullptr; bool master = false;
    bool HasRealPlayerMaster() const { return master; }
    bool HasPlayerNearby(WorldPosition pos, float range);
    bool HasPlayerNearby(float range) { return HasPlayerNearby(WorldPosition(bot),range); }
};
struct PlayerbotAIStorage { static PlayerbotAIStorage& Instance() { static PlayerbotAIStorage s; return s; }
    PlayerbotAI* GetAI(Player* p) { return p ? p->ai : nullptr; } };
class BotPlayerAdapter { public: bool IsMachineDriven(Player const*); bool IsUpdateCritical(Player const*); };
#include "ModuleHumanInterest.inc"
#include "ModuleSchedulerTraits.inc"
int main()
{
    Map map, otherInstance; Player bot, observer, otherBot;
    bot.map = observer.map = otherBot.map = &map;
    PlayerbotAI ai; ai.bot = &bot; bot.ai = &ai;
    map.players = {{&bot},{&otherBot}};
    BotPlayerAdapter adapter;
    CHECK(adapter.IsMachineDriven(&bot)); CHECK(!adapter.IsMachineDriven(nullptr));
    CHECK(!adapter.IsMachineDriven(&otherBot));
    CHECK(!ai.HasPlayerNearby(100)); CHECK(!adapter.IsUpdateCritical(&bot));
    observer.session = &humanSession; observer.camera.body = &observer;
    observer.x = 99; map.players.push_back({&observer});
    CHECK(ai.HasPlayerNearby(100)); CHECK(adapter.IsUpdateCritical(&bot));
    observer.x = 101; CHECK(!ai.HasPlayerNearby(100));
    WorldObject viewpoint; viewpoint.x = 10; observer.camera.body = &viewpoint;
    CHECK(ai.HasPlayerNearby(100));
    observer.gm = true; observer.visible = false; CHECK(!ai.HasPlayerNearby(100));
    observer.visible = true; CHECK(ai.HasPlayerNearby(100));
    observer.map = &otherInstance; CHECK(!ai.HasPlayerNearby(100));
    observer.map = &map; observer.world = false; CHECK(!ai.HasPlayerNearby(100));
    observer.world = true; observer.session = nullptr; CHECK(!ai.HasPlayerNearby(100));
    observer.session = &botSession; CHECK(!ai.HasPlayerNearby(100));
    ai.master = true; CHECK(adapter.IsUpdateCritical(&bot)); ai.master = false;
    bot.teleport = true; CHECK(adapter.IsUpdateCritical(&bot)); bot.teleport = false;
    observer.session = &humanSession; observer.x = 500; observer.camera.body = &observer;
    GroupReference member{&observer}; Group group; group.first = &member; bot.group = &group;
    CHECK(adapter.IsUpdateCritical(&bot));
    observer.session = &botSession; CHECK(!adapter.IsUpdateCritical(&bot));
    bot.session = &humanSession; CHECK(!adapter.IsMachineDriven(&bot));
    CHECK(!adapter.IsUpdateCritical(&bot)); // A lingering AI cannot override human ownership.
    std::cout << "Module human interest, instance boundaries and native scheduling traits passed\n";
}
