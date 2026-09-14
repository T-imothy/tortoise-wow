---
layout: default
title: item_required_target
---

# item_required_target

World database table `item_required_target`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 3 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO |  |  |  | non-negative numeric value; identifier column |
| <a id="col-type"></a>`type` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ItemRequiredTargetType enum values |
| <a id="col-target-entry"></a>`target_entry` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `type`

non-negative numeric value.

Value set: `ItemRequiredTargetType` (enum) from `src/game/Objects/Item.h enum ItemRequiredTargetType`.

### `target_entry`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| UNIQUE | `entry_type_target` | `entry`, `type`, `target_entry` |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `ItemRequiredTargetType` | enum | [`type`](#col-type) | `src/game/Objects/Item.h enum ItemRequiredTargetType` | 2 |

### Possible Values

Used by: [`type`](#col-type)

#### `ItemRequiredTargetType`

Kind: `enum`

Source: `src/game/Objects/Item.h enum ItemRequiredTargetType`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `ITEM_TARGET_TYPE_CREATURE` | Target Type Creature |
| `2` | `0x2` | `ITEM_TARGET_TYPE_DEAD` | Target Type Dead |
