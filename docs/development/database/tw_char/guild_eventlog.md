---
layout: default
title: guild_eventlog
---

# guild_eventlog

Guild Eventlog

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 7 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guildid"></a>`guildid` | `int(11)` | NO | `PRI` |  |  | Guild Identificator; numeric value |
| <a id="col-logguid"></a>`LogGuid` | `int(11)` | NO | `PRI` |  |  | Log record identificator - auxiliary column; numeric value |
| <a id="col-eventtype"></a>`EventType` | `tinyint(1)` | NO |  |  |  | Event type; numeric value |
| <a id="col-playerguid1"></a>`PlayerGuid1` | `int(11)` | NO |  |  |  | Player 1; numeric value |
| <a id="col-playerguid2"></a>`PlayerGuid2` | `int(11)` | NO |  |  |  | Player 2; numeric value |
| <a id="col-newrank"></a>`NewRank` | `tinyint(4)` | NO |  |  |  | New rank(in case promotion/demotion); numeric value |
| <a id="col-timestamp"></a>`TimeStamp` | `bigint(20)` | NO |  |  |  | Event UNIX time; numeric value; time/delay value; confirm unit in server usage |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guildid`

numeric value.

References: [`guild`](guild.md).`entry`.

### `LogGuid`

numeric value.

### `EventType`

numeric value.

### `PlayerGuid1`

numeric value.

### `PlayerGuid2`

numeric value.

### `NewRank`

numeric value.

### `TimeStamp`

numeric value; time/delay value; confirm unit in server usage.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guildid`, `LogGuid` |
| KEY | `idx_PlayerGuid1` | `PlayerGuid1` |
| KEY | `idx_PlayerGuid2` | `PlayerGuid2` |
| KEY | `idx_LogGuid` | `LogGuid` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `guildid` | [`guild`](guild.md).`entry` | heuristic | inferred from column name |
