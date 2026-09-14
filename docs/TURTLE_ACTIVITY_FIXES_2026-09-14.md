# Turtle activity and player-present fixes — September 14, 2026

Build 86 is deployed to `C:\Users\root\Desktop\WorkFolder\turtle` from
`D:\WoW Emu\ManTech\ManTech Turtle`. Runtime PID: 28072; started 2026-09-14T09:03:38.0663593-05:00.
SHA256: `F2AB45A766401AE3C80C04E8939883A89017DD97D4C9C7BD2A1F3D6AAA2EF630`. Target remains 10,000 bots, `botActiveAlone=100`,
`DisableActivityPriorities=1`. Other cores and production were not changed.

## Main finding

Our earlier idle-throttling change used the same countdown as actual AI actions.
A scheduled full update could therefore arrive while the artificial idle delay
was still running, then miss its decision. The earlier low-tick unattended
acceptance demonstrated population and latency, but did **not** establish that
all eligible bots were independently making decisions.

The source-derived regression reproduced 5,369 of 10,000 idle bots never reaching
a full decision in five simulated minutes at 100ms ticks with the live 10,000ms
passive-delay setting (5,174 with the earlier 2,000ms test setting). With the
correction, both counts were zero. This isolates a scheduling defect; it is not a simulation
of every gameplay action or class rotation.

## Changes

This follow-up includes the previously deployed fixes in
[TURTLE_FULL_ACTIVITY_FIXES_2026-09-14.md](TURTLE_FULL_ACTIVITY_FIXES_2026-09-14.md):
initialized recent-packet flags; cheap chat admission before expensive recipient
lookups; reusable link expressions; removal of a contended per-recipient locale
lookup; native channel delivery without heap-allocated player wrappers; scoped
sender classification; and the LLM no-human-audience return that prevents canned
bot-to-bot reply cascades. That document's build82 timing acceptance is historical
and must be read with the timer and player-present limitations established here.

| Change | Reason and preserved behavior |
|---|---|
| Separate idle throttle from action countdown | Full/critical turns ignore the minimal-pass throttle. Genuine spell, action and reaction waits remain intact. Reset clears the throttle; deferred work consumes elapsed time once. |
| Stop synthetic minimal-pass yields delaying full decisions | Minimal passes use their own scheduler throttle. Full calls retain the native noncombat/master yield policy. |
| Promote moving/casting bots into the existing active lane | An unfinished spline previously could fall into the hibernated lane, where the 500ms movement cap discarded elapsed travel time. Native movement limits and ownership remain intact. |
| Reject unhandled bot packets before locking | Movement broadcasts no longer lock an AI queue that has no registered handler. Registration is constructor-only and dispatch reads it as const. |
| Preserve queued packets after callback exceptions | The failing packet is consumed; untouched/retry packets survive beneath newer arrivals. Native callbacks execute outside the producer mutex. |
| Avoid empty-mail world continuations | Native MasterPlayer publishes an atomic count; the new trigger uses the existing often result without another random draw. Actual mail processing and usefulness checks remain on the native owner. |
| Release skipped soft-deleted mail allocations | LoadMails now frees the allocated row that never entered its owning list. This does not establish that all long-run memory growth was a leak. |
| Restore Twinkie Boomstick's missing trainer data | NPC80856 had zero offers; 125 exact rows were restored from this checkout's SQL baseline. All learning wrappers/taught spells exist in current data. No existing offer was overwritten; a restart rebuilt native caches. |
| Reject ineligible travel work before world handoff | Choose requires a prepared search; derived refresh/group/reset actions keep their own rules. Existing owner-local active/no-destination flags reject requests before group/world checks. Asynchronous future readiness never grants map-thread execution. Queue bounds, drain budget, searches and viable action ownership remain unchanged. |
| Preserve bounded world-action service as ticks lengthen | Build86 changes the per-pass time allowance from fixed8ms to clamp(tick/4,8,32)ms. The nominal allowance remains8ms; queue size1024, callbacks256 and native lifetime/ownership guards remain. No time credit accumulates. A single long callback may exceed this soft budget and is reported. |

Build84 reached 10,000 bots but still saturated its world-action queue: the08:39:42
sample had931 pending actions and452,233 cumulative rejected admissions at133ms
mean ticks. Selected travel outcomes included5,340 attempts without a prepared
search versus561 selections. Build85 corrects that unnecessary admission; the
final measurements below determine its effectiveness, not population alone.

Build85 subsequently reached7,829 bots with940 pending/1,053 rejected actions at
153ms mean ticks. The remaining queue was led by cheap mail checks while sampled
spirit/corpse navigation consumed more execution time. The fixed8ms-per-tick
allowance shrank the queue's service per second as ticks grew longer. Build86
corrects this service policy; pending action count alone was not used as a cost
estimate. Actual final-run tick and queue measurements remain the acceptance test.

## Diagnostics

`PlayerbotCombatTotals.log` keeps fixed class/stage/result counts independently of
the capped detail table. Counts describe selected samples, not extrapolated totals.
String spell checks include the requested name. Travel outcomes distinguish no
search in progress, invalid/pending/failed search, no destination and selection.

`PB_BOT_PROGRESS` records a bounded deterministic cohort every population scan:
position, XP, physical state, already-created travel/RPG values and separate action
and minimal countdowns. Repeated equal endpoints do not prove continuous idleness;
map/generation changes break comparisons. All probes retain existing diagnostic
switches; details and totals have separate bounded two-file histories.

The manager line additionally reports world_budget_ms, world_last_drained and
world_last_drain_us. These are the last completed pass, not window percentiles.

## Verification recorded so far

- Full native build succeeded; binary hash verified during deployment.
- Focused packet/mail/activity/outcome tests passed, including concurrent packet
  producers, reentrancy/exception ordering, a held queue lock with 100,000 rejected
  opcodes, native atomic-mail publication, and requested-spell thread isolation.
- Corrected scheduling regression passed: timer fairness, real five-second action
  delay, transfer/unlink, combat promotion and deferred elapsed accounting.
- Travel admission regression passed224 status/flag combinations; existing native
  world-queue regressions passed concurrent bounds, actor/event/generation
  cancellation, stop guards and engine continuation lifetimes.
- Actual queue with a deterministic clock passed8/32ms service slices, the
  256-callback bound, overflow clamping, no accumulated time credit, and reporting
  of a single callback exceeding the soft time budget.
- Final-run unattended 10,000-bot samples: 7; average tick range: 167–189 ms.
  These samples span 671 seconds across the baseline and recovery
  intervals, separated by the player-present tests; this is not one uninterrupted
  unattended interval. First full population observed after 23.3 minutes from process start.
  Pending world actions: 0–17; cumulative
  rejected admissions: 0–0.
- Final-run Southshore player-present average tick range: 188–220 ms.
  Test completed/restored: True/True.
  Login: 0.282 seconds; pending world actions:
  0–84; cumulative rejected
  admissions: 0–0.
- Native player-policy checks for this exact process: `{"cross_map_summon_arrived": true, "group_retained_after_loot_changes": true, "native_invite": true, "native_logout": true, "native_master_loot_ffa_and_restore": true, "whisper_summon_arrived": true}`.
  Invite: 0.719 seconds; cross-map outdoor summon:
  0.812 seconds; fixture restored:
  True.
- Cohort in retained final-run history: 39 bots;
  36 changed position;
  9 gained observed XP or levels.
  This retained cohort includes the controlled player-present interval. It is not
  a random population sample and bots have differing exposure times. Earlier in
  this same run, before either test connected, the retained cohort showed27/34
  bots changing position and10 gaining XP/levels, establishing unattended progress.
- Final-run error summary: `{"empty_vendor_item_list": 151, "missing_waypoint_path": 6, "other_error_lines": 594}`.
  New crash dumps: 0.

The earlier build83 Southshore hold reached 10,000 bots with sampled mean ticks
98–184ms and no world rejections, but it preceded the timer correction. Do not use
that run as proof of final independent activity. Native invite/summon/loot checks
are reported separately in the final receipt; earlier receipts remain historical.

## Remaining limits

Recurring empty-vendor warnings include Splinter60556, Dock Logger60576 and
Tarlo Farcrack91292 (their current vendor_id values are0). Direct vendor rows for
Dock Logger/Tarlo were not found in the checked baseline. This is not proof that
their flags should be removed: custom gossip/vendor semantics require review.
No stock was invented and these warnings were not suppressed.

Missing waypoint, script-target and other content warnings remain distinct from
the corrected scheduler faults. Fahrad and Splinter do not have corresponding
offers in the inspected source baseline, so no invented stock or training data
was inserted. Unknown talent-dependent spell probes and ordinary pending actions
are not automatically combat bugs. The memory ledger is partial; the mail fix does
not account for every byte of long-run growth. This work does not certify every
class rotation, encounter or every possible 10,000-bot workload.
