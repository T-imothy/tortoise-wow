---
layout: default
title: shop_categories
---

# shop_categories

World database table `shop_categories`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 4 | utf8mb3 | default |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(11) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | non-negative numeric value; identifier column |
| <a id="col-name"></a>`name` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-name-loc4"></a>`name_loc4` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-icon"></a>`icon` | `text` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `name`

text/string data.

### `name_loc4`

text/string data.

### `icon`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

