---
layout: default
title: reputation_reward_rate
---

# reputation_reward_rate

World database table `reputation_reward_rate`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-faction"></a>`faction` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-quest-rate"></a>`quest_rate` | `float` | NO |  | `1` |  | numeric value |
| <a id="col-creature-rate"></a>`creature_rate` | `float` | NO |  | `1` |  | numeric value |
| <a id="col-spell-rate"></a>`spell_rate` | `float` | NO |  | `1` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `faction`

non-negative numeric value.

References: [`faction`](faction.md).`entry`, [`faction_template`](faction_template.md).`entry`.

### `quest_rate`

numeric value.

### `creature_rate`

numeric value.

### `spell_rate`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `faction` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `faction` | [`faction`](faction.md).`entry` | heuristic | inferred from column name |
| `faction` | [`faction_template`](faction_template.md).`entry` | heuristic | inferred from column name |

