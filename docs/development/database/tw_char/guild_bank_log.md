---
layout: default
title: guild_bank_log
---

# guild_bank_log

Character database table `guild_bank_log`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 11 | latin1 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-log-id"></a>`log_id` | `int(11)` | NO | `PRI` |  | AUTO_INCREMENT | numeric value |
| <a id="col-isinferno"></a>`isInferno` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-guildid"></a>`guildid` | `int(11)` | NO |  |  |  | numeric value |
| <a id="col-player"></a>`player` | `int(11)` | NO |  |  |  | numeric value |
| <a id="col-action"></a>`action` | `int(11)` | NO |  |  |  | numeric value |
| <a id="col-tab"></a>`tab` | `int(11)` | NO |  | `1` |  | numeric value |
| <a id="col-item"></a>`item` | `int(11)` | NO |  |  |  | numeric value |
| <a id="col-randompropertyid"></a>`randomPropertyId` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-enchant"></a>`enchant` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-count"></a>`count` | `int(11)` | NO |  |  |  | numeric value |
| <a id="col-stamp"></a>`stamp` | `bigint(20)` | NO |  |  |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `log_id`

numeric value.

### `isInferno`

non-negative numeric value.

### `guildid`

numeric value.

References: [`guild`](guild.md).`entry`.

### `player`

numeric value.

### `action`

numeric value.

### `tab`

numeric value.

### `item`

numeric value.

References: [`item_template`](../tw_world/item_template.md).`entry`.

### `randomPropertyId`

numeric value.

### `enchant`

numeric value.

### `count`

numeric value.

### `stamp`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `log_id` |
| KEY | `stamp` | `stamp`, `isInferno` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `guildid` | [`guild`](guild.md).`entry` | heuristic | inferred from column name |
| `item` | [`item_template`](../tw_world/item_template.md).`entry` | heuristic | inferred from column name |
