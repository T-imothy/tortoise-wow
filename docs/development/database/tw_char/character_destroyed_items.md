---
layout: default
title: character_destroyed_items
---

# character_destroyed_items

items that players have thrown away

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 4 | latin1 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-player-guid"></a>`player_guid` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-item-entry"></a>`item_entry` | `mediumint(8) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-stack-count"></a>`stack_count` | `mediumint(8) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-time"></a>`time` | `bigint(20) unsigned` | NO |  |  |  | non-negative numeric value; time/delay value; confirm unit in server usage |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `player_guid`

non-negative numeric value.

### `item_entry`

non-negative numeric value.

### `stack_count`

non-negative numeric value.

### `time`

non-negative numeric value; time/delay value; confirm unit in server usage.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| KEY | `player_guid` | `player_guid` |
