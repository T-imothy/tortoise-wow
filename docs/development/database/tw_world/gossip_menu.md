---
layout: default
title: gossip_menu
---

# gossip_menu

World database table `gossip_menu`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-text-id"></a>`text_id` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-script-id"></a>`script_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; script id or script name |
| <a id="col-condition-id"></a>`condition_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `text_id`

non-negative numeric value.

References: [`broadcast_text`](broadcast_text.md).`entry`.

### `script_id`

non-negative numeric value; script id or script name.

### `condition_id`

non-negative numeric value.

References: [`conditions`](conditions.md).`condition_entry`.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry`, `text_id` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `text_id` | [`broadcast_text`](broadcast_text.md).`entry` | heuristic | inferred from column name |
| `condition_id` | [`conditions`](conditions.md).`condition_entry` | heuristic | inferred from column name |

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`gossip_menu_option`](gossip_menu_option.md).`action_menu_id` | `entry` | explicit | linked gossip menu |
| [`creature_template`](creature_template.md).`gossip_menu_id` | `entry` | explicit | gossip menu |
| [`gossip_menu_option`](gossip_menu_option.md).`menu_id` | `entry` | explicit | parent gossip menu |

