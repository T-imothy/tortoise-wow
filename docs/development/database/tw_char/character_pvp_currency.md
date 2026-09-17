---
layout: default
title: character_pvp_currency
---

# character_pvp_currency

Character database table `character_pvp_currency`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 5 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-honor"></a>`honor` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-conquest"></a>`conquest` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-weekly-honor"></a>`weekly_honor` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-week-begin-day"></a>`week_begin_day` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `honor`

non-negative numeric value.

### `conquest`

non-negative numeric value.

### `weekly_honor`

non-negative numeric value.

### `week_begin_day`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid` |
