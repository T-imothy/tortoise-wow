---
layout: default
title: area_template
---

# area_template

World database table `area_template`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 9 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-map-id"></a>`map_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-zone-id"></a>`zone_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-explore-flag"></a>`explore_flag` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-flags"></a>`flags` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses AreaFlags mask values |
| <a id="col-area-level"></a>`area_level` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-name"></a>`name` | `varchar(100)` | NO |  | `''` |  | text/string data |
| <a id="col-team"></a>`team` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses AreaTeams enum values |
| <a id="col-liquid-type"></a>`liquid_type` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `map_id`

non-negative numeric value.

References: [`map_template`](map_template.md).`entry`.

### `zone_id`

non-negative numeric value.

### `explore_flag`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

### `flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `AreaFlags` (mask) from `src/game/Database/DBCEnums.h enum AreaFlags`.

### `area_level`

numeric value.

### `name`

text/string data.

### `team`

non-negative numeric value.

Value set: `AreaTeams` (enum) from `src/game/Database/DBCEnums.h enum AreaTeams`.

### `liquid_type`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `map_id` | [`map_template`](map_template.md).`entry` | heuristic | inferred from column name |

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`spell_area`](spell_area.md).`area` | `entry` | heuristic | inferred from column name |
| [`cartographer`](cartographer.md).`area_id` | `entry` | heuristic | inferred from column name |
| [`custom_graveyards`](custom_graveyards.md).`area_id` | `entry` | heuristic | inferred from column name |
| [`dynamic_visibility_template`](dynamic_visibility_template.md).`area_id` | `entry` | heuristic | inferred from column name |
| [`game_graveyard_zone`](game_graveyard_zone.md).`ghost_zone` | `entry` | explicit | zone |
| [`playercreateinfo`](playercreateinfo.md).`zone` | `entry` | heuristic | inferred from column name |
| [`game_weather`](game_weather.md).`zone` | `entry` | explicit | zone |
| [`custom_graveyards`](custom_graveyards.md).`zone_id` | `entry` | heuristic | inferred from column name |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `AreaFlags` | mask | [`flags`](#col-flags) | `src/game/Database/DBCEnums.h enum AreaFlags` | 10 |
| `AreaTeams` | enum | [`team`](#col-team) | `src/game/Database/DBCEnums.h enum AreaTeams` | 3 |

### Possible Values

Used by: [`flags`](#col-flags)

#### `AreaFlags`

Kind: `mask`

Source: `src/game/Database/DBCEnums.h enum AreaFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `AREA_FLAG_SNOW` | snow (only Dun Morogh, Naxxramas, Razorfen Downs and Winterspring) |
| `2` | `0x2` | `AREA_FLAG_UNK1` | unknown, (only Naxxramas and Razorfen Downs) |
| `4` | `0x4` | `AREA_FLAG_UNK2` | Only used on development map |
| `8` | `0x8` | `AREA_FLAG_SLAVE_CAPITAL` | slave capital city flag? |
| `16` | `0x10` | `AREA_FLAG_UNK3` | unknown |
| `32` | `0x20` | `AREA_FLAG_SLAVE_CAPITAL2` | slave capital city flag? |
| `64` | `0x40` | `AREA_FLAG_DUEL` | zones where duels allowed |
| `128` | `0x80` | `AREA_FLAG_ARENA` | arena, both instanced and world arenas |
| `256` | `0x100` | `AREA_FLAG_CAPITAL` | main capital city flag |
| `512` | `0x200` | `AREA_FLAG_CITY` | only for one zone named "City" (where it located?) |

Used by: [`team`](#col-team)

#### `AreaTeams`

Kind: `enum`

Source: `src/game/Database/DBCEnums.h enum AreaTeams`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `AREATEAM_NONE` | Areateam None |
| `2` | `0x2` | `AREATEAM_ALLY` | Areateam Ally |
| `4` | `0x4` | `AREATEAM_HORDE` | Areateam Horde |

### Unmapped Flag-Like Columns

| Column | Type | Guidance |
| --- | --- | --- |
| [`explore_flag`](#col-explore-flag) | `mediumint(8) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
