---
layout: default
title: areatrigger_tavern
---

# areatrigger_tavern

Trigger System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 2 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | Identifier; non-negative numeric value; identifier column |
| <a id="col-name"></a>`name` | `text` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `name`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

