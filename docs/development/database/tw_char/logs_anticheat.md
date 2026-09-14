---
layout: default
title: logs_anticheat
---

# logs_anticheat

Character database table `logs_anticheat`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 9 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | non-negative numeric value; identifier column |
| <a id="col-time"></a>`time` | `datetime` | NO |  | `current_timestamp()` |  | time/delay value; confirm unit in server usage |
| <a id="col-realm"></a>`realm` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-account"></a>`account` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-ip"></a>`ip` | `varchar(16)` | NO |  |  |  | text/string data |
| <a id="col-fingerprint"></a>`fingerprint` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-actionmask"></a>`actionMask` | `int(10) unsigned` | YES |  | `NULL` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-player"></a>`player` | `varchar(32)` | NO |  |  |  | text/string data |
| <a id="col-info"></a>`info` | `varchar(512)` | NO |  |  |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `time`

time/delay value; confirm unit in server usage.

### `realm`

non-negative numeric value.

### `account`

non-negative numeric value.

### `ip`

text/string data.

### `fingerprint`

non-negative numeric value.

### `actionMask`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

### `player`

text/string data.

### `info`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |
| KEY | `account` | `account` |
| KEY | `ip` | `ip` |
| KEY | `time` | `time` |
| KEY | `realm` | `realm` |

## Masks and Flags

### Unmapped Flag-Like Columns

| Column | Type | Guidance |
| --- | --- | --- |
| [`actionMask`](#col-actionmask) | `int(10) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
