---
layout: default
title: petition
---

# petition

Guild System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-ownerguid"></a>`ownerguid` | `int(10) unsigned` | NO | `PRI` |  |  | non-negative numeric value |
| <a id="col-petitionguid"></a>`petitionguid` | `int(10) unsigned` | YES |  | `0` |  | non-negative numeric value |
| <a id="col-charterguid"></a>`charterguid` | `int(10) unsigned` | YES |  | `NULL` |  | Charter item GUID; non-negative numeric value |
| <a id="col-name"></a>`name` | `varchar(255)` | NO |  | `''` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `ownerguid`

non-negative numeric value.

### `petitionguid`

non-negative numeric value.

### `charterguid`

non-negative numeric value.

### `name`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `ownerguid` |
| UNIQUE | `key_ownerguid_petitionguid` | `ownerguid`, `petitionguid` |
| UNIQUE | `charterguid` | `charterguid` |
