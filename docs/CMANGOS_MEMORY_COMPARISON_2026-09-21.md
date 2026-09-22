# CMaNGOS / Turtle memory comparison — 2026-09-21

Compared the active Turtle checkout against the Classic Arch 4 checkout at C:/Users/root/Documents/Codex/2026-09-06/i-ne/work/arch4/src/classic and production configuration/dependency files. No Classic/TBC/WotLK/playerbots-baseline files were modified.

## Verified differences and common behavior

1. Production Turtle libmysql.dll is 5.5.62.0 (3,931,136 bytes); Classic is 8.4.11.0 (7,031,424 bytes). Classic's September 13 deployment receipt and prepared-binding tests document its client update. Turtle uses bundled 5.5.62 headers. Do not replace its DLL with Classic's without checking all ABI/API consumers and testing connections and prepared statements.
2. Both production botActiveAlone settings are 10, and both update intervals are 1000. Turtle explicitly has DisableActivityPriorities=0. This comparison does not establish equal effective bot workloads.
3. Classic dispatches MapUpdater/Worker jobs. Turtle uses persistent ThreadPool map owners and bounded MapTaskExecutor lanes. Its lane queue falls back inline at 256 entries, tasks are joined, and popped queue entries release packaged tasks. This inspection found no evidence that an unbounded lane queue explains gigabytes of growth.
4. Classic's terrain budget tests unreferenced payload against configurable Memory.InactiveTerrainBudgetMB (default 64). Turtle tests all retained terrain payload against fixed 64 MiB. Both delete only unreferenced grid maps and invoke collision/navigation unload. Turtle's policy can do extra cleanup work; it does not inherently retain more terrain than Classic. Current Turtle terrain ledger is ~68.54 MiB, insufficient to explain the missing gigabytes.
5. Both statement implementations allocate a statement before prepare. Classic asserts on prepare failure; Turtle logs and continues, leaking the unowned object on every retry. Turtle now keeps it in unique_ptr until preparation succeeds. The existing virtual destructor releases MySQL binds, metadata and the statement handle. Successful connection-owned caching is preserved; no CMaNGOS changes made.

## Validation

The extracted actual Turtle GetStmt method passed 10,000 prepare failures without live leaked statements, thrown preparation cleanup, 10,000 cached successful accesses without recreation, invalid index handling, and connection destruction. Built/runs with MSVC. git diff --check passed. Full server not rebuilt, deployed or restarted; changes not committed.

Production errors.log contained zero matches for Can't prepare, mysql_stmt_prepare() failed, mysql_stmt_bind_param() failed, and MySQL client ran out of memory. Therefore the confirmed statement-failure leak is not established as a contributor to the observed production growth.

The bounded read-only old-client prepared-SELECT repro could not connect from this PC (MySQL error 2059). It did not change any database records. An earlier local attempt found no MySQL listener on localhost:3306. No settings/privileges/server processes were changed to make the experiment run.

## What remains unresolved

The +106.24 MiB growing non-default heap in the previous 16-minute comparison still lacks an identified owner. The successful WPR snapshot resolves ~19 MiB of post-enable allocations but cannot attribute the old multi-gigabyte heap. The legacy MySQL/CRT difference is a candidate, not proof. Arch 4 temporal correlation alone does not establish its cause. No measured large-RAM reduction is claimed from today's patch.
