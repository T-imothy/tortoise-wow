---
layout: default
title: conditions
---

# conditions

Condition System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 7 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-condition-entry"></a>`condition_entry` | `mediumint(8) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | Identifier; non-negative numeric value |
| <a id="col-type"></a>`type` | `tinyint(4)` | NO |  | `0` |  | Type of the condition; numeric value; Uses ConditionType enum values; Condition behavior is type-dependent; see Table-Specific Details |
| <a id="col-value1"></a>`value1` | `int(11)` | NO |  | `0` |  | data field one for the condition; numeric value; Condition behavior is type-dependent; see Table-Specific Details |
| <a id="col-value2"></a>`value2` | `int(11)` | NO |  | `0` |  | data field two for the condition; numeric value; Condition behavior is type-dependent; see Table-Specific Details |
| <a id="col-value3"></a>`value3` | `int(11)` | NO |  | `0` |  | data field three for the condition; numeric value; Condition behavior is type-dependent; see Table-Specific Details |
| <a id="col-value4"></a>`value4` | `int(11)` | NO |  | `0` |  | data field four for the condition; numeric value; Condition behavior is type-dependent; see Table-Specific Details |
| <a id="col-flags"></a>`flags` | `tinyint(3) unsigned` | NO |  | `0` |  | general condition flags; non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses ConditionFlags mask values; Condition behavior is type-dependent; see Table-Specific Details |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `condition_entry`

non-negative numeric value.

### `type`

numeric value.

Value set: `ConditionType` (enum) from `src/game/Conditions.h enum ConditionType`.

### `value1`

numeric value.

### `value2`

numeric value.

### `value3`

numeric value.

### `value4`

numeric value.

### `flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `ConditionFlags` (mask) from `src/game/Conditions.h enum ConditionFlags`.

## Table-Specific Details

### Condition Type Matrix

The `conditions` table is type-driven: `type` selects the condition handler and changes the meanings of `value1` through `value4`. Negative types combine other condition ids. `flags` can invert the result or swap source and target before evaluation.

Common comparison mode used by multiple condition types: `0` means equal, `1` means equal or higher, and `2` means equal or lower. Empty value cells are unused unless the source column says the value is optional.

| Type | Name | Check | Requirement | value1 | value2 | value3 | value4 | Value Sources / Validation |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `-3` | `CONDITION_NOT` | Deprecated wrapper returning the opposite result of another condition. | None | condition_id |  |  |  | **value1**: conditions.condition_entry; must exist and be lower than this condition_entry&lt;br&gt;**value3**: If non-zero, optional condition id checked first; must be lower than this condition_entry&lt;br&gt;**value4**: If non-zero, optional condition id checked first; must be lower than this condition_entry |
| `-2` | `CONDITION_OR` | Returns true if any listed condition id is satisfied. | None | condition_id | condition_id | condition_id (optional) | condition_id (optional) | **value1**: conditions.condition_entry; must exist and be lower than this condition_entry&lt;br&gt;**value2**: conditions.condition_entry; must exist and be lower than this condition_entry&lt;br&gt;**value3**: Optional conditions.condition_entry; must be lower than this condition_entry&lt;br&gt;**value4**: Optional conditions.condition_entry; must be lower than this condition_entry |
| `-1` | `CONDITION_AND` | Returns true only if all listed condition ids are satisfied. | None | condition_id | condition_id | condition_id (optional) | condition_id (optional) | **value1**: conditions.condition_entry; must exist and be lower than this condition_entry&lt;br&gt;**value2**: conditions.condition_entry; must exist and be lower than this condition_entry&lt;br&gt;**value3**: Optional conditions.condition_entry; must be lower than this condition_entry&lt;br&gt;**value4**: Optional conditions.condition_entry; must be lower than this condition_entry |
| `0` | `CONDITION_NONE` | Always true; internal use. | None |  |  |  |  | No supplemental values are read by this condition type. |
| `1` | `CONDITION_AURA` | Target unit has an aura from the spell. | Unit Target | spell_id | effindex |  |  | **value1**: spell_template.entry / Spell.dbc spell id&lt;br&gt;**value2**: Spell effect index 0..2; negative value checks any effect index |
| `2` | `CONDITION_ITEM` | Player has an item in inventory. | Player Target | item_id | count |  |  | **value1**: item_template.entry&lt;br&gt;**value2**: Required item count; must be at least 1 |
| `3` | `CONDITION_ITEM_EQUIPPED` | Player has an item equipped. | Player Target | item_id |  |  |  | **value1**: item_template.entry |
| `4` | `CONDITION_AREAID` | Player is in a specific zone or area. | WorldObject Target or Source | area_id |  |  |  | **value1**: AreaEntry id from AreaTable.dbc; checked against both zone id and area id. Put the area/zone id in value1. |
| `5` | `CONDITION_REPUTATION_RANK_MIN` | Player reputation with a faction is at least the rank. | Player Target | faction_id | min_rank |  |  | **value1**: FactionEntry id from Faction.dbc / faction.entry&lt;br&gt;**value2**: ReputationRank enum; 0 hated through 7 exalted |
| `6` | `CONDITION_TEAM` | Player belongs to the specified team. | Player Target | player_team (469 Alliance, 67 Horde) |  |  |  | **value1**: Team id: 469 Alliance or 67 Horde |
| `7` | `CONDITION_SKILL` | Player skill is at least the value. | Player Target | skill_id | skill_value |  |  | **value1**: SkillLine.dbc skill id&lt;br&gt;**value2**: Required base skill value; 1..server max skill |
| `8` | `CONDITION_QUESTREWARDED` | Player has completed a quest. | Player Target | quest_id |  |  |  | **value1**: quest_template.entry |
| `9` | `CONDITION_QUESTTAKEN` | Player has accepted a quest. | Player Target | quest_id | active state mode (0 any, 1 incomplete, 2 completed) |  |  | **value1**: quest_template.entry&lt;br&gt;**value2**: Quest active-state mode: 0 any active state, 1 incomplete, 2 completed |
| `10` | `CONDITION_AD_COMMISSION_AURA` | Player has an Argent Dawn commission aura. | Player Target |  |  |  |  | No supplemental values are read by this condition type. |
| `11` | `CONDITION_WAR_EFFORT_STAGE` | War Effort event stage matches the comparison. | None | stage | compare op (0 ==, 1 &gt;=, 2 &lt;=) |  |  | **value1**: WarEffortEventStage enum from HardcodedEvents.h; valid 0..12&lt;br&gt;**value2**: Comparison mode: 0 ==, 1 &gt;=, 2 &lt;= |
| `12` | `CONDITION_ACTIVE_GAME_EVENT` | Game event is currently active. | None | event_id |  |  |  | **value1**: game_event.entry; must be a valid event id |
| `13` | `CONDITION_CANT_PATH_TO_VICTIM` | Source is chasing a victim but cannot path to it. | Unit Source |  |  |  |  | No supplemental values are read by this condition type. |
| `14` | `CONDITION_RACE_CLASS` | Player race and class match the masks. | Player Target | race_mask | class_mask |  |  | **value1**: RaceMask; zero means any race&lt;br&gt;**value2**: ClassMask; zero means any class |
| `15` | `CONDITION_LEVEL` | Target level matches the comparison. | Unit Target | level | compare op (0 ==, 1 &gt;=, 2 &lt;=) |  |  | **value1**: Target level; 1..configured max player level&lt;br&gt;**value2**: Comparison mode: 0 ==, 1 &gt;=, 2 &lt;= |
| `16` | `CONDITION_SOURCE_ENTRY` | Source entry id matches. | WorldObject Source | entry |  |  |  | **value1**: creature_template.entry or gameobject_template.entry for the source object |
| `17` | `CONDITION_SPELL` | Player has or does not have a learned spell. | Player Target | spell_id | mode (0 has spell, 1 has not spell) |  |  | **value1**: spell_template.entry / Spell.dbc spell id&lt;br&gt;**value2**: Mode: 0 target has spell, 1 target does not have spell |
| `18` | `CONDITION_INSTANCE_SCRIPT` | Instance script-specific condition passes. | Map | map_id | instance_condition_id |  |  | **value1**: Map id used to select/check instance script context&lt;br&gt;**value2**: Instance-script-specific condition id passed to InstanceData::CheckConditionCriteriaMeet |
| `19` | `CONDITION_QUESTAVAILABLE` | Player can accept a quest. | Player Target | quest_id |  |  |  | **value1**: quest_template.entry |
| `20` | `CONDITION_NEARBY_CREATURE` | Creature with the entry is nearby. | WorldObject Target | creature_id | search_radius | dead | not_self | **value1**: creature_template.entry&lt;br&gt;**value2**: Search radius in yards; zero is logged as suspect&lt;br&gt;**value3**: Dead mode passed as !value3: 0 searches alive, non-zero searches dead&lt;br&gt;**value4**: If non-zero, excludes the target creature itself |
| `21` | `CONDITION_NEARBY_GAMEOBJECT` | Gameobject with the entry is nearby. | WorldObject Target | gobject_id | search_radius |  |  | **value1**: gameobject_template.entry&lt;br&gt;**value2**: Search radius in yards; zero is logged as suspect |
| `22` | `CONDITION_QUEST_NONE` | Player has not taken and has not been rewarded for the quest. | Player Target | quest_id |  |  |  | **value1**: quest_template.entry |
| `23` | `CONDITION_ITEM_WITH_BANK` | Player has the item in inventory or bank. | Player Target | item_id | count |  |  | **value1**: item_template.entry&lt;br&gt;**value2**: Required item count; must be at least 1 |
| `24` | `CONDITION_CONTENT_PHASE` | Content patch/progression phase matches the comparison. | None | patch (0-3) | compare op (0 ==, 1 &gt;=, 2 &lt;=) |  |  | **value1**: Content phase / patch index, documented as 0..3&lt;br&gt;**value2**: Comparison mode: 0 ==, 1 &gt;=, 2 &lt;= |
| `25` | `CONDITION_ESCORT` | Checks escort alive state and distance. | None; optionally Creature Source and Player Target | flags (eEscortConditionFlags) | distance (optional) |  |  | **value1**: eEscortConditionFlags mask: 0x1 source dead, 0x2 target dead&lt;br&gt;**value2**: Optional distance in yards between source creature and target player |
| `26` | `CONDITION_ACTIVE_HOLIDAY` | Holiday is active; active game event is preferred. | None | holiday_id |  |  |  | **value1**: HolidayIds enum / Holidays.dbc id |
| `27` | `CONDITION_GENDER` | Target gender matches. | WorldObject Target | gender (0 male, 1 female, 2 none) |  |  |  | **value1**: Gender enum; valid here is 0 male or 1 female. Loader rejects 2/GENDER_NONE and higher. |
| `28` | `CONDITION_IS_PLAYER` | Target is a player or belongs to a player. | WorldObject Target | mode (0 player only, 1 player-owned too) |  |  |  | **value1**: Mode: 0 target must be player, 1 may be player-owned unit |
| `29` | `CONDITION_SKILL_BELOW` | Player knows skill and skill is below value; with value 1, true if player lacks skill. | Player Target | skill_id | skill_value |  |  | **value1**: SkillLine.dbc skill id&lt;br&gt;**value2**: Skill threshold; if value2 is 1, condition is true when player does not know the skill |
| `30` | `CONDITION_REPUTATION_RANK_MAX` | Player reputation with a faction is at most the rank. | Player Target | faction_id | max_rank |  |  | **value1**: FactionEntry id from Faction.dbc / faction.entry&lt;br&gt;**value2**: ReputationRank enum; 0 hated through 7 exalted |
| `31` | `CONDITION_HAS_FLAG` | Source has a specific update-field flag set. | WorldObject Source | field_id (UpdateFields.h) | flag |  |  | **value1**: Update field index from UpdateFields.h; adjusted for client build by GetIndexOfUpdateFieldForCurrentBuild&lt;br&gt;**value2**: Bit flag/mask tested with source-&gt;HasFlag(value1, value2) |
| `32` | `CONDITION_LAST_WAYPOINT` | Source creature's last reached waypoint matches the comparison. | Creature Source | waypointId | compare op (0 ==, 1 &gt;=, 2 &lt;=) |  |  | **value1**: Waypoint id from the source creature motion state&lt;br&gt;**value2**: Comparison mode: 0 ==, 1 &gt;=, 2 &lt;= |
| `33` | `CONDITION_MAP_ID` | Current map id matches. | Map | map_id |  |  |  | **value1**: Map.dbc id / map_template.entry |
| `34` | `CONDITION_INSTANCE_DATA` | Instance script data value matches the comparison. | Map | index | data | compare op (0 ==, 1 &gt;=, 2 &lt;=) |  | **value1**: Instance script data index passed to InstanceData::GetData&lt;br&gt;**value2**: Expected script data value&lt;br&gt;**value3**: Comparison mode: 0 ==, 1 &gt;=, 2 &lt;= |
| `35` | `CONDITION_MAP_EVENT_DATA` | Scripted map event data value matches the comparison. | Map | event_id | index | data | compare op (0 ==, 1 &gt;=, 2 &lt;=) | **value1**: Scripted map event id&lt;br&gt;**value2**: Scripted map event data index&lt;br&gt;**value3**: Expected event data value&lt;br&gt;**value4**: Comparison mode: 0 ==, 1 &gt;=, 2 &lt;= |
| `36` | `CONDITION_MAP_EVENT_ACTIVE` | Scripted map event is active. | Map | event_id |  |  |  | **value1**: Scripted map event id on the current map |
| `37` | `CONDITION_LINE_OF_SIGHT` | Source and target are in line of sight. | WorldObject Source and WorldObject Target |  |  |  |  | No supplemental values are read by this condition type. |
| `38` | `CONDITION_DISTANCE` | Distance between source and target matches the comparison. | WorldObject Source and WorldObject Target | distance | compare op (0 ==, 1 &gt;=, 2 &lt;=) |  |  | **value1**: Distance in yards between source and target&lt;br&gt;**value2**: Comparison mode: 0 ==, 1 &gt;=, 2 &lt;= |
| `39` | `CONDITION_IS_MOVING` | Target is currently moving. | WorldObject Target |  |  |  |  | No supplemental values are read by this condition type. |
| `40` | `CONDITION_HAS_PET` | Target has a pet. | Unit Target |  |  |  |  | No supplemental values are read by this condition type. |
| `41` | `CONDITION_HEALTH_PERCENT` | Target health percent matches the comparison. | Unit Target | hp_percent | compare op (0 ==, 1 &gt;=, 2 &lt;=) |  |  | **value1**: Health percent; valid 1..100&lt;br&gt;**value2**: Comparison mode: 0 ==, 1 &gt;=, 2 &lt;= |
| `42` | `CONDITION_MANA_PERCENT` | Target mana percent matches the comparison. | Unit Target | mana_percent | compare op (0 ==, 1 &gt;=, 2 &lt;=) |  |  | **value1**: Mana percent; valid 1..100&lt;br&gt;**value2**: Comparison mode: 0 ==, 1 &gt;=, 2 &lt;= |
| `43` | `CONDITION_IS_IN_COMBAT` | Target is currently in combat. | Unit Target |  |  |  |  | No supplemental values are read by this condition type. |
| `44` | `CONDITION_IS_HOSTILE_TO` | Target is hostile to source. | WorldObject Source and WorldObject Target |  |  |  |  | No supplemental values are read by this condition type. |
| `45` | `CONDITION_IS_IN_GROUP` | Player is in a group. | Player Target |  |  |  |  | No supplemental values are read by this condition type. |
| `46` | `CONDITION_IS_ALIVE` | Target is alive. | Unit Target |  |  |  |  | No supplemental values are read by this condition type. |
| `47` | `CONDITION_MAP_EVENT_TARGETS` | All extra targets for a scripted map event satisfy a condition id. | Map | event_id | condition_id |  |  | **value1**: Scripted map event id&lt;br&gt;**value2**: conditions.condition_entry applied to every extra event target |
| `48` | `CONDITION_OBJECT_IS_SPAWNED` | GameObject is currently spawned. | GameObject Target |  |  |  |  | No supplemental values are read by this condition type. |
| `49` | `CONDITION_OBJECT_LOOT_STATE` | GameObject loot state matches. | GameObject Target | loot_state (LootState) |  |  |  | **value1**: LootState enum from GameObject.h; valid 0..GO_JUST_DEACTIVATED |
| `50` | `CONDITION_OBJECT_FIT_CONDITION` | GameObject guid exists and satisfies a condition id. | Map | guid | condition_id |  |  | **value1**: gameobject.guid; server resolves to gameobject id plus ObjectGuid&lt;br&gt;**value2**: conditions.condition_entry evaluated against that gameobject |
| `51` | `CONDITION_PVP_RANK` | Player honor rank matches the comparison. | Player Target | rank | compare op (0 ==, 1 &gt;=, 2 &lt;=) |  |  | **value1**: Player honor visual rank; valid 0..14&lt;br&gt;**value2**: Comparison mode: 0 ==, 1 &gt;=, 2 &lt;= |
| `52` | `CONDITION_DB_GUID` | Source object's database guid is one of the listed guids. | WorldObject Source | guid | guid (optional) | guid (optional) | guid (optional) | **value1**: creature.guid or gameobject.guid for source object&lt;br&gt;**value2**: Optional additional creature.guid/gameobject.guid&lt;br&gt;**value3**: Optional additional creature.guid/gameobject.guid&lt;br&gt;**value4**: Optional additional creature.guid/gameobject.guid |
| `53` | `CONDITION_LOCAL_TIME` | Current local time is inside a range. | None | start_hour | start_minutes | end_hour | end_minutes | **value1**: Start hour, 0..23&lt;br&gt;**value2**: Start minute, 0..59&lt;br&gt;**value3**: End hour, 0..23&lt;br&gt;**value4**: End minute, 0..59 |
| `54` | `CONDITION_DISTANCE_TO_POSITION` | Target is within distance of coordinates. | WorldObject Target | x | y | z | distance | **value1**: World X coordinate&lt;br&gt;**value2**: World Y coordinate&lt;br&gt;**value3**: World Z coordinate&lt;br&gt;**value4**: Maximum distance in yards; must be greater than 0 |
| `55` | `CONDITION_OBJECT_GO_STATE` | GameObject state matches. | GameObject Target | go_state (GOState) |  |  |  | **value1**: GOState enum from GameObject.h; valid 0..GO_STATE_ACTIVE_ALTERNATIVE |
| `56` | `CONDITION_NEARBY_PLAYER` | Player matching relation mode is nearby. | Unit Target | mode (0 any, 1 hostile, 2 friendly) | search_radius |  |  | **value1**: Mode: 0 any player, 1 hostile player, 2 friendly player&lt;br&gt;**value2**: Search radius in yards; must be greater than 0 |
| `57` | `CONDITION_CREATURE_GROUP_MEMBER` | Creature is part of a group. | Creature Source | leader_guid (optional) |  |  |  | **value1**: Optional creature.guid of original group leader; zero allows any leader |
| `58` | `CONDITION_CREATURE_GROUP_DEAD` | Creature's group is dead. | Creature Source |  |  |  |  | No supplemental values are read by this condition type. |
| `59` | `CONDITION_BG_EVENT_ACTIVE` | Battleground event is active. | Map | event1 | event2 |  |  | **value1**: Battleground event1 id; must be less than 255&lt;br&gt;**value2**: Battleground event2 id; must be less than 255 |
| `60` | `CONDITION_STAND_STATE` | Target unit stand state matches. | Unit Target | stand_state |  |  |  | **value1**: UnitStandStateType enum; valid 0..8 |

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `condition_entry` |
| UNIQUE | `unique_conditions` | `type`, `value1`, `value2`, `flags`, `value3`, `value4` |

## Related Tables

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`quest_template`](quest_template.md).`RequiredCondition` | `condition_entry` | heuristic | inferred from column name |
| [`spell_script_target`](spell_script_target.md).`conditionId` | `condition_entry` | heuristic | inferred from column name |
| [`creature_ai_events`](creature_ai_events.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`creature_ai_scripts`](creature_ai_scripts.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`creature_loot_template`](creature_loot_template.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`creature_movement_scripts`](creature_movement_scripts.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`creature_spells_scripts`](creature_spells_scripts.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`custom_merchant`](custom_merchant.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`disenchant_loot_template`](disenchant_loot_template.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`event_scripts`](event_scripts.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`fishing_loot_template`](fishing_loot_template.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`gameobject_loot_template`](gameobject_loot_template.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`gameobject_scripts`](gameobject_scripts.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`generic_scripts`](generic_scripts.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`gossip_menu`](gossip_menu.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`gossip_menu_option`](gossip_menu_option.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`gossip_scripts`](gossip_scripts.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`item_loot_template`](item_loot_template.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`mail_loot_template`](mail_loot_template.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`npc_vendor`](npc_vendor.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`npc_vendor_template`](npc_vendor_template.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`pickpocketing_loot_template`](pickpocketing_loot_template.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`quest_end_scripts`](quest_end_scripts.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`quest_start_scripts`](quest_start_scripts.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`reference_loot_template`](reference_loot_template.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`skinning_loot_template`](skinning_loot_template.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |
| [`spell_scripts`](spell_scripts.md).`condition_id` | `condition_entry` | heuristic | inferred from column name |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `ConditionFlags` | mask | [`flags`](#col-flags) | `src/game/Conditions.h enum ConditionFlags` | 2 |
| `ConditionType` | enum | [`type`](#col-type) | `src/game/Conditions.h enum ConditionType` | 64 |

### Possible Values

Used by: [`flags`](#col-flags)

#### `ConditionFlags`

Kind: `mask`

Source: `src/game/Conditions.h enum ConditionFlags`

Flags may be combined. These modify how the condition is evaluated, not what type-specific values mean.

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `CONDITION_FLAG_REVERSE_RESULT` | Invert the condition result after evaluation. |
| `2` | `0x2` | `CONDITION_FLAG_SWAP_TARGETS` | Swap source and target before evaluating the condition. |

Used by: [`type`](#col-type)

#### `ConditionType`

Kind: `enum`

Source: `src/game/Conditions.h enum ConditionType`

The meanings of value1 through value4 depend on the selected condition type. See the table-specific condition matrix.

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `-3` | `-0x3` | `CONDITION_NOT` | Deprecated wrapper returning the opposite result of another condition. |
| `-2` | `-0x2` | `CONDITION_OR` | Returns true if any listed condition id is satisfied. |
| `-1` | `-0x1` | `CONDITION_AND` | Returns true only if all listed condition ids are satisfied. |
| `0` | `0x0` | `CONDITION_NONE` | Always true; internal use. |
| `1` | `0x1` | `CONDITION_AURA` | Target unit has an aura from the spell. |
| `2` | `0x2` | `CONDITION_ITEM` | Player has an item in inventory. |
| `3` | `0x3` | `CONDITION_ITEM_EQUIPPED` | Player has an item equipped. |
| `4` | `0x4` | `CONDITION_AREAID` | Player is in a specific zone or area. |
| `5` | `0x5` | `CONDITION_REPUTATION_RANK_MIN` | Player reputation with a faction is at least the rank. |
| `6` | `0x6` | `CONDITION_TEAM` | Player belongs to the specified team. |
| `7` | `0x7` | `CONDITION_SKILL` | Player skill is at least the value. |
| `8` | `0x8` | `CONDITION_QUESTREWARDED` | Player has completed a quest. |
| `9` | `0x9` | `CONDITION_QUESTTAKEN` | Player has accepted a quest. |
| `10` | `0xA` | `CONDITION_AD_COMMISSION_AURA` | Player has an Argent Dawn commission aura. |
| `11` | `0xB` | `CONDITION_WAR_EFFORT_STAGE` | War Effort event stage matches the comparison. |
| `12` | `0xC` | `CONDITION_ACTIVE_GAME_EVENT` | Game event is currently active. |
| `13` | `0xD` | `CONDITION_CANT_PATH_TO_VICTIM` | Source is chasing a victim but cannot path to it. |
| `14` | `0xE` | `CONDITION_RACE_CLASS` | Player race and class match the masks. |
| `15` | `0xF` | `CONDITION_LEVEL` | Target level matches the comparison. |
| `16` | `0x10` | `CONDITION_SOURCE_ENTRY` | Source entry id matches. |
| `17` | `0x11` | `CONDITION_SPELL` | Player has or does not have a learned spell. |
| `18` | `0x12` | `CONDITION_INSTANCE_SCRIPT` | Instance script-specific condition passes. |
| `19` | `0x13` | `CONDITION_QUESTAVAILABLE` | Player can accept a quest. |
| `20` | `0x14` | `CONDITION_NEARBY_CREATURE` | Creature with the entry is nearby. |
| `21` | `0x15` | `CONDITION_NEARBY_GAMEOBJECT` | Gameobject with the entry is nearby. |
| `22` | `0x16` | `CONDITION_QUEST_NONE` | Player has not taken and has not been rewarded for the quest. |
| `23` | `0x17` | `CONDITION_ITEM_WITH_BANK` | Player has the item in inventory or bank. |
| `24` | `0x18` | `CONDITION_CONTENT_PHASE` | Content patch/progression phase matches the comparison. |
| `25` | `0x19` | `CONDITION_ESCORT` | Checks escort alive state and distance. |
| `26` | `0x1A` | `CONDITION_ACTIVE_HOLIDAY` | Holiday is active; active game event is preferred. |
| `27` | `0x1B` | `CONDITION_GENDER` | Target gender matches. |
| `28` | `0x1C` | `CONDITION_IS_PLAYER` | Target is a player or belongs to a player. |
| `29` | `0x1D` | `CONDITION_SKILL_BELOW` | Player knows skill and skill is below value; with value 1, true if player lacks skill. |
| `30` | `0x1E` | `CONDITION_REPUTATION_RANK_MAX` | Player reputation with a faction is at most the rank. |
| `31` | `0x1F` | `CONDITION_HAS_FLAG` | Source has a specific update-field flag set. |
| `32` | `0x20` | `CONDITION_LAST_WAYPOINT` | Source creature's last reached waypoint matches the comparison. |
| `33` | `0x21` | `CONDITION_MAP_ID` | Current map id matches. |
| `34` | `0x22` | `CONDITION_INSTANCE_DATA` | Instance script data value matches the comparison. |
| `35` | `0x23` | `CONDITION_MAP_EVENT_DATA` | Scripted map event data value matches the comparison. |
| `36` | `0x24` | `CONDITION_MAP_EVENT_ACTIVE` | Scripted map event is active. |
| `37` | `0x25` | `CONDITION_LINE_OF_SIGHT` | Source and target are in line of sight. |
| `38` | `0x26` | `CONDITION_DISTANCE` | Distance between source and target matches the comparison. |
| `39` | `0x27` | `CONDITION_IS_MOVING` | Target is currently moving. |
| `40` | `0x28` | `CONDITION_HAS_PET` | Target has a pet. |
| `41` | `0x29` | `CONDITION_HEALTH_PERCENT` | Target health percent matches the comparison. |
| `42` | `0x2A` | `CONDITION_MANA_PERCENT` | Target mana percent matches the comparison. |
| `43` | `0x2B` | `CONDITION_IS_IN_COMBAT` | Target is currently in combat. |
| `44` | `0x2C` | `CONDITION_IS_HOSTILE_TO` | Target is hostile to source. |
| `45` | `0x2D` | `CONDITION_IS_IN_GROUP` | Player is in a group. |
| `46` | `0x2E` | `CONDITION_IS_ALIVE` | Target is alive. |
| `47` | `0x2F` | `CONDITION_MAP_EVENT_TARGETS` | All extra targets for a scripted map event satisfy a condition id. |
| `48` | `0x30` | `CONDITION_OBJECT_IS_SPAWNED` | GameObject is currently spawned. |
| `49` | `0x31` | `CONDITION_OBJECT_LOOT_STATE` | GameObject loot state matches. |
| `50` | `0x32` | `CONDITION_OBJECT_FIT_CONDITION` | GameObject guid exists and satisfies a condition id. |
| `51` | `0x33` | `CONDITION_PVP_RANK` | Player honor rank matches the comparison. |
| `52` | `0x34` | `CONDITION_DB_GUID` | Source object's database guid is one of the listed guids. |
| `53` | `0x35` | `CONDITION_LOCAL_TIME` | Current local time is inside a range. |
| `54` | `0x36` | `CONDITION_DISTANCE_TO_POSITION` | Target is within distance of coordinates. |
| `55` | `0x37` | `CONDITION_OBJECT_GO_STATE` | GameObject state matches. |
| `56` | `0x38` | `CONDITION_NEARBY_PLAYER` | Player matching relation mode is nearby. |
| `57` | `0x39` | `CONDITION_CREATURE_GROUP_MEMBER` | Creature is part of a group. |
| `58` | `0x3A` | `CONDITION_CREATURE_GROUP_DEAD` | Creature's group is dead. |
| `59` | `0x3B` | `CONDITION_BG_EVENT_ACTIVE` | Battleground event is active. |
| `60` | `0x3C` | `CONDITION_STAND_STATE` | Target unit stand state matches. |
