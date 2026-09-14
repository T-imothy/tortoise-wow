---
layout: default
title: page_text
---

# page_text

Item System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 3 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-text"></a>`text` | `longtext` | NO |  |  |  | text/string data |
| <a id="col-next-page"></a>`next_page` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `text`

text/string data.

### `next_page`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`locales_page_text`](locales_page_text.md).`entry` | `entry` | explicit | localized row |
| [`item_template`](item_template.md).`page_text` | `entry` | heuristic | inferred from column name |

