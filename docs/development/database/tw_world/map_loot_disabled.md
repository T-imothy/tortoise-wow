---
layout: default
title: map_loot_disabled
---

# map_loot_disabled

World database table `map_loot_disabled`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 2 | latin1 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-map-id"></a>`map_id` | `int(11)` | NO | `PRI` | `0` |  | numeric value |
| <a id="col-comment"></a>`comment` | `varchar(255)` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `map_id`

numeric value.

References: [`map_template`](map_template.md).`entry`.

### `comment`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `map_id` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `map_id` | [`map_template`](map_template.md).`entry` | heuristic | inferred from column name |

