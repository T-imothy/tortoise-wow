---
layout: default
title: shop_items
---

# shop_items

World database table `shop_items`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 14 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(11) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | non-negative numeric value; identifier column |
| <a id="col-category"></a>`category` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-item"></a>`item` | `int(11) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-model-id"></a>`model_id` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-item-id"></a>`item_id` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-description"></a>`description` | `text` | YES |  | `NULL` |  | text/string data; script id or script name |
| <a id="col-description-loc4"></a>`description_loc4` | `text` | YES |  | `NULL` |  | text/string data; script id or script name |
| <a id="col-price"></a>`price` | `int(11) unsigned` | YES |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-region-locked"></a>`region_locked` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-position-x"></a>`position_x` | `float` | YES |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-position-y"></a>`position_y` | `float` | YES |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-position-z"></a>`position_z` | `float` | YES |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-rotation"></a>`rotation` | `float` | YES |  | `0` |  | numeric value |
| <a id="col-scale"></a>`scale` | `float` | YES |  | `1` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `category`

non-negative numeric value.

### `item`

non-negative numeric value.

References: [`item_template`](item_template.md).`entry`.

### `model_id`

non-negative numeric value.

### `item_id`

non-negative numeric value.

References: [`item_template`](item_template.md).`entry`.

### `description`

text/string data; script id or script name.

### `description_loc4`

text/string data; script id or script name.

### `price`

non-negative numeric value; money/cost value, usually copper.

### `region_locked`

non-negative numeric value.

### `position_x`

numeric value; world coordinate or orientation.

### `position_y`

numeric value; world coordinate or orientation.

### `position_z`

numeric value; world coordinate or orientation.

### `rotation`

numeric value.

### `scale`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `item` | [`item_template`](item_template.md).`entry` | heuristic | item id |
| `item_id` | [`item_template`](item_template.md).`entry` | heuristic | inferred from column name |

