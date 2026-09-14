---
layout: default
title: daily_quest_timer
---

# daily_quest_timer

World database table `daily_quest_timer`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 1 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-nextresettime"></a>`nextResetTime` | `bigint(20) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `nextResetTime`

non-negative numeric value; time/delay value; confirm unit in server usage.

## Keys and Indexes

No keys were declared in the parsed CREATE TABLE statement.

