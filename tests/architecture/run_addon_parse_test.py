from pathlib import Path
import argparse,subprocess
p=argparse.ArgumentParser();p.add_argument('--root',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();a.output.mkdir(parents=True,exist_ok=True)
s=(a.root/'src/game/Handlers/ChatHandler.cpp').read_text(encoding='utf-8');body=s[s.index('bool WorldSession::ProcessChatMessageAfterSecurityCheck('):s.index('bool WorldSession::IsLanguageAllowedForChatType(')]
prefix=r'''
#include <cassert>
#include <cstdint>
#include <string>
#include <iostream>
using uint32=uint32_t;constexpr uint32 LANG_ADDON=0xffffffff;constexpr int PLAYERHOOK_ON_BEFORE_SEND_CHAT_MESSAGE=1;
int hooks=0,commands=0;
struct PlayerScript {void OnBeforeSendChatMessage(void*,uint32&,uint32&,std::string&){++hooks;}};
template<class T>struct ScriptRegistry {template<class F>static void ForEachEnabledHook(int,F f){T t;f(&t);}};
struct WorldSession {bool valid=true;bool CheckChatMessageValidity(std::string&,uint32,uint32){return valid;}void* GetPlayer(){return nullptr;}bool ProcessChatMessageAfterSecurityCheck(std::string&,uint32&,uint32&);};
struct ChatHandler {ChatHandler(WorldSession*){}bool ParseCommands(char const* msg){++commands;return msg[0]=='.';}};
'''
test=r'''
int main(){int cases=0;for(bool valid:{false,true})for(uint32 lang:{uint32(7),LANG_ADDON})for(uint32 type:{0u,1u,3u,4u,14u,17u,28u})for(std::string msg:{"hello",".bot remove Fixture"}){
 WorldSession session;session.valid=valid;hooks=commands=0;
 const bool expected=valid&&(lang==LANG_ADDON||msg[0]!='.');
 assert(session.ProcessChatMessageAfterSecurityCheck(msg,lang,type)==expected);
 assert(hooks==int(valid&&lang!=LANG_ADDON));assert(commands==int(valid&&lang!=LANG_ADDON));++cases;
 }std::cout<<"PASS "<<cases<<" actual chat preprocessing cases: invalid payloads rejected, addon commands never parsed, normal chat hooks retained\n";}
'''
src=a.output/'AddonChatTest.cpp';exe=a.output/'test.exe';src.write_text(prefix+body+test)
subprocess.run(['cl.exe','/nologo','/std:c++17','/EHsc',str(src),'/Fe:'+str(exe),'/Fo:'+str(a.output/'test.obj')],cwd=a.output,check=True)
subprocess.run([str(exe)],check=True)
