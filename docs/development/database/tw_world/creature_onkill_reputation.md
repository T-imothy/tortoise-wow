---
layout: default
title: creature_onkill_reputation
---

# creature_onkill_reputation

Creature OnKill Reputation gain

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 10 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-creature-id"></a>`creature_id` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | Creature Identifier; non-negative numeric value |
| <a id="col-rewonkillrepfaction1"></a>`RewOnKillRepFaction1` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-rewonkillrepfaction2"></a>`RewOnKillRepFaction2` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-maxstanding1"></a>`MaxStanding1` | `tinyint(4)` | NO |  | `0` |  | numeric value |
| <a id="col-isteamaward1"></a>`IsTeamAward1` | `tinyint(4)` | NO |  | `0` |  | numeric value |
| <a id="col-rewonkillrepvalue1"></a>`RewOnKillRepValue1` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-maxstanding2"></a>`MaxStanding2` | `tinyint(4)` | NO |  | `0` |  | numeric value |
| <a id="col-isteamaward2"></a>`IsTeamAward2` | `tinyint(4)` | NO |  | `0` |  | numeric value |
| <a id="col-rewonkillrepvalue2"></a>`RewOnKillRepValue2` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-teamdependent"></a>`TeamDependent` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `creature_id`

non-negative numeric value.

References: [`creature`](creature.md).`entry`, [`creature_template`](creature_template.md).`entry`.

### `RewOnKillRepFaction1`

numeric value.

### `RewOnKillRepFaction2`

numeric value.

### `MaxStanding1`

numeric value.

### `IsTeamAward1`

numeric value.

### `RewOnKillRepValue1`

numeric value.

### `MaxStanding2`

numeric value.

### `IsTeamAward2`

numeric value.

### `RewOnKillRepValue2`

numeric value.

### `TeamDependent`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `creature_id` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `creature_id` | [`creature`](creature.md).`entry` | heuristic | inferred from column name |
| `creature_id` | [`creature_template`](creature_template.md).`entry` | heuristic | inferred from column name |

