---
layout: default
title: locales_gameobject
---

# locales_gameobject

World database table `locales_gameobject`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 10 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-name-loc0"></a>`name_loc0` | `varchar(100)` | NO |  | `''` |  | text/string data |
| <a id="col-name-loc1"></a>`name_loc1` | `varchar(100)` | NO |  | `''` |  | text/string data |
| <a id="col-name-loc2"></a>`name_loc2` | `varchar(100)` | NO |  | `''` |  | text/string data |
| <a id="col-name-loc3"></a>`name_loc3` | `varchar(100)` | NO |  | `''` |  | text/string data |
| <a id="col-name-loc4"></a>`name_loc4` | `varchar(100)` | NO |  | `''` |  | text/string data |
| <a id="col-name-loc5"></a>`name_loc5` | `varchar(100)` | NO |  | `''` |  | text/string data |
| <a id="col-name-loc6"></a>`name_loc6` | `varchar(100)` | NO |  | `''` |  | text/string data |
| <a id="col-name-loc7"></a>`name_loc7` | `varchar(100)` | NO |  | `''` |  | text/string data |
| <a id="col-name-loc8"></a>`name_loc8` | `varchar(100)` | NO |  | `''` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

References: [`gameobject`](gameobject.md).`entry`.

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

### `name_loc7`

text/string data.

### `name_loc8`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `entry` | [`gameobject`](gameobject.md).`entry` | explicit | localized row |

