---
layout: default
title: taxi_path_transitions
---

# taxi_path_transitions

World database table `taxi_path_transitions`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 5 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-in-path"></a>`in_path` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-out-path"></a>`out_path` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-in-node"></a>`in_node` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-out-node"></a>`out_node` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-comment"></a>`comment` | `text` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `in_path`

non-negative numeric value.

### `out_path`

non-negative numeric value.

### `in_node`

non-negative numeric value.

### `out_node`

non-negative numeric value.

### `comment`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `in_path`, `out_path` |

