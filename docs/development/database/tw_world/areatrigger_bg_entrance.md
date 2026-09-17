---
layout: default
title: areatrigger_bg_entrance
---

# areatrigger_bg_entrance

World database table `areatrigger_bg_entrance`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 9 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | Identifier; non-negative numeric value; identifier column |
| <a id="col-name"></a>`name` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-team"></a>`team` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Team enum values |
| <a id="col-bg-template"></a>`bg_template` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-exit-map"></a>`exit_map` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-exit-position-x"></a>`exit_position_x` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-exit-position-y"></a>`exit_position_y` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-exit-position-z"></a>`exit_position_z` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-exit-orientation"></a>`exit_orientation` | `float` | NO |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `name`

text/string data.

### `team`

non-negative numeric value.

Value set: `Team` (enum) from `src/game/SharedDefines.h enum Team`.

### `bg_template`

non-negative numeric value.

### `exit_map`

non-negative numeric value.

### `exit_position_x`

numeric value.

### `exit_position_y`

numeric value.

### `exit_position_z`

numeric value.

### `exit_orientation`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

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
