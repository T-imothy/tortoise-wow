---
layout: default
title: spell_affect
---

# spell_affect

World database table `spell_affect`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 3 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `smallint(5) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-effectid"></a>`effectId` | `tinyint(3) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-spellfamilymask"></a>`SpellFamilyMask` | `bigint(20) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `effectId`

non-negative numeric value.

### `SpellFamilyMask`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry`, `effectId` |

## Masks and Flags

### Unmapped Flag-Like Columns

| Column | Type | Guidance |
| --- | --- | --- |
| [`SpellFamilyMask`](#col-spellfamilymask) | `bigint(20) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
