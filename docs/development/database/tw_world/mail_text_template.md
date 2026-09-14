---
layout: default
title: mail_text_template
---

# mail_text_template

World database table `mail_text_template`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 9 | utf8mb4 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-content-default"></a>`content_default` | `mediumtext` | NO |  |  |  | text/string data |
| <a id="col-content-loc1"></a>`content_loc1` | `mediumtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-content-loc2"></a>`content_loc2` | `mediumtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-content-loc3"></a>`content_loc3` | `mediumtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-content-loc4"></a>`content_loc4` | `mediumtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-content-loc5"></a>`content_loc5` | `mediumtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-content-loc6"></a>`content_loc6` | `mediumtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-content-loc7"></a>`content_loc7` | `mediumtext` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `content_default`

text/string data.

### `content_loc1`

text/string data.

### `content_loc2`

text/string data.

### `content_loc3`

text/string data.

### `content_loc4`

text/string data.

### `content_loc5`

text/string data.

### `content_loc6`

text/string data.

### `content_loc7`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

