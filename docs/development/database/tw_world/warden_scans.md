---
layout: default
title: warden_scans
---

# warden_scans

World database table `warden_scans`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 9 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `smallint(5) unsigned` | NO |  |  | AUTO_INCREMENT | non-negative numeric value; identifier column |
| <a id="col-type"></a>`type` | `int(11)` | YES |  | `0` |  | numeric value |
| <a id="col-str"></a>`str` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-data"></a>`data` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-address"></a>`address` | `int(11)` | YES |  | `0` |  | numeric value |
| <a id="col-length"></a>`length` | `int(11)` | YES |  | `0` |  | numeric value |
| <a id="col-result"></a>`result` | `tinytext` | NO |  |  |  | text/string data |
| <a id="col-flags"></a>`flags` | `smallint(5) unsigned` | NO |  |  |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-comment"></a>`comment` | `tinytext` | NO |  |  |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `type`

numeric value.

### `str`

text/string data.

### `data`

text/string data.

### `address`

numeric value.

### `length`

numeric value.

### `result`

text/string data.

### `flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

### `comment`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| UNIQUE | `id` | `id` |

## Masks and Flags

### Unmapped Flag-Like Columns

| Column | Type | Guidance |
| --- | --- | --- |
| [`flags`](#col-flags) | `smallint(5) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
