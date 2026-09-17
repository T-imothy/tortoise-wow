---
layout: default
title: cinematic_waypoints
---

# cinematic_waypoints

World database table `cinematic_waypoints`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 7 | latin1 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-cinematic"></a>`cinematic` | `int(11)` | YES |  | `0` |  | numeric value |
| <a id="col-timer"></a>`timer` | `int(11)` | YES |  | `0` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-position-x"></a>`position_x` | `float` | YES |  | `NULL` |  | numeric value; world coordinate or orientation |
| <a id="col-position-y"></a>`position_y` | `float` | YES |  | `NULL` |  | numeric value; world coordinate or orientation |
| <a id="col-position-z"></a>`position_z` | `float` | YES |  | `NULL` |  | numeric value; world coordinate or orientation |
| <a id="col-comment"></a>`comment` | `varchar(255)` | YES |  | `NULL` |  | text/string data |
| <a id="col-id"></a>`id` | `int(11)` | NO | `PRI` |  | AUTO_INCREMENT | numeric value; identifier column |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `cinematic`

numeric value.

### `timer`

numeric value; time/delay value; confirm unit in server usage.

### `position_x`

numeric value; world coordinate or orientation.

### `position_y`

numeric value; world coordinate or orientation.

### `position_z`

numeric value; world coordinate or orientation.

### `comment`

text/string data.

### `id`

numeric value; identifier column.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

