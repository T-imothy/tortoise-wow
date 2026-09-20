"""MSVC native-fragment regressions for zero honor and bot mailbox dispatch."""
from pathlib import Path
import subprocess
import tempfile

root = Path(__file__).resolve().parents[2]
source = (root / 'src/game/Objects/Player.cpp').read_text()
start = source.index('    // Distribute honor ratio per group', source.index('void Player::RewardHonorOnDeath()'))
honor = source[start:source.index('    m_damageTakenHistory.clear();', start)]
source = (root / 'modules/ManTechPlayerbots/playerbot/strategy/actions/UseItemAction.cpp').read_text()
start = source.index('    std::unique_ptr<WorldPacket> packet', source.index('bool UseAction::UseGameObject('))
end = source.index('    bot->GetSession()->QueuePacket(std::move(packet));', start)
packet = source[start:end + len('    bot->GetSession()->QueuePacket(std::move(packet));')]
code = r'''
#include <cassert>
#include <vector>
#include <map>
#include <memory>
#include <iostream>
using uint32=unsigned;using int32=int;
constexpr int SPELL_AURA_MOD_HONOR_GAIN=1,CONFIG_FLOAT_OPEN_WORLD_HONOR_MULTIPLIER=2,HONORABLE=3;
struct Player;
struct Log {int errors=0;template<class...T>void outError(const char*,T...){++errors;}}sLog;
struct World {float multiplier=1;float getConfig(int){return multiplier;}}sWorld;
static int xpCalls=0;
namespace MaNGOS {namespace XP {float xp_in_group_rate(unsigned count,bool){++xpCalls;assert(count);return 1;}}}
struct HonorMgr {
    int awarded=0;
    void Add(int points,int,Player*){awarded+=points;}
    static float HonorableKillPoints(Player*,Player*,int);
};
struct Group {struct Slot {unsigned guid;};std::vector<Slot> slots;auto const& GetMemberSlots(){return slots;}};
struct Map {std::map<unsigned,Player*> players;Player* GetPlayer(unsigned id){auto i=players.find(id);return i==players.end()?nullptr:i->second;}};
struct Player {
    Map* map=nullptr;int team=1,mapId=0;bool alive=true,near=true,eligible=true;float points=10,multiplier=1;HonorMgr honor;
    std::map<Group*,uint32> damagePerGroup;std::map<Player*,uint32> damagePerAlonePlayer;uint32 totalDamage=100;
    Map* GetMap(){return map;}int GetMapId(){return mapId;}int GetTeam(){return team;}
    bool IsAtGroupRewardDistance(Player*){return near;}bool IsAlive(){return alive;}bool IsHonorOrXPTarget(Player*){return eligible;}
    float GetTotalAuraMultiplier(int){return multiplier;}HonorMgr& GetHonorMgr(){return honor;}
    void run(){HONOR}
};
float HonorMgr::HonorableKillPoints(Player* p,Player*,int){return p->points;}
constexpr int GAMEOBJECT_TYPE_MAILBOX=19,CMSG_GET_MAIL_LIST=100,CMSG_GAMEOBJ_USE=101;
struct WorldPacket {int opcode;unsigned guid=0;explicit WorldPacket(int op):opcode(op){};WorldPacket& operator<<(unsigned g){guid=g;return *this;}};
struct Session {std::unique_ptr<WorldPacket> last;void QueuePacket(std::unique_ptr<WorldPacket> p){last=std::move(p);}};
struct Bot {Session session;Session* GetSession(){return &session;}};
struct GO {int type;int GetGoType(){return type;}};
void dispatch(Bot* bot,GO* gameObject,unsigned guid){PACKET}
int main(){
    Map map;Player victim,solo,member;victim.map=&map;victim.team=0;map.players[1]=&member;
    Group group;group.slots={{1}};victim.damagePerGroup[&group]=1;victim.damagePerAlonePlayer[&solo]=1;
    victim.run();assert(!sLog.errors&&!solo.honor.awarded&&!member.honor.awarded);
    victim.damagePerGroup[&group]=50;victim.damagePerAlonePlayer[&solo]=50;
    victim.run();assert(solo.honor.awarded==5&&member.honor.awarded==5&&!sLog.errors);
    solo.points=-10;member.points=-10;victim.run();assert(sLog.errors==2);
    victim.damagePerAlonePlayer.clear();member.alive=false;xpCalls=0;victim.run();assert(xpCalls==0);
    member.alive=true;member.team=0;victim.run();assert(xpCalls==0);
    member.team=1;member.near=false;victim.run();assert(xpCalls==0);
    member.near=true;member.eligible=false;victim.run();assert(member.honor.awarded==5);
    Bot bot;GO mailbox{19},door{0},goober{10};
    dispatch(&bot,&mailbox,42);assert(bot.session.last->opcode==CMSG_GET_MAIL_LIST&&bot.session.last->guid==42);
    dispatch(&bot,&door,43);assert(bot.session.last->opcode==CMSG_GAMEOBJ_USE&&bot.session.last->guid==43);
    dispatch(&bot,&goober,44);assert(bot.session.last->opcode==CMSG_GAMEOBJ_USE&&bot.session.last->guid==44);
    std::cout<<"PASS: zero/positive/negative honor, ineligible groups, mailbox and normal GO packet dispatch\n";
}
'''.replace('HONOR}',honor+'}').replace('PACKET}',packet+'}')
with tempfile.TemporaryDirectory(prefix='turtle-log-regression-') as tmp:
    work=Path(tmp)
    (work/'test.cpp').write_text(code)
    subprocess.run(['cl','/nologo','/std:c++17','/EHsc','test.cpp','/Fe:test.exe'],cwd=work,check=True)
    subprocess.run([str(work/'test.exe')],cwd=work,check=True)
