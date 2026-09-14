---
layout: default
title: whisper_targets
---

# whisper_targets

Character database table `whisper_targets`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 3 | utf8mb4 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-account"></a>`account` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-target-guid"></a>`target_guid` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-time"></a>`time` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value; time/delay value; confirm unit in server usage |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `account`

non-negative numeric value.

### `target_guid`

non-negative numeric value.

### `time`

non-negative numeric value; time/delay value; confirm unit in server usage.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| UNIQUE | `account_target` | `account`, `target_guid` |
