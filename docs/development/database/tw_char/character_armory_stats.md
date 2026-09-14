---
layout: default
title: character_armory_stats
---

# character_armory_stats

Character database table `character_armory_stats`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 41 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-maxhealth"></a>`maxhealth` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-maxpower1"></a>`maxpower1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-maxpower2"></a>`maxpower2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-maxpower3"></a>`maxpower3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-maxpower4"></a>`maxpower4` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-maxpower5"></a>`maxpower5` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-strength"></a>`strength` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-agility"></a>`agility` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-stamina"></a>`stamina` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-intellect"></a>`intellect` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-spirit"></a>`spirit` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-armor"></a>`armor` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-resholy"></a>`resHoly` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-resfire"></a>`resFire` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-resnature"></a>`resNature` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-resfrost"></a>`resFrost` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-resshadow"></a>`resShadow` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-resarcane"></a>`resArcane` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-dmgmodnormal"></a>`dmgModNormal` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-dmgmodholy"></a>`dmgModHoly` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-dmgmodfire"></a>`dmgModFire` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-dmgmodnature"></a>`dmgModNature` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-dmgmodfrost"></a>`dmgModFrost` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-dmgmodshadow"></a>`dmgModShadow` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-dmgmodarcane"></a>`dmgModArcane` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-blockpct"></a>`blockPct` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-dodgepct"></a>`dodgePct` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-parrypct"></a>`parryPct` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-meleecritpct"></a>`meleeCritPct` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-rangedcritpct"></a>`rangedCritPct` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-attackpower"></a>`attackPower` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-rangedattackpower"></a>`rangedAttackPower` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-meleedamage"></a>`meleeDamage` | `text` | NO |  |  |  | text/string data |
| <a id="col-rangeddamage"></a>`rangedDamage` | `text` | NO |  |  |  | text/string data |
| <a id="col-meleeweaponspeed"></a>`meleeWeaponSpeed` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-rangedweaponspeed"></a>`rangedWeaponSpeed` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-castspeed"></a>`castSpeed` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-meleehit"></a>`meleeHit` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-rangedhit"></a>`rangedHit` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-spellhit"></a>`spellHit` | `float` | NO |  | `0` |  | numeric value |

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

### `strength`

numeric value.

### `agility`

numeric value.

### `stamina`

numeric value.

### `intellect`

numeric value.

### `spirit`

numeric value.

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

### `dmgModNormal`

non-negative numeric value.

### `dmgModHoly`

non-negative numeric value.

### `dmgModFire`

non-negative numeric value.

### `dmgModNature`

non-negative numeric value.

### `dmgModFrost`

non-negative numeric value.

### `dmgModShadow`

non-negative numeric value.

### `dmgModArcane`

non-negative numeric value.

### `blockPct`

numeric value.

### `dodgePct`

numeric value.

### `parryPct`

numeric value.

### `meleeCritPct`

numeric value.

### `rangedCritPct`

numeric value.

### `attackPower`

numeric value.

### `rangedAttackPower`

numeric value.

### `meleeDamage`

text/string data.

### `rangedDamage`

text/string data.

### `meleeWeaponSpeed`

numeric value.

### `rangedWeaponSpeed`

numeric value.

### `castSpeed`

numeric value.

### `meleeHit`

numeric value.

### `rangedHit`

numeric value.

### `spellHit`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid` |
