---
layout: default
title: mail_items
---

# mail_items

Character database table `mail_items`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-mail-id"></a>`mail_id` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-item-guid"></a>`item_guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-item-template"></a>`item_template` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-receiver"></a>`receiver` | `int(10) unsigned` | NO |  | `0` |  | Character Global Unique Identifier; non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `mail_id`

non-negative numeric value.

References: [`mail`](mail.md).`entry`.

### `item_guid`

non-negative numeric value.

### `item_template`

non-negative numeric value.

### `receiver`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `mail_id`, `item_guid` |
| KEY | `idx_receiver` | `receiver` |
| KEY | `idx_item_guid` | `item_guid` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `mail_id` | [`mail`](mail.md).`entry` | heuristic | inferred from column name |
