---
layout: default
title: worldstates
---

# worldstates

Character database table `worldstates`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 3 | latin1 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `int(11)` | YES |  | `NULL` |  | numeric value; identifier column |
| <a id="col-value"></a>`value` | `int(11)` | YES |  | `NULL` |  | numeric value |
| <a id="col-comment"></a>`comment` | `varchar(255)` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

numeric value; identifier column.

### `value`

numeric value.

### `comment`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| UNIQUE | `key_entry` | `entry` |
