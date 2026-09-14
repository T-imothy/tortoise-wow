---
layout: default
title: player_factionchange_quests
---

# player_factionchange_quests

World database table `player_factionchange_quests`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 3 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-alliance-id"></a>`alliance_id` | `int(11)` | NO | `PRI` |  |  | numeric value |
| <a id="col-horde-id"></a>`horde_id` | `int(11)` | NO | `PRI` |  |  | numeric value |
| <a id="col-comment"></a>`comment` | `varchar(255)` | NO |  | `''` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `alliance_id`

numeric value.

### `horde_id`

numeric value.

### `comment`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `alliance_id`, `horde_id` |

