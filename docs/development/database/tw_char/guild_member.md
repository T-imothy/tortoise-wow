---
layout: default
title: guild_member
---

# guild_member

Guild System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 5 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guildid"></a>`guildid` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; identifier column |
| <a id="col-rank"></a>`rank` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-pnote"></a>`pnote` | `varchar(255)` | NO |  | `''` |  | text/string data |
| <a id="col-offnote"></a>`offnote` | `varchar(255)` | NO |  | `''` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guildid`

non-negative numeric value.

References: [`guild`](guild.md).`entry`.

### `guid`

non-negative numeric value; identifier column.

### `rank`

non-negative numeric value.

### `pnote`

text/string data.

### `offnote`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| UNIQUE | `key_guid` | `guid` |
| KEY | `idx_guildid` | `guildid` |
| KEY | `idx_guildid_rank` | `guildid`, `rank` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `guildid` | [`guild`](guild.md).`entry` | heuristic | inferred from column name |
