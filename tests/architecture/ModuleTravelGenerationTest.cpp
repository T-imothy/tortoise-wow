#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>
using uint32 = std::uint32_t;
#define CHECK(x) do { if (!(x)) { std::cerr << __LINE__ << ": " #x << '\n'; std::exit(1); } } while (0)
std::vector<std::string> events;
struct { bool generateTravelNodes = false; } sPlayerbotAIConfig;
struct { void LoadMapTransfers() { events.push_back("transfers"); } } sTravelMgr;
struct { template<class... T> void outError(T...) { events.push_back("pending"); }
    template<class... T> void outString(T...) {} } sLog;
struct WorldPosition
{
    unsigned map = 0; float x = 0, y = 0, z = 0; bool valid = false;
    WorldPosition() = default;
    WorldPosition(unsigned m, float a, float b, float c) : map(m),x(a),y(b),z(c),valid(true) {}
    explicit operator bool() const { return valid; }
    unsigned getMapId() const { return map; }
    float getX() const { return x; } float getY() const { return y; } float getZ() const { return z; }
    float distance(WorldPosition const& b) const { return std::sqrt((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y)+(z-b.z)*(z-b.z)); }
};
struct TerrainInfo { bool IsInWater(float x, float, float) const { return x >= 10; } } terrain;
struct { TerrainInfo* LoadTerrain(unsigned map) { return map == 99 ? nullptr : &terrain; } } sTerrainMgr;
enum class TravelNodePathType { walk, flightPath };
struct TravelNodePath
{
    float distance = 500, swimDistance = 400;
    std::vector<WorldPosition> path;
    bool calculated = false, fail = false; unsigned calls = 0;
    TravelNodePathType type = TravelNodePathType::walk;
    TravelNodePathType getPathType() const { return type; }
    bool GetCalculated() const { return calculated; }
    void calculateCost() { ++calls; if (!fail) calculated = true; }
    bool recalculateGeometry();
};
struct TravelNode
{
    std::map<TravelNode*, TravelNodePath*> links;
    auto GetLinks() { return &links; }
    void hasRouteTo(TravelNode* n) { CHECK(n == this); events.push_back("coverage"); }
};
struct TravelNodeMap
{
    bool hasToGen = false, hasToFullGen = false, hasToSave = false, fail = false;
    TravelNode node;
    std::vector<TravelNode*> m_nodes;
    auto GetNodes() { return m_nodes; }
    void generateNodes() { events.push_back("nodes"); m_nodes.push_back(&node); }
    void calcMapOffset() { events.push_back("offsets"); }
    void generatePaths(bool helpers) { CHECK(!helpers); events.push_back("walking"); if (fail) throw std::runtime_error("test failure"); }
    void generateTaxiPaths() { events.push_back("taxi"); }
    void generateAll(); void calculatePathCosts();
};
#include "ModuleGenerateAll.inc"
#include "ModulePathCosts.inc"
#include "ModuleGeometry.inc"
int main()
{
    TravelNodeMap map;
    map.generateAll(); CHECK(events.empty());
    map.hasToFullGen = true; map.generateAll(); CHECK(events.empty() && map.hasToFullGen);
    map.m_nodes.push_back(&map.node);
    map.generateAll();
    CHECK((events == std::vector<std::string>{"offsets","transfers","pending","taxi","coverage"}));
    CHECK(map.hasToFullGen && !map.hasToSave);
    events.clear(); map.hasToFullGen = false;
    map.generateAll();
    CHECK((events == std::vector<std::string>{"offsets","transfers","taxi","coverage"}));
    events.clear(); sPlayerbotAIConfig.generateTravelNodes = true; map.hasToGen = true; map.fail = true;
    try { map.generateAll(); CHECK(false); } catch (std::runtime_error const&) {}
    CHECK(map.hasToGen && !map.hasToSave);
    CHECK(std::find(events.begin(),events.end(),"taxi") == events.end());
    events.clear(); map.fail = false; map.generateAll();
    CHECK((events == std::vector<std::string>{"offsets","transfers","walking","taxi","coverage"}));
    CHECK(!map.hasToGen && map.hasToSave);
    events.clear(); TravelNodeMap fresh; fresh.hasToFullGen = true; fresh.generateAll();
    CHECK((events == std::vector<std::string>{"nodes","offsets","transfers","walking","taxi","coverage"}));
    CHECK(!fresh.hasToFullGen && fresh.hasToSave);
    TravelNode a,b,c; TravelNodePath walk,flight,done;
    flight.type = TravelNodePathType::flightPath; done.calculated = true;
    map.node.links = {{&a,&walk},{&b,&flight},{&c,&done}};
    map.calculatePathCosts(); CHECK(walk.calls == 1 && flight.calls == 0 && done.calls == 0);
    map.calculatePathCosts(); CHECK(walk.calls == 1);
    walk.calculated = false; walk.fail = true;
    try { map.calculatePathCosts(); CHECK(false); } catch (std::runtime_error const&) {}
    CHECK(walk.calls == 2); // Failed work cannot recurse forever.
    TravelNodePath geometry;
    geometry.path = {{0,1,0,0},{0,4,4,0},{0,10,12,0},{1,10000,0,0},{1,10003,4,0}};
    CHECK(geometry.recalculateGeometry());
    CHECK(std::fabs(geometry.distance - 20.1f) < .001f);
    CHECK(std::fabs(geometry.swimDistance - 15.f) < .001f);
    CHECK(!geometry.recalculateGeometry());
    geometry.path = {{99,1,0,0},{99,4,4,0}};
    CHECK(geometry.recalculateGeometry()); CHECK(geometry.swimDistance == 0);
    CHECK(std::fabs(geometry.distance - 5.1f) < .001f);
    std::cout << "Module travel startup gates, failure propagation, bounded costs and cached geometry passed\n";
}
