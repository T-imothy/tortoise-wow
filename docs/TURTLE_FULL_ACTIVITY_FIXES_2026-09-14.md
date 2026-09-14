# Turtle full-activity login fixes

Date: September 14, 2026. Scope: the login-stall investigation and fixes in builds 77–82, following the Arch4 integration. This report does not certify every feature in the larger Turtle port.

**Status: this login-stall fix pass is complete.** Build 82 passed the bounded unattended 10,000-bot/full-activity run and the native player-policy checks described below. This is not a declaration that every feature in the larger port has exhaustive gameplay coverage.

## Required outcome and environment

The target is **10,000 online bots with independent activity enabled for all bots**. The 20% experiment was a diagnostic control, not the accepted operating configuration.

- Source: `D:\WoW Emu\ManTech\ManTech Turtle`
- Runtime: `C:\Users\root\Desktop\WorkFolder\turtle`
- Active module: `modules/ManTechPlayerbots`, on the Penqle-based Turtle core.
- World port: 8088. Login port: 3726.
- Deployed build: 82, SHA256 `9A4C61A8443E557E334D17A03A9BA59981F4D552581744082CA830050296530D`.
- Runtime settings: `MinRandomBots = 10000`, `MaxRandomBots = 10000`, `botActiveAlone = 100`, `DisableActivityPriorities = 1`.

`DisableActivityPriorities = 1` bypasses the activity-priority scaling and the ordinary background percentage. The diagnostics controller percentage can therefore be below 100 while `bots_active` equals every online bot. That active counter means eligibility, not that every bot must be moving or attacking at every instant.

Production servers and the other CMaNGOS development servers were not changed or stopped by this work. No GitHub push was performed by this investigation. Runtime credentials are intentionally omitted.

## What caused the apparent login stall

Login admission pauses when the average world tick reaches 250 ms. Between 120 and 250 ms it reduces admission. These checks are reevaluated; there is no permanent latch. When the existing population keeps the tick above 250 ms, no new login work is submitted even though account capacity and database availability remain.

There are separate database guards: pending database work is bounded, and the bot manager pauses new admissions when its asynchronous database-delay measurement reaches 10 seconds. These can cause temporary pauses during a ramp without a world-tick stall.

The full-activity profiles identified work in the existing population—especially bot chat broadcasts and recipient processing—as a substantial contributor. The changes below reduce that work. The 250/120 ms admission thresholds were not raised, ordinary chat was not globally muted, and the final activity setting was not reduced.

## Fixes made and why

### 1. Restore the intended background AI scheduling contract

Files: `src/game/Maps/BackgroundAIScheduling.h`, `src/game/Maps/Map.cpp`, `modules/ManTechPlayerbots/playerbot/PlayerbotScripts.cpp`, and the native config template.

The Turtle integration gained an opt-in CMaNGOS-style cadence for independent background AI. It spreads full turns by GUID and uses minimal processing between full turns. Deferred timers retain elapsed time; minimal turns retain the configured passive/react delay floor and GUID jitter. Combat and player-interactive bots are promoted through the existing native checks, including a recheck when queued work executes.

Native map ownership, mandatory worker joins, account/entity lifetime checks, map generation checks, and teleport/logout cancellation remain. No arbitrary entity mutation was moved to an unowned thread. The local runtime enables `MapUpdate.BackgroundAI.CmangosScheduling = 1`; the generic core default remains off for other modules.

This was informed by the actual Classic/TBC/WotLK implementations. Their timer-advancement contract differs in one place, so the CMaNGOS third `UpdateAI` argument was not copied blindly.

Validation: source-extracted native dispatch/hook tests covered 10,000-GUID cadence distribution, timer accounting, minimal delays, promotion, and stale/transferred/unlinked entities. This is scheduling coverage, not certification of every combat routine.

### 2. Initialize native session packet-activity flags

File: `src/game/WorldSession.cpp`.

`_receivedPacketType` was not initialized in the session constructor. Arbitrary initial bytes could classify headless bots as recently handling spell packets, sending excessive numbers through the foreground path. The constructor now clears every entry. Native packet dispatch still sets and clears those flags normally.

Validation: the regression constructs the actual initialization fragment over dirty storage and checks every flag. Runtime population classification changed from widespread false foreground classification to counts consistent with observed combat/activity.

### 3. Avoid expensive recipient work before chat selection

Files: `modules/ManTechPlayerbots/playerbot/PlayerbotAI.cpp` and `ChatHelper.cpp`.

For ordinary bot-to-bot messages, most recipients fail the existing random response gates. Previously each recipient could still perform strategy lookup, locked cooldown-value lookup, sender-name resolution, and link parsing before rejection.

The existing response selection now precedes those expensive lookups where policy allows. Human LLM messages retain their existing cooldown exception. Recording, mentions, master/BG/guild rules, addon/debug filtering, and special-link behavior remain. Item and quest extraction skip messages without their link token and share immutable compiled regular expressions.

The response probabilities are preserved. The order of random draws for already-discarded or cooldown-blocked messages may differ; this is not a promise of identical RNG sequences.

Validation: policy comparisons cover ordinary messages, mentions, LLM modes, cooldowns, BG/master/guild cases, addons/debug prefixes, and special links. Link tests cover empty/plain/duplicate/malformed/overflow cases and concurrent readers. The final expanded policy test has 46,080 combinations, including free-alt senders controlled by real players.

### 4. Remove repeated MSVC locale-lock acquisition

Files: `modules/ManTechPlayerbots/playerbot/ChatPrefix.h` and `PlayerbotAI.cpp`.

At the build 79 full-activity plateau, stack samples repeatedly showed worker threads in MSVC locale locking through Boost's case-insensitive prefix comparison. This work occurred inside recipient processing during broadcasts.

The replacement pins the current C++ locale and its character facet once per thread and uses the facet directly. A link-token guard also avoids that predicate for ordinary messages. No runtime global C++ locale mutation was found in the active source; a future feature that changes the global locale must revisit this contract.

Validation: all 65,536 byte pairs were compared against the actual Boost predicate, plus empty/short/prefix cases and eight concurrent readers. The bounded local 80,000-call test measured 75 ms for the old path and under 1 ms for the cached-facet path; that is a microbenchmark, not a whole-server speedup claim. A subsequent build 80 live stack sample contained no `_Lockit` or `use_facet` frames.

### 5. Remove channel delivery's temporary heap wrappers

File: `src/game/Chat/Channel.cpp`, `Channel::SendToAll`.

Turtle allocated a `PlayerWrapper` and shared-pointer control block for each broadcast recipient. That shared pointer owned only the forwarding wrapper, not the native Player/MasterPlayer. The wrapper added allocation and virtual dispatch without extending the recipient's lifetime.

Delivery now performs the same native lookup immediately before each send, using the existing node/master choice. It preserves recipient order, ignore checks, missing-recipient handling, and `WorldSession::SendPacket`, including module hooks. It does not cache players or change threading.

Validation: 32 source-extracted old/new delivery cases cover both native variants, ignored senders, empty sender GUID, stale/departing recipients, and repeated packets. Both 10,000-recipient variants deliver the same results with zero temporary wrappers.

### 6. Reuse the sender classification during synchronous bot broadcasts

Files: `modules/ManTechPlayerbots/playerbot/ChatBroadcastSender.h` and `PlayerbotAI.cpp`.

The build 80 profile still showed repeated global player and account-membership locking for the same sender, once per recipient. The module already has that live sender when it initiates a synchronous channel broadcast.

Seven channel-send sites now establish a short-lived sender scope. It computes the same random-account/free-alt/real-player classification once and reuses the scalar result for matching recipient packets. Unknown senders and calls outside that scope retain the full native lookup path.

The scope retains no Player pointer, survives no queue or tick, is isolated per thread, and restores its caller after nested sends or exception unwinding. Native asynchronous/human channel messages retain their existing path.

Validation: nested scopes, mismatches, false classifications, unwinding, and eight independent threads passed. The 46,080 policy comparisons cover both fallback and scoped paths. A 10,000-recipient rejection fixture confirms scoped delivery performs zero sender account lookups.

### 7. Stop no-audience LLM dispatch from producing canned reply chains

File: `modules/ManTechPlayerbots/playerbot/strategy/actions/SayAction.cpp`, `ChatReplyAction::ChatReplyDo`.

An eligible LLM-managed channel without a real player audience set its sender pointer to null. That skipped the LLM policy's final return and fell through to `SendGeneralResponse`. A bot message that stayed within LLM policy while a human was present could therefore generate a canned reply after the human left. Those replies were themselves broadcast to bots and could trigger further replies. This bypassed the intent of a zero LLM bot-to-bot chance through a separate canned-response path.

The no-audience branch now returns explicitly. **This is a deliberate correction to chat behavior**, unlike the allocation and lookup optimizations above. Early LFG/WTB/special-link handlers remain before the guard. Non-LLM, blocked-LLM, and undefined-channel paths retain their existing dispatch. Direct messages and channels with a human audience retain their sender/LLM policy. No activity percentages, login admission thresholds, model endpoint, or API permissions were changed.

Validation: the regression extracts the actual LLM eligibility expression and old/new audience branch, asserts the special-handler and terminal-return wiring, and checks 2,304 dispatch combinations. It reproduces and stops 24 erroneous canned-fallback cases; other dispatch outcomes match. Prompt construction and network/model calls are mocked: this test checks dispatch, not model response quality. The inspected CMaNGOS shared module has the same old branch.

## Runtime evidence

These are observations from separate runs, not controlled benchmark ratios.

| Run | Activity configuration | Observed outcome |
|---|---|---|
| Build 79 | Forced full activity | Sustained plateau around 5,440 bots; average tick about 301 ms; no pending login/DB work at the plateau. |
| Build 79 control | Priorities enabled, background 20% | Last recorded sample: 9,996 online, four pending, 174 ms. Stopped for the next build before a 10,000 sample. This reduced workload; it did not meet the goal. |
| Build 80 | Forced full activity | Reached 10,000 online and 10,000 eligible. Observed 112 ms, then 98 ms and 95 ms at full population before deployment of build 81. |
| Build 81 | Forced full activity, no humans | Plateau at 7,354 bots; average tick grew from 317 to 491 ms. No pending logins/world actions; DB delay 770 ms at the last sample. This failed unattended acceptance. |
| Build 82 | Forced full activity, no humans | Reached and held 10,000 online/eligible through the bounded unattended interval; average ticks 83–104 ms. Native player-policy fixture then passed. |

Two real clients joined during the build 80 ramp; one remained in its last sample. The user reported that playing and combat on Stickme felt fine. This is useful live evidence, but it is not a substitute for the final unattended full-population test.

At full population build 80 briefly accumulated 983 world actions and recorded admission refusals. The backlog subsequently drained to zero; the rejected total stopped increasing at 3,127 in the final observations. Engine continuations retain their pending decision and retry when admission is refused. This does not establish that every possible direct action path has identical retry behavior. The final test checks for recurring saturation rather than removing the queue bound.

## Validation and remaining limits

- Release/diagnostic builds 81 and 82 succeeded. The first build 81 attempt exposed a missing include; it was corrected before deployment. Build 82 adds the audience-dispatch correction and its passing regression.
- Existing native player-policy testing before build 81 covered invite acceptance, cross-map outdoor summons, whisper summons, and master/FFA/group loot without disabling bots. Final live checks are recorded below.
- Bounded stack samplers exit after their capture; no continuous stack capture was left running. Source contract indexes were regenerated without a database refresh.
- Bulk shutdown produced character-transaction deadlock/retry logs and then completed cleanly. This investigation has not established that shutdown transaction contention is eliminated.
- Existing content/path/trainer errors are not certified fixed by these performance changes. Neither this report nor the online/eligible count certifies every Turtle spell, talent, race, quest, mount, or combat behavior.
- There is no claim of indefinite stability, exact equivalence between the two cores, or a universal hardware limit based on one bounded run.

## CMaNGOS applicability

The shared module's chat changes are concrete candidates, particularly the no-audience canned-reply fallthrough. The inspected CMaNGOS Arch4 source still compiled item/quest regular expressions per call and retained the earlier per-recipient strategy/prefix/sender-lookup path. The handoff prompt accompanies this report.

The native channel wrapper removal is Turtle-specific: the inspected Classic channel delivery already uses native Player pointers directly. Background cadence largely came from CMaNGOS and should not be ported back as a new feature. The session-flag initialization applies only if the receiving core has the same field and omission. Windows locale contention must be measured separately from Linux behavior.

## Final build 82 acceptance

The final build is **82**, SHA256 `9A4C61A8443E557E334D17A03A9BA59981F4D552581744082CA830050296530D`. The built and deployed executable hashes match. Turtle world PID 29096 started at 2026-09-14T03:14:21.2474917-05:00; the realm service remained running on port 3726, with world port 8088.

**The unattended acceptance interval passed:** 10,000 online and 10,000 activity-eligible bots, zero real players, from 2026-09-14 03:30:35 through 2026-09-14 03:35:37 local time (302 seconds between diagnostic timestamps). Sampled average world ticks were **83–104 ms**. The largest reported interval maximum in those samples was 176 ms; average latency does not rule out individual spikes.

During that interval the maximum sampled world-action backlog was 21, with cumulative world-action rejections ending at 0. Database-delay samples were 73–122 ms. Private memory at the final unattended sample was 14352.81 MiB. These are bounded live observations, not an indefinite stability claim or an allocation-complete memory ledger.

The native player fixture then passed world entry, bot invite acceptance (0.625 seconds), cross-map outdoor summon (0.609 seconds), whisper summon, master-loot/FFA/group-loot packets, and logout. The fixture bot was removed and its saved position restored. This tests these native workflows; it is not exhaustive combat or content coverage.

After the fixture logged out, the final sample at 2026-09-14 03:37:39 again showed **10,000 online / 10,000 eligible / zero real players**, 101 ms average tick, 0 pending world actions, and 72 ms database delay. Turtle is left running with the requested full activity settings.

The bounded error-log review found no new crash dump, SQL-error entry, or fatal/assertion/exception match for this run. Startup/content warnings remain, including missing trainer spell lists and missing waypoint paths; they were not hidden or declared fixed. The categorized receipt is `turtle-build82-error-summary.json`.

Evidence retained in the task workspace: `turtle-build82-full-activity-start.json`, `turtle-build82-load-observation.log`, `turtle-full-load-observation.json`, `background-ai-final-samples.jsonl`, `turtle-player-policy-live-result.json`, `turtle-build82-player-policy.log`, and the focused test/build logs cited by filename above. Paths are under `C:\Users\root\Documents\Codex\2026-09-12\can-y\work`.


## Related engineering receipts

The earlier Arch4 instrumentation/ownership work is documented separately in `docs/ARCH4_TURTLE_PORT.md`. The broader module import and native contracts are in `docs/MANTECH_PLAYERBOTS_INTEGRATION_AUDIT_2026-09-13.md`. Their historical load-test status is superseded by this report's measured build 82 result; their untested content/feature coverage limits are not erased by a scale test.

Focused regressions used here: `run_background_ai_test.py`, `run_chat_admission_test.py`, `run_chat_link_test.py`, `run_channel_fanout_test.py`, `run_chat_audience_test.py`, `ChatPrefixTest.cpp`, and `ChatBroadcastSenderTest.cpp`, all under `tests/architecture`. Python runners accept `--output` for generated native fixtures and require the local MSVC compiler environment. No model/network calls are made by the audience dispatch test. Whole architecture-suite coverage is not claimed; the pre-existing BotMoveDispatch extraction failure was outside this pass.
