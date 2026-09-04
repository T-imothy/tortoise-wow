# Turtle architecture and PlayerBot patch notes — 2026-09-03

## Scope

This pass keeps Turtle's own map partitioning, packet broadcast and custom
content architecture. It does not add a second scheduler and does not backport
Turtle code to the ManTech Classic, TBC or WotLK branches.

## Core scheduling and database work

- Bounded all active continent/partition updates behind a shared worker count
  (`MapUpdate.Continents.UpdateThreads`, default `2`).
- Disabled nested per-map motion, object, visibility and cell worker pools when
  partitioned continents are enabled, preventing a worker pool per partition.
- Made thread-pool and SQL-delay lifecycle state atomic.
- Limited each SQL delay pass to 64 normal and 64 serial operations so a
  continuously replenished bot queue cannot monopolize a database worker.
- Added priority database lanes for real-client character enumeration and
  world-entry query holders while preserving per-account serial ordering.
- Bounded async result admission to 16 callbacks per update, reduced callback
  pools from six to two workers per database, and set the world callback budget
  to 5 ms.
- Changed conservative four-vCPU defaults to two instance workers, two
  continent workers, two network workers, one object-update lane, no nested
  motion lane, and a 100 ms map interval.

## Movement and PlayerBot work

- Capped every movement broadcaster queue. Replaceable movement is coalesced;
  if a queue contains no replaceable entry, its oldest broadcast is discarded
  instead of allowing unbounded memory growth.
- Added a non-blocking single-entry guard around each bot AI update so map and
  manager paths cannot mutate the same AI concurrently during login or transfer.
- Staggered inactive, unowned bots across four update slots while retaining
  full-rate updates for combat, battleground and real-player-owned bots.
- Preserved elapsed AI time across skipped background slots and bounded the
  catch-up advance to one second.
- Added minute-based cleanup of expired, non-protected AI values.
- Reduced the default action-search iteration multiplier from 100 to 10 and
  stopped minimal ticks immediately when only low-priority actions remain.
- Added a target- and event-aware failed-action cache with exponential retry,
  a 30-second TTL, and a 64-entry limit per engine. Successful actions clear
  their prior failure state.
- Replaced straight-line portal following with synchronous navmesh paths. Bots
  reject shortcut/no-path results and only accept a path whose real endpoint is
  inside the official area-trigger volume.
- Added an exclusive 15-second portal-transition state. It cancels movement and
  spell state once, tracks forward progress, retries only after a one-second
  stall, caps retries at six, and clears on teleport acknowledgement or map
  or instance change.

## Diagnostics and configuration

Every 30 seconds, `PB_DIAG` reports online bots, failed-action cache size/peak,
expired and evicted entries, suppressed retries, portal transition requests,
discarded concurrent updates, and movement packets coalesced/dropped.

New PlayerBot settings:

- `AiPlayerbot.ValueCacheCleanupInterval = 60000`
- `AiPlayerbot.FailedActionRetryBase = 250`
- `AiPlayerbot.FailedActionRetryMax = 2000`
- `AiPlayerbot.FailedActionCacheTtl = 30000`
- `AiPlayerbot.FailedActionCacheMaxEntries = 64`
- `AiPlayerbot.IdleBotUpdateSkip = 4`
- `AiPlayerbot.IdleBotMaxTimerAdvanceMs = 1000`
- `AiPlayerbot.Diagnostics.Enabled = 1`
- `AiPlayerbot.Diagnostics.Interval = 30000`

## Validation and operational notes

- Full Release build completed for `mangosd.exe`, `realmd.exe`, all Turtle
  scripts, and the static PlayerBot module with MSVC 2026.
- No database schema or world-content rows are changed by this pass.
- Asynchronous navmesh construction/tile unloading remains disabled; the known
  unload race was not reintroduced.
- Runtime validation still requires an administrator-started realm. The agent
  must not start `realmd` or `mangosd`.
