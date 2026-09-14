---
layout: default
title: character_gifts
---

# character_gifts

Character database table `character_gifts`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; identifier column |
| <a id="col-item-guid"></a>`item_guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-entry"></a>`entry` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; identifier column |
| <a id="col-flags"></a>`flags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `item_guid`

non-negative numeric value.

### `entry`

non-negative numeric value; identifier column.

### `flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `item_guid` |
| KEY | `idx_guid` | `guid` |

## Masks and Flags

### Unmapped Flag-Like Columns

| Column | Type | Guidance |
| --- | --- | --- |
| [`flags`](#col-flags) | `int(10) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
