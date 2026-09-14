---
layout: default
title: auctionhousebot
---

# auctionhousebot

World database table `auctionhousebot`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | latin1 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-item"></a>`item` | `int(10) unsigned` | NO |  |  |  | Item Id; non-negative numeric value |
| <a id="col-stack"></a>`stack` | `tinyint(3) unsigned` | NO |  | `1` |  | Stack Size; non-negative numeric value |
| <a id="col-bid"></a>`bid` | `int(10) unsigned` | NO |  | `1` |  | Bid Price; non-negative numeric value |
| <a id="col-buyout"></a>`buyout` | `int(10) unsigned` | NO |  | `1` |  | Buyout Price; non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `item`

non-negative numeric value.

References: [`item_template`](item_template.md).`entry`.

### `stack`

non-negative numeric value.

### `bid`

non-negative numeric value.

### `buyout`

non-negative numeric value.

## Keys and Indexes

No keys were declared in the parsed CREATE TABLE statement.

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `item` | [`item_template`](item_template.md).`entry` | heuristic | item id |

