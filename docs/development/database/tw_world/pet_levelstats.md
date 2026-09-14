---
layout: default
title: pet_levelstats
---

# pet_levelstats

Stores pet levels stats.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 10 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-creature-entry"></a>`creature_entry` | `mediumint(8) unsigned` | NO | `PRI` |  |  | non-negative numeric value |
| <a id="col-level"></a>`level` | `tinyint(3) unsigned` | NO | `PRI` |  |  | non-negative numeric value |
| <a id="col-hp"></a>`hp` | `smallint(5) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-mana"></a>`mana` | `smallint(5) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-armor"></a>`armor` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-str"></a>`str` | `smallint(5) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-agi"></a>`agi` | `smallint(5) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-sta"></a>`sta` | `smallint(5) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-inte"></a>`inte` | `smallint(5) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-spi"></a>`spi` | `smallint(5) unsigned` | NO |  |  |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `creature_entry`

non-negative numeric value.

References: [`creature`](creature.md).`entry`, [`creature_template`](creature_template.md).`entry`.

### `level`

non-negative numeric value.

### `hp`

non-negative numeric value.

### `mana`

non-negative numeric value.

### `armor`

non-negative numeric value.

### `str`

non-negative numeric value.

### `agi`

non-negative numeric value.

### `sta`

non-negative numeric value.

### `inte`

non-negative numeric value.

### `spi`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `creature_entry`, `level` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `creature_entry` | [`creature`](creature.md).`entry` | heuristic | inferred from column name |
| `creature_entry` | [`creature_template`](creature_template.md).`entry` | heuristic | inferred from column name |

