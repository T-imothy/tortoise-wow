from pathlib import Path
import sys
w=Path(__file__).parent;t=Path(sys.argv[1]);s=w.parents[2]
native=(s/'src/framework/Network/MangosSocketImpl.h').read_text(encoding='utf-8')
def body(name):
 start=native.index('::'+name+'(');start=native.index('{',start);depth=1;end=start+1
 while depth:
  depth+=(native[end]=='{')-(native[end]=='}');end+=1
 return native[start:end]
code=r'''
#include <mutex>
#include <memory>
#include <deque>
#include <vector>
#include <cassert>
#include <algorithm>
#include <iostream>
#include "Memory/WriteBudget.h"
struct WorldPacket {int id;size_t bytes;size_t size()const{return bytes;}};
struct ServerPktHeader {unsigned short size,cmd;};
struct Log {void outError(const char*){}} sLog;
namespace WorkMetrics {enum {SocketQueue};struct Probe{Probe(int){}};}
template<class P> struct Queue {
 std::deque<P> q;bool fail=false;
 int enqueue_tail(P p){if(fail)return -1;q.push_back(p);return 0;}
 int enqueue_head(P p){if(fail)return -1;q.push_front(p);return 0;}
 int dequeue_head(P& p){if(q.empty())return -1;p=q.front();q.pop_front();return 0;}
 bool is_empty()const{return q.empty();}
};
struct Socket {
 using SocketName=Socket;using GuardType=std::unique_lock<std::mutex>;
 struct PendingPacket {
  std::shared_ptr<ManTech::WriteBudget::Token> charge;WorldPacket packet;
  PendingPacket(WorldPacket const& p,std::shared_ptr<ManTech::WriteBudget::Token> t):charge(std::move(t)),packet(p){}
 };
 std::mutex m_OutBufferLock,m_SessionLock;bool closing_=false;void* m_Session=nullptr;
 Queue<PendingPacket*> m_PacketQueue;ManTech::WriteBudget m_writeBudget;
 size_t m_socketWriteLimit=256,m_globalWriteLimit=1024,m_OutBufferSize=32,used=0;
 int closeNotifications=0;std::vector<int> sent;
 struct Peer{void close_writer(){}} stream;Peer& peer(){return stream;}
 void OnSocketClose(){++closeNotifications;}
 int iSendPacket(WorldPacket const& p){if(used+p.size()+4>m_OutBufferSize)return -1;used+=p.size()+4;sent.push_back(p.id);return 0;}
 void CloseSocket() CLOSE_BODY
 int SendPacket(WorldPacket const& pct) SEND_BODY
 bool iFlushPacketQueue() FLUSH_BODY
 void Flush(){GuardType lock(m_OutBufferLock);used=0;iFlushPacketQueue();}
 ~Socket(){CloseSocket();}
};
int main(){
 using namespace ManTech;
 {
 Socket s;
 assert(s.SendPacket({1,24})==0);assert(s.SendPacket({2,8})==0);
 assert(s.SendPacket({3,0})==0); // Fits remaining space but must not overtake #2.
 assert((s.sent==std::vector<int>{1}));assert(MemoryLedger::Read(MemoryKind::Network).bytes==256);
 s.Flush();assert((s.sent==std::vector<int>{1,2,3}));assert(MemoryLedger::Read(MemoryKind::Network).bytes==0);
 s.used=32;assert(s.SendPacket({4,0})==0);assert(s.SendPacket({5,0})==0);
 assert(s.SendPacket({6,0})==-1);assert(s.closing_&&s.closeNotifications==1);
 assert(s.m_PacketQueue.is_empty());assert(MemoryLedger::Read(MemoryKind::Network).bytes==0);
 assert(s.SendPacket({7,0})==-1);s.CloseSocket();assert(s.closeNotifications==1);
 }
 {
 Socket s;s.m_PacketQueue.fail=true;s.used=32;
 assert(s.SendPacket({1,1})==-1);assert(s.closing_);
 assert(MemoryLedger::Read(MemoryKind::Network).bytes==0);
 }
 {
 Socket s;assert(s.SendPacket({1,65534})==-1);assert(s.closing_);
 }
 {
 Socket a,b;a.m_globalWriteLimit=b.m_globalWriteLimit=128;a.used=b.used=32;
 assert(a.SendPacket({1,0})==0);assert(b.SendPacket({1,0})==-1);
 assert(!a.closing_&&b.closing_);a.CloseSocket();
 }
 assert(MemoryLedger::Read(MemoryKind::Network).bytes==0);
 std::cout<<"Actual ACE SendPacket/flush/close bodies: FIFO, quota rejection, global pressure, queue failure, oversize and release passed\n";
}
'''
code=code.replace('CLOSE_BODY',body('CloseSocket')).replace('SEND_BODY',body('SendPacket')).replace('FLUSH_BODY',body('iFlushPacketQueue'))
(t/'native_socket_quota_tests.cpp').write_text(code,encoding='utf-8')
d=w/'memory_tests.cpp'
(t/'memory_tests.cpp').write_bytes(d.read_bytes())
print('Prepared actual native send/flush/close tests and concurrent budget tests.')
