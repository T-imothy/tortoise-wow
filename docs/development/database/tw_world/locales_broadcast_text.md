---
layout: default
title: locales_broadcast_text
---

# locales_broadcast_text

World database table `locales_broadcast_text`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 19 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-male-text-loc0"></a>`male_text_loc0` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-male-text-loc1"></a>`male_text_loc1` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-male-text-loc2"></a>`male_text_loc2` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-male-text-loc3"></a>`male_text_loc3` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-male-text-loc4"></a>`male_text_loc4` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-male-text-loc5"></a>`male_text_loc5` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-male-text-loc6"></a>`male_text_loc6` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-male-text-loc7"></a>`male_text_loc7` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-male-text-loc8"></a>`male_text_loc8` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-female-text-loc0"></a>`female_text_loc0` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-female-text-loc1"></a>`female_text_loc1` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-female-text-loc2"></a>`female_text_loc2` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-female-text-loc3"></a>`female_text_loc3` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-female-text-loc4"></a>`female_text_loc4` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-female-text-loc5"></a>`female_text_loc5` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-female-text-loc6"></a>`female_text_loc6` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-female-text-loc7"></a>`female_text_loc7` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-female-text-loc8"></a>`female_text_loc8` | `longtext` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

References: [`broadcast_text`](broadcast_text.md).`entry`.

### `male_text_loc0`

text/string data.

### `male_text_loc1`

text/string data.

### `male_text_loc2`

text/string data.

### `male_text_loc3`

text/string data.

### `male_text_loc4`

text/string data.

### `male_text_loc5`

text/string data.

### `male_text_loc6`

text/string data.

### `male_text_loc7`

text/string data.

### `male_text_loc8`

text/string data.

### `female_text_loc0`

text/string data.

### `female_text_loc1`

text/string data.

### `female_text_loc2`

text/string data.

### `female_text_loc3`

text/string data.

### `female_text_loc4`

text/string data.

### `female_text_loc5`

text/string data.

### `female_text_loc6`

text/string data.

### `female_text_loc7`

text/string data.

### `female_text_loc8`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `entry` | [`broadcast_text`](broadcast_text.md).`entry` | explicit | localized row |

