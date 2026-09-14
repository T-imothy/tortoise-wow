---
layout: default
title: areatrigger_involvedrelation
---

# areatrigger_involvedrelation

Trigger System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 2 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | Identifier; non-negative numeric value; identifier column |
| <a id="col-quest"></a>`quest` | `mediumint(8) unsigned` | NO |  | `0` |  | Quest Identifier; non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `quest`

non-negative numeric value.

References: [`quest_template`](quest_template.md).`entry`.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `quest` | [`quest_template`](quest_template.md).`entry` | heuristic | inferred from column name |

