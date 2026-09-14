---
layout: default
title: game_event_status
---

# game_event_status

Game event system

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 1 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-event"></a>`event` | `smallint(5) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `event`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `event` |
