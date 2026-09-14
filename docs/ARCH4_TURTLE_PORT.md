# Arch4 on the current Turtle core

Implementation review: September 13, 2026. Runtime results are recorded separately; source integration is not proof of 10,000-bot stability.

## Reference and inherited architecture

The reference is the cumulative ManTech Classic `arch`, `arch 2`, `arch 3`, and `arch 4` lineage, including fixes/reversions. The Classic production deployment record identifies core `e90c11961c02da56838fa7f5b31388d18c157644`: both Arch4 storage increments with later lifecycle/cost corrections, original allocator, profiler off. Newer development diagnostics are imported separately as opt-in tools.

The original Turtle scheduling commits `0d9d09e5`, `3833da48`, `ff85aeba`, and `258e6db5` are already ancestors of the current core. The separate `6ab4d909` proposal is not an ancestor; that does not mean the underlying original changes are missing. Preserve joined map ownership, generation checks, native player/session processing and the later correction that executes bot AI as one joined batch per map.

## Implemented adaptations

- **Sparse aura storage:** all 231 native Turtle aura types keep `std::list` semantics. Materialized public lists, references and end iterators survive until Unit destruction. Internal reads can use an immutable empty list. Page/bucket publication is synchronized; mutation still requires native ownership.
- **Lazy immunity storage:** optional native immunity vectors allocate on first use. Existing exposed references retain their lifetime.
- **Shared EventAI:** creatures retain a shared immutable generation of native event definitions. Turtle events contain pointers to separate native `ScriptMap` actions, so the generation also owns a copy of those action definitions. Reloading global script/event tables cannot invalidate existing AI's action pointers. Timers/enabled flags remain per creature; native event filtering and script execution remain unchanged.
- **Bounded ACE socket output:** acquire a per-socket/process quota before copying a queued packet. Defaults are 8 MiB per connection and 256 MiB across connections, minimum 128-byte charge. Older queued packets precede newer packets. Quota/allocation/enqueue failure closes that connection rather than dropping a reliable frame and continuing. Unsuitable oversized frames are rejected. Queued charges release on flush, close or destruction. The native reusable output buffer remains; its capacity is reported separately within the partial network ledger, outside the pending-payload quota.
- **Terrain cleanup:** report native array allocation lifetimes, including partially loaded data. Above 64 MiB of retained terrain payload per map, check once per second and use the existing zero-reference cleanup path. Referenced grids remain loaded. The existing lifetime gate protects readers while cleanup unloads matching VMAP/MMAP resources. Stable TerrainInfo owners still survive until shutdown.
- **Account membership:** a shared index replaces repeated linear bot-account membership searches. All five Turtle registration sites update it. Original ordered registration lists and Turtle's username-prefix fallback are retained. Unknown-account negative-cache access is serialized; known-bot membership remains a shared read.
- **Relocation:** the two positive-integer destination shuffles use the verified O(n log n) weighted permutation. Existing destinations, weights, filters and teleport checks are preserved. Other shuffle algorithms remain unchanged.
- **Chat replies:** extract due replies while holding the queue lock, then broadcast after unlocking. Future replies keep their order and replies arriving during delivery wait for the next update. Reciprocal bot delivery no longer nests the two bots' queue locks.
- **Cached context lookup:** the previously imported `f9993224` change remains, preserving owned cache keys while avoiding temporary strings on successful lookup. The `255b636a` Uldaman addition is also retained.

The runtime keeps the original CRT allocator. Mimalloc is not enabled. Turtle already uses stack-local path-smoothing arrays and shared per-map navigation geometry, so the CMaNGOS per-PathFinder scratch-vector and Wrath-only private-instance geometry changes have no identical retained-storage problem to port here. Native query state remains per thread.

## Development diagnostics and coverage

`dev/build-mantech.ps1 -BuildOnly -Diagnostics` enables bounded timing and optional allocation-stack capture. Without the switch, both build options are OFF. These diagnostics do not change population, activity eligibility, combat strategies or content data.

The observer writes `logs/DevDiagnostics-latest.json`, bounded history JSONL and observer-cost metadata. Timing includes world/map batches, per-map core player work, object discovery/update, bot batches, pathfinding, callback processing, bot AI/decisions and action execution. Detailed scopes are sampled. Metrics without hooked scopes are unmeasured, not proof of zero cost. Parent/child times overlap and must not be summed as independent CPU usage.

Memory JSON reports process working set/private memory, virtual-region categories, fixed diagnostic capacity, native entity counts and a partial subsystem ledger. Each ledger category explicitly declares whether it is instrumented. Measured categories are Unit base objects, update-field arrays, sparse aura indexes/list objects, optional containers, EventAI holders, socket output, terrain arrays and queued/executing SQL base objects/query-text estimates.

**Coverage limits:** list/vector nodes and allocator metadata are not fully counted; derived Unit members are not included in base-object bytes; EventAI generation/script-map allocations are not included in holder bytes; SQL results/prepared-value payloads/callback captures and driver allocations are excluded. Native navigation tile buffers, shared mesh slot/lookup arrays, per-thread query pools, loaded VMAP model/map-tree capacities and PathInfo/vector capacities are now measured at their owners. Hash-map nodes, allocator overhead, transient collision-loader scratch and capacity changes made solely through escaped mutable path references remain outside these estimates. The ledger is not a complete heap census and its gap from process memory is not itself a leak.

Write a single command to `logs/DevDiagnostics.control`:

- `enabled 0` / `enabled 1`: toggle timing.
- `capture 10`: bounded scope timeline, clamped to 1–30 seconds; four rotating trace files.
- `memory 10`: bounded allocation-stack sample, clamped to 1–60 seconds; off until requested. Eight rotating `arch4-heap-NNN.tsv` files in the runtime directory.

Allocation sampling defaults to 1/1024 C++ allocations. It cannot retrospectively classify older allocations, arbitrary C malloc/free, external DLL heaps or mappings. Export reports dropped samples/sites. Diagnostic captures add overhead; separate captured intervals from normal latency comparisons.

## Validation

The native storage fixture covers all 231 aura types, concurrent publication, iterator/reference stability, lazy-storage lifetime and ledger release. Diagnostic and allocation fixtures cover bounded recording, aligned/cross-thread allocation and release. A Windows include-order fixture catches interaction between diagnostics and Winsock headers.

Nine additional source-extracted regressions are maintained in `tests/architecture/arch4`:

1. Due/future chat ordering and simultaneous reciprocal delivery.
2. Membership/order/duplicate/runtime registration and concurrent index readers.
3. 1,000 seeded weighted permutations, paired weights and generator states, plus 4,000/8,000/14,459-entry cases.
4. Native Turtle EventAI definitions/holders: shared events/actions survive reload, independent mutable state, 10,000-holder vector growth and balanced release.
5. Actual native ACE send/flush/close bodies: FIFO, quota pressure, failed enqueue, oversize frames and cleanup.
6. Concurrent write-budget acquisition, integer overflow rejection and token survival beyond owner lifetime.
7. SQL base/query accounting through execution and destruction.
8. Actual terrain cleanup: cadence/pressure threshold, referenced-grid protection, paired collision/navigation cleanup and repeated unload.

9. Real Detour allocation callbacks verify reported mesh/query capacities, tile unload, rejected query initialization and complete MMapData destruction across 40 lifetimes.

Fixtures mock native service boundaries; they are not whole-world gameplay tests. Run the portable regression driver from an initialized MSVC environment or use the independent architecture CTest project. Keep generated test outputs outside source control.

The pre-change dev sample plateaued at 3,649 independently active bots: average world tick 336 ms, 841 queued world actions, zero pending logins and explicit `world_slow` admission suppression. A native profile attributed 93.4% of world-tick elapsed time to MapManager. This confirms a workload bottleneck, not a login-database backlog. The 10,000-bot target and admission guard are retained; post-deployment measurements must establish the improvement.

No production changes, population reductions, database content migration or schema changes are part of this Arch4 adaptation.

## September 14 diagnostics integration

The shared CMake DEFINITIONS list now carries MANTECH_DEV_DIAGNOSTICS into every
native subdirectory. Earlier builds enabled the cache option but lost the actual
compile definition when native directories replaced COMPILE_DEFINITIONS.

The newer ManTech development diagnostics are adapted to Turtle, with a fixed
20,074,496-byte timing table and separate allocation-sampler capacity. Native
MapTaskExecutor submissions retain map context; queue/execution timing preserves
inline fallback, exceptions and joined ownership. ThreadPool execution, map
barriers, task waits, connection-lock acquisition, actual MySQL driver calls,
channel broadcasts, movement, spells/auras and active ManTech AI value/reaction/
useful/possible/trigger calls now have bounded timing probes. No admission,
population, activity or broadcast behavior changes accompany these probes.

Slow operations retain the latest fixed-size per-thread rings without requiring
a manual trace; reports select at most 100 major and 100 detailed recent spans.
Detailed probes remain sampled; ring overwrites, thread/name table drops and
inclusive/parallel overlap prevent treating this as a complete CPU profile.

`heap` writes a Windows HeapSummary snapshot on the observer. `memory 10` records
allocation samples for 10 seconds, then tracks their frees for another 60 seconds.
Retention snapshots and heap summaries are written at before/end/after phases.
Sampling is cumulative for the process; later captures compare deltas against
their own before snapshot. The observer does not sample its own C++ allocations.
Supported Windows heaps include CRT/library allocations missed by the C++ stack
sampler. Committed minus allocated includes overhead and reusable space; it is
not an exact fragmentation measure. Direct VirtualAlloc and mapped/image regions
remain outside heap totals. Commands and exports are bounded and dev-only.

Disable timing with `enabled 0`; omit `-Diagnostics` to compile out scopes and
the observer/allocation profiler. Owner memory-ledger counters remain available.
Coverage is partial even when every category is instrumented. Performance at
10,000 independent bots remains a separate acceptance target; this integration
does not resolve the observed world_slow login-admission bottleneck.


Focused checks can also be configured directly from `tests/architecture/arch4`,
independent of unrelated legacy source-extraction fixtures in the parent suite.
The six compiled fixtures and nine extracted/native capacity cases passed before
deployment. The parent suite currently fails configuration at its older
BotMoveDispatch extraction; that unrelated fixture was not changed here.
Native queue-delay telemetry follows Architecture.Diagnostics.Enabled, while
task-executor queue timing follows the development timing switch. Session sends
and movement-broadcast flushing have separate sampled scopes.


## Deployed validation, September 14 (build76)

Turtle development world PID 33920, binary SHA256 `283b9e2af51d8db8084cf307012b911d01f64f7f6763a3dd1d37e845fa382085`. Build and runtime
hashes match. The shared compile definition is present in actual Ninja commands;
the live observer reports this PID and enabled timing. The 10,000-bot target,
botActiveAlone100, DisableActivityPriorities1 and existing pool remain unchanged.

Six compiled fixtures and all nine native/source-extracted Arch4 regression cases
passed. Live protocol checks passed login, invitation (0.750s), outdoor cross-map
summon (0.406s), whisper summon, native master-loot/FFA/group-loot changes and
logout; the fixture position was restored. The dev server restarted cleanly.

The live 10-second allocation capture sampled 19,539 allocations with no dropped
allocations/sites. After recording stopped, sampled live bytes fell from172,815
to134,239 over the60-second follow-up; sample count stayed constant. These are
sampled bytes, not a complete process-memory estimate. The bounded trace contains
28,434 events. Thread, label and named-table drops were zero in the final check.
All14 partial memory-ledger categories are instrumented; native navigation,
collision, query and path capacities are populated without counter underflow.

All5 enumerated Windows heaps were summarized. Live heap capture cost ranged
from0.54 to1.19seconds; do not use those intervals as normal latency samples.
The observer formats reports away from gameplay owners, but heap enumeration and
allocation capture still add cost. Native movement-flush timing may remain zero
when that optional path has not run; other native/core/AI/SQL timing scopes were
observed. Per-call-site sampling varies (typically16 or32); actual calls/samples
are reported per metric and should be used rather than assuming one fixed ratio.

The captures finished automatically and allocation recording is now off. Timing
remains enabled for the next bottleneck investigation. This is integration/tool
validation, not proof of10,000-bot throughput or sustained full-population stability.
No login-admission or activity-policy adjustment was made during this phase.
