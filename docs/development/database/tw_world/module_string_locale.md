---
layout: default
title: module_string_locale
---

# module_string_locale

World database table `module_string_locale`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-module"></a>`module` | `varchar(64)` | NO | `PRI` |  |  | text/string data |
| <a id="col-id"></a>`id` | `int(10) unsigned` | NO | `PRI` |  |  | non-negative numeric value; identifier column |
| <a id="col-locale"></a>`locale` | `tinyint(3) unsigned` | NO | `PRI` |  |  | non-negative numeric value |
| <a id="col-content"></a>`content` | `text` | NO |  |  |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `module`

text/string data.

### `id`

non-negative numeric value; identifier column.

### `locale`

non-negative numeric value.

### `content`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `module`, `id`, `locale` |

