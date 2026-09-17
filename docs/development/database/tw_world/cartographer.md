---
layout: default
title: cartographer
---

# cartographer

list of all areas that must be explored to gain the cartographer title

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 1 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-area-id"></a>`area_id` | `int(10) unsigned` | NO | `PRI` |  |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `area_id`

non-negative numeric value.

References: [`area_template`](area_template.md).`entry`.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `area_id` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `area_id` | [`area_template`](area_template.md).`entry` | heuristic | inferred from column name |

