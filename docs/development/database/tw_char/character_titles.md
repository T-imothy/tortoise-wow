---
layout: default
title: character_titles
---

# character_titles

Player System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 3 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | Global Unique Identifier; non-negative numeric value; identifier column |
| <a id="col-title"></a>`title` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-active"></a>`active` | `tinyint(4)` | NO |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `title`

non-negative numeric value.

### `active`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid`, `title` |
