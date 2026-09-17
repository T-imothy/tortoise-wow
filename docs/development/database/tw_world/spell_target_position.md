---
layout: default
title: spell_target_position
---

# spell_target_position

Spell System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 6 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | Identifier; non-negative numeric value; identifier column |
| <a id="col-target-map"></a>`target_map` | `smallint(5) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-target-position-x"></a>`target_position_x` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-target-position-y"></a>`target_position_y` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-target-position-z"></a>`target_position_z` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-target-orientation"></a>`target_orientation` | `float` | NO |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `target_map`

non-negative numeric value.

### `target_position_x`

numeric value.

### `target_position_y`

numeric value.

### `target_position_z`

numeric value.

### `target_orientation`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id`, `target_map` |

