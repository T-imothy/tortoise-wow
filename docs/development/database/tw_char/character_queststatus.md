---
layout: default
title: character_queststatus
---

# character_queststatus

Player System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 15 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | Global Unique Identifier; non-negative numeric value; identifier column |
| <a id="col-quest"></a>`quest` | `int(10) unsigned` | NO | `PRI` | `0` |  | Quest Identifier; non-negative numeric value |
| <a id="col-status"></a>`status` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewarded"></a>`rewarded` | `tinyint(1) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-explored"></a>`explored` | `tinyint(1) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-timer"></a>`timer` | `bigint(20) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-mobcount1"></a>`mobcount1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-mobcount2"></a>`mobcount2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-mobcount3"></a>`mobcount3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-mobcount4"></a>`mobcount4` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-itemcount1"></a>`itemcount1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-itemcount2"></a>`itemcount2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-itemcount3"></a>`itemcount3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-itemcount4"></a>`itemcount4` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reward-choice"></a>`reward_choice` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `quest`

non-negative numeric value.

References: [`quest_template`](../tw_world/quest_template.md).`entry`.

### `status`

non-negative numeric value.

### `rewarded`

non-negative numeric value.

### `explored`

non-negative numeric value.

### `timer`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `mobcount1`

non-negative numeric value.

### `mobcount2`

non-negative numeric value.

### `mobcount3`

non-negative numeric value.

### `mobcount4`

non-negative numeric value.

### `itemcount1`

non-negative numeric value.

### `itemcount2`

non-negative numeric value.

### `itemcount3`

non-negative numeric value.

### `itemcount4`

non-negative numeric value.

### `reward_choice`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid`, `quest` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `quest` | [`quest_template`](../tw_world/quest_template.md).`entry` | heuristic | inferred from column name |
