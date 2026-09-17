---
layout: default
title: logs_spamdetect
---

# logs_spamdetect

Character database table `logs_spamdetect`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 7 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | non-negative numeric value; identifier column |
| <a id="col-time"></a>`time` | `timestamp` | NO |  | `current_timestamp()` |  | time/delay value; confirm unit in server usage |
| <a id="col-realm"></a>`realm` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-accountid"></a>`accountId` | `int(11)` | YES |  | `0` |  | numeric value |
| <a id="col-fromip"></a>`fromIP` | `varchar(16)` | NO |  |  |  | text/string data |
| <a id="col-fromfingerprint"></a>`fromFingerprint` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-comment"></a>`comment` | `varchar(8192)` | NO |  | `''` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `time`

time/delay value; confirm unit in server usage.

### `realm`

non-negative numeric value.

### `accountId`

numeric value.

### `fromIP`

text/string data.

### `fromFingerprint`

non-negative numeric value.

### `comment`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |
