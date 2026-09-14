---
layout: default
title: spell_chain
---

# spell_chain

Spell Additinal Data

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 5 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-spell-id"></a>`spell_id` | `mediumint(9)` | NO | `PRI` | `0` |  | numeric value |
| <a id="col-prev-spell"></a>`prev_spell` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-first-spell"></a>`first_spell` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-rank"></a>`rank` | `tinyint(4)` | NO |  | `0` |  | numeric value |
| <a id="col-req-spell"></a>`req_spell` | `mediumint(9)` | NO |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `spell_id`

numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `prev_spell`

numeric value.

### `first_spell`

numeric value.

### `rank`

numeric value.

### `req_spell`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `spell_id` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `spell_id` | [`spell_template`](spell_template.md).`entry` | heuristic | spell id |

