---
layout: default
title: quest_cast_objective
---

# quest_cast_objective

World database table `quest_cast_objective`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 6 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` |  |  | quest id; non-negative numeric value; identifier column |
| <a id="col-idx"></a>`idx` | `tinyint(3) unsigned` | NO | `PRI` |  |  | objective index (0 to 3); non-negative numeric value |
| <a id="col-spell-id"></a>`spell_id` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-player-guid"></a>`player_guid` | `int(11)` | NO |  |  |  | low guid, 0 for any player, -1 for gm; numeric value |
| <a id="col-player-class"></a>`player_class` | `tinyint(4)` | NO |  | `0` |  | 0 for any class; numeric value |
| <a id="col-objective-text"></a>`objective_text` | `varchar(64)` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `idx`

non-negative numeric value.

### `spell_id`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `player_guid`

numeric value.

### `player_class`

numeric value.

### `objective_text`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry`, `idx` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `spell_id` | [`spell_template`](spell_template.md).`entry` | heuristic | spell id |

