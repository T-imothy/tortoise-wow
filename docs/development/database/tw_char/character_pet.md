---
layout: default
title: character_pet
---

# character_pet

Pet System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 23 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-entry"></a>`entry` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; identifier column |
| <a id="col-owner"></a>`owner` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-modelid"></a>`modelid` | `int(10) unsigned` | YES |  | `0` |  | non-negative numeric value |
| <a id="col-createdbyspell"></a>`CreatedBySpell` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-pettype"></a>`PetType` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-level"></a>`level` | `int(10) unsigned` | NO |  | `1` |  | non-negative numeric value |
| <a id="col-exp"></a>`exp` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reactstate"></a>`Reactstate` | `tinyint(1) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-loyaltypoints"></a>`loyaltypoints` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-loyalty"></a>`loyalty` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-trainpoint"></a>`trainpoint` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-name"></a>`name` | `varchar(100)` | YES |  | `'Pet'` |  | text/string data |
| <a id="col-renamed"></a>`renamed` | `tinyint(1) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-slot"></a>`slot` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-curhealth"></a>`curhealth` | `int(10) unsigned` | NO |  | `1` |  | non-negative numeric value |
| <a id="col-curmana"></a>`curmana` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-curhappiness"></a>`curhappiness` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-savetime"></a>`savetime` | `bigint(20) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-resettalents-cost"></a>`resettalents_cost` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-resettalents-time"></a>`resettalents_time` | `bigint(20) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-abdata"></a>`abdata` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-teachspelldata"></a>`teachspelldata` | `longtext` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `entry`

non-negative numeric value; identifier column.

### `owner`

non-negative numeric value.

### `modelid`

non-negative numeric value.

### `CreatedBySpell`

non-negative numeric value.

### `PetType`

non-negative numeric value.

### `level`

non-negative numeric value.

### `exp`

non-negative numeric value.

### `Reactstate`

non-negative numeric value.

### `loyaltypoints`

numeric value.

### `loyalty`

non-negative numeric value.

### `trainpoint`

numeric value.

### `name`

text/string data.

### `renamed`

non-negative numeric value.

### `slot`

non-negative numeric value.

### `curhealth`

non-negative numeric value.

### `curmana`

non-negative numeric value.

### `curhappiness`

non-negative numeric value.

### `savetime`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `resettalents_cost`

non-negative numeric value; money/cost value, usually copper.

### `resettalents_time`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `abdata`

text/string data.

### `teachspelldata`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |
| KEY | `idx_owner` | `owner` |
