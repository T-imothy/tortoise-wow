---
layout: default
title: locales_creature
---

# locales_creature

World database table `locales_creature`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 19 | utf8mb3 | DYNAMIC |

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
| <a id="col-subname-loc0"></a>`subname_loc0` | `varchar(100)` | YES |  | `NULL` |  | text/string data |
| <a id="col-subname-loc1"></a>`subname_loc1` | `varchar(100)` | YES |  | `NULL` |  | text/string data |
| <a id="col-subname-loc2"></a>`subname_loc2` | `varchar(100)` | YES |  | `NULL` |  | text/string data |
| <a id="col-subname-loc3"></a>`subname_loc3` | `varchar(100)` | YES |  | `NULL` |  | text/string data |
| <a id="col-subname-loc4"></a>`subname_loc4` | `varchar(100)` | YES |  | `NULL` |  | text/string data |
| <a id="col-subname-loc5"></a>`subname_loc5` | `varchar(100)` | YES |  | `NULL` |  | text/string data |
| <a id="col-subname-loc6"></a>`subname_loc6` | `varchar(100)` | YES |  | `NULL` |  | text/string data |
| <a id="col-subname-loc7"></a>`subname_loc7` | `varchar(100)` | YES |  | `NULL` |  | text/string data |
| <a id="col-subname-loc8"></a>`subname_loc8` | `varchar(100)` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

References: [`creature`](creature.md).`entry`.

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

### `subname_loc0`

text/string data.

### `subname_loc1`

text/string data.

### `subname_loc2`

text/string data.

### `subname_loc3`

text/string data.

### `subname_loc4`

text/string data.

### `subname_loc5`

text/string data.

### `subname_loc6`

text/string data.

### `subname_loc7`

text/string data.

### `subname_loc8`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `entry` | [`creature`](creature.md).`entry` | explicit | localized row |

