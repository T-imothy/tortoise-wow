---
layout: default
title: spell_disabled
---

# spell_disabled

World database table `spell_disabled`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 1 | latin1 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `int(10) unsigned` | NO | `PRI` |  |  | Disabled spell; non-negative numeric value; identifier column |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

