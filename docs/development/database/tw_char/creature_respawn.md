---
layout: default
title: creature_respawn
---

# creature_respawn

Grid Loading System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 4 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | Global Unique Identifier; non-negative numeric value; identifier column |
| <a id="col-respawntime"></a>`respawntime` | `bigint(20)` | NO |  | `0` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-instance"></a>`instance` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-map"></a>`map` | `int(10) unsigned` | YES |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `respawntime`

numeric value; time/delay value; confirm unit in server usage.

### `instance`

non-negative numeric value.

References: [`instance`](instance.md).`entry`.

### `map`

non-negative numeric value.

References: [`map_template`](../tw_world/map_template.md).`entry`.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid`, `instance` |
| KEY | `idx_instance` | `instance` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `instance` | [`instance`](instance.md).`entry` | heuristic | inferred from column name |
| `map` | [`map_template`](../tw_world/map_template.md).`entry` | heuristic | inferred from column name |
