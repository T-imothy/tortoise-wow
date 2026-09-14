---
layout: default
title: npc_vendor_template
---

# npc_vendor_template

Npc System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 7 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-slot"></a>`slot` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-item"></a>`item` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-maxcount"></a>`maxcount` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-incrtime"></a>`incrtime` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-itemflags"></a>`itemflags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses VendorItemFlags mask values |
| <a id="col-condition-id"></a>`condition_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `slot`

non-negative numeric value.

### `item`

non-negative numeric value.

References: [`item_template`](item_template.md).`entry`.

### `maxcount`

non-negative numeric value.

### `incrtime`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `itemflags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `VendorItemFlags` (mask) from `src/game/Objects/Creature.h enum VendorItemFlags`.

### `condition_id`

non-negative numeric value.

References: [`conditions`](conditions.md).`condition_entry`.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry`, `item` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `condition_id` | [`conditions`](conditions.md).`condition_entry` | heuristic | inferred from column name |
| `item` | [`item_template`](item_template.md).`entry` | explicit | sold item |

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`creature_template`](creature_template.md).`vendor_id` | `entry` | explicit | vendor template |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `VendorItemFlags` | mask | [`itemflags`](#col-itemflags) | `src/game/Objects/Creature.h enum VendorItemFlags` | 2 |

### Possible Values

Used by: [`itemflags`](#col-itemflags)

#### `VendorItemFlags`

Kind: `mask`

Source: `src/game/Objects/Creature.h enum VendorItemFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `VENDOR_ITEM_FLAG_RANDOM_RESTOCK` | Random restock behavior |
| `2` | `0x2` | `VENDOR_ITEM_FLAG_DYNAMIC_RESTOCK` | Dynamic restock behavior |
