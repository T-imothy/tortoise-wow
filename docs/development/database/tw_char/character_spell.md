---
layout: default
title: character_spell
---

# character_spell

Player System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | Global Unique Identifier; non-negative numeric value; identifier column |
| <a id="col-spell"></a>`spell` | `int(10) unsigned` | NO | `PRI` | `0` |  | Spell Identifier; non-negative numeric value |
| <a id="col-active"></a>`active` | `tinyint(3) unsigned` | NO |  | `1` |  | non-negative numeric value |
| <a id="col-disabled"></a>`disabled` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `spell`

non-negative numeric value.

References: [`spell_template`](../tw_world/spell_template.md).`entry`.

### `active`

non-negative numeric value.

### `disabled`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid`, `spell` |
| KEY | `idx_spell` | `spell` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `spell` | [`spell_template`](../tw_world/spell_template.md).`entry` | heuristic | inferred from column name |
