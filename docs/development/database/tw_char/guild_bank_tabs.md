---
layout: default
title: guild_bank_tabs
---

# guild_bank_tabs

Character database table `guild_bank_tabs`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 24 | latin1 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(11)` | NO | `PRI` |  | AUTO_INCREMENT | numeric value; identifier column |
| <a id="col-guildid"></a>`guildid` | `int(11)` | NO |  |  |  | numeric value |
| <a id="col-isinferno"></a>`isInferno` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-tabs"></a>`tabs` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-name1"></a>`name1` | `varchar(64)` | NO |  | `'Tab1'` |  | text/string data |
| <a id="col-name2"></a>`name2` | `varchar(64)` | NO |  | `'Tab2'` |  | text/string data |
| <a id="col-name3"></a>`name3` | `varchar(64)` | NO |  | `'Tab3'` |  | text/string data |
| <a id="col-name4"></a>`name4` | `varchar(64)` | NO |  | `'Tab4'` |  | text/string data |
| <a id="col-name5"></a>`name5` | `varchar(64)` | NO |  | `'Tab5'` |  | text/string data |
| <a id="col-icon1"></a>`icon1` | `varchar(128)` | NO |  | `'inv_misc_bag_08'` |  | text/string data |
| <a id="col-icon2"></a>`icon2` | `varchar(128)` | NO |  | `'inv_misc_bag_05'` |  | text/string data |
| <a id="col-icon3"></a>`icon3` | `varchar(128)` | NO |  | `'inv_misc_bag_03'` |  | text/string data |
| <a id="col-icon4"></a>`icon4` | `varchar(128)` | NO |  | `'inv_misc_bag_06'` |  | text/string data |
| <a id="col-icon5"></a>`icon5` | `varchar(128)` | NO |  | `'inv_misc_bag_02'` |  | text/string data |
| <a id="col-withdrawal1"></a>`withdrawal1` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-withdrawal2"></a>`withdrawal2` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-withdrawal3"></a>`withdrawal3` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-withdrawal4"></a>`withdrawal4` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-withdrawal5"></a>`withdrawal5` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-minrank1"></a>`minrank1` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-minrank2"></a>`minrank2` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-minrank3"></a>`minrank3` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-minrank4"></a>`minrank4` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-minrank5"></a>`minrank5` | `int(11)` | NO |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

numeric value; identifier column.

### `guildid`

numeric value.

References: [`guild`](guild.md).`entry`.

### `isInferno`

non-negative numeric value.

### `tabs`

numeric value.

### `name1`

text/string data.

### `name2`

text/string data.

### `name3`

text/string data.

### `name4`

text/string data.

### `name5`

text/string data.

### `icon1`

text/string data.

### `icon2`

text/string data.

### `icon3`

text/string data.

### `icon4`

text/string data.

### `icon5`

text/string data.

### `withdrawal1`

numeric value.

### `withdrawal2`

numeric value.

### `withdrawal3`

numeric value.

### `withdrawal4`

numeric value.

### `withdrawal5`

numeric value.

### `minrank1`

numeric value.

### `minrank2`

numeric value.

### `minrank3`

numeric value.

### `minrank4`

numeric value.

### `minrank5`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `guildid` | [`guild`](guild.md).`entry` | heuristic | inferred from column name |
