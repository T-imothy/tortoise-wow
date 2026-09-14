---
layout: default
title: petcreateinfo_spell
---

# petcreateinfo_spell

Pet Create Spells

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 5 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-spell1"></a>`spell1` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spell2"></a>`spell2` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spell3"></a>`spell3` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spell4"></a>`spell4` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `spell1`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `spell2`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `spell3`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `spell4`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `spell1` | [`spell_template`](spell_template.md).`entry` | heuristic | spell id |
| `spell2` | [`spell_template`](spell_template.md).`entry` | heuristic | spell id |
| `spell3` | [`spell_template`](spell_template.md).`entry` | heuristic | spell id |
| `spell4` | [`spell_template`](spell_template.md).`entry` | heuristic | spell id |

