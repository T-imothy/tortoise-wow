---
layout: default
title: npc_trainer
---

# npc_trainer

World database table `npc_trainer`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 6 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; identifier column |
| <a id="col-spell"></a>`spell` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spellcost"></a>`spellcost` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-reqskill"></a>`reqskill` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqskillvalue"></a>`reqskillvalue` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqlevel"></a>`reqlevel` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

References: [`creature_template`](creature_template.md).`entry`.

### `spell`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `spellcost`

non-negative numeric value; money/cost value, usually copper.

### `reqskill`

non-negative numeric value.

### `reqskillvalue`

non-negative numeric value.

### `reqlevel`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| UNIQUE | `entry_spell` | `entry`, `spell` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `entry` | [`creature_template`](creature_template.md).`entry` | explicit | trainer creature |
| `spell` | [`spell_template`](spell_template.md).`entry` | explicit | trained spell |

