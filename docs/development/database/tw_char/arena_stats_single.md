---
layout: default
title: arena_stats_single
---

# arena_stats_single

Character database table `arena_stats_single`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 10 | utf8mb3 | default |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | non-negative numeric value; identifier column |
| <a id="col-arena-id"></a>`arena_id` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-team-id"></a>`team_id` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Team enum values |
| <a id="col-level"></a>`level` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-item-level"></a>`item_level` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-class"></a>`class` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; class id or class mask; Uses Classes enum values |
| <a id="col-race"></a>`race` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; race id or race mask; Uses Races enum values |
| <a id="col-won"></a>`won` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-duration"></a>`duration` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-date"></a>`date` | `datetime` | NO |  | `current_timestamp()` |  | schema-defined value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `arena_id`

non-negative numeric value.

### `team_id`

non-negative numeric value.

Value set: `Team` (enum) from `src/game/SharedDefines.h enum Team`.

### `level`

non-negative numeric value.

### `item_level`

non-negative numeric value.

### `class`

non-negative numeric value; class id or class mask.

Value set: `Classes` (enum) from `src/game/SharedDefines.h enum Classes`.

### `race`

non-negative numeric value; race id or race mask.

Value set: `Races` (enum) from `src/game/SharedDefines.h enum Races`.

### `won`

non-negative numeric value.

### `duration`

non-negative numeric value.

### `date`

schema-defined value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `Classes` | enum | [`class`](#col-class) | `src/game/SharedDefines.h enum Classes` | 9 |
| `Races` | enum | [`race`](#col-race) | `src/game/SharedDefines.h enum Races` | 10 |
| `Team` | enum | [`team_id`](#col-team-id) | `src/game/SharedDefines.h enum Team` | 4 |

### Possible Values

Used by: [`class`](#col-class)

#### `Classes`

Kind: `enum`

Source: `src/game/SharedDefines.h enum Classes`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `CLASS_WARRIOR` | Warrior |
| `2` | `0x2` | `CLASS_PALADIN` | Paladin |
| `3` | `0x3` | `CLASS_HUNTER` | Hunter |
| `4` | `0x4` | `CLASS_ROGUE` | Rogue |
| `5` | `0x5` | `CLASS_PRIEST` | Priest |
| `7` | `0x7` | `CLASS_SHAMAN` | Shaman |
| `8` | `0x8` | `CLASS_MAGE` | Mage |
| `9` | `0x9` | `CLASS_WARLOCK` | Warlock |
| `11` | `0xB` | `CLASS_DRUID` | Druid |

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

Used by: [`team_id`](#col-team-id)

#### `Team`

Kind: `enum`

Source: `src/game/SharedDefines.h enum Team`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `TEAM_NONE` | used when team value unknown or not set, 0 is also meaning that can be used !team check |
| `1` | `0x1` | `TEAM_CROSSFACTION` | Team Crossfaction |
| `67` | `0x43` | `HORDE` | Horde |
| `469` | `0x1D5` | `ALLIANCE` | Alliance |
