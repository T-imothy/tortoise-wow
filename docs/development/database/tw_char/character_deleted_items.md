---
layout: default
title: character_deleted_items
---

# character_deleted_items

Character database table `character_deleted_items`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 4 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | non-negative numeric value; identifier column |
| <a id="col-player-guid"></a>`player_guid` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-item-entry"></a>`item_entry` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-stack-count"></a>`stack_count` | `mediumint(8) unsigned` | NO |  | `1` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `player_guid`

non-negative numeric value.

### `item_entry`

non-negative numeric value.

### `stack_count`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |
