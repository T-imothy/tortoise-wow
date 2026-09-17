---
layout: default
title: spell_effect_mod
---

# spell_effect_mod

World database table `spell_effect_mod`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 21 | latin1 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`Id` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-effectindex"></a>`EffectIndex` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-effect"></a>`Effect` | `int(11)` | NO |  | `-1` |  | numeric value; Uses SpellEffects enum values |
| <a id="col-effectdiesides"></a>`EffectDieSides` | `int(11)` | NO |  | `-1` |  | numeric value |
| <a id="col-effectbasedice"></a>`EffectBaseDice` | `int(11)` | NO |  | `-1` |  | numeric value |
| <a id="col-effectdiceperlevel"></a>`EffectDicePerLevel` | `float` | NO |  | `-1` |  | numeric value |
| <a id="col-effectrealpointsperlevel"></a>`EffectRealPointsPerLevel` | `float` | NO |  | `-1` |  | numeric value |
| <a id="col-effectbasepoints"></a>`EffectBasePoints` | `int(11)` | NO |  | `-1` |  | numeric value |
| <a id="col-effectamplitude"></a>`EffectAmplitude` | `int(11)` | NO |  | `-1` |  | numeric value |
| <a id="col-effectpointspercombopoint"></a>`EffectPointsPerComboPoint` | `float` | NO |  | `-1` |  | numeric value |
| <a id="col-effectchaintarget"></a>`EffectChainTarget` | `int(11)` | NO |  | `-1` |  | numeric value |
| <a id="col-effectmultiplevalue"></a>`EffectMultipleValue` | `float` | NO |  | `-1` |  | numeric value |
| <a id="col-effectmechanic"></a>`EffectMechanic` | `int(11)` | NO |  | `-1` |  | numeric value; Uses Mechanics enum values |
| <a id="col-effectimplicittargeta"></a>`EffectImplicitTargetA` | `int(11)` | NO |  | `-1` |  | numeric value; Uses SpellTarget enum values |
| <a id="col-effectimplicittargetb"></a>`EffectImplicitTargetB` | `int(11)` | NO |  | `-1` |  | numeric value; Uses SpellTarget enum values |
| <a id="col-effectradiusindex"></a>`EffectRadiusIndex` | `int(11)` | NO |  | `-1` |  | numeric value |
| <a id="col-effectapplyauraname"></a>`EffectApplyAuraName` | `int(11)` | NO |  | `-1` |  | numeric value; Uses AuraType enum values |
| <a id="col-effectitemtype"></a>`EffectItemType` | `int(11)` | NO |  | `-1` |  | numeric value |
| <a id="col-effectmiscvalue"></a>`EffectMiscValue` | `int(11)` | NO |  | `-1` |  | numeric value |
| <a id="col-effecttriggerspell"></a>`EffectTriggerSpell` | `int(11)` | NO |  | `-1` |  | numeric value |
| <a id="col-comment"></a>`Comment` | `varchar(255)` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `Id`

non-negative numeric value; identifier column.

### `EffectIndex`

non-negative numeric value.

### `Effect`

numeric value.

Value set: `SpellEffects` (enum) from `src/game/Spells/SpellDefines.h enum SpellEffects`.

### `EffectDieSides`

numeric value.

### `EffectBaseDice`

numeric value.

### `EffectDicePerLevel`

numeric value.

### `EffectRealPointsPerLevel`

numeric value.

### `EffectBasePoints`

numeric value.

### `EffectAmplitude`

numeric value.

### `EffectPointsPerComboPoint`

numeric value.

### `EffectChainTarget`

numeric value.

### `EffectMultipleValue`

numeric value.

### `EffectMechanic`

numeric value.

Value set: `Mechanics` (enum) from `src/game/Spells/SpellDefines.h enum Mechanics`.

### `EffectImplicitTargetA`

numeric value.

Value set: `SpellTarget` (enum) from `src/game/Spells/SpellDefines.h enum SpellTarget`.

### `EffectImplicitTargetB`

numeric value.

Value set: `SpellTarget` (enum) from `src/game/Spells/SpellDefines.h enum SpellTarget`.

### `EffectRadiusIndex`

numeric value.

### `EffectApplyAuraName`

numeric value.

Value set: `AuraType` (enum) from `src/game/Spells/SpellAuraDefines.h enum AuraType`.

### `EffectItemType`

numeric value.

### `EffectMiscValue`

numeric value.

### `EffectTriggerSpell`

numeric value.

### `Comment`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `Id`, `EffectIndex` |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `AuraType` | enum | [`EffectApplyAuraName`](#col-effectapplyauraname) | `src/game/Spells/SpellAuraDefines.h enum AuraType` | 228 |
| `Mechanics` | enum | [`EffectMechanic`](#col-effectmechanic) | `src/game/Spells/SpellDefines.h enum Mechanics` | 32 |
| `SpellEffects` | enum | [`Effect`](#col-effect) | `src/game/Spells/SpellDefines.h enum SpellEffects` | 136 |
| `SpellTarget` | enum | [`EffectImplicitTargetA`](#col-effectimplicittargeta), [`EffectImplicitTargetB`](#col-effectimplicittargetb) | `src/game/Spells/SpellDefines.h enum SpellTarget` | 64 |

### Possible Values

Used by: [`EffectApplyAuraName`](#col-effectapplyauraname)

#### `AuraType`

Kind: `enum`

Source: `src/game/Spells/SpellAuraDefines.h enum AuraType`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `SPELL_AURA_NONE` | Aura None |
| `1` | `0x1` | `SPELL_AURA_BIND_SIGHT` | Aura Bind Sight |
| `2` | `0x2` | `SPELL_AURA_MOD_POSSESS` | Aura Mod Possess |
| `3` | `0x3` | `SPELL_AURA_PERIODIC_DAMAGE` | Aura Periodic Damage |
| `4` | `0x4` | `SPELL_AURA_DUMMY` | Aura Dummy |
| `5` | `0x5` | `SPELL_AURA_MOD_CONFUSE` | Aura Mod Confuse |
| `6` | `0x6` | `SPELL_AURA_MOD_CHARM` | Aura Mod Charm |
| `7` | `0x7` | `SPELL_AURA_MOD_FEAR` | Aura Mod Fear |
| `8` | `0x8` | `SPELL_AURA_PERIODIC_HEAL` | Aura Periodic Heal |
| `9` | `0x9` | `SPELL_AURA_MOD_ATTACKSPEED` | Aura Mod Attackspeed |
| `10` | `0xA` | `SPELL_AURA_MOD_THREAT` | Aura Mod Threat |
| `11` | `0xB` | `SPELL_AURA_MOD_TAUNT` | Aura Mod Taunt |
| `12` | `0xC` | `SPELL_AURA_MOD_STUN` | Aura Mod Stun |
| `13` | `0xD` | `SPELL_AURA_MOD_DAMAGE_DONE` | Aura Mod Damage Done |
| `14` | `0xE` | `SPELL_AURA_MOD_DAMAGE_TAKEN` | Aura Mod Damage Taken |
| `15` | `0xF` | `SPELL_AURA_DAMAGE_SHIELD` | Aura Damage Shield |
| `16` | `0x10` | `SPELL_AURA_MOD_STEALTH` | Aura Mod Stealth |
| `17` | `0x11` | `SPELL_AURA_MOD_STEALTH_DETECT` | Aura Mod Stealth Detect |
| `18` | `0x12` | `SPELL_AURA_MOD_INVISIBILITY` | Aura Mod Invisibility |
| `19` | `0x13` | `SPELL_AURA_MOD_INVISIBILITY_DETECTION` | Aura Mod Invisibility Detection |
| `20` | `0x14` | `SPELL_AURA_OBS_MOD_HEALTH` | 20,21 unofficial |
| `21` | `0x15` | `SPELL_AURA_OBS_MOD_MANA` | Aura Obs Mod Mana |
| `22` | `0x16` | `SPELL_AURA_MOD_RESISTANCE` | Aura Mod Resistance |
| `23` | `0x17` | `SPELL_AURA_PERIODIC_TRIGGER_SPELL` | Aura Periodic Trigger Spell |
| `24` | `0x18` | `SPELL_AURA_PERIODIC_ENERGIZE` | Aura Periodic Energize |
| `25` | `0x19` | `SPELL_AURA_MOD_PACIFY` | Aura Mod Pacify |
| `26` | `0x1A` | `SPELL_AURA_MOD_ROOT` | Aura Mod Root |
| `27` | `0x1B` | `SPELL_AURA_MOD_SILENCE` | Aura Mod Silence |
| `28` | `0x1C` | `SPELL_AURA_REFLECT_SPELLS` | Aura Reflect Spells |
| `29` | `0x1D` | `SPELL_AURA_MOD_STAT` | Aura Mod Stat |
| `30` | `0x1E` | `SPELL_AURA_MOD_SKILL` | Aura Mod Skill |
| `31` | `0x1F` | `SPELL_AURA_MOD_INCREASE_SPEED` | Aura Mod Increase Speed |
| `32` | `0x20` | `SPELL_AURA_MOD_INCREASE_MOUNTED_SPEED` | Aura Mod Increase Mounted Speed |
| `33` | `0x21` | `SPELL_AURA_MOD_DECREASE_SPEED` | Aura Mod Decrease Speed |
| `34` | `0x22` | `SPELL_AURA_MOD_INCREASE_HEALTH` | Aura Mod Increase Health |
| `35` | `0x23` | `SPELL_AURA_MOD_INCREASE_ENERGY` | Aura Mod Increase Energy |
| `36` | `0x24` | `SPELL_AURA_MOD_SHAPESHIFT` | Aura Mod Shapeshift |
| `37` | `0x25` | `SPELL_AURA_EFFECT_IMMUNITY` | Aura Effect Immunity |
| `38` | `0x26` | `SPELL_AURA_STATE_IMMUNITY` | Aura State Immunity |
| `39` | `0x27` | `SPELL_AURA_SCHOOL_IMMUNITY` | Aura School Immunity |
| `40` | `0x28` | `SPELL_AURA_DAMAGE_IMMUNITY` | Aura Damage Immunity |
| `41` | `0x29` | `SPELL_AURA_DISPEL_IMMUNITY` | Aura Dispel Immunity |
| `42` | `0x2A` | `SPELL_AURA_PROC_TRIGGER_SPELL` | Aura Proc Trigger Spell |
| `43` | `0x2B` | `SPELL_AURA_PROC_TRIGGER_DAMAGE` | Aura Proc Trigger Damage |
| `44` | `0x2C` | `SPELL_AURA_TRACK_CREATURES` | Aura Track Creatures |
| `45` | `0x2D` | `SPELL_AURA_TRACK_RESOURCES` | Aura Track Resources |
| `46` | `0x2E` | `SPELL_AURA_MOD_PARRY_SKILL` | Aura Mod Parry Skill |
| `47` | `0x2F` | `SPELL_AURA_MOD_PARRY_PERCENT` | Aura Mod Parry Percent |
| `48` | `0x30` | `SPELL_AURA_MOD_DODGE_SKILL` | Aura Mod Dodge Skill |
| `49` | `0x31` | `SPELL_AURA_MOD_DODGE_PERCENT` | Aura Mod Dodge Percent |
| `50` | `0x32` | `SPELL_AURA_MOD_BLOCK_SKILL` | Aura Mod Block Skill |
| `51` | `0x33` | `SPELL_AURA_MOD_BLOCK_PERCENT` | Aura Mod Block Percent |
| `52` | `0x34` | `SPELL_AURA_MOD_CRIT_PERCENT` | Aura Mod Crit Percent |
| `53` | `0x35` | `SPELL_AURA_PERIODIC_LEECH` | Aura Periodic Leech |
| `54` | `0x36` | `SPELL_AURA_MOD_HIT_CHANCE` | Aura Mod Hit Chance |
| `55` | `0x37` | `SPELL_AURA_MOD_SPELL_HIT_CHANCE` | Aura Mod Spell Hit Chance |
| `56` | `0x38` | `SPELL_AURA_TRANSFORM` | Aura Transform |
| `57` | `0x39` | `SPELL_AURA_MOD_SPELL_CRIT_CHANCE` | Aura Mod Spell Crit Chance |
| `58` | `0x3A` | `SPELL_AURA_MOD_INCREASE_SWIM_SPEED` | Aura Mod Increase Swim Speed |
| `59` | `0x3B` | `SPELL_AURA_MOD_DAMAGE_DONE_CREATURE` | Aura Mod Damage Done Creature |
| `60` | `0x3C` | `SPELL_AURA_MOD_PACIFY_SILENCE` | Aura Mod Pacify Silence |
| `61` | `0x3D` | `SPELL_AURA_MOD_SCALE` | Aura Mod Scale |
| `62` | `0x3E` | `SPELL_AURA_PERIODIC_HEALTH_FUNNEL` | Aura Periodic Health Funnel |
| `63` | `0x3F` | `SPELL_AURA_PERIODIC_MANA_FUNNEL` | Aura Periodic Mana Funnel |
| `64` | `0x40` | `SPELL_AURA_PERIODIC_MANA_LEECH` | Aura Periodic Mana Leech |
| `65` | `0x41` | `SPELL_AURA_MOD_CASTING_SPEED_NOT_STACK` | Aura Mod Casting Speed Not Stack |
| `66` | `0x42` | `SPELL_AURA_FEIGN_DEATH` | Aura Feign Death |
| `67` | `0x43` | `SPELL_AURA_MOD_DISARM` | Aura Mod Disarm |
| `68` | `0x44` | `SPELL_AURA_MOD_STALKED` | Aura Mod Stalked |
| `69` | `0x45` | `SPELL_AURA_SCHOOL_ABSORB` | Aura School Absorb |
| `70` | `0x46` | `SPELL_AURA_EXTRA_ATTACKS` | Aura Extra Attacks |
| `71` | `0x47` | `SPELL_AURA_MOD_SPELL_CRIT_CHANCE_SCHOOL` | Aura Mod Spell Crit Chance School |
| `72` | `0x48` | `SPELL_AURA_MOD_POWER_COST_SCHOOL_PCT` | Aura Mod Power Cost School Pct |
| `73` | `0x49` | `SPELL_AURA_MOD_POWER_COST_SCHOOL` | Aura Mod Power Cost School |
| `74` | `0x4A` | `SPELL_AURA_REFLECT_SPELLS_SCHOOL` | Aura Reflect Spells School |
| `75` | `0x4B` | `SPELL_AURA_MOD_LANGUAGE` | Aura Mod Language |
| `76` | `0x4C` | `SPELL_AURA_FAR_SIGHT` | Aura Far Sight |
| `77` | `0x4D` | `SPELL_AURA_MECHANIC_IMMUNITY` | Aura Mechanic Immunity |
| `78` | `0x4E` | `SPELL_AURA_MOUNTED` | Aura Mounted |
| `79` | `0x4F` | `SPELL_AURA_MOD_DAMAGE_PERCENT_DONE` | Aura Mod Damage Percent Done |
| `80` | `0x50` | `SPELL_AURA_MOD_PERCENT_STAT` | Aura Mod Percent Stat |
| `81` | `0x51` | `SPELL_AURA_SPLIT_DAMAGE_PCT` | Aura Split Damage Pct |
| `82` | `0x52` | `SPELL_AURA_WATER_BREATHING` | Aura Water Breathing |
| `83` | `0x53` | `SPELL_AURA_MOD_BASE_RESISTANCE` | Aura Mod Base Resistance |
| `84` | `0x54` | `SPELL_AURA_MOD_REGEN` | Aura Mod Regen |
| `85` | `0x55` | `SPELL_AURA_MOD_POWER_REGEN` | Aura Mod Power Regen |
| `86` | `0x56` | `SPELL_AURA_CHANNEL_DEATH_ITEM` | Aura Channel Death Item |
| `87` | `0x57` | `SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN` | Aura Mod Damage Percent Taken |
| `88` | `0x58` | `SPELL_AURA_MOD_HEALTH_REGEN_PERCENT` | Aura Mod Health Regen Percent |
| `89` | `0x59` | `SPELL_AURA_PERIODIC_DAMAGE_PERCENT` | Aura Periodic Damage Percent |
| `90` | `0x5A` | `SPELL_AURA_MOD_RESIST_CHANCE` | Aura Mod Resist Chance |
| `91` | `0x5B` | `SPELL_AURA_MOD_DETECT_RANGE` | Aura Mod Detect Range |
| `92` | `0x5C` | `SPELL_AURA_PREVENTS_FLEEING` | Aura Prevents Fleeing |
| `93` | `0x5D` | `SPELL_AURA_MOD_UNATTACKABLE` | Aura Mod Unattackable |
| `94` | `0x5E` | `SPELL_AURA_INTERRUPT_REGEN` | Aura Interrupt Regen |
| `95` | `0x5F` | `SPELL_AURA_GHOST` | Aura Ghost |
| `96` | `0x60` | `SPELL_AURA_SPELL_MAGNET` | Aura Spell Magnet |
| `97` | `0x61` | `SPELL_AURA_MANA_SHIELD` | Aura Mana Shield |
| `98` | `0x62` | `SPELL_AURA_MOD_SKILL_TALENT` | Aura Mod Skill Talent |
| `99` | `0x63` | `SPELL_AURA_MOD_ATTACK_POWER` | Aura Mod Attack Power |
| `100` | `0x64` | `SPELL_AURA_AURAS_VISIBLE` | Aura Auras Visible |
| `101` | `0x65` | `SPELL_AURA_MOD_RESISTANCE_PCT` | Aura Mod Resistance Pct |
| `102` | `0x66` | `SPELL_AURA_MOD_MELEE_ATTACK_POWER_VERSUS` | Aura Mod Melee Attack Power Versus |
| `103` | `0x67` | `SPELL_AURA_MOD_TOTAL_THREAT` | Aura Mod Total Threat |
| `104` | `0x68` | `SPELL_AURA_WATER_WALK` | Aura Water Walk |
| `105` | `0x69` | `SPELL_AURA_FEATHER_FALL` | Aura Feather Fall |
| `106` | `0x6A` | `SPELL_AURA_HOVER` | Aura Hover |
| `107` | `0x6B` | `SPELL_AURA_ADD_FLAT_MODIFIER` | Aura Add Flat Modifier |
| `108` | `0x6C` | `SPELL_AURA_ADD_PCT_MODIFIER` | Aura Add Pct Modifier |
| `109` | `0x6D` | `SPELL_AURA_ADD_TARGET_TRIGGER` | Aura Add Target Trigger |
| `110` | `0x6E` | `SPELL_AURA_MOD_POWER_REGEN_PERCENT` | Aura Mod Power Regen Percent |
| `111` | `0x6F` | `SPELL_AURA_ADD_CASTER_HIT_TRIGGER` | Aura Add Caster Hit Trigger |
| `112` | `0x70` | `SPELL_AURA_OVERRIDE_CLASS_SCRIPTS` | Aura Override Class Scripts |
| `113` | `0x71` | `SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN` | Aura Mod Ranged Damage Taken |
| `114` | `0x72` | `SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN_PCT` | Aura Mod Ranged Damage Taken Pct |
| `115` | `0x73` | `SPELL_AURA_MOD_HEALING` | Aura Mod Healing |
| `116` | `0x74` | `SPELL_AURA_MOD_REGEN_DURING_COMBAT` | Aura Mod Regen During Combat |
| `117` | `0x75` | `SPELL_AURA_MOD_MECHANIC_RESISTANCE` | Aura Mod Mechanic Resistance |
| `118` | `0x76` | `SPELL_AURA_MOD_HEALING_PCT` | Aura Mod Healing Pct |
| `119` | `0x77` | `SPELL_AURA_SHARE_PET_TRACKING` | Aura Share Pet Tracking |
| `120` | `0x78` | `SPELL_AURA_UNTRACKABLE` | Aura Untrackable |
| `121` | `0x79` | `SPELL_AURA_EMPATHY` | Aura Empathy |
| `122` | `0x7A` | `SPELL_AURA_MOD_OFFHAND_DAMAGE_PCT` | Aura Mod Offhand Damage Pct |
| `123` | `0x7B` | `SPELL_AURA_MOD_TARGET_RESISTANCE` | Aura Mod Target Resistance |
| `124` | `0x7C` | `SPELL_AURA_MOD_RANGED_ATTACK_POWER` | Aura Mod Ranged Attack Power |
| `125` | `0x7D` | `SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN` | Aura Mod Melee Damage Taken |
| `126` | `0x7E` | `SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN_PCT` | Aura Mod Melee Damage Taken Pct |
| `127` | `0x7F` | `SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS` | Aura Ranged Attack Power Attacker Bonus |
| `128` | `0x80` | `SPELL_AURA_MOD_POSSESS_PET` | Aura Mod Possess Pet |
| `129` | `0x81` | `SPELL_AURA_MOD_SPEED_ALWAYS` | Aura Mod Speed Always |
| `130` | `0x82` | `SPELL_AURA_MOD_MOUNTED_SPEED_ALWAYS` | Aura Mod Mounted Speed Always |
| `131` | `0x83` | `SPELL_AURA_MOD_RANGED_ATTACK_POWER_VERSUS` | Aura Mod Ranged Attack Power Versus |
| `132` | `0x84` | `SPELL_AURA_MOD_INCREASE_ENERGY_PERCENT` | Aura Mod Increase Energy Percent |
| `133` | `0x85` | `SPELL_AURA_MOD_INCREASE_HEALTH_PERCENT` | Aura Mod Increase Health Percent |
| `134` | `0x86` | `SPELL_AURA_MOD_MANA_REGEN_INTERRUPT` | Aura Mod Mana Regen Interrupt |
| `135` | `0x87` | `SPELL_AURA_MOD_HEALING_DONE` | Aura Mod Healing Done |
| `136` | `0x88` | `SPELL_AURA_MOD_HEALING_DONE_PERCENT` | Aura Mod Healing Done Percent |
| `137` | `0x89` | `SPELL_AURA_MOD_TOTAL_STAT_PERCENTAGE` | Aura Mod Total Stat Percentage |
| `138` | `0x8A` | `SPELL_AURA_MOD_MELEE_HASTE` | Aura Mod Melee Haste |
| `139` | `0x8B` | `SPELL_AURA_FORCE_REACTION` | Aura Force Reaction |
| `140` | `0x8C` | `SPELL_AURA_MOD_RANGED_HASTE` | Aura Mod Ranged Haste |
| `141` | `0x8D` | `SPELL_AURA_MOD_RANGED_AMMO_HASTE` | Aura Mod Ranged Ammo Haste |
| `142` | `0x8E` | `SPELL_AURA_MOD_BASE_RESISTANCE_PCT` | Aura Mod Base Resistance Pct |
| `143` | `0x8F` | `SPELL_AURA_MOD_RESISTANCE_EXCLUSIVE` | Aura Mod Resistance Exclusive |
| `144` | `0x90` | `SPELL_AURA_SAFE_FALL` | Aura Safe Fall |
| `145` | `0x91` | `SPELL_AURA_CHARISMA` | Aura Charisma |
| `146` | `0x92` | `SPELL_AURA_PERSUADED` | Aura Persuaded |
| `147` | `0x93` | `SPELL_AURA_MECHANIC_IMMUNITY_MASK` | Aura Mechanic Immunity Mask |
| `148` | `0x94` | `SPELL_AURA_RETAIN_COMBO_POINTS` | Aura Retain Combo Points |
| `149` | `0x95` | `SPELL_AURA_RESIST_PUSHBACK` | Resist Pushback |
| `150` | `0x96` | `SPELL_AURA_MOD_SHIELD_BLOCKVALUE_PCT` | Aura Mod Shield Blockvalue Pct |
| `151` | `0x97` | `SPELL_AURA_TRACK_STEALTHED` | Track Stealthed |
| `152` | `0x98` | `SPELL_AURA_MOD_DETECTED_RANGE` | Mod Detected Range |
| `153` | `0x99` | `SPELL_AURA_SPLIT_DAMAGE_FLAT` | Split Damage Flat |
| `154` | `0x9A` | `SPELL_AURA_MOD_STEALTH_LEVEL` | Stealth Level Modifier |
| `155` | `0x9B` | `SPELL_AURA_MOD_WATER_BREATHING` | Mod Water Breathing |
| `156` | `0x9C` | `SPELL_AURA_MOD_REPUTATION_GAIN` | Mod Reputation Gain |
| `157` | `0x9D` | `SPELL_AURA_PET_DAMAGE_MULTI` | Mod Pet Damage |
| `158` | `0x9E` | `SPELL_AURA_MOD_SHIELD_BLOCKVALUE` | Aura Mod Shield Blockvalue |
| `159` | `0x9F` | `SPELL_AURA_NO_PVP_CREDIT` | Aura No Pvp Credit |
| `160` | `0xA0` | `SPELL_AURA_MOD_AOE_AVOIDANCE` | Aura Mod Aoe Avoidance |
| `161` | `0xA1` | `SPELL_AURA_MOD_HEALTH_REGEN_IN_COMBAT` | Aura Mod Health Regen In Combat |
| `162` | `0xA2` | `SPELL_AURA_POWER_BURN_MANA` | Aura Power Burn Mana |
| `163` | `0xA3` | `SPELL_AURA_MOD_CRIT_DAMAGE_BONUS` | Aura Mod Crit Damage Bonus |
| `164` | `0xA4` | `SPELL_AURA_164` | Aura 164 |
| `165` | `0xA5` | `SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS` | Aura Melee Attack Power Attacker Bonus |
| `166` | `0xA6` | `SPELL_AURA_MOD_ATTACK_POWER_PCT` | Aura Mod Attack Power Pct |
| `167` | `0xA7` | `SPELL_AURA_MOD_RANGED_ATTACK_POWER_PCT` | Aura Mod Ranged Attack Power Pct |
| `168` | `0xA8` | `SPELL_AURA_MOD_DAMAGE_DONE_VERSUS` | Aura Mod Damage Done Versus |
| `169` | `0xA9` | `SPELL_AURA_MOD_CRIT_PERCENT_VERSUS` | Aura Mod Crit Percent Versus |
| `170` | `0xAA` | `SPELL_AURA_DETECT_AMORE` | Aura Detect Amore |
| `171` | `0xAB` | `SPELL_AURA_MOD_SPEED_NOT_STACK` | Aura Mod Speed Not Stack |
| `172` | `0xAC` | `SPELL_AURA_MOD_MOUNTED_SPEED_NOT_STACK` | Aura Mod Mounted Speed Not Stack |
| `173` | `0xAD` | `SPELL_AURA_ALLOW_CHAMPION_SPELLS` | Aura Allow Champion Spells |
| `174` | `0xAE` | `SPELL_AURA_MOD_SPELL_DAMAGE_OF_STAT_PERCENT` | in 1.12.1 only dependent spirit case |
| `175` | `0xAF` | `SPELL_AURA_MOD_SPELL_HEALING_OF_STAT_PERCENT` | Aura Mod Spell Healing Of Stat Percent |
| `176` | `0xB0` | `SPELL_AURA_SPIRIT_OF_REDEMPTION` | Aura Spirit Of Redemption |
| `177` | `0xB1` | `SPELL_AURA_AOE_CHARM` | Aura Aoe Charm |
| `178` | `0xB2` | `SPELL_AURA_MOD_DEBUFF_RESISTANCE` | Aura Mod Debuff Resistance |
| `179` | `0xB3` | `SPELL_AURA_MOD_ATTACKER_SPELL_CRIT_CHANCE` | Aura Mod Attacker Spell Crit Chance |
| `180` | `0xB4` | `SPELL_AURA_MOD_FLAT_SPELL_DAMAGE_VERSUS` | Aura Mod Flat Spell Damage Versus |
| `181` | `0xB5` | `SPELL_AURA_MOD_FLAT_SPELL_CRIT_DAMAGE_VERSUS` | unused - possible flat spell crit damage versus |
| `182` | `0xB6` | `SPELL_AURA_MOD_RESISTANCE_OF_STAT_PERCENT` | Aura Mod Resistance Of Stat Percent |
| `183` | `0xB7` | `SPELL_AURA_MOD_CRITICAL_THREAT` | Aura Mod Critical Threat |
| `184` | `0xB8` | `SPELL_AURA_MOD_ATTACKER_MELEE_HIT_CHANCE` | Aura Mod Attacker Melee Hit Chance |
| `185` | `0xB9` | `SPELL_AURA_MOD_ATTACKER_RANGED_HIT_CHANCE` | Aura Mod Attacker Ranged Hit Chance |
| `186` | `0xBA` | `SPELL_AURA_MOD_ATTACKER_SPELL_HIT_CHANCE` | Aura Mod Attacker Spell Hit Chance |
| `187` | `0xBB` | `SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_CHANCE` | Aura Mod Attacker Melee Crit Chance |
| `188` | `0xBC` | `SPELL_AURA_MOD_ATTACKER_RANGED_CRIT_CHANCE` | Aura Mod Attacker Ranged Crit Chance |
| `189` | `0xBD` | `SPELL_AURA_MOD_RATING` | Aura Mod Rating |
| `190` | `0xBE` | `SPELL_AURA_MOD_FACTION_REPUTATION_GAIN` | Aura Mod Faction Reputation Gain |
| `191` | `0xBF` | `SPELL_AURA_USE_NORMAL_MOVEMENT_SPEED` | Aura Use Normal Movement Speed |
| `192` | `0xC0` | `SPELL_AURA_AURA_SPELL` | Adds the auras of a spell while this aura is active. |
| `193` | `0xC1` | `SPELL_AURA_SPLIT_DAMAGE_GROUP_PCT` | Needed for Spirit Link. |
| `194` | `0xC2` | `SPELL_AURA_MOD_AOE_DAMAGE_PERCENT_TAKEN` | Needed for Pet Avoidance. |
| `195` | `0xC3` | `SPELL_AURA_MOD_HONOR_GAIN` | From WotLK. |
| `196` | `0xC4` | `SPELL_AURA_ENABLE_FLYING` | For flying mounts. |
| `197` | `0xC5` | `SPELL_AURA_MOD_PERIODIC_DAMAGE_PERCENT_TAKEN` | Modifies periodic damage taken. |
| `198` | `0xC6` | `SPELL_AURA_MOD_CRIT_DAMAGE_BONUS_TAKEN` | Modifies critical damage taken. |
| `199` | `0xC7` | `SPELL_AURA_MOD_SPELL_HEALING_OF_ARMOR_PERCENT` | Converts a percentage of armor into bonus healing power. |
| `200` | `0xC8` | `SPELL_AURA_TRANSFER_TOTEM_THREAT` | Aura Transfer Totem Threat |
| `201` | `0xC9` | `SPELL_AURA_TRIGGER_AURA_ON_TOTEMS` | Aura Trigger Aura On Totems |
| `202` | `0xCA` | `SPELL_AURA_MOD_PET_STAT_PERCENT_OF_OWNER` | Aura Mod Pet Stat Percent Of Owner |
| `203` | `0xCB` | `SPELL_AURA_MOD_PET_ARMOR_PERCENT_OF_OWNER` | Aura Mod Pet Armor Percent Of Owner |
| `204` | `0xCC` | `SPELL_AURA_MOD_PET_RESISTANCE_PERCENT_OF_OWNER` | Aura Mod Pet Resistance Percent Of Owner |
| `205` | `0xCD` | `SPELL_AURA_MOD_PET_ATTACK_POWER_PERCENT_OF_OWNER` | Aura Mod Pet Attack Power Percent Of Owner |
| `206` | `0xCE` | `SPELL_AURA_MOD_PET_SPELL_DAMAGE_PERCENT_OF_OWNER` | Aura Mod Pet Spell Damage Percent Of Owner |
| `207` | `0xCF` | `SPELL_AURA_MOD_ATTACK_AND_SPELL_RANGE` | Aura Mod Attack And Spell Range |
| `208` | `0xD0` | `SPELL_AURA_MOD_REAGENT_CONSUMPTION_CHANCE` | Aura Mod Reagent Consumption Chance |
| `209` | `0xD1` | `SPELL_AURA_MOD_MECHANIC_DURATION` | Aura Mod Mechanic Duration |
| `210` | `0xD2` | `SPELL_AURA_MOD_SELF_RESURRECTION_RECOVERY` | Aura Mod Self Resurrection Recovery |
| `211` | `0xD3` | `SPELL_AURA_MOD_PET_SPELL_CRIT_PERCENT_OF_OWNER` | Aura Mod Pet Spell Crit Percent Of Owner |
| `212` | `0xD4` | `SPELL_AURA_MOD_IGNORE_TARGET_ARMOR` | Aura Mod Ignore Target Armor |
| `213` | `0xD5` | `SPELL_AURA_MOD_SPELL_DAMAGE_OF_INTELLECT_PERCENT` | Aura Mod Spell Damage Of Intellect Percent |
| `214` | `0xD6` | `SPELL_AURA_MOD_MANA_GAIN_PERCENT` | Aura Mod Mana Gain Percent |
| `215` | `0xD7` | `SPELL_AURA_MOD_PET_SPELL_HIT_PERCENT_OF_OWNER` | Aura Mod Pet Spell Hit Percent Of Owner |
| `216` | `0xD8` | `SPELL_AURA_MOD_PET_MELEE_HIT_PERCENT_OF_OWNER` | Aura Mod Pet Melee Hit Percent Of Owner |
| `217` | `0xD9` | `SPELL_AURA_MOD_ENERGY_REGEN_TIME` | Aura Mod Energy Regen Time |
| `218` | `0xDA` | `SPELL_AURA_PERIODIC_TRIGGER_SPELL2` | Aura Periodic Trigger Spell2 |
| `219` | `0xDB` | `SPELL_AURA_219` | Aura 219 |
| `220` | `0xDC` | `SPELL_AURA_MOD_DAMAGE_TAKEN_FROM_CASTER_PET` | Aura Mod Damage Taken From Caster Pet |
| `221` | `0xDD` | `SPELL_AURA_MOD_ATTACK_POWER_AREA` | Aura Mod Attack Power Area |
| `222` | `0xDE` | `SPELL_AURA_MOD_ATTACK_POWER_PERCENT_AREA` | Aura Mod Attack Power Percent Area |
| `223` | `0xDF` | `SPELL_AURA_MOD_ITEM_PROC_CHANCE` | Aura Mod Item Proc Chance |
| `224` | `0xE0` | `SPELL_AURA_MOD_BLOCK_DAMAGE_PERCENT` | Aura Mod Block Damage Percent |
| `225` | `0xE1` | `SPELL_AURA_MOD_GATHERING_ITEM_CHANCE` | Aura Mod Gathering Item Chance |
| `226` | `0xE2` | `SPELL_AURA_MOD_RAGE_FROM_DAMAGE_DEALT` | Aura Mod Rage From Damage Dealt |
| `227` | `0xE3` | `TOTAL_AURAS` | Total Auras |

Used by: [`EffectMechanic`](#col-effectmechanic)

#### `Mechanics`

Kind: `enum`

Source: `src/game/Spells/SpellDefines.h enum Mechanics`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `MECHANIC_NONE` | No mechanic |
| `1` | `0x1` | `MECHANIC_CHARM` | Charm |
| `2` | `0x2` | `MECHANIC_DISORIENTED` | Disoriented |
| `3` | `0x3` | `MECHANIC_DISARM` | Disarm |
| `4` | `0x4` | `MECHANIC_DISTRACT` | Distract |
| `5` | `0x5` | `MECHANIC_FEAR` | Fear |
| `6` | `0x6` | `MECHANIC_FUMBLE` | Fumble |
| `7` | `0x7` | `MECHANIC_ROOT` | Root |
| `8` | `0x8` | `MECHANIC_PACIFY` | Pacify |
| `9` | `0x9` | `MECHANIC_SILENCE` | Silence |
| `10` | `0xA` | `MECHANIC_SLEEP` | Sleep |
| `11` | `0xB` | `MECHANIC_SNARE` | Snare |
| `12` | `0xC` | `MECHANIC_STUN` | Stun |
| `13` | `0xD` | `MECHANIC_FREEZE` | Freeze |
| `14` | `0xE` | `MECHANIC_KNOCKOUT` | Knockout |
| `15` | `0xF` | `MECHANIC_BLEED` | Bleed |
| `16` | `0x10` | `MECHANIC_BANDAGE` | Bandage |
| `17` | `0x11` | `MECHANIC_POLYMORPH` | Polymorph |
| `18` | `0x12` | `MECHANIC_BANISH` | Banish |
| `19` | `0x13` | `MECHANIC_SHIELD` | Shield |
| `20` | `0x14` | `MECHANIC_SHACKLE` | Shackle |
| `21` | `0x15` | `MECHANIC_MOUNT` | Mount |
| `22` | `0x16` | `MECHANIC_PERSUADE` | Persuade |
| `23` | `0x17` | `MECHANIC_TURN` | Turn |
| `24` | `0x18` | `MECHANIC_HORROR` | Horror |
| `25` | `0x19` | `MECHANIC_INVULNERABILITY` | Invulnerability |
| `26` | `0x1A` | `MECHANIC_INTERRUPT` | Interrupt |
| `27` | `0x1B` | `MECHANIC_DAZE` | Daze |
| `28` | `0x1C` | `MECHANIC_DISCOVERY` | Discovery |
| `29` | `0x1D` | `MECHANIC_IMMUNE_SHIELD` | Immune shield |
| `30` | `0x1E` | `MECHANIC_SAPPED` | Sapped |
| `31` | `0x1F` | `MECHANIC_SLOW_CAST_SPEED` | Slow cast speed |

Used by: [`Effect`](#col-effect)

#### `SpellEffects`

Kind: `enum`

Source: `src/game/Spells/SpellDefines.h enum SpellEffects`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `SPELL_EFFECT_NONE` | Effect None |
| `1` | `0x1` | `SPELL_EFFECT_INSTAKILL` | Effect Instakill |
| `2` | `0x2` | `SPELL_EFFECT_SCHOOL_DAMAGE` | Effect School Damage |
| `3` | `0x3` | `SPELL_EFFECT_DUMMY` | Effect Dummy |
| `4` | `0x4` | `SPELL_EFFECT_PORTAL_TELEPORT` | Effect Portal Teleport |
| `5` | `0x5` | `SPELL_EFFECT_TELEPORT_UNITS` | Effect Teleport Units |
| `6` | `0x6` | `SPELL_EFFECT_APPLY_AURA` | Effect Apply Aura |
| `7` | `0x7` | `SPELL_EFFECT_ENVIRONMENTAL_DAMAGE` | Effect Environmental Damage |
| `8` | `0x8` | `SPELL_EFFECT_POWER_DRAIN` | Effect Power Drain |
| `9` | `0x9` | `SPELL_EFFECT_HEALTH_LEECH` | Effect Health Leech |
| `10` | `0xA` | `SPELL_EFFECT_HEAL` | Effect Heal |
| `11` | `0xB` | `SPELL_EFFECT_BIND` | Effect Bind |
| `12` | `0xC` | `SPELL_EFFECT_PORTAL` | Effect Portal |
| `13` | `0xD` | `SPELL_EFFECT_RITUAL_BASE` | Effect Ritual Base |
| `14` | `0xE` | `SPELL_EFFECT_RITUAL_SPECIALIZE` | Effect Ritual Specialize |
| `15` | `0xF` | `SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL` | Effect Ritual Activate Portal |
| `16` | `0x10` | `SPELL_EFFECT_QUEST_COMPLETE` | Effect Quest Complete |
| `17` | `0x11` | `SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL` | Effect Weapon Damage Noschool |
| `18` | `0x12` | `SPELL_EFFECT_RESURRECT` | Effect Resurrect |
| `19` | `0x13` | `SPELL_EFFECT_ADD_EXTRA_ATTACKS` | Effect Add Extra Attacks |
| `20` | `0x14` | `SPELL_EFFECT_DODGE` | Effect Dodge |
| `21` | `0x15` | `SPELL_EFFECT_EVADE` | Effect Evade |
| `22` | `0x16` | `SPELL_EFFECT_PARRY` | Effect Parry |
| `23` | `0x17` | `SPELL_EFFECT_BLOCK` | Effect Block |
| `24` | `0x18` | `SPELL_EFFECT_CREATE_ITEM` | Effect Create Item |
| `25` | `0x19` | `SPELL_EFFECT_WEAPON` | Effect Weapon |
| `26` | `0x1A` | `SPELL_EFFECT_DEFENSE` | Effect Defense |
| `27` | `0x1B` | `SPELL_EFFECT_PERSISTENT_AREA_AURA` | Effect Persistent Area Aura |
| `28` | `0x1C` | `SPELL_EFFECT_SUMMON` | Effect Summon |
| `29` | `0x1D` | `SPELL_EFFECT_LEAP` | Effect Leap |
| `30` | `0x1E` | `SPELL_EFFECT_ENERGIZE` | Effect Energize |
| `31` | `0x1F` | `SPELL_EFFECT_WEAPON_PERCENT_DAMAGE` | Effect Weapon Percent Damage |
| `32` | `0x20` | `SPELL_EFFECT_TRIGGER_MISSILE` | Effect Trigger Missile |
| `33` | `0x21` | `SPELL_EFFECT_OPEN_LOCK` | Effect Open Lock |
| `34` | `0x22` | `SPELL_EFFECT_SUMMON_CHANGE_ITEM` | Effect Summon Change Item |
| `35` | `0x23` | `SPELL_EFFECT_APPLY_AREA_AURA_PARTY` | Effect Apply Area Aura Party |
| `36` | `0x24` | `SPELL_EFFECT_LEARN_SPELL` | Effect Learn Spell |
| `37` | `0x25` | `SPELL_EFFECT_SPELL_DEFENSE` | Effect Spell Defense |
| `38` | `0x26` | `SPELL_EFFECT_DISPEL` | Effect Dispel |
| `39` | `0x27` | `SPELL_EFFECT_LANGUAGE` | Effect Language |
| `40` | `0x28` | `SPELL_EFFECT_DUAL_WIELD` | Effect Dual Wield |
| `41` | `0x29` | `SPELL_EFFECT_SUMMON_WILD` | Effect Summon Wild |
| `42` | `0x2A` | `SPELL_EFFECT_SUMMON_GUARDIAN` | Effect Summon Guardian |
| `43` | `0x2B` | `SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER` | Effect Teleport Units Face Caster |
| `44` | `0x2C` | `SPELL_EFFECT_SKILL_STEP` | Effect Skill Step |
| `45` | `0x2D` | `SPELL_EFFECT_ADD_HONOR` | Effect Add Honor |
| `46` | `0x2E` | `SPELL_EFFECT_SPAWN` | Effect Spawn |
| `47` | `0x2F` | `SPELL_EFFECT_TRADE_SKILL` | Effect Trade Skill |
| `48` | `0x30` | `SPELL_EFFECT_STEALTH` | Effect Stealth |
| `49` | `0x31` | `SPELL_EFFECT_DETECT` | Effect Detect |
| `50` | `0x32` | `SPELL_EFFECT_TRANS_DOOR` | Effect Trans Door |
| `51` | `0x33` | `SPELL_EFFECT_FORCE_CRITICAL_HIT` | Effect Force Critical Hit |
| `52` | `0x34` | `SPELL_EFFECT_GUARANTEE_HIT` | Effect Guarantee Hit |
| `53` | `0x35` | `SPELL_EFFECT_ENCHANT_ITEM` | Effect Enchant Item |
| `54` | `0x36` | `SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY` | Effect Enchant Item Temporary |
| `55` | `0x37` | `SPELL_EFFECT_TAMECREATURE` | Effect Tamecreature |
| `56` | `0x38` | `SPELL_EFFECT_SUMMON_PET` | Effect Summon Pet |
| `57` | `0x39` | `SPELL_EFFECT_LEARN_PET_SPELL` | Effect Learn Pet Spell |
| `58` | `0x3A` | `SPELL_EFFECT_WEAPON_DAMAGE` | Effect Weapon Damage |
| `59` | `0x3B` | `SPELL_EFFECT_OPEN_LOCK_ITEM` | Effect Open Lock Item |
| `60` | `0x3C` | `SPELL_EFFECT_PROFICIENCY` | Effect Proficiency |
| `61` | `0x3D` | `SPELL_EFFECT_SEND_EVENT` | Effect Send Event |
| `62` | `0x3E` | `SPELL_EFFECT_POWER_BURN` | Effect Power Burn |
| `63` | `0x3F` | `SPELL_EFFECT_THREAT` | Effect Threat |
| `64` | `0x40` | `SPELL_EFFECT_TRIGGER_SPELL` | Effect Trigger Spell |
| `65` | `0x41` | `SPELL_EFFECT_HEALTH_FUNNEL` | Effect Health Funnel |
| `66` | `0x42` | `SPELL_EFFECT_POWER_FUNNEL` | Effect Power Funnel |
| `67` | `0x43` | `SPELL_EFFECT_HEAL_MAX_HEALTH` | Effect Heal Max Health |
| `68` | `0x44` | `SPELL_EFFECT_INTERRUPT_CAST` | Effect Interrupt Cast |
| `69` | `0x45` | `SPELL_EFFECT_DISTRACT` | Effect Distract |
| `70` | `0x46` | `SPELL_EFFECT_PULL` | Effect Pull |
| `71` | `0x47` | `SPELL_EFFECT_PICKPOCKET` | Effect Pickpocket |
| `72` | `0x48` | `SPELL_EFFECT_ADD_FARSIGHT` | Effect Add Farsight |
| `73` | `0x49` | `SPELL_EFFECT_SUMMON_POSSESSED` | Effect Summon Possessed |
| `74` | `0x4A` | `SPELL_EFFECT_SUMMON_TOTEM` | Effect Summon Totem |
| `75` | `0x4B` | `SPELL_EFFECT_HEAL_MECHANICAL` | Effect Heal Mechanical |
| `76` | `0x4C` | `SPELL_EFFECT_SUMMON_OBJECT_WILD` | Effect Summon Object Wild |
| `77` | `0x4D` | `SPELL_EFFECT_SCRIPT_EFFECT` | Effect Script Effect |
| `78` | `0x4E` | `SPELL_EFFECT_ATTACK` | Effect Attack |
| `79` | `0x4F` | `SPELL_EFFECT_SANCTUARY` | Effect Sanctuary |
| `80` | `0x50` | `SPELL_EFFECT_ADD_COMBO_POINTS` | Effect Add Combo Points |
| `81` | `0x51` | `SPELL_EFFECT_CREATE_HOUSE` | Effect Create House |
| `82` | `0x52` | `SPELL_EFFECT_BIND_SIGHT` | Effect Bind Sight |
| `83` | `0x53` | `SPELL_EFFECT_DUEL` | Effect Duel |
| `84` | `0x54` | `SPELL_EFFECT_STUCK` | Effect Stuck |
| `85` | `0x55` | `SPELL_EFFECT_SUMMON_PLAYER` | Effect Summon Player |
| `86` | `0x56` | `SPELL_EFFECT_ACTIVATE_OBJECT` | Effect Activate Object |
| `87` | `0x57` | `SPELL_EFFECT_SUMMON_TOTEM_SLOT1` | Effect Summon Totem Slot1 |
| `88` | `0x58` | `SPELL_EFFECT_SUMMON_TOTEM_SLOT2` | Effect Summon Totem Slot2 |
| `89` | `0x59` | `SPELL_EFFECT_SUMMON_TOTEM_SLOT3` | Effect Summon Totem Slot3 |
| `90` | `0x5A` | `SPELL_EFFECT_SUMMON_TOTEM_SLOT4` | Effect Summon Totem Slot4 |
| `91` | `0x5B` | `SPELL_EFFECT_THREAT_ALL` | Effect Threat All |
| `92` | `0x5C` | `SPELL_EFFECT_ENCHANT_HELD_ITEM` | Effect Enchant Held Item |
| `93` | `0x5D` | `SPELL_EFFECT_SUMMON_PHANTASM` | Effect Summon Phantasm |
| `94` | `0x5E` | `SPELL_EFFECT_SELF_RESURRECT` | Effect Self Resurrect |
| `95` | `0x5F` | `SPELL_EFFECT_SKINNING` | Effect Skinning |
| `96` | `0x60` | `SPELL_EFFECT_CHARGE` | Effect Charge |
| `97` | `0x61` | `SPELL_EFFECT_SUMMON_CRITTER` | Effect Summon Critter |
| `98` | `0x62` | `SPELL_EFFECT_KNOCK_BACK` | Effect Knock Back |
| `99` | `0x63` | `SPELL_EFFECT_DISENCHANT` | Effect Disenchant |
| `100` | `0x64` | `SPELL_EFFECT_INEBRIATE` | Effect Inebriate |
| `101` | `0x65` | `SPELL_EFFECT_FEED_PET` | Effect Feed Pet |
| `102` | `0x66` | `SPELL_EFFECT_DISMISS_PET` | Effect Dismiss Pet |
| `103` | `0x67` | `SPELL_EFFECT_REPUTATION` | Effect Reputation |
| `104` | `0x68` | `SPELL_EFFECT_SUMMON_OBJECT_SLOT1` | Effect Summon Object Slot1 |
| `105` | `0x69` | `SPELL_EFFECT_SUMMON_OBJECT_SLOT2` | Effect Summon Object Slot2 |
| `106` | `0x6A` | `SPELL_EFFECT_SUMMON_OBJECT_SLOT3` | Effect Summon Object Slot3 |
| `107` | `0x6B` | `SPELL_EFFECT_SUMMON_OBJECT_SLOT4` | Effect Summon Object Slot4 |
| `108` | `0x6C` | `SPELL_EFFECT_DISPEL_MECHANIC` | Effect Dispel Mechanic |
| `109` | `0x6D` | `SPELL_EFFECT_SUMMON_DEAD_PET` | Effect Summon Dead Pet |
| `110` | `0x6E` | `SPELL_EFFECT_DESTROY_ALL_TOTEMS` | Effect Destroy All Totems |
| `111` | `0x6F` | `SPELL_EFFECT_DURABILITY_DAMAGE` | Effect Durability Damage |
| `112` | `0x70` | `SPELL_EFFECT_SUMMON_DEMON` | Effect Summon Demon |
| `113` | `0x71` | `SPELL_EFFECT_RESURRECT_NEW` | Effect Resurrect New |
| `114` | `0x72` | `SPELL_EFFECT_ATTACK_ME` | Effect Attack Me |
| `115` | `0x73` | `SPELL_EFFECT_DURABILITY_DAMAGE_PCT` | Effect Durability Damage Pct |
| `116` | `0x74` | `SPELL_EFFECT_SKIN_PLAYER_CORPSE` | Effect Skin Player Corpse |
| `117` | `0x75` | `SPELL_EFFECT_SPIRIT_HEAL` | Effect Spirit Heal |
| `118` | `0x76` | `SPELL_EFFECT_SKILL` | Effect Skill |
| `119` | `0x77` | `SPELL_EFFECT_APPLY_AREA_AURA_PET` | Effect Apply Area Aura Pet |
| `120` | `0x78` | `SPELL_EFFECT_TELEPORT_GRAVEYARD` | Effect Teleport Graveyard |
| `121` | `0x79` | `SPELL_EFFECT_NORMALIZED_WEAPON_DMG` | Effect Normalized Weapon Dmg |
| `122` | `0x7A` | `SPELL_EFFECT_REPUTATION_QUEST_REWARD` | Effect Reputation Quest Reward |
| `123` | `0x7B` | `SPELL_EFFECT_SEND_TAXI` | Effect Send Taxi |
| `124` | `0x7C` | `SPELL_EFFECT_PLAYER_PULL` | Effect Player Pull |
| `125` | `0x7D` | `SPELL_EFFECT_MODIFY_THREAT_PERCENT` | Effect Modify Threat Percent |
| `126` | `0x7E` | `SPELL_EFFECT_STEAL_BENEFICIAL_BUFF` | Effect Steal Beneficial Buff |
| `127` | `0x7F` | `SPELL_EFFECT_PROSPECTING` | Effect Prospecting |
| `128` | `0x80` | `SPELL_EFFECT_APPLY_AREA_AURA_FRIEND` | Effect Apply Area Aura Friend |
| `129` | `0x81` | `SPELL_EFFECT_APPLY_AREA_AURA_ENEMY` | Effect Apply Area Aura Enemy |
| `130` | `0x82` | `SPELL_EFFECT_DESPAWN_OBJECT` | Effect Despawn Object |
| `131` | `0x83` | `SPELL_EFFECT_NOSTALRIUS` | Effect Nostalrius |
| `132` | `0x84` | `SPELL_EFFECT_APPLY_AREA_AURA_RAID` | Effect Apply Area Aura Raid |
| `133` | `0x85` | `SPELL_EFFECT_APPLY_AREA_AURA_OWNER` | Effect Apply Area Aura Owner |
| `134` | `0x86` | `SPELL_EFFECT_APPLY_AURA_PET` | Effect Apply Aura Pet |
| `135` | `0x87` | `TOTAL_SPELL_EFFECTS` | Total Spell Effects |

Used by: [`EffectImplicitTargetA`](#col-effectimplicittargeta), [`EffectImplicitTargetB`](#col-effectimplicittargetb)

#### `SpellTarget`

Kind: `enum`

Source: `src/game/Spells/SpellDefines.h enum SpellTarget`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `TARGET_NONE` | Target None |
| `1` | `0x1` | `TARGET_UNIT_CASTER` | Target Unit Caster |
| `2` | `0x2` | `TARGET_UNIT_ENEMY_NEAR_CASTER` | Target Unit Enemy Near Caster |
| `3` | `0x3` | `TARGET_UNIT_FRIEND_NEAR_CASTER` | Target Unit Friend Near Caster |
| `4` | `0x4` | `TARGET_UNIT_NEAR_CASTER` | Target Unit Near Caster |
| `5` | `0x5` | `TARGET_UNIT_CASTER_PET` | Target Unit Caster Pet |
| `6` | `0x6` | `TARGET_UNIT_ENEMY` | Target Unit Enemy |
| `7` | `0x7` | `TARGET_ENUM_UNITS_SCRIPT_AOE_AT_SRC_LOC` | Target Enum Units Script Aoe At Src Loc |
| `8` | `0x8` | `TARGET_ENUM_UNITS_SCRIPT_AOE_AT_DEST_LOC` | Target Enum Units Script Aoe At Dest Loc |
| `9` | `0x9` | `TARGET_LOCATION_CASTER_HOME_BIND` | Target Location Caster Home Bind |
| `10` | `0xA` | `TARGET_LOCATION_CASTER_DIVINE_BIND_NYI` | Target Location Caster Divine Bind Nyi |
| `11` | `0xB` | `TARGET_PLAYER_NYI` | Target Player Nyi |
| `12` | `0xC` | `TARGET_PLAYER_NEAR_CASTER_NYI` | Target Player Near Caster Nyi |
| `13` | `0xD` | `TARGET_PLAYER_ENEMY_NYI` | Target Player Enemy Nyi |
| `14` | `0xE` | `TARGET_PLAYER_FRIEND_NYI` | Target Player Friend Nyi |
| `15` | `0xF` | `TARGET_ENUM_UNITS_ENEMY_AOE_AT_SRC_LOC` | Target Enum Units Enemy Aoe At Src Loc |
| `16` | `0x10` | `TARGET_ENUM_UNITS_ENEMY_AOE_AT_DEST_LOC` | Target Enum Units Enemy Aoe At Dest Loc |
| `17` | `0x11` | `TARGET_LOCATION_DATABASE` | Target Location Database |
| `18` | `0x12` | `TARGET_LOCATION_CASTER_DEST` | Target Location Caster Dest |
| `19` | `0x13` | `TARGET_UNK_19` | Target Unk 19 |
| `20` | `0x14` | `TARGET_ENUM_UNITS_PARTY_WITHIN_CASTER_RANGE` | Target Enum Units Party Within Caster Range |
| `21` | `0x15` | `TARGET_UNIT_FRIEND` | Target Unit Friend |
| `22` | `0x16` | `TARGET_LOCATION_CASTER_SRC` | Target Location Caster Src |
| `23` | `0x17` | `TARGET_GAMEOBJECT` | Target Gameobject |
| `24` | `0x18` | `TARGET_ENUM_UNITS_ENEMY_IN_CONE_24` | Target Enum Units Enemy In Cone 24 |
| `25` | `0x19` | `TARGET_UNIT` | Target Unit |
| `26` | `0x1A` | `TARGET_LOCKED` | Target Locked |
| `27` | `0x1B` | `TARGET_UNIT_CASTER_MASTER` | Target Unit Caster Master |
| `28` | `0x1C` | `TARGET_ENUM_UNITS_ENEMY_AOE_AT_DYNOBJ_LOC` | Target Enum Units Enemy Aoe At Dynobj Loc |
| `29` | `0x1D` | `TARGET_ENUM_UNITS_FRIEND_AOE_AT_DYNOBJ_LOC` | Target Enum Units Friend Aoe At Dynobj Loc |
| `30` | `0x1E` | `TARGET_ENUM_UNITS_FRIEND_AOE_AT_SRC_LOC` | Target Enum Units Friend Aoe At Src Loc |
| `31` | `0x1F` | `TARGET_ENUM_UNITS_FRIEND_AOE_AT_DEST_LOC` | Target Enum Units Friend Aoe At Dest Loc |
| `32` | `0x20` | `TARGET_LOCATION_UNIT_MINION_POSITION` | Target Location Unit Minion Position |
| `33` | `0x21` | `TARGET_ENUM_UNITS_PARTY_AOE_AT_SRC_LOC` | Target Enum Units Party Aoe At Src Loc |
| `34` | `0x22` | `TARGET_ENUM_UNITS_PARTY_AOE_AT_DEST_LOC` | Target Enum Units Party Aoe At Dest Loc |
| `35` | `0x23` | `TARGET_UNIT_PARTY` | Target Unit Party |
| `36` | `0x24` | `TARGET_ENUM_UNITS_ENEMY_WITHIN_CASTER_RANGE` | TODO: only used with dest-effects - reinvestigate naming |
| `37` | `0x25` | `TARGET_UNIT_FRIEND_AND_PARTY` | Target Unit Friend And Party |
| `38` | `0x26` | `TARGET_UNIT_SCRIPT_NEAR_CASTER` | Target Unit Script Near Caster |
| `39` | `0x27` | `TARGET_LOCATION_CASTER_FISHING_SPOT` | Target Location Caster Fishing Spot |
| `40` | `0x28` | `TARGET_GAMEOBJECT_SCRIPT_NEAR_CASTER` | Target Gameobject Script Near Caster |
| `41` | `0x29` | `TARGET_LOCATION_CASTER_FRONT_RIGHT` | Target Location Caster Front Right |
| `42` | `0x2A` | `TARGET_LOCATION_CASTER_BACK_RIGHT` | Target Location Caster Back Right |
| `43` | `0x2B` | `TARGET_LOCATION_CASTER_BACK_LEFT` | Target Location Caster Back Left |
| `44` | `0x2C` | `TARGET_LOCATION_CASTER_FRONT_LEFT` | Target Location Caster Front Left |
| `45` | `0x2D` | `TARGET_UNIT_FRIEND_CHAIN_HEAL` | Target Unit Friend Chain Heal |
| `46` | `0x2E` | `TARGET_LOCATION_SCRIPT_NEAR_CASTER` | Target Location Script Near Caster |
| `47` | `0x2F` | `TARGET_LOCATION_CASTER_FRONT` | Target Location Caster Front |
| `48` | `0x30` | `TARGET_LOCATION_CASTER_BACK` | Target Location Caster Back |
| `49` | `0x31` | `TARGET_LOCATION_CASTER_LEFT` | Target Location Caster Left |
| `50` | `0x32` | `TARGET_LOCATION_CASTER_RIGHT` | Target Location Caster Right |
| `51` | `0x33` | `TARGET_ENUM_GAMEOBJECTS_SCRIPT_AOE_AT_SRC_LOC` | Target Enum Gameobjects Script Aoe At Src Loc |
| `52` | `0x34` | `TARGET_ENUM_GAMEOBJECTS_SCRIPT_AOE_AT_DEST_LOC` | Target Enum Gameobjects Script Aoe At Dest Loc |
| `53` | `0x35` | `TARGET_LOCATION_CASTER_TARGET_POSITION` | Target Location Caster Target Position |
| `54` | `0x36` | `TARGET_ENUM_UNITS_ENEMY_IN_CONE_54` | Target Enum Units Enemy In Cone 54 |
| `55` | `0x37` | `TARGET_LOCATION_CASTER_FRONT_LEAP` | Target Location Caster Front Leap |
| `56` | `0x38` | `TARGET_ENUM_UNITS_RAID_WITHIN_CASTER_RANGE` | Target Enum Units Raid Within Caster Range |
| `57` | `0x39` | `TARGET_UNIT_RAID` | Target Unit Raid |
| `58` | `0x3A` | `TARGET_UNIT_RAID_NEAR_CASTER` | Target Unit Raid Near Caster |
| `59` | `0x3B` | `TARGET_ENUM_UNITS_FRIEND_IN_CONE` | Target Enum Units Friend In Cone |
| `60` | `0x3C` | `TARGET_ENUM_UNITS_SCRIPT_IN_CONE_60` | Target Enum Units Script In Cone 60 |
| `61` | `0x3D` | `TARGET_UNIT_RAID_AND_CLASS` | Target Unit Raid And Class |
| `62` | `0x3E` | `TARGET_PLAYER_RAID_NYI` | Target Player Raid Nyi |
| `63` | `0x3F` | `TARGET_LOCATION_UNIT_POSITION` | Target Location Unit Position |
