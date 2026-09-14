---
layout: default
title: spell_learn_spell
---

# spell_learn_spell

Item System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 3 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `smallint(5) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-spellid"></a>`SpellID` | `smallint(5) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-active"></a>`Active` | `tinyint(3) unsigned` | NO |  | `1` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `SpellID`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `Active`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry`, `SpellID` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `SpellID` | [`spell_template`](spell_template.md).`entry` | heuristic | inferred from column name |

