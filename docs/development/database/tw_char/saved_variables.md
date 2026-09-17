---
layout: default
title: saved_variables
---

# saved_variables

Variable Saves

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 5 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-key"></a>`key` | `tinyint(1) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-cleaning-flags"></a>`cleaning_flags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-lasthonormaintenanceday"></a>`lastHonorMaintenanceDay` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-nexthonormaintenanceday"></a>`nextHonorMaintenanceDay` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-honormaintenancemarker"></a>`honorMaintenanceMarker` | `tinyint(1) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `key`

non-negative numeric value.

### `cleaning_flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

### `lastHonorMaintenanceDay`

non-negative numeric value.

### `nextHonorMaintenanceDay`

non-negative numeric value.

### `honorMaintenanceMarker`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `key` |

## Masks and Flags

### Unmapped Flag-Like Columns

| Column | Type | Guidance |
| --- | --- | --- |
| [`cleaning_flags`](#col-cleaning-flags) | `int(10) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
