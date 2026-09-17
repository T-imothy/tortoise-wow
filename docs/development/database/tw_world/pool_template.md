---
layout: default
title: pool_template
---

# pool_template

World database table `pool_template`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 5 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | Pool entry; non-negative numeric value; identifier column |
| <a id="col-max-limit"></a>`max_limit` | `int(10) unsigned` | NO |  | `0` |  | Max number of objects (0) is no limit; non-negative numeric value |
| <a id="col-description"></a>`description` | `varchar(255)` | NO |  |  |  | text/string data; script id or script name |
| <a id="col-flags"></a>`flags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses PoolFlags mask values |
| <a id="col-instance"></a>`instance` | `mediumint(9)` | NO |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `max_limit`

non-negative numeric value.

### `description`

text/string data; script id or script name.

### `flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `PoolFlags` (mask) from `src/game/Maps/Pool/PoolManager.h enum PoolFlags`.

### `instance`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`pool_creature`](pool_creature.md).`pool_entry` | `entry` | heuristic | inferred from column name |
| [`pool_creature_template`](pool_creature_template.md).`pool_entry` | `entry` | heuristic | inferred from column name |
| [`pool_gameobject`](pool_gameobject.md).`pool_entry` | `entry` | heuristic | inferred from column name |
| [`pool_gameobject_template`](pool_gameobject_template.md).`pool_entry` | `entry` | heuristic | inferred from column name |
| [`pool_pool`](pool_pool.md).`pool_id` | `entry` | heuristic | inferred from column name |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `PoolFlags` | mask | [`flags`](#col-flags) | `src/game/Maps/Pool/PoolManager.h enum PoolFlags` | 2 |

### Possible Values

Used by: [`flags`](#col-flags)

#### `PoolFlags`

Kind: `mask`

Source: `src/game/Maps/Pool/PoolManager.h enum PoolFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `POOL_FLAG_AUTO_SPAWN` | Pool Flag Auto Spawn |
| `2` | `0x2` | `POOL_FLAG_MAXLIMIT_SCALING_LINEAR` | Pool Flag Maxlimit Scaling Linear |
