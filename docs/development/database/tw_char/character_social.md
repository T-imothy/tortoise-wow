---
layout: default
title: character_social
---

# character_social

Player System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 3 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | Character Global Unique Identifier; non-negative numeric value; identifier column |
| <a id="col-friend"></a>`friend` | `int(10) unsigned` | NO | `PRI` | `0` |  | Friend Global Unique Identifier; non-negative numeric value |
| <a id="col-flags"></a>`flags` | `tinyint(1) unsigned` | NO | `PRI` | `0` |  | Friend Flags; non-negative numeric value; mask/flags column; combine values with bitwise OR |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `friend`

non-negative numeric value.

### `flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid`, `friend`, `flags` |
| KEY | `idx_guid` | `guid` |
| KEY | `idx_friend` | `friend` |
| KEY | `idx_guid_flags` | `guid`, `flags` |
| KEY | `idx_friend_flags` | `friend`, `flags` |

## Masks and Flags

### Unmapped Flag-Like Columns

| Column | Type | Guidance |
| --- | --- | --- |
| [`flags`](#col-flags) | `tinyint(1) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
