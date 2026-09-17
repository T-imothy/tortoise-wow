---
layout: default
title: chat_channels
---

# chat_channels

World database table `chat_channels`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 21 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(11)` | NO | `PRI` | `0` |  | numeric value; identifier column |
| <a id="col-flags"></a>`flags` | `int(11)` | NO |  | `0` |  | numeric value; mask/flags column; combine values with bitwise OR; Uses ChannelFlags mask values |
| <a id="col-faction-group"></a>`faction_group` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-name"></a>`name` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-name-loc1"></a>`name_loc1` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-name-loc2"></a>`name_loc2` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-name-loc3"></a>`name_loc3` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-name-loc4"></a>`name_loc4` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-name-loc5"></a>`name_loc5` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-name-loc6"></a>`name_loc6` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-name-loc7"></a>`name_loc7` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-name-flags"></a>`name_flags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-shortcut"></a>`shortcut` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-shortcut-loc1"></a>`shortcut_loc1` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-shortcut-loc2"></a>`shortcut_loc2` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-shortcut-loc3"></a>`shortcut_loc3` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-shortcut-loc4"></a>`shortcut_loc4` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-shortcut-loc5"></a>`shortcut_loc5` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-shortcut-loc6"></a>`shortcut_loc6` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-shortcut-loc7"></a>`shortcut_loc7` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-shortcut-flags"></a>`shortcut_flags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

numeric value; identifier column.

### `flags`

numeric value; mask/flags column; combine values with bitwise OR.

Value set: `ChannelFlags` (mask) from `src/game/Chat/Channel.h enum ChannelFlags`.

### `faction_group`

numeric value.

### `name`

text/string data.

### `name_loc1`

text/string data.

### `name_loc2`

text/string data.

### `name_loc3`

text/string data.

### `name_loc4`

text/string data.

### `name_loc5`

text/string data.

### `name_loc6`

text/string data.

### `name_loc7`

text/string data.

### `name_flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

### `shortcut`

text/string data.

### `shortcut_loc1`

text/string data.

### `shortcut_loc2`

text/string data.

### `shortcut_loc3`

text/string data.

### `shortcut_loc4`

text/string data.

### `shortcut_loc5`

text/string data.

### `shortcut_loc6`

text/string data.

### `shortcut_loc7`

text/string data.

### `shortcut_flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `ChannelFlags` | mask | [`flags`](#col-flags) | `src/game/Chat/Channel.h enum ChannelFlags` | 9 |

### Possible Values

Used by: [`flags`](#col-flags)

#### `ChannelFlags`

Kind: `mask`

Source: `src/game/Chat/Channel.h enum ChannelFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `CHANNEL_FLAG_NONE` | Channel Flag None |
| `1` | `0x1` | `CHANNEL_FLAG_CUSTOM` | Channel Flag Custom |
| `4` | `0x4` | `CHANNEL_FLAG_TRADE` | Channel Flag Trade |
| `8` | `0x8` | `CHANNEL_FLAG_NOT_LFG` | Channel Flag Not Lfg |
| `16` | `0x10` | `CHANNEL_FLAG_GENERAL` | Channel Flag General |
| `32` | `0x20` | `CHANNEL_FLAG_CITY` | Channel Flag City |
| `64` | `0x40` | `CHANNEL_FLAG_LFG` | Channel Flag Lfg |
| `128` | `0x80` | `CHANNEL_FLAG_VOICE` | Channel Flag Voice |
| `256` | `0x100` | `CHANNEL_FLAG_NATIONAL` | Channel Flag National |

### Unmapped Flag-Like Columns

| Column | Type | Guidance |
| --- | --- | --- |
| [`name_flags`](#col-name-flags) | `int(10) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
| [`shortcut_flags`](#col-shortcut-flags) | `int(10) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
