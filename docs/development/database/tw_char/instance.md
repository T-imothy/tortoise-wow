---
layout: default
title: instance
---

# instance

Character database table `instance`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-map"></a>`map` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-resettime"></a>`resettime` | `bigint(20)` | NO |  | `0` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-data"></a>`data` | `longtext` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `map`

non-negative numeric value.

References: [`map_template`](../tw_world/map_template.md).`entry`.

### `resettime`

numeric value; time/delay value; confirm unit in server usage.

### `data`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |
| KEY | `idx_map` | `map` |
| KEY | `idx_resettime` | `resettime` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `map` | [`map_template`](../tw_world/map_template.md).`entry` | heuristic | inferred from column name |

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`character_instance`](character_instance.md).`instance` | `entry` | heuristic | inferred from column name |
| [`corpse`](corpse.md).`instance` | `entry` | heuristic | inferred from column name |
| [`creature_respawn`](creature_respawn.md).`instance` | `entry` | heuristic | inferred from column name |
| [`gameobject_respawn`](gameobject_respawn.md).`instance` | `entry` | heuristic | inferred from column name |
| [`group_instance`](group_instance.md).`instance` | `entry` | heuristic | inferred from column name |
| [`character_battleground_data`](character_battleground_data.md).`instance_id` | `entry` | heuristic | inferred from column name |
