---
layout: default
title: item_loot_template
---

# item_loot_template

Loot System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 7 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-item"></a>`item` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-chanceorquestchance"></a>`ChanceOrQuestChance` | `float` | NO |  | `100` |  | numeric value |
| <a id="col-groupid"></a>`groupid` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-mincountorref"></a>`mincountOrRef` | `mediumint(9)` | NO |  | `1` |  | numeric value |
| <a id="col-maxcount"></a>`maxcount` | `tinyint(3) unsigned` | NO |  | `1` |  | non-negative numeric value |
| <a id="col-condition-id"></a>`condition_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `item`

non-negative numeric value.

References: [`item_template`](item_template.md).`entry`.

### `ChanceOrQuestChance`

numeric value.

### `groupid`

non-negative numeric value.

### `mincountOrRef`

numeric value.

### `maxcount`

non-negative numeric value.

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
| `item` | [`item_template`](item_template.md).`entry` | heuristic | item id |

