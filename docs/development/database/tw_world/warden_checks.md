---
layout: default
title: warden_checks
---

# warden_checks

Warden System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 10 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `smallint(5) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | Check ID; non-negative numeric value; identifier column |
| <a id="col-group-id"></a>`group_id` | `smallint(5) unsigned` | NO |  |  |  | Grouping ID; non-negative numeric value |
| <a id="col-type"></a>`type` | `tinyint(3) unsigned` | YES |  | `NULL` |  | Check Type; non-negative numeric value |
| <a id="col-data"></a>`data` | `varchar(48)` | NO |  | `''` |  | text/string data |
| <a id="col-str"></a>`str` | `varchar(20)` | NO |  | `''` |  | text/string data |
| <a id="col-address"></a>`address` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-length"></a>`length` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-result"></a>`result` | `varchar(24)` | NO |  | `''` |  | text/string data |
| <a id="col-penalty"></a>`penalty` | `tinyint(4)` | NO |  | `-1` |  | Action to take if check fails; numeric value |
| <a id="col-comment"></a>`comment` | `varchar(50)` | YES |  | `''` |  | Description of what the check is; text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `group_id`

non-negative numeric value.

### `type`

non-negative numeric value.

### `data`

text/string data.

### `str`

text/string data.

### `address`

non-negative numeric value.

### `length`

non-negative numeric value.

### `result`

text/string data.

### `penalty`

numeric value.

### `comment`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

