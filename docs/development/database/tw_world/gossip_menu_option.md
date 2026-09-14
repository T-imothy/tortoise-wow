---
layout: default
title: gossip_menu_option
---

# gossip_menu_option

World database table `gossip_menu_option`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 15 | latin1 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-menu-id"></a>`menu_id` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-id"></a>`id` | `smallint(5) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-option-icon"></a>`option_icon` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-option-text"></a>`option_text` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-option-broadcast-text"></a>`option_broadcast_text` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-option-id"></a>`option_id` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-npc-option-npcflag"></a>`npc_option_npcflag` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses NPCFlags mask values |
| <a id="col-action-menu-id"></a>`action_menu_id` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-action-poi-id"></a>`action_poi_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-action-script-id"></a>`action_script_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; script id or script name |
| <a id="col-box-coded"></a>`box_coded` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-box-money"></a>`box_money` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-box-text"></a>`box_text` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-box-broadcast-text"></a>`box_broadcast_text` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-condition-id"></a>`condition_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `menu_id`

non-negative numeric value.

References: [`gossip_menu`](gossip_menu.md).`entry`.

### `id`

non-negative numeric value; identifier column.

### `option_icon`

non-negative numeric value.

### `option_text`

text/string data.

### `option_broadcast_text`

non-negative numeric value.

### `option_id`

non-negative numeric value.

### `npc_option_npcflag`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `NPCFlags` (mask) from `src/game/Objects/UnitDefines.h enum NPCFlags`.

### `action_menu_id`

numeric value.

References: [`gossip_menu`](gossip_menu.md).`entry`.

### `action_poi_id`

non-negative numeric value.

### `action_script_id`

non-negative numeric value; script id or script name.

### `box_coded`

non-negative numeric value.

### `box_money`

non-negative numeric value; money/cost value, usually copper.

### `box_text`

text/string data.

### `box_broadcast_text`

non-negative numeric value.

### `condition_id`

non-negative numeric value.

References: [`conditions`](conditions.md).`condition_entry`.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `menu_id`, `id` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `condition_id` | [`conditions`](conditions.md).`condition_entry` | heuristic | inferred from column name |
| `action_menu_id` | [`gossip_menu`](gossip_menu.md).`entry` | explicit | linked gossip menu |
| `menu_id` | [`gossip_menu`](gossip_menu.md).`entry` | explicit | parent gossip menu |

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`gossip_scripts`](gossip_scripts.md).`id` | `action_script_id` | explicit | gossip action script |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `NPCFlags` | mask | [`npc_option_npcflag`](#col-npc-option-npcflag) | `src/game/Objects/UnitDefines.h enum NPCFlags` | 18 |

### Possible Values

Used by: [`npc_option_npcflag`](#col-npc-option-npcflag)

#### `NPCFlags`

Kind: `mask`

Source: `src/game/Objects/UnitDefines.h enum NPCFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `UNIT_NPC_FLAG_GOSSIP` | Shows gossip interaction |
| `2` | `0x2` | `UNIT_NPC_FLAG_QUESTGIVER` | Can start or complete quests |
| `4` | `0x4` | `UNIT_NPC_FLAG_VENDOR` | Vendor |
| `8` | `0x8` | `UNIT_NPC_FLAG_FLIGHTMASTER` | Flight master |
| `16` | `0x10` | `UNIT_NPC_FLAG_TRAINER` | Trainer |
| `32` | `0x20` | `UNIT_NPC_FLAG_SPIRITHEALER` | Spirit healer |
| `64` | `0x40` | `UNIT_NPC_FLAG_SPIRITGUIDE` | Spirit guide |
| `128` | `0x80` | `UNIT_NPC_FLAG_INNKEEPER` | Innkeeper |
| `256` | `0x100` | `UNIT_NPC_FLAG_BANKER` | Banker |
| `512` | `0x200` | `UNIT_NPC_FLAG_PETITIONER` | Petitioner |
| `1024` | `0x400` | `UNIT_NPC_FLAG_TABARDDESIGNER` | Tabard designer |
| `2048` | `0x800` | `UNIT_NPC_FLAG_BATTLEMASTER` | Battlemaster |
| `4096` | `0x1000` | `UNIT_NPC_FLAG_AUCTIONEER` | Auctioneer |
| `8192` | `0x2000` | `UNIT_NPC_FLAG_STABLEMASTER` | Stable master |
| `16384` | `0x4000` | `UNIT_NPC_FLAG_REPAIR` | Repairs equipment |
| `268435456` | `0x10000000` | `UNIT_NPC_FLAG_TRANSMOG` | Transmogrification service |
| `536870912` | `0x20000000` | `UNIT_NPC_FLAG_OUTDOORPVP` | Outdoor PvP interaction |
| `1073741824` | `0x40000000` | `UNIT_NPC_FLAG_ITEMRESTORE` | Item restore service |
