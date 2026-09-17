---
layout: default
title: areatrigger_template
---

# areatrigger_template

World database table `areatrigger_template`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 10 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `smallint(5) unsigned` | NO | `PRI` |  |  | non-negative numeric value; identifier column |
| <a id="col-map-id"></a>`map_id` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-x"></a>`x` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-y"></a>`y` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-z"></a>`z` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-radius"></a>`radius` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-box-x"></a>`box_x` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-box-y"></a>`box_y` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-box-z"></a>`box_z` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-box-orientation"></a>`box_orientation` | `float` | NO |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `map_id`

non-negative numeric value.

References: [`map_template`](map_template.md).`entry`.

### `x`

numeric value; world coordinate or orientation.

### `y`

numeric value; world coordinate or orientation.

### `z`

numeric value; world coordinate or orientation.

### `radius`

numeric value.

### `box_x`

numeric value.

### `box_y`

numeric value.

### `box_z`

numeric value.

### `box_orientation`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `map_id` | [`map_template`](map_template.md).`entry` | heuristic | inferred from column name |

