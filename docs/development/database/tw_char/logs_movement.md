---
layout: default
title: logs_movement
---

# logs_movement

Character database table `logs_movement`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 9 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-account"></a>`account` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value; identifier column |
| <a id="col-posx"></a>`posx` | `float` | NO |  |  |  | numeric value |
| <a id="col-posy"></a>`posy` | `float` | NO |  |  |  | numeric value |
| <a id="col-posz"></a>`posz` | `float` | NO |  |  |  | numeric value |
| <a id="col-map"></a>`map` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-desyncms"></a>`desyncMs` | `int(11)` | NO |  |  |  | numeric value |
| <a id="col-desyncdist"></a>`desyncDist` | `float` | NO |  |  |  | numeric value |
| <a id="col-cheats"></a>`cheats` | `varchar(50)` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `account`

non-negative numeric value.

### `guid`

non-negative numeric value; identifier column.

### `posx`

numeric value.

### `posy`

numeric value.

### `posz`

numeric value.

### `map`

non-negative numeric value.

References: [`map_template`](../tw_world/map_template.md).`entry`.

### `desyncMs`

numeric value.

### `desyncDist`

numeric value.

### `cheats`

text/string data.

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `map` | [`map_template`](../tw_world/map_template.md).`entry` | heuristic | inferred from column name |
