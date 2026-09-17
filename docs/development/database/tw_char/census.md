---
layout: default
title: census
---

# census

Character database table `census`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 3 | latin1 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-time"></a>`time` | `datetime` | YES |  | `NULL` |  | time/delay value; confirm unit in server usage |
| <a id="col-race"></a>`race` | `int(11)` | YES |  | `NULL` |  | numeric value; race id or race mask; Uses Races enum values |
| <a id="col-onlinecount"></a>`onlineCount` | `int(11)` | YES |  | `NULL` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `time`

time/delay value; confirm unit in server usage.

### `race`

numeric value; race id or race mask.

Value set: `Races` (enum) from `src/game/SharedDefines.h enum Races`.

### `onlineCount`

numeric value.

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `Races` | enum | [`race`](#col-race) | `src/game/SharedDefines.h enum Races` | 10 |

### Possible Values

Used by: [`race`](#col-race)

#### `Races`

Kind: `enum`

Source: `src/game/SharedDefines.h enum Races`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `RACE_HUMAN` | Human |
| `2` | `0x2` | `RACE_ORC` | Orc |
| `3` | `0x3` | `RACE_DWARF` | Dwarf |
| `4` | `0x4` | `RACE_NIGHTELF` | Night elf |
| `5` | `0x5` | `RACE_UNDEAD_PLAYER` | Undead player |
| `6` | `0x6` | `RACE_TAUREN` | Tauren |
| `7` | `0x7` | `RACE_GNOME` | Gnome |
| `8` | `0x8` | `RACE_TROLL` | Troll |
| `9` | `0x9` | `RACE_GOBLIN` | Goblin |
| `10` | `0xA` | `RACE_HIGH_ELF` | High elf |
