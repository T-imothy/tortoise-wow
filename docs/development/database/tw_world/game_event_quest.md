---
layout: default
title: game_event_quest
---

# game_event_quest

Game event system

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 2 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-quest"></a>`quest` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | entry from quest_template; non-negative numeric value |
| <a id="col-event"></a>`event` | `smallint(5) unsigned` | NO | `PRI` | `0` |  | entry from game_event; non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `quest`

non-negative numeric value.

References: [`quest_template`](quest_template.md).`entry`.

### `event`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `quest`, `event` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `quest` | [`quest_template`](quest_template.md).`entry` | explicit | event quest |

