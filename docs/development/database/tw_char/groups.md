---
layout: default
title: groups
---

# groups

Groups

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 16 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-groupid"></a>`groupId` | `int(10) unsigned` | NO | `PRI` |  |  | non-negative numeric value |
| <a id="col-leaderguid"></a>`leaderGuid` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-maintank"></a>`mainTank` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-mainassistant"></a>`mainAssistant` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-lootmethod"></a>`lootMethod` | `tinyint(3) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-looterguid"></a>`looterGuid` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-lootthreshold"></a>`lootThreshold` | `tinyint(3) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-icon1"></a>`icon1` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-icon2"></a>`icon2` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-icon3"></a>`icon3` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-icon4"></a>`icon4` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-icon5"></a>`icon5` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-icon6"></a>`icon6` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-icon7"></a>`icon7` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-icon8"></a>`icon8` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-israid"></a>`isRaid` | `tinyint(1) unsigned` | NO |  |  |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `groupId`

non-negative numeric value.

### `leaderGuid`

non-negative numeric value.

### `mainTank`

non-negative numeric value.

### `mainAssistant`

non-negative numeric value.

### `lootMethod`

non-negative numeric value.

### `looterGuid`

non-negative numeric value.

### `lootThreshold`

non-negative numeric value.

### `icon1`

non-negative numeric value.

### `icon2`

non-negative numeric value.

### `icon3`

non-negative numeric value.

### `icon4`

non-negative numeric value.

### `icon5`

non-negative numeric value.

### `icon6`

non-negative numeric value.

### `icon7`

non-negative numeric value.

### `icon8`

non-negative numeric value.

### `isRaid`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `groupId` |
| UNIQUE | `key_leaderGuid` | `leaderGuid` |
