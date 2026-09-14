---
layout: default
title: spell_proc_event
---

# spell_proc_event

World database table `spell_proc_event`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 11 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-schoolmask"></a>`SchoolMask` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses SpellSchoolMask mask values |
| <a id="col-spellfamilyname"></a>`SpellFamilyName` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spellfamilymask0"></a>`SpellFamilyMask0` | `bigint(20) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-spellfamilymask1"></a>`SpellFamilyMask1` | `bigint(20) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-spellfamilymask2"></a>`SpellFamilyMask2` | `bigint(20) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-procflags"></a>`procFlags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses ProcFlags mask values |
| <a id="col-procex"></a>`procEx` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-ppmrate"></a>`ppmRate` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-customchance"></a>`CustomChance` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-cooldown"></a>`Cooldown` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `SchoolMask`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `SpellSchoolMask` (mask) from `src/game/Spells/SpellDefines.h enum SpellSchoolMask`.

### `SpellFamilyName`

non-negative numeric value.

### `SpellFamilyMask0`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

### `SpellFamilyMask1`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

### `SpellFamilyMask2`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

### `procFlags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `ProcFlags` (mask) from `src/game/Spells/SpellDefines.h enum ProcFlags`.

### `procEx`

non-negative numeric value.

### `ppmRate`

numeric value.

### `CustomChance`

numeric value.

### `Cooldown`

non-negative numeric value; time/delay value; confirm unit in server usage.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `ProcFlags` | mask | [`procFlags`](#col-procflags) | `src/game/Spells/SpellDefines.h enum ProcFlags` | 24 |
| `SpellSchoolMask` | mask | [`SchoolMask`](#col-schoolmask) | `src/game/Spells/SpellDefines.h enum SpellSchoolMask` | 10 |

### Possible Values

Used by: [`procFlags`](#col-procflags)

#### `ProcFlags`

Kind: `mask`

Source: `src/game/Spells/SpellDefines.h enum ProcFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `PROC_FLAG_HEARTBEAT` | On tick |
| `2` | `0x2` | `PROC_FLAG_KILL` | Kill target |
| `4` | `0x4` | `PROC_FLAG_DEAL_MELEE_SWING` | Successful melee auto attack |
| `8` | `0x8` | `PROC_FLAG_TAKE_MELEE_SWING` | Taken melee auto attack hit |
| `16` | `0x10` | `PROC_FLAG_DEAL_MELEE_ABILITY` | Successful melee weapon spell |
| `32` | `0x20` | `PROC_FLAG_TAKE_MELEE_ABILITY` | Taken melee weapon spell damage |
| `64` | `0x40` | `PROC_FLAG_DEAL_RANGED_ATTACK` | Successful ranged auto attack |
| `128` | `0x80` | `PROC_FLAG_TAKE_RANGED_ATTACK` | Taken ranged auto attack |
| `256` | `0x100` | `PROC_FLAG_DEAL_RANGED_ABILITY` | Successful ranged weapon spell |
| `512` | `0x200` | `PROC_FLAG_TAKE_RANGED_ABILITY` | Taken ranged weapon spell damage |
| `1024` | `0x400` | `PROC_FLAG_DEAL_HELPFUL_ABILITY` | Successful positive ability |
| `2048` | `0x800` | `PROC_FLAG_TAKE_HELPFUL_ABILITY` | Taken positive ability |
| `4096` | `0x1000` | `PROC_FLAG_DEAL_HARMFUL_ABILITY` | Successful negative ability |
| `8192` | `0x2000` | `PROC_FLAG_TAKE_HARMFUL_ABILITY` | Taken negative ability |
| `16384` | `0x4000` | `PROC_FLAG_DEAL_HELPFUL_SPELL` | Successful positive spell |
| `32768` | `0x8000` | `PROC_FLAG_TAKE_HELPFUL_SPELL` | Taken positive spell |
| `65536` | `0x10000` | `PROC_FLAG_DEAL_HARMFUL_SPELL` | Successful negative spell |
| `131072` | `0x20000` | `PROC_FLAG_TAKE_HARMFUL_SPELL` | Taken negative spell |
| `262144` | `0x40000` | `PROC_FLAG_DEAL_HARMFUL_PERIODIC` | Successful periodic effect |
| `524288` | `0x80000` | `PROC_FLAG_TAKE_HARMFUL_PERIODIC` | Taken periodic effect |
| `1048576` | `0x100000` | `PROC_FLAG_TAKEN_ANY_DAMAGE` | Taken any damage |
| `2097152` | `0x200000` | `PROC_FLAG_ON_TRAP_ACTIVATION` | On trap activation |
| `4194304` | `0x400000` | `PROC_FLAG_MAIN_HAND_WEAPON_SWING` | Main-hand weapon swing |
| `8388608` | `0x800000` | `PROC_FLAG_OFF_HAND_WEAPON_SWING` | Off-hand weapon swing |

Used by: [`SchoolMask`](#col-schoolmask)

#### `SpellSchoolMask`

Kind: `mask`

Source: `src/game/Spells/SpellDefines.h enum SpellSchoolMask`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `SPELL_SCHOOL_MASK_NORMAL` | Physical/normal |
| `2` | `0x2` | `SPELL_SCHOOL_MASK_HOLY` | Holy |
| `4` | `0x4` | `SPELL_SCHOOL_MASK_FIRE` | Fire |
| `8` | `0x8` | `SPELL_SCHOOL_MASK_NATURE` | Nature |
| `16` | `0x10` | `SPELL_SCHOOL_MASK_FROST` | Frost |
| `32` | `0x20` | `SPELL_SCHOOL_MASK_SHADOW` | Shadow |
| `64` | `0x40` | `SPELL_SCHOOL_MASK_ARCANE` | Arcane |
| `124` | `0x7C` | `SPELL_SCHOOL_MASK_SPELL` | Fire, nature, frost, shadow, and arcane |
| `126` | `0x7E` | `SPELL_SCHOOL_MASK_MAGIC` | Holy plus spell schools |
| `127` | `0x7F` | `SPELL_SCHOOL_MASK_ALL` | All schools |

### Unmapped Flag-Like Columns

| Column | Type | Guidance |
| --- | --- | --- |
| [`SpellFamilyMask0`](#col-spellfamilymask0) | `bigint(20) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
| [`SpellFamilyMask1`](#col-spellfamilymask1) | `bigint(20) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
| [`SpellFamilyMask2`](#col-spellfamilymask2) | `bigint(20) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
