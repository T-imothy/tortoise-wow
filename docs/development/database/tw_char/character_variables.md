---
layout: default
title: character_variables
---

# character_variables

Character database table `character_variables`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 3 | utf8mb4 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-lowguid"></a>`lowGuid` | `int(10) unsigned` | NO | `PRI` |  |  | non-negative numeric value |
| <a id="col-variabletype"></a>`variableType` | `int(10) unsigned` | NO | `PRI` |  |  | non-negative numeric value |
| <a id="col-value"></a>`value` | `varchar(255)` | NO |  | `''` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `lowGuid`

non-negative numeric value.

### `variableType`

non-negative numeric value.

### `value`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `lowGuid`, `variableType` |
