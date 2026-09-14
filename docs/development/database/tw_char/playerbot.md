---
layout: default
title: playerbot
---

# playerbot

Character database table `playerbot`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | latin1 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-char-guid"></a>`char_guid` | `bigint(20) unsigned` | NO | `PRI` |  |  | non-negative numeric value |
| <a id="col-chance"></a>`chance` | `int(10) unsigned` | NO |  | `10` |  | non-negative numeric value |
| <a id="col-comment"></a>`comment` | `varchar(255)` | YES |  | `NULL` |  | text/string data |
| <a id="col-ai"></a>`ai` | `varchar(50)` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `char_guid`

non-negative numeric value.

### `chance`

non-negative numeric value.

### `comment`

text/string data.

### `ai`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `char_guid` |
