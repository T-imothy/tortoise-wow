---
layout: default
title: exploration_basexp
---

# exploration_basexp

Exploration System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 2 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-level"></a>`level` | `tinyint(4)` | NO | `PRI` | `0` |  | numeric value |
| <a id="col-basexp"></a>`basexp` | `mediumint(9)` | NO |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `level`

numeric value.

### `basexp`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `level` |

