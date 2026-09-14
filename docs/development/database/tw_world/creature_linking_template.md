---
layout: default
title: creature_linking_template
---

# creature_linking_template

Creature Linking System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 5 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | creature_template.entry of the slave mob that is linked; non-negative numeric value; identifier column |
| <a id="col-map"></a>`map` | `smallint(5) unsigned` | NO | `PRI` | `0` |  | Id of map of the mobs; non-negative numeric value |
| <a id="col-master-entry"></a>`master_entry` | `mediumint(8) unsigned` | NO |  | `0` |  | master to trigger events; non-negative numeric value |
| <a id="col-flag"></a>`flag` | `mediumint(8) unsigned` | NO |  | `0` |  | flag - describing what should happen when; non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses CreatureLinkingFlags mask values |
| <a id="col-search-range"></a>`search_range` | `mediumint(8) unsigned` | NO |  | `0` |  | search_range - describing in which range (spawn-coords) master and slave are linked together; non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `map`

non-negative numeric value.

References: [`map_template`](map_template.md).`entry`.

### `master_entry`

non-negative numeric value.

### `flag`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `CreatureLinkingFlags` (mask) from `src/game/Group/CreatureLinkingMgr.h enum CreatureLinkingFlags`.

### `search_range`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry`, `map` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `map` | [`map_template`](map_template.md).`entry` | heuristic | inferred from column name |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `CreatureLinkingFlags` | mask | [`flag`](#col-flag) | `src/game/Group/CreatureLinkingMgr.h enum CreatureLinkingFlags` | 15 |

### Possible Values

Used by: [`flag`](#col-flag)

#### `CreatureLinkingFlags`

Kind: `mask`

Source: `src/game/Group/CreatureLinkingMgr.h enum CreatureLinkingFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `FLAG_AGGRO_ON_AGGRO` | Flag Aggro On Aggro |
| `2` | `0x2` | `FLAG_TO_AGGRO_ON_AGGRO` | Flag To Aggro On Aggro |
| `4` | `0x4` | `FLAG_RESPAWN_ON_EVADE` | Flag Respawn On Evade |
| `8` | `0x8` | `FLAG_TO_RESPAWN_ON_EVADE` | Flag To Respawn On Evade |
| `4096` | `0x1000` | `FLAG_DESPAWN_ON_EVADE` | Flag Despawn On Evade |
| `16` | `0x10` | `FLAG_DESPAWN_ON_DEATH` | Flag Despawn On Death |
| `32` | `0x20` | `FLAG_SELFKILL_ON_DEATH` | Flag Selfkill On Death |
| `64` | `0x40` | `FLAG_RESPAWN_ON_DEATH` | Flag Respawn On Death |
| `128` | `0x80` | `FLAG_RESPAWN_ON_RESPAWN` | Flag Respawn On Respawn |
| `256` | `0x100` | `FLAG_DESPAWN_ON_RESPAWN` | Flag Despawn On Respawn |
| `512` | `0x200` | `FLAG_FOLLOW` | Flag Follow |
| `8192` | `0x2000` | `FLAG_DESPAWN_ON_DESPAWN` | Flag Despawn On Despawn |
| `1024` | `0x400` | `FLAG_CANT_SPAWN_IF_BOSS_DEAD` | Flag Cant Spawn If Boss Dead |
| `2048` | `0x800` | `FLAG_CANT_SPAWN_IF_BOSS_ALIVE` | Flag Cant Spawn If Boss Alive |
| `16384` | `0x4000` | `LINKING_FLAG_INVALID` | TODO adjust when other flags are implemented |
