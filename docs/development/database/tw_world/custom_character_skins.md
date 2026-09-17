---
layout: default
title: custom_character_skins
---

# custom_character_skins

Custom character skins

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 3 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-token-id"></a>`token_id` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | References item_template entry; non-negative numeric value |
| <a id="col-skin-male"></a>`skin_male` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-skin-female"></a>`skin_female` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `token_id`

non-negative numeric value.

### `skin_male`

non-negative numeric value.

### `skin_female`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `token_id` |

