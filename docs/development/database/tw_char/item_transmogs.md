---
layout: default
title: item_transmogs
---

# item_transmogs

Character database table `item_transmogs`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`ID` | `int(10) unsigned` | NO | `PRI` |  |  | non-negative numeric value; identifier column |
| <a id="col-itemid"></a>`ItemID` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-displayid"></a>`DisplayID` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-sourceid"></a>`SourceID` | `int(11)` | NO |  |  |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `ID`

non-negative numeric value; identifier column.

### `ItemID`

non-negative numeric value.

References: [`item_template`](../tw_world/item_template.md).`entry`.

### `DisplayID`

non-negative numeric value.

### `SourceID`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `ID` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `ItemID` | [`item_template`](../tw_world/item_template.md).`entry` | heuristic | inferred from column name |
