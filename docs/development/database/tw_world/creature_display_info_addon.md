---
layout: default
title: creature_display_info_addon
---

# creature_display_info_addon

Creature System (display id related info)

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 5 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-display-id"></a>`display_id` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-bounding-radius"></a>`bounding_radius` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-combat-reach"></a>`combat_reach` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-gender"></a>`gender` | `tinyint(3) unsigned` | NO |  | `2` |  | non-negative numeric value; Uses Gender enum values |
| <a id="col-display-id-other-gender"></a>`display_id_other_gender` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `display_id`

non-negative numeric value.

### `bounding_radius`

numeric value.

### `combat_reach`

numeric value.

### `gender`

non-negative numeric value.

Value set: `Gender` (enum) from `src/game/SharedDefines.h enum Gender`.

### `display_id_other_gender`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `display_id` |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `Gender` | enum | [`gender`](#col-gender) | `src/game/SharedDefines.h enum Gender` | 3 |

### Possible Values

Used by: [`gender`](#col-gender)

#### `Gender`

Kind: `enum`

Source: `src/game/SharedDefines.h enum Gender`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `GENDER_MALE` | Gender Male |
| `1` | `0x1` | `GENDER_FEMALE` | Gender Female |
| `2` | `0x2` | `GENDER_NONE` | Gender None |
