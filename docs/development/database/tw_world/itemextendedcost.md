---
layout: default
title: itemextendedcost
---

# itemextendedcost

World database table `itemextendedcost`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 16 | utf8mb4 | COMPRESSED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-costhonour"></a>`costHonour` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-costarena"></a>`costArena` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-unknown1"></a>`unknown1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-requireditem1"></a>`requiredItem1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-requireditem2"></a>`requiredItem2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-requireditem3"></a>`requiredItem3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-requireditem4"></a>`requiredItem4` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-requireditem5"></a>`requiredItem5` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-requireditemcount1"></a>`requiredItemCount1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-requireditemcount2"></a>`requiredItemCount2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-requireditemcount3"></a>`requiredItemCount3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-requireditemcount4"></a>`requiredItemCount4` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-requireditemcount5"></a>`requiredItemCount5` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-personalrating"></a>`personalRating` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-purchasegroup"></a>`purchaseGroup` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `costHonour`

non-negative numeric value; money/cost value, usually copper.

### `costArena`

non-negative numeric value; money/cost value, usually copper.

### `unknown1`

non-negative numeric value.

### `requiredItem1`

non-negative numeric value.

### `requiredItem2`

non-negative numeric value.

### `requiredItem3`

non-negative numeric value.

### `requiredItem4`

non-negative numeric value.

### `requiredItem5`

non-negative numeric value.

### `requiredItemCount1`

non-negative numeric value.

### `requiredItemCount2`

non-negative numeric value.

### `requiredItemCount3`

non-negative numeric value.

### `requiredItemCount4`

non-negative numeric value.

### `requiredItemCount5`

non-negative numeric value.

### `personalRating`

non-negative numeric value.

### `purchaseGroup`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

