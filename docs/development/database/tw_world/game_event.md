---
layout: default
title: game_event
---

# game_event

World database table `game_event`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 10 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` |  |  | Entry of the game event; non-negative numeric value; identifier column |
| <a id="col-start-time"></a>`start_time` | `timestamp` | NO |  | `'0000-00-00 00:00:00'` |  | Absolute start date, the event will never start before; time/delay value; confirm unit in server usage |
| <a id="col-end-time"></a>`end_time` | `timestamp` | NO |  | `'0000-00-00 00:00:00'` |  | Absolute end date, the event will never start afler; time/delay value; confirm unit in server usage |
| <a id="col-occurence"></a>`occurence` | `bigint(20) unsigned` | NO |  | `5184000` |  | Delay in minutes between occurences of the event; non-negative numeric value |
| <a id="col-length"></a>`length` | `bigint(20) unsigned` | NO |  | `2592000` |  | Length in minutes of the event; non-negative numeric value |
| <a id="col-holiday"></a>`holiday` | `mediumint(8) unsigned` | NO |  | `0` |  | Client side holiday id; non-negative numeric value |
| <a id="col-description"></a>`description` | `varchar(255)` | YES |  | `NULL` |  | Description of the event displayed in console; text/string data; script id or script name |
| <a id="col-hardcoded"></a>`hardcoded` | `tinyint(4)` | NO |  | `0` |  | numeric value |
| <a id="col-disabled"></a>`disabled` | `tinyint(4)` | NO |  | `0` |  | numeric value |
| <a id="col-required-phase"></a>`required_phase` | `tinyint(4)` | NO |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `start_time`

time/delay value; confirm unit in server usage.

### `end_time`

time/delay value; confirm unit in server usage.

### `occurence`

non-negative numeric value.

### `length`

non-negative numeric value.

### `holiday`

non-negative numeric value.

### `description`

text/string data; script id or script name.

### `hardcoded`

numeric value.

### `disabled`

numeric value.

### `required_phase`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

