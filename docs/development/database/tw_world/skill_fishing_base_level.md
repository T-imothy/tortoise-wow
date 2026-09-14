---
layout: default
title: skill_fishing_base_level
---

# skill_fishing_base_level

Fishing system

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 2 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | Area identifier; non-negative numeric value; identifier column |
| <a id="col-skill"></a>`skill` | `smallint(6)` | NO |  | `0` |  | Base skill level requirement; numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `skill`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

