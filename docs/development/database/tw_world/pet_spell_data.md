---
layout: default
title: pet_spell_data
---

# pet_spell_data

World database table `pet_spell_data`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 5 | utf8mb4 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `int(10) unsigned` | NO | `PRI` |  |  | non-negative numeric value; identifier column |
| <a id="col-spell-id1"></a>`spell_id1` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spell-id2"></a>`spell_id2` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spell-id3"></a>`spell_id3` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spell-id4"></a>`spell_id4` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `spell_id1`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `spell_id2`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `spell_id3`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `spell_id4`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `spell_id1` | [`spell_template`](spell_template.md).`entry` | heuristic | spell id |
| `spell_id2` | [`spell_template`](spell_template.md).`entry` | heuristic | spell id |
| `spell_id3` | [`spell_template`](spell_template.md).`entry` | heuristic | spell id |
| `spell_id4` | [`spell_template`](spell_template.md).`entry` | heuristic | spell id |

