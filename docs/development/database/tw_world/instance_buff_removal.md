---
layout: default
title: instance_buff_removal
---

# instance_buff_removal

Aura removal on map entry

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 5 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-map-id"></a>`map_id` | `int(10) unsigned` | NO | `PRI` |  |  | MapId to remove aura from; non-negative numeric value |
| <a id="col-spell-id"></a>`spell_id` | `int(10) unsigned` | NO | `PRI` |  |  | aura id to remove on entering MapId; non-negative numeric value |
| <a id="col-enabled"></a>`enabled` | `tinyint(1)` | NO |  |  |  | aura removal enabled or not; numeric value |
| <a id="col-flags"></a>`flags` | `int(11)` | NO |  |  |  | flags, see AuraRemovalMgr.h; numeric value; mask/flags column; combine values with bitwise OR; Uses AuraRemovalFlags mask values |
| <a id="col-comment"></a>`comment` | `varchar(256)` | NO |  |  |  | description, what is removed; text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `map_id`

non-negative numeric value.

References: [`map_template`](map_template.md).`entry`.

### `spell_id`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `enabled`

numeric value.

### `flags`

numeric value; mask/flags column; combine values with bitwise OR.

Value set: `AuraRemovalFlags` (mask) from `src/game/AuraRemovalMgr.h enum AuraRemovalFlags`.

### `comment`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `map_id`, `spell_id` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `map_id` | [`map_template`](map_template.md).`entry` | heuristic | inferred from column name |
| `spell_id` | [`spell_template`](spell_template.md).`entry` | heuristic | spell id |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `AuraRemovalFlags` | mask | [`flags`](#col-flags) | `src/game/AuraRemovalMgr.h enum AuraRemovalFlags` | 2 |

### Possible Values

Used by: [`flags`](#col-flags)

#### `AuraRemovalFlags`

Kind: `mask`

Source: `src/game/AuraRemovalMgr.h enum AuraRemovalFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `AURA_REM_FLAG_EXCLUDE_HORDE` | Rem Flag Exclude Horde |
| `2` | `0x2` | `AURA_REM_FLAG_EXCLUDE_ALLIANCE` | Rem Flag Exclude Alliance |
