---
layout: default
title: points_of_interest
---

# points_of_interest

World database table `points_of_interest`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 7 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-x"></a>`x` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-y"></a>`y` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-icon"></a>`icon` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-flags"></a>`flags` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-data"></a>`data` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-icon-name"></a>`icon_name` | `text` | NO |  |  |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `x`

numeric value; world coordinate or orientation.

### `y`

numeric value; world coordinate or orientation.

### `icon`

non-negative numeric value.

### `flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

### `data`

non-negative numeric value.

### `icon_name`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`locales_points_of_interest`](locales_points_of_interest.md).`entry` | `entry` | explicit | localized row |

## Masks and Flags

### Unmapped Flag-Like Columns

| Column | Type | Guidance |
| --- | --- | --- |
| [`flags`](#col-flags) | `mediumint(8) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
