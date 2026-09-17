---
layout: default
title: playercreateinfo_spell
---

# playercreateinfo_spell

World database table `playercreateinfo_spell`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-race"></a>`race` | `tinyint(3) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; race id or race mask; Uses Races enum values |
| <a id="col-class"></a>`class` | `tinyint(3) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; class id or class mask; Uses Classes enum values |
| <a id="col-spell"></a>`spell` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-note"></a>`note` | `varchar(255)` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `race`

non-negative numeric value; race id or race mask.

Value set: `Races` (enum) from `src/game/SharedDefines.h enum Races`.

### `class`

non-negative numeric value; class id or class mask.

Value set: `Classes` (enum) from `src/game/SharedDefines.h enum Classes`.

### `spell`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `note`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `race`, `class`, `spell` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `spell` | [`spell_template`](spell_template.md).`entry` | heuristic | spell id |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `Classes` | enum | [`class`](#col-class) | `src/game/SharedDefines.h enum Classes` | 9 |
| `Races` | enum | [`race`](#col-race) | `src/game/SharedDefines.h enum Races` | 10 |

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
