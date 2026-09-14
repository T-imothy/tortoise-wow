---
layout: default
title: corpse
---

# corpse

Death System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 10 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | Global Unique Identifier; non-negative numeric value; identifier column |
| <a id="col-player"></a>`player` | `int(10) unsigned` | NO |  | `0` |  | Character Global Unique Identifier; non-negative numeric value |
| <a id="col-position-x"></a>`position_x` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-position-y"></a>`position_y` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-position-z"></a>`position_z` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-orientation"></a>`orientation` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-map"></a>`map` | `int(10) unsigned` | NO |  | `0` |  | Map Identifier; non-negative numeric value |
| <a id="col-time"></a>`time` | `bigint(20) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-corpse-type"></a>`corpse_type` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-instance"></a>`instance` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `player`

non-negative numeric value.

### `position_x`

numeric value; world coordinate or orientation.

### `position_y`

numeric value; world coordinate or orientation.

### `position_z`

numeric value; world coordinate or orientation.

### `orientation`

numeric value; world coordinate or orientation.

### `map`

non-negative numeric value.

References: [`map_template`](../tw_world/map_template.md).`entry`.

### `time`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `corpse_type`

non-negative numeric value.

### `instance`

non-negative numeric value.

References: [`instance`](instance.md).`entry`.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid` |
| KEY | `idx_type` | `corpse_type` |
| KEY | `idx_instance` | `instance` |
| KEY | `idx_player` | `player` |
| KEY | `idx_time` | `time` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `instance` | [`instance`](instance.md).`entry` | heuristic | inferred from column name |
| `map` | [`map_template`](../tw_world/map_template.md).`entry` | heuristic | inferred from column name |
