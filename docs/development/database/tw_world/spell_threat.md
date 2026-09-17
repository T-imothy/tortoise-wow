---
layout: default
title: spell_threat
---

# spell_threat

World database table `spell_threat`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` |  |  | non-negative numeric value; identifier column |
| <a id="col-threat"></a>`Threat` | `smallint(6)` | NO |  |  |  | numeric value |
| <a id="col-multiplier"></a>`multiplier` | `float` | NO |  | `1` |  | threat multiplier for damage/healing; numeric value |
| <a id="col-ap-bonus"></a>`ap_bonus` | `float` | NO |  | `0` |  | additional threat bonus from attack power; numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `Threat`

numeric value.

### `multiplier`

numeric value.

### `ap_bonus`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

