---
layout: default
title: gameobject_requirement
---

# gameobject_requirement

Gameobject System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 3 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | Global Unique Identifier; non-negative numeric value; identifier column |
| <a id="col-reqtype"></a>`reqType` | `int(10) unsigned` | NO |  | `0` |  | Gameobject Identifier; non-negative numeric value |
| <a id="col-reqguid"></a>`reqGuid` | `int(10) unsigned` | NO |  | `0` |  | Gameobject Identifier; non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `reqType`

non-negative numeric value.

### `reqGuid`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid` |

