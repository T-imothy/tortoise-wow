---
layout: default
title: player_factionchange_reputations
---

# player_factionchange_reputations

World database table `player_factionchange_reputations`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 2 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-alliance-id"></a>`alliance_id` | `int(11)` | NO | `PRI` |  |  | numeric value |
| <a id="col-horde-id"></a>`horde_id` | `int(11)` | NO | `PRI` |  |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `alliance_id`

numeric value.

### `horde_id`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `alliance_id`, `horde_id` |

