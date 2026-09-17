---
layout: default
title: mail
---

# mail

Mail System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 15 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | Identifier; non-negative numeric value; identifier column |
| <a id="col-messagetype"></a>`messageType` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-stationery"></a>`stationery` | `tinyint(4)` | NO |  | `41` |  | numeric value |
| <a id="col-mailtemplateid"></a>`mailTemplateId` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-sender"></a>`sender` | `int(10) unsigned` | NO |  | `0` |  | Character Global Unique Identifier; non-negative numeric value |
| <a id="col-receiver"></a>`receiver` | `int(10) unsigned` | NO |  | `0` |  | Character Global Unique Identifier; non-negative numeric value |
| <a id="col-subject"></a>`subject` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-itemtextid"></a>`itemTextId` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-has-items"></a>`has_items` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-expire-time"></a>`expire_time` | `bigint(20)` | NO |  | `0` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-deliver-time"></a>`deliver_time` | `bigint(20)` | NO |  | `0` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-money"></a>`money` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-cod"></a>`cod` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-checked"></a>`checked` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-isdeleted"></a>`isDeleted` | `tinyint(3) unsigned` | YES |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `messageType`

non-negative numeric value.

### `stationery`

numeric value.

### `mailTemplateId`

non-negative numeric value.

### `sender`

non-negative numeric value.

### `receiver`

non-negative numeric value.

### `subject`

text/string data.

### `itemTextId`

non-negative numeric value.

### `has_items`

non-negative numeric value.

### `expire_time`

numeric value; time/delay value; confirm unit in server usage.

### `deliver_time`

numeric value; time/delay value; confirm unit in server usage.

### `money`

non-negative numeric value; money/cost value, usually copper.

### `cod`

non-negative numeric value.

### `checked`

non-negative numeric value.

### `isDeleted`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |
| KEY | `idx_receiver` | `receiver` |
| KEY | `FK_mail_item_text` | `itemTextId` |
| KEY | `expire_time` | `expire_time` |
| KEY | `isDeleted` | `isDeleted` |

## Related Tables

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`mail_items`](mail_items.md).`mail_id` | `entry` | heuristic | inferred from column name |
