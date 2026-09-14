---
layout: default
title: creature_movement
---

# creature_movement

Creature System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 9 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(10) unsigned` | NO | `PRI` |  |  | Creature GUID; non-negative numeric value; identifier column |
| <a id="col-point"></a>`point` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-position-x"></a>`position_x` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-position-y"></a>`position_y` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-position-z"></a>`position_z` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-orientation"></a>`orientation` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-waittime"></a>`waittime` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-wander-distance"></a>`wander_distance` | `float unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-script-id"></a>`script_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; script id or script name |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

References: [`creature`](creature.md).`guid`.

### `point`

non-negative numeric value.

### `position_x`

numeric value; world coordinate or orientation.

### `position_y`

numeric value; world coordinate or orientation.

### `position_z`

numeric value; world coordinate or orientation.

### `orientation`

numeric value; world coordinate or orientation.

### `waittime`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `wander_distance`

non-negative numeric value.

### `script_id`

non-negative numeric value; script id or script name.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id`, `point` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `id` | [`creature`](creature.md).`guid` | explicit | spawn movement path |

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`creature_movement_scripts`](creature_movement_scripts.md).`id` | `id` | explicit | movement script path |

