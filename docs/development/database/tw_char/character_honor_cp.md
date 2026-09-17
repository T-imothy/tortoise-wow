---
layout: default
title: character_honor_cp
---

# character_honor_cp

Player System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 6 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO |  | `0` |  | Global Unique Identifier; non-negative numeric value; identifier column |
| <a id="col-victimtype"></a>`victimType` | `tinyint(3) unsigned` | NO |  | `4` |  | non-negative numeric value |
| <a id="col-victim"></a>`victim` | `int(10) unsigned` | NO |  | `0` |  | Creature / Player Identifier; non-negative numeric value |
| <a id="col-cp"></a>`cp` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-date"></a>`date` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-type"></a>`type` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `victimType`

non-negative numeric value.

### `victim`

non-negative numeric value.

### `cp`

numeric value.

### `date`

non-negative numeric value.

### `type`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| KEY | `idx_guid` | `guid` |
