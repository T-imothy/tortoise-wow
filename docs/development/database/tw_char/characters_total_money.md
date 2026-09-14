---
layout: default
title: characters_total_money
---

# characters_total_money

Character database table `characters_total_money`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 3 | utf8mb4 | default |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`Id` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | non-negative numeric value; identifier column |
| <a id="col-total-gold"></a>`total_gold` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-time"></a>`time` | `datetime` | NO |  | `current_timestamp()` |  | time/delay value; confirm unit in server usage |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `Id`

non-negative numeric value; identifier column.

### `total_gold`

non-negative numeric value; money/cost value, usually copper.

### `time`

time/delay value; confirm unit in server usage.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `Id` |
