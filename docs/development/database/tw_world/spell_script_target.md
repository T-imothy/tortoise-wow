---
layout: default
title: spell_script_target
---

# spell_script_target

Spell System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 5 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO |  |  |  | non-negative numeric value; identifier column |
| <a id="col-type"></a>`type` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellTargetType enum values |
| <a id="col-targetentry"></a>`targetEntry` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-conditionid"></a>`conditionId` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-inverseeffectmask"></a>`inverseEffectMask` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `type`

non-negative numeric value.

Value set: `SpellTargetType` (enum) from `src/game/Spells/SpellMgr.h enum SpellTargetType`.

### `targetEntry`

non-negative numeric value.

### `conditionId`

non-negative numeric value.

References: [`conditions`](conditions.md).`condition_entry`.

### `inverseEffectMask`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| UNIQUE | `entry_type_target` | `entry`, `type`, `targetEntry` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `conditionId` | [`conditions`](conditions.md).`condition_entry` | heuristic | inferred from column name |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `SpellTargetType` | enum | [`type`](#col-type) | `src/game/Spells/SpellMgr.h enum SpellTargetType` | 3 |

### Possible Values

Used by: [`type`](#col-type)

#### `SpellTargetType`

Kind: `enum`

Source: `src/game/Spells/SpellMgr.h enum SpellTargetType`

`spell_script_target.type` is loaded by `SpellMgr::LoadSpellScriptTarget` and must be less than `MAX_SPELL_TARGET_TYPE`. These values describe the kind of target row stored in `targetEntry`, not database script target selection modes.

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `SPELL_TARGET_TYPE_GAMEOBJECT` | Gameobject target |
| `1` | `0x1` | `SPELL_TARGET_TYPE_CREATURE` | Living creature target |
| `2` | `0x2` | `SPELL_TARGET_TYPE_DEAD` | Dead creature target |

### Unmapped Flag-Like Columns

| Column | Type | Guidance |
| --- | --- | --- |
| [`inverseEffectMask`](#col-inverseeffectmask) | `mediumint(8) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
