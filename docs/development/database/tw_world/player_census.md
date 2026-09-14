---
layout: default
title: player_census
---

# player_census

World database table `player_census`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 5 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | non-negative numeric value; identifier column |
| <a id="col-alliance-players"></a>`alliance_players` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-horde-players"></a>`horde_players` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-total-players"></a>`total_players` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-date-time"></a>`date_time` | `datetime` | NO |  |  |  | time/delay value; confirm unit in server usage |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `alliance_players`

non-negative numeric value.

### `horde_players`

non-negative numeric value.

### `total_players`

non-negative numeric value.

### `date_time`

time/delay value; confirm unit in server usage.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

