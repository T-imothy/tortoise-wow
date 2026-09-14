"""Run actual-source Turtle Arch4 regressions in an initialized MSVC environment."""
from pathlib import Path
import subprocess,sys,argparse,os
p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);p.add_argument('--cxx',default='cl');args=p.parse_args()
here=Path(__file__).resolve().parent;root=here.parents[2];out=args.output.resolve();out.mkdir(parents=True,exist_ok=True)
env=os.environ.copy();env['PYTHONUTF8']='1'
for script in ['prepare_cost_event.py','prepare_network.py','prepare_resources.py']:
 subprocess.run([sys.executable,str(here/script),str(out)],check=True,env=env)
for name in ['chat_queue','account_membership','shuffle','event_lifetime','native_socket_quota','memory','sql_accounting','terrain_pressure']:
 subprocess.run([args.cxx,'/nologo','/std:c++20','/EHsc','/O2','/UNDEBUG',f'/I{root / "src/shared"}',name+'_tests.cpp','/Fe:'+name+'.exe'],cwd=out,check=True)
 subprocess.run([str(out/(name+'.exe'))],cwd=out,check=True,timeout=40)
subprocess.run([sys.executable,str(here/'prepare_native_capacity.py'),str(out)],check=True,env=env)
capacity=out/'native_capacity'
subprocess.run([args.cxx,'/nologo','/std:c++20','/EHsc','/O2','/UNDEBUG',f'/I{root / "src/shared"}',f'/I{capacity / "Detour/Include"}','capacity.cpp',*[str(p) for p in (capacity/'Detour/Source').glob('*.cpp')],'/Fe:capacity.exe'],cwd=capacity,check=True)
subprocess.run([str(capacity/'capacity.exe')],cwd=capacity,check=True,timeout=40)
print('All nine Turtle Arch4 port regressions passed. Native boundaries are mocked where documented; this is not a full-world test.')
