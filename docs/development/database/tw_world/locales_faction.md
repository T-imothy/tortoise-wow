---
layout: default
title: locales_faction
---

# locales_faction

World database table `locales_faction`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 15 | utf8mb3 | DYNAMIC |

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
| <a id="col-description-loc0"></a>`description_loc0` | `varchar(512)` | NO |  | `''` |  | text/string data; script id or script name |
| <a id="col-description-loc1"></a>`description_loc1` | `varchar(512)` | NO |  | `''` |  | text/string data; script id or script name |
| <a id="col-description-loc2"></a>`description_loc2` | `varchar(512)` | NO |  | `''` |  | text/string data; script id or script name |
| <a id="col-description-loc3"></a>`description_loc3` | `varchar(512)` | NO |  | `''` |  | text/string data; script id or script name |
| <a id="col-description-loc4"></a>`description_loc4` | `varchar(512)` | NO |  | `''` |  | text/string data; script id or script name |
| <a id="col-description-loc5"></a>`description_loc5` | `varchar(512)` | NO |  | `''` |  | text/string data; script id or script name |
| <a id="col-description-loc6"></a>`description_loc6` | `varchar(512)` | NO |  | `''` |  | text/string data; script id or script name |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

References: [`faction`](faction.md).`entry`.

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

### `description_loc0`

text/string data; script id or script name.

### `description_loc1`

text/string data; script id or script name.

### `description_loc2`

text/string data; script id or script name.

### `description_loc3`

text/string data; script id or script name.

### `description_loc4`

text/string data; script id or script name.

### `description_loc5`

text/string data; script id or script name.

### `description_loc6`

text/string data; script id or script name.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `entry` | [`faction`](faction.md).`entry` | explicit | localized row |

