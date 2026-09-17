---
layout: default
title: module_string
---

# module_string

World database table `module_string`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 3 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-module"></a>`module` | `varchar(64)` | NO | `PRI` |  |  | text/string data |
| <a id="col-id"></a>`id` | `int(10) unsigned` | NO | `PRI` |  |  | non-negative numeric value; identifier column |
| <a id="col-content-default"></a>`content_default` | `text` | NO |  |  |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `module`

text/string data.

### `id`

non-negative numeric value; identifier column.

### `content_default`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `module`, `id` |

