---
layout: default
title: bounty_quest_targets
---

# bounty_quest_targets

Character database table `bounty_quest_targets`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 3 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(10) unsigned` | NO | `PRI` | `1` |  | non-negative numeric value; identifier column |
| <a id="col-horde-player"></a>`horde_player` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-alliance-player"></a>`alliance_player` | `int(11)` | NO |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `horde_player`

non-negative numeric value.

### `alliance_player`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |
