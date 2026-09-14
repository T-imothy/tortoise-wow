---
layout: default
title: character_homebind
---

# character_homebind

Player System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 6 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | Global Unique Identifier; non-negative numeric value; identifier column |
| <a id="col-map"></a>`map` | `int(10) unsigned` | NO |  | `0` |  | Map Identifier; non-negative numeric value |
| <a id="col-zone"></a>`zone` | `int(10) unsigned` | NO |  | `0` |  | Zone Identifier; non-negative numeric value |
| <a id="col-position-x"></a>`position_x` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-position-y"></a>`position_y` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-position-z"></a>`position_z` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `map`

non-negative numeric value.

References: [`map_template`](../tw_world/map_template.md).`entry`.

### `zone`

non-negative numeric value.

References: [`area_template`](../tw_world/area_template.md).`entry`.

### `position_x`

numeric value; world coordinate or orientation.

### `position_y`

numeric value; world coordinate or orientation.

### `position_z`

numeric value; world coordinate or orientation.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `zone` | [`area_template`](../tw_world/area_template.md).`entry` | heuristic | inferred from column name |
| `map` | [`map_template`](../tw_world/map_template.md).`entry` | heuristic | inferred from column name |
