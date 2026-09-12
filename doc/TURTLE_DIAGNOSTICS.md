# Temporary Turtle architecture diagnostics

Purpose: explain server-side action latency at the configured population without logging every bot action. This is an instrumentation/removal inventory, not a claim of live performance validation.

## CMaNGOS-policy AHBot replacement, September 6

On `feature/cmangos-ahbot`, old detached-worker/category/per-listing diagnostics
are removed with that engine. The replacement emits source counts at load and
one expiry/refill completion summary per rebuild. `.ahbot status [all]` reports
phase, queued request, remaining simulation checks, listed/bought/expired/
protected/failed counters and last/max measured slice microseconds. No periodic
auction-count SQL or per-item log was added. Existing DetailedWork and
ExecutionWatch wrappers still apply to the single AHBot Update call.

Budget clocks are required by WorkSlice (default 32 attempts / 2ms), not an
optional trace. Last/max/counters and summary text can be removed independently
after live acceptance; do not remove the work budget, bid protections or queue.
No background worker retains core object pointers. Initialization/reload does
read source/owner data synchronously; it is not part of normal tick sampling.
Tests use deterministic services; live latency, DB mail delivery, restart
persistence and final stock volume still require the user-operated deployment.

## Historical AHBot rebuild acceptance, September 6 (retired category engine)

Read-only evidence from `server_2026-09-06_11-03-10.log` and `gm.log`: rebuild
was requested at 11:05:32 during the 11:05:09--11:06:03 auction check. The old
command rejected a busy worker; no `Rebuild queued` entry or refill passes
followed. Larger config caps were being read (equip.white=3000), but ordinary
passes retained future sell delays. The contemporary database read showed
503/769/388 listings in houses 1/6/7, not a hard global 1400 ceiling.

Added one log line per accepted/coalesced rebuild request and an on-demand
pending status line. Existing per-house completion summaries remain the refill
evidence. Worker/rebuild failures log exceptions and release ownership instead
of retaining a permanent busy flag. There is no new periodic scan or per-item
diagnostic. Remove acceptance/status text independently of the pending-request
state machine; the queue and worker reservation are correctness mechanisms.

`AhBotRebuildLifecycleTest` covers the actual busy-command timeline, reservation
before worker startup, native expiry wait, three sell-only refill passes,
duplicate commands, explicit all, disabled/shutdown and worker failure paths.
`AhBotRefillTest` covers native selection up to 6000 listings under a per-item
cap. Test storage is mocked: final live counts, expiry/mail persistence and
full-load behavior remain deployment acceptance checks. No production config
or database mutations were performed during this correction.

Current contract review: see `docs/CORE_COMPATIBILITY_AUDIT_2026-09-05.md` and
`docs/CORE_SYSTEMS_GUIDE.md` at baseline `b2d5a854`. Historical port coverage below
does not certify runtime behavior or exact native equivalence. In particular,
the capability cache uses a short-lived fingerprint, not a full spellbook
revision, and disabling summary logs does not eliminate ExecutionWatch costs.

## September 5 baseline and remaining movement port

Baseline commit: `3833da48e4c3d2b1ef7e905c6027257d1135d1f8`, branch
`perf/6k-playerbot-scheduler`. It records the pre-existing work, including the
measured-diff reporting candidate. It is a source baseline, not a statement
that the running server has that binary. GitHub publication is separately gated
on approval of the destination; a local commit is not a successful push.

The follow-up changes are:

- NPC movement uses an inverse viewer GUID index, following the CMaNGOS
  `Unit::SendMessageToAllWhoSeeMeMove` / `GetClientGuidsIAmAt` approach. It no
  longer searches camera cells for each NPC spline packet. Normal session
  delivery remains in place for humans AND bots; no bot packet hooks are
  discarded. Snapshot locks are released before map/session/visibility work.
- Visibility creation registers viewers after create packets, including batched
  and stealth creates. Out-of-range, destroy, stealth loss, relog, logout and
  map removal unregister them. World removal/map changes clear the inverse
  index; delivery re-resolves player GUIDs and checks current visibility.
  The player broadcaster and transport-gameobject delivery remain native.
- Packet compression uses one libdeflate workspace per sending thread rather
  than allocating/freeing twice per packet. A compression-level change replaces
  that thread's workspace; failure throws instead of dereferencing null. The
  size bound covers every level, including reload between bound/compression.
  Zlib format, bundle framing, root/walk/speed restoration packets and opcode
  ordering are unchanged. Memory is bounded by the number of sending threads.
- Random wandering retains path scratch capacity, as the reference generator
  does. Each request resets old routes, topology pointers and movement filters;
  it acquires the current thread's query anew. This deliberately does NOT carry
  stale polygon references across tile/map changes. Turtle's destination,
  steep-slope policy, flying paths and successful wander delay are retained.
- Failed navmesh-query lookup now clears the previous mesh pointer.
- TD15 adds `random_path`, `spline_launch`, `packet_compression` and
  `movement_delivery` to the existing bounded `TW_WORK` diagnostics. They are
  inclusive/nested measurements, not additive totals. Disable/remove together
  with TD11 after acceptance.

### Port coverage ledger

References are the local ManTech TBC `b4354d59d`, WotLK `9f47f9a121`,
Classic `5064f7682`, and unified Playerbots `811d6f1e` trees. The commit groups
below distinguish already-recorded implementation from this follow-up; they
are not claims of byte-for-byte code identity or measured performance parity.

| Reference area / representative commits | Turtle implementation / disposition |
|---|---|
| VMangos compatibility, map workers, packet ownership (`578d1be99`, `472803b2d`) | Baseline: `MapManager`, `Map`, `WorldSession`; joined owners, native broadcaster integration and socket safety. Native transport/custom map hooks preserved. |
| Parallel pathfinding and human-login priority (`865a694ea`) | Baseline: thread-owned queries, navmesh lifetime gate, DB priority completions and bounded bot admission. |
| Arch 2 cell/map scheduling (`af9a06ba5`, `d4881c7e4`, `57655f6b6`) | Baseline: discovery snapshots, owner-thread application, staggered idle work, bounded batches and memory telemetry. |
| Corrected idle-AI ownership / stale transitions (`03e066156`, `30c308969`) | Baseline: one serial AI batch per map on a separate joined pool; GUID/map/generation validation. No concurrently mutating independent bots on one map. |
| Arch 3 core (`52270e962`) | Baseline: cell fallback/drain, adaptive idle budget/recovery/age promotion, memory admission guards, spline validation, watchdog/phase diagnostics and warning aggregation. Turtle retains facing/stop/custom spline cases. |
| AI cache/retry work (`185b1f44`, `9e354d93`, `34a09916`, `014f532c`) | Baseline: map-owned cleanup, bounded failed-retry cache, lazy cache accounting and cancellation/retry control. |
| Portal transitions (`0081875b`, `2ec313e4`, `f7086751`, `e7326160`) | Baseline: deferred urgent-transition request, deduplication, generation guards and owner-thread execution. |
| Arch 3 bot capabilities/actions (`74372022`, `407f4cd5`) | Baseline: short-lived spell-capability fingerprint cache (not a true revision; see audit A4), admission counting including pending work, trainer/loot/target/movement guards. Native Turtle spell content retained. |
| Summon direction / stale graveyard (`811d6f1e`, `394afced`) | Baseline: explicit bot-to-requester summon, no implicit human hearthstone use, stale corpse/map guards. |
| World-thread maintenance and service work | Baseline: resumable teleport filtering, static area index, weighted selection, occupancy snapshot, bounded auction completion and synthetic packet draining. These adapt the reference ownership model rather than copying its synchronous stalls. |
| NPC movement recipient lookup | This follow-up: inverse visibility GUID index instead of repeated camera-cell traversal. |
| Random-motion scratch reuse | This follow-up: retained scratch with fresh topology/filter context per request. |
| Compression allocation churn | This follow-up: thread-owned reusable libdeflate workspace; wire behavior retained. |
| Timings / input checkpoints | Baseline: measured max/current/average diff and map-owner human input checkpoints; follow-up TD15 separates movement costs. |

Expansion-only spells, portable convenience items and expansion-specific SQL
inside reference commits are not architecture ports and are not substituted for
Turtle's data. No production database, population or configuration change is
required by this follow-up. Static coverage and successful compilation cannot
certify every gameplay path or establish CMaNGOS-level latency: live checks at
the selected 6,000-bot workload remain necessary.

New tests exercise compressor reuse/reload and zlib round trips across packet
sizes, parallel independent contexts, invalid-level recovery, viewer uniqueness,
removal/reset and concurrent snapshots. The source contract checks visibility
lifecycle wiring and fresh path context. These are not a full client/server
visibility or transport simulation.

### TD16: real-character loading screen

The human login request already uses `DelayQueryHolderUnsafePriority`.
Admission priority does not make the later character/map initialization
asynchronous or eliminate client asset-loading time. The previous logs recorded
successful login but did not measure the phases leading to it.

The follow-up emits `PLAYER_LOGIN_STAGE` for socket-backed human requests only,
under the existing architecture diagnostic switch: request dispatch queue age,
DB-results callback, existing-character resolution, character load, social load,
initial packets, map/initial-object addition, corpse/pet work, cleared login flag,
and completed login hooks. `stage_ms` is elapsed since the preceding marker;
`since_request_ms` is elapsed since request handling began. The DB-results stage
includes request preparation, DB queue/execution and callback dispatch; it is
NOT a measurement of SQL execution alone. No passwords, IPs or character names
are added; correlation uses account and character IDs.

`PLAYER_CLIENT_SIGNAL signal=active_mover` records client control messages and
their server queue age. `since_in_game_ms` is relative to the server's existing
in-game timestamp, NOT an exact measurement of client loading duration. This
message can also accompany possession/mover changes, so correlate it with a
preceding login rather than labeling every instance a login completion.

These probes do not alter queue priority, map loading, packets, login hooks or
bot population. They are needed before attributing the reported loading-screen
pause to SQL, map initialization, server queues or client-side work. Remove or
disable with the other temporary diagnostics after validation.

Validation for the movement/TD16 candidate: full Windows x64 Release build
succeeded; a repeat build reported no pending work. The executable's `--version`
smoke test exited successfully without starting the server. All 14 standalone
tests passed in both ordinary and AddressSanitizer builds. Compressor/viewer
tests each also passed ten consecutive runs in both builds. Live load-screen
and 6,000-bot performance acceptance are still pending.

- World executable SHA-256: `E135871E41008D525D4B073142D6433706A9017BD57A14CF0A5943BB353A2B6B`
- Matching symbols SHA-256: `B9737EF7606FDAD9E7AE984B2CFD36E0442AD5E37BFC38E0A2C9FED406347831`

The build's legacy `--version` revision is unavailable (1970 placeholder); use
these hashes to identify the candidate. This update needs only the world EXE
and matching PDB, not a login-server replacement, SQL or config edits.

## September 5 measured diff reporting correction

`GetMaxDiff()` formerly returned a literal zero and `GetCurrentDiff()` a literal
100. Both now publish measured tick intervals in milliseconds. Maximum and
average share Turtle's existing 50-tick window (not the CMaNGOS history/reset
policy); old peaks expire on leaving that window. The existing zero-padded
startup average is preserved so this reporting correction does not retune
load-sensitive scheduling. A world-owned ring uses a 64-bit sum and atomic
published values for readers; the hardcoded current/max placeholders are gone.
Tests cover zero startup, exact readings, peak expiry, repeated ring wrap and
sum overflow. This does not speed up the simulation or change bot activity.

## September 5 static-destination and input-checkpoint candidate

Built after the user increased the live configuration from 1,000 to 6,000 bots.
The running process, production database and share-root files are not changed
by preparing this candidate. No SQL or bot-population change is required.

- Teleport source positions are classified once after the startup caches are
  assembled. An exact map/XYZ index deduplicates repeated level/race entries.
  Faction, active-zone and custom-race filters use this read-only index, not
  terrain lookups per bot. Missing keys fail closed; no lazy runtime insertion.
  Final landing height and offset validation still use current terrain.
- `TELEPORT_AREA_INDEX preparing` (at most every five seconds) and `ready`
  expose startup progress and unique/invalid counts. This intentionally moves
  classification I/O into startup; it can increase startup time and transient
  terrain memory. Index entries retain IDs/teams, not loaded terrain references.
  Restart after changing source teleport locations or static area definitions.
- Ordinary NPC eligibility uses exact selected AggressorAI, ReactorAI, NullAI
  and CritterAI types. Their idle update paths were checked locally: offensive
  spell lists need a victim; critter timers need combat. Custom subclasses,
  scripts, escorts, bosses, events, controlled units and transports stay
  protected. Combat, casts and real-player neighborhoods remain immediate.
- Only permanent, positive, self-cast passive auras with no duration,
  heartbeat, channel, specialized/periodic/area/persistent effect can defer an
  idle NPC. Existing elapsed-clock handling and movement intervals are retained.
- Map-owned input checkpoints now include MAP actions alongside movement and
  spells, plus checkpoints after the joined AI phase and cell phase. They use
  a responsive GUID snapshot and re-resolve membership. Each session/category
  checkpoint is bounded to 32 packets or two milliseconds between handlers;
  an individual handler remains atomic. WORLD packets retain their owner.
  Existing `MapUpdate.UpdatePacketsDiff` is respected, not silently overridden.
- TD14: `creature_foreground`, `creature_interactive`,
  `creature_script_protected`, `creature_aura_protected`, `creature_other`
  count mutually exclusive scheduling categories in the order listed, before
  the interval decision. `background_creature_deferred` records actual skips.
  They use the existing diagnostic switch and 30-second aggregation; no
  per-creature log spam. Remove these temporary counters after acceptance.

Validation must compare steady-state populations, activity and real cast/loot
inputs. The earlier 1,000-bot improvement is not evidence of parity at 6,000.
Synthetic index/policy tests and static hook guards do not replace in-game
combat, trainer, instance, transport and teleport regression checks.

## September 5 execution-model completion candidate

Live TD11 evidence at 1,000 bots: individual `maintenance_bot` peaks of
1,425-1,576 ms coincide with `world_tail` peaks of 1,430-1,638 ms. Auction
completion was negligible in those samples. This identifies a blocking region,
not yet the exact inner operation. The new inner probes below close that gap.

Reference pass: local `mangos-classic-full-arch`, `mangos-tbc-mantech-integration`,
`mangos-wotlk-mantech-integration`, and their previously listed playerbot trees.
The inspected TBC/WotLK code uses one owning map batch, including its idle-AI
worker phase; it does not safely permit independent bots to mutate the same
map concurrently. The reference also runs random maintenance synchronously.
Blindly copying it would retain that blocking point. The following inventory
distinguishes retained ports from changes in this candidate:

| Execution area | Candidate state |
|---|---|
| Map workers / transfers / destruction | Existing ManTech-style single-owner batches and join-before-transfer retained; old worker-to-worker barriers remain removed |
| Cells / visibility | Existing snapshot/discovery workers and owner-thread application retained |
| Real-player priority / idle AI | Existing foreground classification, budget, GUID cursor, age promotion and generation checks retained |
| Login / database | Existing bounded asynchronous admission, player-priority completions and owner-thread application retained; zero DB-queue limit now means disabled, as in the reference |
| Synthetic bot packets | Replaced empty `HandleBotPackets` stub with native validated handler dispatch; socketless bot actions now actually drain |
| Bot sessions | Separated ACK/packet progression from maintenance/react timers; random and companion holders run only from world hook after map joins |
| Packet bounds / lifetime | Up to 32 packets or 2 ms per synthetic processing category; one handler remains atomic. Limits include script-consumed/requeued packets. Completed synthetic logout sessions are reclaimed and timed logouts finish |
| Battleground join | Removed direct-handler workaround for the missing queue pump; world owner now applies the queued join |
| Weighted selection | Replaced repeated-distribution O(N squared) shuffle with O(N log N) exponential-clock permutation, preserving weight-proportional sampling without replacement and uniform zero-weight tail |
| Teleport occupancy | Value-only spatial snapshot replaces a whole-population scan per destination; queries preserve same-map/zone radius caps |
| Small correctness defects | Empty pointer candidate list no longer indexes element zero; nearest-inn comparison now actually selects the minimum distance |
| Custom gameplay | No SQL, spell-duration, loot, quest, boss-script, race, map or transport-route changes |

Read-only comparison of live Turtle/TBC configs also confirmed both use
`Continents.Instanciate = 0`. Their background-AI count (128), timer advance
(250 ms), budget (20 ms), minimum (16), maximum deferral (15 seconds) and
recovery ticks (20) match. TBC's idle-AI worker is a whole-map batch that the
map owner joins; Turtle executes the equivalent batch on its existing owner
instead of adding an extra worker handoff. No live config was changed.

Tests: weighted distribution (100,000 seeded trials), conditional probabilities,
zero-weight behavior, uniqueness through 20,000 candidates; spatial queries
against brute force with 6,000 points, negative coordinates, boundaries and
map/zone isolation. Existing pool, ownership, discovery, background scheduling
and navmesh lifetime tests retained. Static contracts assert a single world-owner
bot-session path and preserve Turtle script/transport hooks. Static contracts
are not a runtime integration test.

Optimized `/O2` synthetic shuffle benchmark on the build machine, 12,000
candidates: reference 335,757 us; replacement 857 us (one sample). Earlier
unoptimized harness result was 1,430,073 vs 2,778 us. These measure only the
algorithm, not total server speed or a proven resolution of gameplay latency.

TD12 extends TD11 with bot packet dispatch, cache cleanup, nearby-player checks,
randomization, strategy change, event reads, refresh, teleport faction filtering,
weighted shuffle, active-area filtering, area eligibility and final placement.
Bot-generated packet timings are excluded from real-player input-delay metrics.
The probes use the existing diagnostic switch and bounded summary interval.

Acceptance still requires user-started gameplay testing of casts/loot/login at
the fixed 1,000-bot baseline, then larger populations. Do not call this a fully
validated wholesale replacement of every CMaNGOS subsystem. Broad unrelated
content/data replacements are deliberately not part of this execution-model port.

## Temporary additions

| ID | Measurement | Question answered | Removal boundary |
|---|---|---|---|
| TD01 | World/map elapsed time, map job queue time, tick/map/instance/thread identity | Which map or queue holds up a tick? | `ArchitectureDiagnostics.h` and `TurtleDiagnostics::` call sites |
| TD02 | Selected cells, discovery, worker wait, object counts and ordered update time | Is traversal or simulation expensive? | Map discovery probes; keep discovery implementation |
| TD03 | Creature, game-object, dynamic-object, creature AI, movement and pathfinding timings | What inside simulation costs time? | Timing scopes only; keep gameplay calls |
| TD04 | Synchronous DB connection wait/read execution and callback execution | Is game work waiting on the DB? | Timing scopes; never log SQL/passwords |
| TD05 | Gameplay packet queue/handler time | When does input actually reach gameplay? | Diagnostic samples; existing slow-input warning can remain |
| TD06 | Per-window sample count, mean, histogram p95/p99 upper bounds and maximum | Typical latency versus rare stalls | Fixed-size diagnostic summaries |
| TD07 | Bounded failed-action cache size/peak, expiry/eviction, suppressed actions and transition counters | Are retry loops and cache growth controlled? | `TW_DIAG_BOT_COUNTERS` logging call; keep retry safeguards |
| TD08 | Map completion, DB/instance scripts and grid maintenance | Is post-simulation work delaying the next world tick? | Completion timing frame/scopes; keep all script and grid calls |
| TD09 | Creature-only phase totals and one slowest creature per map/report window | Which part of Creature/Unit update explains the object simulation cost? | `CreatureProbe`, `CreatureProbe::Stage` calls, and the creature sample/phase fields in `ArchitectureDiagnostics.h` |
| TD10 | World prelude, sessions, owner tasks, transports, map batch, services and remaining tail | Which world phase accounts for gaps outside map simulation? | `diagnosticPrelude` through `diagnosticTail` scopes in `World::Update` and corresponding enum/name entries |
| TD11 | Maintenance, auction and movement suboperations (`TW_WORK`) | Which individual operation blocks its owner? | `DetailedWorkDiagnostics.h`, `DetailedWork::Scope` call sites and report storage |
| TD12 | Teleport filter/commit, bot packets, cache/nearby/strategy work | Which part of maintenance stalls? | Corresponding `DetailedWork` kinds/names/scopes; keep resumable plans, indexes and packet handling |
| TD13 | `TW_TELEPORT_PLANS`, `TW_WORLD_TASK_SLOW`, `TW_BOT_HANDLER_SLOW`, `PLAYERBOT_CACHE_MEMORY` | Are queues progressing, or is one callback/handler blocking? | Logging sites in `RandomPlayerbotMgr.cpp`, `World.cpp`, `WorldSession.cpp`; retain planner, handler, owner-queue and cache implementations |
| TD14 | Foreground/interactive/script/aura/other NPC category counters | Which NPCs can safely defer? | Category counter calls and enum/name entries; keep the actual eligibility policy |
| TD15 | Random path, spline launch, compression, movement delivery | Which part of moving NPCs remains expensive? | The four `DetailedWork` kinds/names/scopes; keep workspace reuse and viewer index |
| TD16 | Human login stages and client active-mover signal | Where does the character loading-screen delay occur? | `LoginQueryHolder` request timestamp/accessors; `CharacterHandler.cpp` stage lambda/calls; `MovementHandler.cpp` client-signal logging |
| TD17 | Watchdog phase breadcrumbs, thread/map/GUID slots | Where was execution when progress stopped? | `ExecutionWatch.h` phase scopes/setters and diagnostic dump integration in `Master.cpp`; preserve ordinary watchdog/crash reporting |
| TD18 | Upstream dungeon-clear / Arathi banner troubleshooting | Why did an altar, follower, encounter or banner interaction stall? | Diagnostic throttle/log sites in `DcEngageActions.cpp`, `DcFollowerActions.cpp`, `DungeonEventExecutor.cpp`, `BattleGroundTactics.cpp`; keep gather movement retry state and the actual gameplay fixes |

TD18 integration (upstream 0f6b92d9): repeated per-bot diagnostic throttles now
use `BoundedBotThrottle`, bounded to 65,536 IDs per site and synchronized across
map workers. Those diagnostic checks are gated by `Diagnostics.Architecture.Enabled`;
their original per-site 1/5/10/30-second intervals remain independent of the summary
interval. `DcFollowerActions::s_issuedAt` is **gameplay retry state**, not tracing:
keep it enabled when diagnostics are off and retain it during diagnostic removal.
The trainer index and prerequisite catch-up are gameplay/performance code, not probes.

Upstream also added ordinary INFO event lifecycle and test-run logs in GameObject,
Spell, Uldaman/ZulFarrak scripts and the DungeonClear module. These are not all
controlled by the architecture switch. Include `[GO]`, `[DC-DIAG]`, `TESTRUN`,
gather/snap and pyramid/keeper messages in the eventual logging cleanup; preserve
missing-template errors, event execution, retry decisions and test verdict logic.
Never remove a surrounding gameplay block just to remove its log message.

Deployment boundary for the 2026-09-05 upstream integration: production currently
links mod-playerbots, not mod-dungeon-clear. Keep MODULES=disabled with
MODULE_MOD_PLAYERBOTS=static; the corrected playerbot build gate does not change
the global module selection. DungeonClear source updates and TD18 DC probes are
integrated but not active in this production candidate. Enabling that optional
automation later requires its own build, module config, roster/route packaging
and gameplay/load acceptance. The live explicit LoadSpellsFromSql=0 is also
preserved; adopting upstream's new default is not an implicit production migration.

Controls: `Diagnostics.Architecture.Enabled` and `Diagnostics.Architecture.IntervalMs`. Disable after collecting a matched loading and steady-state run. Histogram percentiles are approximate bucket upper bounds; nested timings are inclusive and must not be added together. Elapsed time is not CPU utilization.

### Resource cost and final cleanup contract

The switch suppresses the architecture scope timing/aggregation/output and TD16
human-login output. It is NOT a promise of zero overhead: checks and some
diagnostic fields remain, and `ExecutionWatch` breadcrumbs currently take their
own clock readings/atomic stores independently of that switch. Bot-memory
reports have the separate `AiPlayerbot.MemoryTelemetryInterval` setting. Track
these separately when comparing diagnostic-on/off measurements.

After matched loading/steady-state gameplay validation, first compare a run with
temporary profiling disabled, then remove the diagnostic-only calls, storage,
login timestamp fields, configuration keys and associated test assertions in a
separate cleanup commit. Keep ordinary error/crash logs and rate-limited stall
warnings. Verify no `TW_DIAG`, `TW_WORK`, `PLAYER_LOGIN_STAGE` or
`PLAYER_CLIENT_SIGNAL` output remains in the cleaned build.

Do not remove clocks used for real scheduling, time budgets, admission guards
or gameplay timers. Some current operational budgets call
`TurtleDiagnostics::Micros()`; move those callers to the ordinary monotonic
clock helper before deleting the diagnostic header. Likewise keep the measured
world-diff values used by adaptive scheduling, generation guards, synchronization,
functional indexes/caches, normal packet delivery and gameplay regression tests.
The cleanup build must pass those tests and repeat the same population/gameplay
checks; do not obtain lower overhead by accidentally disabling the fixes.

The staged configuration enables the temporary probes at a 30-second reporting interval and writes them to the existing `logs/perf.log`. It retains the 6,000-bot target, 1,000 random-bot accounts and activity value 10. All optional memory-admission thresholds remain zero (disabled). Configuration comparison against the production share confirmed that only the planned architecture keys differ.

`TW_DIAG` is a window summary; its tick is the last tick in that window, not a trace of one tick. `TW_DIAG_SLOW` is a single tick taking at least 250 ms, rate-limited to once per second per map. It shares map/instance/tick IDs with `GAMEPLAY_INPUT_DELAY`'s `diag_*` fields. World-owner work uses diagnostic map 4294967295. Diagnostics disabled means tick 0. Counter telemetry uses the existing playerbot memory-telemetry interval. Counters without a time suffix are totals/levels, not milliseconds.

Limitations: these are wall-clock scopes, not CPU profiles or instrumentation of every lock. Worker wait includes scheduling and worker execution. DB timing covers synchronous reads on instrumented owner threads, not all SQL workers. It does not print raw queries. A profiler may still be necessary if a scope is expensive but its nested measurements do not explain why.

### September 5 creature breakdown candidate (diagnostics only)

`TW_CREATURE_PHASE` reports 17 sequential phases: creature hooks/state handling, unit hooks, pending visibility, events, spell/aura updates, deleted-aura cleanup, unit combat timers/attacks, reactives, movement checks, spline advancement, synchronous motion, deferred motion, world-object delayed actions, creature combat/leash checks, script AI and regeneration. These accumulate only while the exact creature is inside `Creature::Update`; player updates are excluded. A phase can include callbacks and waiting, so it is elapsed time rather than CPU time. Nested creature updates, if any, remain inclusive, as with the existing parent `creature` metric.

Each phase total uses the same map/report window. `n` is the number of completed creature calls (including calls where that phase did no work); compare `total_us` and its share of the parent creature total, not just the integer-truncated mean. One `TW_CREATURE_SLOWEST` line identifies the slowest observed creature in that window by map, instance, actual tick, GUID, template entry, initial death/combat state and incoming update diff. Its phase values belong to that single update and sum to its elapsed time. It is not a list of every slow creature, and one worst creature may not explain a cost distributed across many creatures.

The existing `Diagnostics.Architecture.Enabled` switch controls all new probes; the existing interval controls reporting. At the current 30-second interval there are at most 18 additional creature lines per active map/window, plus seven world phase summaries. No per-creature log writes occur inside the simulation loop. Storage is fixed-size per map and stack-local per update; identity snapshots retain no creature pointers after a call. There are no gameplay, cadence, configuration, SQL or bot-count changes in this candidate.

Deployment needs only the newly built `mangosd.exe` and its matching PDB. The current server can keep running until the user stops it and replaces those files. No realmd replacement is needed. After the restart, retain 6,000 bots, allow population to settle, and repeat casting/looting for 2â€“3 minutes. Read the new phase totals and slowest samples alongside the original input/map timing rows. If a phase is dominated by waiting or still unexplained work, capture a bounded CPU/wait-stack profile of that phase using the matching PDB rather than infer its internal cause.

No packet contents, chat, account credentials, SQL text, or per-bot per-tick logging. No automatic deletion of logs. No database migration. Keep instrumentation in its own named header and identifiable calls so it can be removed without reverting architecture fixes.

Removal checklist: remove the `ArchitectureDiagnostics.h` includes and `TurtleDiagnostics::` scopes/frames/records; remove Map's `m_archDiagnostics`, `m_archTick`, `m_archQueuedAt`, `MarkUpdateQueued` and `GetDiagnosticTick` and their manager calls; remove the two diagnostic configuration reads/defaults; remove the `diag_*` suffix from the existing slow-input warning and `TW_DIAG_BOT_COUNTERS`. Remove the diagnostic-only assertions from `MapDiscoveryTest`, retaining executor tests. Do not remove the map scheduler, joins, transition guards, DB lanes, ordinary performance warnings or retry caches.

### September 5 background-world scheduling candidate

This candidate includes the creature/world diagnostics above **and changes scheduling**. The diagnostic-only baseline is retained locally in `release/CREATURE_DIAGNOSTICS`. Its SHA-256 is `AE2B3E7BE0516428275FEC9B6CD0C459F44F95AFCB798F29A10848007E17452C` (exe), with PDB `D1277E9340F12E9E697BBDDE0CFCF30817632FE4BEDF5A2CA6442D190A8B23AB`. The baseline compiled and passed its version-only check with the existing runtime DLLs; it was not started as a server.

Source comparison: current ManTech Classic `c6dfe497a`, TBC `63d0260d3`, WotLK `703f12a98`, and the running TBC revision `efc893079`. All three share bot-grid loading separated from full surrounding-NPC activation and player-near protection for background shedding. TBC/WotLK additionally have individual object deadlines; Classic does not have that gate in its object loop. This was a behavioral gap in the earlier Turtle port, despite shared executor and bot scheduling work.

Candidate behavior:

- Background bots on continents load their current grid without automatically scheduling a full visibility-radius NPC neighborhood. Combat/casting bots explicitly retain their own cell and the neighborhoods of their victim, selected target and attackers; this is a Turtle-specific safety adaptation, not a literal copy of the CMaNGOS bot shortcut.
- Real players and responsive companions retain their normal activation areas. Non-continent maps retain the previous path. Active scripted, escort, event, non-idle movement and transport work bypass the added load-shedding policy. Transport routes and the transport-manager update loop are untouched.
- Background bots' pets, guardians, totems, minipets and non-player charms are queued directly by GUID for owner-thread updates, even if no neighborhood was activated. Their combat targets stay discoverable. The owner deduplicates these with discovered objects after all collection workers join. Charmed players stay exclusively in the separate player update path. Farsight/camera viewers protect active-object discovery as well.
- A background bot's selected NPC/gameobject and current loot object are also queued directly, retaining interaction/corpse processing without reactivating a whole region. Turtle's player selection is distinct from its Unit attack target; combat discovery considers both.
- Ordinary distant living idle creatures receive stable 500â€“1000 ms deadlines; ordinary random-moving creatures receive 250â€“500 ms deadlines. Combat, ownership/pets/totems, pending events, casting, **any** auras, script/AI/template spell lists, zone scripts, world bosses, escorts, explicit active status, transports and other movement types bypass those deadlines. Gameobjects, doors, corpses and respawn processing are not assigned new deadlines.
- A deferred creature keeps its existing real elapsed-time tracker. Spell/aura/regeneration clocks receive real elapsed time on the eventual update. Eligible idle/random motion and generic AI catch up with a maximum 1000 ms logical step, avoiding an hours-long movement replay after cell inactivity. Protected objects retain the old logical-diff path. No extra per-creature state, map registry or object pointers are retained.
- `bot_grid_only` counts background-bot grid-loading decisions (a combat bot may also activate combat cells). `background_creature_deferred` counts skipped not-yet-due creature calls. `discovered_objects` still includes collected/deferred objects; the `creature` phase and detailed creature probes count only executed creature updates. Compare those counts with input queue latency and map wall-clock times.

`MapUpdate.BackgroundWorld.CmangosScheduling = 1` is the new candidate default. It is read once and requires a restart. Set it to `0` and restart to recover the diagnostic baseline's scheduling path without replacing the binary; diagnostics stay enabled independently. Startup identifies the selected policy with `BACKGROUND_WORLD_SCHEDULING`. Existing 6000-bot counts and activity settings are unchanged. No SQL or realmd changes are required. Only `mangosd.exe` and its matching PDB should be deployed after successful verification; do not start the realm automatically.

Tests cover protection flags, supported motion modes, stable per-GUID intervals, population-independent decisions through 20000 synthetic GUIDs, retained elapsed time, bounded logical catch-up and uint32 clock wrap, plus the existing owner/executor/content-hook tests. These do not reproduce 6000 live players or prove every Turtle script correct. The acceptance test remains player casting/loot/combat responsiveness, bot population convergence, and transport/escort/instance regression checks at the same settled population. TBC's trace spans loading and a three-continent distribution; it is not an identical-load benchmark or proof of a particular speedup.

### September 5 candidate verification and deployment

The Windows x64 Release world build completed successfully. The final build included the selected/loot-target guard in `Map.cpp`; the follow-up build reported no work pending. All four standalone tests passed in both the normal and AddressSanitizer builds. The executable's `--version` path exited successfully with the existing runtime DLLs, without starting the server or opening a database connection.

With ports 8088 and 3727 not listening and exclusive file-access checks successful, only `mangosd.exe` and its matching `mangosd.pdb` were overwritten in `\\10.0.0.109\turtle`. Source and destination SHA-256 matched:

- `mangosd.exe` (20879360 bytes): `3CEA55E75F4991F5D25C068A79FA9CB1D8ADDE1456AEAB59D46F0C481F1AF066`
- `mangosd.pdb` (230281216 bytes): `75591DE30C5A8101312C5687D877D2924956CA21452C53BF15FF93E8D1DB2C06`

No production config, SQL, realmd, DLL, extracted data or bot-count changes were made during this deployment. The existing configuration was verified at 6000 bots, activity 10, and diagnostics enabled every 30000 ms. No server was started. Live latency and gameplay acceptance checks remain outstanding; build/test success is not a measured performance improvement.

### September 5 navigation/terrain lifetime crash correction

Evidence: `crash_20260905_053547.dmp` belongs to the executable with SHA-256 `3CEA55E75F4991F5D25C068A79FA9CB1D8ADDE1456AEAB59D46F0C481F1AF066`. Its exception is a read access violation at executable RVA `0xB0AEB9`; the matching PDB resolves that instruction to `dtNavMesh::connectExtLinks` in `DetourNavMesh.cpp:415`, inside the neighboring-tile polygon lookup. Candidate return addresses from the crashing thread's raw stack also identify tile loading and asynchronous playerbot travel/area discovery. This is a raw stack scan, not a fully unwound call stack. Code review found tile removal unprotected against concurrent tile loading and navigation queries, and terrain cleanup unprotected against asynchronous terrain readers. The exact historical thread interleaving is not recoverable from this small dump. The available evidence does not identify the friend's trainer purchase as the crashing handler.

The correction adds reentrant shared-read/exclusive-write scopes to the actual Detour entry points. Different threads' queries can still run concurrently; tile insertion/removal waits for readers and excludes other mutations. Explicit read scopes also cover the two server callers that dereference returned tile/polygon pointers. Sliced queries reject a changed mesh revision between slices instead of using stale topology. Locks end at each navigation operation: there is no broad pathfinding lock covering terrain lazy loading, which would create a read-to-write lock upgrade.

Terrain height/area/liquid reads now protect their complete use of tile data against cleanup. Lazy loading publishes its atomic terrain pointer only after terrain, collision and navigation loading finishes. The cleanup timer does not acquire the exclusive lifetime gate until cleanup is due. The terrain registry is snapshotted and released before waiting for readers. Map unload retains terrain and navigation owner objects/query pools until shutdown because existing asynchronous code caches raw pointers; unreferenced terrain, collision and navigation tile payloads are still reclaimed. This retains some owner/pool memory, not all extracted tile data, and is not a promise of lower RAM usage.

`MMapTileUnload` remains enabled. No navigation file format, extraction, route, spell/trainer, bot-population, activity, SQL or realmd change is needed. The startup marker `NAVMESH_LIFETIME shared_queries=1 exclusive_tile_changes=1 guarded_terrain_cleanup=1` identifies the enabled lifetime protection.

Verification adds `NavMeshLifetimeTest` against the actual Detour implementation: a two-tile path, a deterministic unload waiting for a raw-pointer reader, nested gate behavior, concurrent readers, stale polygon/sliced-query rejection, and two tile writers versus two querying threads performing 20,000 actual tile mutations per run. All five standalone tests passed normally and ten consecutive repetitions under AddressSanitizer after these additions. AddressSanitizer is not a data-race detector, and these tests are not a live 6,000-bot acceptance run. Recheck full population loading, action latency, navigation/transports and trainer purchases after the user starts the replaced binary; do not infer stability or a performance gain from compilation alone.

Deployment verification for this correction: the full Windows x64 Release build succeeded, the incremental follow-up included the cleanup-timer adjustment, and the final build reported no work pending. The executable exited successfully through `--version` using the existing runtime DLLs. Before replacement, the share still had the expected crashed-build hash, port 8088 did not accept the bounded connection probe (timeout), and both destination files passed exclusive read/write-open checks. A timeout alone is not evidence of process state; the exclusive executable check is the additional replacement safeguard. Only the world executable and PDB were overwritten; both destination SHA-256 values matched the locally tested outputs:

- `mangosd.exe`, 20894720 bytes: `0382C5488B92CCB5E7C82803F976FBA97BF156CC8E8743C01F562A5A412DEEE4`
- `mangosd.pdb`, 230428672 bytes: `1E05BD446852CBF470BDB17FA7F1C1AC82275DBDB91634C95DC7052BE63510EB`

Production configuration remained at 6000 bots, 1000 bot accounts, activity 10, tile unloading enabled and architecture diagnostics enabled. No database, configuration, realmd, data-file or DLL changes were made. No server was started. Live crash/latency acceptance remains outstanding.

## Permanent architecture coverage

### September 5 full-port reconciliation and maintenance follow-through

The current source comparison additionally uses ManTech TBC `b4354d59d`,
WotLK `9f47f9a121` and the unified playerbots tree `811d6f1e`. The separate
`playerbots-tbc` and `playerbots-wotlk` directories are older than that unified
tree. In particular, the dedicated idle worker handoff from TBC `03e066156`
and Arch 3 `52270e962`, plus playerbot revisions `74372022`, `407f4cd5`,
`394afced` and `811d6f1e`, were compared with Turtle rather than assumed present.

Changes in this candidate, beyond the previously deployed architecture:

- Dedicated shared idle-AI workers now receive one serial batch per map. The
  submitting map owner waits for completion before continuing. This matches
  ManTech's later threat-state safety correction; there is no per-bot parallel
  mutation of one map. `MapUpdate.IdleBotThreads = 2` is the default (0 runs
  inline; restart required). Workers initialize/end their MySQL thread context,
  drain accepted work on shutdown and propagate failures to the waiting owner.
  Diagnostic attribution follows the joined handoff without resetting its map.
- Area-flag lookups use an index built from Turtle's own SQL area storage, with
  the original exact-map/duplicate fallback semantics. This replaces repeated
  whole-area-table scans and the header-local map fallback copies. It does not
  replace Turtle areas with a CMaNGOS DBC or change transport routes.
- Random teleport selection is resumable across world ticks: candidate copy,
  faction checks, active-area and custom race/zone filters, and destination
  attempts share one 2 ms / 8192-attempt budget. Only the active request owns
  expanded candidate arrays. GUID, map, instance, transition generation, level,
  race, combat, group and player lifetime are checked before continuing. Current
  Turtle destination restrictions remain. Weighted shuffle, occupancy snapshot,
  individual terrain calls and final gameplay commit are still atomic and can
  overrun a cooperative budget; this is not a hard real-time deadline.
- Bot session work now uses a shared 2 ms / 8192-attempt slice with a GUID cursor,
  in addition to the existing per-session packet limits. Login admission counts
  outstanding holders, rejects duplicate requests, rechecks the target on
  completion and expires/clears failed login markers. Sync candidate scans resume
  under a 512-attempt / 2 ms budget; async queued admissions also recheck capacity.
  These limits do not encode a particular total population or alter the config's
  requested bot count.
- ManTech's bounded one-second spell-capability cache and early invalid/unknown
  spell rejection are included. Race-trigger pruning uses learned spells so
  Turtle race IDs do not inherit expansion-specific assumptions. Trainer,
  auto-learn, target, LFG, loot-roll and explicit summon guards were reconciled;
  corpse zone checks use terrain coordinates instead of a stale corpse map.
- Bot event reads cache absent rows as well as present events. Expired transient
  cache entries are reclaimed in slices, while permanent spec/init/selfbot state
  stays. Cache access is synchronized across map actions and world maintenance;
  synchronous SQL reads happen outside its mutex, with generation/merge checks
  protecting writes, removals and resets. No SQL schema migration is required.
  AI cache-size estimation uses maintained byte estimates, not a full object
  walk; the figures are estimates, not measured process RSS.

Temporary TD13 additions: `TW_TELEPORT_PLANS` reports planner backlog and stage;
`TW_WORLD_TASK_SLOW` identifies atomic owner callbacks taking at least 50 ms;
`TW_BOT_HANDLER_SLOW` identifies synthetic opcode handlers taking at least 25 ms.
The slow records are rate-limited and controlled by architecture diagnostics.
`PLAYERBOT_CACHE_MEMORY` extends existing cache telemetry. Remove these probes
only after settled-load action latency and queue convergence pass acceptance.
`MANTECH_IDLE_AI` is the startup marker for worker count/ownership policy.

The native Turtle movement broadcaster, adaptive visibility/respawn and keyed
SQL lanes remain intentional engine-specific implementations of those features;
no overlapping second controller was added. Expansion gameplay/balance changes
are not architecture ports. This is not a byte-for-byte CMaNGOS replacement,
nor proof that every reference hunk or every gameplay subsystem is identical.

Validation covers compilation, executor initialization/failure/drain/reuse,
joined diagnostic ownership, area-index equivalence, resumable stable filtering
and the existing navigation/content-hook tests. Synthetic populations up to
20000 do not simulate live bots. Acceptance still requires the chosen live bot
population to converge and cast/melee/loot input latency to improve, then checks
of transitions, bot following, transports, trainers and instances. The previous
live improvement was around 1000 bots, not a validated 6000-bot result.

Deployment verification for this candidate: the full Windows x64 Release build
completed, the follow-up reported no pending work, and `mangosd --version`
exited successfully using the existing runtime DLLs without starting the realm.
All ten standalone tests passed ten consecutive times in both the ordinary and
AddressSanitizer builds. Those tests are not a live gameplay/load simulation.
The executable still reports the checkout's archived/unknown revision string;
use the hashes below to identify this build, not that version string.

With the world port not accepting the bounded connection probe and exclusive
read/write opens acquired on every destination before writing, these share-root
files were overwritten and their destination SHA-256 values verified:

- `mangosd.exe`: `E8160A4B304CFBAF00BEB8385E2061EC9627BB1030BF5CE977ECA78972347510`
- `mangosd.pdb`: `6EEB5CC1960CCC4914E3B60AA17C7D5BD8B403F2E17E4AC1B4C4E16FDFF65F37`
- `mangosd.conf`: `6D8D2A23228E6170C9774613A597725C45D75DE6D7E45620ED814FA4446E3DE4`

The only configuration addition is `MapUpdate.IdleBotThreads = 2`; all prior
lines were compared before replacement. The bot config remains untouched at
1000 minimum/maximum bots, 1000 accounts and activity 10. No production SQL,
realmd, DLL or extracted-data change was necessary or performed. No server was
started. Deployment is complete; live acceptance, especially at 6000, remains
outstanding.

Reference revisions reviewed: ManTech Classic `2b03fc85b` (Arch), `ec6ae5a74` (Arch 2), `8870edeeb` (Arch 3), and the later `7112fdd6b` per-map AI serialization correction. Playerbot reference: the ManTech integration tree through `407f4cd5`, including transition revisions `2ec313e4`, `f7086751`, `e7326160` and Arch 3 `74372022`.

This is an architectural adaptation, not a blind cherry-pick or a claim that the two engines are identical.

| Area | Turtle implementation |
|---|---|
| Shared map ownership | Existing rework: shared map-owner pool, manager join/completion/transfer phases; no worker-to-worker continent barrier |
| Cell workers | New: bounded shared discovery workers, minimum-work threshold, chunk limit, joined timeout with serial cooldown; ordered GUID-resolved gameplay updates |
| Object packet workers | New: shared disjoint serialization batches, owner-thread sends after all jobs join; Lua-enabled builds use inline serialization |
| Old overlapping workers | Per-map object pool removed; old concurrent cell path removed; motion/visibility mutation workers clamped off |
| Player priority/core cadence | Existing real-player/companion priority, GUID-staggered background work, bounded elapsed catch-up retained; cached player-work lists now store GUIDs instead of pointers surviving a logout/transfer |
| Bot AI scheduling | Map-owned serial execution; count/time budgets, minimum progress, GUID round-robin, age promotion, gradual budget recovery |
| Population/admission | Existing target reconciliation and retry backpressure retained; async completion batches bounded; optional soft/hard/recovery memory guard added, disabled by default |
| SQL | Existing asynchronous reads and owner-thread budgeted callbacks; unkeyed writes now ordered on worker 0; explicit keyed read/write chains retain Turtle's lane contract; fair priority bursts and full shutdown draining |
| Bot transitions | Owner-thread handoff, generation invalidation, deduplicated cancellation, bounded portal retry/timeout, official trigger geometry and reachable path validation |
| Bot caches | Existing staggered value-cache expiry retained; bounded failed-action retry cache and context-keyed path-failure backoff added |
| Navigation/movement | Existing per-thread Detour queries retained; model-query table locking fixed; finite/zero-motion spline checks; existing global spline IDs retained |
| Movement networking | Native broadcaster retained; socket lifetime/queue locking fixed; safe stats snapshots and actual slow-map publication; reconfiguration re-buckets listeners once; coalescing limited to consecutive compatible heartbeats, preserving transition/ACK packets |
| Listener/network buffers | Existing kernel/user output buffer controls retained; configurable bounded listen backlog added |
| Adaptive visibility/respawn | Turtle's native per-map visibility/grid adaptation and dynamic-respawn logic retained; no duplicate respawn controller |
| Diagnostics/operations | Existing nonfatal watchdog, crash breadcrumbs, console QuickEdit protection and startup log rotation retained; repeated runtime DB-script warnings coalesced with counts; temporary probes listed above |

Deliberate differences from reference: idle AI is serialized within each map following the later ManTech correction. Cell timeout drains running jobs before falling back; it never detaches work holding world pointers. Age promotion stays within a hard batch limit instead of dispatching every overdue bot at once. Memory pressure slows/pauses only new background admissions; map-owned cache expiry is not replaced with a global AI-cache mutation pass. Existing queued SQL operations with a serial ID keep their ordering contract instead of being routed blindly into separate pools.

Unrelated gameplay edits bundled in reference commits (specific Bloodthirst/racial spell changes, expansion IDs, balance and convenience items) are not architecture and are not imported over Turtle content. No quest, boss, loot-table, transport route, account-rank or database-schema migration is included in this package.

## September 4 architecture package validation (historical)

The standalone suite checks executor concurrency, varying work populations, exact-once task processing, failure/drain/reuse behavior, timing histogram bounds/context restoration and static preservation of gameplay hooks. All three tests passed ten consecutive repetitions in both the ordinary and AddressSanitizer builds. Work sizes include 8, 156, 186, 1,000, 4,000, 5,217, 6,000, 3,000 and 20,000 with zero, one, two and four executor workers. These are synthetic task counts: the tests do not emulate that many players or validate every boss/quest.

Both full Windows x64 Release targets built successfully on September 4, 2026. A second build reported no pending work. The final ordinary and AddressSanitizer standalone test runs also passed. Both executables exited with code 0 through their `--version` paths; neither check started a server or connected to the database. Live latency, bot population convergence and gameplay regression checks remain required after the user starts the candidate.

Candidate SHA-256 identifiers (use these to distinguish this package from earlier builds):

- `mangosd.exe`: `59317D4032DB2D6ABE077B18E77A51DA7A450C8D8E0598C3FAE5A730D38E3618`
- `realmd.exe`: `F3501268496A270805DD7D161C3AE97D04219D58A61522BB172C340FED6B21F4`

Historical deployment for the September 4 package: with world and login stopped, copy the two executables, matching PDBs and two configuration files from `ARCH_REWORK` over the corresponding files in the Turtle share root. Keep the existing `realmd.conf`, DLLs and extracted data. No SQL is required. This is not the deployment instruction for the newer September 5 world-only candidate above. Server startup is left to the user.

## Evidence to capture after user starts the candidate

Keep the chosen 6,000-bot population and activity settings. Record population and client actions during loading, then after population settles. Match diagnostic tick/map identifiers to existing `GAMEPLAY_INPUT_DELAY` records. Compare time spent selecting/discovering cells with time updating creatures/AI, pathfinding, DB waits and map queue delay. Use a short CPU/wait stack profile only if elapsed timings leave unexplained waits. Do not infer average latency from slow-only warnings.

## Removal acceptance

### September 5 maintenance slices and TD11 candidate

Reference review used the local `mangos-classic-full-arch`,
`mangos-tbc-mantech-integration`, and `mangos-wotlk-mantech-integration` core
trees plus `playerbots-mantech-integration`, `playerbots-tbc`, and
`playerbots-wotlk`. These are source references, not a claim that each working
tree exactly matches its currently deployed binary. All three inspected
`ahbot/AhBot.cpp` files have SHA-256
`E969C782C00B13A596ACB831AF803B84BD903E4DC6B11C507825B0766A92BD28`.

The reference auction scans run in a background thread; winning bids call
CMaNGOS `AuctionBidWinning`, and ordinary bids persist their bid without
finalizing the sale. Turtle instead hands purchase/mail completion to the
world owner and contains extra direct-equipment work. The candidate retains
that existing ownership boundary and bounds the completion queue; it does
not port raw auction pointers across threads or alter the current purchase
semantics. Both implementations rebuild an auction mirror and use a shared
auction-action mutex, so those alone are not proof of the lag cause.

CMaNGOS random movement advances the waiting timer only after spline completion
and backs off after failed location selection (100 ms controlled, 500 ms
otherwise). Turtle's new failure delay uses a GUID-staggered 1-2 seconds while
retaining its custom successful wander cadence. Reference maintenance also
counts successful ProcessBot operations; bounding every attempt is an explicit
Turtle safeguard rather than a claim of a verbatim CMaNGOS port. The TBC/WotLK
map schedulers' budget/round-robin pattern is the reference for fair admission
to each slice. Existing Turtle map-owned AI scheduling is retained.

The preceding random-motion optimization did not pass live acceptance: at about
5,975 bots the world continued to stall for seconds; a subsequent run targeting
1,000 also showed intermittent world-tail stalls over one second. Neither the
shared ikebots ancestry nor aggregate CPU/RAM proves the responsible operation.

This candidate counts every maintenance candidate against RandomBotsPerInterval
(default fallback 64) and stops between operations after 5 ms. The existing GUID
cursor resumes on the next pass. Group/taxi eligibility is checked before cache
cleanup. Loading characters are excluded from ghost homebind recovery. Failed
random destinations retry after 1-2 seconds rather than every tick; successful
wandering keeps its previous delay. Auction completion queues alternate FIFO
purchases/propositions, at most four operations or 5 ms per world tick. A single
operation is atomic and can still exceed the cooperative time budget.

TD11 adds `TW_WORK` summaries to perf.log using the existing diagnostic enable
switch and report interval. Timings are inclusive and nested; do not add parent
and child totals together. Fields include map/instance, count, total, mean,
histogram p95 bound, maximum and slowest GUID. Phases distinguish bot sessions,
teleport ACK/homebind recovery, activity scaling, memory telemetry, population
and individual maintenance, facing/location logging, auction mirroring,
auction purchases/propositions/cleanup, random-motion mutex wait, destination
selection and spline launch, targeted-motion wait/location, navmesh query
lookup, nearest walk polygon, random nav search and height lookup.

ExecutionWatch now restores enclosing phase/start/GUID on return. The old
`bot-maintenance` marker remained set during later auction work and could not
prove that the manager itself consumed the entire reported stall. New nested
markers distinguish those operations and identify movement lock/target waits.
Auction action and mirror locks use RAII to prevent a caught exception from
leaving the mutex permanently locked. This is preventative; no lock leak has
been demonstrated in the live run.

No database migration or population/config change is required. The candidate
must be tested with the user's chosen population and real cast/loot inputs;
build and synthetic tests alone do not establish a latency fix. The Fireball
animation report is part of that validation, not a reason to change spell
durations or globally discard elapsed simulation time.

Remove/disable temporary measurements only after the implicated code is fixed and the same workload shows improved action latency, stable population, and no regression in combat, loot, instances, transports, trainers, and bot following. Preserve ordinary crash/error logging and lightweight stall breadcrumbs. A successful build/unit test is not this live acceptance test.

## 2026-09-05 audit correction instrumentation impact

Stall follow-up adds one ordinary error message, `Playerbot travel search failed
for bot ...`, only when consuming an exceptional async result. It is not a
per-tick probe, has no new counter/timer/storage, and should remain as normal
error reporting. Each failed future is consumed once; repeated failed searches
can produce repeated errors and should be investigated, not silently suppressed.
Existing stall breadcrumbs remain diagnostic-only. The retained pending future
and scoped permit release are lifecycle corrections, not temporary diagnostics.
The historical stall has no captured process stack; passing regression tests
does not prove its exact cause or guarantee that another blocking path is absent.

No new runtime probes or log streams were added by the audit fixes. The generic
failed-action cache and redundant spell-capability cache were removed, including
their storage/pruning and failure-cache atomics. Existing telemetry field names
remain for compatibility but report zero for the retired caches. This is not a
disabled diagnostic hiding active cache work. The four old failed-action cache/
retry configuration settings are ignored; path-specific retry settings remain.

The new tests/audit collectors run outside the server and add no production tick
work. Existing ExecutionWatch clocks/atomics and other TD probes remain and still
require their own overhead/cleanup evaluation. The candidate has not been
profiled at 6,000 bots. See `docs/AUDIT_FIXES_2026-09-05.md` for remaining gates.

Aura/loot follow-up adds no runtime logging, counters or timed probes. Four
native aura-list slots per Unit and the corresponding native calculation hooks
are functional state, not temporary diagnostics. Skill-index lookup is gated
on a nonempty skill-cast aura list. Their total runtime/memory effect has not
been profiled. Source/DBC/DB audit outputs and fragment tests run externally.

## 2026-09-05 CMaNGOS bot behavior integration

Supersedes the retired-retry paragraph above: the existing retry config keys
now control a bounded CMaNGOS cache for autonomous NONCOMBAT Execute failures,
after native prerequisites/usefulness/possible checks. Combat, reactions,
high-priority actions, explicit packet/owner events, real-player AI and bots
following real players are excluded. Movement, resources, reset and transitions
invalidate it. Impossible predicates are never suppressed (that gauge is zero).

The existing failure/cache telemetry getters now return actual relaxed-atomic
counts, including expiry/eviction. No new log stream, per-action print or timer
was added. FailedActionRetryBase=0 or FailedActionRetryMax=0 disables caching;
empty caches skip key construction and pruning. Cache bounds default to 64
entries per engine and 30s TTL, with a default 2s maximum retry delay. State and
counters are functional retry/measurement overhead, not free when enabled.
This has not yet been profiled with the new build at 6,000 bots.

BotRetryIntegrationTest and BotTaxiIntegrationTest exercise extracted native
functions with deterministic stand-ins. Both suites passed Release and ASAN;
they are not a live route, encounter or per-class combat certification.

The subsequent RPG movement correction adds no logs, timers, permanent per-bot
cache or diagnostic counters. The occupancy tally is local to target selection
and replaces repeated scans; its lifetime ends with the call. BotRpgMovementTest
runs externally. Candidate inspection restores the temporary next-action value
so the existing debug command cannot leave proximity checks overridden.

## 2026-09-05 Southshore area behavior trace (temporary)

`AiPlayerbot.BehaviorTrace=1` enables `TW_BOT_BEHAVIOR` in the existing core
performance log. Map/X/Y/Radius select the area (default map 0, -800/-530,
200 yards; instance 0 only for enrolling a new sample). Sampled GUIDs continue
to be observed after leaving that area or changing maps/instances. This is
independent of EnableActionLog/BotLogFile.
It does not enable the old global per-bot action/aura files or console spam.

Limits are fixed: 12 GUID-only slots, 8 accepted lines per bot per second,
8,000 accepted lines per process and ten minutes from the first eligible event.
Slots not seen for 30 seconds can be replaced; named bots need not be chased.
One of the eight per-second slots is reserved for a periodic position/spline
sample (at most one every five seconds). Generic engine-action text is also
limited to one every five seconds per sampled bot. Other event records share
the remaining seven slots; the 8,000-line/ten-minute caps still apply.
An END marker records completion on the next eligible call. Each record has
a sequence and cumulative suppression count: this is sampled evidence, not a
complete event transcript. The limit is process-wide and starts over on restart.

Hooks: Engine terminal action messages, RPG selection/cancellation/next-action,
RPG approach rejection/movement results, and shared taxi activation rejection.
Snapshots include position, motion, combat/AFK/taxi flags, master GUID, RPG
target GUID/entry/coordinates, next RPG action, travel state/entry, path size,
next waypoint and final destination. No player account credentials are recorded.
September 6 adds an AI-owner entry hook for periodic progress, including during
taxi flight or action waits: monotonic tick, instance, enrollment-area flag,
level, group leader, travel purpose/goal, next leg type/entry, spline ID,
elapsed/duration/finalized state/endpoint, target lifetime and retry counts.
Spline timing is read only when the native `MoveSpline::Initialized()` check
passes. A freshly allocated or cleared spline is recorded with zero timing
and `spline_initialized=0`, not treated as a completed valid trip. A non-null
MoveSpline pointer alone does not satisfy Duration()'s storage precondition.
GUID + ordered ticks + goal/purpose changes let the log reader reconstruct
sampled journeys; gaps and the END marker must not be treated as arrivals.
Manual AI values are read on their existing owner; no action/trigger is run by
the trace and no entity pointer is stored across calls.

Overhead: disabled is a boolean gate (Engine also gates before calling); enabled
checks eligibility and a small mutex-protected 12-slot limiter. Retaining bots
outside the area means enabled calls outside the area also check that limiter;
unsampled remote bots cannot enroll. Only admitted
records read manual state/format/write. After completion an atomic gate prevents
further sampling work. Logging cost is not zero or yet benchmarked live.
To disable, set BehaviorTrace=0 and restart; removal sites are BotDiagnostics.h/
.cpp, PlayerbotAI.cpp, Engine.cpp, ChooseRpgTargetAction.cpp, MoveToRpgTargetAction.cpp,
RpgSubActions.cpp, MovementActions.cpp, PlayerbotAIConfig.h/.cpp and the template.
BoundedBotTrace.h and BoundedBotTraceTest are diagnostics-only support.
Do not remove the unrelated behavior fixes when retiring these hooks.

26/26 tests passed in the normal and ASAN builds, including caps, slot turnover,
rate limits, timeout and clock wrap. Native taxi/RPG fragment tests run with
no-op diagnostic hooks; full compilation checks their production wiring.
Live trace output and the underlying repeated-travel cause remain to validate.

### September 6: enabled-snapshot startup crash

The extended trace introduced an unchecked `MoveSpline::Duration()` read for
newly loaded bots before their first movement. Dump `crash_20260906_024603.dmp`
from executable SHA256 `02D7A8BA06B4657427B1AAD086880859E1C97C4673B5BEB3229AAB7A170EA8CD`
faulted at RVA `0x5e4e91`, inside TraceBehavior. The fault instruction reads
`[rax+rcx*4]` with both registers zero, matching the empty spline-length array
indexed by the native Duration() method. This was introduced by diagnostics,
not a user account-reset mistake or proof that the movement correction failed.

The caller now guards native initialization before any spline snapshot reads;
the shared movement API is unchanged. `BotTraceSnapshotTest` executes the
complete enabled trace body and native Duration() accessor with checked
stand-in storage. It failed before the guard, then passed for absent, fresh,
active, completed, cleared, and transferred bot snapshots, plus disabled and
ineligible admission. Earlier limiter/dispatch tests did not cover this enabled
snapshot boundary. Full realm startup remains a separate user-run validation.

## 2026-09-05 Southshore trace result and retirement

The bounded trace completed normally: 7,185 records were admitted and 17,771
were suppressed before the ten-minute cutoff. It repeatedly captured valid
Southshore travel paths reaching the flight-master position, followed by
`taxi_reject: no matching interactable flight master` and native travel-target
failure/cooldown. The production configuration is to return to
`AiPlayerbot.BehaviorTrace=0`; the compiled bounded facility remains dormant for
future targeted runs.

Taxi service discovery now uses the core's live
`Player::FindNearestInteractableNpcWithFlag` grid query at interaction time,
then verifies that NPC resolves to the requested source node. It no longer
depends on the generic cached `nearest npcs` AI value after a long route. Native
interaction, faction, learned-node, endpoint, cost and activation checks remain
in force.

A crash dump from the same run established a separate heap-corruption fault in
expired AI-value cleanup. The manager pass was erasing a bot's context map while
the map worker evaluated it. Cleanup is now requested atomically and executed
only inside that bot's serialized `UpdateAI` path. Named context maps also use
the same recursive-mutex protection as the established CMaNGOS implementation,
and predicate inspection plus erase is one locked transaction. This is a
functional safety correction, not temporary diagnostic overhead.

Release and AddressSanitizer architecture suites pass 26/26, and the complete
optimized Windows world server links successfully. Live 6,000-bot stability and
Southshore route behavior still require production observation; no server was
started by the build process.

## September 6: exact NPC-interaction rejection trace

The 02:56 startup's bounded sample ended at 03:08:17 with 2,768 records and
983,078 suppressed attempts. Of these, 85 records report no matching flight
master. The prior summary message alone cannot distinguish failed discovery,
native interaction rejection or a mismatched requested source node.

The next diagnostic build forwards the real UseTaxi path ID into TraceBehavior.
Only an admitted taxi-rejection record runs an additional 20-yard raw
flight-master search through Cell::VisitAllObjects (no grid loading). It reports
taxi_path, taxi_from, taxi_to, taxi_probe, npc_guid, npc_entry, npc_node,
npc_source_match, npc_distance, npc_alive, npc_combat, npc_flags,
npc_interactable and npc_reject. The probe includes dead/unavailable flagged
NPCs so rejection is observable. It uses the native CanInteractWithNPC predicate
with an optional const-string reason output; no copied eligibility rules,
mutation or NPC substitution occurs. Activation records retain path IDs but
do not probe the post-activation NPC state. Probe observations describe the
nearest flagged NPC at trace time, not the earlier cached candidate list.

Interpretation: npc_reject identifies the first native failure. An interactable
NPC with npc_source_match=0 indicates the nearby service is not the requested
source. An interactable matching NPC after a failed gameplay lookup points to
the discovery path. npc_missing means no flagged NPC was found within the probe
radius, not proof that the creature has no database spawn.

This retains BehaviorTrace's 12 slots, 8 records/bot/second, 8,000 records and
10-minute process cap. Formatting/scanning occurs after admission, never when
disabled or expired. Additional scan/format cost is bounded but unbenchmarked;
the optional native reason argument also adds unmeasured small branch/call
overhead for ordinary interaction checks. Disable with BehaviorTrace=0 at the
next coordinated restart. Removal sites: the taxiPath argument/calls,
DiagnosticFlightMasterCheck and DescribeTaxiInteraction in BotDiagnostics.cpp,
and the optional reason output in Player.h/Player.cpp. The tests identify the
added diagnostic contract; no functional flight or destination change is part
of this update.

Release architecture tests passed 32/32. NpcInteractionTraceTest covers every
native predicate exit, default/no-reason equivalence, 4,096 combined failure
states, unavailable/missing NPCs, source mismatch, both mock map containers,
range and malformed-path snapshots. BotTraceSnapshotTest verifies fresh-spline
safety and that disabled/expired/rate-rejected snapshots do not run the probe.
These two tests and BotTaxiIntegrationTest also passed AddressSanitizer.
The full optimized world executable and PDB linked successfully at local
05:41 on September 6. The formatted snapshot also passed the AddressSanitizer
recheck. No mangosd/realmd process was started. Deployment and the subsequent
live rejection capture remain pending the user's shutdown confirmation;
production files, configuration and database were not changed by this build.

Deployment follow-up: after the user confirmed shutdown, exclusively opened
and overwrote only the share's mangosd.exe/PDB and verified SHA-256 against the
tested local artifacts. EXE: F5FFFF3C165F792DF4405E9ADF7DC94ED72C5A98E3487A8D1FB42EC670859EC7.
PDB: CB7C167ABBED940506399F357102B9EC3C9FA6761D5143BC9F1CC389D968EE11.
Both production configs were hash-verified unchanged; BehaviorTrace remains 1
for the Southshore sample, bot count remains 6,000 and account deletion is off.
No DB writes or server start were performed. Runtime rejection evidence from
this new build is still pending the user's next startup.

### Live result and flight-cache correction

The 03:45:06 startup produced the needed evidence: interactable Darla at node
14 while bots request path 272 (native source 71/destination 5). The full
read-only audit found all 270 bundled flight edges using mismatched IDs; all
have unique current replacements and complete native geometry. See
BOT_TECH_INTEGRATION_2026-09-05.md for the source provenance and audit limits.

The functional startup refresh adds one bounded summary in TravelNode.cpp:
`Refreshed N bot taxi links from native data (C corrected cached IDs, I incomplete paths skipped)`.
With the audited, unchanged production data, expect N=270, C=270, I=0 on the
first and subsequent startups (SQL is intentionally not rewritten). This is
one startup graph pass, not a per-tick scan; wall-clock cost is unmeasured until
the next startup. The bounded BehaviorTrace remains unchanged for validation
of the actual flight activations and progress, then should be disabled at a
coordinated restart. Do not remove the functional startup refresh when removing
temporary diagnostics.

The new executable is SHA256
`655B9E4BCBD0D77ACAB08A3732479F15AC9FB087D7412CC36EBDBB10D8BA61C8`;
its matching PDB is
`7700575960D7F081DF4F04BF0C6DA59DA1F4A113B1187C6FFD2D4A27DA9B58B2`.
No mangosd/realmd process was started during building/tests. The user confirmed
shutdown before replacement; deployment verification is pending below.

Deployment completed after shutdown confirmation: replaced only mangosd.exe
and its matching PDB on `\\10.0.0.109\turtle`, with exclusive destination
handles and exact SHA-256 verification against the hashes above. The world
port was not listening. Both production config hashes remained unchanged;
no DB writes, bot resets, backups or server starts occurred. The final Release
suite passed 33/33, including the captured source-mismatch adapter case; both
taxi tests passed AddressSanitizer. Source indexes were regenerated without DB
refresh. The user's next startup/flight observation remains the live acceptance
step, not a completed gameplay validation.

Live acceptance follow-up, session `server_2026-09-06_04-21-25.log`: at
04:22:54 the native startup summary reports 270 refreshed links, 270 corrected
cached IDs, zero incomplete paths skipped. The user observed bot departures
from the Southshore flight master. The new-run bounded sample through 04:26:22
contains 524 behavior records, six accepted taxi activations and zero taxi
rejections. Paths 17 (14->6), 99 (14->7) and 101 (14->16) are represented.
Silnorion subsequently has taxi=0, spline_done=1 and position near Refuge Pointe;
Morence has taxi=0, spline_done=1 near Menethil. Melias shows advancing flight
time/position toward Ironforge. This verifies actual departures, progress and
two completed flight legs, not merely an activation return code. It does not
certify every route, all bot destinations or full-population crowd distribution.
Checks were read-only against production; the bounded trace remains unchanged.

## September 7 upstream integration controls

SOAP configuration lives beside `Console.Enable`: `SOAP.Enabled = 0`,
`SOAP.IP = 127.0.0.1`, `SOAP.Port = 7878`. Settings are read at startup.
Disabled SOAP creates no listener or worker. Enabled SOAP logs bind success
or failure, requires an administrator game account, retains its command
permissions, and joins before database shutdown. No per-tick SOAP tracing was
added. The live config received these three disabled defaults with a backup;
other settings, including bot activity and auction settings, were preserved.

DungeonClear's existing bounded empty-menu diagnostic remains under
`TurtleDiagnostics::enabled`; resolving a supplied action in a nonempty menu
uses the native select packet and adds no shared throttle or per-tick logging.
The production build keeps DungeonClear disabled. Unit tests exercise its
gossip selection function; they are not live dungeon acceptance tests.

### Auction owner notification guard (upstream 6a2ddc82)

The notification function returns immediately for a socketless session.
Its client packet, notification-specific log and packet-send hooks are skipped;
the caller's settlement/mail logic and logging remain. There is no new config
key, SQL migration, diagnostic loop or background work. Current bots have no
handler for this opcode. The upstream report describes live verification, but
the supplied crash text has no faulting instruction or matching binary snapshot;
keep the underlying memory-fault diagnosis open. Focused native-fragment tests
cover notification payloads and continuing mail operations, not production
network/database durability or a replay of that crash.

## Thorn Gorge prototype status (2026-09-08)

`.bg thorn` inside a Thorn Gorge instance prints scores, node progress/ownership,
flag state and elapsed time through the existing administrator BG command.
It runs only on request. Optional match logging is described below. No global polling or DB writes are added.
Feature control: Battleground.ThornGorge.Enabled (default 0; restart required).
The opt-in match samples at most 30 members across four nodes once per second
and publishes native HUD updates. Lifecycle announcements are match messages.
See docs/THORN_GORGE_PROTOTYPE.md for activation, provisional values and removal.


## Thorn Gorge match logging (2026-09-08)

The native `BgLogFile` receives structured `THORN_GORGE schema=1 map=821`
records. With `LogsDir="logs"` and `BgLogFile="bg.log"`, read `logs/bg.log`.
Other native battleground messages remain in the same file. Each structured
record includes an instance ID; snapshots also have a sequence number.

`Battleground.ThornGorge.LogLevel` defaults to 0 (off). Level 1 logs lifecycle,
joins/leaves, deaths, node ownership, flag requests/rejections/pickups/drops/
deliveries/resets, setup failures, and team/node snapshots. Level 2 adds each
member's GUID/name, socket presence, position, health, combat/ghost/GM/mount/
carry/cast state, victim, selected objective and scoreboard counters. A
socketless session is reported as such; it is not an identity guarantee.
Objective coordinates describe a selected destination, not proof of arrival.

`Battleground.ThornGorge.LogIntervalMs` defaults to 5000 and clamps to
1000-60000. Settings are read on match Reset; restart with the new binary and
configuration for the next test. Start/end also emit snapshots. `.bg thorn`
requests an extra snapshot at most once per configured interval. Team values
are 0=Alliance, 1=Horde, 2=neutral; `match_end related` uses native winner values
469=Alliance, 67=Horde, 0=tie. Flag values are 0=center, 1=carried, 2=dropped,
3=respawning. Node indexes 0-3 follow the locations listed in the prototype guide.
Node nearby counts describe the last once-per-second capture sample.

Events are capped at 64 per match simulation-second, except critical lifecycle
and setup failures. Suppression counts appear on the next snapshot. After a
stall only one periodic snapshot is emitted, without a catch-up burst. Level 2
normally adds at most 35 snapshot lines per interval for a full 30-player match.
The existing logger flushes each line synchronously on the match owner thread;
live disk/CPU overhead is not yet measured. Use level 1 or a longer interval to
reduce detail, or level 0 to disable it for new matches. No extra thread, SQL
write, or global scan is introduced. Off mode returns before formatting or
walking players for diagnostics. Existing BG logging must also be enabled.

This is event and sampled-state telemetry, not every packet/spell/damage tick.
It cannot recover events from earlier binaries or prove that a missing final
record was a crash. Match state is in memory; character autosaves do not contain
the live score or capture timeline. New records contain no account IDs, IPs,
chat, or credentials; unrelated existing BG records may contain native session
metadata. The file uses the existing append/retention behavior; archive test
logs as needed. `ThornGorgeDiagnosticsTest` checks disabled mode, clamps, rate
limits, suppression accounting, manual cooldown and long-stall behavior.


## First live-match corrections (2026-09-09)

Match 103 ended Alliance 1600-1179 after 932 seconds of active simulation.
Patch made three flag deliveries. The initial prototype sampled capture once
per second with up to five net players; groups could take a neutral node in
five samples. New defaults are CaptureTickMs=1200 and CaptureMaxAdvantage=2:
25 samples (30 seconds) solo and 13 samples (15.6 seconds) with a net advantage
of two or more. Equal teams cancel. A full enemy takeover requires 50 solo
samples (60 seconds) or 25 grouped samples (30 seconds). These remain test
tuning, not a claim about the original release. Settings are read on Reset;
interval clamps to 1000-10000ms and advantage to 1-5. Stalls grant no retroactive
capture at a player's new location.

Native AreaPOI.dbc records 2749-2760 on map 821 define worldstates 3606-3617.
Each node's three states are neutral, Horde, Alliance; icon IDs are 5, 9, 10.
The colour ordering is independently consistent with the native AV assault
landmarks. Initial and changed states publish exactly one active icon per
node, clearing the other two. No client patch is required for the inspected
assets. Server log confirmation is not proof of client rendering; check both
teams' icons and late entry in the next live test.

Victory quests 42098/42099 use Player::AreaExploredOrEventHappens for an accepted,
incomplete quest on an online participating winner. Dead winners remain
eligible. GMs, spectators, losing/tied teams, unavailable members and already
complete/absent quests receive no new credit. Apply
sql/custom/thorn_gorge_victory_quests.sql to set SpecialFlags bit 2, preventing
completion before the victory event. Existing character progress is untouched.
Players still turn in the quest normally for its imported reward; the BG
does not grant quest items, XP or reputation directly.

Added diagnostic records: layout (actual flag XYZ and capture tuning),
capture_transition (old/new owner/progress, nearby counts, interval),
map_icon_sent (active client worldstate), quest_credit / quest_credit_skipped,
and update_delay (owner updates of at least 2000ms). Node snapshots include
active_icon. Existing event budgets apply. No packet/combat spam or extra
thread is added. Native-fragment tests exercise initial/live icon agreement
and quest filters/repeat protection; rule tests cover capture caps.

Flag position was subsequently supplied by the player using .gps on map 821,
instance 104: X=2174.469482, Y=1569.349243, Z=1160.459473, O=3.306524.
The GPS also reported FloorZ=1160.459351 and GroundZ=1160.445312. Defaults,
deployment configuration and the real-asset navigation probe now use that XY.
The native terrain/collision query still resolves Z and adds the existing
0.1-yard object offset; no fixed-height override or teleport is introduced.
The d7f50f8 binary already supports these config keys, so deploying the config
is sufficient for the next restart without another executable build. Visual
alignment at the supplied point still requires the next in-game check.
The start enclosure still uses the prototype's 35-yard countdown leash; its
physical gate has not been positioned. Screenshot feedback records that gap.

### Thorn Gorge bot progress trace (September 9)

Existing Battleground.ThornGorge.LogLevel=2 and LogIntervalMs controls also admit
one bot_ai record per bot per interval during an active match. Records use
LOG_BG/bg.log and share the match's 64-event/second budget; no global action log
is enabled. Map-owner UpdateAI samples existing engine action history (last 256
characters, whitespace escaped), cached activity decisions, minimal flag, motion
generator/unit state, initialized spline progress, path size, failure retry and
next teleport deadline. Cached flags can be initial/stale; they are not recomputed
for diagnostics. A bot with player snapshots but no bot_ai samples may not be
reaching UpdateAI. Path retry is evidence of a recent failed path, not its cause.
No spell, trigger, priority evaluation or movement is initiated by the trace.
Admission entries are erased on leave and reset; off/level1 returns before
formatting/context reads. Disable with LogLevel=0 (or use level1 for match events).
Removal sites: TraceThornBehavior, its UpdateAI hook, CachedActivity accessor,
BattleGroundTG::AdmitBotDiagnostic and m_botDiagnosticTicks. No DB change.

### Spline expired-segment guard, September 9

Adapted Shyalya 7e63fae3: a negative segment remainder emits a native error log
with elapsed/next timestamp/diff, globally limited to once per minute using an
atomic compare/exchange. This avoids a data race in the upstream static time_t
limiter under our parallel map updates. Logging runs only on the exceptional
path; ordinary motion has no extra clock or atomic access. Retain this diagnostic
until the invalid timestamp producer is understood; the guard does not certify
path generation. Location: MoveSpline::_updateState; no new config or thread.

### September 9 Thorn Gorge match 102 follow-up

Existing level-2 bot_ai samples now include pvp_nc/pvp_combat, the effective
speed-cheat flag, actual run/swim speeds, native movement flags, spline ID,
full duration, current/sent point indexes and next/final XYZ. Player snapshots
include god_hp, pvp, unit_flags and run_speed. Fields are additive to schema=1.
This separates proactive combat strategy loss, immunity/GM state, genuine speed
changes and client spline continuation defects. No AI targets or priorities are
evaluated, no terrain/path queries added and no movement initiated. Existing
per-bot interval and 64-event/second cap remain; overhead is bounded field reads
and longer log lines. Fresh splines are excluded before position/index reads.
Removal: added fields in TraceThornBehavior and BattleGroundTG::TraceSnapshot;
existing LogLevel=0 disables all TG diagnostics, level1 omits bot/player samples.
The layout event additionally records flag_scale. FlagScale defaults to 2.5,
clamps to 1-5, and is applied to both center and dropped objects at spawn.
ThornBotDiagnosticsTest checks strategy/speed/continuation formatting alongside
existing admission, disabled, reentry, no-spline and fresh-spline coverage.

### September 9 completed Horde match 101: movement observations

At LogLevel=2, TraceSnapshot now calls TraceMovement for each available member,
including human players. It rejects unloaded/foreign-map/teleporting players.
Each admitted snapshot adds one `event=movement` record per member: current XYZ,
100-yard downward floor query starting near the feet, validity and floor gap,
movement flags, unit state, motion generator, run/swim speed, mount state,
initialized spline ID/time/flags/transport and at most eight current/following
control vertices. Up to eight active speed-affecting aura type/spell/amount
records are included. No path is generated, trigger evaluated, packet captured,
position corrected, or gameplay decision changed by this trace. Use elapsed_ms,
instance, sequence and GUID to correlate the existing player and bot_ai records.

A large floor gap is not an automatic violation. Distinguish collision surfaces,
bridges, falling/jumping/knockback, spline-local transport coordinates, teleports,
mount changes and GM speed changes before attributing a fault. The sampled
vertices are control points; they are not a complete trajectory or proof of
walkability. Sampling can miss a brief path between snapshots.

Overhead at the default five-second interval: one height query and one bounded
line per member per snapshot (six queries/lines per second averaged over a
30-player match, in addition to existing logs). Work occurs on the existing BG
owner; no retained player pointers, new threads or global action logging. The
queries occur in a batch on the snapshot update. LogLevel=1 omits these samples;
LogLevel=0 disables TG logging. Existing interval and manual-snapshot limits
apply. Removal: TraceMovement, its TraceSnapshot call/declaration and the read-only
MoveSpline::GetFlags accessor if unused elsewhere. ThornMovementDiagnosticsTest
executes the native formatter and checks admission, invalid height, fresh/null
splines, bounded vertices/auras and transport context.

### Thorn native traversal decisions

TryGroundTraversal adds event=bot_traversal through the existing level2 admission budget: jump, rejected or no_safe_progress, sampled-candidate count and source/landing positions. Failed walking bots may perform at most16 native ballistic candidates per5s; those queries are gameplay decisions, not diagnostic work. Logging does not initiate them. The records share the existing64-events/second cap and per-bot interval; no history or retained players. Disable samples with LogLevel1 or all TG logs with0. Removal: the small trace lambda and calls in JumpAction::TryGroundTraversal. Preserve traversal eligibility and safety checks if removing logging.


### September 9 required-route failure admission

The existing five-second movement snapshots already captured position, speed,
mount/aura context, floor query, motion generator and bounded spline vertices.
No additional periodic sampling was needed for match102. Shared ResolveMovePath
now emits `event=bot_path result=no_route` for admitted TG bot failures with
source and requested destination XYZ. This and `bot_traversal` use the existing
level2 per-bot admission and64events/second cap. Outside TG, the generic movement
behavior works identically without TG log records. No global movement log,
retained paths/players, new threads or additional periodic height queries were
added. Removing the diagnostic branch in ResolveMovePath and traversal trace
lambda leaves generic failure handling intact. LogLevel1 omits these details;
0 disables TG logging. Detailed AI movement permission, retry cache and a5second
per-bot traversal cooldown bound gameplay query attempts separately from logs.
Monitor tick time when many bots are blocked;16candidate arcs is a ceiling,
not a guarantee that every blocked actor will recover or that geometry is sound.

## Modular migration telemetry (2026-09-12, candidate only)

The former direct `BotActionLog_*` core references are replaced by generic
script observations; `TortoiseBots/host/BotCombatTelemetry.cpp` owns diagnostic
registration and calls the module-local log helpers. `AiPlayerbot.Enabled` and
`AiPlayerbot.EnableActionLog` gate logging before AI lookup or formatting.
Without the module there is no logger and no linker stub for these events.
Damage sampling remains one in five events per unit in the existing helper.
Aura attempts precede early rejection/refresh/stack returns, and holder removal
is observed before destruction. Confirmed AURA_APPLY follows native per-effect
application (multi-effect spells can therefore produce multiple apply records).
Cast attempts precede the native spell-ID check; finish includes success/failure.
The independent bounded Thorn movement/spline diagnostics remain in place.

This is not evidence that the new AI preserves prior parallel logging safety:
the map-scheduling port and shared logger state audit remain migration gates.
