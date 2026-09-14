---
layout: default
title: game_event_mail
---

# game_event_mail

Game event system

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 5 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-event"></a>`event` | `smallint(6)` | NO | `PRI` | `0` |  | Negatives value to send at event stop, positive value for send at event start.; numeric value |
| <a id="col-racemask"></a>`raceMask` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; race id or race mask; Uses RaceMask mask values |
| <a id="col-quest"></a>`quest` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-mailtemplateid"></a>`mailTemplateId` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-senderentry"></a>`senderEntry` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `event`

numeric value.

### `raceMask`

non-negative numeric value; mask/flags column; combine values with bitwise OR; race id or race mask.

Value set: `RaceMask` (mask) from `src/game/SharedDefines.h race mask constants`.

### `quest`

non-negative numeric value.

References: [`quest_template`](quest_template.md).`entry`.

### `mailTemplateId`

non-negative numeric value.

### `senderEntry`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `event`, `raceMask`, `quest` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `quest` | [`quest_template`](quest_template.md).`entry` | heuristic | inferred from column name |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `RaceMask` | mask | [`raceMask`](#col-racemask) | `src/game/SharedDefines.h race mask constants` | 10 |

### Possible Values

Used by: [`raceMask`](#col-racemask)

#### `RaceMask`

Kind: `mask`

Source: `src/game/SharedDefines.h race mask constants`

Race masks use 1 &lt;&lt; (race id - 1). Combine allowed races with bitwise OR.

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `RACEMASK_HUMAN` | Human |
| `2` | `0x2` | `RACEMASK_ORC` | Orc |
| `4` | `0x4` | `RACEMASK_DWARF` | Dwarf |
| `8` | `0x8` | `RACEMASK_NIGHTELF` | Night elf |
| `16` | `0x10` | `RACEMASK_UNDEAD_PLAYER` | Undead player |
| `32` | `0x20` | `RACEMASK_TAUREN` | Tauren |
| `64` | `0x40` | `RACEMASK_GNOME` | Gnome |
| `128` | `0x80` | `RACEMASK_TROLL` | Troll |
| `256` | `0x100` | `RACEMASK_GOBLIN` | Goblin |
| `512` | `0x200` | `RACEMASK_HIGH_ELF` | High elf |
