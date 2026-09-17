---
layout: default
title: faction
---

# faction

World database table `faction`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 35 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `smallint(5) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-reputation-list-id"></a>`reputation_list_id` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-base-rep-race-mask1"></a>`base_rep_race_mask1` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses RaceMask mask values |
| <a id="col-base-rep-race-mask2"></a>`base_rep_race_mask2` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses RaceMask mask values |
| <a id="col-base-rep-race-mask3"></a>`base_rep_race_mask3` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses RaceMask mask values |
| <a id="col-base-rep-race-mask4"></a>`base_rep_race_mask4` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses RaceMask mask values |
| <a id="col-base-rep-class-mask1"></a>`base_rep_class_mask1` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses ClassMask mask values |
| <a id="col-base-rep-class-mask2"></a>`base_rep_class_mask2` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses ClassMask mask values |
| <a id="col-base-rep-class-mask3"></a>`base_rep_class_mask3` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses ClassMask mask values |
| <a id="col-base-rep-class-mask4"></a>`base_rep_class_mask4` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses ClassMask mask values |
| <a id="col-base-rep-value1"></a>`base_rep_value1` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-base-rep-value2"></a>`base_rep_value2` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-base-rep-value3"></a>`base_rep_value3` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-base-rep-value4"></a>`base_rep_value4` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-reputation-flags1"></a>`reputation_flags1` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-reputation-flags2"></a>`reputation_flags2` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-reputation-flags3"></a>`reputation_flags3` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-reputation-flags4"></a>`reputation_flags4` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-team"></a>`team` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Team enum values |
| <a id="col-name1"></a>`name1` | `varchar(256)` | NO |  | `''` |  | text/string data |
| <a id="col-name2"></a>`name2` | `varchar(256)` | NO |  | `''` |  | text/string data |
| <a id="col-name3"></a>`name3` | `varchar(256)` | NO |  | `''` |  | text/string data |
| <a id="col-name4"></a>`name4` | `varchar(256)` | NO |  | `''` |  | text/string data |
| <a id="col-name5"></a>`name5` | `varchar(256)` | NO |  | `''` |  | text/string data |
| <a id="col-name6"></a>`name6` | `varchar(256)` | NO |  | `''` |  | text/string data |
| <a id="col-name7"></a>`name7` | `varchar(256)` | NO |  | `''` |  | text/string data |
| <a id="col-name8"></a>`name8` | `varchar(256)` | NO |  | `''` |  | text/string data |
| <a id="col-description1"></a>`description1` | `varchar(512)` | NO |  | `''` |  | text/string data; script id or script name |
| <a id="col-description2"></a>`description2` | `varchar(512)` | NO |  | `''` |  | text/string data; script id or script name |
| <a id="col-description3"></a>`description3` | `varchar(512)` | NO |  | `''` |  | text/string data; script id or script name |
| <a id="col-description4"></a>`description4` | `varchar(512)` | NO |  | `''` |  | text/string data; script id or script name |
| <a id="col-description5"></a>`description5` | `varchar(512)` | NO |  | `''` |  | text/string data; script id or script name |
| <a id="col-description6"></a>`description6` | `varchar(512)` | NO |  | `''` |  | text/string data; script id or script name |
| <a id="col-description7"></a>`description7` | `varchar(512)` | NO |  | `''` |  | text/string data; script id or script name |
| <a id="col-description8"></a>`description8` | `varchar(512)` | NO |  | `''` |  | text/string data; script id or script name |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `reputation_list_id`

numeric value.

### `base_rep_race_mask1`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `RaceMask` (mask) from `src/game/SharedDefines.h race mask constants`.

### `base_rep_race_mask2`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `RaceMask` (mask) from `src/game/SharedDefines.h race mask constants`.

### `base_rep_race_mask3`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `RaceMask` (mask) from `src/game/SharedDefines.h race mask constants`.

### `base_rep_race_mask4`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `RaceMask` (mask) from `src/game/SharedDefines.h race mask constants`.

### `base_rep_class_mask1`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `ClassMask` (mask) from `src/game/SharedDefines.h class mask constants`.

### `base_rep_class_mask2`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `ClassMask` (mask) from `src/game/SharedDefines.h class mask constants`.

### `base_rep_class_mask3`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `ClassMask` (mask) from `src/game/SharedDefines.h class mask constants`.

### `base_rep_class_mask4`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `ClassMask` (mask) from `src/game/SharedDefines.h class mask constants`.

### `base_rep_value1`

numeric value.

### `base_rep_value2`

numeric value.

### `base_rep_value3`

numeric value.

### `base_rep_value4`

numeric value.

### `reputation_flags1`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

### `reputation_flags2`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

### `reputation_flags3`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

### `reputation_flags4`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

### `team`

non-negative numeric value.

Value set: `Team` (enum) from `src/game/SharedDefines.h enum Team`.

### `name1`

text/string data.

### `name2`

text/string data.

### `name3`

text/string data.

### `name4`

text/string data.

### `name5`

text/string data.

### `name6`

text/string data.

### `name7`

text/string data.

### `name8`

text/string data.

### `description1`

text/string data; script id or script name.

### `description2`

text/string data; script id or script name.

### `description3`

text/string data; script id or script name.

### `description4`

text/string data; script id or script name.

### `description5`

text/string data; script id or script name.

### `description6`

text/string data; script id or script name.

### `description7`

text/string data; script id or script name.

### `description8`

text/string data; script id or script name.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

## Related Tables

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`locales_faction`](locales_faction.md).`entry` | `entry` | explicit | localized row |
| [`game_graveyard_zone`](game_graveyard_zone.md).`faction` | `entry` | heuristic | inferred from column name |
| [`reputation_reward_rate`](reputation_reward_rate.md).`faction` | `entry` | heuristic | inferred from column name |
| [`reputation_spillover_template`](reputation_spillover_template.md).`faction` | `entry` | heuristic | inferred from column name |
| [`reputation_spillover_template`](reputation_spillover_template.md).`faction1` | `entry` | heuristic | inferred from column name |
| [`reputation_spillover_template`](reputation_spillover_template.md).`faction2` | `entry` | heuristic | inferred from column name |
| [`reputation_spillover_template`](reputation_spillover_template.md).`faction3` | `entry` | heuristic | inferred from column name |
| [`reputation_spillover_template`](reputation_spillover_template.md).`faction4` | `entry` | heuristic | inferred from column name |
| [`faction_template`](faction_template.md).`faction_id` | `entry` | heuristic | inferred from column name |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `ClassMask` | mask | [`base_rep_class_mask1`](#col-base-rep-class-mask1), [`base_rep_class_mask2`](#col-base-rep-class-mask2), [`base_rep_class_mask3`](#col-base-rep-class-mask3), [`base_rep_class_mask4`](#col-base-rep-class-mask4) | `src/game/SharedDefines.h class mask constants` | 9 |
| `RaceMask` | mask | [`base_rep_race_mask1`](#col-base-rep-race-mask1), [`base_rep_race_mask2`](#col-base-rep-race-mask2), [`base_rep_race_mask3`](#col-base-rep-race-mask3), [`base_rep_race_mask4`](#col-base-rep-race-mask4) | `src/game/SharedDefines.h race mask constants` | 10 |
| `Team` | enum | [`team`](#col-team) | `src/game/SharedDefines.h enum Team` | 4 |

### Possible Values

Used by: [`base_rep_class_mask1`](#col-base-rep-class-mask1), [`base_rep_class_mask2`](#col-base-rep-class-mask2), [`base_rep_class_mask3`](#col-base-rep-class-mask3), [`base_rep_class_mask4`](#col-base-rep-class-mask4)

#### `ClassMask`

Kind: `mask`

Source: `src/game/SharedDefines.h class mask constants`

Class masks use 1 &lt;&lt; (class id - 1). Combine allowed classes with bitwise OR.

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `CLASSMASK_WARRIOR` | Warrior |
| `2` | `0x2` | `CLASSMASK_PALADIN` | Paladin |
| `4` | `0x4` | `CLASSMASK_HUNTER` | Hunter |
| `8` | `0x8` | `CLASSMASK_ROGUE` | Rogue |
| `16` | `0x10` | `CLASSMASK_PRIEST` | Priest |
| `64` | `0x40` | `CLASSMASK_SHAMAN` | Shaman |
| `128` | `0x80` | `CLASSMASK_MAGE` | Mage |
| `256` | `0x100` | `CLASSMASK_WARLOCK` | Warlock |
| `1024` | `0x400` | `CLASSMASK_DRUID` | Druid |

Used by: [`base_rep_race_mask1`](#col-base-rep-race-mask1), [`base_rep_race_mask2`](#col-base-rep-race-mask2), [`base_rep_race_mask3`](#col-base-rep-race-mask3), [`base_rep_race_mask4`](#col-base-rep-race-mask4)

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

Used by: [`team`](#col-team)

#### `Team`

Kind: `enum`

Source: `src/game/SharedDefines.h enum Team`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `TEAM_NONE` | used when team value unknown or not set, 0 is also meaning that can be used !team check |
| `1` | `0x1` | `TEAM_CROSSFACTION` | Team Crossfaction |
| `67` | `0x43` | `HORDE` | Horde |
| `469` | `0x1D5` | `ALLIANCE` | Alliance |

### Unmapped Flag-Like Columns

| Column | Type | Guidance |
| --- | --- | --- |
| [`reputation_flags1`](#col-reputation-flags1) | `mediumint(8) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
| [`reputation_flags2`](#col-reputation-flags2) | `mediumint(8) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
| [`reputation_flags3`](#col-reputation-flags3) | `mediumint(8) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
| [`reputation_flags4`](#col-reputation-flags4) | `mediumint(8) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
