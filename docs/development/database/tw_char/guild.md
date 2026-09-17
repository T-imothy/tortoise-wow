---
layout: default
title: guild
---

# guild

Guild System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 11 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guildid"></a>`guildid` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-name"></a>`name` | `varchar(255)` | NO |  | `''` |  | text/string data |
| <a id="col-leaderguid"></a>`leaderguid` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-emblemstyle"></a>`EmblemStyle` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-emblemcolor"></a>`EmblemColor` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-borderstyle"></a>`BorderStyle` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-bordercolor"></a>`BorderColor` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-backgroundcolor"></a>`BackgroundColor` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-info"></a>`info` | `text` | NO |  |  |  | text/string data |
| <a id="col-motd"></a>`motd` | `varchar(255)` | NO |  | `''` |  | text/string data |
| <a id="col-createdate"></a>`createdate` | `bigint(20)` | NO |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guildid`

non-negative numeric value.

### `name`

text/string data.

### `leaderguid`

non-negative numeric value.

### `EmblemStyle`

numeric value.

### `EmblemColor`

numeric value.

### `BorderStyle`

numeric value.

### `BorderColor`

numeric value.

### `BackgroundColor`

numeric value.

### `info`

text/string data.

### `motd`

text/string data.

### `createdate`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guildid` |

## Related Tables

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`guild_house`](guild_house.md).`guild_id` | `entry` | heuristic | inferred from column name |
| [`guild_bank`](guild_bank.md).`guildid` | `entry` | heuristic | inferred from column name |
| [`guild_bank_analysis`](guild_bank_analysis.md).`guildid` | `entry` | heuristic | inferred from column name |
| [`guild_bank_log`](guild_bank_log.md).`guildid` | `entry` | heuristic | inferred from column name |
| [`guild_bank_money`](guild_bank_money.md).`guildid` | `entry` | heuristic | inferred from column name |
| [`guild_bank_tabs`](guild_bank_tabs.md).`guildid` | `entry` | heuristic | inferred from column name |
| [`guild_eventlog`](guild_eventlog.md).`guildid` | `entry` | heuristic | inferred from column name |
| [`guild_member`](guild_member.md).`guildid` | `entry` | heuristic | inferred from column name |
| [`guild_rank`](guild_rank.md).`guildid` | `entry` | heuristic | inferred from column name |
