# Turtle core: native systems and change contracts

Chat-channel follow-up (2026-09-09): ObjectMgr's database loader preserves each
channel ID. Fixed names/shortcuts match exactly and localized zone names match
the anchored prefix/suffix around `%s`; custom names containing a built-in name
must not acquire its identity or zone restrictions. `Channel` consumes ID/flags
and `ChannelMgr` enforces zone-dependent admission. The native-fragment
`ChatChannelLookupTest` covers loading, locales, misses and reloads. See
[Penqle integration](PENQLE_INTEGRATION_2026-09-09.md) for the upstream ancestry,
SQL contracts and unapplied migration limitations.

Source baseline: `mantech-turtle`, `b2d5a8549194f7ffa38e324dcb7a82ccc0ba2132`, reviewed 2026-09-05. This guide is a navigational and ownership reference, not a substitute for reading the current implementation. Line numbers below describe this baseline and will drift.

Start with the [compatibility audit](CORE_COMPATIBILITY_AUDIT_2026-09-05.md), [map coverage](core-audit/COVERAGE.md), and [diagnostic inventory](../doc/TURTLE_DIAGNOSTICS.md). `AGENTS.md` requires using native mechanisms and checking their full contract before making changes.

## How to investigate the next bug

1. Record the exact build, config, client version, entity entry/GUID, map/instance, reproduction and expected behavior. A local source tree is not proof of the running binary.
2. Find the public entry point: opcode, AI hook, spell effect, gossip/event script, DB loader or maintenance callback. Find its callers and the authoritative state it changes.
3. Identify the selected implementation, not just a filename. Check database binding, build inclusion, registration and native fallback. Check optional modules and runtime Lua separately.
4. Trace eligibility checks, caster/target roles, ownership, state transitions, notifications, persistence and failure cleanup. Identify which thread owns the object when each step runs.
5. Compare another working consumer of that same native API. Use CMaNGOS/upstream as references, not as proof of equivalent Turtle semantics.
6. Correct the demonstrated cause in the responsible layer. Do not put an isolated fix in an outer handler when the generic implementation already supports the behavior. Conversely, do not rewrite a shared spell effect to compensate for an invalid caller.
7. Test supported variants, rejected/repeated requests, transitions and persistence; include other consumers of any changed shared function. Record what was not exercised.
8. Update this guide, the finding ledger and regression tests when contracts change. Audit snapshots are evidence at a timestamp, not an evergreen content database.

Useful searches: `rg -n 'SymbolName' src modules tests`, literal `script_name` in the audit JSON, and `git diff <verified-base> -- <path>`. Do not search only dungeon folders: `generic_spell_ai` is registered in the game library.

## Execution and ownership map

September 7 upstream integration: `PlayerbotHolder::UpdateAllHolderSessions`
is the sole world-owner synthetic session pump after map work joins. Snapshot
entries carry a holder generation; callbacks can remove or replace a later
holder without dispatching a stale lifetime. Registry locks must not span
native packet/teleport handlers. AI-less, socketless bots use native near/far
teleport ACK handlers, then revalidate player/session ownership before continuing.

Optional SOAP runs only with `SOAP.Enabled = 1`. Authentication uses the game
account and commands retain its security level on the native world command
queue. Shared callback state survives a request returning during shutdown.
`Master` explicitly joins SOAP before closing databases because its final
`quick_exit` does not unwind local objects. The matching gSOAP runtime builds
from source on Windows and Linux; no prebuilt Linux archive is linked.

Balor explosives use database-bound `go_balor_explosives` and native
`broadcast_text`/`npc_text` delivery. Quest status, objective entry/count and
the upstream spawn identity are checked before repeatable gossip can grant
credit. DungeonClear action IDs must resolve to an offered gossip option;
Turtle's select packet contains GUID then option index, without a menu-ID
field. The pre-existing empty-menu compatibility fallback remains separate
and diagnostic-gated; this integration does not certify or expand it.

Bot startup provisioning (`RandomPlayerbotFactory::CreateRandomBots`) must keep
account-creation futures separate from character-save futures. `get()` consumes
a future; waiting on it again throws `std::future_error`. Drain and clear both
bounded eight-task windows before advancing phases. Keep native `SaveToDB`,
cache registration with the session attached, and subsequent player/session
cleanup in that order. `BotCreationLifecycleTest` executes the production loops
with real futures and mock account/player services; it is not a realm startup
or database-persistence test.

| Boundary | Current source entry points | Contract to preserve |
| --- | --- | --- |
| World lifecycle | [World.cpp](../src/game/World.cpp), `World::Update` at 2731 | Global services, transports, session/result processing and map orchestration are separate phases. World-thread maintenance must not mutate a map concurrently with its owner. |
| Map jobs | [MapManager.cpp](../src/game/Maps/MapManager.cpp), `Update` at 336; [Map.cpp](../src/game/Maps/Map.cpp), `DoUpdate` at 1528 | Selected maps get joined owner jobs; transfers/unload occur across the ownership barriers. Serial/parallel choices are alternatives, not permission to execute both. |
| Object discovery and update | `Map::UpdateDiscoveredCells` at 802; [Creature.cpp](../src/game/Objects/Creature.cpp), `Update` at 716 | Discovery collects/deduplicates candidates; the owner runs native object logic. Players/cameras/corpses have separate handling. A second collector is not a second combat engine. |
| Completion and instance state | `Map::CompleteUpdate` at 1673 | Instances complete inside their update; continents use a later manager phase. Retain `UpdateScriptedEvents`, `ScriptsProcess`, optional Eluna, `i_data->Update`, weather and grid lifecycle. |
| Player and bot simulation | `Map::UpdatePlayers` at 1274, `UpdatePlayerAI` at 1396; [PlayerbotScripts.cpp](../modules/mod-playerbots/src/playerbot/PlayerbotScripts.cpp) | Core player state, module bookkeeping, individual AI and synthetic session work are distinct. The idle batch hands off the whole map's AI and waits; do not fan out mutating bots on one map independently. |
| Motion | [Unit.cpp](../src/game/Objects/Unit.cpp), [MotionMaster.cpp](../src/game/Movement/MotionMaster.cpp), `Map::UpdateActiveObjects`/motion work | Native motion and deferred `UpdateAsync` are distinct stages. Preserve queue-or-inline exclusivity, pending-set cleanup, map transitions and generator lifetime. |
| Packet ownership | [WorldSession.cpp](../src/game/WorldSession.cpp), `ProcessPackets` at 480; opcode registration/filter definitions | A handler must execute in the context its opcode permits. Extra queue-drain checkpoints must consume packets, not replay them. Synthetic bot packets retain handlers but intentionally have different socket admission. |
| Persistence | [Database sources](../src/shared/Database), native entity save methods | SQL worker execution and application of results are different ownership stages. Priority queues can reorder work across priorities; callbacks and object references must survive cancellation/shutdown safely. |
| Maintenance | [RandomPlayerbotMgr.cpp](../modules/mod-playerbots/src/playerbot/RandomPlayerbotMgr.cpp), auction module | Population counts include pending work; resumable plans need identity/generation checks. A cooperative budget cannot interrupt a single expensive operation. Preserve native final teleport/auction operations. |

### CMaNGOS-policy AHBot (feature/cmangos-ahbot, September 6)

The single public service remains `AhBot`, called by `PlayerbotWorldScript`
after map/session owners join; `ChatHandler::HandleAhBotCommand` forwards to it.
The former detached category seller/buyer, item bag, pricing strategies, direct
bot equipment writes, and speculative mail offers have been removed, not left
running beside the replacement. Historical category/refill tests are superseded
by `AhBotMarketTest` and `AuctionSettlementTest`; chat dispatch remains covered.

The CMaNGOS Classic/TBC/WotLK reference model supplies creature-rank, disenchant,
fishing, chest, skinning and profession stock. It uses `AuctionHouseBot.*`
configuration, quality/class valuation, vendor prices, level limits, random
properties, stack splitting, item overrides, and a 20-second normal check.
Rebuild simulates mean auction duration * 90 sell-only checks (1,170 for 2â€“24h),
not a fixed desired count. A shared house receives the same three logical
CMaNGOS supply opportunities; expiry/status deduplicate physical houses.
Native data/content differences mean a matching config does not promise an
identical auction count.

Turtle adaptations that must not be lost:
- Resolve creature `loot_id`, not NPC entry; preserve per-template weighting.
  Chest sources require respawning chest gameobjects. Profession items come
  from loaded native create-item spell effects; vendor templates are included.
- Use a fresh native `Loot` per repeat. Reusing Turtle's container across repeats
  silently truncates stock at its loot-slot limit. Keep native roll/reference/
  group/rate processing; no parallel custom loot generator.
- Keep native character/account ownership using verified random-bot characters,
  never a human configured as synthetic bidder. Do not use CMaNGOS owner 0,
  the no-op `AuctionEntry::UpdateBid`, or the integer house-lookup shim.
- Initialize auction stock's random properties/enchantments while the new item
  is ownerless, then assign its persistent bot owner before saving. Native
  `SetItemRandomProperties` calls `SetState` and can enqueue an online owner's
  item for inventory saving. `ClearUpdateMask` does not remove that queue entry;
  `SaveToDB` resets its queue position without removing the queued pointer.
  Inventory validation can then delete the auction item, leaving a stale auction
  pointer. `AuctionStockOwnershipTest` executes native publication, property,
  enchantment and item queue methods for online/offline owners, repeated saves,
  valid/absent/unknown properties and admission/allocation failures. Ordinary
  inventory enchantments must still enqueue normally. Persistence remains mocked.
  The September 8 crash reached expiry-mail item access after the notification
  guard; that guard alone does not fix this ownership violation.
- `AuctionHouseObject::ExpireAuction` is the extracted native expiry/sale body:
  script hooks, winner/owner mail, DB deletion, item and auction index removal.
  Normal expiry and incremental rebuild call this same method. Native outbid
  refund mail is now owned by `AuctionHouseMgr`; the session delegates to it.
- `SendAuctionOwnerNotification` skips socketless sessions before constructing
  the client UI packet (upstream `6a2ddc82`). Expiry/success mail and native
  settlement continue in the caller. Current playerbots register no handler
  for `SMSG_AUCTION_OWNER_NOTIFICATION`; connected player packets retain their
  existing format. The early return also omits this packet's logging and send
  hooks for socketless sessions. Revisit that contract if adding a consumer.
  This is a defensive mitigation, not proof of the original invalid pointer.
  `AuctionOwnerNotificationTest` executes native notification and owner-mail
  functions for socketless/connected owners, sale/unsold expiry/bid payloads,
  offline-owner mail and missing-item handling with mock persistence/transport.
- Buyer rechecks a paged snapshot against the live auction under its lock,
  protects same-account ownership, respects IP locks and native hardcore mail
  restrictions, and refunds an existing bidder before a bid/buyout. Ordinary
  bids persist without prematurely ending the auction.
- Administrative `rebuild [all]` coalesces requests and protects existing bids
  by default; repeated requests during expiry/refill cannot restart it.
  Reload/item edits are refused while accepted work is active.
- Client auction searches consume native `AuctionEntry` and `Item` indexes as
  one read snapshot. Hold the auction-house lock before the auction-item lock
  until packet construction finishes; `GetAItem`'s lookup-only lock does not
  extend a raw `Item*` lifetime. The item mutex is recursive because native
  `BuildAuctionInfo` re-enters `GetAItem` while that snapshot is held. Invalid
  item templates are logged and skipped instead of being dereferenced.
- Stock work is resumable on the world owner, bounded by existing `WorkSlice`
  (default 32 attempts / 2ms); expiry and buying page at most 32 entries.
  A native operation can exceed a cooperative budget; status reports actual
  last/max slice cost. Source/config reads happen at initialization/reload,
  not once per listing. Reload uses candidate data and retains old settings
  when parsing or source reads fail.
- Checked 64-bit arithmetic prevents price/stack overflow into signed money.
  This port honors `Buy.Value`; the sampled Classic implementation reads that
  option but does not actually multiply buyer valuation by it.
- The replacement does not consume old `AhBot.GUID` or category caps. Use the
  matching `ahbot.conf.dist.in`. Existing `ahbot_items` overrides remain valid;
  amounts can exceed a stack and are split legally.

Read-only schema checks: 5,238 distinct creature loot IDs, 732 respawning chest
loot IDs, 2,363 vendor item IDs. These are source availability checks, not a live
market test. Regression doubles exercise production scheduler/gather/post/buy/
commands and native expiry/refund/paging; they do not validate DB durability,
actual drop distributions, client auction interaction, or 6k-bot latency.
Those remain explicit deployment acceptance checks. See the diagnostic inventory.

There is no source evidence in these inspected paths of two complete simulation engines. That does **not** mean the architecture port is behavior-neutral, or that every shared-state race is excluded. See findings A1â€“A6 in the audit.

## Creature, boss and trash AI: actual selection

The important chain is:

`creature` spawn definition / dynamic summon â†’ `creature_template` â†’ `Creature::AIM_Initialize` â†’ `FactorySelector::selectAI` â†’ native `Creature::Update` â†’ selected `AI()->UpdateAI` and lifecycle hooks.

- [CreatureAISelector.cpp](../src/game/AI/CreatureAISelector.cpp), `selectAI` at 37, asks the script manager first for eligible ordinary creatures/non-controlled pets. Possession, controlled pets, charm, totems and guards have special selection rules. Named AI, permit selection and fallback follow.
- [ScriptMgr.cpp](../src/game/ScriptMgr.cpp), `GetCreatureAI` at 1767, supports legacy registered scripts, typed script registries, global creature hooks and optional Eluna. An empty or stale `ai_name` alone does not establish which implementation actually runs.
- [ScriptLoader.cpp](../src/scripts/ScriptLoader.cpp) invokes `AddSC_*`; [scripts CMake](../src/scripts/CMakeLists.txt) and [game CMake](../src/game/CMakeLists.txt) determine source inclusion. File presence and successful compilation do not prove registration was invoked.
- [CreatureAI.cpp](../src/game/AI/CreatureAI.cpp) loads `creature_spells` through `SetSpellsList`; its spell-list update and cast helpers are native mechanisms. [CreatureEventAI.cpp](../src/game/AI/CreatureEventAI.cpp) separately loads `creature_ai_events` and can still run its spell list and melee with no event rows.
- `creature_ai_scripts` stores command scripts referenced by events; it is **not** the table of EventAI event rows. Mixing those schemas leads to incorrect audits and fixes.
- [GenericSpellAI.cpp](../src/game/AI/GenericSpellAI.cpp), registration at 154 and initialization at 390, derives generic behavior from template spell slots. Its presence outside `src/scripts` resolved 52 apparent missing bindings in the first scanner pass.
- [ScriptedAI](../src/game/AI/ScriptedAI.h) and [ScriptedInstance](../src/game/AI/ScriptedInstance.h) provide native combat/instance helpers. Reuse those instead of separate hand-built targeting, spell, door or respawn systems.

### Architecture implications for every encounter

[BackgroundWorldScheduling.h](../src/shared/BackgroundWorldScheduling.h) returns no distant-creature interval for non-continents. `DescribeBackgroundCreature` in `Map.cpp:770` additionally protects script IDs, non-ordinary selected AI types, zone scripts, world-boss rank, escorts, controlled units, combat, relevant auras/events/casting, active objects and transport passengers.

Therefore dungeon/raid actors are outside this particular continent-only throttle. They still depend on shared discovery, map ownership, movement/protocol, spell clocks, DB callbacks and visibility. World-boss protection applies to the boss once selected; nearby helpers, trigger objects, grid activation and custom global hooks still need tracing. Do not interpret the guard as proof that every encounter dependency is protected.

No special conversion is required in each boss file to use the new map scheduling: it runs underneath the native AI. Conversely, adding an extra boss-update loop to "enable the new tech" would risk duplicate mechanics.

## Instances, doors, summons and persistence

- `map_template.script_name` selects the instance implementation. [InstanceData](../src/game/Maps/InstanceData.h) defines lifecycle hooks; [ScriptedInstance.cpp](../src/game/AI/ScriptedInstance.cpp) implements helpers including `DoUseDoorOrButton` at 11.
- Trace `OnCreatureCreate`/`OnObjectCreate`, stored GUIDs, `SetData`/`GetData`/`GetData64`, encounter states, reset/evade/death, save/load and world-object recreation. Correctly opening a door once is insufficient if it remains closed after reload or opens on a failed encounter.
- Default examples: [Blackwing Lair instance](../src/scripts/dungeons/blackwing_lair/instance_blackwing_lair.cpp), [Deadmines instance](../src/scripts/dungeons/deadmines/instance_deadmines.cpp). Custom examples: [Lower Karazhan](../src/scripts/dungeons/lower_karazhan_halls/instance_lower_karazhan_halls.cpp) registers multiple trash AIs as well as the instance; [Solnius](../src/scripts/dungeons/emerald_sanctum/boss_solnius.cpp) connects gossip, instance lookup and boss behavior.
- Summoned bosses/adds may have no ordinary spawn row. Search creature entry constants, summon spells, `SummonCreature`, event commands and summon callbacks. Check cleanup on wipe, phase transitions and grid/map unload.
- Blank `map_template.script_name` is not automatically a bug: some content relies on creature/GO/EventAI/native mechanisms. Identify the intended state owner before adding an instance controller.
- Portals may be visual gameobjects plus separate area-trigger/teleport data. A missing visual object's script binding warrants investigation, not an automatic extra teleport handler.

## Other native entry points and change boundaries

This is a navigation index. The targeted audit did not execute every behavior in the following systems.

| System | Start here | Related consumers / checks before changing |
| --- | --- | --- |
| Casts, melee, damage and death | [SpellHandler.cpp](../src/game/Handlers/SpellHandler.cpp) `HandleCastSpellOpcode:325`; [Spell.cpp](../src/game/Spells/Spell.cpp) `prepare:3507`, `cast:3775`, `CheckCast:5561`; [Unit.cpp](../src/game/Objects/Unit.cpp) `DealDamage:756`, `Kill:1190` | Players, creatures, pets, triggered spells, threat, immunity, procs, auras, rewards and script hooks share these paths. A scheduler must not replay elapsed time as duplicate effects. |
| Spell effects and auras | [SpellEffects.cpp](../src/game/Spells/SpellEffects.cpp), [SpellAuras.cpp](../src/game/Spells/SpellAuras.cpp), [UnitAuraProcHandler.cpp](../src/game/UnitAuraProcHandler.cpp) | Dispatch by actual effect/type. Preserve caster vs target, trigger flags, resources, duration, death/removal and proc ordering. |
| Trainers | [NPCHandler.cpp](../src/game/Handlers/NPCHandler.cpp) `HandleTrainerBuySpellOpcode:285`; [Player.cpp](../src/game/Objects/Player.cpp) `LearnSpell:4670`, `HasSpell:5383`; spell effects 2254/3152 | Player training and pet training are different supported services. The pet path requires a player caster, native eligibility/training-point checks, pet persistence and owner notification. Verify successful learning before payment; failure must not later finish as a free delayed purchase. |
| Loot and inventory | [LootMgr.cpp](../src/game/LootMgr.cpp) `LootTemplate::Process:1324`; [LootHandler.cpp](../src/game/Handlers/LootHandler.cpp) `HandleAutostoreLootItemOpcode:41`; `Player::SendLoot:9451` | Template/reference/group/condition selection is separate from allowed-player checks and inventory storage. Include group distribution, quest loot, pickpocket/skinning, full bags, release/retry and persistence. Do not replace the native eligibility/store sequence. |
| Quests, rewards and XP | [QuestHandler.cpp](../src/game/Handlers/QuestHandler.cpp) `HandleQuestgiverCompleteQuest:588`; `Player::RewardQuest:15269`; [QuestDef.cpp](../src/game/QuestDef.cpp) | Acceptance, objectives, item/money requirements, repeatability, reputation, XP rate modifiers, reward scripts and persistence. A quest relation alone is not proof that objectives work. |
| Trade | [TradeHandler.cpp](../src/game/Handlers/TradeHandler.cpp) `HandleAcceptTradeOpcode:293` | Both accept states, item ownership, bag space, enchant spell targets, money, cancellation and saves. Native code saves both players; that alone is not proof of one cross-player atomic transaction. |
| Chat, WHO and commands | [ChatHandler.cpp](../src/game/Handlers/ChatHandler.cpp) `HandleMessagechatOpcode:176`; [MiscHandler.cpp](../src/game/Handlers/MiscHandler.cpp) `HandleWhoOpcode:271`; [Chat sources](../src/game/Chat) | Client request parsing, filters, result counts/wire fields, security levels, channel membership and visibility. Do not special-case one displayed name or confuse account authority with character level. |
| Travel | [TaxiHandler.cpp](../src/game/Handlers/TaxiHandler.cpp) `HandleActivateTaxiOpcode:203`; [MotionMaster.cpp](../src/game/Movement/MotionMaster.cpp); [TransportMgr.cpp](../src/game/Transports/TransportMgr.cpp) `Update:538`; `Player::TeleportTo:2670` | Taxi flight is not moving-transport simulation. Preserve route data, client/server templates, embark/disembark offsets, transfer ACKs, native relocation, visibility and generator lifetime. Client WDB cache and server DBC/data are distinct. |
| Gameobjects and interaction | [GameObject.cpp](../src/game/Objects/GameObject.cpp) `Use:1477`; ScriptMgr gossip/GO hooks | GO type determines native behavior. Check door/button state, spell activation, use conditions, area triggers, event callbacks and cooldowns before attaching a new script. |
| PvP/group systems | [Battleground sources](../src/game/Battlegrounds), [OutdoorPvP sources](../src/game/OutdoorPvP), [Group.cpp](../src/game/Group/Group.cpp), [ThreatManager.cpp](../src/game/Threat/ThreatManager.cpp) | Team/faction and controlled-unit rules, match lifecycle, objective scripts, group state and threat ownership. PvP is not certified by a PvE test. |

### Trainer lesson to retain

Knowing that a service touches `SPELL_EFFECT_LEARN_SPELL` is only the start. The sibling `SPELL_EFFECT_LEARN_PET_SPELL` uses different state and side effects. The original direct player-learning approach did not cover it. At this baseline the handler reuses the native pet spell path, and a handler regression test covers success/failure/repeat variants. The test uses mocks and does not prove the entire live spell engine. Future changes must inspect sibling effect types and other callers before narrowing a generic service.

## Evidence maintenance

- September 6 bot dispatch: `MovementAction::DispatchMovement` must choose one
  native movement path. Direct/free-flying/single-point requests use MovePoint;
  generated multi-point requests use MovePath after hazard avoidance, with no
  stale point generator underneath. Preserve the first route vertex when
  MoveSplineInit replaces vertex zero with the live position, and pass walking
  mode through Turtle's explicit walk argument. Empty requests do not interrupt
  existing motion. BotMovementDispatchTest executes the real dispatcher,
  MovePath and point initialize/update bodies with deterministic unit/spline
  services. It covers double launches, options, walking, short/empty paths,
  hazard-point retention and point speed reinitialization, not full live trips.

- [Bot technology integration](BOT_TECH_INTEGRATION_2026-09-05.md) adapts the
  CMaNGOS bounded retry engine after native eligibility, excluding combat and
  human-directed activity. Do not move retry admission ahead of prerequisites.
  The shared bot UseTaxi helper validates both Turtle endpoints and discovers
  an unknown source only through a matching interactable flight master; it
  never bypasses native anticheat. MinimalMove must retain failed flight legs.
  Dungeon/avoid-list behavior uses the existing strategy/trigger/action/value
  registries and the existing MoveAwayFromCreature path implementation.
  RPG crowd selection tallies eligible nearby bot targets once per selection;
  do not restore the old >=200-neighbor exemption or per-candidate scan.
  MoveToRpgTargetAction consumes the corrected nav coordinates, rejects stale/
  unreachable targets through native values, and only pauses creature patrols.
  ClosestCorrectPoint must preserve its input on query failure (also used by
  corpse recovery). BotRpgMovementTest covers these native boundary fragments.
  The temporary BehaviorTrace hook reads owner-local state and uses the existing
  core performance log with bounded, rotating GUID samples. It must never run
  target-selection triggers, change masters or enable global verbose logging.
  Controls, limits and removal sites are in TURTLE_DIAGNOSTICS.md.
  A Unit owns a MoveSpline before its first path is initialized: check native
  `Initialized()` before reading Duration()/length-dependent data. Trace callers
  must handle absent/fresh/cleared paths without changing the movement API's
  contract. BotTraceSnapshotTest covers the full enabled snapshot body with
  checked spline storage; limiter-only tests cannot establish snapshot safety.
  The September 6 taxi-specific extension reports requested path/from/to and
  probes the nearest flagged flight master within 20 yards only after trace
  admission. It visits both native object containers, including unavailable
  NPCs, without loading grids, and asks CanInteractWithNPC for its optional
  rejection explanation. The predicate's original checks, order and bool
  result remain unchanged; the probe never supplies a new NPC or changes
  eligibility for gameplay. An activation logs route IDs without probing its
  post-taxi state. NpcInteractionTraceTest exercises the native predicate and
  formatter with deterministic map/DBC/reputation services, not a live flight.

- Selected fork adaptations are recorded in
  [SELECTED_FORK_INTEGRATION_2026-09-05.md](SELECTED_FORK_INTEGRATION_2026-09-05.md).
  September 6 AB capture compares real GO entries, not the shim's node indices.
  Only AB bypasses the BUTTON readiness gate; range/interaction/spell/native
  match/node/team validation remain. Attempt spacing uses the existing
  per-bot qualified `last spell cast time` value, never a shared GUID map.
  `UpstreamAbCaptureTest` covers the extracted entry/state/throttle boundaries.
  Null-owner PathInfo calls without an explicit map return NOPATH; native AB discovery
  retains range/eligibility/capture checks; bot broadcasts honor their global gate.
  PetIsDeadValue caches only its database fallback per value instance, not live
  pet state, and Reset/live-pet observations invalidate that fallback. Do not
  replace this with a global cache or a blanket slow cadence for pet reactions.
  ForkIntegrationTest exercises these boundary fragments, not a live realm.

- Native bot travel searches own `std::async` futures. Resetting/replacing an
  unfinished future can join the worker and block the map owner. Full reset
  expires the travel target, retaining unfinished ownership; all three request
  variants reject replacement until ready. Only PREPARE results are eligible
  for adoption. `GetPartitions` releases its existing five-worker permit on
  exception as well as success. Do not detach workers, skip map joins or add a
  second travel engine. `TravelFutureLifecycleTest` covers the native fragments;
  bot destruction still joins outstanding work and is not a bounded cancellation.

- The playerbot node graph persists links, point geometry and derived costs in
  `ai_playerbot_travelnode*`. Runtime loading now recomputes walk distance and
  water exposure from those stored points while retaining creature-risk data,
  and restores the original/upstream 3,600-divisor taxi route preference. This
  avoids a destructive graph/account reset when derived costs are stale. A*
  retains one native graph and applies a stable, bounded per-party preference
  to comparable edges so large populations do not all select one corridor.
  Destination/point ordering is also seeded by party, purpose and coarse
  position rather than wall-clock timing. Short water crossings retain native
  swim timing; sustained swims receive a bounded safety cost so roads, taxis
  and transports win when available without making a required swim impossible.
  `TravelRoutePolicyTest` covers time units, determinism and the preference
  bound; live validation still requires observing route distribution, taxi
  completion and ordinary player travel at the configured population.

- September 6 flight-ID contract: persisted `flightPath` objects are identifiers
  in the currently loaded native TaxiPath DBC, not stable across client/data
  layouts. The compat `sTaxiNodesStore` reads ObjectMgr's DB-backed taxi nodes;
  `sTaxiPathStore` and path geometry come from `DataDir/dbc`. The SQL `taxipath`
  mirror can be empty and is not the runtime authority. On a complete cached
  graph, `generateAll()` now calls the existing `generateTaxiPaths()` before
  coverage warming. Partial/full generation already calls it and must not call
  it twice. Refresh both IDs and geometry through `setPathTo`, retaining native
  cost/eligibility rules. Do not dirty `hasToSave` solely for this startup pass,
  rewrite all cached geometry in SQL, reset bots, or bypass NPC source checks.
  Native point arrays can contain null holes: generation skips incomplete data
  with a startup count. It does not remove arbitrary cached/custom links when
  native data is missing. `BotTaxiCacheRefreshTest` executes these production
  boundaries; see the bot integration ledger for the all-270 live-data audit.

- Custom aura types 227â€“230 are native non-immediate modifiers. Registration
  must cover both `AuraHandler` and `AuraProcHandler` and the `TOTAL_AURAS`
  bound. Actual arithmetic belongs in rage, skill cast time, periodic damage
  done and chain damage taken, using existing aura lists/multiplier helpers.
  Do not substitute attacker spell-ID checks for recipient damage reductions.
  Tests: `NativeCustomAuraTest`; exact affected data and limits: audit ledger.

- The [audit correction ledger](AUDIT_FIXES_2026-09-05.md) supersedes resolved
  baseline findings. In particular, use the live native spell map rather than
  adding another capability cache, retain AI elapsed time across admission
  deferrals, and never write item progress into packed creature/GO quest slots.
- Turtle's `quest_cast_objective` defines player-target spell objectives.
  `World::SetInitialWorldSettings` loads those after quests/player cache;
  `ObjectMgr::LoadQuestSpellCastObjectives` deliberately creates synthetic
  objective IDs. A missing creature-template join is not sufficient evidence
  of a broken objective for these quests.

- [audit-core-contracts.ps1](../tools/audit-core-contracts.ps1) regenerates lexical source indexes and content joins. Without `-RefreshDatabase` it only reads the saved snapshot. Explicit refresh takes the existing local query adapter and issues read-only SELECTs against `tw_world`; it requires network access and valid credentials outside the report.
- The script is an investigator's helper, not a C++ parser. It does not resolve preprocessor branches, dynamic registration, runtime Lua, all summon dependencies, expected encounter design, or live availability. CMake hints for modules/shared are unknown rather than assumed enabled.
- The snapshot contains NPC/content information, not player accounts, characters or credentials. DB reads were sequential, not a consistent-transaction snapshot.
- Existing architecture tests are under [tests/architecture](../tests/architecture). `ContentHookContract.cmake` checks source wiring by lexical/regex assertions; passing it does not establish exactly-once execution or all boss mechanics.
- Diagnostic controls/removal belong in the existing [diagnostic inventory](../doc/TURTLE_DIAGNOSTICS.md), not scattered permanent logs. Disabled summary logging does not necessarily remove timers/atomics.
- Record source revision and fresh evidence on every significant update. Repository documentation makes the knowledge reusable; it does not make an assistant infallible or remove the need to reopen current source.

## Thorn Gorge prototype (2026-09-08)

See [Thorn Gorge implementation and acceptance checks](THORN_GORGE_PROTOTYPE.md).
Map 821 / type and queue 6 is opt-in. BattleGroundTG owns its proximity capture,
flag and score state on the native battleground map update. Generic capture GOs
currently dispatch events on use and do not supply timed player-count capture.
Native queues, GO ownership, spell completion/aura hooks and resurrection are
retained. Spell 59011 is an objective cast with fixed DBC time; completion must
revalidate original GO identity and player eligibility. Client trigger packets
must not advance time. BattleGround::Update can delete the instance and must be
the final call in the derived update. Missing templates now yield no bracket
instead of asserting in Player::GetBattleGroundBracketIdFromLevel.
The extracted client HUD uses 3601/3602/3603 and 3621-3625, not TBC EotS IDs.
Pure rules tests and real-asset route tests are not live gameplay certification.


### Thorn Gorge diagnostic ownership (2026-09-08)

Optional structured match telemetry uses the native LOG_BG sink. Budget and
snapshot state belong to each BattleGroundTG and are accessed only through its
native match callbacks/map owner. Periodic snapshots run before the final base
BattleGround::Update, which may delete the instance. Logging does not change
flag validation order, objective selection or character persistence. See
doc/TURTLE_DIAGNOSTICS.md for configuration and overhead; regression coverage
includes ThornGorgeDiagnosticsTest and ThornGorgeFlagTest.

Thorn Gorge live-test follow-up: AreaPOI worldstates 3606-3617 provide native
ownership icons. Accepted victory quests 42098/42099 receive native event
credit; the paired SQL sets their required-event special flag. See the
prototype guide for tunable capture pacing, lifecycle guards and diagnostics.
ThornGorgePresentationTest compiles the actual UI/quest methods in its harness.

Flag placement follow-up: the live GPS-confirmed Thorn Gorge point is
2174.469482,1569.349243,1160.459473. Deployment uses the existing XY config keys
and native collision height. See the prototype guide for evidence and checks.

### Thorn Gorge match review, September 9

Dropped flags remain available for 30 seconds so travel plus native spell 59011's
ten-second cast can complete. Center respawn after delivery or missing ground
object remains ten seconds; native GO identity/range/LOS/aura checks still apply.
WorldPosition::isBg now reads the core's loaded MapEntry::IsBattleGround metadata,
including custom map_template entries. Its consumers are activity classification,
login classification and test travel filtering; stock maps retain their native
type. The old map-ID list omitted 821 and could demote distant bots once a path
existed. This defect is corrected, but live attribution of the recorded Horde
spawn stalls remains pending. Do not force teleport/revive or bypass path failures.
ThornBotDiagnosticsTest executes native map classification, trace admission and
formatting against deterministic services, including uninitialized splines.

### September 9 upstream refresh

See [integration decisions](SHYALYA_INTEGRATION_2026-09-09.md). AccountMgr::GetName
must fall through to its native database lookup when a cache entry lacks a name;
partial LastIP/e-mail/ban cache entries do not establish a username. Password
changes retain normalization, length checks and verifier invalidation.
ENABLE_SOAP controls compilation (portable, default ON); SOAP.Enabled controls
listener startup (default OFF). Both startup and explicit shutdown join must be
guarded in builds without SOAP. Our native module gossip order is retained.

Spline advance retains native segment completion, cycle wrapping and arrival
callbacks when a segment deadline is already behind time_passed. The upstream
7e63fae3 guard consumes zero time for that expired segment instead of aborting the
world; our log limiter uses an atomic timestamp for parallel map owners. This is
a defensive guard, not proof that malformed path construction has been repaired.
SplineAdvanceGuardTest executes native advance/finalize across normal, zero and
decreasing deadlines, large deltas, cyclic paths and parallel diagnostic calls.

### September 9 ground movement packet continuation

Unit::UpdateSplineMovement resends a linear spline before its last transmitted
vertex is reached. SMSG_MONSTER_MOVE replaces the client's route: the header
must start at ComputePosition(), and the new route must include every remaining
vertex starting at _currentSplineIdx() in the real_path array (whose zero is
spline[1]). The previous last-sent index is a send-watermark, not the next
untraversed point. Reusing the original origin and skipping to that watermark
can draw straight client travel across terrain despite a valid server route.
Partial packet deadlines use spline index lastNode+1; the old lastNode deadline
was one segment early. Preserve full-path/smooth/cyclic encoding and map-owner
movement/arrival lifecycle. No path, speed, collision or teleport rule changes.
SplinePacketContinuationTest executes native writers and decodes ground packets
for initial/continuing/final chunks, remaining corners, late updates and timing;
smooth-path encoding is also checked. The old writer fails on the continuation
origin. This establishes a packet defect, not that all reported geometry issues
are repaired. Live verification remains necessary, especially bridge ledges.

### September 9 battleground PvP reset and carrier presentation

The BG join callback adds pvp to both engines, but subsequent ResetStrategies
recreates them from AiFactory. The noncombat BG defaults must also include pvp,
otherwise an idle bot loses the enemy-player-near emergency attack trigger.
Keep existing hostile target eligibility and combat strategies; god mode only
sets the native minimum surviving HP and is not a target-exclusion flag.
The native BG positions opcode now includes Thorn Gorge's neutral carrier for
both teams, resolved on the owning BG map with membership/in-world checks.
It retains the native count/GUID/XY wire structure and existing WSG handling.
BattlegroundPlayerPresentationTest covers repeated BG resets and carrier absence,
foreign membership, either viewer team, non-BG requests and WSG/AB behavior.
Actual client rendering and renewed human-directed combat require live testing.

### September 9 Thorn Gorge follow-up contracts

BattleGround::AddObject takes optional instance scale (zero preserves template). Apply after successful Create and before Map::Add, update collision model; native ownership, GUID, hooks and failure handling remain. TG uses it for both flag objects and two native countdown doors. Missing door collision fails setup. Model-derived placement still requires client acceptance.

TG strategy exists only in type6 on Turtle. Delivery95, local interception93 and objective travel92 outrank proactive90 while critical survival100+ remains. Stable GUID roles select runner, escort/interceptor, defender or distributed capture. Carrier lookup uses the owning map and BG-team membership, not global holders or race team. Native PositionMap and movement/cast checks remain.

Unit::SetSpeedRate uses a live socket-bearing controller for ACK-driven speed changes. A synthetic connected session has no client to acknowledge; applying its native speed immediately prevents stale mounted ACK restoration after dismount. Real-client possession and pre-world transitions are covered by focused tests. Aura calculations are unchanged.

MoveMap native per-thread/per-map queries read mmap.QueryNodes.<mapId> once at creation (default2048, bounded2048–65535). Map821 uses16384. PlayerWalkable.<mapId> defaults off;821 opts into native NAV_STEEP_SLOPES exclusion for players. Polygon lookup copies include AND exclude flags. When steep exclusion is requested, missing navigation data and forced destinations cannot silently bypass it. This preservation also applies to existing callers explicitly excluding steep slopes, beyond TG; other default map filters remain unchanged.

The native smoother detects a repeated two-point oscillation after an oversized step around a tight corner and retries0.05yd past that corner through the same moveAlongSurface collision/filter query. It does not replace the corridor or invent a direct path. Real assets reproduce the former loop and verify the retry. WorldPosition path assembly rejects an unchanged singleton origin while retaining useful partial prefixes.

TG walking failure can ask the existing cached JumpAction for bounded traversal: at most16 run/walk ballistic candidates per5s, normal jump vertical speed, native collision/landing checks and a following walk improving remaining objective distance. No teleport, unrestricted dispatch or artificial speed is introduced. Native facilities lacked an objective-directed safe jump retry; this uses their existing trajectory/DoJump lifecycle. This is scoped to a live TG, but actual geometry traversal still needs live acceptance.

MT_TG1 is a one-way native addon message for same-BG human sockets, carrying version, instance, status, flag state, faction and remaining timer. Native carrier packets lack colour/timer fields; the client companion supplies those visuals without replacing coordinate APIs. No incoming command or extra thread. WorldMapArea821 is expanded and original art fitted/cropped; four Thorn ADTs add existing ramp models. Matching extracted collision/navmesh are deployed in a separate data directory to avoid mixing live cached trees with new tiles. See client/ManTechThornGorge/README.md and the playtest report for reproducibility and live limits.


### September 9 generic walking failure contract

MovementAction::MoveTo delegates to MoveTo2. ResolveMovePath now receives the
required-path intent before resolving; required walking failure stays empty on
all maps. Native travel nodes and special portal/transport handling are retained.
The shared failure retry cache gates repeats. Detailed ground actors may call
JumpAction::TryGroundTraversal only after failure; it uses bounded existing
ballistics, landing collision/navmesh and subsequent walking progress. There is
no TG-only movement fallback. TG tactics only choose objectives.

MoveSplineInit::Move must interpret PathInfo status before copying coordinates:
NOPATH can carry BuildShortcut coordinates which are not an approved route.
Reject failures, preserve valid normal/incomplete paths and explicit direct
MoveTo requests. Player ground paths use the generic mmap.PlayerWalkable filter;
flight/explicit ignore states and creature capabilities remain distinct. The
per-map query-node capacity setting is independent of this behavioral contract.
CheckMountStateAction requires an actual current target before declaring a close
attack target. Nearby target discovery alone must not create a zero-distance foe.
See StrictPathHandoffTest, GroundTraversalTest, PlayerWalkableFilterTest and
MountTargetDecisionTest. Fixtures cover shared contracts; runtime acceptance and
query cost under populated worlds remain required.


### Long travel mounting preparation

MoveTo2 calls TryMountForTravel after obtaining a valid route and handling native
special transport/portal movement. A long ground journey can outrank idle mount
maintenance; consult the existing check-mount-state action through DoSpecificAction,
which preserves Engine usefulness/possibility/listener handling. Carry its cast
duration into the outer movement action rather than immediately overwriting it
with a walking delay. Idle/reaction/direct movement, combat and movement modes
that cannot safely prepare a mount are excluded. Native mount refusal never makes
the journey fail. TravelMountPreparationTest extracts this actual method; it does
not mock an alternative mount selector. Live mixed-content validation remains.

### Modular migration candidate (2026-09-12; not deployed)

`feature/modular-playerbots` preserves `mantech-turtle` at
`37aee50d6bfbf9194dd5e3c79a156d9bfcb4f569` while integrating upstream's
generic headless-session manager and the `modules/TortoiseBots` submodule.
See [MODULAR_MIGRATION_CHECKLIST.md](MODULAR_MIGRATION_CHECKLIST.md) for gaps.

The CMaNGOS AH service now lives in `modules/TortoiseBots/ahbot`. It uses the
module's verified random-account policy and runs on its world hook after the
map/session owners join. `AiPlayerbot.AhMarketUseCMaNGOS` selects one market
controller. The alternative module market consumes native auction snapshot
pages and retains house ownership while resolving/acting on a live entry;
it captures identity before native buyout can delete that entry. Appraisal
and cancellation use copied entries/counts; no raw auction-map getter was
restored. Native mail/expiry and ownerless random-property initialization remain.

The module registers `.bot` and `.ahbot` through `CommandScript::GetCommands`
and `ChatCommand::ModuleHandler`. `HandleAhBot` additionally enforces
the registered AH command through `IsCommandAvailable` so `.bot ah` and SOAP cannot bypass
the auction permission gate. The old core table no longer shadows these commands.

Combat diagnostics use generic read-only UnitScript attempt/removal observers
and AllSpellScript cast attempt/finish observers at the original native probe
positions. They cannot change amounts or veto native eligibility. The optional
module owns the logger and registers its callbacks; the core has no logging
symbol dependency on it. Existing aura-effect apply hooks provide confirmed
apply observations. These contracts require both optional-build configurations;
runtime acceptance remains pending.

### Modular coordinate pathfinder contract (2026-09-12)

PathInfo's map constructor now supports explicit start/end coordinate queries
through the native Detour path algorithm. Unit-owned behavior stays on the same
implementation. Coordinate callers must provide valid finite coordinates and
loaded map tiles; they exclude steep polygons and cannot force a destination.
Missing meshes/tiles fail closed. Reset preserves the strict coordinate filter.
The per-thread query is map-scoped, as in native unit pathfinding; instanceId is
not a separate navmesh. Unsupported area-cost/fish APIs are not enabled.
CoordinatePathTest compiles production PathInfo with real Detour tiles and mock
host lookup, covering valid routes, gaps, steep polygons, missing maps, invalid
coordinates, reset and unit-owned requests. This does not validate live map assets.

### Modular database dispatch and headless reclaim (2026-09-12)

- Database.AutoUpdate.ModuleAuthUpdateName/ModuleCharUpdateName/ModuleWorldUpdateName
  independently select module data/sql folders (auth/char/world by default).
  Core folder settings still select the core migration tree and regional SQL.
  This prevents a core using "character" from silently missing module "char"
  migrations. Disabled-updater behavior, order and error propagation remain.
- HeadlessSessionMgr::ReclaimForNetwork emits the existing generic
  OnReleaseToClient callback only after validating the request, before session
  reattachment/deletion. Module observers relinquish control, never delete the
  session. Normal session ownership stays native.
- ModuleMigrationDispatchTest and NativeHeadlessReclaimTest execute these native
  bodies with deterministic service/session fixtures. Neither test executes
  live SQL, opens a network client, or proves full character login acceptance.
