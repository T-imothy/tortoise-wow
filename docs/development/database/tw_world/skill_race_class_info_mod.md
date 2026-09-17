---
layout: default
title: skill_race_class_info_mod
---

# skill_race_class_info_mod

World database table `skill_race_class_info_mod`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 9 | utf8mb4 | COMPRESSED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`Id` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-skilllinedbcrecord"></a>`SkillLineDbcRecord` | `int(11)` | NO |  | `-1` |  | numeric value |
| <a id="col-racemask"></a>`RaceMask` | `int(11)` | NO |  | `-1` |  | numeric value; mask/flags column; combine values with bitwise OR; race id or race mask; Uses RaceMask mask values |
| <a id="col-classmask"></a>`ClassMask` | `int(11)` | NO |  | `-1` |  | numeric value; mask/flags column; combine values with bitwise OR; class id or class mask; Uses ClassMask mask values |
| <a id="col-flags"></a>`Flags` | `int(11)` | NO |  | `-1` |  | numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-minlevel"></a>`MinLevel` | `int(11)` | NO |  | `-1` |  | numeric value |
| <a id="col-skilltierid"></a>`SkillTierId` | `int(11)` | NO |  | `-1` |  | numeric value |
| <a id="col-skillcostindex"></a>`SkillCostIndex` | `int(11)` | NO |  | `-1` |  | numeric value; money/cost value, usually copper |
| <a id="col-comment"></a>`Comment` | `varchar(255)` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `Id`

non-negative numeric value; identifier column.

### `SkillLineDbcRecord`

numeric value.

### `RaceMask`

numeric value; mask/flags column; combine values with bitwise OR; race id or race mask.

Value set: `RaceMask` (mask) from `src/game/SharedDefines.h race mask constants`.

### `ClassMask`

numeric value; mask/flags column; combine values with bitwise OR; class id or class mask.

Value set: `ClassMask` (mask) from `src/game/SharedDefines.h class mask constants`.

### `Flags`

numeric value; mask/flags column; combine values with bitwise OR.

### `MinLevel`

numeric value.

### `SkillTierId`

numeric value.

### `SkillCostIndex`

numeric value; money/cost value, usually copper.

### `Comment`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `Id` |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `ClassMask` | mask | [`ClassMask`](#col-classmask) | `src/game/SharedDefines.h class mask constants` | 9 |
| `RaceMask` | mask | [`RaceMask`](#col-racemask) | `src/game/SharedDefines.h race mask constants` | 10 |

### Possible Values

Used by: [`ClassMask`](#col-classmask)

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

Used by: [`RaceMask`](#col-racemask)

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

### Unmapped Flag-Like Columns

| Column | Type | Guidance |
| --- | --- | --- |
| [`Flags`](#col-flags) | `int(11)` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
