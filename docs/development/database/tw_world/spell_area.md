---
layout: default
title: spell_area
---

# spell_area

World database table `spell_area`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 9 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-spell"></a>`spell` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-area"></a>`area` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-quest-start"></a>`quest_start` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-quest-start-active"></a>`quest_start_active` | `tinyint(1) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-quest-end"></a>`quest_end` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-aura-spell"></a>`aura_spell` | `mediumint(9)` | NO | `PRI` | `0` |  | numeric value |
| <a id="col-racemask"></a>`racemask` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; race id or race mask; Uses RaceMask mask values |
| <a id="col-gender"></a>`gender` | `tinyint(1) unsigned` | NO | `PRI` | `2` |  | non-negative numeric value; Uses Gender enum values |
| <a id="col-autocast"></a>`autocast` | `tinyint(1) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `spell`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `area`

non-negative numeric value.

References: [`area_template`](area_template.md).`entry`.

### `quest_start`

non-negative numeric value.

### `quest_start_active`

non-negative numeric value.

### `quest_end`

non-negative numeric value.

### `aura_spell`

numeric value.

### `racemask`

non-negative numeric value; mask/flags column; combine values with bitwise OR; race id or race mask.

Value set: `RaceMask` (mask) from `src/game/SharedDefines.h race mask constants`.

### `gender`

non-negative numeric value.

Value set: `Gender` (enum) from `src/game/SharedDefines.h enum Gender`.

### `autocast`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `spell`, `area`, `quest_start`, `quest_start_active`, `aura_spell`, `racemask`, `gender` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `area` | [`area_template`](area_template.md).`entry` | heuristic | inferred from column name |
| `spell` | [`spell_template`](spell_template.md).`entry` | heuristic | spell id |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `Gender` | enum | [`gender`](#col-gender) | `src/game/SharedDefines.h enum Gender` | 3 |
| `RaceMask` | mask | [`racemask`](#col-racemask) | `src/game/SharedDefines.h race mask constants` | 10 |

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

Used by: [`racemask`](#col-racemask)

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
