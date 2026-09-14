---
layout: default
title: world
---

# world

Character database table `world`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 2 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-map"></a>`map` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-data"></a>`data` | `longtext` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `map`

non-negative numeric value.

References: [`map_template`](../tw_world/map_template.md).`entry`.

### `data`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `map` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `map` | [`map_template`](../tw_world/map_template.md).`entry` | heuristic | inferred from column name |
