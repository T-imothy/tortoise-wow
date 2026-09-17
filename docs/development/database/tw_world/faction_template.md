---
layout: default
title: faction_template
---

# faction_template

World database table `faction_template`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 14 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `smallint(5) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-faction-id"></a>`faction_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-faction-flags"></a>`faction_flags` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses FactionTemplateFlags mask values |
| <a id="col-our-mask"></a>`our_mask` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses FactionMasks mask values |
| <a id="col-friendly-mask"></a>`friendly_mask` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses FactionMasks mask values |
| <a id="col-hostile-mask"></a>`hostile_mask` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses FactionMasks mask values |
| <a id="col-enemy-faction1"></a>`enemy_faction1` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-enemy-faction2"></a>`enemy_faction2` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-enemy-faction3"></a>`enemy_faction3` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-enemy-faction4"></a>`enemy_faction4` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-friend-faction1"></a>`friend_faction1` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-friend-faction2"></a>`friend_faction2` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-friend-faction3"></a>`friend_faction3` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-friend-faction4"></a>`friend_faction4` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `faction_id`

non-negative numeric value.

References: [`faction`](faction.md).`entry`.

### `faction_flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `FactionTemplateFlags` (mask) from `src/game/Database/DBCEnums.h enum FactionTemplateFlags`.

### `our_mask`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `FactionMasks` (mask) from `src/game/Database/DBCEnums.h enum FactionMasks`.

### `friendly_mask`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `FactionMasks` (mask) from `src/game/Database/DBCEnums.h enum FactionMasks`.

### `hostile_mask`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `FactionMasks` (mask) from `src/game/Database/DBCEnums.h enum FactionMasks`.

### `enemy_faction1`

non-negative numeric value.

### `enemy_faction2`

non-negative numeric value.

### `enemy_faction3`

non-negative numeric value.

### `enemy_faction4`

non-negative numeric value.

### `friend_faction1`

non-negative numeric value.

### `friend_faction2`

non-negative numeric value.

### `friend_faction3`

non-negative numeric value.

### `friend_faction4`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `faction_id` | [`faction`](faction.md).`entry` | heuristic | inferred from column name |

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`creature_template`](creature_template.md).`faction` | `entry` | explicit | creature faction template |
| [`gameobject_template`](gameobject_template.md).`faction` | `entry` | explicit | gameobject faction template |
| [`game_graveyard_zone`](game_graveyard_zone.md).`faction` | `entry` | heuristic | inferred from column name |
| [`reputation_reward_rate`](reputation_reward_rate.md).`faction` | `entry` | heuristic | inferred from column name |
| [`reputation_spillover_template`](reputation_spillover_template.md).`faction` | `entry` | heuristic | inferred from column name |
| [`reputation_spillover_template`](reputation_spillover_template.md).`faction1` | `entry` | heuristic | inferred from column name |
| [`reputation_spillover_template`](reputation_spillover_template.md).`faction2` | `entry` | heuristic | inferred from column name |
| [`reputation_spillover_template`](reputation_spillover_template.md).`faction3` | `entry` | heuristic | inferred from column name |
| [`reputation_spillover_template`](reputation_spillover_template.md).`faction4` | `entry` | heuristic | inferred from column name |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `FactionMasks` | mask | [`our_mask`](#col-our-mask), [`friendly_mask`](#col-friendly-mask), [`hostile_mask`](#col-hostile-mask) | `src/game/Database/DBCEnums.h enum FactionMasks` | 4 |
| `FactionTemplateFlags` | mask | [`faction_flags`](#col-faction-flags) | `src/game/Database/DBCEnums.h enum FactionTemplateFlags` | 13 |

### Possible Values

Used by: [`our_mask`](#col-our-mask), [`friendly_mask`](#col-friendly-mask), [`hostile_mask`](#col-hostile-mask)

#### `FactionMasks`

Kind: `mask`

Source: `src/game/Database/DBCEnums.h enum FactionMasks`

If no faction mask flags are set, the faction is non-aggressive by this mask.

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `FACTION_MASK_PLAYER` | Any player |
| `2` | `0x2` | `FACTION_MASK_ALLIANCE` | Alliance player or creature |
| `4` | `0x4` | `FACTION_MASK_HORDE` | Horde player or creature |
| `8` | `0x8` | `FACTION_MASK_MONSTER` | Aggressive monster creature |

Used by: [`faction_flags`](#col-faction-flags)

#### `FactionTemplateFlags`

Kind: `mask`

Source: `src/game/Database/DBCEnums.h enum FactionTemplateFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `FACTION_TEMPLATE_RESPOND_TO_CALL_FOR_HELP` | Responds to call for help |
| `2` | `0x2` | `FACTION_TEMPLATE_BROADCAST_TO_ENEMIES_LOW_PRIO` | Broadcast to enemies, low priority |
| `4` | `0x4` | `FACTION_TEMPLATE_BROADCAST_TO_ENEMIES_MED_PRIO` | Broadcast to enemies, medium priority |
| `8` | `0x8` | `FACTION_TEMPLATE_BROADCAST_TO_ENEMIES_HIG_PRIO` | Broadcast to enemies, high priority |
| `16` | `0x10` | `FACTION_TEMPLATE_SEARCH_FOR_ENEMIES_LOW_PRIO` | Search for enemies, low priority |
| `32` | `0x20` | `FACTION_TEMPLATE_SEARCH_FOR_ENEMIES_MED_PRIO` | Search for enemies, medium priority |
| `64` | `0x40` | `FACTION_TEMPLATE_SEARCH_FOR_ENEMIES_HIG_PRIO` | Search for enemies, high priority |
| `128` | `0x80` | `FACTION_TEMPLATE_SEARCH_FOR_FRIENDS_LOW_PRIO` | Search for friends, low priority |
| `256` | `0x100` | `FACTION_TEMPLATE_SEARCH_FOR_FRIENDS_MED_PRIO` | Search for friends, medium priority |
| `512` | `0x200` | `FACTION_TEMPLATE_SEARCH_FOR_FRIENDS_HIG_PRIO` | Search for friends, high priority |
| `1024` | `0x400` | `FACTION_TEMPLATE_FLEE_FROM_CALL_FOR_HELP` | Flee from call for help |
| `2048` | `0x800` | `FACTION_TEMPLATE_FLAG_ASSIST_PLAYERS` | Assist players; PvP flagged |
| `4096` | `0x1000` | `FACTION_TEMPLATE_FLAG_ATTACK_PVP_ACTIVE_PLAYERS` | Attacks players involved in PvP combat |
