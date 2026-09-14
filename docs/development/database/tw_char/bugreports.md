---
layout: default
title: bugreports
---

# bugreports

Character database table `bugreports`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 13 | latin1 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(11)` | NO |  |  | AUTO_INCREMENT | numeric value; identifier column |
| <a id="col-reporttime"></a>`reportTime` | `timestamp` | YES |  | `current_timestamp()` |  | time/delay value; confirm unit in server usage |
| <a id="col-playerguid"></a>`playerGuid` | `int(11)` | YES |  | `NULL` |  | numeric value |
| <a id="col-playermap"></a>`playerMap` | `int(11)` | YES |  | `NULL` |  | numeric value |
| <a id="col-playerinstanceid"></a>`playerInstanceId` | `int(11)` | YES |  | `NULL` |  | numeric value |
| <a id="col-playerx"></a>`playerX` | `float` | YES |  | `NULL` |  | numeric value |
| <a id="col-playery"></a>`playerY` | `float` | YES |  | `NULL` |  | numeric value |
| <a id="col-playerz"></a>`playerZ` | `float` | YES |  | `NULL` |  | numeric value |
| <a id="col-clientip"></a>`clientIp` | `varchar(100)` | YES |  | `NULL` |  | text/string data |
| <a id="col-reporttype"></a>`reportType` | `tinyint(4)` | YES |  | `NULL` |  | numeric value |
| <a id="col-reporttext"></a>`reportText` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-serverinformation"></a>`serverInformation` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-bugstatus"></a>`bugStatus` | `enum('New','NeedTest','Fixed','Invalid','Duplicate','Confirmed')` | NO |  | `'New'` |  | schema-defined value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

numeric value; identifier column.

### `reportTime`

time/delay value; confirm unit in server usage.

### `playerGuid`

numeric value.

### `playerMap`

numeric value.

### `playerInstanceId`

numeric value.

### `playerX`

numeric value.

### `playerY`

numeric value.

### `playerZ`

numeric value.

### `clientIp`

text/string data.

### `reportType`

numeric value.

### `reportText`

text/string data.

### `serverInformation`

text/string data.

### `bugStatus`

schema-defined value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| KEY | `idx_id` | `id` |
