---
layout: default
title: creature_battleground
---

# creature_battleground

Creature battleground indexing system

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 3 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` |  |  | Creature; non-negative numeric value; identifier column |
| <a id="col-event1"></a>`event1` | `tinyint(3) unsigned` | NO | `PRI` |  |  | main event; non-negative numeric value |
| <a id="col-event2"></a>`event2` | `tinyint(3) unsigned` | NO |  |  |  | sub event; non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `event1`

non-negative numeric value.

### `event2`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid`, `event1` |

