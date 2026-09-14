# CMaNGOS playerbots sync for Turtle — 2026-09-14

Integrated the reviewed delta from ManTech merge `873ebbfeda7a7d074d29c7f3bf83c0d18192619a`, covering CMaNGOS master through `266268c6d4920487b013c31a62207ac7e7d777fe`. The remote tip was verified directly when this sync began. This is a targeted upstream update; it does not replace the Turtle module with the CMaNGOS host implementation.

- Selected, still-lootable targets now prevent RPG/travel movement from pulling the bot back and forth before loot is complete.
- Pending loot suppresses incidental RPG-target healing. Existing selected-target and party healing, pet checks, candidate deduplication, forecasts and native range/lifetime checks remain.
- Account-shortage reporting uses floating-point division before rounding up; login rate and target population are unchanged.
- Faction lookups are captured once and retain ManTech's neutral fallback when metadata is missing. The missing creature-template diagnostic guard was already present in Turtle.

The two conflicts were resolved by retaining Turtle movement and healing source and inserting only the reviewed loot guards. Turtle race/talent, battleground, native session, asynchronous ownership, loot policy and NULL-safe production event-loading changes remain.

Validation: Release build88 passed; actual faction/healing methods passed under the retained expansion defines with Turtle fixture APIs; source-derived RPG/travel loot admission passed for queued/selected/invalid/completed loot and forced/free movement; both saved-event loaders passed the SQL NULL regression. These are focused source regressions and a native Turtle build, not a new live gameplay acceptance run.

No SQL migrations or configuration changes are needed. Production is still running build87. The separate missing Thorn Gorge mount-before-travel change identified earlier is not part of these upstream commits and remains outstanding.
