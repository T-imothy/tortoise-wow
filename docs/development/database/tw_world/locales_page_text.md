---
layout: default
title: locales_page_text
---

# locales_page_text

World database table `locales_page_text`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 10 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-text-loc0"></a>`Text_loc0` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-text-loc1"></a>`Text_loc1` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-text-loc2"></a>`Text_loc2` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-text-loc3"></a>`Text_loc3` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-text-loc4"></a>`Text_loc4` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-text-loc5"></a>`Text_loc5` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-text-loc6"></a>`Text_loc6` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-text-loc7"></a>`Text_loc7` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-text-loc8"></a>`Text_loc8` | `longtext` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

References: [`page_text`](page_text.md).`entry`.

### `Text_loc0`

text/string data.

### `Text_loc1`

text/string data.

### `Text_loc2`

text/string data.

### `Text_loc3`

text/string data.

### `Text_loc4`

text/string data.

### `Text_loc5`

text/string data.

### `Text_loc6`

text/string data.

### `Text_loc7`

text/string data.

### `Text_loc8`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `entry` | [`page_text`](page_text.md).`entry` | explicit | localized row |

