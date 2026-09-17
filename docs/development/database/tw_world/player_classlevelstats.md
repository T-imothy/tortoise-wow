---
layout: default
title: player_classlevelstats
---

# player_classlevelstats

Stores levels stats.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-class"></a>`class` | `tinyint(3) unsigned` | NO | `PRI` |  |  | non-negative numeric value; class id or class mask; Uses Classes enum values |
| <a id="col-level"></a>`level` | `tinyint(3) unsigned` | NO | `PRI` |  |  | non-negative numeric value |
| <a id="col-basehp"></a>`basehp` | `smallint(5) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-basemana"></a>`basemana` | `smallint(5) unsigned` | NO |  |  |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `class`

non-negative numeric value; class id or class mask.

Value set: `Classes` (enum) from `src/game/SharedDefines.h enum Classes`.

### `level`

non-negative numeric value.

### `basehp`

non-negative numeric value.

### `basemana`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `class`, `level` |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `Classes` | enum | [`class`](#col-class) | `src/game/SharedDefines.h enum Classes` | 9 |

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
