---
layout: default
title: character_transmogs
---

# character_transmogs

Character database table `character_transmogs`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 2 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-itemid"></a>`itemId` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `itemId`

non-negative numeric value.

References: [`item_template`](../tw_world/item_template.md).`entry`.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid`, `itemId` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `itemId` | [`item_template`](../tw_world/item_template.md).`entry` | heuristic | inferred from column name |
