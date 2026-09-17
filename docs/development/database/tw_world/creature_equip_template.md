---
layout: default
title: creature_equip_template
---

# creature_equip_template

Creature System (Equipment)

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | Unique entry; non-negative numeric value; identifier column |
| <a id="col-equipentry1"></a>`equipentry1` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-equipentry2"></a>`equipentry2` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-equipentry3"></a>`equipentry3` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `equipentry1`

non-negative numeric value.

### `equipentry2`

non-negative numeric value.

### `equipentry3`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`creature_template`](creature_template.md).`equipment_id` | `entry` | explicit | equipment template |

