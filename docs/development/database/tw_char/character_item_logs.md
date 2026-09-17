---
layout: default
title: character_item_logs
---

# character_item_logs

Character database table `character_item_logs`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 7 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | non-negative numeric value; identifier column |
| <a id="col-playerlowguid"></a>`playerLowGuid` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-itemlowguid"></a>`itemLowGuid` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-itementry"></a>`itemEntry` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-itemcount"></a>`itemCount` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-action"></a>`action` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-timestamp"></a>`timestamp` | `bigint(20) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `playerLowGuid`

non-negative numeric value.

### `itemLowGuid`

non-negative numeric value.

### `itemEntry`

non-negative numeric value.

### `itemCount`

non-negative numeric value.

### `action`

non-negative numeric value.

### `timestamp`

non-negative numeric value; time/delay value; confirm unit in server usage.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |
| KEY | `playerLowGuid` | `playerLowGuid`, `itemLowGuid`, `itemEntry` |
| KEY | `action` | `action` |
| KEY | `timestamp` | `timestamp` |
