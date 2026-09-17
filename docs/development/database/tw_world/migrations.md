---
layout: default
title: migrations
---

# migrations

World database table `migrations`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 4 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`Id` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | non-negative numeric value; identifier column |
| <a id="col-name"></a>`Name` | `varchar(255)` | NO |  | `'0'` |  | text/string data |
| <a id="col-hash"></a>`Hash` | `varchar(128)` | NO |  | `'0'` |  | text/string data |
| <a id="col-appliedat"></a>`AppliedAt` | `datetime` | NO |  |  |  | schema-defined value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `Id`

non-negative numeric value; identifier column.

### `Name`

text/string data.

### `Hash`

text/string data.

### `AppliedAt`

schema-defined value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `Id` |

