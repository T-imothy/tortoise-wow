---
layout: default
title: character_aura
---

# character_aura

Player System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 15 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | Global Unique Identifier; non-negative numeric value; identifier column |
| <a id="col-caster-guid"></a>`caster_guid` | `bigint(20) unsigned` | NO | `PRI` | `0` |  | Full Global Unique Identifier; non-negative numeric value |
| <a id="col-item-guid"></a>`item_guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-spell"></a>`spell` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-stackcount"></a>`stackcount` | `int(10) unsigned` | NO |  | `1` |  | non-negative numeric value |
| <a id="col-remaincharges"></a>`remaincharges` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-basepoints0"></a>`basepoints0` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-basepoints1"></a>`basepoints1` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-basepoints2"></a>`basepoints2` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-periodictime0"></a>`periodictime0` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-periodictime1"></a>`periodictime1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-periodictime2"></a>`periodictime2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-maxduration"></a>`maxduration` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-remaintime"></a>`remaintime` | `int(11)` | NO |  | `0` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-effindexmask"></a>`effIndexMask` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `caster_guid`

non-negative numeric value.

### `item_guid`

non-negative numeric value.

### `spell`

non-negative numeric value.

References: [`spell_template`](../tw_world/spell_template.md).`entry`.

### `stackcount`

non-negative numeric value.

### `remaincharges`

non-negative numeric value.

### `basepoints0`

numeric value.

### `basepoints1`

numeric value.

### `basepoints2`

numeric value.

### `periodictime0`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `periodictime1`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `periodictime2`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `maxduration`

numeric value.

### `remaintime`

numeric value; time/delay value; confirm unit in server usage.

### `effIndexMask`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid`, `caster_guid`, `item_guid`, `spell` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `spell` | [`spell_template`](../tw_world/spell_template.md).`entry` | heuristic | inferred from column name |

## Masks and Flags

### Unmapped Flag-Like Columns

| Column | Type | Guidance |
| --- | --- | --- |
| [`effIndexMask`](#col-effindexmask) | `int(10) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
