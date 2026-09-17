---
layout: default
title: sound_entries
---

# sound_entries

World database table `sound_entries`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 2 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(11)` | NO | `PRI` | `0` |  | numeric value; identifier column |
| <a id="col-name"></a>`name` | `varchar(128)` | NO |  | `''` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

numeric value; identifier column.

### `name`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |
| UNIQUE | `ID` | `id` |

## Related Tables

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`broadcast_text`](broadcast_text.md).`sound_id` | `entry` | heuristic | inferred from column name |

