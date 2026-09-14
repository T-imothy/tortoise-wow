# ManTech playerbots integration audit — September 13

User scope: preserve the ManTech Classic baseline on current Penqle Turtle,
including custom races/content, recruitment, configuration, LLM, diagnostics,
and loading. Audit concurrency and tick cost for an eventual4–6k population.
User raised the development target to 6000 at approximately18:20. No sustained full-scale acceptance is claimed.

## Confirmed failures and corrections

| Boundary | Evidence | Correction and state |
|---|---|---|
| Human login / chat audience | Matching build49 dump at17:33:24 faults in ChannelHasRealPlayer:6579, invalid CMaNGOS Channel layout cast | Build50 removed ChannelAcces, reads native membership on joined world boundary, publishes immutable values. User confirmed entering world and killing mobs. |
| Human recruitment | AcceptInvitationAction intentionally declines to own human invitations, but native CanInvite/OnInvite and coordinator Update had no callers | Build52 adds generic inviter-aware GroupScript hooks and wires ManTech coordinator after map jobs join. Native faction/hardcore/ignore/capacity and accept handlers retained. User confirmed one bot accepted and came to the player. |
| /who | Native handler suppressed ordinary accounts for30 seconds | User requested removal. Build52 removes cooldown while retaining in-flight coalescing, native filtering and49-row client limit. |
| Delayed LLM reply | Detached thread captured WorldSession*; unused incoming helper also captured packet-handler address | Build52 uses bounded dedicated native executor, value-only jobs, weak AI lifetime identity, world-owned session resolution/delivery,32 packets/2ms per maintenance pass and256 pending-delivery cap. Worker admission precedes thread/network work; no additional thread per reply. |
| Packet dispatch lock | PacketHandlingHelper held non-recursive producer mutex while invoking callbacks; exceptions skipped unlock | Build52 swaps queued work under RAII lock and calls handlers outside it; preserves retry-stack order and queues new arrivals for next pass. |
| Shared random-event cache | Unprotected cache/set access from map AI; SetEventValue marked an entire bot loaded without loading sibling events | Build53 changes deployed with build54: recursive synchronization, bulk startup read before admission, first mutation preserves persisted sibling settings. |
| Sparse human selection | GetRandomPlayer used random vector index as a GUID map key and inserted null entries | Build53 selects an existing iterator. No online character/config/database population is rewritten. |

## Focused checks performed

- Channel query: actual source extracted and compiled; human/headless identity,
  factions/cross-faction, case folding, missing/deleted channels, logout, and
  concurrent snapshot readers passed.
- Async chat: actual implementation with native MapTaskExecutor; saturation,
  nonblocking pending/logged-out futures, relogin identity, account checks,
  packet direction, worker exception, delivery budget and shutdown join passed.
- Packet callbacks: actual Handle/AddPacket; reentrant enqueue, next-pass delivery,
  retries and exception-safe mutex reuse passed.
- Recruitment: existing actual-coordinator regression adapted to native slot/API
  names, plus native hook registration/order assertions. Classic and preserved
  conditional variants passed for stale/replaced invitations, ownership, combat,
  death, session loss, assistants, capacity, replay, cancellation and bounded work.
- Event cache: actual methods with deterministic DB fixture; first-write sibling
  preservation, one initial query serving6000 IDs, eight concurrent cache users,
  expiration and persistent-event retention passed. This is not a server load test.

## Native threading traced

MapManager dispatches joined whole-map jobs to four configured map-owner workers.
Map::UpdatePlayerAI executes foreground AI on that owner; background batches
handoff to a separate two-worker idle-AI executor and join before map reuse.
No actor from a map is authorized to mutate that map independently while its
owner also advances it. Global module maintenance runs after maps and the channel
broadcaster join. Native group opcodes are PACKET_PROCESS_WORLD (GROUP alias).
Player AI remains guarded against overlapping execution; elapsed decision/reaction
clocks are consumed only for admitted or explicitly advanced work.

This architecture already separates map and idle-bot execution; it does not mean
every imported shared helper or asynchronous call is compatible. A global lock
around all bot AI would hide races while destroying useful parallelism and is
not the chosen remedy.

## Runtime observations and limits

Build50 user login/combat succeeded. At17:53:55 diagnostics recorded500 online,
one real player,66ms average/125ms maximum over the sample. Compilation and three
other expansion test servers also ran on this PC, so this is not an isolated
benchmark. Activity controller/active-bot counts vary during startup/ramp and
must be interpreted separately from online population.

Build52 deployed18:04:00, ready18:04:32, world39436/realm30244. SHA256:
29F94B9E6EAD53573DDBE06F1F7E9814C995A0DFCC069D4522146AB3D64A7A82.
World8088/login3726; shared local MySQL;500 bots; level1–60; approved Classic LLM
endpoint/credential stays in runtime configuration, outside Git. No push/commit.

## Historical open work at build60 — see build69 disposition below

1. Build53 cache work and human recruitment retry are complete (the user confirmed an invited bot joined). Preserve a coherent deployed EXE/PDB before crash analysis; sustained gameplay acceptance remains open.
2. Audit remaining cross-map reads of real-player position, camera, friends and
   guild presence; existing raw player iteration is not a concurrency proof.
3. Shared-value owner lifetime/calculation locking and travel-worker bounds are fixed in build59, with focused regressions. Continue auditing mutable references escaping shared caches and travel destination data ownership.
4. Manual debug RPG chat still waits/sleeps on its caller; move its continuation
   to the owner update without changing conversation state. Main asynchronous
   chat no longer uses detached session/AI captures.
5. Check remaining global mutations in bot social/group/queue commands against
   native packet ownership, including repeated invitations and cross-map parties.
6. Continue inventory of host service hooks, caches, persistence, class/custom-race
   adapters, movement and diagnostic boundaries against the selected baseline.
7. Evaluate per-map/foreground work and synchronous DB/storage costs for4–6k;
   report measured budgets and unresolved costs. User authorized6000, then restored500 for engineering tests after the high-population run; full-scale performance remains unproven.

Generic native hooks belong in a separate Penqle-facing commit designation.
Module behavior, tests and runtime operations remain separate. No unrelated
working-tree changes were staged and no previous binary backup was made.

## User-directed 6000-bot target and local diagnostics (build55)

The previous 500 minimum/maximum became 6000; levels remain1–60 and automatic
character creation remains disabled. The existing TBPLAY pool contains6000
characters on600 accounts. Diagnostics exposed only5277 eligible characters:
the imported factory's static class/race list excluded723 existing native Turtle
characters (Tauren priest, Dwarf/Orc mage, Undead/Gnome hunter, Dwarf/Troll warlock).
The seven pairs exist in native playercreateinfo. Configuration now gives each
a positive weight. Factory eligibility/creation lists use native validated
ObjectMgr::GetPlayerInfo, the same contract used by Player::Create, after native
player data loads. Function-static initialization prevents repeated constructors
appending duplicates to the shared list. Unsupported pairs remain rejected.
The old 9-per-account creation estimate is labelled an estimate; it no longer
claims the imported6000-character pool is too small merely because600*9=5400.

The localhost8080 bot panel now reads ManTech PB_DIAG/PB_COMBAT records rather
than the dormant Sagiroth service. It displays world timing/population/controller
trends, login backpressure, DB queues, memory, physical state/class/level/race/zone
breakdowns, action failures, and sampled combat counts/traces. The new PB_DIAG_POP
record reuses the existing world-owned diagnostic iteration every30 seconds;
it emits scalar counts only and adds no individual-bot website query. Files and
repeatable installer/tests are preserved in dev/local-website.

Checked: build55 compilation/link; extracted actual factory methods with native
lookup fixture (seven added pairs, goblin/high elf, unsupported pairs, repeated
and concurrent construction); PHP adapter complete/partial/restart/tail fixtures;
PHP/JS syntax; browser population and sampled combat display. The earlier event
cache and recruitment checks remain recorded above. Sustained6000-bot gameplay,
world latency, and the broader integration audit remain open.

Build55 runtime started18:39:01, ready18:39:32. At18:40:03 the new diagnostics
reported449 online,6000 eligible/target, one real player,58ms average world update,
and204 pending logins. This is ramp-up evidence, not sustained6000 acceptance.
The factory regression is preserved in
modules/ManTechPlayerbots/tests/turtle_native_race_pool_regression.py.


## Shared values, trainers and bounded travel (build59)

Deployed 2026-09-13 19:44:18, ready19:44:48, world12064/realm42912.
User-directed test minimum/maximum500; botActiveAlone100 and
DisableActivityPriorities1 preserved. The previous build55 high-population run
reached4606 online/activity-enabled in the captured sample (282ms average,
340ms max); it did not reach6000 before the user requested shutdown. An earlier
sample showed1472ms average/6815ms max. These are separate samples, not sustained
latency guarantees. The website JSON snapshot is retained in the task work directory
as turtle-high-population-before-500.json; original server/diagnostic logs remain
in the runtime logs directory. Production Shy diagnostics are not a comparison.

- SharedObjectContext now owns its AI for the entire cached-value lifetime and
  explicitly owns/deletes its shared context. The former temporary AI was deleted
  while values still referenced it. A recursive per-value lock serializes shared
  Get/LazyGet/Set/reset/serialization; no global lock surrounds per-bot AI. A failed
  SingleCalculatedValue calculation does not mark an uninitialized value cached.
  Returned mutable pointer/reference consumers still require ownership review.
- Trainer cache combines native entry and template lists, preserves entry override
  precedence, keeps IDs in their separate namespaces, initializes requirements per
  offer, and groups equivalent offers including price/level/skill/condition fields.
  Unqualified trainer queries now include all trainer types. Native purchase and
  eligibility handlers are unchanged. Current Turtle data drives class/race/skill
  requirements; no Classic hardcoded trainer spell catalogue is introduced.
- All12 async travel request sites use five native MapTaskExecutor workers and a
  maximum128 outstanding searches. Existing five destination permits remain.
  Admission stays below the native executor's inline fallback; a rejected request
  returns an invalid future and uses the existing travel retry path, not the
  negative destination cache. Packaged-task future destruction does not block
  logout. OnShutdown drains accepted searches before native logout/data teardown.
  Captures retain the existing copied PlayerTravelInfo/coordinates/IDs; no bot or
  session pointer is added to jobs. This does not certify every global destination
  cache read/reload path or eliminate the owner cost of building travel inputs.

Validation: build59 linked successfully; actual-source C++ fixtures passed shared
AI lifetime, concurrent calculation/reset/exception retry/string access; trainer
namespace collisions, both native lists, override precedence, class/race/skill and
missing-spell cases, distinct offers, qualified/unqualified consumers; travel
concurrent producers,128 admission/five execution bounds, abandoned futures,
shutdown drain, exceptions and restart. Portable harnesses are in module tests:
turtle_shared_values_regression.py, turtle_trainer_cache_regression.py,
turtle_travel_workers_regression.py. Run in a C++17 compiler environment.

Build59 live sample:500 online/activity-enabled,0 pending logins,0 pending DB
operations/results,66ms average/108ms maximum world update, no real players.
This validates startup/population, not all trainer purchases or travel behaviors.

### Shutdown persistence finding — unresolved

The high-population build55 shutdown exceeded the helper's45s wait, then finished
normally at19:43:23. At19:42:56, a prepared character_aura INSERT logged MySQL
deadlock. Native MySQLConnection::HandleMySQLError returns false for deadlock;
SqlTransaction::Execute rolls back on a failed operation without retry. This can
lose that save transaction; a successful process exit does not prove every save
committed. Investigate the conflicting transactions and native transaction replay
contracts before introducing retries; do not retry only the failed INSERT.

### Manual RPG chat (build60 deployed)

ManualChat no longer waits for generation or sleeps between lines. Its action
owns the pending response; PlayerbotAI polls only when a manual response is pending,
under the existing serialized owner update, before ordinary AI delays. At most one
line is delivered per update, honoring its millisecond delay. Target world/map/
instance/identity and current RPG target are revalidated. Reset, replacement,
target loss and teleport cancel without waiting; generation failures are caught.
Context is preserved per delivered line. Bare impersonate no longer substrings
past the command, prefixed impersonation uses the NPC identity, and undo/continue
handle missing speakers. No live entity is captured by generation workers.
Actual-source manual-chat fixture passed polling/delays, context, superseding
responses, target/teleport cancellation, exceptions and conversation commands.
Live LLM response success and debug direct-LLM command ownership remain open.

Build60 deployed19:51:59, world1152/realm24092. Build and persisted actual-source manual-chat regression passed; matching EXE/PDB copied without a previous-binary backup. Test target500 and all-bot activity remain enabled.


## Engineering closure and scale run (build69, September 13)

The user restored the test target to6000 during this engineering pass. Runtime
minimum/maximum6000, levels1–60, botActiveAlone100 and DisableActivityPriorities1
are retained. These settings allow independent activity; a physical-state snapshot
does not imply every bot must be moving or attacking simultaneously. The module's
activity controller percentage is not the final activity gate when priorities are
disabled. The developer PC now uses8 native map workers and8 idle-bot workers.
Other Classic/TBC/WotLK/production processes and databases were not changed.

Implemented since build60:

- Character-save transaction replay: the native MySQL connection confirms that
  every base table in its schema is InnoDB before permitting opt-in whole-transaction
  replay. Player saves opt in, including the character row in direct saves. Only
  a confirmed1213 statement deadlock, followed by successful rollback, permits
  retry; maximum3 attempts, with no replay for begin/rollback/ambiguous commit
  errors. The explicit custom migration converted59 MyISAM character tables to
  InnoDB/DYNAMIC while Turtle was stopped. All111 character tables are now InnoDB;
 6006 existing characters were retained. No other schemas were migrated. This
  resolves the previously documented no-retry save path; it does not guarantee
  success after exhaustion or authorize live engine changes.
- Human presence: immutable world-published snapshots cover map/instance,
  body/camera positions, visibility, friendship and real-guild leadership. The
  nearby-count helper now compares squared distance to squared radius correctly
  and counts the camera/body union once per human. Native guild leadership has
  a lock-protected value snapshot; offline leaders use the native account cache.
- World ownership: module actions touching groups, guilds, auctions, mail,
  battleground/LFG queues, population maintenance and corpse resurrection cross
  a bounded post-map queue. Identity/account/map-generation/event ownership are
  revalidated before execution. Native headless stop deferral keeps the actor
  alive through callback return and rejects stale stop tokens. Master-manager
  updates also run after map workers join. Local AI/combat/movement stays on map
  workers; the queue is not a replacement global bot AI thread.
- Queue integration regression and correction: builds64–66 re-ran triggers on
  continuation and admitted checks that could be rejected locally. Build67
  retains a decision through map/world/map handoffs and populates triggers once.
  Build69 adds stable local preflight and drains up to256 callbacks/8ms per tick
  (soft time limit: one indivisible callback can exceed it). Admission remains
 1024 total/8 per bot. Enqueue retries have a minimum100ms AI delay. Normal-engine
  local prerequisites/alternatives resume on the map. Reset/replacement cancels
  the engine epoch. Queue statistics expose pending, accepted/rejected/executed/
  cancelled totals and the most frequent pending action every30 seconds.
- Cached guild item recipients now store a GUID and resolve/revalidate world,
  teleport, map, instance, guild and interaction distance before transferring.
- Direct debug LLM generation is asynchronous with bounded workers and private
  recipient identity validation. Manual RPG generation already uses the owner
  continuation. Approved Classic LLM configuration stays only in runtime files.
- Quest giver/taker enumeration uses native creature and gameobject relation
  bounds, preserving their separate signed entry namespaces; no fabricated
  ObjectMgr subclass/layout cast remains in this path.
- Optional module-owned voice lookup loads the installed EmotesTextSound.dbc;
  the live loader reported882 race/sex entries, including Turtle races.
- Animated transport route lookup reads installed TransportAnimation.dbc through
  native DBCStorage into immutable owned nodes. This replaces the active module's
  null animation call; existing generated/stored travel graphs and native transport
  movement are preserved. No claim of a live elevator/tram traversal is made.

Validation completed:

- Release/LTO build69 linked, matching EXE/PDB deployed without an old-binary backup.
- Actual-source C++ regressions cover save replay/error variants, human visibility
  and distance, native headless stop/token lifetime, queue concurrency/saturation/
  identity/teleport/reset cancellation, the real decision loop across ownership,
  bounded async chat delivery/logout, native quest union, voice selection and
  transport animation storage. Shared-value, trainer and travel-worker regressions
  from build59 and manual chat from build60 remain preserved and passed this pass.
- A real MySQL fixture provoked1213 between two InnoDB transactions, rolled back
  and replayed the victim, and verified both increments before dropping its own
  isolated test table. A subsequent real character_aura shutdown deadlock logged
  DB_TRANSACTION_RETRY and normal shutdown; this is not an individual save-content
  comparison.
- A native wire client using the existing disposable account passed SRP/world
  authentication, world entry, two consecutive /who responses, owned-bot login,
  native group invitation acceptance and logout. The owned bot's debug LLM command
  returned the requested TURTLE_PORT_OK from the approved endpoint. This confirms
  the private generation/delivery path, not every conversational trigger.
- Native source contract audit regenerated without a DB refresh. The active-talent
  inventory found77 talent spell names with strategy references; this is lexical
  coverage, not exhaustive rotation/talent gameplay acceptance.

Acceptance limits still requiring evidence:

The6000 activity-enabled scale run is in progress. Earlier ramp/shutdown samples
and builds with the queue regression must not be labelled sustained6000 success.
All class/rank/spec combinations, custom-race progression exits, every dungeon/
raid, transport traversal, and every mutable reference escaping shared caches
have not been exhaustively exercised. Normal world-data missing-waypoint/script/
trainer warnings are retained for attribution, not silently suppressed. The exact
earlier eight-item Shy checklist has not been reconciled item by item in this
engineering receipt. Do not equate feature import or compilation with that proof.

Commit designation remains three separate groups: generic native core hooks and
persistence contracts for possible Penqle review; ManTech module/adapters/tests;
local-development instructions and receipts. No commit or GitHub push was made.
