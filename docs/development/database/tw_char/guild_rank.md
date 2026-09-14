---
layout: default
title: guild_rank
---

# guild_rank

Guild System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guildid"></a>`guildid` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-rid"></a>`rid` | `int(10) unsigned` | NO | `PRI` |  |  | non-negative numeric value |
| <a id="col-rname"></a>`rname` | `varchar(255)` | NO |  | `''` |  | text/string data |
| <a id="col-rights"></a>`rights` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guildid`

non-negative numeric value.

References: [`guild`](guild.md).`entry`.

### `rid`

non-negative numeric value.

### `rname`

text/string data.

### `rights`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guildid`, `rid` |
| KEY | `idx_rid` | `rid` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `guildid` | [`guild`](guild.md).`entry` | heuristic | inferred from column name |
