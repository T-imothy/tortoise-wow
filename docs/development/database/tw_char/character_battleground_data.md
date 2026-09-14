---
layout: default
title: character_battleground_data
---

# character_battleground_data

Player System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 8 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | Global Unique Identifier; non-negative numeric value; identifier column |
| <a id="col-instance-id"></a>`instance_id` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-team"></a>`team` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Team enum values |
| <a id="col-join-x"></a>`join_x` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-join-y"></a>`join_y` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-join-z"></a>`join_z` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-join-o"></a>`join_o` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-join-map"></a>`join_map` | `int(11)` | NO |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `instance_id`

non-negative numeric value.

References: [`instance`](instance.md).`entry`.

### `team`

non-negative numeric value.

Value set: `Team` (enum) from `src/game/SharedDefines.h enum Team`.

### `join_x`

numeric value.

### `join_y`

numeric value.

### `join_z`

numeric value.

### `join_o`

numeric value.

### `join_map`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `instance_id` | [`instance`](instance.md).`entry` | heuristic | inferred from column name |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `Team` | enum | [`team`](#col-team) | `src/game/SharedDefines.h enum Team` | 4 |

### Possible Values

Used by: [`team`](#col-team)

#### `Team`

Kind: `enum`

Source: `src/game/SharedDefines.h enum Team`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `TEAM_NONE` | used when team value unknown or not set, 0 is also meaning that can be used !team check |
| `1` | `0x1` | `TEAM_CROSSFACTION` | Team Crossfaction |
| `67` | `0x43` | `HORDE` | Horde |
| `469` | `0x1D5` | `ALLIANCE` | Alliance |
