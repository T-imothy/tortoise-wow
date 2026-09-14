---
layout: default
title: character_stats
---

# character_stats

Character database table `character_stats`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 28 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | Global Unique Identifier, Low part; non-negative numeric value; identifier column |
| <a id="col-maxhealth"></a>`maxhealth` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-maxpower1"></a>`maxpower1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-maxpower2"></a>`maxpower2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-maxpower3"></a>`maxpower3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-maxpower4"></a>`maxpower4` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-maxpower5"></a>`maxpower5` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-maxpower6"></a>`maxpower6` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-maxpower7"></a>`maxpower7` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-strength"></a>`strength` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-agility"></a>`agility` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-stamina"></a>`stamina` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-intellect"></a>`intellect` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spirit"></a>`spirit` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-armor"></a>`armor` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-resholy"></a>`resHoly` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-resfire"></a>`resFire` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-resnature"></a>`resNature` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-resfrost"></a>`resFrost` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-resshadow"></a>`resShadow` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-resarcane"></a>`resArcane` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-blockpct"></a>`blockPct` | `float unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-dodgepct"></a>`dodgePct` | `float unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-parrypct"></a>`parryPct` | `float unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-critpct"></a>`critPct` | `float unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rangedcritpct"></a>`rangedCritPct` | `float unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-attackpower"></a>`attackPower` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rangedattackpower"></a>`rangedAttackPower` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `maxhealth`

non-negative numeric value.

### `maxpower1`

non-negative numeric value.

### `maxpower2`

non-negative numeric value.

### `maxpower3`

non-negative numeric value.

### `maxpower4`

non-negative numeric value.

### `maxpower5`

non-negative numeric value.

### `maxpower6`

non-negative numeric value.

### `maxpower7`

non-negative numeric value.

### `strength`

non-negative numeric value.

### `agility`

non-negative numeric value.

### `stamina`

non-negative numeric value.

### `intellect`

non-negative numeric value.

### `spirit`

non-negative numeric value.

### `armor`

non-negative numeric value.

### `resHoly`

non-negative numeric value.

### `resFire`

non-negative numeric value.

### `resNature`

non-negative numeric value.

### `resFrost`

non-negative numeric value.

### `resShadow`

non-negative numeric value.

### `resArcane`

non-negative numeric value.

### `blockPct`

non-negative numeric value.

### `dodgePct`

non-negative numeric value.

### `parryPct`

non-negative numeric value.

### `critPct`

non-negative numeric value.

### `rangedCritPct`

non-negative numeric value.

### `attackPower`

non-negative numeric value.

### `rangedAttackPower`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid` |
