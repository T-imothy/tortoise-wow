---
layout: default
title: scripted_areatrigger
---

# scripted_areatrigger

World database table `scripted_areatrigger`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 2 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(9)` | NO | `PRI` |  |  | numeric value; identifier column |
| <a id="col-script-name"></a>`script_name` | `char(64)` | NO |  |  |  | text/string data; script id or script name |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

numeric value; identifier column.

### `script_name`

text/string data; script id or script name.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

