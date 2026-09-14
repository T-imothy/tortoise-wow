---
layout: default
title: guild_bank_money
---

# guild_bank_money

Character database table `guild_bank_money`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 3 | latin1 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guildid"></a>`guildid` | `int(11)` | NO | `PRI` |  |  | numeric value |
| <a id="col-isinferno"></a>`isInferno` | `tinyint(3) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-money"></a>`money` | `int(11)` | NO |  | `0` |  | numeric value; money/cost value, usually copper |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guildid`

numeric value.

References: [`guild`](guild.md).`entry`.

### `isInferno`

non-negative numeric value.

### `money`

numeric value; money/cost value, usually copper.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guildid`, `isInferno` |
| UNIQUE | `guildid` | `guildid`, `isInferno` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `guildid` | [`guild`](guild.md).`entry` | heuristic | inferred from column name |
