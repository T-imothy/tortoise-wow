---
layout: default
title: game_graveyard_zone
---

# game_graveyard_zone

Trigger System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 3 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-ghost-zone"></a>`ghost_zone` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-faction"></a>`faction` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `ghost_zone`

non-negative numeric value.

References: [`area_template`](area_template.md).`entry`.

### `faction`

non-negative numeric value.

References: [`faction`](faction.md).`entry`, [`faction_template`](faction_template.md).`entry`.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id`, `ghost_zone` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `ghost_zone` | [`area_template`](area_template.md).`entry` | explicit | zone |
| `faction` | [`faction`](faction.md).`entry` | heuristic | inferred from column name |
| `faction` | [`faction_template`](faction_template.md).`entry` | heuristic | inferred from column name |

