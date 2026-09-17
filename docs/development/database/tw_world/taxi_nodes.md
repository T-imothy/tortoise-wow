---
layout: default
title: taxi_nodes
---

# taxi_nodes

World database table `taxi_nodes`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 8 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `smallint(5) unsigned` | NO | `PRI` |  |  | non-negative numeric value; identifier column |
| <a id="col-map-id"></a>`map_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-x"></a>`x` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-y"></a>`y` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-z"></a>`z` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-name"></a>`name` | `varchar(256)` | NO |  | `''` |  | text/string data |
| <a id="col-mount-creature-id1"></a>`mount_creature_id1` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-mount-creature-id2"></a>`mount_creature_id2` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |

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

### `name`

text/string data.

### `mount_creature_id1`

non-negative numeric value.

### `mount_creature_id2`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `map_id` | [`map_template`](map_template.md).`entry` | heuristic | inferred from column name |

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`locales_taxi_node`](locales_taxi_node.md).`entry` | `entry` | explicit | localized row |

