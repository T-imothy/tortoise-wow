---
layout: default
title: store_racechange
---

# store_racechange

Race change requests from web backend. Playerbytes is from 

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 6 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value; identifier column |
| <a id="col-race"></a>`race` | `tinyint(1) unsigned` | NO |  |  |  | non-negative numeric value; race id or race mask; Uses Races enum values |
| <a id="col-gender"></a>`gender` | `tinyint(1) unsigned` | NO |  |  |  | non-negative numeric value; Uses Gender enum values |
| <a id="col-playerbytes1"></a>`playerbytes1` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-playerbytes2"></a>`playerbytes2` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-transaction"></a>`transaction` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `race`

non-negative numeric value; race id or race mask.

Value set: `Races` (enum) from `src/game/SharedDefines.h enum Races`.

### `gender`

non-negative numeric value.

Value set: `Gender` (enum) from `src/game/SharedDefines.h enum Gender`.

### `playerbytes1`

non-negative numeric value.

### `playerbytes2`

non-negative numeric value.

### `transaction`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `transaction` |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `Gender` | enum | [`gender`](#col-gender) | `src/game/SharedDefines.h enum Gender` | 3 |
| `Races` | enum | [`race`](#col-race) | `src/game/SharedDefines.h enum Races` | 10 |

### Possible Values

Used by: [`gender`](#col-gender)

#### `Gender`

Kind: `enum`

Source: `src/game/SharedDefines.h enum Gender`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `GENDER_MALE` | Gender Male |
| `1` | `0x1` | `GENDER_FEMALE` | Gender Female |
| `2` | `0x2` | `GENDER_NONE` | Gender None |

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
