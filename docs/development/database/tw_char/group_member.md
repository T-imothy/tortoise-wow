---
layout: default
title: group_member
---

# group_member

Groups

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-groupid"></a>`groupId` | `int(10) unsigned` | NO | `PRI` |  |  | non-negative numeric value |
| <a id="col-memberguid"></a>`memberGuid` | `int(10) unsigned` | NO | `PRI` |  |  | non-negative numeric value |
| <a id="col-assistant"></a>`assistant` | `tinyint(1) unsigned` | NO |  |  |  | non-negative numeric value |
| <a id="col-subgroup"></a>`subgroup` | `smallint(5) unsigned` | NO |  |  |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `groupId`

non-negative numeric value.

### `memberGuid`

non-negative numeric value.

### `assistant`

non-negative numeric value.

### `subgroup`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `groupId`, `memberGuid` |
| KEY | `idx_memberGuid` | `memberGuid` |
