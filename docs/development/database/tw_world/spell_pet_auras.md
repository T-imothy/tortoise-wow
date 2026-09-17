---
layout: default
title: spell_pet_auras
---

# spell_pet_auras

World database table `spell_pet_auras`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 3 | latin1 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-spell"></a>`spell` | `mediumint(8) unsigned` | NO | `PRI` |  |  | dummy spell id; non-negative numeric value |
| <a id="col-pet"></a>`pet` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | pet id; 0 = all; non-negative numeric value |
| <a id="col-aura"></a>`aura` | `mediumint(8) unsigned` | NO |  |  |  | pet aura id; non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `spell`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `pet`

non-negative numeric value.

### `aura`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `spell`, `pet` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `spell` | [`spell_template`](spell_template.md).`entry` | heuristic | spell id |

