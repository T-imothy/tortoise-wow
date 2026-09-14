---
layout: default
title: creature
---

# creature

Creature System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 18 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | Global Unique Identifier; non-negative numeric value; identifier column |
| <a id="col-id"></a>`id` | `mediumint(8) unsigned` | NO |  | `0` |  | Creature Template Id; non-negative numeric value; identifier column |
| <a id="col-id2"></a>`id2` | `mediumint(8) unsigned` | NO |  | `0` |  | Creature Template Id; non-negative numeric value |
| <a id="col-id3"></a>`id3` | `mediumint(8) unsigned` | NO |  | `0` |  | Creature Template Id; non-negative numeric value |
| <a id="col-id4"></a>`id4` | `mediumint(8) unsigned` | NO |  | `0` |  | Creature Template Id; non-negative numeric value |
| <a id="col-map"></a>`map` | `smallint(5) unsigned` | NO |  | `0` |  | Map Identifier; non-negative numeric value |
| <a id="col-position-x"></a>`position_x` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-position-y"></a>`position_y` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-position-z"></a>`position_z` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-orientation"></a>`orientation` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-spawntimesecsmin"></a>`spawntimesecsmin` | `int(10) unsigned` | NO |  | `120` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-spawntimesecsmax"></a>`spawntimesecsmax` | `int(10) unsigned` | NO |  | `120` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-wander-distance"></a>`wander_distance` | `float` | NO |  | `5` |  | numeric value |
| <a id="col-health-percent"></a>`health_percent` | `float` | NO |  | `100` |  | numeric value |
| <a id="col-mana-percent"></a>`mana_percent` | `float unsigned` | NO |  | `100` |  | non-negative numeric value |
| <a id="col-movement-type"></a>`movement_type` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses MovementGeneratorType enum values |
| <a id="col-spawn-flags"></a>`spawn_flags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses SpawnFlags mask values |
| <a id="col-visibility-mod"></a>`visibility_mod` | `float` | YES |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `id`

non-negative numeric value; identifier column.

References: [`creature_template`](creature_template.md).`entry`.

### `id2`

non-negative numeric value.

### `id3`

non-negative numeric value.

### `id4`

non-negative numeric value.

### `map`

non-negative numeric value.

References: [`map_template`](map_template.md).`entry`.

### `position_x`

numeric value; world coordinate or orientation.

### `position_y`

numeric value; world coordinate or orientation.

### `position_z`

numeric value; world coordinate or orientation.

### `orientation`

numeric value; world coordinate or orientation.

### `spawntimesecsmin`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `spawntimesecsmax`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `wander_distance`

numeric value.

### `health_percent`

numeric value.

### `mana_percent`

non-negative numeric value.

### `movement_type`

non-negative numeric value.

Value set: `MovementGeneratorType` (enum) from `src/game/Movement/MotionMaster.h enum MovementGeneratorType`.

### `spawn_flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `SpawnFlags` (mask) from `src/game/Objects/Object.h spawn flag constants`.

### `visibility_mod`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid` |
| KEY | `idx_map` | `map` |
| KEY | `idx_id` | `id` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `id` | [`creature_template`](creature_template.md).`entry` | explicit | spawn uses template |
| `map` | [`map_template`](map_template.md).`entry` | explicit | map id |

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`pet_levelstats`](pet_levelstats.md).`creature_entry` | `entry` | heuristic | inferred from column name |
| [`creature_ai_events`](creature_ai_events.md).`creature_id` | `entry` | heuristic | inferred from column name |
| [`creature_onkill_reputation`](creature_onkill_reputation.md).`creature_id` | `entry` | heuristic | inferred from column name |
| [`script_escort_data`](script_escort_data.md).`creature_id` | `entry` | heuristic | inferred from column name |
| [`locales_creature`](locales_creature.md).`entry` | `entry` | explicit | localized row |
| [`game_event_creature_data`](game_event_creature_data.md).`guid` | `guid` | explicit | event creature data |
| [`game_event_creature`](game_event_creature.md).`guid` | `guid` | explicit | event creature spawn |
| [`creature_addon`](creature_addon.md).`guid` | `guid` | explicit | spawn addon |
| [`creature_movement`](creature_movement.md).`id` | `guid` | explicit | spawn movement path |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `MovementGeneratorType` | enum | [`movement_type`](#col-movement-type) | `src/game/Movement/MotionMaster.h enum MovementGeneratorType` | 18 |
| `SpawnFlags` | mask | [`spawn_flags`](#col-spawn-flags) | `src/game/Objects/Object.h spawn flag constants` | 9 |

### Possible Values

Used by: [`movement_type`](#col-movement-type)

#### `MovementGeneratorType`

Kind: `enum`

Source: `src/game/Movement/MotionMaster.h enum MovementGeneratorType`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `IDLE_MOTION_TYPE` | IdleMovementGenerator.h |
| `1` | `0x1` | `RANDOM_MOTION_TYPE` | RandomMovementGenerator.h |
| `2` | `0x2` | `WAYPOINT_MOTION_TYPE` | WaypointMovementGenerator.h |
| `4` | `0x4` | `CONFUSED_MOTION_TYPE` | ConfusedMovementGenerator.h |
| `5` | `0x5` | `CHASE_MOTION_TYPE` | TargetedMovementGenerator.h |
| `6` | `0x6` | `HOME_MOTION_TYPE` | HomeMovementGenerator.h |
| `7` | `0x7` | `FLIGHT_MOTION_TYPE` | WaypointMovementGenerator.h |
| `8` | `0x8` | `POINT_MOTION_TYPE` | PointMovementGenerator.h |
| `9` | `0x9` | `FLEEING_MOTION_TYPE` | FleeingMovementGenerator.h |
| `10` | `0xA` | `DISTRACT_MOTION_TYPE` | IdleMovementGenerator.h |
| `11` | `0xB` | `ASSISTANCE_MOTION_TYPE` | PointMovementGenerator.h (first part of flee for assistance) |
| `12` | `0xC` | `ASSISTANCE_DISTRACT_MOTION_TYPE` | IdleMovementGenerator.h (second part of flee for assistance) |
| `13` | `0xD` | `TIMED_FLEEING_MOTION_TYPE` | FleeingMovementGenerator.h (alt.second part of flee for assistance) |
| `14` | `0xE` | `FOLLOW_MOTION_TYPE` | TargetedMovementGenerator.h |
| `15` | `0xF` | `EFFECT_MOTION_TYPE` | Effect Motion Type |
| `16` | `0x10` | `PATROL_MOTION_TYPE` | Patrol Motion Type |
| `17` | `0x11` | `CHARGE_MOTION_TYPE` | Charge Motion Type |
| `18` | `0x12` | `DISTANCING_MOTION_TYPE` | Distancing Motion Type |

Used by: [`spawn_flags`](#col-spawn-flags)

#### `SpawnFlags`

Kind: `mask`

Source: `src/game/Objects/Object.h spawn flag constants`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `SPAWN_FLAG_ACTIVE` | Always active |
| `2` | `0x2` | `SPAWN_FLAG_DISABLED` | Spawn disabled |
| `4` | `0x4` | `SPAWN_FLAG_RANDOM_RESPAWN_TIME` | Random respawn time |
| `8` | `0x8` | `SPAWN_FLAG_DYNAMIC_RESPAWN_TIME` | Dynamic respawn time |
| `16` | `0x10` | `SPAWN_FLAG_FORCE_DYNAMIC_ELITE` | Force dynamic elite; creature only |
| `32` | `0x20` | `SPAWN_FLAG_EVADE_OUT_HOME_AREA` | Evade outside home area; creature only |
| `64` | `0x40` | `SPAWN_FLAG_NOT_VISIBLE` | Not visible; creature only |
| `128` | `0x80` | `SPAWN_FLAG_DEAD` | Spawn dead; creature only |
| `256` | `0x100` | `SPAWN_FLAG_NO_DYNAMIC_RESPAWN` | Disable dynamic respawn; creature only |
