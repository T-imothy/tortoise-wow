# Modular migration: required behavior preservation

Baseline: mantech-turtle 37aee50d6bfbf9194dd5e3c79a156d9bfcb4f569.
Migration branch: feature/modular-playerbots. Production is unchanged.

The user requires every existing feature/fix to survive the migration. Inclusion in
Git history is not proof of functional preservation. For each row, compare current
callers/contracts and run relevant tests. A merged file or passing compile is not
runtime acceptance. Do not mark complete until equivalent behavior is established.

| Required area | Evidence / examples | Migration status |
| --- | --- | --- |
| Complete architecture work | Joined map ownership; real-client priority; bounded maintenance and admission; AI cadence; memory/cache lifecycle; safe async callbacks; 0d9d09e5, 3833da48 | Core changes retained during merge; new module scheduling adaptation and validation pending |
| Thorn Gorge | Rules, gates, spawn containment, rewards, objectives, flag lifecycle/presentation, pathing, mounting, client map/bridge assets; a80ca1d1 and predecessors | Core/assets preserved in history and tree; module bot objectives and runtime validation pending |
| SOAP | Portable optional build and shutdown; dd9b7b93; character erase 0fe5b1d8; console-ranked service account 37aee50d | Retained; optional builds and lifecycle regression pass; live service behavior pending |
| Flight paths and movement | IDs, cache geometry, route convergence, distributed destinations, taxi handoff; b68dddd3 through 258e6db5 | Native taxi-ID/sparse-node/cached-cost refresh ported; selected-module regression passes; handoff, route selection and movement audit still pending |
| CMaNGOS AHBot | Bounded market, profession supply, overrides, rebuilding, ownership/mail safety; 0c322d52, 94c76b96 | Ported to TortoiseBots/ahbot with exclusive controller selection; focused market/ownership/settlement and command tests pass; module-enabled build passes; runtime validation pending |
| Admin commands | AH commands; playable rank five; GM flight; SOAP/account permissions | Preserve native command security/behavior and migrate module-owned commands deliberately |
| Trainer fixes | Atomic purchases 32826645; native pet cast 5f9c0b7a; verify learning before payment b2d5a854 | All in baseline ancestry; TrainerPurchaseTest passed on candidate; live trainer variants pending |
| Moving transports and client visibility | 59c900dc, 968b2e2f, 713b1c27, b2a0b6d8, ff85aeba | Retain packet order, lifecycle and 1.18 compatibility; verify related movement paths |
| Who results | Bot visibility and class/level filters; e6868400, 0e9f4853 | Preserve core filtering; verify new headless population appears correctly |
| Population reconciliation and startup | b77d7fbd, 258e6db5, async admission/lifetime fixes | New module has different manager; preserve outcomes with native headless ownership and failure-path tests |
| Native gameplay and data fixes | Dungeon gossip d21b1782, Balor 415564c7, Wild Regeneration integration, selected upstream fixes | Retain corrected data/script bindings; reconcile migration SQL without overwriting realm data |
| Auction query/mail safety | 28d3de94, f1c9f61d, 94c76b96 | Retain lifetime/locking/native mail semantics; revalidate socketless delivery |
| Diagnostics/regression coverage | Existing architecture tests, bounded logs and core audit guide | Adapt tests to real current code, preserve useful assertions, record diagnostics overhead |
| Client DNS and installer | Separate patched WoW.exe and launcher packaging | Preserve external deployed assets; no server module replacement should undo them |

Known integration issues:
- Upstream and our fork both provide some identical native accessors; remove duplicate definitions while retaining their checks.
- LoginQueryHolder moved upstream. Preserve interactive SQL priority and timing fields within upstream request-token/transport identity, not a second holder type.
- New headless manager updates must execute while the world owns sessions, before async network packet work resumes.
- Sagiroth currently drives AI from a world update loop. Our prior joined map AI scheduling must be reconciled before claiming old performance carries over.
- AHBot now consumes the new module's existing IsInRandomAccountList policy; isolated DB owner/provisioning validation is still required.

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

## Current validation and remaining blockers (2026-09-12)

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
- Port/reconcile Thorn Gorge bot objectives, mounting and safe traversal.
- Compare all flight-master, taxi handoff and route-selection fixes. The current
  module disables walking graph generation for its pinned core; resolve the
  capability against this core instead of silently accepting direct movement.
- Remove the retired bot tree and remaining legacy command/lifetime stubs only
  after replacements and tests exist. Adapt legacy tests to active code paths.
- Review random-account provisioning, population/admission, LFT/BG fill,
  native data migration order, transport behavior and shared diagnostic state.
- Finish optional-build matrix and isolated database/client acceptance. No
  production database, running server or client assets have been changed.
