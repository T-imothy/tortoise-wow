---
layout: default
title: game_event_creature_data
---

# game_event_creature_data

World database table `game_event_creature_data`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 7 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-entry-id"></a>`entry_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-display-id"></a>`display_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-equipment-id"></a>`equipment_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spell-start"></a>`spell_start` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spell-end"></a>`spell_end` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-event"></a>`event` | `smallint(5) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

References: [`creature`](creature.md).`guid`.

### `entry_id`

non-negative numeric value.

### `display_id`

non-negative numeric value.

### `equipment_id`

non-negative numeric value.

### `spell_start`

non-negative numeric value.

### `spell_end`

non-negative numeric value.

### `event`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid`, `event` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `guid` | [`creature`](creature.md).`guid` | explicit | event creature data |

