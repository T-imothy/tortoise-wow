---
layout: default
title: battleground_template
---

# battleground_template

World database table `battleground_template`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 12 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `mediumint(8) unsigned` | NO | `PRI` |  |  | non-negative numeric value; identifier column |
| <a id="col-min-players-per-team"></a>`min_players_per_team` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-max-players-per-team"></a>`max_players_per_team` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-min-level"></a>`min_level` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-max-level"></a>`max_level` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-alliance-win-spell"></a>`alliance_win_spell` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-alliance-lose-spell"></a>`alliance_lose_spell` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-horde-win-spell"></a>`horde_win_spell` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-horde-lose-spell"></a>`horde_lose_spell` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-alliance-start-location"></a>`alliance_start_location` | `mediumint(8) unsigned` | NO |  | `0` |  | WorldSafeLocs.dbc; non-negative numeric value |
| <a id="col-horde-start-location"></a>`horde_start_location` | `mediumint(8) unsigned` | NO |  | `0` |  | WorldSafeLocs.dbc; non-negative numeric value |
| <a id="col-player-loot-id"></a>`player_loot_id` | `mediumint(8) unsigned` | NO |  | `0` |  | entry from reference_loot_template; non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `min_players_per_team`

non-negative numeric value.

### `max_players_per_team`

non-negative numeric value.

### `min_level`

non-negative numeric value.

### `max_level`

non-negative numeric value.

### `alliance_win_spell`

non-negative numeric value.

### `alliance_lose_spell`

non-negative numeric value.

### `horde_win_spell`

non-negative numeric value.

### `horde_lose_spell`

non-negative numeric value.

### `alliance_start_location`

non-negative numeric value.

### `horde_start_location`

non-negative numeric value.

### `player_loot_id`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

