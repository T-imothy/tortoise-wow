---
layout: default
title: character_skills_copy
---

# character_skills_copy

Player System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` |  |  | Global Unique Identifier; non-negative numeric value; identifier column |
| <a id="col-skill"></a>`skill` | `mediumint(8) unsigned` | NO | `PRI` |  |  | non-negative numeric value |
| <a id="col-value"></a>`value` | `mediumint(8) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-max"></a>`max` | `mediumint(8) unsigned` | NO |  |  |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `skill`

non-negative numeric value.

### `value`

non-negative numeric value.

### `max`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid`, `skill` |
