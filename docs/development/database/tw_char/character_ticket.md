---
layout: default
title: character_ticket
---

# character_ticket

Player System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 5 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-ticket-id"></a>`ticket_id` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | non-negative numeric value |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; identifier column |
| <a id="col-ticket-text"></a>`ticket_text` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-response-text"></a>`response_text` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-ticket-lastchange"></a>`ticket_lastchange` | `timestamp` | NO |  | `current_timestamp()` | ON UPDATE | schema-defined value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `ticket_id`

non-negative numeric value.

### `guid`

non-negative numeric value; identifier column.

### `ticket_text`

text/string data.

### `response_text`

text/string data.

### `ticket_lastchange`

schema-defined value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `ticket_id` |
