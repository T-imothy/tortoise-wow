---
layout: default
title: locales_taxi_node
---

# locales_taxi_node

World database table `locales_taxi_node`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 8 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `int(10) unsigned` | NO | `PRI` |  |  | non-negative numeric value; identifier column |
| <a id="col-name-loc0"></a>`name_loc0` | `varchar(256)` | NO |  | `''` |  | text/string data |
| <a id="col-name-loc1"></a>`name_loc1` | `varchar(256)` | NO |  | `''` |  | text/string data |
| <a id="col-name-loc2"></a>`name_loc2` | `varchar(256)` | NO |  | `''` |  | text/string data |
| <a id="col-name-loc3"></a>`name_loc3` | `varchar(256)` | NO |  | `''` |  | text/string data |
| <a id="col-name-loc4"></a>`name_loc4` | `varchar(256)` | NO |  | `''` |  | text/string data |
| <a id="col-name-loc5"></a>`name_loc5` | `varchar(256)` | NO |  | `''` |  | text/string data |
| <a id="col-name-loc6"></a>`name_loc6` | `varchar(256)` | NO |  | `''` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

References: [`taxi_nodes`](taxi_nodes.md).`entry`.

### `name_loc0`

text/string data.

### `name_loc1`

text/string data.

### `name_loc2`

text/string data.

### `name_loc3`

text/string data.

### `name_loc4`

text/string data.

### `name_loc5`

text/string data.

### `name_loc6`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `entry` | [`taxi_nodes`](taxi_nodes.md).`entry` | explicit | localized row |

