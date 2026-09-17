---
layout: default
title: bugreport
---

# bugreport

Debug System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 3 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(11)` | NO | `PRI` |  | AUTO_INCREMENT | Identifier; numeric value; identifier column |
| <a id="col-type"></a>`type` | `longtext` | NO |  |  |  | text/string data |
| <a id="col-content"></a>`content` | `longtext` | NO |  |  |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

numeric value; identifier column.

### `type`

text/string data.

### `content`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |
