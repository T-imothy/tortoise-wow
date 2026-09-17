---
layout: default
title: script_escort_data
---

# script_escort_data

World database table `script_escort_data`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 3 | latin1 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-creature-id"></a>`creature_id` | `int(11)` | YES |  | `NULL` |  | numeric value |
| <a id="col-quest"></a>`quest` | `int(11)` | YES |  | `NULL` |  | numeric value |
| <a id="col-escort-faction"></a>`escort_faction` | `int(11)` | YES |  | `NULL` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `creature_id`

numeric value.

References: [`creature`](creature.md).`entry`, [`creature_template`](creature_template.md).`entry`.

### `quest`

numeric value.

References: [`quest_template`](quest_template.md).`entry`.

### `escort_faction`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| UNIQUE | `creature_id` | `creature_id` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `creature_id` | [`creature`](creature.md).`entry` | heuristic | inferred from column name |
| `creature_id` | [`creature_template`](creature_template.md).`entry` | heuristic | inferred from column name |
| `quest` | [`quest_template`](quest_template.md).`entry` | heuristic | inferred from column name |

