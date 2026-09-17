---
layout: default
title: spell_group
---

# spell_group

Spell System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 3 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-group-id"></a>`group_id` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-group-spell-id"></a>`group_spell_id` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-spell-id"></a>`spell_id` | `int(11)` | NO | `PRI` | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `group_id`

non-negative numeric value.

### `group_spell_id`

non-negative numeric value.

### `spell_id`

numeric value.

References: [`spell_template`](spell_template.md).`entry`.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `group_id`, `group_spell_id`, `spell_id` |
| UNIQUE | `group_id` | `group_id`, `group_spell_id` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `spell_id` | [`spell_template`](spell_template.md).`entry` | heuristic | spell id |

