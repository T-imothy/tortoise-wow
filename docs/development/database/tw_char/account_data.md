---
layout: default
title: account_data
---

# account_data

Character database table `account_data`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 4 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-account"></a>`account` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-type"></a>`type` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-time"></a>`time` | `bigint(20) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-data"></a>`data` | `longblob` | NO |  |  |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `account`

non-negative numeric value.

### `type`

non-negative numeric value.

### `time`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `data`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `account`, `type` |
