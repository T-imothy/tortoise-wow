---
layout: default
title: areatrigger_teleport
---

# areatrigger_teleport

Trigger System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 11 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | Identifier; non-negative numeric value; identifier column |
| <a id="col-name"></a>`name` | `varchar(64)` | NO |  | `''` |  | text/string data |
| <a id="col-message"></a>`message` | `varchar(128)` | NO |  | `''` |  | text/string data |
| <a id="col-required-level"></a>`required_level` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-required-condition"></a>`required_condition` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-required-phase"></a>`required_phase` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-target-map"></a>`target_map` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-target-position-x"></a>`target_position_x` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-target-position-y"></a>`target_position_y` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-target-position-z"></a>`target_position_z` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-target-orientation"></a>`target_orientation` | `float` | NO |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `name`

text/string data.

### `message`

text/string data.

### `required_level`

non-negative numeric value.

### `required_condition`

non-negative numeric value.

### `required_phase`

non-negative numeric value.

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
| PRIMARY | `PRIMARY` | `id` |

