---
layout: default
title: character_egg_loot
---

# character_egg_loot

Character database table `character_egg_loot`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 5 | utf8mb3 | default |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`Id` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | non-negative numeric value; identifier column |
| <a id="col-playerguid"></a>`playerGuid` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-itementry"></a>`itemEntry` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-itemguid"></a>`itemGuid` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-refunded"></a>`refunded` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `Id`

non-negative numeric value; identifier column.

### `playerGuid`

non-negative numeric value.

### `itemEntry`

non-negative numeric value.

### `itemGuid`

non-negative numeric value.

### `refunded`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `Id` |
