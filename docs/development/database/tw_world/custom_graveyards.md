---
layout: default
title: custom_graveyards
---

# custom_graveyards

Custom graveyards

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 16 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | Identifier; non-negative numeric value; identifier column |
| <a id="col-name"></a>`name` | `varchar(64)` | NO |  | `''` |  | text/string data |
| <a id="col-map-id"></a>`map_id` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-zone-id"></a>`zone_id` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-area-id"></a>`area_id` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-max-level"></a>`max_level` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-map-gy-alliance"></a>`map_gy_alliance` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-gy-x-alliance"></a>`gy_x_alliance` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-gy-y-alliance"></a>`gy_y_alliance` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-gy-z-alliance"></a>`gy_z_alliance` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-orientation-alliance"></a>`orientation_alliance` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-map-gy-horde"></a>`map_gy_horde` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-gy-x-horde"></a>`gy_x_horde` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-gy-y-horde"></a>`gy_y_horde` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-gy-z-horde"></a>`gy_z_horde` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-orientation-horde"></a>`orientation_horde` | `float` | NO |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `name`

text/string data.

### `map_id`

non-negative numeric value.

References: [`map_template`](map_template.md).`entry`.

### `zone_id`

non-negative numeric value.

References: [`area_template`](area_template.md).`entry`.

### `area_id`

non-negative numeric value.

References: [`area_template`](area_template.md).`entry`.

### `max_level`

non-negative numeric value.

### `map_gy_alliance`

non-negative numeric value.

### `gy_x_alliance`

numeric value.

### `gy_y_alliance`

numeric value.

### `gy_z_alliance`

numeric value.

### `orientation_alliance`

numeric value.

### `map_gy_horde`

non-negative numeric value.

### `gy_x_horde`

numeric value.

### `gy_y_horde`

numeric value.

### `gy_z_horde`

numeric value.

### `orientation_horde`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `area_id` | [`area_template`](area_template.md).`entry` | heuristic | inferred from column name |
| `zone_id` | [`area_template`](area_template.md).`entry` | heuristic | inferred from column name |
| `map_id` | [`map_template`](map_template.md).`entry` | heuristic | inferred from column name |

