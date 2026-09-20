# Turtle runtime-log review, September 19

Sources: production `server_2026-09-19_16-58-49.log` and the longer previous
`server_2026-09-18_11-11-54.log`, plus errors, bot diagnostics and incidents.
The current run was still loading its population during inspection. Counts are
observed log rows, not unique bots, and snapshots were taken while files grew.

## Local corrections, not yet built or deployed

- Previous run: 1,506 negative-honor messages actually reported zero. Integer
  rounding of small damage shares legitimately produces zero. Both solo and
  group branches now log only truly negative results. Positive payouts and
  existing rounding remain unchanged. Empty eligible groups skip division.
- Previous run: 44 unhandled-object messages included mailbox type 19, entry
  175668. Bot `UseAction::UseGameObject` could send the generic use opcode for a
  mailbox, which Turtle's GameObject::Use does not handle. It now queues the
  native mail-list opcode with the same GUID. Existing prechecks remain, and
  `WorldSession::HandleGetMailList` independently checks mailbox interaction.
  The error log lacks actor attribution, so not every observed row is proven
  to originate from this bot path. Non-mailbox use is unchanged.

Validation: `tests/architecture/RuntimeLogRegression.py` compiles extracted
production fragments with MSVC fixtures and verifies zero/positive/negative
awards, empty/ineligible groups, mailbox dispatch and ordinary GO dispatch.
No full server build, live mail test, DB write, deploy, restart or publish.

## Remaining actionable findings

| Observed family | Count/scope | Follow-up required |
| --- | --- | --- |
| Duplicate `character_inventory.PRIMARY` insert | 1 at 2026-09-19 02:09:31, key `2000633849` | Trace save ownership/order and the affected inventory row; do not use INSERT IGNORE or delete characters to hide it. |
| Bad script-condition parameters with null target | 214 prior-run rows | Compare each condition's source/target contract with the invoking DB script; absence of a target can indicate incorrect script data. |
| Script target not found | 180 prior-run rows | Check target selectors, spawn identity, map/instance and whether the target should exist at execution. |
| Empty vendor item lists | 275 prior-run rows | Verify vendor template inheritance and content intent before editing flags or items. |
| Empty trainer spell lists | 11 prior-run rows | Verify template inheritance and Turtle trainer rules; do not grant fabricated spells. |
| Temporary summon failed | 26 prior-run rows | Check creature template, position and summon lifecycle for the listed scripts. |
| Missing pet spell lists | 101 current startup rows | Compare current world data and core spell-list schema before changing pet ability data. |
| Missing NPC equipment templates | 83 current startup rows | Match intended equipment data; this can affect visible NPC equipment. |
| Trainer data for creatures without trainer flag | 66 current startup rows | Check content intent; these rows are ignored by the loader. |
| Missing waypoint paths | 6 current runtime rows | GUIDs 60006, 2572945, 2442, 10740, 9082, 9090 need path-source/binding review. |
| Missing triggered spell | Aura 41111, effect 0, trigger 0 | Check Turtle spell definitions and special-case proc handling; not evidence that every combat routine is broken. |

## Messages that are not sufficient evidence of broken AI

`PB_DIAG_FAILURE outcome=impossible` means an attempted action was ineligible at
that moment. Cooldown, range, resources and target state need checking before
calling it a broken spell. Repeated `add gathering loot` failures can mean no
eligible nearby resource (skill, LOS, lootability and range are checked).
`SLOW_BOT_ACTION` is timing evidence, not an exception. Login backpressure during
population loading is intentional; progress must be checked before calling it
a stall. Incident rows marked resolved do not describe a currently stuck bot.

These categories remain visible. No broad log suppression or speculative world
database repair was applied. This review does not certify the unresolved cases.
