---
layout: default
title: character_bgqueue
---

# character_bgqueue

Character database table `character_bgqueue`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 6 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-playerguid"></a>`PlayerGUID` | `int(11)` | NO | `PRI` | `0` |  | numeric value |
| <a id="col-playername"></a>`playerName` | `varchar(12)` | NO |  |  |  | text/string data |
| <a id="col-playerip"></a>`playerIP` | `int(11)` | NO |  |  |  | numeric value |
| <a id="col-bgtype"></a>`BGtype` | `int(11)` | NO |  |  |  | numeric value |
| <a id="col-action"></a>`action` | `int(11)` | NO |  |  |  | numeric value |
| <a id="col-time"></a>`time` | `int(11)` | NO |  |  |  | numeric value; time/delay value; confirm unit in server usage |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `PlayerGUID`

numeric value.

### `playerName`

text/string data.

### `playerIP`

numeric value.

### `BGtype`

numeric value.

### `action`

numeric value.

### `time`

numeric value; time/delay value; confirm unit in server usage.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `PlayerGUID` |
