---
layout: default
title: petition_sign
---

# petition_sign

Guild System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-ownerguid"></a>`ownerguid` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-petitionguid"></a>`petitionguid` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-playerguid"></a>`playerguid` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-player-account"></a>`player_account` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `ownerguid`

non-negative numeric value.

### `petitionguid`

non-negative numeric value.

### `playerguid`

non-negative numeric value.

### `player_account`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `petitionguid`, `playerguid` |
| KEY | `idx_playerguid` | `playerguid` |
| KEY | `idx_ownerguid` | `ownerguid` |
