---
layout: default
title: item_loot
---

# item_loot

Item System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 5 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-owner-guid"></a>`owner_guid` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-itemid"></a>`itemid` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-amount"></a>`amount` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-property"></a>`property` | `int(11)` | NO |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `owner_guid`

non-negative numeric value.

### `itemid`

non-negative numeric value.

References: [`item_template`](../tw_world/item_template.md).`entry`.

### `amount`

non-negative numeric value.

### `property`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid`, `itemid` |
| KEY | `idx_owner_guid` | `owner_guid` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `itemid` | [`item_template`](../tw_world/item_template.md).`entry` | heuristic | inferred from column name |
