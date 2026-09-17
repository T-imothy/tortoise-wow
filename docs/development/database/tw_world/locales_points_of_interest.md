---
layout: default
title: locales_points_of_interest
---

# locales_points_of_interest

World database table `locales_points_of_interest`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 10 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-icon-name-loc0"></a>`icon_name_loc0` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-icon-name-loc1"></a>`icon_name_loc1` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-icon-name-loc2"></a>`icon_name_loc2` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-icon-name-loc3"></a>`icon_name_loc3` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-icon-name-loc4"></a>`icon_name_loc4` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-icon-name-loc5"></a>`icon_name_loc5` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-icon-name-loc6"></a>`icon_name_loc6` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-icon-name-loc7"></a>`icon_name_loc7` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-icon-name-loc8"></a>`icon_name_loc8` | `text` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

References: [`points_of_interest`](points_of_interest.md).`entry`.

### `icon_name_loc0`

text/string data.

### `icon_name_loc1`

text/string data.

### `icon_name_loc2`

text/string data.

### `icon_name_loc3`

text/string data.

### `icon_name_loc4`

text/string data.

### `icon_name_loc5`

text/string data.

### `icon_name_loc6`

text/string data.

### `icon_name_loc7`

text/string data.

### `icon_name_loc8`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `entry` | [`points_of_interest`](points_of_interest.md).`entry` | explicit | localized row |

