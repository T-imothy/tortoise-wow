---
layout: default
title: skill_line_ability
---

# skill_line_ability

World database table `skill_line_ability`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 11 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `smallint(5) unsigned` | NO | `PRI` |  |  | non-negative numeric value; identifier column |
| <a id="col-skill-id"></a>`skill_id` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spell-id"></a>`spell_id` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-race-mask"></a>`race_mask` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; race id or race mask; Uses RaceMask mask values |
| <a id="col-class-mask"></a>`class_mask` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; class id or class mask; Uses ClassMask mask values |
| <a id="col-req-skill-value"></a>`req_skill_value` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-superseded-by-spell"></a>`superseded_by_spell` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-learn-on-get-skill"></a>`learn_on_get_skill` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-max-value"></a>`max_value` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-min-value"></a>`min_value` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-req-train-points"></a>`req_train_points` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `skill_id`

non-negative numeric value.

### `spell_id`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `race_mask`

non-negative numeric value; mask/flags column; combine values with bitwise OR; race id or race mask.

Value set: `RaceMask` (mask) from `src/game/SharedDefines.h race mask constants`.

### `class_mask`

non-negative numeric value; mask/flags column; combine values with bitwise OR; class id or class mask.

Value set: `ClassMask` (mask) from `src/game/SharedDefines.h class mask constants`.

### `req_skill_value`

non-negative numeric value.

### `superseded_by_spell`

non-negative numeric value.

### `learn_on_get_skill`

non-negative numeric value.

### `max_value`

non-negative numeric value.

### `min_value`

non-negative numeric value.

### `req_train_points`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `spell_id` | [`spell_template`](spell_template.md).`entry` | heuristic | spell id |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `ClassMask` | mask | [`class_mask`](#col-class-mask) | `src/game/SharedDefines.h class mask constants` | 9 |
| `RaceMask` | mask | [`race_mask`](#col-race-mask) | `src/game/SharedDefines.h race mask constants` | 10 |

### Possible Values

Used by: [`class_mask`](#col-class-mask)

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

Used by: [`race_mask`](#col-race-mask)

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
