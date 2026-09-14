---
layout: default
title: pool_pool
---

# pool_pool

World database table `pool_pool`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 5 | latin1 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-pool-id"></a>`pool_id` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-mother-pool"></a>`mother_pool` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-chance"></a>`chance` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-description"></a>`description` | `varchar(255)` | NO |  |  |  | text/string data; script id or script name |
| <a id="col-flags"></a>`flags` | `int(10) unsigned` | NO |  | `0` |  | FLAG_SPAWN_ENABLE_IF_WORLD_POP_OVER_BLIZZLIKE = 1; non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses PoolObjectFlags mask values |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `pool_id`

non-negative numeric value.

References: [`pool_template`](pool_template.md).`entry`.

### `mother_pool`

non-negative numeric value.

### `chance`

numeric value.

### `description`

text/string data; script id or script name.

### `flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `PoolObjectFlags` (mask) from `src/game/Maps/Pool/PoolManager.h enum ObjectFlags`.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `pool_id` |
| KEY | `pool_idx` | `mother_pool` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `pool_id` | [`pool_template`](pool_template.md).`entry` | heuristic | inferred from column name |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `PoolObjectFlags` | mask | [`flags`](#col-flags) | `src/game/Maps/Pool/PoolManager.h enum ObjectFlags` | 1 |

### Possible Values

Used by: [`flags`](#col-flags)

#### `PoolObjectFlags`

Kind: `mask`

Source: `src/game/Maps/Pool/PoolManager.h enum ObjectFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `FLAG_SPAWN_ENABLE_IF_WORLD_POP_OVER_BLIZZLIKE` | Flag Spawn Enable If World Pop Over Blizzlike |
