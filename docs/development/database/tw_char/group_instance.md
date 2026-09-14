---
layout: default
title: group_instance
---

# group_instance

Character database table `group_instance`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 3 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-leaderguid"></a>`leaderGuid` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-instance"></a>`instance` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-permanent"></a>`permanent` | `tinyint(1) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `leaderGuid`

non-negative numeric value.

### `instance`

non-negative numeric value.

References: [`instance`](instance.md).`entry`.

### `permanent`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `leaderGuid`, `instance` |
| KEY | `idx_instance` | `instance` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `instance` | [`instance`](instance.md).`entry` | heuristic | inferred from column name |
