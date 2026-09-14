---
layout: default
title: reputation_spillover_template
---

# reputation_spillover_template

Reputation spillover reputation gain

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 13 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-faction"></a>`faction` | `smallint(5) unsigned` | NO | `PRI` | `0` |  | faction entry; non-negative numeric value |
| <a id="col-faction1"></a>`faction1` | `smallint(5) unsigned` | NO |  | `0` |  | faction to give spillover for; non-negative numeric value |
| <a id="col-rate-1"></a>`rate_1` | `float` | NO |  | `0` |  | the given rep points * rate; numeric value |
| <a id="col-rank-1"></a>`rank_1` | `tinyint(3) unsigned` | NO |  | `0` |  | max rank, above this will not give any spillover; non-negative numeric value |
| <a id="col-faction2"></a>`faction2` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rate-2"></a>`rate_2` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-rank-2"></a>`rank_2` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-faction3"></a>`faction3` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rate-3"></a>`rate_3` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-rank-3"></a>`rank_3` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-faction4"></a>`faction4` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rate-4"></a>`rate_4` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-rank-4"></a>`rank_4` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `faction`

non-negative numeric value.

References: [`faction`](faction.md).`entry`, [`faction_template`](faction_template.md).`entry`.

### `faction1`

non-negative numeric value.

References: [`faction`](faction.md).`entry`, [`faction_template`](faction_template.md).`entry`.

### `rate_1`

numeric value.

### `rank_1`

non-negative numeric value.

### `faction2`

non-negative numeric value.

References: [`faction`](faction.md).`entry`, [`faction_template`](faction_template.md).`entry`.

### `rate_2`

numeric value.

### `rank_2`

non-negative numeric value.

### `faction3`

non-negative numeric value.

References: [`faction`](faction.md).`entry`, [`faction_template`](faction_template.md).`entry`.

### `rate_3`

numeric value.

### `rank_3`

non-negative numeric value.

### `faction4`

non-negative numeric value.

References: [`faction`](faction.md).`entry`, [`faction_template`](faction_template.md).`entry`.

### `rate_4`

numeric value.

### `rank_4`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `faction` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `faction` | [`faction`](faction.md).`entry` | heuristic | inferred from column name |
| `faction1` | [`faction`](faction.md).`entry` | heuristic | inferred from column name |
| `faction2` | [`faction`](faction.md).`entry` | heuristic | inferred from column name |
| `faction3` | [`faction`](faction.md).`entry` | heuristic | inferred from column name |
| `faction4` | [`faction`](faction.md).`entry` | heuristic | inferred from column name |
| `faction` | [`faction_template`](faction_template.md).`entry` | heuristic | inferred from column name |
| `faction1` | [`faction_template`](faction_template.md).`entry` | heuristic | inferred from column name |
| `faction2` | [`faction_template`](faction_template.md).`entry` | heuristic | inferred from column name |
| `faction3` | [`faction_template`](faction_template.md).`entry` | heuristic | inferred from column name |
| `faction4` | [`faction_template`](faction_template.md).`entry` | heuristic | inferred from column name |

