---
layout: default
title: pet_name_generation
---

# pet_name_generation

World database table `pet_name_generation`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `mediumint(8) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | non-negative numeric value; identifier column |
| <a id="col-word"></a>`word` | `tinytext` | NO |  |  |  | text/string data |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; identifier column |
| <a id="col-half"></a>`half` | `tinyint(4)` | NO |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `word`

text/string data.

### `entry`

non-negative numeric value; identifier column.

### `half`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

