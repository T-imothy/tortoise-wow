---
layout: default
title: creature_groups
---

# creature_groups

World database table `creature_groups`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 5 | latin1 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-leader-guid"></a>`leader_guid` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-member-guid"></a>`member_guid` | `int(10) unsigned` | NO | `PRI` |  |  | non-negative numeric value |
| <a id="col-dist"></a>`dist` | `float unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-angle"></a>`angle` | `float unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-flags"></a>`flags` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses CreatureGroupOptionFlags mask values |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `leader_guid`

non-negative numeric value.

### `member_guid`

non-negative numeric value.

### `dist`

non-negative numeric value.

### `angle`

non-negative numeric value.

### `flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `CreatureGroupOptionFlags` (mask) from `src/game/CreatureGroups.h enum OptionFlags`.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `member_guid` |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `CreatureGroupOptionFlags` | mask | [`flags`](#col-flags) | `src/game/CreatureGroups.h enum OptionFlags` | 8 |

### Possible Values

Used by: [`flags`](#col-flags)

#### `CreatureGroupOptionFlags`

Kind: `mask`

Source: `src/game/CreatureGroups.h enum OptionFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `OPTION_FORMATION_MOVE` | Option Formation Move |
| `2` | `0x2` | `OPTION_AGGRO_TOGETHER` | Option Aggro Together |
| `4` | `0x4` | `OPTION_EVADE_TOGETHER` | Option Evade Together |
| `8` | `0x8` | `OPTION_RESPAWN_TOGETHER` | Option Respawn Together |
| `16` | `0x10` | `OPTION_RESPAWN_ALL_ON_MASTER_EVADE` | Option Respawn All On Master Evade |
| `32` | `0x20` | `OPTION_RESPAWN_ALL_ON_ANY_EVADE` | Option Respawn All On Any Evade |
| `64` | `0x40` | `OPTION_INFORM_LEADER_ON_MEMBER_DIED` | Option Inform Leader On Member Died |
| `128` | `0x80` | `OPTION_INFORM_MEMBERS_ON_ANY_DIED` | Option Inform Members On Any Died |
