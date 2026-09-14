---
layout: default
title: collection_mount
---

# collection_mount

World database table `collection_mount`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 2 | utf8mb4 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-itemid"></a>`itemId` | `int(10) unsigned` | NO | `PRI` |  |  | non-negative numeric value |
| <a id="col-spellid"></a>`spellId` | `int(10) unsigned` | NO | `PRI` |  |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `itemId`

non-negative numeric value.

References: [`item_template`](item_template.md).`entry`.

### `spellId`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `itemId`, `spellId` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `itemId` | [`item_template`](item_template.md).`entry` | heuristic | inferred from column name |
| `spellId` | [`spell_template`](spell_template.md).`entry` | heuristic | inferred from column name |

