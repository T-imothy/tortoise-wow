# ManTech Playerbots native port

Feature authority: current ManTech CMaNGOS Classic baseline
`c271085c92c380142a90a5514cf54a69b8f8ac37`.

The source is `modules/ManTechPlayerbots`. Preserve its AI configuration, LLM,
population/loading scheduler, diagnostics/reports, commands and Classic behavior.
Adapt host contracts to the current Penqle core. Neither retired Turtle bot code
nor Sagiroth behavior is the baseline. Existing native adapters are reference
material requiring contract review, not evidence of completed feature parity.


### Current state (September 13, build69)

Build69 is deployed in the user-selected Turtle dev output. The test target is
6000 with independent activity enabled. Save replay, human presence snapshots,
bounded world-action ownership, asynchronous debug/manual LLM, native quest
relations, voice emotes and transport animation lookup have been integrated.
Native client login, owned-bot invitation and a private live LLM response passed.
The scale run and exhaustive Turtle gameplay acceptance are distinct from these
engineering tests. See [the current audit](MANTECH_PLAYERBOTS_INTEGRATION_AUDIT_2026-09-13.md)
for exact evidence and limitations. Runtime credentials remain outside Git;
no commit or push has occurred. Earlier build sections below are historical.

## Review and commit boundaries

1. **Core hooks**: generic session/AI/lifecycle/native APIs, independent of bot
   implementation. Keep these changes in a separate commit/PR for Penqle. Trace
   callers and maintain both module choices. Never stage unrelated core changes.
2. **Module port**: ManTech implementation and its native adapters, configuration,
   data and feature preservation. Separate repository history retains the donor.
3. **Local development**: build/deployment instructions, separate from reusable
   hooks. Runtime credentials stay outside Git.

Only one bot implementation may own sessions/AI in a build. The dedicated
`dev/build-mantech.ps1` selects ManTechPlayerbots and disables both other bot
modules. It builds into `build/mantech-playerbots` without deploying. Integration
is incomplete until native contracts, full build and configuration/data migration
are finished. Do not publish an intermediate binary as the completed port.

## Generic prepared-login hook (integration in progress)

`World::StartPreparedHeadlessSession` adopts a completed, unbound headless login
query bundle. This retains a module's query batching/prefetch policy while keeping
native admission, request-token validation, login handling, and session lifetime
in `HeadlessSessionMgr`. It consumes the holder on success and failure. It is a
world-owner API, not a worker-thread callback. Bound/network holders are rejected.
The ordinary `StartHeadlessSession` API remains available to existing modules.
`Handlers/LoginQueryHolder.h` now forwards to the native type rather than defining
an incompatible second class with the same name. These host files belong in the
separate core-hooks commit. The module's scheduler/transport adapters belong in
the module repository. Neither group is committed or runtime-certified yet.

## Turtle gameplay adaptation (required, 2026-09-13)

Compilation is complete for the initial native integration, but gameplay parity
and deployment are not certified. The port includes a system-wide comparison of
the installed Turtle talent/DBC data and native spell templates with ManTech's
Classic talent paths, spell selection, triggers and class strategies. Retain the
ManTech features while adapting their gameplay assumptions to Turtle.

Goblin and high-elf bots must begin in their actual native starting regions and
progress into suitable mainland zones. Do not substitute mainland character
creation or blacklist their homes as a workaround. Player::Create and generated
start nodes already consume PlayerInfo; the installed world defines goblin start
zone 5536 and high-elf start zone 5225. The existing race/class lists match all
eleven custom-race PlayerInfo combinations in this database.

Random relocation keeps these races below level 10 in their native home region.
At level 10 and above, they use faction/level eligibility rather than Classic's
race-specific mainland exclusions. Normal quest travel remains independent of
this random relocation policy. Existing level-based grind eligibility remains
responsible for rejecting outgrown starter mobs. Review natural exits separately:
Blackstone's flying-machine route is native scripted gossip (taxi paths 311/322),
while the high-elf area has Windrunner transport links. Node presence alone does
not demonstrate usable end-to-end travel. Validate both directions and retries.

Required remaining coverage includes appearances, racial/class eligibility,
starting spells/gear, racial skills, quests/trainers, talents and new/modified
class abilities. The 500-bot local test must exercise both custom races and low,
middle and high levels. Do not treat a compile or login count as gameplay parity.

### Racial travel and mounts: implemented source changes

The module now adds the two native Blackstone scripted taxi routes to the
existing graph, attaching their endpoints through native pathfinding. Boarding
uses the offered NPC gossip action through native session handlers; it does not
directly activate a taxi or fabricate completed movement. Failed boarding leaves
the minimal-movement route pending. Native faction checks remain at route
selection, and native interaction checks remain at boarding. Runtime coverage
and return journeys are still pending.

Mount item identification resolves collection_mount through sMountMgr. Goblin
factory choices are the native rocket cars (80460-80462), and high elves use the
native unicorns (80457-80459), with Player::CanUseItem and required reputation
checks before a factory grant. Existing racial choices remain for other races.
Repeated initialization retains an existing suitable color. Mount selection
prefers the new racial choices over equally fast legacy fallback mounts without
deleting an existing character's learned mounts. All races use riding skill 762.
Speed selection matches Turtle's mounted-aura scaling and custom flags instead
of treating the spell's base value as the speed at every riding tier.

The RPG destination table was empty in the local Turtle database. The additive
sql/world/turtle/ai_playerbot_rpg_races.sql migration restores applicable native
mainland innkeeper destinations, with Blackstone/Brinthilien beginner anchors and
both custom races included in mainland progression. It excludes expansion maps
and does not execute the donor SQL's unrelated gossip deletion or table drops.
Teleport cache SQL now uses native column names and native flag constants.

Talent review has confirmed changed layouts for all nine classes. The review
must use spell identity plus class rather than talent ID, because IDs were also
renumbered. Mount/travel compilation is separate from completion of that review.


## Integration findings, 2026-09-13

The active AH service is the existing Turtle CMaNGOS-policy market, copied into
`modules/ManTechPlayerbots/cmangos-ahbot`. This is the September 6-8 implementation
documented in CORE_SYSTEMS_GUIDE, including native auction publication, expiry,
refunds, paging and bounded WorkSlice scheduling. It is distinct from the older
category AHBot bundled with the ManTech bot repository. That older source remains
under `ahbot` as an excluded reference, with NativeAuctionView still used for bot
price reads. Only the selected market implementation is compiled. Runtime
ahbot.conf uses the matching AuctionHouseBot.* settings. No retired bot AI was
enabled or copied as the behavior baseline.

The first runtime pass exposed an unregistered native module entry point.
AddManTechPlayerbotsScripts now registers the ManTech world/player/server hooks;
configuration and data loading occur in the native WorldScript::OnStartup.
CommandScript supplies the existing bot/rndbot/ahbot/perfmon handlers. The legacy
World::InitPlayerbotsAtStartup member is not the active bootstrap on this host.

The first enabled pass admitted more than 100 bots, including both custom races,
then crashed while logging a random teleport. Minidump 20260913_141559 contains
the teleport format string and BotLog::outDetail/RandomPlayerbotMgr stack evidence;
the fault reads address 0x44 (the first character of the destination name). Native
AreaEntry::area_name is char*, not the Classic localized pointer array. Indexed
area-name reads throughout this module were corrected to the native pointer.
Native std::string item/spell fields in printf logging were also corrected.
Detail logs now respect the native detail level or AiPlayerbot.BotLogDebug;
errors and state/diagnostic logs remain enabled.

Talent application uses native LearnTalent/ResetTalents and native point checks.
The Turtle config contains 27 primary spec paths with 297 level checkpoints,
checked against installed Talent/TalentTab DBC rank limits, tiers, dependencies,
class masks and level point budgets. Four intermediate demonology checkpoints
are under budget; this validation does not certify build optimization. Original
Classic preset rows remain in config/classic-talents.reference.conf. The full
layout comparison is MANTECH_TURTLE_TALENT_REVIEW.md.

New racial actions handle the native high-elf resource variants and goblin escape
tradeoffs. Nineteen previously unreferenced active talent abilities now have
explicit Turtle action/strategy handling; existing renamed paladin support spells
and shaman Ancestral Swiftness share the native spell-name index with the Classic
strategy names. Shared ManTech CC/area safety and native cast checks still apply.
This is not a claim of completed class parity: the trainer scan also identified
20 new spell names without explicit strategy references, including warlock stones,
rogue poisons, druid abilities and custom utility/teleport spells. Some existing
references may be excluded by expansion guards and need active-path review.

Remaining acceptance: a sustained 500-bot runtime after the crash correction,
native mount grants/casting at both riding tiers and both new races, end-to-end
custom starting-zone exits, class strategy coverage and feature parity. Existing
market/settlement/item-ownership test executables pass; they use native production
fragments with service doubles and do not certify a live market or bot gameplay.
No commit or GitHub push has been made by this port task.


## Runtime follow-up, September 13 afternoon

The 14:31:09 dump identified SpiritHealerAction::Execute dereferencing the
unregistered `corpse run` value. The retained native resurrection actions and
explicit corpse-run command now share a registered ManualSetValue<bool>, false
initially and cleared after successful recovery. No resurrection bypass was added.
The literal value-name registration scan found no additional missing AI values.
Console `rndbot stats` now uses requester 0 and runs on the native command owner,
after map jobs join, instead of traversing live bots in a detached thread.

Build27 ran with 500 bots from 14:40 through at least 14:46 without a new dump.
At 14:46 the existing report counted 45 moving, 16 in combat, 7 on taxi and 75
mounted. This pass retained the donor's 10% background activity configuration;
it is not a 500-fully-active acceptance run. The next run uses 100% with the
same 500 online cap. Reports initially omitted custom race names and counted
high elves as Horde: IsAlliance now delegates to native Player::TeamForRace,
and the chat/report race map includes Goblin and High Elf.

The selected CMaNGOS auction service reported 162 listings, no failures and a
largest update of 654 microseconds at 14:43. Existing auctions were preserved.
Five-minute diagnostics reported world average 87ms, maximum 735ms, with no
unknown sampled actions. Slow bot maintenance still occurs in placement checks
and strategy changes; these measurements are not a completed latency acceptance.

Pet persistence remains under investigation: native pet numbers restart at 1
and skip only IDs in the character-pet cache, while the dev database contains
orphan pet_spell rows (486 rows in the 14:44 sample). New pet saves reported
duplicate pet_spell keys. Native hunter-pet replacement deletes other
character_pet rows without their child spell rows, which is a relevant producer.
Do not hide this with INSERT IGNORE or delete arbitrary pet data. No pet tables
were changed during this investigation. Native data also reports existing
missing trainer/waypoint/script bindings; these are separate from bot crashes.

Source review confirmed Healing Touch's existing action node requests caster
form, whose native removal includes tree form. This is source-path coverage;
the expanded class review and in-world healing acceptance remain outstanding.


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

Build29 runtime result (2026-09-13 14:55-14:56): 500 online, 142 goblins,
175 high elves, 122 moving, 31 in combat, 14 on taxi and 44 mounted in the
14:55:30 snapshot. Config botActiveAlone=100; dynamic activity priorities remain
on, so this does not claim all 500 execute full AI every tick. Native server exit
completed through database shutdown and process halt without another dump;
characters.online count was 0 afterward. The previous last dump remains 14:50:12.
Pet-spell duplicate keys and slower maintenance remain unresolved, as do the
previously listed class/racial-exit gameplay acceptance items. Build29 is deployed
in the user-selected dev folder and restarted with max/min500. No Git push.


### Native compatibility follow-up, September 13, 15:45

Build30 fixes native pet identity allocation: restart now chooses an ID above
all persisted pet identities, including child spell/aura/cooldown rows. It does
not erase orphan rows or mask duplicate writes. Three subsequent startups chose
increasing IDs (1327 and later 1515), with no new pet-spell duplicate in those
runs. The pre-existing orphan producer remains separate. This native persistence
change belongs with core hooks; the 24-bit pet counter is checked for exhaustion.

Random relocation now evaluates the existing activity/faction/zone predicates
lazily in weighted candidate order. It retains native teleport/height checks,
the three attempts per eligible location and the existing active-only fallback.
The 15:24 five-minute manager sample averaged 6.739ms/max59.113ms, followed by
4.076ms/max13.299ms at 15:29. No native teleport success is fabricated. A sample
is not a guaranteed bound for an expensive native operation or all-invalid input.

Build31 includes nine further trained Turtle abilities, the three warlock stones,
and native Tree of Life Form handling. Regrowth/Rejuvenation preserve tree form;
Healing Touch leaves it. High-elf priests with actual bows can receive native
ammunition. Build32 adds manual Dissolvent/Agitating poison strategies, Wolf
aspect selection using the existing close/ranged policy, and Alah'Thalas mage
teleport routing. Portal casting remains through the general learned-spell cast
command, like other capitals. Calm Elements is a requested out-of-combat utility,
like the baseline Mind Soothe action. These are source/build results, not proof
that every class ability has been exercised in combat.

The inherited compatibility shim had further real placeholders. IsAutocastable
always returned false, blocking the pet autocast command. It now follows native
passive-spell eligibility, and the command delegates to the native packet handler
which updates both the pet spell list and charm action bar. Persistent-area-aura
inspection uses actual spell effects. Fixed template ceilings also omitted 139
items >=100000, 80 creatures >=100000 and 12091 game objects >=200000 in the
installed world. The affected scans now iterate loaded native template maps;
their original eligibility filters remain. Unordered native stores can change
candidate enumeration order; no persistent snapshot or parallel store is added.
Previously persisted item caches still need explicit content-coverage review.

The native Master Strike script already dispatches its weapon-specific helper
after damage. Its unused effect-1 trigger has ID zero in the installed template.
The script now consumes only that empty placeholder; nonzero triggers and all
other effects retain normal dispatch. Human and bot casts share this correction.
Live helper/weapon variants have not all been exercised.

Runtime build32 at 15:43:56: 500 online, 499 classified active, world average66ms,
max79ms over five minutes. No new dump or pet-key duplicate in this run. Inspection
confirms a level60 high elf remains stationary and reaches travel cooldown;
a goblin selects a mainland destination. Those observations require route/movement
diagnosis and are not a successful racial-exit test. No forced relocation or
starter-zone blacklist was used to hide them. Full gameplay parity remains open.


### Native adapter completion, September 13, builds 39-48

The active source remains current Penqle with ManTech Classic baseline
c271085c92c380142a90a5514cf54a69b8f8ac37. The dedicated build selects only
ManTechPlayerbots. Sagiroth and retired Turtle modules are not the active AI.
AI/configuration, the baseline population scheduler, LLM HTTP/TLS, diagnostics,
reports, class/party commands, travel and the existing CMaNGOS-policy AH service
are integrated. The user explicitly approved reuse of Classic's LLM credential and endpoint.
Its current live settings are copied to Turtle runtime only, including the
existing chat policy and concurrency cap. No live model response is certified
by this port run; earlier disabled/empty settings are superseded.

Native navigation queries now report actual loaded MMAP/VMAP tiles, including
the native world-X/world-Y filename swap. Path area costs use real Detour areas
and flags (water=6, steep=3; magma/slime flags remain distinct). Bot avoidance
raises ground-area costs under the native exclusive navigation gate; it does
not replace water/hazard flags. Reused PathInfo objects reset filter costs.
Outdoor behavior uses Map::IsContinent, because native continents have nonzero
shard IDs. An existing stuck action can repair a stationary bot 3-10 yards below
verified native ground; native terrain, movement eligibility and a nearby walk
polygon must agree before native same-XY relocation. It is not blanket teleport
or forced route completion. The empty-route graph lock leak is fixed.

Native area-trigger access now has one shared helper for phase, corpse/parent
entrance, level, condition and raid-combat eligibility. The native handler still
owns all proximity, quest, tavern, battleground, zone/script and teleport effects.
Bot route selection calls this helper only for a current-map edge; final entry
still uses the native handler. Script-only gossip reaches native hello handling
and its conversation GUID, hooks and interaction checks.

The active factory and train command now reuse the module trainer path instead
of empty class-spell aliases. Both native per-NPC and shared-template trainer
lists are considered once per pass. Native trainer state gates level, race,
class, ranks, prerequisites and skill requirements. Progress measures successful
new spells, not spell-map size or a fixed six passes; removed entries can remain
in native spell maps after reset. Factory reset/rewarded-spell learning uses
native ResetSpells/LearnQuestRewardedSpells. Existing configured trainer catch-up
is retained for login and professions. No population reset was requested.

Melee/ranged switching restores native melee state and swing notifications.
Behind-target positioning uses actual facing arcs. Raid subgroup counts use
native SameSubGroup. Quest abandonment and profession unlearning use native
session handlers and confirm success, preserving hooks/items/timers and race
eligibility. In-game stats use native system chat. Spell failure reports include
147 native result identities instead of blank strings.

Loot selection now reads the native LootView, with actual registered looter,
group permission and per-player quest/FFA/conditional records. StoreLoot maps the
native response slot through LootItemInSlot(player), then retains the native
award handler; quest slots are no longer indexed as ordinary items. Moving away
uses native DoLootRelease. Corpse completion uses native remaining-loot counts.
Loaded loot definitions are inspected through read-only native accessors/visitor,
removing unrelated-class layout casts; cached drop-map policy remains in the
module. Source-row references retain the native loaded-store lifetime contract.

Runtime evidence preceding build48: at 16:54:25, build42 had 500 online/active,
222 moving,35 combat,26 taxi,70 mounted,25 dead,0 AFK. Quest travel was disabled
by the retained AutoDoQuests configuration; its zero quest-travel counters do not
mean zero AI updates. Hyrthalnon, previously below the walk surface, moved with
a valid approach/full route at 16:34:30; no recovery log was recorded for him, so
that improvement is not attributed to the new repair. Trikhalshur and Kharsyrtri
were observed outside the high-elf starter region in Eastern Plaguelands. A
goblin was observed on Tel Abim. Pukivyrk logged one actual GROUND_RECOVERY at
16:53:16, z29.854 ->34.433. These samples demonstrate activity and some native
exits, not every race/class, mount, dungeon, spell or return-route scenario.

The item cache already contains 1,318,106 rows/12,068 distinct items, including
125 high-ID items in 1,686 rows. It was not erased or rebuilt for this review.
Build48 runtime results must be recorded separately after deployment. Full
gameplay parity is not inferred from compilation. Core hooks and module changes
remain separately designated but uncommitted; nothing was pushed to GitHub.



Build48 compiled but did not link: allocator-tagged loot containers were exposed
in a callback signature. Build49 replaces that boundary with non-owning pointer/
count views; native container layout/allocator policy stays private. The new
symbols are present in the native library. The old layout-cast classes are gone.
No failed-build executable was deployed.

The user approved copying the current Classic Cloudflare LLM settings, including
its credential and endpoint, into Turtle runtime. The 10 LLM settings match;
mode2 is enabled, both bot-to-bot/RPG generation chances remain0, concurrency2.
Secrets are not stored in source. The 14 Classic diagnostic settings also match:
mode2/30-second interval, sampled combat diagnostics and existing bounded caps.
500 bots and levels1-60 are retained. None of the other expansion servers changed.
