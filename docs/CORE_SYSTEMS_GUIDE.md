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


## Modular startup and merged SQL follow-up (2026-09-12)

`Database::Initialize` may fail after creating only part of its configured worker
pool. Cleanup joins actual joinable workers, drains their accepted tail, and resets
the pool; it must not index the requested worker count. Failed connection creation
releases that connection. DatabasePartialPoolTest covers partial/repeated cleanup.

The legacy playerbot-event unique-index migration is manual-only under sql/custom:
it cannot run before an optional module's tables exist. TortoiseBots owns its new
value schema/import. Core and module migration folders remain independently mapped.

Merged world migrations reconcile duplicate Wild Regeneration/skin/quest rows and
are safe to retry on MyISAM. Northwind keeps existing interrogation/report script
ownership and atomic paid gossip; new school menu IDs retain Prestor as the correct
answer. Corpse comb and inspection interactions have separate option IDs.
Ten isolated SQL assertions passed after initial native application and two full
replays of the affected migrations. This is data-contract validation, not a client
quest playthrough.


### Selected-module maintenance and travel follow-up

The module registry owns `rndbot` at administrator rank; the duplicate legacy root
entry was removed. Command work queues GUID/action pairs into RandomBotService,
uses the existing maintenance budgets, and resolves native headless ownership
again before mutation. The disabled module remains optional.

Travel permits, future reset/result lifecycle, taxi cache generation, pet lookup
cadence, Arathi eligibility, RPG target/navigation handling and broadcast disable
are now tested against selected-module excerpts. Fixture API names match the
current core. Queue/cache mutexes prevent local shared-state bugs; they do not
authorize moving the still world-owned AI loop into parallel map jobs.

ModulePacketDispatchTest, ModuleBgObjectiveLifetimeTest,
ModuleSharedValueCacheTest, ModuleRandomAdminCommandTest and
ModuleRandomAdminQueueTest add concurrency, lifetime and command regression
coverage. The suite passes 89 tests; retained donor-only tests remain explicitly
identified by source path until their replacements are implemented.

### Outgoing packet ownership (2026-09-12)

`BotPacketAdapter` submits all three packet directions through
`PlayerbotAIStorage::QueuePacket`. The registry mutex covers lookup and enqueue,
so `RemoveAI` finishes active producers before the adapter deletes its AI. Queue
operations under that lock never execute actions, parse packets, or send replies.
Raw `GetAI` lookups elsewhere still depend on the native lifecycle phase barrier;
this change does not turn raw pointers into lifetime leases.

Outgoing spell failure/delay, knockback, emote and chat notifications are copied
into a per-AI FIFO. `UpdateAI` drains a finite snapshot before its decision delay,
on the current world owner after native map jobs join. Reentrant sends wait for
the next batch. Malformed payloads discard only their own event; an unexpected
exception preserves the remaining FIFO ahead of new arrivals.

Spell and movement notifications originate on the target's native map owner and
capture `Player::GetMapWorkGeneration` there. Dispatch rejects them if the player
transferred, is out of world, or has a pending teleport. Cross-map chat/emote
producers do not read Player state or AI contexts. Ordinary opcode action queues
retain their existing filtering/retry behavior. Each AI lifetime owns its queue;
logout destroys pending reactions instead of delivering them to a relogged bot.

`ModuleOwnerPacketTest` executes the selected module's enqueue/drain methods for
FIFO, reentrancy, malformed/unexpected exceptions, native generation changes,
teleports and 4,000 concurrent chat events. `ModuleAIIdentityTest` exercises all
three delivery directions and removal blocked behind an active enqueue. These
tests do not prove parallel action/strategy execution: world-owned services,
cross-bot actions and remaining mutable caches still require adaptation before
native map AI dispatch is enabled. No new core hook is introduced.


### Delayed reply lifetime (2026-09-12)

LLM reply workers now publish into a weak per-AI mailbox, replacing the
process-wide GUID-addressed queue. The worker waits on futures and reply pacing
without owning an AI, Player or WorldSession. When the AI is released, queued
replies are discarded; a later login of the same character creates a different
mailbox. The native login request token remains private to HeadlessSessionMgr;
this module change requires no new host hook or native session identifier.

The current AI owner drains replies before its decision delay and queues native
client opcodes only while it is still the registered headless AI. Network reclaim
rejects delivery. Malformed chat and command-like replies are discarded; valid
packet read positions are restored before native dispatch. Mailbox synchronization
protects packet data only. Optional LLM network calls are not required for gameplay.

ModuleDelayedReplyTest uses the actual worker/drain bodies to cover deferred
publication, blocked futures at AI destruction, replacement AI lifetimes, normal
delivery, human reclaim and command filtering. The architecture suite now passes
92 tests (8.35s). This does not exercise a live LLM provider or prove that all bot
actions are ready to execute concurrently on separate maps.

### Runtime-discovered lifecycle and catalog gaps (2026-09-12)

The isolated PacketBridgeTest initially passed commands and group invitation but
failed stranded-session recovery. `HeadlessSessionMgr::Update` had no implementation
of the documented five-second grace period. The native registry now accumulates
out-of-world elapsed time after packet dispatch, resets it during loading/teleport
or recovery, and routes an expired session through its existing erase/destroy/save/
online-clear path. The saturated timer cannot overflow on a large world diff.
This is generic headless lifecycle work; there is no new bot-specific host hook.

NativeHeadlessStrandedTest exercises the actual Update body for the exact deadline,
loading, pending transfers, packet-driven recovery, missing players and native stop
requests. ModuleReplySelectionTest covers a missing reply category without random
index underflow. Reply and probability lookups no longer insert missing map keys.
All 94 architecture tests passed (8.05s).

The runtime also exposed an empty reply catalog. Module migration
`20260912091000_world.sql` ports 1,937 reply rows and three probability defaults from
the preserved Tortoise dataset. It stages data in temporary tables and fills missing
entries without replacing existing replies, translations or operator probabilities.
The isolated database check passed repeated application and customization preservation
and rolled back its test edits. The donor's destructive table definitions and
generated help graphs are excluded; this is reply data, not a claim that all mature
bot datasets/help content have been migrated.

The first failed runtime receipt is retained. The checklist records the rerun for
the corrected artifact when available; unit tests do not supersede the runtime gate.

### Decision recovery after exceptions (2026-09-12)

The native module's decision walk restores its previous execution flag on every
exit, including exceptions from context updates, triggers, multipliers and actions.
The adapter already drops malformed-packet exceptions for a tick; previously that
path could leave the engine permanently deferring strategy resets. A pending
rebuild now retries before the next eligible owner tick. Rebuilds do not run during
exception unwinding, and a failed rebuild retains its pending signal for retry.

Popped decision and reaction nodes have local unique ownership. Requeue transfers
that ownership to the existing PushAgain helper; it releases the old node even if
replacement fails. MultiplyAndPush owns all of its input descriptors and temporary
nodes/baskets until the native queue accepts or merges them. The queue's ordering,
prerequisites, relevance, continuation and duplicate-merge contracts are retained.

ModuleEngineRecoveryTest compiles the actual decision/reaction walk, requeue,
MultiplyAndPush and native queue methods with fault-injecting collaborators. It
checks state restoration, deferred and failed rebuilds, teleport deferral, nested
state preservation, reaction payloads, prerequisite replacement, duplicate merge
and object lifetime counts. This module-only correction introduces no host hook
and does not enable parallel AI scheduling or swallow additional exception types.


### Active-module diagnostics and default data (2026-09-12)

TortoiseBots now owns the preserved bounded movement/taxi/Thorn observation sites.
The native NPC interaction and initialized-spline contracts are unchanged; the
diagnostic regressions extract the active module. No new core gameplay hook exists.
The module's world maintenance owns its restored activity PID; this must not be
mistaken for completion of parallel AI map ownership.

Module default-data migration is additive and preserves operator values. MySQL 8
help-column compatibility uses a schema inspection plus prepared DDL on the
updater's existing single transaction connection, replacing MariaDB-only syntax.

### Local build variants and active lifecycle tests (2026-09-12)

Windows CMake retains its historical source/bin default, but respects an explicit
CMAKE_RUNTIME_OUTPUT_DIRECTORY. The local development scripts use separate bin
directories per ON/OFF cache; disabled verification cannot overwrite enabled output.
NativeCharacterMaterializationTest covers synchronous character save, publication
ordering and transient Player/session destruction. ModuleBotDispatchTest covers
deferred AI removal and near/far/pending acknowledgements using active module code.
The architecture suite no longer extracts retired mod-playerbots fragments.

### Generic channel membership query (2026-09-12)

Channel::HasMember(ObjectGuid) exposes the existing IsOn predicate as a const
query on the channel owner. No join, channel creation or client packet is implied.
Both membership containers were private; this removes the need for unsupported
layout access. The module checks the requested channel and Network sessions for
chat audience presence. Membership still mutates under existing channel ownership;
the query adds no cross-thread lifetime guarantee. ModuleSocialPopulationTest
covers audience identity and non-random friend/population semantics.


### Mail attachment transfer lifetime (2026-09-12)

`HandleMailTakeItem` transfers its incoming Item to `MoveItemToInventory`.
`StoreItem` may merge and delete that object; the original pointer cannot be read
afterward. The handler snapshots entry/name/count before transfer for its existing
mail log and response. Native COD, quest/inventory effects, transaction and mail
result ordering remain unchanged. `NativeMailDeliveryLifetimeTest` exercises the
actual delivery/logging fragment with ordinary and deleting merge transfers.
This applies to all native sessions and has no module dependency.


### Native headless logout timer (2026-09-12)

The headless WorldSession update excludes socket-loss and idle-kick behavior, but
must still honor an explicit LogoutRequest's native 20-second timer. Only a world
packet filter can return expired; loading/map passes keep the session. Returning
false delegates saved teardown to HeadlessSessionMgr rather than deleting a player
from the module's AI stack. Ordinary combat stun state is unrelated to this timer.


## Empty-path postprocessing crash (2026-09-12)

The local 30-bot candidate 0cc5857d552f38a0b42f17f2126ed5ec8b05f25c8fb7b456215b7e20b200c537
hit an access violation reading 0xC in PathInfo::CutPathWithDynamicLoS, confirmed
against its matching PDB at PathFinder.cpp:1086. Its dump, executable, symbols and
console log are preserved under the runtime reports/history/logout-0cc5857d.
The population run failed; its earlier focused packet/logout check had passed.

Native fear, fleeing and confused movement call collision clipping before checking
PATHFIND_NOPATH. PathInfo intentionally returns an empty NOPATH for missing tiles,
steep-slope exclusions and malformed coordinates. The clipping loop used size-1,
which underflowed for that supported result. It now iterates only existing pairs
and requires a live unit map for dynamic collision. The sibling caster/melee
postprocessing loops also iterate existing pairs without unsigned subtraction.
Their already-in-range stationary path behavior remains intact. This does not
invent a shortcut or change retry ownership in movement generators.

NativePathPostProcessingTest compiles the actual three functions and covers empty,
single-point, valid clipped/unobstructed, ownerless, missing-map and already-in-range
cases. CoordinatePathTest retains real Detour missing-tile/steep-slope coverage.
No bot-specific branch, new core seam or diagnostic overhead was introduced.


## Native resurrection rejection (2026-09-12)

Player::ResurrectPlayer deliberately refuses permanently dead hardcore characters
unless the caller explicitly supplies forceHc. Corpse reclaim and spirit-healer
handlers previously continued with corpse removal and durability loss after this
refusal. They now require IsAlive before those effects. The solo/AI dungeon-entry
release path similarly removes the corpse and returns through its alive teleport
only after acceptance; rejection falls through to the existing ghost graveyard
route. Forced hardcore recovery remains the existing separate native operation.
These are generic native lifecycle checks, with no bot branches or new hooks.

The module now returns failure from rejected corpse reclaim, spirit-healer and
repop operations before clearing corpse-run/death state, saving, relocating or
reporting recovery. NativeResurrectionResultTest compiles the actual reclaim and
spirit-resurrection functions and dungeon-entry recovery block; it checks normal,
BG, delayed/distant corpse, hardcore rejection and accepted cleanup ordering.


## Social activity snapshot (2026-09-12)

The existing post-map SyncNativePlayers publishes immutable activity facts:
whether a human/controlled population is online, its friend GUID union, and the
real-guild classification for referenced bot guilds. Explicit map execution reads
those values for empty-server/friend/guild priority and relation checks. Existing
world AI retains current native queries. A snapshot may lag a world transition by
one join; it affects activity priority only. Permission, membership and ownership
mutations still resolve current native state on the world owner.

The native PlayerSocial API previously exposed only single-GUID friendship
queries. Building the union with those queries would scan every player for every
bot. GetFriendGuids adds a generic value query over the existing friend flags,
used only on the native social owner; ignored-only entries are excluded. The
module publishes IDs and booleans with atomic shared_ptr replacement, retaining
no Player, Guild or social-list pointer. Each referenced guild is classified once
per publication; no database query or mutation is introduced.

This is an independent host adaptation of the active Sagiroth-derived module,
base 0fb3bc0bff08f5a47d8f6c3e3fc2a9528f538c02, against native SocialMgr/GuildMgr.
No lifecycle hook or bot-specific core branch was added. Joined map AI remains
disabled while packet/chat prelude, trigger/value and other shared-state gates
are completed.


### Native map AI ownership (2026-09-12)

The selected module now registers the existing OnAIUpdate and IsAIUpdateDue
player hooks. Native Map::UpdatePlayerAI owns GUID/generation validation,
foreground admission, bounded idle batches, elapsed clocks and joined map
lifetime. PlayerbotAIAdapter establishes MapScope and retains malformed-packet
containment; network ownership, transfers, missing engines and pending logout
reject AI execution. BotManager no longer executes individual AI on the world
loop. It retains native teleport acknowledgements, lifecycle reconciliation,
logout consumption and bounded world continuations/trades after maps join.

The active Sagiroth-derived UpdateAI performs packet/movement/reaction work
before its action-delay gate. IsAIUpdateDue therefore admits each usable AI to
the native budget instead of treating action delay as permission to skip that
work. Decisions still use their original delay. No new core hook or alternate
scheduler is introduced. The default-off packet diagnostic reports native map
AI only after execution through this hook; its transitional serial probe is
removed. Build/runtime acceptance is recorded separately with executable hashes.
Source: current native Map.cpp/ScriptObjects hooks and the pinned active
Sagiroth-derived PlayerbotAI::UpdateAI; independently implemented adapter seam.


### Turtle autonomous initialization repair (2026-09-13)

The native equipment and random-item caches must generate when their installed
tables are empty. Empty-cache startup previously returned before generation;
full factory initialization could then remove equipment with no replacements.
The builder now indexes native item/class/quality candidates before applying the
unchanged slot/spec/level predicates. Beginner randomization preserves equipped
items and recovers a missing starter outfit through native PlayerInfo and item
storage APIs. Level assignment uses GiveLevel to preserve native stat/talent work.

World-owned random maintenance tracks equipment and initial placement separately
from the assigned level. Failed gear or relocation attempts remain pending at the
existing bounded maintenance cursor; repair does not reroll persisted levels or
talents. Controlled, grouped, combat, queued, pinned and real-guild bots remain
excluded. Cache generation and gameplay after these repairs still require the
next runtime startup; compilation alone does not establish gameplay behavior.

ProcessBot expired-value cleanup excludes nearby humans; that refusal does not
gate initialization or incomplete equipment/placement work. Each initialization
operation keeps its own native ownership and activity eligibility checks.

First equipment-cache persistence uses 500-row native INSERT batches in one
transaction; incomplete synchronous startup builds roll back instead of leaving
a partially populated table that a later startup would mistake for a full cache.


### Sagiroth main 0063f9c integration (2026-09-13)

Integrated upstream d477d74..0063f9c: degenerate movement paths report failure
to the travel caller, missing zone-level cache rows are supplied by the upstream
INSERT IGNORE migration, and Goblin/High Elf bot starts use the upstream mainland
routing and custom-island exclusions. Human racial starts are unchanged. Native
MovePoint/MovePath, transport coordinate conversion, hazard routing and continuation
remain in the local movement adapter; it rejects paths with fewer than two points
before launch and reports failure to MoveTo2, which clears the rejected cached path.

The upstream under-level-10 scatter restriction also applies to our maintenance
relocation entry point. Eligible initialized bots continue directly from successful
gear repair to placement in the same bounded maintenance pass, instead of waiting
for another full population cursor cycle. Failed repairs and placement retain their
pending markers and original eligibility checks. SPECROLL is detail-level logging.
These changes do not establish the cause of every observed idle bot or force the
activity controller to bypass its load limit. Gameplay remains for the user's manual run.


### Bot decision timer accounting (2026-09-13)

Map::UpdatePlayerAI supplies the full admitted per-player elapsed delta to the
native AI hook. The previous 500ms foreground/250ms background cap consumed the
whole timestamp while discarding excess elapsed time, stretching decision and
reaction delays under deferral. Count/time budgets, one AI call per admission,
map generation checks, and separate Player/movement simulation bounds remain.
The retained IdleBotMaxTimerAdvanceMs setting no longer clips decision timers.
Inactive-to-active activity transitions are evaluated before the decision delay
gate, waking passive sleep while preserving explicit waits and casting.

The on-demand privileged rndbot inspect <online-character> command reports up to
eight nearest bots within 120 yards on the same map instance: cached activity,
human proximity/priority, decision delay, time since AI admission, combat and
teleport state. It performs no background sampling and changes no configuration.
Observability counts native network sessions directly; headless sessions were
already excluded and must not be subtracted a second time. Compilation and the
user's next manual run are separate from proving all idle behavior resolved.


### Headless logout ordering, September 13

Dump 20260913_145012 reproduces an exit-time Database::Query fault through
LFTManager::EnsureListingsLoaded, PlayerbotAI destruction, native LogoutPlayer,
HeadlessSessionMgr::Shutdown and World::InternalShutdown. The latter runs after
Master closes databases and WorldRunnable unloads maps. World::Shutdown now drains
headless sessions beside network-player logout, on the world owner under the
existing session update mutex, before maps and database dependencies disappear.
It retains native logout, save and online-state cleanup. InternalShutdown's
second call is empty/idempotent; pending sessions retain their existing unsaved
cancellation path. This generic lifecycle change belongs in the core-hooks
commit, independently of which bot module is selected. Verify clean exit after
the next 500-bot run; the preceding gameplay run alone did not test clean exit.

Native headless shutdown verification: build29 exited with 500 sessions at 14:55:57-14:56:04 without a new dump; characters.online=0 afterward. Independent pet_spell duplicate-key errors still occurred and are not resolved by shutdown ordering.


### ManTech host-contract follow-up, September 13

World::Shutdown now drains native headless sessions before map and database
teardown, retaining LogoutPlayer/save/online cleanup. Repeated InternalShutdown
draining is empty. The 500-bot dev exit completed without the former DB-after-close
crash. ObjectMgr::LoadPetNumber chooses above the maximum ID in character_pet and
pet_spell/pet_spell_cooldown/pet_aura, then preserves the existing allocation lock
and cache collision checks. Child-row orphans must not make a new pet inherit an
old identity. No orphan deletion or duplicate-write suppression was introduced.

Master Strike's native script owns the weapon-dependent helper effect. Its
OnEffectExecute consumes only effect1 when it is TRIGGER_SPELL with trigger0;
damage, the post-damage helper selection and any defined nonzero trigger remain.
These generic native changes are designated separately from module behavior.
See MANTECH_PLAYERBOTS_PORT.md for runtime evidence and unverified variants.


### Native read/access contracts for ManTech, September 13, builds 39-48

MoveMap::IsMapTileLoaded reads the native loaded map and tile state under existing
locks. VMAP tree queries also use their native tree locks. Callers must respect
the native coordinate/file convention: map-grid X follows world Y and grid Y
follows world X. A guessed loaded=true is not a safe optimization.

PathInfo now exposes actual walk polygon area/flags and opt-in area costs.
Ground avoidance mutations hold dtAccessGate::Write across discovery and update;
water/magma/slime/steep flags are preserved. Query filter costs reset on request
reuse. Native consumers retain default costs unless they opt in.

Maps/AreaTriggerAccess is the shared native teleport-eligibility helper. It may
redirect the candidate entrance for a ghost's corpse map. It does not perform
teleports or bypass scripts/proximity/quest/tavern/BG handling. Its Player and
Map reads require the same owner/lifetime discipline as the native handler.

LootTemplate::GetEntries and VisitGroups expose read-only loaded rows, including
both explicit/equal-chance group lists. No concurrent reload is supported and
visitors must not retain references or mutate the store. This replaces unsafe
module layout casts without changing native loot generation. Bot loot inspection
uses native LootView and per-player LootItemInSlot; awards/release/quest abandon/
skill unlearning retain native session handlers and their side effects.

These generic APIs belong in the independently designated core-hooks commit.
Bot eligibility policies, recovery actions, trainer convenience and diagnostics
remain module changes. See MANTECH_PLAYERBOTS_PORT.md for actual runtime evidence.



The loot visitor interface uses LootEntryView (pointer/count ranges), not the
native allocator-tagged STL containers. Allocation category tags have internal
linkage; putting those container types into the callback signature caused an
unresolved external across compilation units in build48. Build49 uses external
plain view types, and both native symbols were confirmed in game.lib. This does
not change allocator policy or native container ownership. Views expire with the
store and cannot be retained across reloads.


### ManTech recruitment transaction hooks (September 13)

GroupScript::CanInvitePlayer and OnPlayerInvited retain the actual inviter,
including raid assistants. Native HandleGroupInviteOpcode calls eligibility
after its faction/hardcore/ignore/group/capacity checks, before allocation, and
notification only after a successful AddInvite and invite packet. Existing
OnInviteMember remains unchanged. Default implementations preserve other modules.
The ManTech module wires its baseline BotRecruitment eligibility/notification
and bounded Update on WorldScript::OnUpdate, after map jobs join. It retains
native HandleGroupAcceptOpcode, stale-invite checks, capacity, control and
preparation policy; no direct membership insertion or automatic gearing bypass.
Designate these generic hooks separately from the module's registration for PR.

The user-requested /who change removes the 30-second player cooldown. Existing
in-flight request coalescing, native filters and 49-row client limit remain.

### ManTech module integration ownership (2026-09-13, build60)

The active module owns shared cached-value AI lifetime explicitly. Shared value
calculations/mutations use per-value recursive locking; escaped mutable references
are not covered by that lock. Trainer offers use both native lists with entry
precedence, per-trainer requirements and full offer identity; native purchase
handlers remain authoritative. Twelve travel request sites use five dedicated
native MapTaskExecutor workers with128 outstanding admission, below its256-job
inline fallback. Invalid admission results follow the normal travel retry path.
WorldScript::OnShutdown drains these workers before native entity/data teardown.
Manual RPG responses resume only on the serialized PlayerbotAI owner, one due line
per update, with target revalidation and reset/replacement cancellation. Worker
captures remain values. See the focused module tests and the September13 ManTech
integration audit for evidence and unresolved cross-map/data-lifetime boundaries.


### ManTech generic native contracts (September13, build69)

SqlTransaction opt-in deadlock retry replays the entire queued transaction only
after confirmed1213 and successful rollback, at most3 attempts. Native MySQL
connections permit this only when every base table in the schema is InnoDB.
Player::SaveToDB opts in; direct saves enqueue their character-row operation too.
Ambiguous commit errors, mixed schemas and unmarked transactions are not retried.
The explicit character migration requires the world stopped and uses DYNAMIC rows.

HeadlessSessionMgr BeginStopDeferral/EndStopDeferral protect module callbacks
which request their own stop. Nested scopes defer destruction to the outer exit;
the original request token prevents logout of a replacement login. These guards
do not constitute arbitrary concurrent manager access or a StopForAccount guard.
World exposes generic forwarding methods. GuildMgr::GetLeadershipSnapshot copies
guild/leader IDs under its native lock; callers may not retain native guild pointers.

The module's WorldActions queue runs only from post-map WorldScript::OnUpdate,
after map jobs join. It validates account/AI identity, event identity and native
map generation, and wraps each callback in the stop guard. Its256-callback/8ms
soft budget and1024 queue bound are module policy, separate from generic hooks.
Engine decision state is retained across ownership handoffs; a continuation must
not populate triggers again. Master managers likewise update in this world phase.
TransportAnimation lookup is module-owned installed DBC data, with no replacement
of native moving-transport simulation. See the integration audit for test limits.


September 13 pool expansion: `RandomPlayerbotFactory::CreateRandomBots` discovers
all existing accounts with the configured random-bot prefix, adds only the
account-count deficit through native bounded creation, and provisions the
combined pool by account ID. Migrated non-sequential account suffixes must not
cause existing characters to be excluded or a second full pool to be created.
Existing full accounts retain their characters. Native cleanup of temporary
bots remains unchanged; the development preflight found no temporary bots or
empty bot accounts before one-time expansion. Character GUID preservation and
the post-startup pool count are recorded in the local workspace receipts.


### Arch4 native ownership and enhanced diagnostics (September 14)

See [Arch4 Turtle integration](../docs/ARCH4_TURTLE_PORT.md) for implementation,
coverage and removal controls. Detour capacity accessors are read-only; navigation
and collision charges follow successful allocation/install, native unload and
owner destruction. PathInfo records its native retained vector capacity without
replacing movement or mesh ownership. Diagnostic executor wrappers keep exception
propagation, bounded inline fallback and mandatory joins. SQL acquisition scopes
measure the existing recursive lock; driver scopes preserve retries/return values.
The CMake flag now survives subdirectory definition replacement. Observer-only
heap summaries, sampled allocation survival comparisons, bounded slow-operation
records and expanded named timing tables use the current ManTech diagnostics.
They do not establish 10k-bot stability or complete memory attribution. Native
capacity, diagnostic concurrency/overflow, allocation and executor lifetime tests
are maintained in the independent architecture suite.


### CMaNGOS background AI cadence (September 14)

Opt-in restart-only `MapUpdate.BackgroundAI.CmangosScheduling=1` enables GUID
staggered full turns at ceil(world average ms / 10), tripled on empty maps.
Combat, player interest and transitions retain native foreground handling.
Between full turns, due background requests use minimal AI and retain existing
count/time budgets and map generation validation. ManTech reschedules minimal
updates to max(existing wait, passive delay, 10*reaction delay) plus up to
`MapUpdate.IdleBotJitterMs` (default 4000) of deterministic GUID staggering.
Due-time accounting remains Turtle-native: only NOT-due probes decrement the
timer, and admitted AI consumes the remaining elapsed time once. CMaNGOS's
delayAlreadyAdvanced flag must not be copied into this different contract.
The diagnostic named timings `background_minimal_ai` and `foreground_full_ai`
use existing DevDiagnostics controls; no packet/capture logging is enabled.
This scheduling port alone does not establish full-population stability.

Follow-up in the same scheduling fix: WorldSession constructor initializes all
recent-packet flags. Headless sessions drain the world queue and bypass network
map packet passes; uninitialized spell flags otherwise incorrectly promote idle
bots into the foreground lane. Native packet dispatch still sets/clears flags.
The source-extracted regression constructs these flags over dirty storage.


### Bot chat admission cost (September 14)

The full-load stall persisted after background scheduling: sampled map work
still repeatedly entered Channel::Say -> every recipient's outgoing-chat hook.
Reply selection now precedes strategy, cooldown-value and sender-name lookups
for free-bot messages. Human LLM messages retain their cooldown exception;
recording, special links, mentions, guild gates and addon/debug filtering remain.
Reply probabilities are unchanged; RNG draw ordering on discarded/paused messages
can differ. The unused non-self channel-source lookup was removed. Item/quest
link extraction skips link-free text and shares immutable compiled patterns.
No chat mute, eligibility reduction, DB or login-threshold change was applied.

Focused commands (initialized MSVC): tests/architecture/run_chat_admission_test.py
--output DIR and run_chat_link_test.py --output DIR. Actual source excerpts are
compared against retained pre-change behavior with mock packet/AI boundaries:
11520 policy combinations, 10000 rejected recipients avoiding strategy/value/name
lookups, malformed/duplicate/overflow link behavior, and 8 concurrent readers.
The scoped stack samplers exited; no continuing capture was enabled.

### Locale contention follow-up — build80 full-activity trial

The build79 full-activity plateau reached roughly5440 bots. A bounded stack
sample found many map workers blocked in MSVC's locale lock through Boost
istarts_with in the per-recipient toxic-link check. ChatPrefix.h pins the current
C++ locale/ctype facet once per thread and uses its toupper operation directly.
A cheap link-token presence guard skips the entire predicate for ordinary text.
No runtime C++ global-locale mutation was found in the core/active module; a
future feature that changes it must revisit this cached-facet contract.
ChatPrefixTest.cpp passed all65536 byte pairs against the actual Boost predicate,
empty/short inputs and8 concurrent readers. Its bounded80k-call fixture measured
75ms for the default Boost path and under1ms for the cached path on this run;
this is a local microbenchmark, not a claimed full-server improvement.
The11520 recipient-policy comparisons also passed after this change.
Build80 succeeded but is deliberately NOT deployed during the user's20% activity
control; runtime remains build79 with botActiveAlone20 and priorities override0.


### Native channel recipient allocation cost (September 14)

The build79 20-percent stack sample still showed channel broadcasts traversing
player wrappers, heap allocation and social lookups. SendToAll now resolves the
same Player or MasterPlayer directly at each delivery, selected by the existing
m_area_dependant flag. PlayerWrapper merely forwarded calls through a reference;
its shared_ptr owned the wrapper, not the player. This removes per-recipient
wrapper/control-block allocations without extending any native object lifetime.
Recipient order, live lookup, ignore checks (including empty sender GUID), and
WorldSession::SendPacket hooks are retained for chat and channel notifications.
No pointers are cached across recipients or ticks, and no work moves to another
thread. Existing channel membership/owner-phase contracts still apply.
The focused runner is tests/architecture/run_channel_fanout_test.py --output DIR.
Source-extracted comparisons cover both native lookup variants, missing/departing
recipients, ignored senders, repeated packets and a 10,000-recipient fanout.
No additional always-on diagnostic or configuration setting was introduced.


### Synchronous bot broadcast sender metadata (September 14)

Build80's bounded full-activity stack sample had no locale-lock frames, but
repeated HashMapHolder<Player>::Find and AccountMembershipIndex::Contains calls
remained in recipient chat admission. The module's seven synchronous channel Say
sites now establish a thread-local RAII sender scope. It computes the existing
random-account/free-alt/real-player predicates from the same live sender once.
Matching recipient packets reuse that boolean only until the native call returns;
other senders and packets outside the scope retain the full original lookup path.
The scope holds only scalar metadata, restores nested scopes, and crosses no
thread, queue, tick or player lifetime. Native async/human chat is unchanged.
The expanded46080 admission cases compare both the fallback and scoped paths,
including free-alt senders under real-player control. A10000-recipient rejection
fixture verifies scoped delivery performs zero sender account lookups.
ChatBroadcastSenderTest covers nesting, mismatches, false classifications,
scope exit, unwinding and independent threads. No new runtime switch or log.


### LLM channel audience fallthrough (September 14)

The unattended build81 trial stalled around7354 bots/317ms with no DB or world
action backlog, although build80 had reached10000/95ms with a player connected.
ChatReplyDo explained an audience-dependent traffic change: inside the eligible
LLM branch, no human channel audience set the sender pointer to null. That skipped
the LLM policy's terminal return and fell through to SendGeneralResponse, creating
canned bot-to-bot reply chains. The same message with an audience did not take
that canned fallback. The no-audience branch now returns explicitly.
This deliberately corrects reply behavior for LLM-managed channels without
humans; it does not change bot activity, admission thresholds, LLM settings or
external request permissions. LFG/WTB/special-link handlers remain before the
guard. Non-LLM and blocked-LLM channels retain their canned path. Direct messages
and channels with an audience retain existing sender/LLM policy.
The receiving CMaNGOS shared module contains the same old branch and should
review this correction independently. Full-load acceptance remains pending.


### September 14: final full-activity acceptance

Build 82 is deployed from build/mantech-playerbots/bin to the Turtle WorkFolder runtime. SHA256: 9A4C61A8443E557E334D17A03A9BA59981F4D552581744082CA830050296530D. The development target is 10,000 bots, botActiveAlone=100, DisableActivityPriorities=1. The unattended full-population interval passed with zero real players and 83–104 ms sampled average ticks; native invite/summon/loot/logout checks passed afterward. See docs/TURTLE_FULL_ACTIVITY_FIXES_2026-09-14.md for the full result, exact observations, behavior correction, and limits. Earlier pending build 76/80/81 throughput notes are historical. Other cores and production were not changed.


### September 14: player-present queues, native mail count, movement activity

The build82 unattended acceptance remains a bounded historical result. The later
player-present run reached 391–500ms mean ticks and 29,536 cumulative rejected
world actions, then returned to approximately96ms after humans left. It is not
full player-present acceptance. Short stack samples identified movement packet
admission locks and world continuations dominated by empty mailbox checks.

Build83 changes PacketHandlingHelper to reject unregistered opcodes before its
queue mutex. Handler registration occurs only during PlayerbotAI construction;
ExternalEventHelper treats that map as const. Callback execution stays outside
the mutex, and exception unwinding now restores untouched/retry packets beneath
new arrivals, consuming only the failing packet. Native packet hooks are intact.

MasterPlayer publishes an atomic count after AddMail, LoadMails, RemoveMail and
SaveMails structural mutations. Only this count is cross-thread readable; the
mail list, iterators and processing retain their native owner. The module's
mail-available trigger follows the existing often node and reads its cached true
state without another random draw. Master/BG/combat and empty mail exclude the
automatic continuation; execution still rechecks usefulness on the world owner.
Direct mail requests and native delivery remain unchanged. A soft-deleted mail
row allocated by LoadMails is now deleted before skipping it; it never entered
the owning list. This fixes a demonstrated leak, not the whole unexplained RSS
growth. LoadMails is called by native character login; no new reload path exists.

Map::IsAutonomousActivePlayer now includes an unfinished movement spline and
native non-melee casting. Moving bots previously fell into the hibernated lane;
UpdateRealTimeBounded capped movement elapsed to500ms then reset its clock,
losing travel time when the lane ran less frequently. Promotion uses the existing
active stride and native timer bound. It also promotes the existing AI lane and
may increase real workload; 10,000-bot performance must be measured after deploy.
No activity target, login safety guard, native timer limit or worker ownership
was weakened to obtain a larger population count.

Focused source-extracted tests: tests/architecture/run_player_present_fixes_test.py
--root CHECKOUT --output DIRECTORY, plus run_background_ai_test.py. Coverage:
4,000 concurrent packet producers; reentrant/delayed/exception ordering;
100,000 unhandled packets bypassing a held queue lock; native activity predicates;
100,000 mail count publish/read cycles; empty mailbox and existing often result
gating; fixed outcome bounds/reset; requested-spell nesting/thread isolation.
These are focused contracts, not a certification of all class combat behavior.


### September 14: correction to full-decision scheduling (build84)

Build83's bounded progress cohort exposed mostly unchanged sampled positions and
expired travel targets despite 100-percent eligibility. Native inspection of
Moribalhul (GUID512) confirmed movement/travel allowed, the travel strategy present,
valid mmap/vmap data and a valid31-point approach to the nearest travel node.
It had not assigned a travel destination. It was not proximity-disabled.

The minimal-update floor introduced during the throughput work wrote into
aiInternalUpdateDelay. Full map turns bypassed the scheduler's due check but the
real PlayerbotAI::UpdateAI still honored that same internal timer. Repeated
minimal floors could therefore suppress every full decision. The previous test
counted admitted full updates, not decisions past that timer, and missed this.
The low-tick unattended build82/83 results remain population/latency observations,
not proof that all eligible bots were actually making independent decisions.

Build84 stores the minimal-pass throttle separately in PlayerbotAI, four bytes
per bot. The native due hook consumes both countdowns only if no call runs;
deferred work retains elapsed time. OnAIUpdate consumes the minimal countdown
before invoking native AI. Full/critical turns ignore that throttle and retain
the real action/spell countdown. Post-minimal scheduling revalidates map, GUID,
generation, AI identity and transition/combat/master status before storing it.
AI reset clears the new scheduler countdown alongside the existing action delay.

A scheduler-requested minimal pass no longer adds the synthetic Yield delay to
the action timer. Actual action/reaction/spell delays are left intact. Full calls
retain the native out-of-combat/real-master Yield policy; configured activity
policies and their own passive delay are unchanged. Native ownership, map jobs,
cadence, login guards and100-percent eligibility settings are unchanged.

run_background_ai_test.py now runs the retained build83 hook fixture against the
actual corrected hooks with the native countdown/CanUpdate/Yield contract.
At100ms ticks, no humans and the configured4000ms jitter, 5174/10000 legacy idle
bots never crossed the full-decision timer gate over five simulated minutes;
the corrected count is0/10000, with at least90 full decisions per bot. A separate
five-second action-delay case confirms no deadline bypass. Transfer, unlink,
transition, combat promotion and deferred elapsed-accounting cases still pass.
This isolates the timer defect; live10,000-bot progression/performance remains
to be measured on build84. The simulation is not full gameplay execution.


### Travel queue admission (September 14, build85)

Build84 reached 10,000 independently eligible bots but its post-map WorldActions
queue saturated: at08:39:42, 931 queued and452,233 cumulative rejected admissions,
despite133ms mean world ticks. The selected travel counters contained5,340
`not_preparing` outcomes versus561 selections. Population-only success is not
healthy activity. This observation supersedes any provisional acceptance of84.

ChooseTravelTargetAction now rejects non-PREPARE work as useless before the
world handoff. This action has no native alternatives/prerequisites; only its
search-consumption operation requires PREPARE. Derived group/refresh/reset actions
retain the original general IsTravelUseful predicate and their own status rules.
Request actions reject owner-local active-target/no-destinations flags before
handoff. Every dynamic RequiresWorldOwner=false path exits isUseful immediately,
before group readiness or destination state can be read. Viable work still uses
the serialized native owner. The cached active value calls TravelTarget::IsActive,
which only reads its owner's status; no-destinations is a manual per-AI flag.
Future readiness is deliberately excluded because workers may complete between
admission and execution. Group pointers are only tested for presence locally.

No queue bound, drain budget or activity percentage was increased. The source
regression enumerates224 status/flag combinations and checks rejection precedes
unsafe usefulness checks. Existing world queue tests cover concurrent bounds,
generation/actor/event cancellation, stop deferral and engine continuation epochs.
Live effectiveness is recorded separately in TURTLE_ACTIVITY_FIXES_2026-09-14.md.

Build84 scheduling-regression clarification: with the actual10,000ms PassiveDelay,
5,369/10,000 old-hook bots miss all full decisions in five simulated minutes at
100ms ticks;5,174 is the2,000ms variant. Both corrected variants have zero starved
bots, and each corrected bot reaches at least90 full decisions. Real action delay
preservation is a separate assertion, not inferred from callback admission.


### Serialized service budget (September14, build86)

Build85 removed non-PREPARE travel admission and still reached7,829 bots before
world actions saturated again (940 pending,1,053 rejected,153ms mean). Mail
dominated queued count but not cost: sampled check-mail execution max59us,
whereas spirit/corpse navigation dominated observed world-action time. Do not
infer expensive work merely from pending action names.

WorldActions::Drain now receives native WorldScript::OnUpdate diff and uses
clamp(diff/4,8,32) milliseconds rather than8ms regardless of tick length. The
nominal30ms-tick allowance is unchanged; at160ms, the old service allowance fell
to roughly50ms per second. The bounded proportional allowance avoids that loss
of service while allowing at most24ms extra in one pass. No unused time is carried
forward. The1024 queue and256 callbacks per pass remain unchanged, as do native
post-map ownership, lifetime/generation/event guards and per-bot admission.

This is a soft budget checked between callbacks: one native callback can exceed
it and is not interrupted. PB_DIAG_MANAGER adds world_budget_ms,
world_last_drained and world_last_drain_us; these describe the last completed
drain, not a whole-window percentile. Scalar atomics add no histories or pointers.
The existing diagnostic toggle controls output. Tests use the actual queue with
a deterministic clock:8 and32 one-millisecond callbacks,UINT32_MAX clamp, no time
credit, a100ms overrun reported after one callback, and the256-callback bound.
Live queue recovery/full-population results are recorded in the activity report.


### September14 build86: bounded full-load and player-present result

Deployed SHA256 `F2AB45A766401AE3C80C04E8939883A89017DD97D4C9C7BD2A1F3D6AAA2EF630` to the authorized Turtle WorkFolder runtime;
world PID28072, started2026-09-14T09:03:38.0663593-05:00. Target10,000, botActiveAlone100,
DisableActivityPriorities1 remain in the runtime config. Binary hash rechecked.
The final run reached10,000; unattended retained mean ticks167–189ms, Southshore
three-minute player hold188–220ms, no world-action rejections. Native login,
invite(0.719s), cross-map outdoor summon(0.812s), whisper summon, master/FFA/group
loot and group retention/logout passed; isolated fixture positions restored.
The last recorded unattended sample at2026-09-14 09:38:06 has10000 bots,
167ms average and0 world actions pending.
See docs/TURTLE_ACTIVITY_FIXES_2026-09-14.md for exact intervals, queue bursts,
timer-starvation correction, travel admission, service policy and remaining
content/memory limits. This supersedes provisional build82/83/84/85 acceptance
claims; it does not certify every gameplay scenario or a multi-hour soak.
The dev world remains running. No production or other core was changed.

### Nullable legacy random-bot event payloads (September14)

Playerbot event persistence permits SQL NULL payloads. Every cache ingestion path
must use Field::GetCppString() for optional text instead of constructing or
assigning std::string from Field::GetString(). Build87 corrects both the lazy and
bulk event loaders; existing legacy bots and saved event values are retained.
Coverage: modules/ManTechPlayerbots/tests/turtle_nullable_events_regression.py.


### Upstream loot/travel admission sync (September14, build88)

The Turtle module includes the reviewed CMaNGOS delta through 266268c6. RPG and
travel movement now defer while the selected loot target remains lootable;
incidental RPG healing also defers, while party/selected-target healing retains
its existing safety and urgency rules. Native ownership, NULL-safe event loading
and Turtle adapters are unchanged. See TURTLE_UPSTREAM_SYNC_2026-09-14.md.


### Penqle upstream chat and trade compatibility (September 14, build89)

Upstream main through d886113c is merged. Delivery-gated module chat hooks,
OnChatYell and BeginTradeWith are present; the active ManTech module retains
its existing chat-command/outgoing-packet integration and scheduling.

BeginTradeWith preserves native fingerprint, hardcore and optional Eluna
trade-init restrictions. Both sessions/maps must exist before allocating trade
state; GetMap asserts on an absent map. Callers must own both players' execution
domain. Items/gold/acceptance remain in the existing native acceptance path.
This additive API is not yet used by the active ManTech module.

Addon preprocessing validates payloads but does not run text command parsing
or ordinary pre-send chat hooks. Destination-authorized OnAddonMessage remains
in the handling switch. This completes upstream's channel-only protection for
party/guild/raid/battleground addon paths. Normal text chat retains its hooks.

Focused source-extracted regressions: run_trade_helper_test.py (24 cases each
with and without ENABLE_ELUNA) and run_addon_parse_test.py (56 cases), both in
tests/architecture and accepting --root SOURCE --output TEST_DIRECTORY. These
exercise actual method bodies with controlled dependencies, not full-world
Eluna execution or trade settlement. Existing chat admission/link regressions
also pass. See TURTLE_PENQLE_SYNC_2026-09-14.md for the deployment/live result.

### Build89 runtime follow-up (September15, build90 candidate)

The selected ManTech module checks the same DBC name rules as Player::LoadFromDB
before including imported characters in its random pool. Failed names remain
intact for owner-directed rename; eligible existing characters refill the target.
Completed query holders release their population reservation even when native
admission rejects login. Native bans, ownership, rename and session checks remain.
Name creation consumes rejected candidates under one lock; an exhausted pool
must not call the locking public name picker recursively.

OutdoorPvPEP now uses Turtle WorldSafeLocs128 at (1978.47,-3655.89,119.79), beside
the Crown Guard banner. The previous927 does not exist in the deployed DBC.
Native LinkGraveYard/UnLinkGraveYard still own capture, neutralization and faction
transitions, with inDB=false. RemoveGraveYardLink removes a neutral existing link
when called for a faction, so the database's default128/139 link is handled by
existing capture initialization. Other graveyards remain untouched. The manual
world SQL cleanup removes only redundant, loader-rejected subzone rows136/5180
and137/2041 when an encompassing parent link exists; it adds no graveyards.

Bot merchant-purpose selection and selling require stock in at least one native
entry/template list, matching gossip's merchant availability. Quest/gossip and
native purchase conditions remain separate. Performance-monitor labels in three
AI update paths are now constructed only while that monitor is enabled; this
does not disable runtime diagnostics or change activity/scan scheduling.

run_turtle_build90_fixes_test.py compiles actual source bodies against controlled
fixtures for20 reproduced DBC-rule failures, admission/security variants, repeated
completion, name-pool exhaustion, vendor lists and native graveyard transitions.
These focused regressions do not certify live combat or long-run memory behavior.


## September 15 build91: ManTech pursuit, incidents and party tactics

The module's ReachTargetAction records lack of LOS/progress and feeds bounded
per-AI target exclusions into existing AttackersValue validation. Native movement,
combat ownership and encounter behavior are retained. Player-led bots, PvP and
enemies already fighting are exempt. Full reset/resurrection/map transitions
clear pursuit state. Incident collection is a separate optional observer.

`.bot action interrupt` and `.bot action cc <mark>` reuse the world-owned
BotRecruitment dispatcher, its controller authorization, bounded queue and receipt
cache. Requests expire after three seconds and revalidate lifecycle, party, map
and selection/mark before one eligible bot calls the existing native casting
helper. A started response is admission, not confirmation of the spell's effect.
No new native hook, packet ownership change or database migration is introduced.

See modules/ManTechPlayerbots/docs/TURTLE_BOT_CAPABILITIES.md for supported
abilities, exclusions, protocol and diagnostic controls. Focused tests compile
actual module policies/dispatcher/executor and retain existing native ownership
and recruitment regression coverage; live combat effects remain separate checks.


### Penqle 1.18 development refresh (September 17)

Penqle `1181dev` through `010cdb6d` is integrated over the September 14
baseline. The Moonwhisper quest and Holy Strike/Mending Light source changes
retain their matching world migrations. Mending Light now filters invalid and
full-health targets, prioritizes an injured caster, and applies the caster
healing reduction after the complete effect total is known.

Channel admission is checked before module broadcast hooks execute, and the
hook remains on the caller/world thread rather than the asynchronous delivery
thread. The local `Player*` channel overloads remain adapters to the native
`ObjectGuid` path; they do not bypass membership, mute, moderation, or public
channel echo-only rules.

SOAP now authenticates before reading the request body, checks live database
rank and ban state, limits requests to 64 KiB, and retains the authenticated
rank when the command is queued. The local explicit stop signal and shared
callback lifetime remain in place so shutdown joins the listener before the
databases close. Windows builds use the parent OpenSSL include directory and
install ACE when dynamically linked; local external OpenSSL overrides and the
existing playerbot Boost link path remain supported.
