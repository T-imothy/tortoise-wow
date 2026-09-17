---
layout: default
title: logs_shellcoin
---

# logs_shellcoin

Character database table `logs_shellcoin`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 3 | latin1 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-time"></a>`time` | `bigint(20)` | NO |  | `0` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-count"></a>`count` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-price"></a>`price` | `int(11)` | NO |  | `0` |  | numeric value; money/cost value, usually copper |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `time`

numeric value; time/delay value; confirm unit in server usage.

### `count`

numeric value.

### `price`

numeric value; money/cost value, usually copper.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| KEY | `time` | `time` |
