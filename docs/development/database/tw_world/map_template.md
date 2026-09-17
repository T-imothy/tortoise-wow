---
layout: default
title: map_template
---

# map_template

World database table `map_template`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 12 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `smallint(5) unsigned` | NO | `PRI` |  |  | non-negative numeric value; identifier column |
| <a id="col-parent"></a>`parent` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-map-type"></a>`map_type` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-linked-zone"></a>`linked_zone` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-player-limit"></a>`player_limit` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reset-delay"></a>`reset_delay` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-time-offset"></a>`time_offset` | `int(11)` | NO |  | `0` |  | seconds; numeric value; time/delay value; confirm unit in server usage |
| <a id="col-ghost-entrance-map"></a>`ghost_entrance_map` | `smallint(6)` | NO |  | `-1` |  | numeric value |
| <a id="col-ghost-entrance-x"></a>`ghost_entrance_x` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-ghost-entrance-y"></a>`ghost_entrance_y` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-map-name"></a>`map_name` | `varchar(128)` | NO |  | `''` |  | text/string data |
| <a id="col-script-name"></a>`script_name` | `varchar(128)` | NO |  | `''` |  | text/string data; script id or script name |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `parent`

non-negative numeric value.

### `map_type`

non-negative numeric value.

### `linked_zone`

non-negative numeric value.

### `player_limit`

non-negative numeric value.

### `reset_delay`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `time_offset`

numeric value; time/delay value; confirm unit in server usage.

### `ghost_entrance_map`

numeric value.

### `ghost_entrance_x`

numeric value.

### `ghost_entrance_y`

numeric value.

### `map_name`

text/string data.

### `script_name`

text/string data; script id or script name.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`battleground_events`](battleground_events.md).`map` | `entry` | heuristic | inferred from column name |
| [`creature_linking_template`](creature_linking_template.md).`map` | `entry` | heuristic | inferred from column name |
| [`game_tele`](game_tele.md).`map` | `entry` | heuristic | inferred from column name |
| [`playercreateinfo`](playercreateinfo.md).`map` | `entry` | heuristic | inferred from column name |
| [`creature`](creature.md).`map` | `entry` | explicit | map id |
| [`gameobject`](gameobject.md).`map` | `entry` | explicit | map id |
| [`gm_tickets`](gm_tickets.md).`mapId` | `entry` | heuristic | inferred from column name |
| [`area_template`](area_template.md).`map_id` | `entry` | heuristic | inferred from column name |
| [`areatrigger_template`](areatrigger_template.md).`map_id` | `entry` | heuristic | inferred from column name |
| [`custom_graveyards`](custom_graveyards.md).`map_id` | `entry` | heuristic | inferred from column name |
| [`instance_buff_removal`](instance_buff_removal.md).`map_id` | `entry` | heuristic | inferred from column name |
| [`map_loot_disabled`](map_loot_disabled.md).`map_id` | `entry` | heuristic | inferred from column name |
| [`taxi_nodes`](taxi_nodes.md).`map_id` | `entry` | heuristic | inferred from column name |

