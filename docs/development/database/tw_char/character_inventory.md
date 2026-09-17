---
layout: default
title: character_inventory
---

# character_inventory

Player System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 5 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO |  | `0` |  | Global Unique Identifier; non-negative numeric value; identifier column |
| <a id="col-bag"></a>`bag` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-slot"></a>`slot` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-item"></a>`item` | `int(10) unsigned` | NO | `PRI` | `0` |  | Item Global Unique Identifier; non-negative numeric value |
| <a id="col-item-template"></a>`item_template` | `int(10) unsigned` | NO |  | `0` |  | Item Identifier; non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `bag`

non-negative numeric value.

### `slot`

non-negative numeric value.

### `item`

non-negative numeric value.

References: [`item_template`](../tw_world/item_template.md).`entry`.

### `item_template`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `item` |
| KEY | `idx_guid` | `guid` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `item` | [`item_template`](../tw_world/item_template.md).`entry` | heuristic | inferred from column name |
