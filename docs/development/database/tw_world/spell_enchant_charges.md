---
layout: default
title: spell_enchant_charges
---

# spell_enchant_charges

World database table `spell_enchant_charges`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 2 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `int(10) unsigned` | NO | `PRI` |  |  | non-negative numeric value; identifier column |
| <a id="col-charges"></a>`charges` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `charges`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

