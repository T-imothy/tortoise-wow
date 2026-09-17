---
layout: default
title: gameobject_template
---

# gameobject_template

Gameobject System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 35 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-type"></a>`type` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses GameobjectTypes enum values |
| <a id="col-displayid"></a>`displayId` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-name"></a>`name` | `varchar(100)` | NO |  | `''` |  | text/string data |
| <a id="col-faction"></a>`faction` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-flags"></a>`flags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses GameObjectFlags mask values |
| <a id="col-size"></a>`size` | `float` | NO |  | `1` |  | numeric value |
| <a id="col-data0"></a>`data0` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data1"></a>`data1` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-data2"></a>`data2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data3"></a>`data3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data4"></a>`data4` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data5"></a>`data5` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data6"></a>`data6` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-data7"></a>`data7` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data8"></a>`data8` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data9"></a>`data9` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data10"></a>`data10` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data11"></a>`data11` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data12"></a>`data12` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data13"></a>`data13` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data14"></a>`data14` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data15"></a>`data15` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data16"></a>`data16` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data17"></a>`data17` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data18"></a>`data18` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data19"></a>`data19` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data20"></a>`data20` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data21"></a>`data21` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data22"></a>`data22` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-data23"></a>`data23` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-mingold"></a>`mingold` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-maxgold"></a>`maxgold` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-phase-quest-id"></a>`phase_quest_id` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-script-name"></a>`script_name` | `varchar(64)` | NO |  | `''` |  | text/string data; script id or script name |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `type`

non-negative numeric value.

Value set: `GameobjectTypes` (enum) from `src/game/SharedDefines.h enum GameobjectTypes`.

### `displayId`

non-negative numeric value.

### `name`

text/string data.

### `faction`

non-negative numeric value.

References: [`faction_template`](faction_template.md).`entry`.

### `flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `GameObjectFlags` (mask) from `src/game/SharedDefines.h enum GameObjectFlags`.

### `size`

numeric value.

### `data0`

non-negative numeric value.

### `data1`

numeric value.

### `data2`

non-negative numeric value.

### `data3`

non-negative numeric value.

### `data4`

non-negative numeric value.

### `data5`

non-negative numeric value.

### `data6`

numeric value.

### `data7`

non-negative numeric value.

### `data8`

non-negative numeric value.

### `data9`

non-negative numeric value.

### `data10`

non-negative numeric value.

### `data11`

non-negative numeric value.

### `data12`

non-negative numeric value.

### `data13`

non-negative numeric value.

### `data14`

non-negative numeric value.

### `data15`

non-negative numeric value.

### `data16`

non-negative numeric value.

### `data17`

non-negative numeric value.

### `data18`

non-negative numeric value.

### `data19`

non-negative numeric value.

### `data20`

non-negative numeric value.

### `data21`

non-negative numeric value.

### `data22`

non-negative numeric value.

### `data23`

non-negative numeric value.

### `mingold`

non-negative numeric value; money/cost value, usually copper.

### `maxgold`

non-negative numeric value; money/cost value, usually copper.

### `phase_quest_id`

non-negative numeric value.

References: [`quest_template`](quest_template.md).`entry`.

### `script_name`

text/string data; script id or script name.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `faction` | [`faction_template`](faction_template.md).`entry` | explicit | gameobject faction template |
| `phase_quest_id` | [`quest_template`](quest_template.md).`entry` | explicit | phase quest |

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`gameobject`](gameobject.md).`id` | `entry` | explicit | spawn uses template |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `GameObjectFlags` | mask | [`flags`](#col-flags) | `src/game/SharedDefines.h enum GameObjectFlags` | 7 |
| `GameobjectTypes` | enum | [`type`](#col-type) | `src/game/SharedDefines.h enum GameobjectTypes` | 31 |

### Possible Values

Used by: [`flags`](#col-flags)

#### `GameObjectFlags`

Kind: `mask`

Source: `src/game/SharedDefines.h enum GameObjectFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `GO_FLAG_IN_USE` | Disables interaction while animated |
| `2` | `0x2` | `GO_FLAG_LOCKED` | Requires key, spell, event, or other unlock condition |
| `4` | `0x4` | `GO_FLAG_INTERACT_COND` | Conditional interaction |
| `8` | `0x8` | `GO_FLAG_TRANSPORT` | Transport object |
| `16` | `0x10` | `GO_FLAG_NO_INTERACT` | Cannot be interacted with |
| `32` | `0x20` | `GO_FLAG_NODESPAWN` | Do not despawn |
| `64` | `0x40` | `GO_FLAG_TRIGGERED` | Triggered object |

Used by: [`type`](#col-type)

#### `GameobjectTypes`

Kind: `enum`

Source: `src/game/SharedDefines.h enum GameobjectTypes`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `GAMEOBJECT_TYPE_DOOR` | Door |
| `1` | `0x1` | `GAMEOBJECT_TYPE_BUTTON` | Button |
| `2` | `0x2` | `GAMEOBJECT_TYPE_QUESTGIVER` | Quest giver |
| `3` | `0x3` | `GAMEOBJECT_TYPE_CHEST` | Chest |
| `4` | `0x4` | `GAMEOBJECT_TYPE_BINDER` | Binder |
| `5` | `0x5` | `GAMEOBJECT_TYPE_GENERIC` | Generic |
| `6` | `0x6` | `GAMEOBJECT_TYPE_TRAP` | Trap |
| `7` | `0x7` | `GAMEOBJECT_TYPE_CHAIR` | Chair |
| `8` | `0x8` | `GAMEOBJECT_TYPE_SPELL_FOCUS` | Spell focus |
| `9` | `0x9` | `GAMEOBJECT_TYPE_TEXT` | Text |
| `10` | `0xA` | `GAMEOBJECT_TYPE_GOOBER` | Goober |
| `11` | `0xB` | `GAMEOBJECT_TYPE_TRANSPORT` | Transport |
| `12` | `0xC` | `GAMEOBJECT_TYPE_AREADAMAGE` | Area damage |
| `13` | `0xD` | `GAMEOBJECT_TYPE_CAMERA` | Camera |
| `14` | `0xE` | `GAMEOBJECT_TYPE_MAP_OBJECT` | Map object |
| `15` | `0xF` | `GAMEOBJECT_TYPE_MO_TRANSPORT` | Map object transport |
| `16` | `0x10` | `GAMEOBJECT_TYPE_DUEL_ARBITER` | Duel arbiter |
| `17` | `0x11` | `GAMEOBJECT_TYPE_FISHINGNODE` | Fishing node |
| `18` | `0x12` | `GAMEOBJECT_TYPE_SUMMONING_RITUAL` | Summoning ritual |
| `19` | `0x13` | `GAMEOBJECT_TYPE_MAILBOX` | Mailbox |
| `20` | `0x14` | `GAMEOBJECT_TYPE_AUCTIONHOUSE` | Auction house |
| `21` | `0x15` | `GAMEOBJECT_TYPE_GUARDPOST` | Guard post |
| `22` | `0x16` | `GAMEOBJECT_TYPE_SPELLCASTER` | Spell caster |
| `23` | `0x17` | `GAMEOBJECT_TYPE_MEETINGSTONE` | Meeting stone |
| `24` | `0x18` | `GAMEOBJECT_TYPE_FLAGSTAND` | Flag stand |
| `25` | `0x19` | `GAMEOBJECT_TYPE_FISHINGHOLE` | Fishing hole |
| `26` | `0x1A` | `GAMEOBJECT_TYPE_FLAGDROP` | Flag drop |
| `27` | `0x1B` | `GAMEOBJECT_TYPE_MINI_GAME` | Mini game |
| `28` | `0x1C` | `GAMEOBJECT_TYPE_LOTTERY_KIOSK` | Lottery kiosk |
| `29` | `0x1D` | `GAMEOBJECT_TYPE_CAPTURE_POINT` | Capture point |
| `30` | `0x1E` | `GAMEOBJECT_TYPE_AURA_GENERATOR` | Aura generator |
