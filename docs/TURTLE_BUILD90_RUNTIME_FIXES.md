# Turtle build90: confirmed runtime fixes

September 15, 2026. Development changes following production build89 review.
Production remains on build89; no production binary, database or website was
changed by this implementation pass.

## Changes and reasons

| Issue | Implemented change | Evidence and limits |
|---|---|---|
| T89-02: 5,993/6,000 bots and seven pending reservations | Reject invalid names before adding bots to the login pool; clear the pending reservation when the native query holder completes, including rejected admissions. | All 20 offline characters in the 6,013-member production pool match native reserved/profane DBC patterns and have the rename flag. Production has 9,000 existing bot characters, so replacement candidates exist. Characters are neither deleted nor renamed; native validation remains authoritative. Production completion awaits deployment. |
| T89-02: future name generation | Both name-selection entry points consume invalid names and continue to another candidate. An exhausted pool returns failure without reacquiring its already-held mutex. | Prevents creating more characters with names the core will reject, and removes the exhausted-pool recursive-lock path. No account regeneration is required. |
| T89-05: Eastern Plaguelands graveyard | Native Crown Guard reference changes from absent WorldSafeLocs 927 to Turtle's Crown Guard entry 128. | Turtle DBC coordinates match the tower. Existing native link/unlink and faction rules are retained. Native transition tests cover neutralization, both factions, recapture and repeated requests. This is not a complete in-game PvP campaign test. |
| T89-05: invalid subzone links | Manual SQL removes exactly two redundant links only when their existing parent-zone link already covers the faction. | Rows 136/5180/0 and 137/2041/67 are skipped by the native loader; parents 5179 and 406 already cover them. Applied twice in dev to verify idempotence; not applied to production. |
| T89-06: empty merchants | Bot vendor travel and selling require native direct or template stock. Vendor item lookup also checks for a missing item prototype. | Repeated production warnings concern entries 60556, 60576, 91292 and 80227 without offers. Quest and generic gossip purposes remain available; NPC flags and inventories are not invented or removed. Generic gossip can still expose the underlying data warning. |
| T89-09: Sagiroth world-tick optimization | Construct performance-monitor labels in UpdateAI, UpdateAIReaction and UpdateAIInternal only when monitoring is enabled. | Production monitoring is disabled. Enabled monitor lifetime and independent diagnostics are unchanged. No measured percentage speedup is claimed. |
| T89-01/T89-08: activity interpretation | PB_DIAG_STATE now includes background_config_pct and activity_priorities_disabled. | Distinguishes configured background eligibility from the load controller and actual combat. No scheduling or activity policy was changed. |
| T89-07/T89-08: public analytics | Prepared decimal-string counters, monitoring-state labels, partial-storage coverage labels and a bounded aggregate runtime-log reader. | PHP syntax and 16 boundary checks pass. Files are staged separately; public deployment awaits explicit approval. See the deployment note below. |

Sagiroth references: https://github.com/Sagiroth/TortoiseBots/issues/175 and
https://github.com/Sagiroth/TortoiseBots/pull/177. Our shared friend snapshot
already addresses the friendship scan. Their native-player registry mechanism
is absent here. Experimental spatial scan reductions were not copied: they
would alter gameplay and have no demonstrated compatibility benefit in this port.

## Validation and deployment

- Release/LTO world build succeeded. Dev binary SHA256:
  `67B99D4CFBCAAA71D02D11C030571ECC0891E36C1B5CB9E8529B684169523F17`.
- Dev world PID 39460 started at 09:28:31 workstation time; realm PID 25508.
  Runtime remains at 10,000 target, 100% background and priorities disabled.
  Production remains at 6,000 target, 10% background and priorities enabled.
- Native wire-level checks passed: invite (0.782 s), outdoor cross-map summon
  (0.609 s), whisper summon, master/FFA/group loot and group retention, say/yell/
  party/channel delivery, addon payload handling, trade open/cancel and logout.
  The owned test character's original position was restored.
- Focused source-body regressions passed for native name rules, rejected query
  completion, repeated completion, name pool exhaustion, native vendor lists and
  graveyard transitions. They do not simulate every asynchronous admission path.
- 129 compiled architecture tests passed across the suite and the corrected
  ContentHookContract rerun. Five additional fixtures for the disabled
  TortoiseBots module fail to compile against that module's existing changes:
  ModulePopulationMaintenance, ModuleRandomAdminCommand, ModuleBotInitialization,
  ModuleTeleportPicker and ModuleNativeRemoval. The full suite is therefore not
  claimed green. Small native fixtures were updated for existing path/lifetime
  dependencies; no pathfinding runtime behavior changed in this pass.
- Source-only contract indexes refreshed; no credentials or runtime configuration
  are part of the source changes.

## Findings still requiring evidence

At 09:41 workstation time, build89 production had 5,993 bots, seven pending,
controller 100, and 1,497–1,689 full-AI-eligible bots over the last 20 windows.
Average world ticks were 159–171 ms (mean 163.8 ms), with no queued/rejected world
actions and no pending DB work in the latest window. No newer crash dump appeared.
This does not reproduce the previous run's controller collapse or establish a
new long-run latency regression.

Private memory increased from 12,920 to 13,042 MiB over those windows. Memory
growth is real; its cause is not established. The partial ledger cannot identify
all retained allocations. Inspection confirmed PathInfo charges include the
object size, so the briefly suspected zero-byte double-registration does not
apply; no memory-accounting patch was made on that basis.

Startup pet-spell, equipment, trainer and waypoint warnings remain content
audit items. Missing authoritative data must be reconciled with Turtle content;
creating arbitrary replacement rows or muting warnings is not a fix. The shared
DB buffer pool is small, but no sustained production backlog was demonstrated,
so no server-wide memory or cache setting was changed.

The public website's SQL storage view only exposes selected tables. The staged
change labels this coverage honestly; it does not broaden database privileges.
Runtime collection is aggregate-only, reads at most 256 KiB, rejects incomplete
or mismatched session windows, reports stale/unreadable data, and adds no per-bot
names, raw log lines or credentials to the response. Production web-host execution
and rendering remain unverified until deployment is authorized.

## Porting guidance for the ManTech CMaNGOS task

Compare these fixes with the current Classic/TBC/WotLK source before applying:
gate disabled performance-monitor string work; release completed failed login
reservations using that core's native lifecycle; validate generated/selected bot
names with its own rules; avoid recursive name-pool locking; and use native vendor
stock for vendor targets. Preserve ownership, enabled diagnostics, other gossip
purposes and character data. The graveyard IDs and SQL are Turtle-specific and
must not be copied. Neither a world-tick speedup nor a memory-leak fix has been
established by this change set.


## Final full-load dev receipt

At09:51:15 workstation time on September15, dev reached10,000/10,000 bots with
10,000 full-AI eligible, background100 and priorities disabled. Pending logins0;
world pending0/rejected0. The09:51:15 and09:51:46 windows averaged172 and178ms,
with maxima216 and254ms. Private memory16,329–16,373MiB. The population reached
its target22m44s after process start; this is a short full-load check, not a
multi-hour soak or proof that every bot is fighting.

Current-session bounded errors through09:51:56: SQLerrors0, duplicate keys0,
assertions0, deadlocks0, graveyard warnings0, new crash dumps0. Content warnings
remain:83equipment,68trainer,101pet-spell,16waypoint and47empty-vendor messages
(entries91292 and1650). Generic gossip remains capable of reporting bad content
flags; the vendor-selection fix does not claim to eliminate these warnings.

Local commits: module1da05e2b, native graveyardc971875c, integrationfd2b52f2.
GitHub push was rejected by automatic approval review because authorization for
both exact repository destinations was not established. A user approval question
is pending; no push occurred. Public website deployment was separately rejected
pending authorization for the public aggregate telemetry destination; no website
files changed. The code and analytics artifacts remain saved locally.
