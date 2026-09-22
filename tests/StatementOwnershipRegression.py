from pathlib import Path
import subprocess,sys
root=Path(__file__).resolve().parents[1]
source=(root/'src/shared/Database/Database.cpp').read_text()
method=source[source.index('SqlPreparedStatement * SqlConnection::GetStmt('):source.index('bool SqlConnection::Initialize(')]
preamble=r'''
#include <cassert>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#define MANGOS_ASSERT assert
struct Log { void outError(const char*,const char*) {} } sLog;
struct SqlPreparedStatement {
 static inline int alive=0,mode=0,created=0;
 SqlPreparedStatement(){++alive;++created;}
 virtual ~SqlPreparedStatement(){--alive;}
 bool prepare(){if(mode==2)throw std::runtime_error("prepare failure");return mode==1;}
};
struct DB {std::string GetStmtString(int){return "SELECT ?";}};
struct SqlConnection {
 DB m_db;std::vector<SqlPreparedStatement*> m_holder;
 SqlPreparedStatement* CreateStatement(const std::string&){return new SqlPreparedStatement;}
 SqlPreparedStatement* GetStmt(int);
 ~SqlConnection(){for(auto* s:m_holder)delete s;}
};
'''
tests=r'''
int main(){
 {SqlConnection conn;
 assert(conn.GetStmt(-1)==nullptr);assert(SqlPreparedStatement::alive==0);
 for(int i=0;i<10000;++i){assert(conn.GetStmt(3)==nullptr);assert(SqlPreparedStatement::alive==0);}
 SqlPreparedStatement::mode=2;
 try{conn.GetStmt(3);assert(false);}catch(const std::runtime_error&){}
 assert(SqlPreparedStatement::alive==0);
 SqlPreparedStatement::mode=1;
 auto* saved=conn.GetStmt(3);assert(saved);assert(SqlPreparedStatement::alive==1);
 int created=SqlPreparedStatement::created;
 for(int i=0;i<10000;++i)assert(conn.GetStmt(3)==saved);
 assert(SqlPreparedStatement::created==created);assert(SqlPreparedStatement::alive==1);
 }assert(SqlPreparedStatement::alive==0);
}
'''
out=Path(sys.argv[1]).resolve();out.mkdir(parents=True,exist_ok=True)
(out/'StatementOwnership.cpp').write_text(preamble+method+tests)
cmd=out/'run.cmd'
cmd.write_text('@echo off\ncall "C:\\Program Files\\Microsoft Visual Studio\\18\\Community\\Common7\\Tools\\VsDevCmd.bat" -arch=x64 -host_arch=x64 >nul\ncl /nologo /std:c++17 /EHsc /W3 StatementOwnership.cpp /Fe:StatementOwnership.exe\nif errorlevel 1 exit /b 1\nStatementOwnership.exe\nexit /b %errorlevel%\n')
subprocess.run(['cmd.exe','/c',str(cmd)],cwd=out,check=True)
print('PASS: repeated preparation failure, thrown preparation, successful cache reuse, connection destruction.')


