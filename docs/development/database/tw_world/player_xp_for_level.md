---
layout: default
title: player_xp_for_level
---

# player_xp_for_level

World database table `player_xp_for_level`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 2 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-lvl"></a>`lvl` | `int(10) unsigned` | NO | `PRI` |  |  | non-negative numeric value |
| <a id="col-xp-for-next-level"></a>`xp_for_next_level` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `lvl`

non-negative numeric value.

### `xp_for_next_level`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `lvl` |

