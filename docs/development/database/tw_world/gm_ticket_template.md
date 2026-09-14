---
layout: default
title: gm_ticket_template
---

# gm_ticket_template

World database table `gm_ticket_template`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 3 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | non-negative numeric value; identifier column |
| <a id="col-name"></a>`name` | `varchar(32)` | NO |  | `''` |  | text/string data |
| <a id="col-text"></a>`text` | `varchar(256)` | NO |  | `''` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `name`

text/string data.

### `text`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

