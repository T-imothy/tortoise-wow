---
layout: default
title: dynamic_visibility_template
---

# dynamic_visibility_template

World database table `dynamic_visibility_template`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 5 | utf8mb4 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-area-id"></a>`area_id` | `int(10) unsigned` | NO | `PRI` |  |  | non-negative numeric value |
| <a id="col-min-vis-distance"></a>`min_vis_distance` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-max-vis-distance"></a>`max_vis_distance` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-decrease-tick-diff"></a>`decrease_tick_diff` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-increase-tick-diff"></a>`increase_tick_diff` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `area_id`

non-negative numeric value.

References: [`area_template`](area_template.md).`entry`.

### `min_vis_distance`

non-negative numeric value.

### `max_vis_distance`

non-negative numeric value.

### `decrease_tick_diff`

non-negative numeric value.

### `increase_tick_diff`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `area_id` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `area_id` | [`area_template`](area_template.md).`entry` | heuristic | inferred from column name |

