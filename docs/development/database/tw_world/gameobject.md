---
layout: default
title: gameobject
---

# gameobject

Gameobject System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 17 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | Global Unique Identifier; non-negative numeric value; identifier column |
| <a id="col-id"></a>`id` | `mediumint(8) unsigned` | NO |  | `0` |  | Gameobject Identifier; non-negative numeric value; identifier column |
| <a id="col-map"></a>`map` | `smallint(5) unsigned` | NO |  | `0` |  | Map Identifier; non-negative numeric value |
| <a id="col-position-x"></a>`position_x` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-position-y"></a>`position_y` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-position-z"></a>`position_z` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-orientation"></a>`orientation` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-rotation0"></a>`rotation0` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-rotation1"></a>`rotation1` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-rotation2"></a>`rotation2` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-rotation3"></a>`rotation3` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-spawntimesecsmin"></a>`spawntimesecsmin` | `int(11)` | NO |  | `0` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-spawntimesecsmax"></a>`spawntimesecsmax` | `int(11)` | NO |  | `0` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-animprogress"></a>`animprogress` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-state"></a>`state` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses GOState enum values |
| <a id="col-spawn-flags"></a>`spawn_flags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses SpawnFlags mask values |
| <a id="col-visibility-mod"></a>`visibility_mod` | `float` | YES |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `id`

non-negative numeric value; identifier column.

References: [`gameobject_template`](gameobject_template.md).`entry`.

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

### `rotation0`

numeric value.

### `rotation1`

numeric value.

### `rotation2`

numeric value.

### `rotation3`

numeric value.

### `spawntimesecsmin`

numeric value; time/delay value; confirm unit in server usage.

### `spawntimesecsmax`

numeric value; time/delay value; confirm unit in server usage.

### `animprogress`

non-negative numeric value.

### `state`

non-negative numeric value.

Value set: `GOState` (enum) from `src/game/Objects/GameObject.h enum GOState`.

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
| `id` | [`gameobject_template`](gameobject_template.md).`entry` | explicit | spawn uses template |
| `map` | [`map_template`](map_template.md).`entry` | explicit | map id |

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`locales_gameobject`](locales_gameobject.md).`entry` | `entry` | explicit | localized row |
| [`game_event_gameobject`](game_event_gameobject.md).`guid` | `guid` | explicit | event gameobject spawn |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `GOState` | enum | [`state`](#col-state) | `src/game/Objects/GameObject.h enum GOState` | 3 |
| `SpawnFlags` | mask | [`spawn_flags`](#col-spawn-flags) | `src/game/Objects/Object.h spawn flag constants` | 9 |

### Possible Values

Used by: [`state`](#col-state)

#### `GOState`

Kind: `enum`

Source: `src/game/Objects/GameObject.h enum GOState`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `GO_STATE_ACTIVE` | show in world as used and not reset (closed door open) |
| `1` | `0x1` | `GO_STATE_READY` | show in world as ready (closed door close) |
| `2` | `0x2` | `GO_STATE_ACTIVE_ALTERNATIVE` | show in world as used in alt way and not reset (closed door open by cannon fire) |

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
