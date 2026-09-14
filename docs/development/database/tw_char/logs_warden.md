---
layout: default
title: logs_warden
---

# logs_warden

Warden log of failed checks

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 10 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | Log entry ID; non-negative numeric value; identifier column |
| <a id="col-check"></a>`check` | `smallint(5) unsigned` | NO |  |  |  | Failed Warden check ID; non-negative numeric value |
| <a id="col-action"></a>`action` | `tinyint(3) unsigned` | NO |  | `0` |  | Action taken (enum WardenActions); non-negative numeric value |
| <a id="col-account"></a>`account` | `int(10) unsigned` | NO |  |  |  | Account ID; non-negative numeric value |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO |  | `0` |  | Player GUID; non-negative numeric value; identifier column |
| <a id="col-map"></a>`map` | `int(10) unsigned` | YES |  | `NULL` |  | Map ID; non-negative numeric value |
| <a id="col-position-x"></a>`position_x` | `float` | YES |  | `NULL` |  | Player position X; numeric value; world coordinate or orientation |
| <a id="col-position-y"></a>`position_y` | `float` | YES |  | `NULL` |  | Player position Y; numeric value; world coordinate or orientation |
| <a id="col-position-z"></a>`position_z` | `float` | YES |  | `NULL` |  | Player position Z; numeric value; world coordinate or orientation |
| <a id="col-date"></a>`date` | `timestamp` | NO |  | `current_timestamp()` |  | Date of the log entry; schema-defined value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `check`

non-negative numeric value.

### `action`

non-negative numeric value.

### `account`

non-negative numeric value.

### `guid`

non-negative numeric value; identifier column.

### `map`

non-negative numeric value.

References: [`map_template`](../tw_world/map_template.md).`entry`.

### `position_x`

numeric value; world coordinate or orientation.

### `position_y`

numeric value; world coordinate or orientation.

### `position_z`

numeric value; world coordinate or orientation.

### `date`

schema-defined value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `map` | [`map_template`](../tw_world/map_template.md).`entry` | heuristic | inferred from column name |
