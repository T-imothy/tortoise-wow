---
layout: default
title: item_instance
---

# item_instance

Item System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 15 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-itementry"></a>`itemEntry` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-owner-guid"></a>`owner_guid` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-creatorguid"></a>`creatorGuid` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-giftcreatorguid"></a>`giftCreatorGuid` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-count"></a>`count` | `int(10) unsigned` | NO |  | `1` |  | non-negative numeric value |
| <a id="col-duration"></a>`duration` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-charges"></a>`charges` | `tinytext` | YES |  | `NULL` |  | text/string data |
| <a id="col-flags"></a>`flags` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-enchantments"></a>`enchantments` | `text` | NO |  |  |  | text/string data |
| <a id="col-randompropertyid"></a>`randomPropertyId` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-transmogrifyid"></a>`transmogrifyId` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-durability"></a>`durability` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-text"></a>`text` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-generated-loot"></a>`generated_loot` | `tinyint(4)` | YES |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `itemEntry`

non-negative numeric value.

### `owner_guid`

non-negative numeric value.

### `creatorGuid`

non-negative numeric value.

### `giftCreatorGuid`

non-negative numeric value.

### `count`

non-negative numeric value.

### `duration`

numeric value.

### `charges`

text/string data.

### `flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

### `enchantments`

text/string data.

### `randomPropertyId`

numeric value.

### `transmogrifyId`

non-negative numeric value.

### `durability`

non-negative numeric value.

### `text`

non-negative numeric value.

### `generated_loot`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid` |
| KEY | `idx_owner_guid` | `owner_guid` |
| KEY | `idx_itemEntry` | `itemEntry` |

## Masks and Flags

### Unmapped Flag-Like Columns

| Column | Type | Guidance |
| --- | --- | --- |
| [`flags`](#col-flags) | `mediumint(8) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
