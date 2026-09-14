#!/usr/bin/env bash
set -euo pipefail
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo="$(cd "$script_dir/.." && pwd)"
python3() {
  /c/Users/root/.cache/codex-runtimes/codex-primary-runtime/dependencies/python/python.exe "$@"
}
export -f python3
export PYTHONPATH="$(cygpath -w "$repo/build/python-deps")"
export DBC_PATH='C:/Users/root/Desktop/WorkFolder/turtle/data/dbc'
cd "$repo/modules/TortoiseBots"
bash tools/verify_all.sh ../..
