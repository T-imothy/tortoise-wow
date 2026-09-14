---
layout: default
title: pet_spell_cooldown
---

# pet_spell_cooldown

Character database table `pet_spell_cooldown`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 3 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | Global Unique Identifier, Low part; non-negative numeric value; identifier column |
| <a id="col-spell"></a>`spell` | `int(10) unsigned` | NO | `PRI` | `0` |  | Spell Identifier; non-negative numeric value |
| <a id="col-time"></a>`time` | `bigint(20) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `spell`

non-negative numeric value.

References: [`spell_template`](../tw_world/spell_template.md).`entry`.

### `time`

non-negative numeric value; time/delay value; confirm unit in server usage.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid`, `spell` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `spell` | [`spell_template`](../tw_world/spell_template.md).`entry` | heuristic | inferred from column name |
