---
layout: default
title: spell_check
---

# spell_check

World database table `spell_check`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 11 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-spellid"></a>`spellid` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-spellfamilyname"></a>`SpellFamilyName` | `smallint(6)` | NO | `PRI` | `-1` |  | numeric value; Uses SpellFamily enum values |
| <a id="col-spellfamilymask"></a>`SpellFamilyMask` | `bigint(20)` | NO | `PRI` | `-1` |  | numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-spellicon"></a>`SpellIcon` | `int(11)` | NO | `PRI` | `-1` |  | numeric value |
| <a id="col-spellvisual"></a>`SpellVisual` | `int(11)` | NO | `PRI` | `-1` |  | numeric value |
| <a id="col-spellcategory"></a>`SpellCategory` | `int(11)` | NO | `PRI` | `-1` |  | numeric value |
| <a id="col-effecttype"></a>`EffectType` | `int(11)` | NO |  | `-1` |  | numeric value |
| <a id="col-effectaura"></a>`EffectAura` | `int(11)` | NO |  | `-1` |  | numeric value; Uses AuraType enum values |
| <a id="col-effectidx"></a>`EffectIdx` | `tinyint(4)` | NO |  | `-1` |  | numeric value |
| <a id="col-name"></a>`Name` | `varchar(40)` | NO |  | `''` |  | text/string data |
| <a id="col-code"></a>`Code` | `varchar(40)` | NO | `PRI` | `''` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `spellid`

non-negative numeric value.

References: [`spell_template`](spell_template.md).`entry`.

### `SpellFamilyName`

numeric value.

Value set: `SpellFamily` (enum) from `src/game/Database/DBCEnums.h enum SpellFamily`.

### `SpellFamilyMask`

numeric value; mask/flags column; combine values with bitwise OR.

### `SpellIcon`

numeric value.

### `SpellVisual`

numeric value.

### `SpellCategory`

numeric value.

### `EffectType`

numeric value.

### `EffectAura`

numeric value.

Value set: `AuraType` (enum) from `src/game/Spells/SpellAuraDefines.h enum AuraType`.

### `EffectIdx`

numeric value.

### `Name`

text/string data.

### `Code`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `spellid`, `SpellFamilyName`, `SpellFamilyMask`, `SpellIcon`, `SpellVisual`, `SpellCategory`, `Code` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `spellid` | [`spell_template`](spell_template.md).`entry` | heuristic | inferred from column name |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `AuraType` | enum | [`EffectAura`](#col-effectaura) | `src/game/Spells/SpellAuraDefines.h enum AuraType` | 228 |
| `SpellFamily` | enum | [`SpellFamilyName`](#col-spellfamilyname) | `src/game/Database/DBCEnums.h enum SpellFamily` | 15 |

### Possible Values

Used by: [`EffectAura`](#col-effectaura)

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

Used by: [`SpellFamilyName`](#col-spellfamilyname)

#### `SpellFamily`

Kind: `enum`

Source: `src/game/Database/DBCEnums.h enum SpellFamily`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `SPELLFAMILY_GENERIC` | Spellfamily Generic |
| `1` | `0x1` | `SPELLFAMILY_UNK1` | events, holidays |
| `3` | `0x3` | `SPELLFAMILY_MAGE` | Spellfamily Mage |
| `4` | `0x4` | `SPELLFAMILY_WARRIOR` | Spellfamily Warrior |
| `5` | `0x5` | `SPELLFAMILY_WARLOCK` | Spellfamily Warlock |
| `6` | `0x6` | `SPELLFAMILY_PRIEST` | Spellfamily Priest |
| `7` | `0x7` | `SPELLFAMILY_DRUID` | Spellfamily Druid |
| `8` | `0x8` | `SPELLFAMILY_ROGUE` | Spellfamily Rogue |
| `9` | `0x9` | `SPELLFAMILY_HUNTER` | Spellfamily Hunter |
| `10` | `0xA` | `SPELLFAMILY_PALADIN` | Spellfamily Paladin |
| `11` | `0xB` | `SPELLFAMILY_SHAMAN` | Spellfamily Shaman |
| `12` | `0xC` | `SPELLFAMILY_UNK2` | Spellfamily Unk2 |
| `13` | `0xD` | `SPELLFAMILY_POTION` | Spellfamily Potion |
| `15` | `0xF` | `SPELLFAMILY_DEATHKNIGHT` | Spellfamily Deathknight |
| `17` | `0x11` | `SPELLFAMILY_UNK3` | Spellfamily Unk3 |

### Unmapped Flag-Like Columns

| Column | Type | Guidance |
| --- | --- | --- |
| [`SpellFamilyMask`](#col-spellfamilymask) | `bigint(20)` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
