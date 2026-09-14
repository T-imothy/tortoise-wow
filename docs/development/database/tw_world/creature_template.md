---
layout: default
title: creature_template
---

# creature_template

Creature System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 80 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-display-id1"></a>`display_id1` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-display-id2"></a>`display_id2` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-display-id3"></a>`display_id3` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-display-id4"></a>`display_id4` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-mount-display-id"></a>`mount_display_id` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-name"></a>`name` | `char(100)` | NO |  | `'0'` |  | text/string data |
| <a id="col-subname"></a>`subname` | `char(100)` | YES |  | `NULL` |  | text/string data |
| <a id="col-gossip-menu-id"></a>`gossip_menu_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-level-min"></a>`level_min` | `tinyint(3) unsigned` | NO |  | `1` |  | non-negative numeric value |
| <a id="col-level-max"></a>`level_max` | `tinyint(3) unsigned` | NO |  | `1` |  | non-negative numeric value |
| <a id="col-health-min"></a>`health_min` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-health-max"></a>`health_max` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-mana-min"></a>`mana_min` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-mana-max"></a>`mana_max` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-armor"></a>`armor` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-faction"></a>`faction` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-npc-flags"></a>`npc_flags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses NPCFlags mask values |
| <a id="col-speed-walk"></a>`speed_walk` | `float` | NO |  | `1` |  | Result of 2.5/2.5, most common value; numeric value |
| <a id="col-speed-run"></a>`speed_run` | `float` | NO |  | `1.14286` |  | Result of 8.0/7.0, most common value; numeric value |
| <a id="col-scale"></a>`scale` | `float` | NO |  | `1` |  | numeric value |
| <a id="col-detection-range"></a>`detection_range` | `float` | NO |  | `20` |  | numeric value |
| <a id="col-call-for-help-range"></a>`call_for_help_range` | `float` | NO |  | `5` |  | numeric value |
| <a id="col-leash-range"></a>`leash_range` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-rank"></a>`rank` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses CreatureEliteType enum values |
| <a id="col-xp-multiplier"></a>`xp_multiplier` | `float` | NO |  | `1` |  | numeric value |
| <a id="col-dmg-min"></a>`dmg_min` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-dmg-max"></a>`dmg_max` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-dmg-school"></a>`dmg_school` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellSchools enum values |
| <a id="col-attack-power"></a>`attack_power` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-dmg-multiplier"></a>`dmg_multiplier` | `float` | NO |  | `1` |  | numeric value |
| <a id="col-base-attack-time"></a>`base_attack_time` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-ranged-attack-time"></a>`ranged_attack_time` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-unit-class"></a>`unit_class` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Classes enum values |
| <a id="col-unit-flags"></a>`unit_flags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses UnitFlags mask values |
| <a id="col-dynamic-flags"></a>`dynamic_flags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses UnitDynamicFlags mask values |
| <a id="col-beast-family"></a>`beast_family` | `tinyint(4)` | NO |  | `0` |  | numeric value; Uses CreatureFamily enum values |
| <a id="col-trainer-type"></a>`trainer_type` | `tinyint(4)` | NO |  | `0` |  | numeric value; Uses TrainerType enum values |
| <a id="col-trainer-spell"></a>`trainer_spell` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-trainer-class"></a>`trainer_class` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-trainer-race"></a>`trainer_race` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-ranged-dmg-min"></a>`ranged_dmg_min` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-ranged-dmg-max"></a>`ranged_dmg_max` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-ranged-attack-power"></a>`ranged_attack_power` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-type"></a>`type` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses CreatureType enum values |
| <a id="col-type-flags"></a>`type_flags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses CreatureTypeFlags mask values |
| <a id="col-loot-id"></a>`loot_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-pickpocket-loot-id"></a>`pickpocket_loot_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-skinning-loot-id"></a>`skinning_loot_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-holy-res"></a>`holy_res` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-fire-res"></a>`fire_res` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-nature-res"></a>`nature_res` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-frost-res"></a>`frost_res` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-shadow-res"></a>`shadow_res` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-arcane-res"></a>`arcane_res` | `smallint(6)` | NO |  | `0` |  | numeric value |
| <a id="col-spell-id1"></a>`spell_id1` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spell-id2"></a>`spell_id2` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spell-id3"></a>`spell_id3` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spell-id4"></a>`spell_id4` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spell-list-id"></a>`spell_list_id` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-pet-spell-list-id"></a>`pet_spell_list_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spawn-spell-id"></a>`spawn_spell_id` | `mediumint(8) unsigned` | NO |  | `0` |  | Spell with effect 46 that will be cast immediately upon spawning. Creature will remain unattackable until the cast finishes.; non-negative numeric value |
| <a id="col-auras"></a>`auras` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-gold-min"></a>`gold_min` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-gold-max"></a>`gold_max` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-ai-name"></a>`ai_name` | `char(64)` | NO |  | `''` |  | text/string data |
| <a id="col-movement-type"></a>`movement_type` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses MovementGeneratorType enum values |
| <a id="col-inhabit-type"></a>`inhabit_type` | `tinyint(3) unsigned` | NO |  | `3` |  | non-negative numeric value; Uses InhabitType mask values |
| <a id="col-civilian"></a>`civilian` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-racial-leader"></a>`racial_leader` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-regeneration"></a>`regeneration` | `tinyint(3) unsigned` | NO |  | `3` |  | non-negative numeric value; Uses RegenStatsFlags mask values |
| <a id="col-equipment-id"></a>`equipment_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-trainer-id"></a>`trainer_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-vendor-id"></a>`vendor_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-mechanic-immune-mask"></a>`mechanic_immune_mask` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses MechanicImmuneMask mask values |
| <a id="col-school-immune-mask"></a>`school_immune_mask` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses SpellSchoolMask mask values |
| <a id="col-immunity-flags"></a>`immunity_flags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses CreatureImmunityFlags mask values |
| <a id="col-flags-extra"></a>`flags_extra` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses CreatureFlagsExtra mask values |
| <a id="col-phase-quest-id"></a>`phase_quest_id` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-script-name"></a>`script_name` | `char(64)` | NO |  | `''` |  | text/string data; script id or script name |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `display_id1`

non-negative numeric value.

### `display_id2`

non-negative numeric value.

### `display_id3`

non-negative numeric value.

### `display_id4`

non-negative numeric value.

### `mount_display_id`

non-negative numeric value.

### `name`

text/string data.

### `subname`

text/string data.

### `gossip_menu_id`

non-negative numeric value.

References: [`gossip_menu`](gossip_menu.md).`entry`.

### `level_min`

non-negative numeric value.

### `level_max`

non-negative numeric value.

### `health_min`

non-negative numeric value.

### `health_max`

non-negative numeric value.

### `mana_min`

non-negative numeric value.

### `mana_max`

non-negative numeric value.

### `armor`

non-negative numeric value.

### `faction`

non-negative numeric value.

References: [`faction_template`](faction_template.md).`entry`.

### `npc_flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `NPCFlags` (mask) from `src/game/Objects/UnitDefines.h enum NPCFlags`.

### `speed_walk`

numeric value.

### `speed_run`

numeric value.

### `scale`

numeric value.

### `detection_range`

numeric value.

### `call_for_help_range`

numeric value.

### `leash_range`

numeric value.

### `rank`

non-negative numeric value.

Value set: `CreatureEliteType` (enum) from `src/game/SharedDefines.h enum CreatureEliteType`.

### `xp_multiplier`

numeric value.

### `dmg_min`

numeric value.

### `dmg_max`

numeric value.

### `dmg_school`

non-negative numeric value.

Value set: `SpellSchools` (enum) from `src/game/Spells/SpellDefines.h enum SpellSchools`.

### `attack_power`

non-negative numeric value.

### `dmg_multiplier`

numeric value.

### `base_attack_time`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `ranged_attack_time`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `unit_class`

non-negative numeric value.

Value set: `Classes` (enum) from `src/game/SharedDefines.h enum Classes`.

### `unit_flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `UnitFlags` (mask) from `src/game/Objects/UnitDefines.h enum UnitFlags`.

### `dynamic_flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `UnitDynamicFlags` (mask) from `src/game/SharedDefines.h UNIT_DYNFLAG values`.

### `beast_family`

numeric value.

Value set: `CreatureFamily` (enum) from `src/game/SharedDefines.h enum CreatureFamily`.

### `trainer_type`

numeric value.

Value set: `TrainerType` (enum) from `src/game/SharedDefines.h enum TrainerType`.

### `trainer_spell`

non-negative numeric value.

### `trainer_class`

non-negative numeric value.

### `trainer_race`

non-negative numeric value.

### `ranged_dmg_min`

numeric value.

### `ranged_dmg_max`

numeric value.

### `ranged_attack_power`

non-negative numeric value.

### `type`

non-negative numeric value.

Value set: `CreatureType` (enum) from `src/game/SharedDefines.h enum CreatureType`.

### `type_flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `CreatureTypeFlags` (mask) from `src/game/SharedDefines.h enum CreatureTypeFlags`.

### `loot_id`

non-negative numeric value.

References: [`creature_loot_template`](creature_loot_template.md).`entry`.

### `pickpocket_loot_id`

non-negative numeric value.

References: [`pickpocketing_loot_template`](pickpocketing_loot_template.md).`entry`.

### `skinning_loot_id`

non-negative numeric value.

References: [`skinning_loot_template`](skinning_loot_template.md).`entry`.

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

### `spell_id1`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `spell_id2`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `spell_id3`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `spell_id4`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `spell_list_id`

non-negative numeric value.

References: [`creature_spells`](creature_spells.md).`entry`.

### `pet_spell_list_id`

non-negative numeric value.

### `spawn_spell_id`

non-negative numeric value.

### `auras`

text/string data.

### `gold_min`

non-negative numeric value; money/cost value, usually copper.

### `gold_max`

non-negative numeric value; money/cost value, usually copper.

### `ai_name`

text/string data.

### `movement_type`

non-negative numeric value.

Value set: `MovementGeneratorType` (enum) from `src/game/Movement/MotionMaster.h enum MovementGeneratorType`.

### `inhabit_type`

non-negative numeric value.

Value set: `InhabitType` (mask) from `src/game/Objects/Creature.h enum InhabitTypeValues`.

### `civilian`

non-negative numeric value.

### `racial_leader`

non-negative numeric value.

### `regeneration`

non-negative numeric value.

Value set: `RegenStatsFlags` (mask) from `src/game/Objects/Creature.h enum RegenStatsFlags`.

### `equipment_id`

non-negative numeric value.

References: [`creature_equip_template`](creature_equip_template.md).`entry`.

### `trainer_id`

non-negative numeric value.

References: [`npc_trainer_template`](npc_trainer_template.md).`entry`.

### `vendor_id`

non-negative numeric value.

References: [`npc_vendor_template`](npc_vendor_template.md).`entry`.

### `mechanic_immune_mask`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `MechanicImmuneMask` (mask) from `src/game/Spells/SpellDefines.h enum Mechanics`.

### `school_immune_mask`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `SpellSchoolMask` (mask) from `src/game/Spells/SpellDefines.h enum SpellSchoolMask`.

### `immunity_flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `CreatureImmunityFlags` (mask) from `src/game/Objects/Creature.h enum CreatureImmunityFlags`.

### `flags_extra`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `CreatureFlagsExtra` (mask) from `src/game/Objects/Creature.h enum CreatureFlagsExtra`.

### `phase_quest_id`

non-negative numeric value.

References: [`quest_template`](quest_template.md).`entry`.

### `script_name`

text/string data; script id or script name.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `equipment_id` | [`creature_equip_template`](creature_equip_template.md).`entry` | explicit | equipment template |
| `loot_id` | [`creature_loot_template`](creature_loot_template.md).`entry` | explicit | creature loot id |
| `spell_list_id` | [`creature_spells`](creature_spells.md).`entry` | explicit | AI spell list |
| `faction` | [`faction_template`](faction_template.md).`entry` | explicit | creature faction template |
| `gossip_menu_id` | [`gossip_menu`](gossip_menu.md).`entry` | explicit | gossip menu |
| `trainer_id` | [`npc_trainer_template`](npc_trainer_template.md).`entry` | explicit | trainer template |
| `vendor_id` | [`npc_vendor_template`](npc_vendor_template.md).`entry` | explicit | vendor template |
| `pickpocket_loot_id` | [`pickpocketing_loot_template`](pickpocketing_loot_template.md).`entry` | explicit | pickpocket loot id |
| `phase_quest_id` | [`quest_template`](quest_template.md).`entry` | explicit | phase quest |
| `skinning_loot_id` | [`skinning_loot_template`](skinning_loot_template.md).`entry` | explicit | skinning loot id |
| `spell_id1` | [`spell_template`](spell_template.md).`entry` | heuristic | spell id |
| `spell_id2` | [`spell_template`](spell_template.md).`entry` | heuristic | spell id |
| `spell_id3` | [`spell_template`](spell_template.md).`entry` | heuristic | spell id |
| `spell_id4` | [`spell_template`](spell_template.md).`entry` | heuristic | spell id |

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`pet_levelstats`](pet_levelstats.md).`creature_entry` | `entry` | heuristic | inferred from column name |
| [`creature_ai_events`](creature_ai_events.md).`creature_id` | `entry` | heuristic | inferred from column name |
| [`creature_onkill_reputation`](creature_onkill_reputation.md).`creature_id` | `entry` | heuristic | inferred from column name |
| [`script_escort_data`](script_escort_data.md).`creature_id` | `entry` | heuristic | inferred from column name |
| [`creature_movement_template`](creature_movement_template.md).`entry` | `entry` | explicit | template movement path |
| [`npc_trainer`](npc_trainer.md).`entry` | `entry` | explicit | trainer creature |
| [`npc_vendor`](npc_vendor.md).`entry` | `entry` | explicit | vendor creature |
| [`creature`](creature.md).`id` | `entry` | explicit | spawn uses template |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `Classes` | enum | [`unit_class`](#col-unit-class) | `src/game/SharedDefines.h enum Classes` | 9 |
| `CreatureEliteType` | enum | [`rank`](#col-rank) | `src/game/SharedDefines.h enum CreatureEliteType` | 6 |
| `CreatureFamily` | enum | [`beast_family`](#col-beast-family) | `src/game/SharedDefines.h enum CreatureFamily` | 24 |
| `CreatureFlagsExtra` | mask | [`flags_extra`](#col-flags-extra) | `src/game/Objects/Creature.h enum CreatureFlagsExtra` | 28 |
| `CreatureImmunityFlags` | mask | [`immunity_flags`](#col-immunity-flags) | `src/game/Objects/Creature.h enum CreatureImmunityFlags` | 7 |
| `CreatureType` | enum | [`type`](#col-type) | `src/game/SharedDefines.h enum CreatureType` | 11 |
| `CreatureTypeFlags` | mask | [`type_flags`](#col-type-flags) | `src/game/SharedDefines.h enum CreatureTypeFlags` | 7 |
| `InhabitType` | mask | [`inhabit_type`](#col-inhabit-type) | `src/game/Objects/Creature.h enum InhabitTypeValues` | 4 |
| `MechanicImmuneMask` | mask | [`mechanic_immune_mask`](#col-mechanic-immune-mask) | `src/game/Spells/SpellDefines.h enum Mechanics` | 31 |
| `MovementGeneratorType` | enum | [`movement_type`](#col-movement-type) | `src/game/Movement/MotionMaster.h enum MovementGeneratorType` | 18 |
| `NPCFlags` | mask | [`npc_flags`](#col-npc-flags) | `src/game/Objects/UnitDefines.h enum NPCFlags` | 18 |
| `RegenStatsFlags` | mask | [`regeneration`](#col-regeneration) | `src/game/Objects/Creature.h enum RegenStatsFlags` | 2 |
| `SpellSchoolMask` | mask | [`school_immune_mask`](#col-school-immune-mask) | `src/game/Spells/SpellDefines.h enum SpellSchoolMask` | 10 |
| `SpellSchools` | enum | [`dmg_school`](#col-dmg-school) | `src/game/Spells/SpellDefines.h enum SpellSchools` | 7 |
| `TrainerType` | enum | [`trainer_type`](#col-trainer-type) | `src/game/SharedDefines.h enum TrainerType` | 4 |
| `UnitDynamicFlags` | mask | [`dynamic_flags`](#col-dynamic-flags) | `src/game/SharedDefines.h UNIT_DYNFLAG values` | 6 |
| `UnitFlags` | mask | [`unit_flags`](#col-unit-flags) | `src/game/Objects/UnitDefines.h enum UnitFlags` | 26 |

### Possible Values

Used by: [`unit_class`](#col-unit-class)

#### `Classes`

Kind: `enum`

Source: `src/game/SharedDefines.h enum Classes`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `CLASS_WARRIOR` | Warrior |
| `2` | `0x2` | `CLASS_PALADIN` | Paladin |
| `3` | `0x3` | `CLASS_HUNTER` | Hunter |
| `4` | `0x4` | `CLASS_ROGUE` | Rogue |
| `5` | `0x5` | `CLASS_PRIEST` | Priest |
| `7` | `0x7` | `CLASS_SHAMAN` | Shaman |
| `8` | `0x8` | `CLASS_MAGE` | Mage |
| `9` | `0x9` | `CLASS_WARLOCK` | Warlock |
| `11` | `0xB` | `CLASS_DRUID` | Druid |

Used by: [`rank`](#col-rank)

#### `CreatureEliteType`

Kind: `enum`

Source: `src/game/SharedDefines.h enum CreatureEliteType`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `CREATURE_ELITE_NORMAL` | Elite Normal |
| `1` | `0x1` | `CREATURE_ELITE_ELITE` | Elite Elite |
| `2` | `0x2` | `CREATURE_ELITE_RAREELITE` | Elite Rareelite |
| `3` | `0x3` | `CREATURE_ELITE_WORLDBOSS` | Elite Worldboss |
| `4` | `0x4` | `CREATURE_ELITE_RARE` | Elite Rare |
| `5` | `0x5` | `CREATURE_UNKNOWN` | found in 2.2.3 for 2 mobs |

Used by: [`beast_family`](#col-beast-family)

#### `CreatureFamily`

Kind: `enum`

Source: `src/game/SharedDefines.h enum CreatureFamily`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `CREATURE_FAMILY_WOLF` | Wolf |
| `2` | `0x2` | `CREATURE_FAMILY_CAT` | Cat |
| `3` | `0x3` | `CREATURE_FAMILY_SPIDER` | Spider |
| `4` | `0x4` | `CREATURE_FAMILY_BEAR` | Bear |
| `5` | `0x5` | `CREATURE_FAMILY_BOAR` | Boar |
| `6` | `0x6` | `CREATURE_FAMILY_CROCOLISK` | Crocolisk |
| `7` | `0x7` | `CREATURE_FAMILY_CARRION_BIRD` | Carrion bird |
| `8` | `0x8` | `CREATURE_FAMILY_CRAB` | Crab |
| `9` | `0x9` | `CREATURE_FAMILY_GORILLA` | Gorilla |
| `10` | `0xA` | `CREATURE_FAMILY_HORSE_CUSTOM` | Horse, custom |
| `11` | `0xB` | `CREATURE_FAMILY_RAPTOR` | Raptor |
| `12` | `0xC` | `CREATURE_FAMILY_TALLSTRIDER` | Tallstrider |
| `15` | `0xF` | `CREATURE_FAMILY_FELHUNTER` | Felhunter |
| `16` | `0x10` | `CREATURE_FAMILY_VOIDWALKER` | Voidwalker |
| `17` | `0x11` | `CREATURE_FAMILY_SUCCUBUS` | Succubus |
| `19` | `0x13` | `CREATURE_FAMILY_DOOMGUARD` | Doomguard |
| `20` | `0x14` | `CREATURE_FAMILY_SCORPID` | Scorpid |
| `21` | `0x15` | `CREATURE_FAMILY_TURTLE` | Turtle |
| `23` | `0x17` | `CREATURE_FAMILY_IMP` | Imp |
| `24` | `0x18` | `CREATURE_FAMILY_BAT` | Bat |
| `25` | `0x19` | `CREATURE_FAMILY_HYENA` | Hyena |
| `26` | `0x1A` | `CREATURE_FAMILY_OWL` | Owl |
| `27` | `0x1B` | `CREATURE_FAMILY_WIND_SERPENT` | Wind serpent |
| `28` | `0x1C` | `CREATURE_FAMILY_REMOTE_CONTROL` | Remote control |

Used by: [`flags_extra`](#col-flags-extra)

#### `CreatureFlagsExtra`

Kind: `mask`

Source: `src/game/Objects/Creature.h enum CreatureFlagsExtra`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `CREATURE_FLAG_EXTRA_INSTANCE_BIND` | Killing this creature binds players to the raid |
| `2` | `0x2` | `CREATURE_FLAG_EXTRA_NO_AGGRO` | Does not attack nearby hostile targets |
| `4` | `0x4` | `CREATURE_FLAG_EXTRA_NO_PARRY` | Cannot parry |
| `8` | `0x8` | `CREATURE_FLAG_EXTRA_SUMMON_GUARD` | Summons guard on hostile player proximity or attack |
| `16` | `0x10` | `CREATURE_FLAG_EXTRA_NO_BLOCK` | Cannot block |
| `32` | `0x20` | `CREATURE_FLAG_EXTRA_NO_CRUSH` | Cannot perform crushing attacks |
| `64` | `0x40` | `CREATURE_FLAG_EXTRA_FIXED_Z` | Does not fall |
| `128` | `0x80` | `CREATURE_FLAG_EXTRA_INVISIBLE` | Always invisible to players; often trigger creatures |
| `512` | `0x200` | `CREATURE_FLAG_EXTRA_AGGRO_ZONE` | Sets itself in combat with the zone on aggro |
| `1024` | `0x400` | `CREATURE_FLAG_EXTRA_GUARD` | Guard creature |
| `2048` | `0x800` | `CREATURE_FLAG_EXTRA_NO_THREAT_LIST` | Does not select targets from threat |
| `4096` | `0x1000` | `CREATURE_FLAG_EXTRA_KEEP_POSITIVE_AURAS_ON_EVADE` | Keeps positive auras at reset |
| `8192` | `0x2000` | `CREATURE_FLAG_EXTRA_ALWAYS_CRUSH` | Always rolls crushing melee outcome when applicable |
| `32768` | `0x8000` | `CREATURE_FLAG_EXTRA_CHASE_GEN_NO_BACKING` | Does not back up inside bounding radius |
| `65536` | `0x10000` | `CREATURE_FLAG_EXTRA_NO_ASSIST` | Does not aggro when nearby creatures aggro |
| `131072` | `0x20000` | `CREATURE_FLAG_EXTRA_NO_TARGET` | Does not acquire targets |
| `262144` | `0x40000` | `CREATURE_FLAG_EXTRA_ONLY_VISIBLE_TO_FRIENDLY` | Only visible to friendly units |
| `524288` | `0x80000` | `CREATURE_FLAG_EXTRA_PVP` | Applies PvP unit flag by default |
| `1048576` | `0x100000` | `CREATURE_FLAG_EXTRA_CAN_ASSIST` | Can assist players |
| `2097152` | `0x200000` | `CREATURE_FLAG_EXTRA_LARGE_AOI` | Large area of interest, 200 yards |
| `4194304` | `0x400000` | `CREATURE_FLAG_EXTRA_GIGANTIC_AOI` | Gigantic area of interest, 400 yards |
| `8388608` | `0x800000` | `CREATURE_FLAG_EXTRA_INFINITE_AOI` | Infinite area of interest |
| `16777216` | `0x1000000` | `CREATURE_FLAG_EXTRA_NO_MOVEMENT_PAUSE` | Does not pause movement during player interaction |
| `33554432` | `0x2000000` | `CREATURE_FLAG_EXTRA_ALWAYS_RUN` | Runs out of combat |
| `67108864` | `0x4000000` | `CREATURE_FLAG_EXTRA_NO_UNREACHABLE_EVADE` | Does not evade when target is unreachable |
| `134217728` | `0x8000000` | `CREATURE_FLAG_EXTRA_APPEAR_DEAD` | Applies UNIT_DYNFLAG_DEAD |
| `268435456` | `0x10000000` | `CREATURE_FLAG_EXTRA_NO_LEASH_EVADE` | Does not evade when target runs away |
| `536870912` | `0x20000000` | `CREATURE_FLAG_EXTRA_DESPAWN_INSTANTLY` | Despawns on death |

Used by: [`immunity_flags`](#col-immunity-flags)

#### `CreatureImmunityFlags`

Kind: `mask`

Source: `src/game/Objects/Creature.h enum CreatureImmunityFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `CREATURE_IMMUNITY_AOE` | Immune to area effects |
| `2` | `0x2` | `CREATURE_IMMUNITY_TAUNT` | Immune to taunt effects |
| `4` | `0x4` | `CREATURE_IMMUNITY_MOD_STAT` | Immune to stat modification auras |
| `8` | `0x8` | `CREATURE_IMMUNITY_MOD_CAST_SPEED` | Immune to cast-speed modification |
| `16` | `0x10` | `CREATURE_IMMUNITY_DISEASE` | Immune to disease dispel type |
| `32` | `0x20` | `CREATURE_IMMUNITY_POISON` | Immune to poison dispel type |
| `64` | `0x40` | `CREATURE_IMMUNITY_CURSE` | Immune to curse dispel type |

Used by: [`type`](#col-type)

#### `CreatureType`

Kind: `enum`

Source: `src/game/SharedDefines.h enum CreatureType`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `CREATURE_TYPE_BEAST` | Beast |
| `2` | `0x2` | `CREATURE_TYPE_DRAGONKIN` | Dragonkin |
| `3` | `0x3` | `CREATURE_TYPE_DEMON` | Demon |
| `4` | `0x4` | `CREATURE_TYPE_ELEMENTAL` | Elemental |
| `5` | `0x5` | `CREATURE_TYPE_GIANT` | Giant |
| `6` | `0x6` | `CREATURE_TYPE_UNDEAD` | Undead |
| `7` | `0x7` | `CREATURE_TYPE_HUMANOID` | Humanoid |
| `8` | `0x8` | `CREATURE_TYPE_CRITTER` | Critter |
| `9` | `0x9` | `CREATURE_TYPE_MECHANICAL` | Mechanical |
| `10` | `0xA` | `CREATURE_TYPE_NOT_SPECIFIED` | Not specified |
| `11` | `0xB` | `CREATURE_TYPE_TOTEM` | Totem |

Used by: [`type_flags`](#col-type-flags)

#### `CreatureTypeFlags`

Kind: `mask`

Source: `src/game/SharedDefines.h enum CreatureTypeFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `CREATURE_TYPEFLAGS_TAMEABLE` | Creature can be tamed |
| `2` | `0x2` | `CREATURE_TYPEFLAGS_GHOST_VISIBLE` | Visible to ghosts |
| `4` | `0x4` | `CREATURE_TYPEFLAGS_BOSS` | Boss classification |
| `8` | `0x8` | `CREATURE_TYPEFLAGS_NO_WOUND_ANIM` | No wound animation |
| `16` | `0x10` | `CREATURE_TYPEFLAGS_HIDE_FACTION_TOOLTIP` | Hide faction tooltip |
| `32` | `0x20` | `CREATURE_TYPEFLAGS_UNK6` | Unknown |
| `64` | `0x40` | `CREATURE_TYPEFLAGS_SPELL_ATTACKABLE` | Attackable by spells |

Used by: [`inhabit_type`](#col-inhabit-type)

#### `InhabitType`

Kind: `mask`

Source: `src/game/Objects/Creature.h enum InhabitTypeValues`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `INHABIT_GROUND` | Can inhabit ground |
| `2` | `0x2` | `INHABIT_WATER` | Can inhabit water |
| `4` | `0x4` | `INHABIT_AIR` | Can inhabit air |
| `7` | `0x7` | `INHABIT_ANYWHERE` | Ground, water, and air |

Used by: [`mechanic_immune_mask`](#col-mechanic-immune-mask)

#### `MechanicImmuneMask`

Kind: `mask`

Source: `src/game/Spells/SpellDefines.h enum Mechanics`

Mechanic immunity masks use 1 &lt;&lt; (mechanic id - 1).

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `MECHANIC_CHARM` | Charm |
| `2` | `0x2` | `MECHANIC_DISORIENTED` | Disoriented |
| `4` | `0x4` | `MECHANIC_DISARM` | Disarm |
| `8` | `0x8` | `MECHANIC_DISTRACT` | Distract |
| `16` | `0x10` | `MECHANIC_FEAR` | Fear |
| `32` | `0x20` | `MECHANIC_FUMBLE` | Fumble |
| `64` | `0x40` | `MECHANIC_ROOT` | Root |
| `128` | `0x80` | `MECHANIC_PACIFY` | Pacify |
| `256` | `0x100` | `MECHANIC_SILENCE` | Silence |
| `512` | `0x200` | `MECHANIC_SLEEP` | Sleep |
| `1024` | `0x400` | `MECHANIC_SNARE` | Snare |
| `2048` | `0x800` | `MECHANIC_STUN` | Stun |
| `4096` | `0x1000` | `MECHANIC_FREEZE` | Freeze |
| `8192` | `0x2000` | `MECHANIC_KNOCKOUT` | Knockout |
| `16384` | `0x4000` | `MECHANIC_BLEED` | Bleed |
| `32768` | `0x8000` | `MECHANIC_BANDAGE` | Bandage |
| `65536` | `0x10000` | `MECHANIC_POLYMORPH` | Polymorph |
| `131072` | `0x20000` | `MECHANIC_BANISH` | Banish |
| `262144` | `0x40000` | `MECHANIC_SHIELD` | Shield |
| `524288` | `0x80000` | `MECHANIC_SHACKLE` | Shackle |
| `1048576` | `0x100000` | `MECHANIC_MOUNT` | Mount |
| `2097152` | `0x200000` | `MECHANIC_PERSUADE` | Persuade |
| `4194304` | `0x400000` | `MECHANIC_TURN` | Turn |
| `8388608` | `0x800000` | `MECHANIC_HORROR` | Horror |
| `16777216` | `0x1000000` | `MECHANIC_INVULNERABILITY` | Invulnerability |
| `33554432` | `0x2000000` | `MECHANIC_INTERRUPT` | Interrupt |
| `67108864` | `0x4000000` | `MECHANIC_DAZE` | Daze |
| `134217728` | `0x8000000` | `MECHANIC_DISCOVERY` | Discovery |
| `268435456` | `0x10000000` | `MECHANIC_IMMUNE_SHIELD` | Immune shield |
| `536870912` | `0x20000000` | `MECHANIC_SAPPED` | Sapped |
| `1073741824` | `0x40000000` | `MECHANIC_SLOW_CAST_SPEED` | Slow cast speed |

Used by: [`movement_type`](#col-movement-type)

#### `MovementGeneratorType`

Kind: `enum`

Source: `src/game/Movement/MotionMaster.h enum MovementGeneratorType`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `IDLE_MOTION_TYPE` | IdleMovementGenerator.h |
| `1` | `0x1` | `RANDOM_MOTION_TYPE` | RandomMovementGenerator.h |
| `2` | `0x2` | `WAYPOINT_MOTION_TYPE` | WaypointMovementGenerator.h |
| `4` | `0x4` | `CONFUSED_MOTION_TYPE` | ConfusedMovementGenerator.h |
| `5` | `0x5` | `CHASE_MOTION_TYPE` | TargetedMovementGenerator.h |
| `6` | `0x6` | `HOME_MOTION_TYPE` | HomeMovementGenerator.h |
| `7` | `0x7` | `FLIGHT_MOTION_TYPE` | WaypointMovementGenerator.h |
| `8` | `0x8` | `POINT_MOTION_TYPE` | PointMovementGenerator.h |
| `9` | `0x9` | `FLEEING_MOTION_TYPE` | FleeingMovementGenerator.h |
| `10` | `0xA` | `DISTRACT_MOTION_TYPE` | IdleMovementGenerator.h |
| `11` | `0xB` | `ASSISTANCE_MOTION_TYPE` | PointMovementGenerator.h (first part of flee for assistance) |
| `12` | `0xC` | `ASSISTANCE_DISTRACT_MOTION_TYPE` | IdleMovementGenerator.h (second part of flee for assistance) |
| `13` | `0xD` | `TIMED_FLEEING_MOTION_TYPE` | FleeingMovementGenerator.h (alt.second part of flee for assistance) |
| `14` | `0xE` | `FOLLOW_MOTION_TYPE` | TargetedMovementGenerator.h |
| `15` | `0xF` | `EFFECT_MOTION_TYPE` | Effect Motion Type |
| `16` | `0x10` | `PATROL_MOTION_TYPE` | Patrol Motion Type |
| `17` | `0x11` | `CHARGE_MOTION_TYPE` | Charge Motion Type |
| `18` | `0x12` | `DISTANCING_MOTION_TYPE` | Distancing Motion Type |

Used by: [`npc_flags`](#col-npc-flags)

#### `NPCFlags`

Kind: `mask`

Source: `src/game/Objects/UnitDefines.h enum NPCFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `UNIT_NPC_FLAG_GOSSIP` | Shows gossip interaction |
| `2` | `0x2` | `UNIT_NPC_FLAG_QUESTGIVER` | Can start or complete quests |
| `4` | `0x4` | `UNIT_NPC_FLAG_VENDOR` | Vendor |
| `8` | `0x8` | `UNIT_NPC_FLAG_FLIGHTMASTER` | Flight master |
| `16` | `0x10` | `UNIT_NPC_FLAG_TRAINER` | Trainer |
| `32` | `0x20` | `UNIT_NPC_FLAG_SPIRITHEALER` | Spirit healer |
| `64` | `0x40` | `UNIT_NPC_FLAG_SPIRITGUIDE` | Spirit guide |
| `128` | `0x80` | `UNIT_NPC_FLAG_INNKEEPER` | Innkeeper |
| `256` | `0x100` | `UNIT_NPC_FLAG_BANKER` | Banker |
| `512` | `0x200` | `UNIT_NPC_FLAG_PETITIONER` | Petitioner |
| `1024` | `0x400` | `UNIT_NPC_FLAG_TABARDDESIGNER` | Tabard designer |
| `2048` | `0x800` | `UNIT_NPC_FLAG_BATTLEMASTER` | Battlemaster |
| `4096` | `0x1000` | `UNIT_NPC_FLAG_AUCTIONEER` | Auctioneer |
| `8192` | `0x2000` | `UNIT_NPC_FLAG_STABLEMASTER` | Stable master |
| `16384` | `0x4000` | `UNIT_NPC_FLAG_REPAIR` | Repairs equipment |
| `268435456` | `0x10000000` | `UNIT_NPC_FLAG_TRANSMOG` | Transmogrification service |
| `536870912` | `0x20000000` | `UNIT_NPC_FLAG_OUTDOORPVP` | Outdoor PvP interaction |
| `1073741824` | `0x40000000` | `UNIT_NPC_FLAG_ITEMRESTORE` | Item restore service |

Used by: [`regeneration`](#col-regeneration)

#### `RegenStatsFlags`

Kind: `mask`

Source: `src/game/Objects/Creature.h enum RegenStatsFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `REGEN_FLAG_HEALTH` | Regenerate health |
| `2` | `0x2` | `REGEN_FLAG_POWER` | Regenerate power |

Used by: [`school_immune_mask`](#col-school-immune-mask)

#### `SpellSchoolMask`

Kind: `mask`

Source: `src/game/Spells/SpellDefines.h enum SpellSchoolMask`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `SPELL_SCHOOL_MASK_NORMAL` | Physical/normal |
| `2` | `0x2` | `SPELL_SCHOOL_MASK_HOLY` | Holy |
| `4` | `0x4` | `SPELL_SCHOOL_MASK_FIRE` | Fire |
| `8` | `0x8` | `SPELL_SCHOOL_MASK_NATURE` | Nature |
| `16` | `0x10` | `SPELL_SCHOOL_MASK_FROST` | Frost |
| `32` | `0x20` | `SPELL_SCHOOL_MASK_SHADOW` | Shadow |
| `64` | `0x40` | `SPELL_SCHOOL_MASK_ARCANE` | Arcane |
| `124` | `0x7C` | `SPELL_SCHOOL_MASK_SPELL` | Fire, nature, frost, shadow, and arcane |
| `126` | `0x7E` | `SPELL_SCHOOL_MASK_MAGIC` | Holy plus spell schools |
| `127` | `0x7F` | `SPELL_SCHOOL_MASK_ALL` | All schools |

Used by: [`dmg_school`](#col-dmg-school)

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

Used by: [`trainer_type`](#col-trainer-type)

#### `TrainerType`

Kind: `enum`

Source: `src/game/SharedDefines.h enum TrainerType`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `TRAINER_TYPE_CLASS` | Class trainer |
| `1` | `0x1` | `TRAINER_TYPE_MOUNTS` | Mount trainer |
| `2` | `0x2` | `TRAINER_TYPE_TRADESKILLS` | Profession trainer |
| `3` | `0x3` | `TRAINER_TYPE_PETS` | Pet trainer |

Used by: [`dynamic_flags`](#col-dynamic-flags)

#### `UnitDynamicFlags`

Kind: `mask`

Source: `src/game/SharedDefines.h UNIT_DYNFLAG values`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `UNIT_DYNFLAG_LOOTABLE` | Unit can be looted |
| `2` | `0x2` | `UNIT_DYNFLAG_TRACK_UNIT` | Unit is tracked |
| `4` | `0x4` | `UNIT_DYNFLAG_TAPPED` | Lua UnitIsTapped |
| `8` | `0x8` | `UNIT_DYNFLAG_TAPPED_BY_PLAYER` | Tapped by player |
| `16` | `0x10` | `UNIT_DYNFLAG_SPECIALINFO` | Special info marker |
| `32` | `0x20` | `UNIT_DYNFLAG_DEAD` | Appears dead |

Used by: [`unit_flags`](#col-unit-flags)

#### `UnitFlags`

Kind: `mask`

Source: `src/game/Objects/UnitDefines.h enum UnitFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `UNIT_FLAG_UNK_0` | Movement checks disabled in several paths |
| `2` | `0x2` | `UNIT_FLAG_SPAWNING` | Not attackable while spawning |
| `4` | `0x4` | `UNIT_FLAG_DISABLE_MOVE` | Movement disabled |
| `8` | `0x8` | `UNIT_FLAG_PLAYER_CONTROLLED` | Controlled by player |
| `16` | `0x10` | `UNIT_FLAG_PET_RENAME` | Pet can be renamed |
| `32` | `0x20` | `UNIT_FLAG_PET_ABANDON` | Pet can be abandoned |
| `64` | `0x40` | `UNIT_FLAG_UNK_6` | Unknown |
| `256` | `0x100` | `UNIT_FLAG_IMMUNE_TO_PLAYER` | Immune to player attacks |
| `512` | `0x200` | `UNIT_FLAG_IMMUNE_TO_NPC` | Immune to NPC attacks |
| `4096` | `0x1000` | `UNIT_FLAG_PVP` | PvP flag |
| `8192` | `0x2000` | `UNIT_FLAG_SILENCED` | Silenced |
| `16384` | `0x4000` | `UNIT_FLAG_UNK_14` | Unknown |
| `32768` | `0x8000` | `UNIT_FLAG_USE_SWIM_ANIMATION` | Use swim animation |
| `65536` | `0x10000` | `UNIT_FLAG_NON_ATTACKABLE_2` | Secondary non-attackable flag |
| `131072` | `0x20000` | `UNIT_FLAG_PACIFIED` | Pacified |
| `262144` | `0x40000` | `UNIT_FLAG_STUNNED` | Stunned |
| `524288` | `0x80000` | `UNIT_FLAG_IN_COMBAT` | In combat |
| `1048576` | `0x100000` | `UNIT_FLAG_TAXI_FLIGHT` | Taxi flight |
| `4194304` | `0x400000` | `UNIT_FLAG_CONFUSED` | Confused |
| `8388608` | `0x800000` | `UNIT_FLAG_FLEEING` | Fleeing |
| `16777216` | `0x1000000` | `UNIT_FLAG_POSSESSED` | Possessed |
| `33554432` | `0x2000000` | `UNIT_FLAG_NOT_SELECTABLE` | Not selectable |
| `67108864` | `0x4000000` | `UNIT_FLAG_SKINNABLE` | Skinnable |
| `134217728` | `0x8000000` | `UNIT_FLAG_AURAS_VISIBLE` | Auras visible |
| `1073741824` | `0x40000000` | `UNIT_FLAG_SHEATHE` | Sheathe state |
| `2147483648` | `0x80000000` | `UNIT_FLAG_IMMUNE` | Immune |
