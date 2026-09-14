# Modular migration: required behavior preservation

Baseline: mantech-turtle 37aee50d6bfbf9194dd5e3c79a156d9bfcb4f569.
Migration branch: feature/modular-playerbots. Production is unchanged.

The user requires every existing feature/fix to survive the migration. Inclusion in
Git history is not proof of functional preservation. For each row, compare current
callers/contracts and run relevant tests. A merged file or passing compile is not
runtime acceptance. Do not mark complete until equivalent behavior is established.

## Current preservation status (2026-09-12)

Active source is `D:\WoW Emu\ManTech\ManTech Turtle`; runtime is
`C:\Users\root\Desktop\WorkFolder\turtle`. The relocation and authorized
old-location cleanup are complete. Live Turtle schemas use the shared MySQL
instance. Current artifact-bound receipts are in the runtime reports directory;
historical receipts below retain their original artifact identities.

| Required area | Current evidence and remaining acceptance |
| --- | --- |
| Architecture and performance | Native headless lifecycle, bounded admission/maintenance, packet and requester lifetime, shared caches, exception recovery and bounded world-action queue ported/tested. Whole-action social/commerce domains and cancellable engine/reaction continuations preserve eligibility and completion; default world AI remains synchronous. AI still runs on the world owner after maps join; joined map AI execution and remaining cross-map/world mutation contracts are outstanding. |
| Thorn Gorge | Core/assets retained; native queue/objectives/carrier/mount/traversal ports have focused tests. Client match, presentation and movement acceptance remains. |
| SOAP and admin security | Optional ON/OFF SOAP builds and native lifecycle/security tests pass; prior artifact has live authentication/rank evidence. Native command permissions remain authoritative. |
| Flight paths and movement | Native taxi handoff, path/cache geometry, route convergence, movement ownership and jump generation fencing ported. Native graph generated/restored: 2467 nodes, 8536 links, 650358 path points. Client movement/transport acceptance remains. |
| CMaNGOS AHBot | Exclusive native controller, bounded market/ownership/mail handling and tests pass. Local startup loaded the controller with 30 eligible owners. Real player trade and scale acceptance remains. |
| Module administration | Native queued refresh/upgrade/revive/strategy/remove/init/teleport/rpg/grind, reset, PID and diff commands implemented; actual disposable fixture initialization/RPG/grind/teleport receipts exist. Legacy unsafe detached-map unload/login-debug toggles are deliberately unsupported and documented. |
| Trainer/native gameplay/data | Preserved native fixes remain; trainer and source-contract tests/audits pass. Full encounter/client acceptance is not inferred from ancestry or compile success. |
| Moving transports, visibility and Who | Generic native paths retained. Full new-module network-client visibility/transport/Who acceptance remains. |
| Population and startup | Native async login/reclaim, reconciliation, bounded persistence/import and lifetime tests pass; 30-bot shared-MySQL runs and clean shutdowns pass. Native group invite/accept and stranded-session cleanup also pass. |
| Diagnostics and datasets | Default-off bounded diagnostics restored and observed in local runtime. Mature scales/weights/enchant/zone/location/help data imported additively with replay/customization tests. Native-fragment tests replaced the remaining donor-only test dependencies. |
| Guild/social behavior | Correct non-random social population and real named-channel membership; revocable requester identities; native guild admission/leave result handling and membership guards. Deterministic tests pass; client social acceptance remains. |
| Client DNS and installer | External deployed assets preserved; this relocation/port has not changed a client installation. |
| Legacy retirement | Disabled legacy source remains a donor reference until preservation gates complete. No architecture test depends on its implementation now. |

Do not enable native map AI hooks merely because shared-cache tests pass. Group,
guild, auction and cross-player actions must retain native ownership and completion
semantics. Existing native World::AddAsyncTask runs alongside map updates and is
not a safe replacement for a post-join player mutation queue.

## Baseline custom commit inventory

This is a navigation aid, not a proof that every inherited upstream change is covered.

```text
37aee50d Load console-ranked service accounts
0fe5b1d8 Allow private SOAP service to erase characters
a80ca1d1 Prepare mounts for long travel and correct Thorn gate, pickup and local defense
2aa82994 Document match 102 evidence and generic movement compatibility checks
dcb04034 Refine Thorn gate fit, map presentation and battleground timers
53a737c4 Preserve failed walking routes and share safe bot traversal across maps
e33ddcd3 Record Thorn Gorge validation evidence, diagnostics and live acceptance checks
828b2a9d Add matching Thorn Gorge bridge ramps, map companion and quest zone correction
82d2aa49 Repair Thorn Gorge navigation, gates, flag lifecycle and bot objectives
e90665b7 Apply socketless player speed changes without stale client acknowledgments
704b7821 Enlarge Thorn Gorge flags and record combat and spline movement diagnostics
150970bf Retain battleground PvP after bot resets and report Thorn flag carriers
c874726d Fix ground spline continuation origins, corners and packet timing
ae8c67e7 Adapt upstream spline crash guard for parallel map updates
611612f5 Fix Thorn Gorge flag recovery and custom battleground bot activity; trace AI progress
bea6a4f1 Place Thorn Gorge flag at the player-verified bridge coordinate
d7f50f87 Complete Thorn Gorge ownership icons and victory quest credit; tune captures
9ff73e25 Add bounded Thorn Gorge match event and player diagnostics
79d547d5 Add opt-in Thorn Gorge prototype with native battleground and bot objectives
94c76b96 Fix AHBot stock ownership before random-property initialization
f1c9f61d Verify socketless auction notifications preserve mail and player packets
c0a03bde Cover upstream lifecycle and content contracts with regression tests
d21b1782 Resolve dungeon gossip actions through offered Turtle 1.12 options
415564c7 Bind Balor explosives to native gossip and quest credit paths
4175c1f4 Preserve native bot holder lifetimes and single auction schema ownership
dd9b7b93 Make optional SOAP portable and safe across world shutdown
e50369d9 Remove Actions-based Discord notifications [skip ci]
738539c1 Add production GitHub updates to Discord
98b02c57 Resolve duplicate Wild Regeneration integration
28d3de94 Fix auction query item lifetime crash
3d6f54b9 Port CMaNGOS-style AHBot with commands and profession item supply
7ece785f Adapt compatible upstream fixes without replacing realm architecture
0c322d52 Replace category AHBot with bounded CMaNGOS market model
32d913e0 Queue AHBot rebuilds behind active checks and reserve worker ownership
d63009c6 Fix AHBot rebuild refill pacing and auction ownership
a6550e7c Connect AHBot chat commands to the auction service
07641e8f Port CMaNGOS auction bot admin commands
258e6db5 Fix playerbot travel data, movement dispatch and startup safety
cc9df979 Restore upstream playerbot taxi route preference
5d2da09e Distribute playerbot destinations and avoid ocean shortcuts
dcb7e7a4 Correct persisted playerbot route geometry
c21b36d1 Fix playerbot route convergence and stranded followers
a4c635a2 Fix playerbot flight-master convergence
9fa86b4d Fix playerbot taxi handoff at busy hubs
b68dddd3 Fix bot travel oscillation and taxi liveness
7c3405b4 Complete core audit fixes and stabilize playerbot runtime
b6be2a57 Integrate selected upstream bot correctness and gameplay data fixes
b2d5a854 Preserve native pet trainer casting and verify learning before payment
5f9c0b7a Restore native pet training alongside atomic player purchases
32826645 Make trainer purchases atomic
ccc9c650 Document diagnostic switches, residual overhead and safe removal boundaries
ff85aeba Port indexed NPC movement delivery and reusable movement workspaces; trace human world entry
3833da48 Baseline: ManTech scheduling, bounded maintenance, movement safety and measured diagnostics
d0055711 Unpublish memory monitor before static teardown
0d9d09e5 Rework map ownership, bot AI scheduling and world callback execution
01e5e7fd Bound background map work and preserve active caches
7ec05bbd Keep queried terrain cached and service queued gameplay input
b3635778 Stagger autonomous active bot updates
a95c2322 Prioritize real clients during continent synchronization
e5d50d7c Scale continent playerbot scheduling
3a6ead21 Optimize world scheduling for 6k playerbots
b77d7fbd Fix dynamic playerbot population reconciliation
4a0d35c2 Bound 4k playerbot memory growth
806ebb61 Optimize core scheduling for 4k playerbots
efc1b4c1 Make trainer purchases atomic
0e9f4853 Restore who class and level filters
713b1c27 Order visibility packets and refresh transport cache
59c900dc Rebuild moving transport lifecycle for 1.18 clients
b2a0b6d8 Prevent 1.12 client crashes on initial spline visibility
968b2e2f Send transport positions to 1.18 clients
d4072d81 Stabilize 4k bot admission and moving transports
e3bd7735 Match proven ManTech bot admission profile
9eb9e42e Repair backpressured async playerbot login
38b299cc Make playerbot event updates atomic
bfe00942 Bound legacy bot maintenance for 4k populations
7c73da2c Stagger idle bot work and repair who results
e6868400 Restore playerbots to who search results
2a07af41 Revert unstable Turtle scheduling experiment
a7ede7be Match proven ManTech bot admission profile
2a48ce12 Repair backpressured async playerbot login
cbc4961a Make playerbot event updates atomic
9f54198c Bound legacy bot maintenance for 4k populations
9132d5cc Prevent large bot waves from blocking player login
af8c8e64 Stabilize Turtle scheduling and playerbot transitions
be677aa2 fix: resolve verified Penqle gameplay reports
1dd28999 Stabilize bot startup and repair world references
3e798599 Allow assigning playable rank five
44095804 Restore GM free-flight command
5f7aa4b4 Stabilize Turtle core transports, sessions, and data
```

## Earlier validation checkpoints (2026-09-12)

Completed source checks:
- Release builds with SOAP enabled passed with TortoiseBots enabled and disabled.
  These are offline candidate builds, with Eluna and other optional modules
  disabled; they do not certify the production feature matrix.
- All 69 architecture regression tests passed (7.54 seconds). Nine focused
  regressions include auction dispatch/market/ownership/settlement, trainer,
  SOAP, selected-module taxi refresh and native command permissions.
- Some inherited regression targets still extract the retired bot implementation.
  Their success preserves a reference contract; it does not prove equivalent
  behavior in TortoiseBots. Adapt these as each behavior is migrated.
- OKF validation (26 nodes), generic host-contract and module-surface checks
  passed after the command and telemetry changes.
- Both builds completed after adapting auction readers to native snapshots and
  moving module logging ownership behind generic script observers.

Build receipts: `work/modular-bots-build.log`,
`work/modular-core-final-build.log`, and `work/modular-full-tests.log` in the
migration workspace. The saved module-enabled offline artifact has SHA-256
`EFCB108FC9BC88CB6F2701EA9102DB64431407A35C239620380E6C17AEA489E7`.

Still required before this can replace production:
- Joined map AI scheduling plus thread-safe shared module state and lifecycle
  transitions. Sagiroth currently drives all AI in the world-owner update loop.
- Live-validate ported Thorn Gorge queue/objectives/mounting; finish generic jump/transition handling.
- Compare all flight-master, taxi handoff and route-selection fixes. The current
  module now uses native coordinate pathfinding for opt-in walking generation;
  verify real map assets and route connectivity in isolated preparation.
- Remove the retired bot tree and remaining legacy command/lifetime stubs only
  after replacements and tests exist. Adapt legacy tests to active code paths.
- Review random-account provisioning, population/admission, LFT/BG fill,
  native data migration order, transport behavior and shared diagnostic state.
- Finish optional-build matrix and isolated database/client acceptance. No
  production database, running server or client assets have been changed.

### Travel checkpoint (2026-09-12)

- Active module now supplies Thorn queue/strategy/value/action behavior, mount
  preparation, safe native taxi handoff, strict ground-route handling and
  single-owner movement dispatch. Cached route geometry and opt-in walking graph
  generation use the native coordinate pathfinder.
- 72/72 architecture tests passed (5.23 seconds) in
  `work/modular-travel-lifecycle-tests.log`. Carrier/mount/taxi/path tests now
  extract the selected module. ModuleTravelGenerationTest covers startup opt-in,
  failure propagation, bounded cost work and cached geometry. CoordinatePathTest
  uses production pathfinding with real Detour tiles and mock host services.
- Other legacy tests still explicitly target reference code until ported. No
  runtime gameplay or architecture performance parity is claimed by these tests.
- The previous saved binary/hash above is historical and predates these ports.
  Current build receipts are `work/modular-walking-build.log` and the incremental
  travel build. Production databases, processes and client assets remain unchanged.


### Ground recovery and scheduler classification checkpoint

- Generic bounded jump recovery and failed-path retry invalidation are ported.
  GroundTraversalTest now extracts TortoiseBots. Native route preference test
  now includes the active module's TravelRoutePolicy.
- Core machine-driven/critical hooks are connected; the human-interest bug
  (checking the bot roster for human observers) is fixed with instance-safe
  network-player/camera checks. This is classification only. Parallel map AI
  dispatch and shared-state/lifecycle migration are still pending.
- 74/74 architecture regressions passed in 5.93 seconds, receipt
  `work/modular-ground-tests.log`. Generic jump, retry timer wrap, 64-bit
  transition invalidation and human-interest boundaries are covered.
- Baseline build cache confirms production uses Release, SOAP on, Eluna off,
  Discord off, extractors off, LTO on. Candidate checks so far use LTO off;
  the matching LTO build and final bots-disabled build remain required.
- No local MySQL/MariaDB server or Docker executable was found on PATH; an
  isolated database runtime still needs preparation. No live schema was used
  as a substitute for an isolated test instance.


### Native integration follow-up

- Fixed independent module/core SQL folder selection: our core "character"
  setting otherwise skipped the module's "char" directory. Defaults preserve
  module auth/char/world conventions; optional overrides support other layouts.
- Wired the existing generic OnReleaseToClient observer before native headless
  session replacement. The module now drops AI immediately on a valid reclaim.
- 76/76 regressions passed (9.35 seconds), receipt `work/modular-reclaim-tests.log`.
  Database dispatch tests do not execute SQL; reclaim tests use mock sessions.

Database/population findings at that checkpoint (see current status below):
- Module char migration 20260824090003 drops ai_playerbot_random_bots,
  ai_playerbot_tele_cache and ai_playerbot_rarity_cache. Its world counterpart
  drops ai_playerbot_rpg_races. They are upstream cleanup migrations, not an
  approved ManTech data migration. Preserve/reconcile legacy state before
  allowing cleanup; no such SQL was executed during this work.
- RandomBotFacade::SetValue/GetValue currently stores event values only in
  process memory. The old core persisted some event state. Save/restart parity
  requires an explicit state inventory and migration, not a blind table drop.
- The new random service scans the full pool for recovery/strategy/gear work
  once per cadence and snapshots target population at initialization. Its
  bounded admission count alone does not preserve our 6000-bot maintenance and
  dynamic reconciliation behavior.
- The core LFT.BotFill service and module randomBotLftEnabled service both exist.
  Select/reconcile one population owner before enabling generic AI-controlled
  hooks that expose new bots to the old fill service. Do not double-fill queues.


### Population maintenance port

The expensive RandomBotService recovery/strategy/gear loop is now bounded by
candidate count and a soft elapsed-time budget, with round-robin fairness and
independent timer accounting. Player/record identity is resolved again after
recovery. ModulePopulationMaintenanceTest uses 6,000 fixtures to verify coverage,
both bounds, deferred timer progression and removal safety. This addresses the
heavy-work loop noted above; cheap pool scans, persistence, dynamic population
reconciliation and parallel AI dispatch still need work/runtime evidence.


## Current persistence and isolated-startup checkpoint (2026-09-12)

The earlier test counts/build hashes above are historical. Latest regression run:
82/82 passed in 7.01 seconds (`work/modular-construction-tests.log`). Latest
module-enabled Release build uses SOAP on, LTO on, Eluna/Discord/extractors off
(`work/modular-construction-production-build.log`). The module-disabled rebuild including native DB cleanup also passed
(`work/modular-runtime-core-only-build.log`).

Resolved since the earlier findings:
- Legacy bot tables are preserved; module values now persist with one-time import,
  expiration and ordered cached writes. Real MariaDB fresh/legacy/replay cases pass.
- Cadence target reconciliation, bounded surplus removal and random-login queue
  headroom are implemented. Native role hooks select one LFT fill controller.
- Native startup now completes all core/module SQL updates on fresh isolated
  schemas. Duplicates and semantic conflicts in spell, skin and Northwind updates
  were reconciled; ten SQL assertions pass before and after two full replays.
- Partial DB worker-pool initialization now cleans up actual created workers.
- First-bot construction revealed a runtime crash in the module AI registry's
  GUID fallback. Pointer-only lookup and a regression now cover this lifecycle.

Runtime status: the corrected candidate creates/attaches a bot, survives restart,
and shuts down cleanly. Native pending-add/remove, save/logout/re-login/cleanup
tests pass on a disposable fixture. The bots-disabled candidate also starts/stops
cleanly; the deliberately partial DB worker pool exits with expected failure and
no crash. Readiness alone is not gameplay or load acceptance.
The portable MariaDB database is isolated. Production baseline, databases,
configuration, processes and client assets remain unchanged.

Still required: successful bot runtime/restart/reclaim and gameplay acceptance;
joined-map AI dispatch with safe module lifetimes/shared state; retired tree/admin
stub replacement and test adaptation; final optional build matrix; measured load
and real-client responsiveness. No complete architecture/performance parity or
production cutover is claimed.


### Runtime receipts and current diagnostic changes

- Native lifecycle: `work/isolated-gameplay/lifecycle-smoke-receipt.json`
  (ready, bot attached, lifecyclePassed=true, exit 0, no forced stop).
- Module-disabled: `work/isolated-gameplay/core-only-smoke-receipt.json`
  (ready, exit 0, no forced stop).
- Partial worker failure: `work/isolated-gameplay/partial-pool-receipt.json`
  (12 maximum DB connections, expected exit 1, no crash).
- Merged SQL replay: `work/isolated-gameplay/world-sql-receipt.json`
  (10 assertions across initial application and two replays).
- Module value import: `work/isolated-mariadb/sql-test-receipt.json`.
- Current source regression suite: 83/83, 6.87 seconds,
  `work/modular-performance-command-tests.log`.
- Full module gate passes OKF, native surface, wiring, engine tests, decision
  trail and host contract. Talent-preset DBC validation remains separately required.

Performance diagnostics now have safe shared counter/index ownership and native
`.perfmon` dispatch. This resolves that shared-state issue, but does not complete
joined-map AI scheduling, all other AI shared-state/lifetime adaptation, retired
tree/admin compatibility or live gameplay/load acceptance. No production cutover.


### Active-module verification follow-up (2026-09-12)

- 89/89 architecture tests passed in 7.82 seconds. Twenty inherited native source
  fragments now select TortoiseBots; fixture changes exposed and repaired missing
  travel, pet, Arathi, RPG movement/crowd and broadcast behavior rather than
  treating legacy test success as preservation proof.
- Packet dispatch handles reentrant producers and exception recovery without
  holding the queue lock across handlers. Stable shared-value ownership,
  synchronized caches/telemetry, and map-generation Arathi objective lifetime are
  covered by additional tests.
- Native administrator `rndbot` commands implement stats/update and bounded
  refresh/upgrade/revive/change_strategy/remove requests. Legacy reset/init,
  teleport/grind and PID control remain explicit unsupported-command gaps.
- A production-option build before the latest behavior ports sustained 30 native
  random bots for 120 seconds with telemetry active, then exited with code zero
  without forced termination. Receipt: `work/isolated-gameplay/population-smoke-receipt.json`
  in the original workspace. This is functional rehearsal, not a 6,000-bot benchmark.
- SOAP/perfmon verification from the earlier task completed successfully; the
  interrupted conversation did not mean the running check failed. Final checks
  must still be repeated against the final candidate artifact.
- Joined map AI ownership, remaining donor-only regression migration and the
  production/client acceptance matrix remain required. The disabled legacy tree
  is retained until its remaining contracts have active replacements.


### Retry preservation checkpoint

- The replacement already contained bounded retry and transition policy classes.
  Adapted those implementations to preserve prerequisite/possibility recovery,
  alternatives, immediate owner commands, and map/resource invalidation.
- BotRetryIntegrationTest now executes selected-module methods and cache;
  ModuleFailureBackoffTest adds native header policy coverage. All 90 tests pass
  (8.14 seconds). Other donor-only lifecycle/diagnostic fixtures remain identified.
- The preceding full runtime rehearsal passed: 30 bots, SOAP authorization
  positives/negatives, native queued `rndbot` commands, perfmon toggle/report/reset,
  telemetry and normal shutdown. It predates the retry policy change and is not
  substituted for final-artifact verification.


The capability/BG source audit also restored the baseline unknown-spell-data
guard, native map-template battleground classification, and proactive PvP after
noncombat strategy resets. NativeSpellCapabilityTest, ThornBotDiagnosticsTest's
map classification, and BattlegroundPlayerPresentationTest's factory fragment
now select the module. These repairs close source-level preservation gaps;
client combat/objective acceptance remains separate.


Objective memory uses the existing per-AI value context, shared by all BGTactics
action instances. Review found that action-local fields could disagree when
select/check/move actions ran on the same bot; ModuleBgObjectiveLifetimeTest now
explicitly covers shared same-AI identity as well as independent maps and bots.
The state retains only GUID, native map-work generation and selection time.


### Verified candidate checkpoint (2026-09-12)

- 90/90 architecture regressions passed (8.42 seconds).
- Both Release/SOAP/LTO module-enabled and module-disabled builds passed.
- Final required module checks passed, including 297 talent links with no failures.
- The final enabled artifact reached 30 isolated bots and held the population
  for the requested 120-second observation. Native SOAP authorization, queued
  admin commands, performance commands, telemetry and normal shutdown passed.
- Lifecycle login/cancel/save/logout/re-login/cleanup passed on the preceding
  retry build; subsequent changes concern spell/BG behavior and objective state.
- Bots-disabled isolated startup and shutdown passed. Production was unchanged.
- Final enabled SHA-256: `adb3e1878ed703fac346c42f0bf8f6f1e413cd734762b453cddfc0278909ca0f`.
- Review receipts are saved under the continuation task's `outputs/verification.json`
  and `outputs/MIGRATION_STATUS.md`. Source changes remain uncommitted in the
  existing migration worktrees; no branch was pushed or deployed.

This checkpoint is not completion of the full migration. Parallel map AI
ownership, remaining donor-only test/stub replacement, omitted legacy admin
operations and client/production-scale gameplay acceptance are still required.

### Verified ownership/lifecycle continuation — 2026-09-12T20:13:20.748642+00:00

94 architecture tests and all module validators passed. Native stranded-session
cleanup and the 1,937-row reply catalog were corrected after a failed packet-bridge
run. The corrected artifact `8c35ee67382106e8fc4e6900a89e8ed5ac11e54074be30efa07056b6986c45a8` passed packet-bridge commands/invitation,
five-second stranded recovery, cleanup and native login/save/logout/relogin checks.
Both Release/SOAP/LTO module selections built; the disabled executable also started
without bots and stopped normally. Catalog replay and customization checks passed.
Production is unchanged. No new host hook or claim of parallel AI readiness.

The earlier 30-bot receipt remains evidence for its own older artifact. This check
uses a synthetic native Network-session fixture, not a real client or live LLM.
Remaining: parallel owner/service adaptation, donor retirement/admin parity,
remaining mature data/help and client/scale acceptance.

### Verified decision recovery continuation — 2026-09-12T20:37:27.969970+00:00

95 architecture tests passed (8.90s), including native engine/reaction fault
injection and object-lifetime checks. All module validators, source-only audit and
both whitespace checks passed. The module Release/SOAP/LTO build passed; artifact
`78ee07e3cc7fa3c93b6bdbb4a5ad75cce5d0a0bce87bcd472fc0f8dc29dd22d2` reached 30 isolated bots and held the target for
95 seconds. SOAP authorization, queued admin commands, telemetry and
performance commands passed. Shutdown exited normally and cleared all online flags.

No core gameplay code or host hook changed in this slice. Prior module-disabled
build/runtime evidence remains applicable to the unchanged core. Earlier lifecycle
and packet-bridge receipts retain their own artifact hashes. No production change,
real-client test, live-LLM test or claim of parallel AI scheduling readiness.
