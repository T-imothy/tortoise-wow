---
layout: default
title: gameobject_scripts
---

# gameobject_scripts

World database table `gameobject_scripts`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 22 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; identifier column |
| <a id="col-delay"></a>`delay` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-priority"></a>`priority` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-command"></a>`command` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ScriptCommands enum values |
| <a id="col-datalong"></a>`datalong` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-datalong2"></a>`datalong2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-datalong3"></a>`datalong3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-datalong4"></a>`datalong4` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-target-param1"></a>`target_param1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-target-param2"></a>`target_param2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-target-type"></a>`target_type` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses ScriptTarget enum values |
| <a id="col-data-flags"></a>`data_flags` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses ScriptDataFlags mask values |
| <a id="col-dataint"></a>`dataint` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-dataint2"></a>`dataint2` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-dataint3"></a>`dataint3` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-dataint4"></a>`dataint4` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-x"></a>`x` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-y"></a>`y` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-z"></a>`z` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-o"></a>`o` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-condition-id"></a>`condition_id` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-comments"></a>`comments` | `varchar(255)` | NO |  |  |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `delay`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `priority`

non-negative numeric value.

### `command`

non-negative numeric value.

Value set: `ScriptCommands` (enum) from `src/game/Maps/ScriptCommands.cpp command handlers`.

### `datalong`

non-negative numeric value.

### `datalong2`

non-negative numeric value.

### `datalong3`

non-negative numeric value.

### `datalong4`

non-negative numeric value.

### `target_param1`

non-negative numeric value.


### `target_param2`

non-negative numeric value.


### `target_type`

non-negative numeric value.

Value set: `ScriptTarget` (enum) from `src/game/ScriptMgr.h enum ScriptTarget`.

### `data_flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `ScriptDataFlags` (mask) from `src/game/ScriptMgr.h general DB script flags`.

### `dataint`

numeric value.

### `dataint2`

numeric value.

### `dataint3`

numeric value.

### `dataint4`

numeric value.

### `x`

numeric value; world coordinate or orientation.

### `y`

numeric value; world coordinate or orientation.

### `z`

numeric value; world coordinate or orientation.

### `o`

numeric value; world coordinate or orientation.

### `condition_id`

non-negative numeric value.

References: [`conditions`](conditions.md).`condition_entry`.

### `comments`

text/string data.

## Table-Specific Details

### Script Target Parameter Notes

`target_param1` and `target_param2` are interpreted according to `target_type`, not as one global enum or mask. `ScriptMgr::CheckScriptTargets` validates the accepted shape: some target types require both params to be zero, hostile random target types use `target_param1` as a `SelectFlags` mask and leave `target_param2` unused, entry-based creature/gameobject target types use `target_param1` as the entry and `target_param2` as search radius, guid-based target types use `target_param1` as the guid, and several friendly/map-event target types use `target_param2` for a bool, percent, spell id, or entry.

Source: `src/game/ScriptMgr.cpp ScriptMgr::CheckScriptTargets`; `src/game/ScriptMgr.h enum ScriptTarget`; `src/game/Objects/Creature.h enum SelectFlags`.

### Script Command Parameter Notes

Script table parameter columns are command-dependent. A column such as `datalong` cannot be assigned one enum globally because each `command` changes the meaning of `datalong`, `datalong2`, `datalong3`, `datalong4`, and `dataint*`.

| Command | Name | Parameter Meaning | Reference |
| --- | --- | --- | --- |
| `1` | `SCRIPT_COMMAND_EMOTE` | `datalong`, `datalong2`, `datalong3`, and `datalong4` are Emotes.dbc ids. `dataint` is the targeted flag. | `Emote` |
| `28` | `SCRIPT_COMMAND_STAND_STATE` | `datalong` is a unit stand state. | `UnitStandStateType` |
| `51` | `SCRIPT_COMMAND_SET_SHEATH` | `datalong` is a sheath state. | `SheathState` |
| `80` | `SCRIPT_COMMAND_SET_GO_STATE` | `datalong` is a gameobject state. | `GOState` |

## Keys and Indexes

No keys were declared in the parsed CREATE TABLE statement.

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `condition_id` | [`conditions`](conditions.md).`condition_entry` | heuristic | inferred from column name |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `ScriptCommands` | enum | [`command`](#col-command) | `src/game/Maps/ScriptCommands.cpp command handlers` | 93 |
| `ScriptDataFlags` | mask | [`data_flags`](#col-data-flags) | `src/game/ScriptMgr.h general DB script flags` | 5 |
| `ScriptTarget` | enum | [`target_type`](#col-target-type) | `src/game/ScriptMgr.h enum ScriptTarget` | 28 |

### Possible Values

Used by: [`command`](#col-command)

#### `ScriptCommands`

Kind: `enum`

Source: `src/game/Maps/ScriptCommands.cpp command handlers`

Command values are derived from ScriptMgr.h and ScriptCommands.cpp comments for this server.

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `SCRIPT_COMMAND_TALK` | Send text |
| `1` | `0x1` | `SCRIPT_COMMAND_EMOTE` | Play emote |
| `2` | `0x2` | `SCRIPT_COMMAND_FIELD_SET` | Set object field |
| `3` | `0x3` | `SCRIPT_COMMAND_MOVE_TO` | Move creature |
| `4` | `0x4` | `SCRIPT_COMMAND_MODIFY_FLAGS` | Modify object flags |
| `5` | `0x5` | `SCRIPT_COMMAND_INTERRUPT_CASTS` | Interrupt casts |
| `6` | `0x6` | `SCRIPT_COMMAND_TELEPORT_TO` | Teleport unit |
| `7` | `0x7` | `SCRIPT_COMMAND_QUEST_EXPLORED` | Mark quest exploration/event |
| `8` | `0x8` | `SCRIPT_COMMAND_KILL_CREDIT` | Grant kill credit |
| `9` | `0x9` | `SCRIPT_COMMAND_RESPAWN_GAMEOBJECT` | Respawn gameobject |
| `10` | `0xA` | `SCRIPT_COMMAND_TEMP_SUMMON_CREATURE` | Temporarily summon creature |
| `11` | `0xB` | `SCRIPT_COMMAND_OPEN_DOOR` | Open door |
| `12` | `0xC` | `SCRIPT_COMMAND_CLOSE_DOOR` | Close door |
| `13` | `0xD` | `SCRIPT_COMMAND_ACTIVATE_OBJECT` | Activate gameobject |
| `14` | `0xE` | `SCRIPT_COMMAND_REMOVE_AURA` | Remove aura |
| `15` | `0xF` | `SCRIPT_COMMAND_CAST_SPELL` | Cast spell |
| `16` | `0x10` | `SCRIPT_COMMAND_PLAY_SOUND` | Play sound |
| `17` | `0x11` | `SCRIPT_COMMAND_CREATE_ITEM` | Create item |
| `18` | `0x12` | `SCRIPT_COMMAND_DESPAWN_CREATURE` | Despawn creature |
| `19` | `0x13` | `SCRIPT_COMMAND_SET_EQUIPMENT` | Set creature equipment |
| `20` | `0x14` | `SCRIPT_COMMAND_MOVEMENT` | Change movement |
| `21` | `0x15` | `SCRIPT_COMMAND_SET_ACTIVEOBJECT` | Set active object |
| `22` | `0x16` | `SCRIPT_COMMAND_SET_FACTION` | Set faction |
| `23` | `0x17` | `SCRIPT_COMMAND_MORPH_TO_ENTRY_OR_MODEL` | Morph to entry or model |
| `24` | `0x18` | `SCRIPT_COMMAND_MOUNT_TO_ENTRY_OR_MODEL` | Mount to entry or model |
| `25` | `0x19` | `SCRIPT_COMMAND_SET_RUN` | Set run/walk |
| `26` | `0x1A` | `SCRIPT_COMMAND_ATTACK_START` | Start attack |
| `27` | `0x1B` | `SCRIPT_COMMAND_UPDATE_ENTRY` | Update creature entry |
| `28` | `0x1C` | `SCRIPT_COMMAND_STAND_STATE` | Set stand state |
| `29` | `0x1D` | `SCRIPT_COMMAND_MODIFY_THREAT` | Modify threat |
| `30` | `0x1E` | `SCRIPT_COMMAND_SEND_TAXI_PATH` | Send taxi path |
| `31` | `0x1F` | `SCRIPT_COMMAND_TERMINATE_SCRIPT` | Terminate script |
| `32` | `0x20` | `SCRIPT_COMMAND_TERMINATE_CONDITION` | Terminate condition |
| `33` | `0x21` | `SCRIPT_COMMAND_ENTER_EVADE_MODE` | Enter evade mode |
| `34` | `0x22` | `SCRIPT_COMMAND_SET_HOME_POSITION` | Set home position |
| `35` | `0x23` | `SCRIPT_COMMAND_TURN_TO` | Turn to target or angle |
| `36` | `0x24` | `SCRIPT_COMMAND_MEETINGSTONE` | Meeting stone interaction |
| `37` | `0x25` | `SCRIPT_COMMAND_SET_INST_DATA` | Set instance data |
| `38` | `0x26` | `SCRIPT_COMMAND_SET_INST_DATA64` | Set 64-bit instance data |
| `39` | `0x27` | `SCRIPT_COMMAND_START_SCRIPT` | Start another script |
| `40` | `0x28` | `SCRIPT_COMMAND_REMOVE_ITEM` | Remove item |
| `41` | `0x29` | `SCRIPT_COMMAND_REMOVE_OBJECT` | Remove object |
| `42` | `0x2A` | `SCRIPT_COMMAND_SET_MELEE_ATTACK` | Toggle melee attack |
| `43` | `0x2B` | `SCRIPT_COMMAND_SET_COMBAT_MOVEMENT` | Toggle combat movement |
| `44` | `0x2C` | `SCRIPT_COMMAND_SET_PHASE` | Set phase |
| `45` | `0x2D` | `SCRIPT_COMMAND_SET_PHASE_RANDOM` | Set random phase |
| `46` | `0x2E` | `SCRIPT_COMMAND_SET_PHASE_RANGE` | Set random phase in range |
| `47` | `0x2F` | `SCRIPT_COMMAND_FLEE` | Start fleeing |
| `48` | `0x30` | `SCRIPT_COMMAND_DEAL_DAMAGE` | Deal damage |
| `49` | `0x31` | `SCRIPT_COMMAND_ZONE_COMBAT_PULSE` | Pulse zone combat |
| `50` | `0x32` | `SCRIPT_COMMAND_CALL_FOR_HELP` | Call nearby allies |
| `51` | `0x33` | `SCRIPT_COMMAND_SET_SHEATH` | Set sheath state |
| `52` | `0x34` | `SCRIPT_COMMAND_INVINCIBILITY` | Toggle invincibility |
| `53` | `0x35` | `SCRIPT_COMMAND_GAME_EVENT` | Start or stop game event |
| `54` | `0x36` | `SCRIPT_COMMAND_SET_SERVER_VARIABLE` | Set server variable |
| `55` | `0x37` | `SCRIPT_COMMAND_CREATURE_SPELLS` | Set creature spell list |
| `56` | `0x38` | `SCRIPT_COMMAND_REMOVE_GUARDIANS` | Remove guardians |
| `57` | `0x39` | `SCRIPT_COMMAND_ADD_SPELL_COOLDOWN` | Add spell cooldown |
| `58` | `0x3A` | `SCRIPT_COMMAND_REMOVE_SPELL_COOLDOWN` | Remove spell cooldown |
| `59` | `0x3B` | `SCRIPT_COMMAND_SET_REACT_STATE` | Set creature react state |
| `60` | `0x3C` | `SCRIPT_COMMAND_START_WAYPOINTS` | Start waypoint movement |
| `61` | `0x3D` | `SCRIPT_COMMAND_START_MAP_EVENT` | Start map event |
| `62` | `0x3E` | `SCRIPT_COMMAND_END_MAP_EVENT` | End map event |
| `63` | `0x3F` | `SCRIPT_COMMAND_ADD_MAP_EVENT_TARGET` | Add map event target |
| `64` | `0x40` | `SCRIPT_COMMAND_REMOVE_MAP_EVENT_TARGET` | Remove map event target |
| `65` | `0x41` | `SCRIPT_COMMAND_SET_MAP_EVENT_DATA` | Set map event data |
| `66` | `0x42` | `SCRIPT_COMMAND_SEND_MAP_EVENT` | Send map event |
| `67` | `0x43` | `SCRIPT_COMMAND_SET_DEFAULT_MOVEMENT` | Set default movement |
| `68` | `0x44` | `SCRIPT_COMMAND_START_SCRIPT_FOR_ALL` | Start script for all matching players |
| `69` | `0x45` | `SCRIPT_COMMAND_EDIT_MAP_EVENT` | Edit map event |
| `70` | `0x46` | `SCRIPT_COMMAND_FAIL_QUEST` | Fail quest |
| `71` | `0x47` | `SCRIPT_COMMAND_RESPAWN_CREATURE` | Respawn creature |
| `72` | `0x48` | `SCRIPT_COMMAND_ASSIST_UNIT` | Assist unit |
| `73` | `0x49` | `SCRIPT_COMMAND_COMBAT_STOP` | Stop combat |
| `74` | `0x4A` | `SCRIPT_COMMAND_ADD_AURA` | Add aura |
| `75` | `0x4B` | `SCRIPT_COMMAND_ADD_THREAT` | Add threat |
| `76` | `0x4C` | `SCRIPT_COMMAND_SUMMON_OBJECT` | Summon gameobject |
| `77` | `0x4D` | `SCRIPT_COMMAND_SET_FLY` | Toggle flight |
| `78` | `0x4E` | `SCRIPT_COMMAND_JOIN_CREATURE_GROUP` | Join creature group |
| `79` | `0x4F` | `SCRIPT_COMMAND_LEAVE_CREATURE_GROUP` | Leave creature group |
| `80` | `0x50` | `SCRIPT_COMMAND_SET_GO_STATE` | Set gameobject state |
| `81` | `0x51` | `SCRIPT_COMMAND_DESPAWN_GAMEOBJECT` | Despawn gameobject |
| `82` | `0x52` | `SCRIPT_COMMAND_LOAD_GAMEOBJECT_SPAWN` | Load gameobject spawn |
| `83` | `0x53` | `SCRIPT_COMMAND_QUEST_CREDIT` | Grant quest credit |
| `84` | `0x54` | `SCRIPT_COMMAND_SET_GOSSIP_MENU` | Set gossip menu |
| `85` | `0x55` | `SCRIPT_COMMAND_SEND_SCRIPT_EVENT` | Send script event |
| `86` | `0x56` | `SCRIPT_COMMAND_SET_PVP` | Set PvP state |
| `87` | `0x57` | `SCRIPT_COMMAND_RESET_DOOR_OR_BUTTON` | Reset door or button |
| `88` | `0x58` | `SCRIPT_COMMAND_SET_COMMAND_STATE` | Set command state |
| `89` | `0x59` | `SCRIPT_COMMAND_PLAY_CUSTOM_ANIM` | Play custom animation |
| `90` | `0x5A` | `SCRIPT_COMMAND_START_SCRIPT_ON_GROUP` | Start script on group |
| `91` | `0x5B` | `SCRIPT_COMMAND_LOAD_CREATURE_SPAWN` | Load creature spawn |
| `92` | `0x5C` | `SCRIPT_COMMAND_START_SCRIPT_ON_ZONE` | Start script on zone |

Used by: [`data_flags`](#col-data-flags)

#### `ScriptDataFlags`

Kind: `mask`

Source: `src/game/ScriptMgr.h general DB script flags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `SF_GENERAL_SWAP_INITIAL_TARGETS` | Swap provided source and target before buddy lookup |
| `2` | `0x2` | `SF_GENERAL_SWAP_FINAL_TARGETS` | Swap local source and target after buddy assignment |
| `4` | `0x4` | `SF_GENERAL_TARGET_SELF` | Replace provided target with provided source |
| `8` | `0x8` | `SF_GENERAL_ABORT_ON_FAILURE` | Terminate script if command fails |
| `16` | `0x10` | `SF_GENERAL_SKIP_MISSING_TARGETS` | Skip command if source or target is missing |

Used by: [`target_type`](#col-target-type)

#### `ScriptTarget`

Kind: `enum`

Source: `src/game/ScriptMgr.h enum ScriptTarget`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `TARGET_T_PROVIDED_TARGET` | Use the provided target |
| `1` | `0x1` | `TARGET_T_HOSTILE` | Current hostile target |
| `2` | `0x2` | `TARGET_T_HOSTILE_SECOND_AGGRO` | Second unit on threat list |
| `3` | `0x3` | `TARGET_T_HOSTILE_LAST_AGGRO` | Last unit on threat list |
| `4` | `0x4` | `TARGET_T_HOSTILE_RANDOM` | Random hostile target |
| `5` | `0x5` | `TARGET_T_HOSTILE_RANDOM_NOT_TOP` | Random hostile target excluding top threat |
| `6` | `0x6` | `TARGET_T_OWNER_OR_SELF` | Owner if present, otherwise self |
| `7` | `0x7` | `TARGET_T_OWNER` | Owner |
| `8` | `0x8` | `TARGET_T_NEAREST_CREATURE_WITH_ENTRY` | Nearest creature matching entry |
| `9` | `0x9` | `TARGET_T_CREATURE_WITH_GUID` | Creature matching guid |
| `10` | `0xA` | `TARGET_T_CREATURE_FROM_INSTANCE_DATA` | Creature guid from instance data |
| `11` | `0xB` | `TARGET_T_NEAREST_GAMEOBJECT_WITH_ENTRY` | Nearest gameobject matching entry |
| `12` | `0xC` | `TARGET_T_GAMEOBJECT_WITH_GUID` | Gameobject matching guid |
| `13` | `0xD` | `TARGET_T_GAMEOBJECT_FROM_INSTANCE_DATA` | Gameobject guid from instance data |
| `14` | `0xE` | `TARGET_T_FRIENDLY` | Friendly unit |
| `15` | `0xF` | `TARGET_T_FRIENDLY_INJURED` | Injured friendly unit |
| `16` | `0x10` | `TARGET_T_FRIENDLY_INJURED_EXCEPT` | Injured friendly unit excluding a condition |
| `17` | `0x11` | `TARGET_T_FRIENDLY_MISSING_BUFF` | Friendly unit missing buff |
| `18` | `0x12` | `TARGET_T_FRIENDLY_MISSING_BUFF_EXCEPT` | Friendly unit missing buff excluding a condition |
| `19` | `0x13` | `TARGET_T_FRIENDLY_CC` | Friendly crowd-controlled unit |
| `20` | `0x14` | `TARGET_T_MAP_EVENT_SOURCE` | Map event source |
| `21` | `0x15` | `TARGET_T_MAP_EVENT_TARGET` | Map event target |
| `22` | `0x16` | `TARGET_T_MAP_EVENT_EXTRA_TARGET` | Map event extra target |
| `23` | `0x17` | `TARGET_T_NEAREST_PLAYER` | Nearest player |
| `24` | `0x18` | `TARGET_T_NEAREST_HOSTILE_PLAYER` | Nearest hostile player |
| `25` | `0x19` | `TARGET_T_NEAREST_FRIENDLY_PLAYER` | Nearest friendly player |
| `26` | `0x1A` | `TARGET_T_RANDOM_CREATURE_WITH_ENTRY` | Random creature matching entry |
| `27` | `0x1B` | `TARGET_T_RANDOM_GAMEOBJECT_WITH_ENTRY` | Random gameobject matching entry |
