---
layout: default
title: game_weather
---

# game_weather

Weather System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 14 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-zone"></a>`zone` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-spring-rain-chance"></a>`spring_rain_chance` | `tinyint(3) unsigned` | NO |  | `25` |  | non-negative numeric value |
| <a id="col-spring-snow-chance"></a>`spring_snow_chance` | `tinyint(3) unsigned` | NO |  | `25` |  | non-negative numeric value |
| <a id="col-spring-storm-chance"></a>`spring_storm_chance` | `tinyint(3) unsigned` | NO |  | `25` |  | non-negative numeric value |
| <a id="col-summer-rain-chance"></a>`summer_rain_chance` | `tinyint(3) unsigned` | NO |  | `25` |  | non-negative numeric value |
| <a id="col-summer-snow-chance"></a>`summer_snow_chance` | `tinyint(3) unsigned` | NO |  | `25` |  | non-negative numeric value |
| <a id="col-summer-storm-chance"></a>`summer_storm_chance` | `tinyint(3) unsigned` | NO |  | `25` |  | non-negative numeric value |
| <a id="col-fall-rain-chance"></a>`fall_rain_chance` | `tinyint(3) unsigned` | NO |  | `25` |  | non-negative numeric value |
| <a id="col-fall-snow-chance"></a>`fall_snow_chance` | `tinyint(3) unsigned` | NO |  | `25` |  | non-negative numeric value |
| <a id="col-fall-storm-chance"></a>`fall_storm_chance` | `tinyint(3) unsigned` | NO |  | `25` |  | non-negative numeric value |
| <a id="col-winter-rain-chance"></a>`winter_rain_chance` | `tinyint(3) unsigned` | NO |  | `25` |  | non-negative numeric value |
| <a id="col-winter-snow-chance"></a>`winter_snow_chance` | `tinyint(3) unsigned` | NO |  | `25` |  | non-negative numeric value |
| <a id="col-winter-storm-chance"></a>`winter_storm_chance` | `tinyint(3) unsigned` | NO |  | `25` |  | non-negative numeric value |
| <a id="col-comment"></a>`comment` | `varchar(255)` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `zone`

non-negative numeric value.

References: [`area_template`](area_template.md).`entry`.

### `spring_rain_chance`

non-negative numeric value.

### `spring_snow_chance`

non-negative numeric value.

### `spring_storm_chance`

non-negative numeric value.

### `summer_rain_chance`

non-negative numeric value.

### `summer_snow_chance`

non-negative numeric value.

### `summer_storm_chance`

non-negative numeric value.

### `fall_rain_chance`

non-negative numeric value.

### `fall_snow_chance`

non-negative numeric value.

### `fall_storm_chance`

non-negative numeric value.

### `winter_rain_chance`

non-negative numeric value.

### `winter_snow_chance`

non-negative numeric value.

### `winter_storm_chance`

non-negative numeric value.

### `comment`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `zone` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `zone` | [`area_template`](area_template.md).`entry` | explicit | zone |

