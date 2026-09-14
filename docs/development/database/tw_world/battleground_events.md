---
layout: default
title: battleground_events
---

# battleground_events

World database table `battleground_events`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-map"></a>`map` | `smallint(6)` | NO | `PRI` |  |  | numeric value |
| <a id="col-event1"></a>`event1` | `tinyint(3) unsigned` | NO | `PRI` |  |  | non-negative numeric value |
| <a id="col-event2"></a>`event2` | `tinyint(3) unsigned` | NO | `PRI` |  |  | non-negative numeric value |
| <a id="col-description"></a>`description` | `varchar(255)` | NO |  |  |  | text/string data; script id or script name |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `map`

numeric value.

References: [`map_template`](map_template.md).`entry`.

### `event1`

non-negative numeric value.

### `event2`

non-negative numeric value.

### `description`

text/string data; script id or script name.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `map`, `event1`, `event2` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `map` | [`map_template`](map_template.md).`entry` | heuristic | inferred from column name |

