---
layout: default
title: custom_merchant
---

# custom_merchant

Npc System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 7 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; identifier column |
| <a id="col-slot"></a>`slot` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-item"></a>`item` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-count"></a>`count` | `int(10) unsigned` | NO |  | `1` |  | non-negative numeric value |
| <a id="col-extendedcost"></a>`extendedcost` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-condition-id"></a>`condition_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `entry`

non-negative numeric value; identifier column.

### `slot`

non-negative numeric value.

### `item`

non-negative numeric value.

References: [`item_template`](item_template.md).`entry`.

### `count`

non-negative numeric value.

### `extendedcost`

non-negative numeric value; money/cost value, usually copper.

### `condition_id`

non-negative numeric value.

References: [`conditions`](conditions.md).`condition_entry`.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |
| KEY | `entry_slot` | `entry`, `slot` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `condition_id` | [`conditions`](conditions.md).`condition_entry` | heuristic | inferred from column name |
| `item` | [`item_template`](item_template.md).`entry` | heuristic | item id |

