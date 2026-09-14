---
layout: default
title: creature_ai_events
---

# creature_ai_events

EventAI Scripts

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 15 | utf8mb3 | FIXED |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | Identifier; non-negative numeric value; identifier column |
| <a id="col-creature-id"></a>`creature_id` | `int(10) unsigned` | NO |  | `0` |  | Creature Template Identifier; non-negative numeric value |
| <a id="col-condition-id"></a>`condition_id` | `mediumint(8) unsigned` | NO |  | `0` |  | Condition id from conditions table; non-negative numeric value |
| <a id="col-event-type"></a>`event_type` | `tinyint(3) unsigned` | NO |  | `0` |  | Event Type; non-negative numeric value; Uses EventAIType enum values |
| <a id="col-event-inverse-phase-mask"></a>`event_inverse_phase_mask` | `int(11)` | NO |  | `0` |  | Mask which phases this event will not trigger in; numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-event-chance"></a>`event_chance` | `int(10) unsigned` | NO |  | `100` |  | non-negative numeric value |
| <a id="col-event-flags"></a>`event_flags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses EventFlags mask values |
| <a id="col-event-param1"></a>`event_param1` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-event-param2"></a>`event_param2` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-event-param3"></a>`event_param3` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-event-param4"></a>`event_param4` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-action1-script"></a>`action1_script` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; script id or script name |
| <a id="col-action2-script"></a>`action2_script` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; script id or script name |
| <a id="col-action3-script"></a>`action3_script` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; script id or script name |
| <a id="col-comment"></a>`comment` | `varchar(255)` | NO |  | `''` |  | Event Comment; text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `creature_id`

non-negative numeric value.

References: [`creature`](creature.md).`entry`, [`creature_template`](creature_template.md).`entry`.

### `condition_id`

non-negative numeric value.

References: [`conditions`](conditions.md).`condition_entry`.

### `event_type`

non-negative numeric value.

Value set: `EventAIType` (enum) from `src/game/AI/CreatureEventAI.h enum EventAI_Type`.

### `event_inverse_phase_mask`

numeric value; mask/flags column; combine values with bitwise OR.

### `event_chance`

non-negative numeric value.

### `event_flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `EventFlags` (mask) from `src/game/AI/CreatureEventAI.h enum EventFlags`.

### `event_param1`

numeric value.

### `event_param2`

numeric value.

### `event_param3`

numeric value.

### `event_param4`

numeric value.

### `action1_script`

non-negative numeric value; script id or script name.

### `action2_script`

non-negative numeric value; script id or script name.

### `action3_script`

non-negative numeric value; script id or script name.

### `comment`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `id` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `condition_id` | [`conditions`](conditions.md).`condition_entry` | heuristic | inferred from column name |
| `creature_id` | [`creature`](creature.md).`entry` | heuristic | inferred from column name |
| `creature_id` | [`creature_template`](creature_template.md).`entry` | heuristic | inferred from column name |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `EventAIType` | enum | [`event_type`](#col-event-type) | `src/game/AI/CreatureEventAI.h enum EventAI_Type` | 36 |
| `EventFlags` | mask | [`event_flags`](#col-event-flags) | `src/game/AI/CreatureEventAI.h enum EventFlags` | 5 |

### Possible Values

Used by: [`event_type`](#col-event-type)

#### `EventAIType`

Kind: `enum`

Source: `src/game/AI/CreatureEventAI.h enum EventAI_Type`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `EVENT_T_TIMER_IN_COMBAT` | InitialMin, InitialMax, RepeatMin, RepeatMax |
| `1` | `0x1` | `EVENT_T_TIMER_OOC` | InitialMin, InitialMax, RepeatMin, RepeatMax |
| `2` | `0x2` | `EVENT_T_HP` | HPMax%, HPMin%, RepeatMin, RepeatMax |
| `3` | `0x3` | `EVENT_T_MANA` | ManaMax%,ManaMin% RepeatMin, RepeatMax |
| `4` | `0x4` | `EVENT_T_AGGRO` | NONE |
| `5` | `0x5` | `EVENT_T_KILL` | RepeatMin, RepeatMax, PlayerOnly |
| `6` | `0x6` | `EVENT_T_DEATH` | NONE |
| `7` | `0x7` | `EVENT_T_EVADE` | NONE |
| `8` | `0x8` | `EVENT_T_HIT_BY_SPELL` | SpellID, School, RepeatMin, RepeatMax |
| `9` | `0x9` | `EVENT_T_RANGE` | MinDist, MaxDist, RepeatMin, RepeatMax |
| `10` | `0xA` | `EVENT_T_OOC_LOS` | Reaction, MaxRnage, RepeatMin, RepeatMax |
| `11` | `0xB` | `EVENT_T_SPAWNED` | NONE |
| `12` | `0xC` | `EVENT_T_TARGET_HP` | HPMax%, HPMin%, RepeatMin, RepeatMax |
| `13` | `0xD` | `EVENT_T_TARGET_CASTING` | RepeatMin, RepeatMax |
| `14` | `0xE` | `EVENT_T_FRIENDLY_HP` | HPDeficit, Radius, RepeatMin, RepeatMax |
| `15` | `0xF` | `EVENT_T_FRIENDLY_IS_CC` | DispelType, Radius, RepeatMin, RepeatMax |
| `16` | `0x10` | `EVENT_T_FRIENDLY_MISSING_BUFF` | SpellId, Radius, RepeatMin, RepeatMax |
| `17` | `0x11` | `EVENT_T_SUMMONED_UNIT` | CreatureId, RepeatMin, RepeatMax |
| `18` | `0x12` | `EVENT_T_TARGET_MANA` | ManaMax%, ManaMin%, RepeatMin, RepeatMax |
| `19` | `0x13` | `EVENT_T_QUEST_ACCEPT` | QuestID |
| `20` | `0x14` | `EVENT_T_QUEST_COMPLETE` | Event T Quest Complete |
| `21` | `0x15` | `EVENT_T_REACHED_HOME` | NONE |
| `22` | `0x16` | `EVENT_T_RECEIVE_EMOTE` | EmoteId, Condition, CondValue1, CondValue2 |
| `23` | `0x17` | `EVENT_T_AURA` | Param1 = SpellID, Param2 = Number of time stacked, Param3/4 Repeat Min/Max |
| `24` | `0x18` | `EVENT_T_TARGET_AURA` | Param1 = SpellID, Param2 = Number of time stacked, Param3/4 Repeat Min/Max |
| `25` | `0x19` | `EVENT_T_SUMMONED_JUST_DIED` | CreatureId, RepeatMin, RepeatMax |
| `26` | `0x1A` | `EVENT_T_SUMMONED_JUST_DESPAWN` | CreatureId, RepeatMin, RepeatMax |
| `27` | `0x1B` | `EVENT_T_MISSING_AURA` | Param1 = SpellID, Param2 = Number of time stacked expected, Param3/4 Repeat Min/Max |
| `28` | `0x1C` | `EVENT_T_TARGET_MISSING_AURA` | Param1 = SpellID, Param2 = Number of time stacked expected, Param3/4 Repeat Min/Max |
| `29` | `0x1D` | `EVENT_T_MOVEMENT_INFORM` | Param1 = motion type, Param2 = point ID, RepeatMin, RepeatMax |
| `30` | `0x1E` | `EVENT_T_LEAVE_COMBAT` | NONE |
| `31` | `0x1F` | `EVENT_T_SCRIPT` | Param1 = EventID, Param2 = Data |
| `32` | `0x20` | `EVENT_T_GROUP_MEMBER_DIED` | Param1 = CreatureId, Param2 = IsLeader |
| `33` | `0x21` | `EVENT_T_VICTIM_ROOTED` | RepeatMin, RepeatMax |
| `34` | `0x22` | `EVENT_T_HIT_BY_AURA` | AuraType, Unused, RepeatMin, RepeatMax |
| `35` | `0x23` | `EVENT_T_STEALTH_ALERT` | RepeatMin, RepeatMax |

Used by: [`event_flags`](#col-event-flags)

#### `EventFlags`

Kind: `mask`

Source: `src/game/AI/CreatureEventAI.h enum EventFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `EFLAG_REPEATABLE` | Event repeats |
| `2` | `0x2` | `EFLAG_RANDOM_ACTION` | Event only execute one from existed actions instead each action. |
| `4` | `0x4` | `EFLAG_NOT_CASTING` | Event will not occur while creature is casting a spell |
| `8` | `0x8` | `EFLAG_CHECK_RESULT` | Event will not go on cooldown if script actions fail |
| `16` | `0x10` | `EFLAG_DEBUG_ONLY` | Event only occurs in debug build |

### Unmapped Flag-Like Columns

| Column | Type | Guidance |
| --- | --- | --- |
| [`event_inverse_phase_mask`](#col-event-inverse-phase-mask) | `int(11)` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
