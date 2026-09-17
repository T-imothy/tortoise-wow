---
layout: default
title: object_scaling
---

# object_scaling

World database table `object_scaling`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 2 | utf8mb4 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-fullguid"></a>`fullGuid` | `bigint(20) unsigned` | NO | `PRI` |  |  | non-negative numeric value |
| <a id="col-scale"></a>`scale` | `float` | NO |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `fullGuid`

non-negative numeric value.

### `scale`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `fullGuid` |

