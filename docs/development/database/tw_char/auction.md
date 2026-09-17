---
layout: default
title: auction
---

# auction

Character database table `auction`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 11 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-houseid"></a>`houseid` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-itemguid"></a>`itemguid` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-item-template"></a>`item_template` | `int(10) unsigned` | NO |  | `0` |  | Item Identifier; non-negative numeric value |
| <a id="col-itemowner"></a>`itemowner` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-buyoutprice"></a>`buyoutprice` | `int(11)` | NO |  | `0` |  | numeric value; money/cost value, usually copper |
| <a id="col-time"></a>`time` | `bigint(20)` | NO |  | `0` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-buyguid"></a>`buyguid` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-lastbid"></a>`lastbid` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-startbid"></a>`startbid` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-deposit"></a>`deposit` | `int(11)` | NO |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `houseid`

non-negative numeric value.

### `itemguid`

non-negative numeric value.

### `item_template`

non-negative numeric value.

### `itemowner`

non-negative numeric value.

### `buyoutprice`

numeric value; money/cost value, usually copper.

### `time`

numeric value; time/delay value; confirm unit in server usage.

### `buyguid`

non-negative numeric value.

### `lastbid`

numeric value.

### `startbid`

numeric value.

### `deposit`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |
| UNIQUE | `key_item_guid` | `itemguid` |
