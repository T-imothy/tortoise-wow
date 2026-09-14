---
layout: default
title: character_xp_from_log
---

# character_xp_from_log

Character database table `character_xp_from_log`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 3 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | Global Unique Identifier; non-negative numeric value; identifier column |
| <a id="col-type"></a>`type` | `tinyint(3) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-xp"></a>`xp` | `bigint(20) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `type`

non-negative numeric value.

### `xp`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid`, `type` |
