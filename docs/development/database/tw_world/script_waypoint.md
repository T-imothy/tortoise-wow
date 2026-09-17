---
layout: default
title: script_waypoint
---

# script_waypoint

Script Creature waypoints

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 7 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | creature_template entry; non-negative numeric value; identifier column |
| <a id="col-pointid"></a>`pointid` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-location-x"></a>`location_x` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-location-y"></a>`location_y` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-location-z"></a>`location_z` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-waittime"></a>`waittime` | `int(10) unsigned` | NO |  | `0` |  | waittime in millisecs; non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-point-comment"></a>`point_comment` | `text` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `pointid`

non-negative numeric value.

### `location_x`

numeric value.

### `location_y`

numeric value.

### `location_z`

numeric value.

### `waittime`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `point_comment`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry`, `pointid` |

