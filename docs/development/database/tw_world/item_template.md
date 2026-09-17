---
layout: default
title: item_template
---

# item_template

Item System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 130 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-class"></a>`class` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; class id or class mask; Uses ItemClass enum values |
| <a id="col-subclass"></a>`subclass` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-name"></a>`name` | `varchar(255)` | NO |  | `''` |  | text/string data |
| <a id="col-description"></a>`description` | `varchar(255)` | NO |  | `''` |  | text/string data; script id or script name |
| <a id="col-display-id"></a>`display_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-quality"></a>`quality` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ItemQualities enum values |
| <a id="col-flags"></a>`flags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses ItemFlags mask values |
| <a id="col-buy-count"></a>`buy_count` | `tinyint(3) unsigned` | NO |  | `1` |  | non-negative numeric value |
| <a id="col-buy-price"></a>`buy_price` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-sell-price"></a>`sell_price` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-inventory-type"></a>`inventory_type` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses InventoryType enum values |
| <a id="col-allowable-class"></a>`allowable_class` | `mediumint(9)` | NO |  | `-1` |  | numeric value; Uses ClassMask mask values |
| <a id="col-allowable-race"></a>`allowable_race` | `mediumint(9)` | NO |  | `-1` |  | numeric value; Uses RaceMask mask values |
| <a id="col-item-level"></a>`item_level` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-required-level"></a>`required_level` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-required-skill"></a>`required_skill` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-required-skill-rank"></a>`required_skill_rank` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-required-spell"></a>`required_spell` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-required-honor-rank"></a>`required_honor_rank` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-required-city-rank"></a>`required_city_rank` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-required-reputation-faction"></a>`required_reputation_faction` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-required-reputation-rank"></a>`required_reputation_rank` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ReputationRank enum values |
| <a id="col-max-count"></a>`max_count` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-stackable"></a>`stackable` | `smallint(5) unsigned` | NO |  | `1` |  | non-negative numeric value |
| <a id="col-container-slots"></a>`container_slots` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-stat-type1"></a>`stat_type1` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ItemModType enum values |
| <a id="col-stat-value1"></a>`stat_value1` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-stat-type2"></a>`stat_type2` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ItemModType enum values |
| <a id="col-stat-value2"></a>`stat_value2` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-stat-type3"></a>`stat_type3` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ItemModType enum values |
| <a id="col-stat-value3"></a>`stat_value3` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-stat-type4"></a>`stat_type4` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ItemModType enum values |
| <a id="col-stat-value4"></a>`stat_value4` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-stat-type5"></a>`stat_type5` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ItemModType enum values |
| <a id="col-stat-value5"></a>`stat_value5` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-stat-type6"></a>`stat_type6` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ItemModType enum values |
| <a id="col-stat-value6"></a>`stat_value6` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-stat-type7"></a>`stat_type7` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ItemModType enum values |
| <a id="col-stat-value7"></a>`stat_value7` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-stat-type8"></a>`stat_type8` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ItemModType enum values |
| <a id="col-stat-value8"></a>`stat_value8` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-stat-type9"></a>`stat_type9` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ItemModType enum values |
| <a id="col-stat-value9"></a>`stat_value9` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-stat-type10"></a>`stat_type10` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ItemModType enum values |
| <a id="col-stat-value10"></a>`stat_value10` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-delay"></a>`delay` | `smallint(5) unsigned` | NO |  | `1000` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-range-mod"></a>`range_mod` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-ammo-type"></a>`ammo_type` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-dmg-min1"></a>`dmg_min1` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-dmg-max1"></a>`dmg_max1` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-dmg-type1"></a>`dmg_type1` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellSchools enum values |
| <a id="col-dmg-min2"></a>`dmg_min2` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-dmg-max2"></a>`dmg_max2` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-dmg-type2"></a>`dmg_type2` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellSchools enum values |
| <a id="col-dmg-min3"></a>`dmg_min3` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-dmg-max3"></a>`dmg_max3` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-dmg-type3"></a>`dmg_type3` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellSchools enum values |
| <a id="col-dmg-min4"></a>`dmg_min4` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-dmg-max4"></a>`dmg_max4` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-dmg-type4"></a>`dmg_type4` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellSchools enum values |
| <a id="col-dmg-min5"></a>`dmg_min5` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-dmg-max5"></a>`dmg_max5` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-dmg-type5"></a>`dmg_type5` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellSchools enum values |
| <a id="col-block"></a>`block` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-armor"></a>`armor` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-holy-res"></a>`holy_res` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-fire-res"></a>`fire_res` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-nature-res"></a>`nature_res` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-frost-res"></a>`frost_res` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-shadow-res"></a>`shadow_res` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-arcane-res"></a>`arcane_res` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-spellid-1"></a>`spellid_1` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spelltrigger-1"></a>`spelltrigger_1` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ItemSpelltriggerType enum values |
| <a id="col-spellcharges-1"></a>`spellcharges_1` | `tinyint(4)` | NO |  | `0` |  | numeric value |
| <a id="col-spellppmrate-1"></a>`spellppmrate_1` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-spellcooldown-1"></a>`spellcooldown_1` | `int(11)` | NO |  | `-1` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-spellcategory-1"></a>`spellcategory_1` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spellcategorycooldown-1"></a>`spellcategorycooldown_1` | `int(11)` | NO |  | `-1` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-spellid-2"></a>`spellid_2` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spelltrigger-2"></a>`spelltrigger_2` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ItemSpelltriggerType enum values |
| <a id="col-spellcharges-2"></a>`spellcharges_2` | `tinyint(4)` | NO |  | `0` |  | numeric value |
| <a id="col-spellppmrate-2"></a>`spellppmrate_2` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-spellcooldown-2"></a>`spellcooldown_2` | `int(11)` | NO |  | `-1` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-spellcategory-2"></a>`spellcategory_2` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spellcategorycooldown-2"></a>`spellcategorycooldown_2` | `int(11)` | NO |  | `-1` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-spellid-3"></a>`spellid_3` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spelltrigger-3"></a>`spelltrigger_3` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ItemSpelltriggerType enum values |
| <a id="col-spellcharges-3"></a>`spellcharges_3` | `tinyint(4)` | NO |  | `0` |  | numeric value |
| <a id="col-spellppmrate-3"></a>`spellppmrate_3` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-spellcooldown-3"></a>`spellcooldown_3` | `int(11)` | NO |  | `-1` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-spellcategory-3"></a>`spellcategory_3` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spellcategorycooldown-3"></a>`spellcategorycooldown_3` | `int(11)` | NO |  | `-1` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-spellid-4"></a>`spellid_4` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spelltrigger-4"></a>`spelltrigger_4` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ItemSpelltriggerType enum values |
| <a id="col-spellcharges-4"></a>`spellcharges_4` | `tinyint(4)` | NO |  | `0` |  | numeric value |
| <a id="col-spellppmrate-4"></a>`spellppmrate_4` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-spellcooldown-4"></a>`spellcooldown_4` | `int(11)` | NO |  | `-1` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-spellcategory-4"></a>`spellcategory_4` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spellcategorycooldown-4"></a>`spellcategorycooldown_4` | `int(11)` | NO |  | `-1` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-spellid-5"></a>`spellid_5` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spelltrigger-5"></a>`spelltrigger_5` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ItemSpelltriggerType enum values |
| <a id="col-spellcharges-5"></a>`spellcharges_5` | `tinyint(4)` | NO |  | `0` |  | numeric value |
| <a id="col-spellppmrate-5"></a>`spellppmrate_5` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-spellcooldown-5"></a>`spellcooldown_5` | `int(11)` | NO |  | `-1` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-spellcategory-5"></a>`spellcategory_5` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spellcategorycooldown-5"></a>`spellcategorycooldown_5` | `int(11)` | NO |  | `-1` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-bonding"></a>`bonding` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ItemBondingType enum values |
| <a id="col-page-text"></a>`page_text` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-page-language"></a>`page_language` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Language enum values |
| <a id="col-page-material"></a>`page_material` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-start-quest"></a>`start_quest` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-lock-id"></a>`lock_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-material"></a>`material` | `tinyint(4)` | NO |  | `0` |  | numeric value |
| <a id="col-sheath"></a>`sheath` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SheathTypes enum values |
| <a id="col-random-property"></a>`random_property` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-set-id"></a>`set_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-max-durability"></a>`max_durability` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-area-bound"></a>`area_bound` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-map-bound"></a>`map_bound` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-duration"></a>`duration` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-bag-family"></a>`bag_family` | `mediumint(9)` | NO |  | `0` |  | numeric value; Uses BagFamily enum values |
| <a id="col-disenchant-id"></a>`disenchant_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-food-type"></a>`food_type` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-min-money-loot"></a>`min_money_loot` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-max-money-loot"></a>`max_money_loot` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-wrapped-gift"></a>`wrapped_gift` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-extra-flags"></a>`extra_flags` | `tinyint(1) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses ItemExtraFlags mask values |
| <a id="col-other-team-entry"></a>`other_team_entry` | `int(10) unsigned` | YES |  | `1` |  | non-negative numeric value |
| <a id="col-script-name"></a>`script_name` | `varchar(255)` | YES |  | `NULL` |  | text/string data; script id or script name |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `class`

non-negative numeric value; class id or class mask.

Value set: `ItemClass` (enum) from `src/game/Objects/ItemPrototype.h enum ItemClass`.

### `subclass`

non-negative numeric value.

### `name`

text/string data.

### `description`

text/string data; script id or script name.

### `display_id`

non-negative numeric value.

### `quality`

non-negative numeric value.

Value set: `ItemQualities` (enum) from `src/game/SharedDefines.h enum ItemQualities`.

### `flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `ItemFlags` (mask) from `src/game/Objects/ItemPrototype.h enum ItemPrototypeFlags`.

### `buy_count`

non-negative numeric value.

### `buy_price`

non-negative numeric value; money/cost value, usually copper.

### `sell_price`

non-negative numeric value; money/cost value, usually copper.

### `inventory_type`

non-negative numeric value.

Value set: `InventoryType` (enum) from `src/game/Objects/ItemPrototype.h enum InventoryType`.

### `allowable_class`

numeric value.

Value set: `ClassMask` (mask) from `src/game/SharedDefines.h class mask constants`.

### `allowable_race`

numeric value.

Value set: `RaceMask` (mask) from `src/game/SharedDefines.h race mask constants`.

### `item_level`

non-negative numeric value.

### `required_level`

non-negative numeric value.

### `required_skill`

non-negative numeric value.

### `required_skill_rank`

non-negative numeric value.

### `required_spell`

non-negative numeric value.

### `required_honor_rank`

non-negative numeric value.

### `required_city_rank`

non-negative numeric value.

### `required_reputation_faction`

non-negative numeric value.

### `required_reputation_rank`

non-negative numeric value.

Value set: `ReputationRank` (enum) from `src/game/SharedDefines.h enum ReputationRank`.

### `max_count`

non-negative numeric value.

### `stackable`

non-negative numeric value.

### `container_slots`

non-negative numeric value.

### `stat_type1`

non-negative numeric value.

Value set: `ItemModType` (enum) from `src/game/Objects/ItemPrototype.h enum ItemModType`.

### `stat_value1`

numeric value.

### `stat_type2`

non-negative numeric value.

Value set: `ItemModType` (enum) from `src/game/Objects/ItemPrototype.h enum ItemModType`.

### `stat_value2`

numeric value.

### `stat_type3`

non-negative numeric value.

Value set: `ItemModType` (enum) from `src/game/Objects/ItemPrototype.h enum ItemModType`.

### `stat_value3`

numeric value.

### `stat_type4`

non-negative numeric value.

Value set: `ItemModType` (enum) from `src/game/Objects/ItemPrototype.h enum ItemModType`.

### `stat_value4`

numeric value.

### `stat_type5`

non-negative numeric value.

Value set: `ItemModType` (enum) from `src/game/Objects/ItemPrototype.h enum ItemModType`.

### `stat_value5`

numeric value.

### `stat_type6`

non-negative numeric value.

Value set: `ItemModType` (enum) from `src/game/Objects/ItemPrototype.h enum ItemModType`.

### `stat_value6`

numeric value.

### `stat_type7`

non-negative numeric value.

Value set: `ItemModType` (enum) from `src/game/Objects/ItemPrototype.h enum ItemModType`.

### `stat_value7`

numeric value.

### `stat_type8`

non-negative numeric value.

Value set: `ItemModType` (enum) from `src/game/Objects/ItemPrototype.h enum ItemModType`.

### `stat_value8`

numeric value.

### `stat_type9`

non-negative numeric value.

Value set: `ItemModType` (enum) from `src/game/Objects/ItemPrototype.h enum ItemModType`.

### `stat_value9`

numeric value.

### `stat_type10`

non-negative numeric value.

Value set: `ItemModType` (enum) from `src/game/Objects/ItemPrototype.h enum ItemModType`.

### `stat_value10`

numeric value.

### `delay`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `range_mod`

numeric value.

### `ammo_type`

non-negative numeric value.

### `dmg_min1`

numeric value.

### `dmg_max1`

numeric value.

### `dmg_type1`

non-negative numeric value.

Value set: `SpellSchools` (enum) from `src/game/Spells/SpellDefines.h enum SpellSchools`.

### `dmg_min2`

numeric value.

### `dmg_max2`

numeric value.

### `dmg_type2`

non-negative numeric value.

Value set: `SpellSchools` (enum) from `src/game/Spells/SpellDefines.h enum SpellSchools`.

### `dmg_min3`

numeric value.

### `dmg_max3`

numeric value.

### `dmg_type3`

non-negative numeric value.

Value set: `SpellSchools` (enum) from `src/game/Spells/SpellDefines.h enum SpellSchools`.

### `dmg_min4`

numeric value.

### `dmg_max4`

numeric value.

### `dmg_type4`

non-negative numeric value.

Value set: `SpellSchools` (enum) from `src/game/Spells/SpellDefines.h enum SpellSchools`.

### `dmg_min5`

numeric value.

### `dmg_max5`

numeric value.

### `dmg_type5`

non-negative numeric value.

Value set: `SpellSchools` (enum) from `src/game/Spells/SpellDefines.h enum SpellSchools`.

### `block`

non-negative numeric value.

### `armor`

numeric value.

### `holy_res`

numeric value.

### `fire_res`

numeric value.

### `nature_res`

numeric value.

### `frost_res`

numeric value.

### `shadow_res`

numeric value.

### `arcane_res`

numeric value.

### `spellid_1`

non-negative numeric value.

### `spelltrigger_1`

non-negative numeric value.

Value set: `ItemSpelltriggerType` (enum) from `src/game/Objects/ItemPrototype.h enum ItemSpelltriggerType`.

### `spellcharges_1`

numeric value.

### `spellppmrate_1`

numeric value.

### `spellcooldown_1`

numeric value; time/delay value; confirm unit in server usage.

### `spellcategory_1`

non-negative numeric value.

### `spellcategorycooldown_1`

numeric value; time/delay value; confirm unit in server usage.

### `spellid_2`

non-negative numeric value.

### `spelltrigger_2`

non-negative numeric value.

Value set: `ItemSpelltriggerType` (enum) from `src/game/Objects/ItemPrototype.h enum ItemSpelltriggerType`.

### `spellcharges_2`

numeric value.

### `spellppmrate_2`

numeric value.

### `spellcooldown_2`

numeric value; time/delay value; confirm unit in server usage.

### `spellcategory_2`

non-negative numeric value.

### `spellcategorycooldown_2`

numeric value; time/delay value; confirm unit in server usage.

### `spellid_3`

non-negative numeric value.

### `spelltrigger_3`

non-negative numeric value.

Value set: `ItemSpelltriggerType` (enum) from `src/game/Objects/ItemPrototype.h enum ItemSpelltriggerType`.

### `spellcharges_3`

numeric value.

### `spellppmrate_3`

numeric value.

### `spellcooldown_3`

numeric value; time/delay value; confirm unit in server usage.

### `spellcategory_3`

non-negative numeric value.

### `spellcategorycooldown_3`

numeric value; time/delay value; confirm unit in server usage.

### `spellid_4`

non-negative numeric value.

### `spelltrigger_4`

non-negative numeric value.

Value set: `ItemSpelltriggerType` (enum) from `src/game/Objects/ItemPrototype.h enum ItemSpelltriggerType`.

### `spellcharges_4`

numeric value.

### `spellppmrate_4`

numeric value.

### `spellcooldown_4`

numeric value; time/delay value; confirm unit in server usage.

### `spellcategory_4`

non-negative numeric value.

### `spellcategorycooldown_4`

numeric value; time/delay value; confirm unit in server usage.

### `spellid_5`

non-negative numeric value.

### `spelltrigger_5`

non-negative numeric value.

Value set: `ItemSpelltriggerType` (enum) from `src/game/Objects/ItemPrototype.h enum ItemSpelltriggerType`.

### `spellcharges_5`

numeric value.

### `spellppmrate_5`

numeric value.

### `spellcooldown_5`

numeric value; time/delay value; confirm unit in server usage.

### `spellcategory_5`

non-negative numeric value.

### `spellcategorycooldown_5`

numeric value; time/delay value; confirm unit in server usage.

### `bonding`

non-negative numeric value.

Value set: `ItemBondingType` (enum) from `src/game/Objects/ItemPrototype.h enum ItemBondingType`.

### `page_text`

non-negative numeric value.

References: [`page_text`](page_text.md).`entry`.

### `page_language`

non-negative numeric value.

Value set: `Language` (enum) from `src/game/SharedDefines.h enum Language`.

### `page_material`

non-negative numeric value.

### `start_quest`

non-negative numeric value.

### `lock_id`

non-negative numeric value.

### `material`

numeric value.

### `sheath`

non-negative numeric value.

Value set: `SheathTypes` (enum) from `src/game/SharedDefines.h enum SheathTypes`.

### `random_property`

non-negative numeric value.

### `set_id`

non-negative numeric value.

### `max_durability`

non-negative numeric value.

### `area_bound`

non-negative numeric value.

### `map_bound`

numeric value.

### `duration`

non-negative numeric value.

### `bag_family`

numeric value.

Value set: `BagFamily` (enum) from `src/game/Objects/ItemPrototype.h enum BagFamily`.

### `disenchant_id`

non-negative numeric value.

### `food_type`

non-negative numeric value.

### `min_money_loot`

non-negative numeric value; money/cost value, usually copper.

### `max_money_loot`

non-negative numeric value; money/cost value, usually copper.

### `wrapped_gift`

non-negative numeric value.

### `extra_flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `ItemExtraFlags` (mask) from `src/game/Objects/ItemPrototype.h enum ItemExtraFlags`.

### `other_team_entry`

non-negative numeric value.

### `script_name`

text/string data; script id or script name.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |
| KEY | `items_index` | `class` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `page_text` | [`page_text`](page_text.md).`entry` | heuristic | inferred from column name |

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`player_factionchange_mounts`](player_factionchange_mounts.md).`ItemEntry` | `entry` | heuristic | inferred from column name |
| [`item_transmogrify_template`](item_transmogrify_template.md).`ItemID` | `entry` | heuristic | inferred from column name |
| [`quest_template`](quest_template.md).`RewChoiceItemId1` | `entry` | explicit | choice reward item |
| [`quest_template`](quest_template.md).`RewChoiceItemId2` | `entry` | explicit | choice reward item |
| [`quest_template`](quest_template.md).`RewChoiceItemId3` | `entry` | explicit | choice reward item |
| [`quest_template`](quest_template.md).`RewChoiceItemId4` | `entry` | explicit | choice reward item |
| [`quest_template`](quest_template.md).`RewChoiceItemId5` | `entry` | explicit | choice reward item |
| [`quest_template`](quest_template.md).`RewChoiceItemId6` | `entry` | explicit | choice reward item |
| [`quest_template`](quest_template.md).`RewItemId1` | `entry` | explicit | reward item |
| [`quest_template`](quest_template.md).`RewItemId2` | `entry` | explicit | reward item |
| [`quest_template`](quest_template.md).`RewItemId3` | `entry` | explicit | reward item |
| [`quest_template`](quest_template.md).`RewItemId4` | `entry` | explicit | reward item |
| [`quest_template`](quest_template.md).`SrcItemId` | `entry` | explicit | source item |
| [`auctionhousebot`](auctionhousebot.md).`item` | `entry` | heuristic | item id |
| [`creature_loot_template`](creature_loot_template.md).`item` | `entry` | heuristic | item id |
| [`custom_merchant`](custom_merchant.md).`item` | `entry` | heuristic | item id |
| [`disenchant_loot_template`](disenchant_loot_template.md).`item` | `entry` | heuristic | item id |
| [`fishing_loot_template`](fishing_loot_template.md).`item` | `entry` | heuristic | item id |
| [`gameobject_loot_template`](gameobject_loot_template.md).`item` | `entry` | heuristic | item id |
| [`item_loot_template`](item_loot_template.md).`item` | `entry` | heuristic | item id |
| [`mail_loot_template`](mail_loot_template.md).`item` | `entry` | heuristic | item id |
| [`pickpocketing_loot_template`](pickpocketing_loot_template.md).`item` | `entry` | heuristic | item id |
| [`reference_loot_template`](reference_loot_template.md).`item` | `entry` | heuristic | item id |
| [`shop_items`](shop_items.md).`item` | `entry` | heuristic | item id |
| [`skinning_loot_template`](skinning_loot_template.md).`item` | `entry` | heuristic | item id |
| [`npc_vendor`](npc_vendor.md).`item` | `entry` | explicit | sold item |
| [`npc_vendor_template`](npc_vendor_template.md).`item` | `entry` | explicit | sold item |
| [`collection_mount`](collection_mount.md).`itemId` | `entry` | heuristic | inferred from column name |
| [`collection_pet`](collection_pet.md).`itemId` | `entry` | heuristic | inferred from column name |
| [`collection_toy`](collection_toy.md).`itemId` | `entry` | heuristic | inferred from column name |
| [`shop_items`](shop_items.md).`item_id` | `entry` | heuristic | inferred from column name |
| [`playercreateinfo_item`](playercreateinfo_item.md).`itemid` | `entry` | heuristic | inferred from column name |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `BagFamily` | enum | [`bag_family`](#col-bag-family) | `src/game/Objects/ItemPrototype.h enum BagFamily` | 14 |
| `ClassMask` | mask | [`allowable_class`](#col-allowable-class) | `src/game/SharedDefines.h class mask constants` | 9 |
| `InventoryType` | enum | [`inventory_type`](#col-inventory-type) | `src/game/Objects/ItemPrototype.h enum InventoryType` | 29 |
| `ItemBondingType` | enum | [`bonding`](#col-bonding) | `src/game/Objects/ItemPrototype.h enum ItemBondingType` | 7 |
| `ItemClass` | enum | [`class`](#col-class) | `src/game/Objects/ItemPrototype.h enum ItemClass` | 16 |
| `ItemExtraFlags` | mask | [`extra_flags`](#col-extra-flags) | `src/game/Objects/ItemPrototype.h enum ItemExtraFlags` | 5 |
| `ItemFlags` | mask | [`flags`](#col-flags) | `src/game/Objects/ItemPrototype.h enum ItemPrototypeFlags` | 19 |
| `ItemModType` | enum | [`stat_type1`](#col-stat-type1), [`stat_type2`](#col-stat-type2), [`stat_type3`](#col-stat-type3), [`stat_type4`](#col-stat-type4), [`stat_type5`](#col-stat-type5), [`stat_type6`](#col-stat-type6), [`stat_type7`](#col-stat-type7), [`stat_type8`](#col-stat-type8), [`stat_type9`](#col-stat-type9), [`stat_type10`](#col-stat-type10) | `src/game/Objects/ItemPrototype.h enum ItemModType` | 7 |
| `ItemQualities` | enum | [`quality`](#col-quality) | `src/game/SharedDefines.h enum ItemQualities` | 7 |
| `ItemSpelltriggerType` | enum | [`spelltrigger_1`](#col-spelltrigger-1), [`spelltrigger_2`](#col-spelltrigger-2), [`spelltrigger_3`](#col-spelltrigger-3), [`spelltrigger_4`](#col-spelltrigger-4), [`spelltrigger_5`](#col-spelltrigger-5) | `src/game/Objects/ItemPrototype.h enum ItemSpelltriggerType` | 5 |
| `Language` | enum | [`page_language`](#col-page-language) | `src/game/SharedDefines.h enum Language` | 15 |
| `RaceMask` | mask | [`allowable_race`](#col-allowable-race) | `src/game/SharedDefines.h race mask constants` | 10 |
| `ReputationRank` | enum | [`required_reputation_rank`](#col-required-reputation-rank) | `src/game/SharedDefines.h enum ReputationRank` | 8 |
| `SheathTypes` | enum | [`sheath`](#col-sheath) | `src/game/SharedDefines.h enum SheathTypes` | 8 |
| `SpellSchools` | enum | [`dmg_type1`](#col-dmg-type1), [`dmg_type2`](#col-dmg-type2), [`dmg_type3`](#col-dmg-type3), [`dmg_type4`](#col-dmg-type4), [`dmg_type5`](#col-dmg-type5) | `src/game/Spells/SpellDefines.h enum SpellSchools` | 7 |

### Possible Values

Used by: [`bag_family`](#col-bag-family)

#### `BagFamily`

Kind: `enum`

Source: `src/game/Objects/ItemPrototype.h enum BagFamily`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `BAG_FAMILY_NONE` | Bag Family None |
| `1` | `0x1` | `BAG_FAMILY_ARROWS` | Bag Family Arrows |
| `2` | `0x2` | `BAG_FAMILY_BULLETS` | Bag Family Bullets |
| `3` | `0x3` | `BAG_FAMILY_SOUL_SHARDS` | Bag Family Soul Shards |
| `4` | `0x4` | `BAG_FAMILY_UNKNOWN1` | Bag Family Unknown1 |
| `5` | `0x5` | `BAG_FAMILY_UNKNOWN2` | Bag Family Unknown2 |
| `6` | `0x6` | `BAG_FAMILY_HERBS` | Bag Family Herbs |
| `7` | `0x7` | `BAG_FAMILY_ENCHANTING_SUPP` | Bag Family Enchanting Supp |
| `8` | `0x8` | `BAG_FAMILY_ENGINEERING_SUPP` | Bag Family Engineering Supp |
| `9` | `0x9` | `BAG_FAMILY_KEYS` | Bag Family Keys |
| `10` | `0xA` | `BAG_FAMILY_MEAT` | Turtle: rations bags |
| `11` | `0xB` | `BAG_FAMILY_FISH` | Turtle: fishing bags |
| `12` | `0xC` | `BAG_FAMILY_LEATHER` | Turtle: leatherworking bags |
| `13` | `0xD` | `BAG_FAMILY_MINING` | Turtle: mining bags (ore, stone, gems) |

Used by: [`allowable_class`](#col-allowable-class)

#### `ClassMask`

Kind: `mask`

Source: `src/game/SharedDefines.h class mask constants`

Class masks use 1 &lt;&lt; (class id - 1). Combine allowed classes with bitwise OR.

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `CLASSMASK_WARRIOR` | Warrior |
| `2` | `0x2` | `CLASSMASK_PALADIN` | Paladin |
| `4` | `0x4` | `CLASSMASK_HUNTER` | Hunter |
| `8` | `0x8` | `CLASSMASK_ROGUE` | Rogue |
| `16` | `0x10` | `CLASSMASK_PRIEST` | Priest |
| `64` | `0x40` | `CLASSMASK_SHAMAN` | Shaman |
| `128` | `0x80` | `CLASSMASK_MAGE` | Mage |
| `256` | `0x100` | `CLASSMASK_WARLOCK` | Warlock |
| `1024` | `0x400` | `CLASSMASK_DRUID` | Druid |

Used by: [`inventory_type`](#col-inventory-type)

#### `InventoryType`

Kind: `enum`

Source: `src/game/Objects/ItemPrototype.h enum InventoryType`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `INVTYPE_NON_EQUIP` | Not equippable |
| `1` | `0x1` | `INVTYPE_HEAD` | Head |
| `2` | `0x2` | `INVTYPE_NECK` | Neck |
| `3` | `0x3` | `INVTYPE_SHOULDERS` | Shoulders |
| `4` | `0x4` | `INVTYPE_BODY` | Body |
| `5` | `0x5` | `INVTYPE_CHEST` | Chest |
| `6` | `0x6` | `INVTYPE_WAIST` | Waist |
| `7` | `0x7` | `INVTYPE_LEGS` | Legs |
| `8` | `0x8` | `INVTYPE_FEET` | Feet |
| `9` | `0x9` | `INVTYPE_WRISTS` | Wrists |
| `10` | `0xA` | `INVTYPE_HANDS` | Hands |
| `11` | `0xB` | `INVTYPE_FINGER` | Finger |
| `12` | `0xC` | `INVTYPE_TRINKET` | Trinket |
| `13` | `0xD` | `INVTYPE_WEAPON` | One-handed weapon |
| `14` | `0xE` | `INVTYPE_SHIELD` | Shield |
| `15` | `0xF` | `INVTYPE_RANGED` | Ranged |
| `16` | `0x10` | `INVTYPE_CLOAK` | Cloak |
| `17` | `0x11` | `INVTYPE_2HWEAPON` | Two-handed weapon |
| `18` | `0x12` | `INVTYPE_BAG` | Bag |
| `19` | `0x13` | `INVTYPE_TABARD` | Tabard |
| `20` | `0x14` | `INVTYPE_ROBE` | Robe |
| `21` | `0x15` | `INVTYPE_WEAPONMAINHAND` | Main-hand weapon |
| `22` | `0x16` | `INVTYPE_WEAPONOFFHAND` | Off-hand weapon |
| `23` | `0x17` | `INVTYPE_HOLDABLE` | Held in off hand |
| `24` | `0x18` | `INVTYPE_AMMO` | Ammo |
| `25` | `0x19` | `INVTYPE_THROWN` | Thrown |
| `26` | `0x1A` | `INVTYPE_RANGEDRIGHT` | Ranged right |
| `27` | `0x1B` | `INVTYPE_QUIVER` | Quiver |
| `28` | `0x1C` | `INVTYPE_RELIC` | Relic |

Used by: [`bonding`](#col-bonding)

#### `ItemBondingType`

Kind: `enum`

Source: `src/game/Objects/ItemPrototype.h enum ItemBondingType`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `NO_BIND` | No Bind |
| `1` | `0x1` | `BIND_WHEN_PICKED_UP` | Bind When Picked Up |
| `2` | `0x2` | `BIND_WHEN_EQUIPPED` | Bind When Equipped |
| `3` | `0x3` | `BIND_WHEN_USE` | Bind When Use |
| `4` | `0x4` | `BIND_QUEST_ITEM` | Bind Quest Item |
| `5` | `0x5` | `BIND_QUEST_ITEM1` | not used in game |
| `6` | `0x6` | `BIND_ACCOUNT` | Turtle specific |

Used by: [`class`](#col-class)

#### `ItemClass`

Kind: `enum`

Source: `src/game/Objects/ItemPrototype.h enum ItemClass`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `ITEM_CLASS_CONSUMABLE` | Consumable |
| `1` | `0x1` | `ITEM_CLASS_CONTAINER` | Container |
| `2` | `0x2` | `ITEM_CLASS_WEAPON` | Weapon |
| `3` | `0x3` | `ITEM_CLASS_GEM` | Gem |
| `4` | `0x4` | `ITEM_CLASS_ARMOR` | Armor |
| `5` | `0x5` | `ITEM_CLASS_REAGENT` | Reagent |
| `6` | `0x6` | `ITEM_CLASS_PROJECTILE` | Projectile |
| `7` | `0x7` | `ITEM_CLASS_TRADE_GOODS` | Trade goods |
| `8` | `0x8` | `ITEM_CLASS_GENERIC` | Generic |
| `9` | `0x9` | `ITEM_CLASS_RECIPE` | Recipe |
| `10` | `0xA` | `ITEM_CLASS_MONEY` | Money |
| `11` | `0xB` | `ITEM_CLASS_QUIVER` | Quiver |
| `12` | `0xC` | `ITEM_CLASS_QUEST` | Quest |
| `13` | `0xD` | `ITEM_CLASS_KEY` | Key |
| `14` | `0xE` | `ITEM_CLASS_PERMANENT` | Permanent |
| `15` | `0xF` | `ITEM_CLASS_JUNK` | Junk |

Used by: [`extra_flags`](#col-extra-flags)

#### `ItemExtraFlags`

Kind: `mask`

Source: `src/game/Objects/ItemPrototype.h enum ItemExtraFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `ITEM_EXTRA_MAIL_STATIONERY` | Used as icon or background for mails |
| `2` | `0x2` | `ITEM_EXTRA_IGNORE_QUEST_STATUS` | Quest status is not checked when this item drops |
| `4` | `0x4` | `ITEM_EXTRA_NOT_OBTAINABLE` | Never obtainable by players in vanilla |
| `8` | `0x8` | `ITEM_EXTRA_CREATE_BROKEN` | Item starts with zero durability |
| `15` | `0xF` | `ITEM_EXTRA_ALL` | All used item extra flags |

Used by: [`flags`](#col-flags)

#### `ItemFlags`

Kind: `mask`

Source: `src/game/Objects/ItemPrototype.h enum ItemPrototypeFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `ITEM_FLAG_UNK0` | Not used |
| `2` | `0x2` | `ITEM_FLAG_CONJURED` | Conjured item |
| `4` | `0x4` | `ITEM_FLAG_LOOTABLE` | Can be opened for loot outside containers |
| `8` | `0x8` | `ITEM_FLAG_UNK3` | Not used in pre-3.x |
| `16` | `0x10` | `ITEM_FLAG_DEPRECATED` | Deprecated; red icon behavior |
| `32` | `0x20` | `ITEM_FLAG_INDESTRUCTIBLE` | Cannot be destroyed except by spell reagent use |
| `64` | `0x40` | `ITEM_FLAG_UNK6` | Unknown, old note says usable |
| `128` | `0x80` | `ITEM_FLAG_NO_EQUIP_COOLDOWN` | No equip cooldown |
| `256` | `0x100` | `ITEM_FLAG_UNK8` | Unknown |
| `512` | `0x200` | `ITEM_FLAG_WRAPPER` | Wrapper item behavior |
| `1024` | `0x400` | `ITEM_FLAG_IGNORE_BAG_SPACE` | Ignore bag space on creation |
| `2048` | `0x800` | `ITEM_FLAG_PARTY_LOOT` | Party loot item |
| `4096` | `0x1000` | `ITEM_FLAG_UNK12` | Not used in pre-3.x |
| `8192` | `0x2000` | `ITEM_FLAG_CHARTER` | Guild charter |
| `16384` | `0x4000` | `ITEM_FLAG_HAS_TEXT` | Readable item text |
| `32768` | `0x8000` | `ITEM_FLAG_NO_DISENCHANT` | Cannot be disenchanted |
| `65536` | `0x10000` | `ITEM_FLAG_REAL_DURATION` | Duration uses real time |
| `131072` | `0x20000` | `ITEM_FLAG_NO_CREATOR` | Does not store creator |
| `524288` | `0x80000` | `ITEM_FLAG_UNIQUE_EQUIPPED` | Unique-equipped server-side check |

Used by: [`stat_type1`](#col-stat-type1), [`stat_type2`](#col-stat-type2), [`stat_type3`](#col-stat-type3), [`stat_type4`](#col-stat-type4), [`stat_type5`](#col-stat-type5), [`stat_type6`](#col-stat-type6), [`stat_type7`](#col-stat-type7), [`stat_type8`](#col-stat-type8), [`stat_type9`](#col-stat-type9), [`stat_type10`](#col-stat-type10)

#### `ItemModType`

Kind: `enum`

Source: `src/game/Objects/ItemPrototype.h enum ItemModType`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `ITEM_MOD_MANA` | Mod Mana |
| `1` | `0x1` | `ITEM_MOD_HEALTH` | Mod Health |
| `3` | `0x3` | `ITEM_MOD_AGILITY` | Mod Agility |
| `4` | `0x4` | `ITEM_MOD_STRENGTH` | Mod Strength |
| `5` | `0x5` | `ITEM_MOD_INTELLECT` | Mod Intellect |
| `6` | `0x6` | `ITEM_MOD_SPIRIT` | Mod Spirit |
| `7` | `0x7` | `ITEM_MOD_STAMINA` | Mod Stamina |

Used by: [`quality`](#col-quality)

#### `ItemQualities`

Kind: `enum`

Source: `src/game/SharedDefines.h enum ItemQualities`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `ITEM_QUALITY_POOR` | GREY |
| `1` | `0x1` | `ITEM_QUALITY_NORMAL` | WHITE |
| `2` | `0x2` | `ITEM_QUALITY_UNCOMMON` | GREEN |
| `3` | `0x3` | `ITEM_QUALITY_RARE` | BLUE |
| `4` | `0x4` | `ITEM_QUALITY_EPIC` | PURPLE |
| `5` | `0x5` | `ITEM_QUALITY_LEGENDARY` | ORANGE |
| `6` | `0x6` | `ITEM_QUALITY_ARTIFACT` | LIGHT YELLOW |

Used by: [`spelltrigger_1`](#col-spelltrigger-1), [`spelltrigger_2`](#col-spelltrigger-2), [`spelltrigger_3`](#col-spelltrigger-3), [`spelltrigger_4`](#col-spelltrigger-4), [`spelltrigger_5`](#col-spelltrigger-5)

#### `ItemSpelltriggerType`

Kind: `enum`

Source: `src/game/Objects/ItemPrototype.h enum ItemSpelltriggerType`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `ITEM_SPELLTRIGGER_ON_USE` | use after equip cooldown |
| `1` | `0x1` | `ITEM_SPELLTRIGGER_ON_EQUIP` | Spelltrigger On Equip |
| `2` | `0x2` | `ITEM_SPELLTRIGGER_CHANCE_ON_HIT` | Spelltrigger Chance On Hit |
| `4` | `0x4` | `ITEM_SPELLTRIGGER_SOULSTONE` | Spelltrigger Soulstone |
| `5` | `0x5` | `ITEM_SPELLTRIGGER_ON_NO_DELAY_USE` | no equip cooldown |

Used by: [`page_language`](#col-page-language)

#### `Language`

Kind: `enum`

Source: `src/game/SharedDefines.h enum Language`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `LANG_UNIVERSAL` | Lang Universal |
| `1` | `0x1` | `LANG_ORCISH` | Lang Orcish |
| `2` | `0x2` | `LANG_DARNASSIAN` | Lang Darnassian |
| `3` | `0x3` | `LANG_TAURAHE` | Lang Taurahe |
| `6` | `0x6` | `LANG_DWARVISH` | Lang Dwarvish |
| `7` | `0x7` | `LANG_COMMON` | Lang Common |
| `8` | `0x8` | `LANG_DEMONIC` | Lang Demonic |
| `9` | `0x9` | `LANG_TITAN` | Lang Titan |
| `10` | `0xA` | `LANG_THALASSIAN` | Lang Thalassian |
| `11` | `0xB` | `LANG_DRACONIC` | Lang Draconic |
| `12` | `0xC` | `LANG_KALIMAG` | Lang Kalimag |
| `13` | `0xD` | `LANG_GNOMISH` | Lang Gnomish |
| `14` | `0xE` | `LANG_TROLL` | Lang Troll |
| `33` | `0x21` | `LANG_GUTTERSPEAK` | Lang Gutterspeak |
| `4294967295` | `0xFFFFFFFF` | `LANG_ADDON` | used by addons, in 2.4.0 not exit, replaced by messagetype? |

Used by: [`allowable_race`](#col-allowable-race)

#### `RaceMask`

Kind: `mask`

Source: `src/game/SharedDefines.h race mask constants`

Race masks use 1 &lt;&lt; (race id - 1). Combine allowed races with bitwise OR.

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `RACEMASK_HUMAN` | Human |
| `2` | `0x2` | `RACEMASK_ORC` | Orc |
| `4` | `0x4` | `RACEMASK_DWARF` | Dwarf |
| `8` | `0x8` | `RACEMASK_NIGHTELF` | Night elf |
| `16` | `0x10` | `RACEMASK_UNDEAD_PLAYER` | Undead player |
| `32` | `0x20` | `RACEMASK_TAUREN` | Tauren |
| `64` | `0x40` | `RACEMASK_GNOME` | Gnome |
| `128` | `0x80` | `RACEMASK_TROLL` | Troll |
| `256` | `0x100` | `RACEMASK_GOBLIN` | Goblin |
| `512` | `0x200` | `RACEMASK_HIGH_ELF` | High elf |

Used by: [`required_reputation_rank`](#col-required-reputation-rank)

#### `ReputationRank`

Kind: `enum`

Source: `src/game/SharedDefines.h enum ReputationRank`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `REP_HATED` | Rep Hated |
| `1` | `0x1` | `REP_HOSTILE` | Rep Hostile |
| `2` | `0x2` | `REP_UNFRIENDLY` | Rep Unfriendly |
| `3` | `0x3` | `REP_NEUTRAL` | Rep Neutral |
| `4` | `0x4` | `REP_FRIENDLY` | Rep Friendly |
| `5` | `0x5` | `REP_HONORED` | Rep Honored |
| `6` | `0x6` | `REP_REVERED` | Rep Revered |
| `7` | `0x7` | `REP_EXALTED` | Rep Exalted |

Used by: [`sheath`](#col-sheath)

#### `SheathTypes`

Kind: `enum`

Source: `src/game/SharedDefines.h enum SheathTypes`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `SHEATHETYPE_NONE` | Sheathetype None |
| `1` | `0x1` | `SHEATHETYPE_MAINHAND` | Sheathetype Mainhand |
| `2` | `0x2` | `SHEATHETYPE_OFFHAND` | Sheathetype Offhand |
| `3` | `0x3` | `SHEATHETYPE_LARGEWEAPONLEFT` | Sheathetype Largeweaponleft |
| `4` | `0x4` | `SHEATHETYPE_LARGEWEAPONRIGHT` | Sheathetype Largeweaponright |
| `5` | `0x5` | `SHEATHETYPE_HIPWEAPONLEFT` | Sheathetype Hipweaponleft |
| `6` | `0x6` | `SHEATHETYPE_HIPWEAPONRIGHT` | Sheathetype Hipweaponright |
| `7` | `0x7` | `SHEATHETYPE_SHIELD` | Sheathetype Shield |

Used by: [`dmg_type1`](#col-dmg-type1), [`dmg_type2`](#col-dmg-type2), [`dmg_type3`](#col-dmg-type3), [`dmg_type4`](#col-dmg-type4), [`dmg_type5`](#col-dmg-type5)

#### `SpellSchools`

Kind: `enum`

Source: `src/game/Spells/SpellDefines.h enum SpellSchools`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `SPELL_SCHOOL_NORMAL` | Physical, Armor |
| `1` | `0x1` | `SPELL_SCHOOL_HOLY` | School Holy |
| `2` | `0x2` | `SPELL_SCHOOL_FIRE` | School Fire |
| `3` | `0x3` | `SPELL_SCHOOL_NATURE` | School Nature |
| `4` | `0x4` | `SPELL_SCHOOL_FROST` | School Frost |
| `5` | `0x5` | `SPELL_SCHOOL_SHADOW` | School Shadow |
| `6` | `0x6` | `SPELL_SCHOOL_ARCANE` | School Arcane |
