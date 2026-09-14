---
layout: default
title: creature_spells
---

# creature_spells

World database table `creature_spells`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 90 | latin1 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-name"></a>`name` | `varchar(255)` | NO |  | `''` |  | text/string data |
| <a id="col-spellid-1"></a>`spellId_1` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-probability-1"></a>`probability_1` | `tinyint(3) unsigned` | NO |  | `100` |  | non-negative numeric value |
| <a id="col-casttarget-1"></a>`castTarget_1` | `tinyint(3) unsigned` | NO |  | `1` |  | non-negative numeric value; Uses ScriptTarget enum values |
| <a id="col-targetparam1-1"></a>`targetParam1_1` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-targetparam2-1"></a>`targetParam2_1` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-castflags-1"></a>`castFlags_1` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses CastFlags mask values |
| <a id="col-delayinitialmin-1"></a>`delayInitialMin_1` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayinitialmax-1"></a>`delayInitialMax_1` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayrepeatmin-1"></a>`delayRepeatMin_1` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayrepeatmax-1"></a>`delayRepeatMax_1` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-scriptid-1"></a>`scriptId_1` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; script id or script name |
| <a id="col-spellid-2"></a>`spellId_2` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-probability-2"></a>`probability_2` | `tinyint(3) unsigned` | NO |  | `100` |  | non-negative numeric value |
| <a id="col-casttarget-2"></a>`castTarget_2` | `tinyint(3) unsigned` | NO |  | `1` |  | non-negative numeric value; Uses ScriptTarget enum values |
| <a id="col-targetparam1-2"></a>`targetParam1_2` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-targetparam2-2"></a>`targetParam2_2` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-castflags-2"></a>`castFlags_2` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses CastFlags mask values |
| <a id="col-delayinitialmin-2"></a>`delayInitialMin_2` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayinitialmax-2"></a>`delayInitialMax_2` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayrepeatmin-2"></a>`delayRepeatMin_2` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayrepeatmax-2"></a>`delayRepeatMax_2` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-scriptid-2"></a>`scriptId_2` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; script id or script name |
| <a id="col-spellid-3"></a>`spellId_3` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-probability-3"></a>`probability_3` | `tinyint(3) unsigned` | NO |  | `100` |  | non-negative numeric value |
| <a id="col-casttarget-3"></a>`castTarget_3` | `tinyint(3) unsigned` | NO |  | `1` |  | non-negative numeric value; Uses ScriptTarget enum values |
| <a id="col-targetparam1-3"></a>`targetParam1_3` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-targetparam2-3"></a>`targetParam2_3` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-castflags-3"></a>`castFlags_3` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses CastFlags mask values |
| <a id="col-delayinitialmin-3"></a>`delayInitialMin_3` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayinitialmax-3"></a>`delayInitialMax_3` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayrepeatmin-3"></a>`delayRepeatMin_3` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayrepeatmax-3"></a>`delayRepeatMax_3` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-scriptid-3"></a>`scriptId_3` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; script id or script name |
| <a id="col-spellid-4"></a>`spellId_4` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-probability-4"></a>`probability_4` | `tinyint(3) unsigned` | NO |  | `100` |  | non-negative numeric value |
| <a id="col-casttarget-4"></a>`castTarget_4` | `tinyint(3) unsigned` | NO |  | `1` |  | non-negative numeric value; Uses ScriptTarget enum values |
| <a id="col-targetparam1-4"></a>`targetParam1_4` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-targetparam2-4"></a>`targetParam2_4` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-castflags-4"></a>`castFlags_4` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses CastFlags mask values |
| <a id="col-delayinitialmin-4"></a>`delayInitialMin_4` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayinitialmax-4"></a>`delayInitialMax_4` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayrepeatmin-4"></a>`delayRepeatMin_4` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayrepeatmax-4"></a>`delayRepeatMax_4` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-scriptid-4"></a>`scriptId_4` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; script id or script name |
| <a id="col-spellid-5"></a>`spellId_5` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-probability-5"></a>`probability_5` | `tinyint(3) unsigned` | NO |  | `100` |  | non-negative numeric value |
| <a id="col-casttarget-5"></a>`castTarget_5` | `tinyint(3) unsigned` | NO |  | `1` |  | non-negative numeric value; Uses ScriptTarget enum values |
| <a id="col-targetparam1-5"></a>`targetParam1_5` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-targetparam2-5"></a>`targetParam2_5` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-castflags-5"></a>`castFlags_5` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses CastFlags mask values |
| <a id="col-delayinitialmin-5"></a>`delayInitialMin_5` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayinitialmax-5"></a>`delayInitialMax_5` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayrepeatmin-5"></a>`delayRepeatMin_5` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayrepeatmax-5"></a>`delayRepeatMax_5` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-scriptid-5"></a>`scriptId_5` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; script id or script name |
| <a id="col-spellid-6"></a>`spellId_6` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-probability-6"></a>`probability_6` | `tinyint(3) unsigned` | NO |  | `100` |  | non-negative numeric value |
| <a id="col-casttarget-6"></a>`castTarget_6` | `tinyint(3) unsigned` | NO |  | `1` |  | non-negative numeric value; Uses ScriptTarget enum values |
| <a id="col-targetparam1-6"></a>`targetParam1_6` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-targetparam2-6"></a>`targetParam2_6` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-castflags-6"></a>`castFlags_6` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses CastFlags mask values |
| <a id="col-delayinitialmin-6"></a>`delayInitialMin_6` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayinitialmax-6"></a>`delayInitialMax_6` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayrepeatmin-6"></a>`delayRepeatMin_6` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayrepeatmax-6"></a>`delayRepeatMax_6` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-scriptid-6"></a>`scriptId_6` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; script id or script name |
| <a id="col-spellid-7"></a>`spellId_7` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-probability-7"></a>`probability_7` | `tinyint(3) unsigned` | NO |  | `100` |  | non-negative numeric value |
| <a id="col-casttarget-7"></a>`castTarget_7` | `tinyint(3) unsigned` | NO |  | `1` |  | non-negative numeric value; Uses ScriptTarget enum values |
| <a id="col-targetparam1-7"></a>`targetParam1_7` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-targetparam2-7"></a>`targetParam2_7` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-castflags-7"></a>`castFlags_7` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses CastFlags mask values |
| <a id="col-delayinitialmin-7"></a>`delayInitialMin_7` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayinitialmax-7"></a>`delayInitialMax_7` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayrepeatmin-7"></a>`delayRepeatMin_7` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayrepeatmax-7"></a>`delayRepeatMax_7` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-scriptid-7"></a>`scriptId_7` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; script id or script name |
| <a id="col-spellid-8"></a>`spellId_8` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-probability-8"></a>`probability_8` | `tinyint(3) unsigned` | NO |  | `100` |  | non-negative numeric value |
| <a id="col-casttarget-8"></a>`castTarget_8` | `tinyint(3) unsigned` | NO |  | `1` |  | non-negative numeric value; Uses ScriptTarget enum values |
| <a id="col-targetparam1-8"></a>`targetParam1_8` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-targetparam2-8"></a>`targetParam2_8` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-castflags-8"></a>`castFlags_8` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses CastFlags mask values |
| <a id="col-delayinitialmin-8"></a>`delayInitialMin_8` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayinitialmax-8"></a>`delayInitialMax_8` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayrepeatmin-8"></a>`delayRepeatMin_8` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-delayrepeatmax-8"></a>`delayRepeatMax_8` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-scriptid-8"></a>`scriptId_8` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; script id or script name |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `name`

text/string data.

### `spellId_1`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `probability_1`

non-negative numeric value.

### `castTarget_1`

non-negative numeric value.

Value set: `ScriptTarget` (enum) from `src/game/ScriptMgr.h enum ScriptTarget`.

### `targetParam1_1`

non-negative numeric value.


### `targetParam2_1`

non-negative numeric value.

### `castFlags_1`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `CastFlags` (mask) from `src/game/ScriptMgr.h enum CastFlags`.

### `delayInitialMin_1`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayInitialMax_1`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayRepeatMin_1`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayRepeatMax_1`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `scriptId_1`

non-negative numeric value; script id or script name.

References: [`creature_spells_scripts`](creature_spells_scripts.md).`id`.

### `spellId_2`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `probability_2`

non-negative numeric value.

### `castTarget_2`

non-negative numeric value.

Value set: `ScriptTarget` (enum) from `src/game/ScriptMgr.h enum ScriptTarget`.

### `targetParam1_2`

non-negative numeric value.


### `targetParam2_2`

non-negative numeric value.

### `castFlags_2`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `CastFlags` (mask) from `src/game/ScriptMgr.h enum CastFlags`.

### `delayInitialMin_2`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayInitialMax_2`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayRepeatMin_2`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayRepeatMax_2`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `scriptId_2`

non-negative numeric value; script id or script name.

References: [`creature_spells_scripts`](creature_spells_scripts.md).`id`.

### `spellId_3`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `probability_3`

non-negative numeric value.

### `castTarget_3`

non-negative numeric value.

Value set: `ScriptTarget` (enum) from `src/game/ScriptMgr.h enum ScriptTarget`.

### `targetParam1_3`

non-negative numeric value.


### `targetParam2_3`

non-negative numeric value.

### `castFlags_3`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `CastFlags` (mask) from `src/game/ScriptMgr.h enum CastFlags`.

### `delayInitialMin_3`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayInitialMax_3`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayRepeatMin_3`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayRepeatMax_3`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `scriptId_3`

non-negative numeric value; script id or script name.

References: [`creature_spells_scripts`](creature_spells_scripts.md).`id`.

### `spellId_4`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `probability_4`

non-negative numeric value.

### `castTarget_4`

non-negative numeric value.

Value set: `ScriptTarget` (enum) from `src/game/ScriptMgr.h enum ScriptTarget`.

### `targetParam1_4`

non-negative numeric value.


### `targetParam2_4`

non-negative numeric value.

### `castFlags_4`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `CastFlags` (mask) from `src/game/ScriptMgr.h enum CastFlags`.

### `delayInitialMin_4`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayInitialMax_4`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayRepeatMin_4`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayRepeatMax_4`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `scriptId_4`

non-negative numeric value; script id or script name.

References: [`creature_spells_scripts`](creature_spells_scripts.md).`id`.

### `spellId_5`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `probability_5`

non-negative numeric value.

### `castTarget_5`

non-negative numeric value.

Value set: `ScriptTarget` (enum) from `src/game/ScriptMgr.h enum ScriptTarget`.

### `targetParam1_5`

non-negative numeric value.


### `targetParam2_5`

non-negative numeric value.

### `castFlags_5`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `CastFlags` (mask) from `src/game/ScriptMgr.h enum CastFlags`.

### `delayInitialMin_5`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayInitialMax_5`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayRepeatMin_5`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayRepeatMax_5`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `scriptId_5`

non-negative numeric value; script id or script name.

References: [`creature_spells_scripts`](creature_spells_scripts.md).`id`.

### `spellId_6`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `probability_6`

non-negative numeric value.

### `castTarget_6`

non-negative numeric value.

Value set: `ScriptTarget` (enum) from `src/game/ScriptMgr.h enum ScriptTarget`.

### `targetParam1_6`

non-negative numeric value.


### `targetParam2_6`

non-negative numeric value.

### `castFlags_6`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `CastFlags` (mask) from `src/game/ScriptMgr.h enum CastFlags`.

### `delayInitialMin_6`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayInitialMax_6`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayRepeatMin_6`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayRepeatMax_6`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `scriptId_6`

non-negative numeric value; script id or script name.

References: [`creature_spells_scripts`](creature_spells_scripts.md).`id`.

### `spellId_7`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `probability_7`

non-negative numeric value.

### `castTarget_7`

non-negative numeric value.

Value set: `ScriptTarget` (enum) from `src/game/ScriptMgr.h enum ScriptTarget`.

### `targetParam1_7`

non-negative numeric value.


### `targetParam2_7`

non-negative numeric value.

### `castFlags_7`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `CastFlags` (mask) from `src/game/ScriptMgr.h enum CastFlags`.

### `delayInitialMin_7`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayInitialMax_7`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayRepeatMin_7`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayRepeatMax_7`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `scriptId_7`

non-negative numeric value; script id or script name.

References: [`creature_spells_scripts`](creature_spells_scripts.md).`id`.

### `spellId_8`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `probability_8`

non-negative numeric value.

### `castTarget_8`

non-negative numeric value.

Value set: `ScriptTarget` (enum) from `src/game/ScriptMgr.h enum ScriptTarget`.

### `targetParam1_8`

non-negative numeric value.


### `targetParam2_8`

non-negative numeric value.

### `castFlags_8`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `CastFlags` (mask) from `src/game/ScriptMgr.h enum CastFlags`.

### `delayInitialMin_8`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayInitialMax_8`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayRepeatMin_8`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `delayRepeatMax_8`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `scriptId_8`

non-negative numeric value; script id or script name.

References: [`creature_spells_scripts`](creature_spells_scripts.md).`id`.

## Table-Specific Details

### Target Parameter Notes

`targetParam1_N` and `targetParam2_N` are interpreted according to `castTarget_N`, not as one global enum or mask. `ObjectMgr::LoadCreatureSpells` passes `castTarget_N`, `targetParam1_N`, and `targetParam2_N` to `ScriptMgr::CheckScriptTargets`; only hostile random target types use `targetParam1_N` as a `SelectFlags` mask.

Source: `src/game/ObjectMgr.cpp ObjectMgr::LoadCreatureSpells`; `src/game/ScriptMgr.cpp ScriptMgr::CheckScriptTargets`; `src/game/ScriptMgr.h enum ScriptTarget`; `src/game/Objects/Creature.h enum SelectFlags`.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `scriptId_1` | [`creature_spells_scripts`](creature_spells_scripts.md).`id` | explicit | post-cast script |
| `scriptId_2` | [`creature_spells_scripts`](creature_spells_scripts.md).`id` | explicit | post-cast script |
| `scriptId_3` | [`creature_spells_scripts`](creature_spells_scripts.md).`id` | explicit | post-cast script |
| `scriptId_4` | [`creature_spells_scripts`](creature_spells_scripts.md).`id` | explicit | post-cast script |
| `scriptId_5` | [`creature_spells_scripts`](creature_spells_scripts.md).`id` | explicit | post-cast script |
| `scriptId_6` | [`creature_spells_scripts`](creature_spells_scripts.md).`id` | explicit | post-cast script |
| `scriptId_7` | [`creature_spells_scripts`](creature_spells_scripts.md).`id` | explicit | post-cast script |
| `scriptId_8` | [`creature_spells_scripts`](creature_spells_scripts.md).`id` | explicit | post-cast script |
| `spellId_1` | [`spell_template`](spell_template.md).`entry` | explicit | AI spell slot |
| `spellId_2` | [`spell_template`](spell_template.md).`entry` | explicit | AI spell slot |
| `spellId_3` | [`spell_template`](spell_template.md).`entry` | explicit | AI spell slot |
| `spellId_4` | [`spell_template`](spell_template.md).`entry` | explicit | AI spell slot |
| `spellId_5` | [`spell_template`](spell_template.md).`entry` | explicit | AI spell slot |
| `spellId_6` | [`spell_template`](spell_template.md).`entry` | explicit | AI spell slot |
| `spellId_7` | [`spell_template`](spell_template.md).`entry` | explicit | AI spell slot |
| `spellId_8` | [`spell_template`](spell_template.md).`entry` | explicit | AI spell slot |

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`creature_template`](creature_template.md).`spell_list_id` | `entry` | explicit | AI spell list |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `CastFlags` | mask | [`castFlags_1`](#col-castflags-1), [`castFlags_2`](#col-castflags-2), [`castFlags_3`](#col-castflags-3), [`castFlags_4`](#col-castflags-4), [`castFlags_5`](#col-castflags-5), [`castFlags_6`](#col-castflags-6), [`castFlags_7`](#col-castflags-7), [`castFlags_8`](#col-castflags-8) | `src/game/ScriptMgr.h enum CastFlags` | 10 |
| `ScriptTarget` | enum | [`castTarget_1`](#col-casttarget-1), [`castTarget_2`](#col-casttarget-2), [`castTarget_3`](#col-casttarget-3), [`castTarget_4`](#col-casttarget-4), [`castTarget_5`](#col-casttarget-5), [`castTarget_6`](#col-casttarget-6), [`castTarget_7`](#col-casttarget-7), [`castTarget_8`](#col-casttarget-8) | `src/game/ScriptMgr.h enum ScriptTarget` | 28 |

### Possible Values

Used by: [`castFlags_1`](#col-castflags-1), [`castFlags_2`](#col-castflags-2), [`castFlags_3`](#col-castflags-3), [`castFlags_4`](#col-castflags-4), [`castFlags_5`](#col-castflags-5), [`castFlags_6`](#col-castflags-6), [`castFlags_7`](#col-castflags-7), [`castFlags_8`](#col-castflags-8)

#### `CastFlags`

Kind: `mask`

Source: `src/game/ScriptMgr.h enum CastFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `CF_INTERRUPT_PREVIOUS` | Interrupt previous spell |
| `2` | `0x2` | `CF_TRIGGERED` | Cast as triggered |
| `4` | `0x4` | `CF_FORCE_CAST` | Force cast |
| `8` | `0x8` | `CF_MAIN_RANGED_SPELL` | Main ranged spell |
| `16` | `0x10` | `CF_TARGET_UNREACHABLE` | Allow unreachable target |
| `32` | `0x20` | `CF_AURA_NOT_PRESENT` | Only if aura is not present |
| `64` | `0x40` | `CF_ONLY_IN_MELEE` | Only in melee range |
| `128` | `0x80` | `CF_NOT_IN_MELEE` | Only outside melee range |
| `256` | `0x100` | `CF_TARGET_CASTING` | Only when target is casting |
| `512` | `0x200` | `CF_IGNORE_LOS` | Ignore line of sight; Turtle-specific |

Used by: [`castTarget_1`](#col-casttarget-1), [`castTarget_2`](#col-casttarget-2), [`castTarget_3`](#col-casttarget-3), [`castTarget_4`](#col-casttarget-4), [`castTarget_5`](#col-casttarget-5), [`castTarget_6`](#col-casttarget-6), [`castTarget_7`](#col-casttarget-7), [`castTarget_8`](#col-casttarget-8)

#### `ScriptTarget`

Kind: `enum`

Source: `src/game/ScriptMgr.h enum ScriptTarget`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `TARGET_T_PROVIDED_TARGET` | Use the provided target |
| `1` | `0x1` | `TARGET_T_HOSTILE` | Current hostile target |
| `2` | `0x2` | `TARGET_T_HOSTILE_SECOND_AGGRO` | Second unit on threat list |
| `3` | `0x3` | `TARGET_T_HOSTILE_LAST_AGGRO` | Last unit on threat list |
| `4` | `0x4` | `TARGET_T_HOSTILE_RANDOM` | Random hostile target |
| `5` | `0x5` | `TARGET_T_HOSTILE_RANDOM_NOT_TOP` | Random hostile target excluding top threat |
| `6` | `0x6` | `TARGET_T_OWNER_OR_SELF` | Owner if present, otherwise self |
| `7` | `0x7` | `TARGET_T_OWNER` | Owner |
| `8` | `0x8` | `TARGET_T_NEAREST_CREATURE_WITH_ENTRY` | Nearest creature matching entry |
| `9` | `0x9` | `TARGET_T_CREATURE_WITH_GUID` | Creature matching guid |
| `10` | `0xA` | `TARGET_T_CREATURE_FROM_INSTANCE_DATA` | Creature guid from instance data |
| `11` | `0xB` | `TARGET_T_NEAREST_GAMEOBJECT_WITH_ENTRY` | Nearest gameobject matching entry |
| `12` | `0xC` | `TARGET_T_GAMEOBJECT_WITH_GUID` | Gameobject matching guid |
| `13` | `0xD` | `TARGET_T_GAMEOBJECT_FROM_INSTANCE_DATA` | Gameobject guid from instance data |
| `14` | `0xE` | `TARGET_T_FRIENDLY` | Friendly unit |
| `15` | `0xF` | `TARGET_T_FRIENDLY_INJURED` | Injured friendly unit |
| `16` | `0x10` | `TARGET_T_FRIENDLY_INJURED_EXCEPT` | Injured friendly unit excluding a condition |
| `17` | `0x11` | `TARGET_T_FRIENDLY_MISSING_BUFF` | Friendly unit missing buff |
| `18` | `0x12` | `TARGET_T_FRIENDLY_MISSING_BUFF_EXCEPT` | Friendly unit missing buff excluding a condition |
| `19` | `0x13` | `TARGET_T_FRIENDLY_CC` | Friendly crowd-controlled unit |
| `20` | `0x14` | `TARGET_T_MAP_EVENT_SOURCE` | Map event source |
| `21` | `0x15` | `TARGET_T_MAP_EVENT_TARGET` | Map event target |
| `22` | `0x16` | `TARGET_T_MAP_EVENT_EXTRA_TARGET` | Map event extra target |
| `23` | `0x17` | `TARGET_T_NEAREST_PLAYER` | Nearest player |
| `24` | `0x18` | `TARGET_T_NEAREST_HOSTILE_PLAYER` | Nearest hostile player |
| `25` | `0x19` | `TARGET_T_NEAREST_FRIENDLY_PLAYER` | Nearest friendly player |
| `26` | `0x1A` | `TARGET_T_RANDOM_CREATURE_WITH_ENTRY` | Random creature matching entry |
| `27` | `0x1B` | `TARGET_T_RANDOM_GAMEOBJECT_WITH_ENTRY` | Random gameobject matching entry |
