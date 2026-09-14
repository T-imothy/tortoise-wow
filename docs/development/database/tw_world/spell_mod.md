---
layout: default
title: spell_mod
---

# spell_mod

World database table `spell_mod`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 38 | latin1 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`Id` | `int(11)` | NO | `PRI` | `0` |  | numeric value; identifier column |
| <a id="col-procchance"></a>`procChance` | `int(11)` | YES |  | `-1` |  | numeric value |
| <a id="col-procflags"></a>`procFlags` | `int(11)` | YES |  | `-1` |  | numeric value; mask/flags column; combine values with bitwise OR; Uses ProcFlags mask values |
| <a id="col-proccharges"></a>`procCharges` | `int(11)` | YES |  | `-1` |  | numeric value |
| <a id="col-durationindex"></a>`DurationIndex` | `int(11)` | YES |  | `-1` |  | numeric value |
| <a id="col-category"></a>`Category` | `int(11)` | YES |  | `-1` |  | numeric value |
| <a id="col-castingtimeindex"></a>`CastingTimeIndex` | `int(11)` | YES |  | `-1` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-stackamount"></a>`StackAmount` | `int(11)` | YES |  | `-1` |  | numeric value |
| <a id="col-spelliconid"></a>`SpellIconID` | `int(11)` | YES |  | `-1` |  | numeric value |
| <a id="col-activeiconid"></a>`activeIconID` | `int(11)` | YES |  | `-1` |  | numeric value |
| <a id="col-manacost"></a>`manaCost` | `int(11)` | YES |  | `-1` |  | numeric value; money/cost value, usually copper |
| <a id="col-attributes"></a>`Attributes` | `int(11)` | YES |  | `-1` |  | numeric value; Uses SpellAttributes mask values |
| <a id="col-attributesex"></a>`AttributesEx` | `int(11)` | YES |  | `-1` |  | numeric value; Uses SpellAttributesEx mask values |
| <a id="col-attributesex2"></a>`AttributesEx2` | `int(11)` | YES |  | `-1` |  | numeric value; Uses SpellAttributesEx2 mask values |
| <a id="col-attributesex3"></a>`AttributesEx3` | `int(11)` | YES |  | `-1` |  | numeric value; Uses SpellAttributesEx3 mask values |
| <a id="col-attributesex4"></a>`AttributesEx4` | `int(11)` | YES |  | `-1` |  | numeric value; Uses SpellAttributesEx4 mask values |
| <a id="col-custom"></a>`Custom` | `int(11)` | YES |  | `0` |  | numeric value; Uses SpellAttributesCustom mask values |
| <a id="col-interruptflags"></a>`InterruptFlags` | `int(11)` | YES |  | `-1` |  | numeric value; mask/flags column; combine values with bitwise OR; Uses SpellInterruptFlags mask values |
| <a id="col-aurainterruptflags"></a>`AuraInterruptFlags` | `int(11)` | YES |  | `-1` |  | numeric value; mask/flags column; combine values with bitwise OR; Uses SpellAuraInterruptFlags mask values |
| <a id="col-channelinterruptflags"></a>`ChannelInterruptFlags` | `int(11)` | YES |  | `-1` |  | numeric value; mask/flags column; combine values with bitwise OR; Uses ChannelInterruptFlags mask values |
| <a id="col-dispel"></a>`Dispel` | `int(11)` | NO |  | `-1` |  | numeric value; Uses DispelType enum values |
| <a id="col-stances"></a>`Stances` | `int(11)` | YES |  | `-1` |  | numeric value |
| <a id="col-stancesnot"></a>`StancesNot` | `int(11)` | YES |  | `-1` |  | numeric value |
| <a id="col-spellvisual"></a>`SpellVisual` | `int(11)` | YES |  | `-1` |  | numeric value |
| <a id="col-manacostpercentage"></a>`ManaCostPercentage` | `int(11)` | YES |  | `-1` |  | numeric value; money/cost value, usually copper |
| <a id="col-startrecoverycategory"></a>`StartRecoveryCategory` | `int(11)` | YES |  | `-1` |  | numeric value |
| <a id="col-startrecoverytime"></a>`StartRecoveryTime` | `int(11)` | YES |  | `-1` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-maxaffectedtargets"></a>`MaxAffectedTargets` | `int(11)` | YES |  | `-1` |  | numeric value |
| <a id="col-maxtargetlevel"></a>`MaxTargetLevel` | `int(11)` | YES |  | `-1` |  | numeric value |
| <a id="col-dmgclass"></a>`DmgClass` | `int(11)` | YES |  | `-1` |  | numeric value; Uses SpellDmgClass enum values |
| <a id="col-rangeindex"></a>`rangeIndex` | `int(11)` | YES |  | `-1` |  | numeric value; Uses SpellRangeIndex enum values |
| <a id="col-recoverytime"></a>`RecoveryTime` | `int(11)` | NO |  | `-1` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-categoryrecoverytime"></a>`CategoryRecoveryTime` | `int(11)` | NO |  | `-1` |  | numeric value; time/delay value; confirm unit in server usage |
| <a id="col-spellfamilyname"></a>`SpellFamilyName` | `int(11)` | NO |  | `-1` |  | numeric value |
| <a id="col-spellfamilyflags"></a>`SpellFamilyFlags` | `bigint(20) unsigned` | YES |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-mechanic"></a>`Mechanic` | `int(11)` | YES |  | `-1` |  | numeric value; Uses Mechanics enum values |
| <a id="col-equippeditemclass"></a>`EquippedItemClass` | `int(11)` | YES |  | `-1` |  | numeric value; Uses ItemClass enum values |
| <a id="col-comment"></a>`Comment` | `varchar(255)` | YES |  | `NULL` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `Id`

numeric value; identifier column.

### `procChance`

numeric value.

### `procFlags`

numeric value; mask/flags column; combine values with bitwise OR.

Value set: `ProcFlags` (mask) from `src/game/Spells/SpellDefines.h enum ProcFlags`.

### `procCharges`

numeric value.

### `DurationIndex`

numeric value.

### `Category`

numeric value.

### `CastingTimeIndex`

numeric value; time/delay value; confirm unit in server usage.

### `StackAmount`

numeric value.

### `SpellIconID`

numeric value.

### `activeIconID`

numeric value.

### `manaCost`

numeric value; money/cost value, usually copper.

### `Attributes`

numeric value.

Value set: `SpellAttributes` (mask) from `src/game/Spells/SpellDefines.h enum SpellAttributes`.

### `AttributesEx`

numeric value.

Value set: `SpellAttributesEx` (mask) from `src/game/Spells/SpellDefines.h enum SpellAttributesEx`.

### `AttributesEx2`

numeric value.

Value set: `SpellAttributesEx2` (mask) from `src/game/Spells/SpellDefines.h enum SpellAttributesEx2`.

### `AttributesEx3`

numeric value.

Value set: `SpellAttributesEx3` (mask) from `src/game/Spells/SpellDefines.h enum SpellAttributesEx3`.

### `AttributesEx4`

numeric value.

Value set: `SpellAttributesEx4` (mask) from `src/game/Spells/SpellDefines.h enum SpellAttributesEx4`.

### `Custom`

numeric value.

Value set: `SpellAttributesCustom` (mask) from `src/game/Spells/SpellDefines.h enum SpellAttributesCustom`.

### `InterruptFlags`

numeric value; mask/flags column; combine values with bitwise OR.

Value set: `SpellInterruptFlags` (mask) from `src/game/Spells/SpellDefines.h enum SpellInterruptFlags`.

### `AuraInterruptFlags`

numeric value; mask/flags column; combine values with bitwise OR.

Value set: `SpellAuraInterruptFlags` (mask) from `src/game/Spells/SpellDefines.h enum SpellAuraInterruptFlags`.

### `ChannelInterruptFlags`

numeric value; mask/flags column; combine values with bitwise OR.

Value set: `ChannelInterruptFlags` (mask) from `src/game/Spells/SpellDefines.h channel interrupt constants`.

### `Dispel`

numeric value.

Value set: `DispelType` (enum) from `src/game/Spells/SpellDefines.h enum DispelType`.

### `Stances`

numeric value.

### `StancesNot`

numeric value.

### `SpellVisual`

numeric value.

### `ManaCostPercentage`

numeric value; money/cost value, usually copper.

### `StartRecoveryCategory`

numeric value.

### `StartRecoveryTime`

numeric value; time/delay value; confirm unit in server usage.

### `MaxAffectedTargets`

numeric value.

### `MaxTargetLevel`

numeric value.

### `DmgClass`

numeric value.

Value set: `SpellDmgClass` (enum) from `src/game/Spells/SpellDefines.h enum SpellDmgClass`.

### `rangeIndex`

numeric value.

Value set: `SpellRangeIndex` (enum) from `src/game/Spells/SpellDefines.h enum SpellRangeIndex`.

### `RecoveryTime`

numeric value; time/delay value; confirm unit in server usage.

### `CategoryRecoveryTime`

numeric value; time/delay value; confirm unit in server usage.

### `SpellFamilyName`

numeric value.

### `SpellFamilyFlags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

### `Mechanic`

numeric value.

Value set: `Mechanics` (enum) from `src/game/Spells/SpellDefines.h enum Mechanics`.

### `EquippedItemClass`

numeric value.

Value set: `ItemClass` (enum) from `src/game/Objects/ItemPrototype.h enum ItemClass`.

### `Comment`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `Id` |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `ChannelInterruptFlags` | mask | [`ChannelInterruptFlags`](#col-channelinterruptflags) | `src/game/Spells/SpellDefines.h channel interrupt constants` | 1 |
| `DispelType` | enum | [`Dispel`](#col-dispel) | `src/game/Spells/SpellDefines.h enum DispelType` | 11 |
| `ItemClass` | enum | [`EquippedItemClass`](#col-equippeditemclass) | `src/game/Objects/ItemPrototype.h enum ItemClass` | 16 |
| `Mechanics` | enum | [`Mechanic`](#col-mechanic) | `src/game/Spells/SpellDefines.h enum Mechanics` | 32 |
| `ProcFlags` | mask | [`procFlags`](#col-procflags) | `src/game/Spells/SpellDefines.h enum ProcFlags` | 24 |
| `SpellAttributes` | mask | [`Attributes`](#col-attributes) | `src/game/Spells/SpellDefines.h enum SpellAttributes` | 32 |
| `SpellAttributesCustom` | mask | [`Custom`](#col-custom) | `src/game/Spells/SpellDefines.h enum SpellAttributesCustom` | 24 |
| `SpellAttributesEx` | mask | [`AttributesEx`](#col-attributesex) | `src/game/Spells/SpellDefines.h enum SpellAttributesEx` | 32 |
| `SpellAttributesEx2` | mask | [`AttributesEx2`](#col-attributesex2) | `src/game/Spells/SpellDefines.h enum SpellAttributesEx2` | 32 |
| `SpellAttributesEx3` | mask | [`AttributesEx3`](#col-attributesex3) | `src/game/Spells/SpellDefines.h enum SpellAttributesEx3` | 32 |
| `SpellAttributesEx4` | mask | [`AttributesEx4`](#col-attributesex4) | `src/game/Spells/SpellDefines.h enum SpellAttributesEx4` | 10 |
| `SpellAuraInterruptFlags` | mask | [`AuraInterruptFlags`](#col-aurainterruptflags) | `src/game/Spells/SpellDefines.h enum SpellAuraInterruptFlags` | 25 |
| `SpellDmgClass` | enum | [`DmgClass`](#col-dmgclass) | `src/game/Spells/SpellDefines.h enum SpellDmgClass` | 4 |
| `SpellInterruptFlags` | mask | [`InterruptFlags`](#col-interruptflags) | `src/game/Spells/SpellDefines.h enum SpellInterruptFlags` | 5 |
| `SpellRangeIndex` | enum | [`rangeIndex`](#col-rangeindex) | `src/game/Spells/SpellDefines.h enum SpellRangeIndex` | 3 |

### Possible Values

Used by: [`ChannelInterruptFlags`](#col-channelinterruptflags)

#### `ChannelInterruptFlags`

Kind: `mask`

Source: `src/game/Spells/SpellDefines.h channel interrupt constants`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `4` | `0x4` | `CHANNEL_FLAG_INTERRUPT` | Interrupt channeled spell |

Used by: [`Dispel`](#col-dispel)

#### `DispelType`

Kind: `enum`

Source: `src/game/Spells/SpellDefines.h enum DispelType`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `DISPEL_NONE` | Dispel None |
| `1` | `0x1` | `DISPEL_MAGIC` | Dispel Magic |
| `2` | `0x2` | `DISPEL_CURSE` | Dispel Curse |
| `3` | `0x3` | `DISPEL_DISEASE` | Dispel Disease |
| `4` | `0x4` | `DISPEL_POISON` | Dispel Poison |
| `5` | `0x5` | `DISPEL_STEALTH` | Dispel Stealth |
| `6` | `0x6` | `DISPEL_INVISIBILITY` | Dispel Invisibility |
| `7` | `0x7` | `DISPEL_ALL` | Dispel All |
| `8` | `0x8` | `DISPEL_SPE_NPC_ONLY` | Dispel Spe Npc Only |
| `9` | `0x9` | `DISPEL_ENRAGE` | Dispel Enrage |
| `10` | `0xA` | `DISPEL_ZG_TICKET` | Dispel Zg Ticket |

Used by: [`EquippedItemClass`](#col-equippeditemclass)

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

Used by: [`Mechanic`](#col-mechanic)

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

Used by: [`procFlags`](#col-procflags)

#### `ProcFlags`

Kind: `mask`

Source: `src/game/Spells/SpellDefines.h enum ProcFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `PROC_FLAG_HEARTBEAT` | On tick |
| `2` | `0x2` | `PROC_FLAG_KILL` | Kill target |
| `4` | `0x4` | `PROC_FLAG_DEAL_MELEE_SWING` | Successful melee auto attack |
| `8` | `0x8` | `PROC_FLAG_TAKE_MELEE_SWING` | Taken melee auto attack hit |
| `16` | `0x10` | `PROC_FLAG_DEAL_MELEE_ABILITY` | Successful melee weapon spell |
| `32` | `0x20` | `PROC_FLAG_TAKE_MELEE_ABILITY` | Taken melee weapon spell damage |
| `64` | `0x40` | `PROC_FLAG_DEAL_RANGED_ATTACK` | Successful ranged auto attack |
| `128` | `0x80` | `PROC_FLAG_TAKE_RANGED_ATTACK` | Taken ranged auto attack |
| `256` | `0x100` | `PROC_FLAG_DEAL_RANGED_ABILITY` | Successful ranged weapon spell |
| `512` | `0x200` | `PROC_FLAG_TAKE_RANGED_ABILITY` | Taken ranged weapon spell damage |
| `1024` | `0x400` | `PROC_FLAG_DEAL_HELPFUL_ABILITY` | Successful positive ability |
| `2048` | `0x800` | `PROC_FLAG_TAKE_HELPFUL_ABILITY` | Taken positive ability |
| `4096` | `0x1000` | `PROC_FLAG_DEAL_HARMFUL_ABILITY` | Successful negative ability |
| `8192` | `0x2000` | `PROC_FLAG_TAKE_HARMFUL_ABILITY` | Taken negative ability |
| `16384` | `0x4000` | `PROC_FLAG_DEAL_HELPFUL_SPELL` | Successful positive spell |
| `32768` | `0x8000` | `PROC_FLAG_TAKE_HELPFUL_SPELL` | Taken positive spell |
| `65536` | `0x10000` | `PROC_FLAG_DEAL_HARMFUL_SPELL` | Successful negative spell |
| `131072` | `0x20000` | `PROC_FLAG_TAKE_HARMFUL_SPELL` | Taken negative spell |
| `262144` | `0x40000` | `PROC_FLAG_DEAL_HARMFUL_PERIODIC` | Successful periodic effect |
| `524288` | `0x80000` | `PROC_FLAG_TAKE_HARMFUL_PERIODIC` | Taken periodic effect |
| `1048576` | `0x100000` | `PROC_FLAG_TAKEN_ANY_DAMAGE` | Taken any damage |
| `2097152` | `0x200000` | `PROC_FLAG_ON_TRAP_ACTIVATION` | On trap activation |
| `4194304` | `0x400000` | `PROC_FLAG_MAIN_HAND_WEAPON_SWING` | Main-hand weapon swing |
| `8388608` | `0x800000` | `PROC_FLAG_OFF_HAND_WEAPON_SWING` | Off-hand weapon swing |

Used by: [`Attributes`](#col-attributes)

#### `SpellAttributes`

Kind: `mask`

Source: `src/game/Spells/SpellDefines.h enum SpellAttributes`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `SPELL_ATTR_DONT_DISPLAY_SPELL_RESULT` | 0 |
| `2` | `0x2` | `SPELL_ATTR_RANGED` | 1 All ranged abilites have this flag |
| `4` | `0x4` | `SPELL_ATTR_ON_NEXT_SWING_1` | 2 on next swing |
| `8` | `0x8` | `SPELL_ATTR_IS_REPLENISHMENT` | 3 not set in 2.4.2 |
| `16` | `0x10` | `SPELL_ATTR_IS_ABILITY` | 4 client puts 'ability' instead of 'spell' in game strings for these spells |
| `32` | `0x20` | `SPELL_ATTR_TRADESPELL` | 5 trade spells, will be added by client to a sublist of profession spell |
| `64` | `0x40` | `SPELL_ATTR_PASSIVE` | 6 Passive spell |
| `128` | `0x80` | `SPELL_ATTR_HIDDEN_CLIENTSIDE` | 7 Spells with this attribute are not visible in spellbook or aura bar |
| `256` | `0x100` | `SPELL_ATTR_HIDE_IN_COMBAT_LOG` | 8 this attributes controls whether spell appears in combat logs |
| `512` | `0x200` | `SPELL_ATTR_TARGET_MAINHAND_ITEM` | 9 Client automatically selects item from mainhand slot as a cast target |
| `1024` | `0x400` | `SPELL_ATTR_ON_NEXT_SWING_2` | 10 on next swing 2 |
| `2048` | `0x800` | `SPELL_ATTR_WEARER_CASTS_PROC_TRIGGER` | 11 |
| `4096` | `0x1000` | `SPELL_ATTR_DAYTIME_ONLY` | 12 only useable at daytime, not set in 2.4.2 |
| `8192` | `0x2000` | `SPELL_ATTR_NIGHT_ONLY` | 13 only useable at night, not set in 2.4.2 |
| `16384` | `0x4000` | `SPELL_ATTR_INDOORS_ONLY` | 14 only useable indoors, not set in 2.4.2 |
| `32768` | `0x8000` | `SPELL_ATTR_OUTDOORS_ONLY` | 15 Only useable outdoors. |
| `65536` | `0x10000` | `SPELL_ATTR_NOT_SHAPESHIFT` | 16 Not while shapeshifted |
| `131072` | `0x20000` | `SPELL_ATTR_ONLY_STEALTHED` | 17 Must be in stealth |
| `262144` | `0x40000` | `SPELL_ATTR_DONT_AFFECT_SHEATH_STATE` | 18 client won't hide unit weapons in sheath on cast/channel |
| `524288` | `0x80000` | `SPELL_ATTR_LEVEL_DAMAGE_CALCULATION` | 19 spelldamage depends on caster level |
| `1048576` | `0x100000` | `SPELL_ATTR_STOP_ATTACK_TARGET` | 20 Stop attack after use this spell (and not begin attack if use) |
| `2097152` | `0x200000` | `SPELL_ATTR_IMPOSSIBLE_DODGE_PARRY_BLOCK` | 21 Cannot be dodged/parried/blocked |
| `4194304` | `0x400000` | `SPELL_ATTR_SET_TRACKING_TARGET` | 22 SetTrackingTarget |
| `8388608` | `0x800000` | `SPELL_ATTR_CASTABLE_WHILE_DEAD` | 23 castable while dead? |
| `16777216` | `0x1000000` | `SPELL_ATTR_CASTABLE_WHILE_MOUNTED` | 24 castable while mounted |
| `33554432` | `0x2000000` | `SPELL_ATTR_DISABLED_WHILE_ACTIVE` | 25 Activate and start cooldown after aura fade or remove summoned creature or go |
| `67108864` | `0x4000000` | `SPELL_ATTR_NEGATIVE` | 26 Almost all negative spell have it |
| `134217728` | `0x8000000` | `SPELL_ATTR_CASTABLE_WHILE_SITTING` | 27 castable while sitting |
| `268435456` | `0x10000000` | `SPELL_ATTR_CANT_USED_IN_COMBAT` | 28 Cannot be used in combat |
| `536870912` | `0x20000000` | `SPELL_ATTR_UNAFFECTED_BY_INVULNERABILITY` | 29 unaffected by invulnerability (hmm possible not...) |
| `1073741824` | `0x40000000` | `SPELL_ATTR_DIMINISHING_RETURNS` | 30 breakable by damage? |
| `2147483648` | `0x80000000` | `SPELL_ATTR_CANT_CANCEL` | 31 positive aura can't be canceled |

Used by: [`Custom`](#col-custom)

#### `SpellAttributesCustom`

Kind: `mask`

Source: `src/game/Spells/SpellDefines.h enum SpellAttributesCustom`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `SPELL_CUSTOM_NONE` | Custom None |
| `1` | `0x1` | `SPELL_CUSTOM_ALLOW_STACK_BETWEEN_CASTER` | For example 'Siphon Soul' must be able to stack between the warlocks on a mob |
| `2` | `0x2` | `SPELL_CUSTOM_NEGATIVE` | Custom Negative |
| `4` | `0x4` | `SPELL_CUSTOM_POSITIVE` | Custom Positive |
| `16` | `0x10` | `SPELL_CUSTOM_FIXED_DAMAGE` | Not affected by damage/healing done bonus |
| `32` | `0x20` | `SPELL_CUSTOM_IGNORE_ARMOR` | Custom Ignore Armor |
| `64` | `0x40` | `SPELL_CUSTOM_BEHIND_TARGET` | For spells that require the caster to be behind the target |
| `128` | `0x80` | `SPELL_CUSTOM_FACE_TARGET` | For spells that require the target to be in front of the caster |
| `256` | `0x100` | `SPELL_CUSTOM_SINGLE_TARGET_AURA` | Aura applied by spell can only be on 1 target at a time |
| `512` | `0x200` | `SPELL_CUSTOM_AURA_APPLY_BREAKS_STEALTH` | Stealth is removed when this aura is applied |
| `1024` | `0x400` | `SPELL_CUSTOM_NOT_REMOVED_ON_EVADE` | Aura persists after creature evades |
| `2048` | `0x800` | `SPELL_CUSTOM_SEND_CHANNEL_VISUAL` | Will periodically send the channeling spell visual kit |
| `4096` | `0x1000` | `SPELL_CUSTOM_PERSISTENT_NO_STACK` | Makes persistent area auras not stack between casters |
| `8192` | `0x2000` | `SPELL_CUSTOM_DEATH_DUNGEON_PERSISTENT` | Custom Death Dungeon Persistent |
| `16384` | `0x4000` | `SPELL_CUSTOM_STACK_WITH_SPELL_SPECIFIC` | Stacks with other auras from caster with same spell specific type |
| `32768` | `0x8000` | `SPELL_CUSTOM_TRIGGER_WEAPON_PROCS` | Can trigger weapon enchants and on hit effects |
| `65536` | `0x10000` | `SPELL_CUSTOM_AURA_NON_EXCLUSIVE` | Aura stacks with normally exclusive auras |
| `131072` | `0x20000` | `SPELL_CUSTOM_AURA_EXCLUSIVE` | Aura is always treated as exclusive |
| `262144` | `0x40000` | `SPELL_CUSTOM_MOUNT_SPEED_100` | Mount aura is always normalized to 100% speed |
| `524288` | `0x80000` | `SPELL_CUSTOM_IGNORE_RIDING_SKILL_MOUNT_SPEED` | Mount aura keeps DBC speed amount |
| `1048576` | `0x100000` | `SPELL_CUSTOM_TEMPORARY_HEALTH_BONUS` | Increases max health and current health together |
| `2097152` | `0x200000` | `SPELL_CUSTOM_AURA_STACKS_WITH_EXCLUSIVE` | Aura stacks with normally exclusive aura categories |
| `4194304` | `0x400000` | `SPELL_CUSTOM_AURA_EFFECT0_STACKS_WITH_EXCLUSIVE` | Effect 0 stacks with normally exclusive aura categories |
| `8388608` | `0x800000` | `SPELL_CUSTOM_BONUS_COEFF_USES_AP` | Uses attack power instead of spell power for effectBonusCoefficient |

Used by: [`AttributesEx`](#col-attributesex)

#### `SpellAttributesEx`

Kind: `mask`

Source: `src/game/Spells/SpellDefines.h enum SpellAttributesEx`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `SPELL_ATTR_EX_DISMISS_PET` | 0 for spells without this flag client doesn't allow to summon pet if caster has a pet |
| `2` | `0x2` | `SPELL_ATTR_EX_DRAIN_ALL_POWER` | 1 use all power (Only paladin Lay of Hands and Bunyanize) |
| `4` | `0x4` | `SPELL_ATTR_EX_CHANNELED_1` | 2 channeled 1 |
| `8` | `0x8` | `SPELL_ATTR_EX_CANT_BE_REDIRECTED` | 3 |
| `16` | `0x10` | `SPELL_ATTR_EX_UNK4` | 4 |
| `32` | `0x20` | `SPELL_ATTR_EX_NOT_BREAK_STEALTH` | 5 Not break stealth |
| `64` | `0x40` | `SPELL_ATTR_EX_CHANNELED_2` | 6 channeled 2 |
| `128` | `0x80` | `SPELL_ATTR_EX_CANT_BE_REFLECTED` | 7 |
| `256` | `0x100` | `SPELL_ATTR_EX_NOT_IN_COMBAT_TARGET` | 8 Spell req target not to be in combat state |
| `512` | `0x200` | `SPELL_ATTR_EX_MELEE_COMBAT_START` | 9 player starts melee combat after this spell is cast |
| `1024` | `0x400` | `SPELL_ATTR_EX_NO_THREAT` | 10 no generates threat on cast 100% |
| `2048` | `0x800` | `SPELL_ATTR_EX_UNK11` | 11 |
| `4096` | `0x1000` | `SPELL_ATTR_EX_IS_PICKPOCKET` | 12 |
| `8192` | `0x2000` | `SPELL_ATTR_EX_FARSIGHT` | 13 |
| `16384` | `0x4000` | `SPELL_ATTR_EX_CHANNEL_TRACK_TARGET` | 14 Client automatically forces player to face target when channeling |
| `32768` | `0x8000` | `SPELL_ATTR_EX_DISPEL_AURAS_ON_IMMUNITY` | 15 remove auras on immunity |
| `65536` | `0x10000` | `SPELL_ATTR_EX_IMMUNITY_TO_HOSTILE_AND_FRIENDLY_EFFECTS` | 16 aura that provides immunity prevents positive effects too |
| `131072` | `0x20000` | `SPELL_ATTR_EX_NOT_RESET_AUTO_ACTIONS` | 17 for auras SPELL_AURA_TRACK_CREATURES, SPELL_AURA_TRACK_RESOURCES and SPELL_AURA_TRACK_STEALTHED select non-stacking tracking spells |
| `262144` | `0x40000` | `SPELL_ATTR_EX_UNK18` | 18 stun, polymorph, daze, sleep |
| `524288` | `0x80000` | `SPELL_ATTR_EX_CANT_TARGET_SELF` | 19 |
| `1048576` | `0x100000` | `SPELL_ATTR_EX_REQ_TARGET_COMBO_POINTS` | 20 Req combo points on target |
| `2097152` | `0x200000` | `SPELL_ATTR_EX_THREAT_ONLY_ON_MISS` | 21 |
| `4194304` | `0x400000` | `SPELL_ATTR_EX_REQ_COMBO_POINTS` | 22 Use combo points (in 4.x not required combo point target selected) |
| `8388608` | `0x800000` | `SPELL_ATTR_EX_UNK23` | 23 |
| `16777216` | `0x1000000` | `SPELL_ATTR_EX_IS_FISHING` | 24 only fishing spells |
| `33554432` | `0x2000000` | `SPELL_ATTR_EX_UNK25` | 25 not set in 2.4.2 |
| `67108864` | `0x4000000` | `SPELL_ATTR_EX_UNK26` | 26 |
| `134217728` | `0x8000000` | `SPELL_ATTR_EX_REFUND_POWER` | 27 All these spells refund power on parry or deflect |
| `268435456` | `0x10000000` | `SPELL_ATTR_EX_DONT_DISPLAY_IN_AURA_BAR` | 28 client doesn't display these spells in aura bar |
| `536870912` | `0x20000000` | `SPELL_ATTR_EX_CHANNEL_DISPLAY_SPELL_NAME` | 29 spell name is displayed in cast bar instead of 'channeling' text |
| `1073741824` | `0x40000000` | `SPELL_ATTR_EX_ENABLE_AT_DODGE` | 30 Overpower |
| `2147483648` | `0x80000000` | `SPELL_ATTR_EX_UNK31` | 31 |

Used by: [`AttributesEx2`](#col-attributesex2)

#### `SpellAttributesEx2`

Kind: `mask`

Source: `src/game/Spells/SpellDefines.h enum SpellAttributesEx2`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `SPELL_ATTR_EX2_CAN_TARGET_DEAD` | 0 can target dead unit or corpse |
| `2` | `0x2` | `SPELL_ATTR_EX2_UNK1` | 1 |
| `4` | `0x4` | `SPELL_ATTR_EX2_IGNORE_LOS` | 2 ? used for detect can or not spell reflected // do not need LOS (e.g. 18220 since 3.3.3) |
| `8` | `0x8` | `SPELL_ATTR_EX2_UNK3` | 3 auto targeting? (e.g. fishing skill enhancement items since 3.3.3) |
| `16` | `0x10` | `SPELL_ATTR_EX2_DISPLAY_IN_STANCE_BAR` | 4 client displays icon in stance bar when learned, even if not shapeshift |
| `32` | `0x20` | `SPELL_ATTR_EX2_AUTOREPEAT_FLAG` | 5 |
| `64` | `0x40` | `SPELL_ATTR_EX2_CANT_TARGET_TAPPED` | 6 target must be tapped by caster |
| `128` | `0x80` | `SPELL_ATTR_EX2_UNK7` | 7 |
| `256` | `0x100` | `SPELL_ATTR_EX2_UNK8` | 8 not set in 2.4.2 |
| `512` | `0x200` | `SPELL_ATTR_EX2_UNK9` | 9 |
| `1024` | `0x400` | `SPELL_ATTR_EX2_UNK10` | 10 |
| `2048` | `0x800` | `SPELL_ATTR_EX2_HEALTH_FUNNEL` | 11 |
| `4096` | `0x1000` | `SPELL_ATTR_EX2_UNK12` | 12 |
| `8192` | `0x2000` | `SPELL_ATTR_EX2_PRESERVE_ENCHANT_IN_ARENA` | 13 Items enchanted by spells with this flag preserve the enchant to arenas |
| `16384` | `0x4000` | `SPELL_ATTR_EX2_ALLOW_WHILE_INVISIBLE` | 14 |
| `32768` | `0x8000` | `SPELL_ATTR_EX2_UNK15` | 15 not set in 2.4.2 |
| `65536` | `0x10000` | `SPELL_ATTR_EX2_TAME_BEAST` | 16 |
| `131072` | `0x20000` | `SPELL_ATTR_EX2_NOT_RESET_AUTO_ACTIONS` | 17 don't reset timers for melee autoattacks (swings) or ranged autoattacks (autoshoots) |
| `262144` | `0x40000` | `SPELL_ATTR_EX2_REQ_DEAD_PET` | 18 Only Revive pet |
| `524288` | `0x80000` | `SPELL_ATTR_EX2_NOT_NEED_SHAPESHIFT` | 19 does not necessary need shapeshift (pre-3.x not have passive spells with this attribute) |
| `1048576` | `0x100000` | `SPELL_ATTR_EX2_UNK20` | 20 |
| `2097152` | `0x200000` | `SPELL_ATTR_EX2_DAMAGE_REDUCED_SHIELD` | 21 for ice blocks, pala immunity buffs, priest absorb shields, but used also for other spells -&gt; not sure! |
| `4194304` | `0x400000` | `SPELL_ATTR_EX2_NO_INITIAL_THREAT` | 22 |
| `8388608` | `0x800000` | `SPELL_ATTR_EX2_PROC_COOLDOWN_ON_FAILURE` | 23 |
| `16777216` | `0x1000000` | `SPELL_ATTR_EX2_UNK24` | 24 |
| `33554432` | `0x2000000` | `SPELL_ATTR_EX2_UNK25` | 25 |
| `67108864` | `0x4000000` | `SPELL_ATTR_EX2_NO_SCHOOL_IMMUNITIES` | 26 |
| `134217728` | `0x8000000` | `SPELL_ATTR_EX2_UNK27` | 27 |
| `268435456` | `0x10000000` | `SPELL_ATTR_EX2_NOT_AN_ACTION` | 28 no breaks stealth if it fails?? |
| `536870912` | `0x20000000` | `SPELL_ATTR_EX2_CANT_CRIT` | 29 Spell can't crit |
| `1073741824` | `0x40000000` | `SPELL_ATTR_EX2_ACTIVE_THREAT` | 30 NYI - has some sort of active threat component like fire nova totem |
| `2147483648` | `0x80000000` | `SPELL_ATTR_EX2_FOOD_BUFF` | 31 Food or Drink Buff (like Well Fed) |

Used by: [`AttributesEx3`](#col-attributesex3)

#### `SpellAttributesEx3`

Kind: `mask`

Source: `src/game/Spells/SpellDefines.h enum SpellAttributesEx3`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `SPELL_ATTR_EX3_PVP_ENABLING` | 0 Spell landed counts as hostile action against enemy even if it doesn't trigger combat state, propagates PvP flags |
| `2` | `0x2` | `SPELL_ATTR_EX3_NO_PROC_EQUIP_REQUIREMENT` | 1 |
| `4` | `0x4` | `SPELL_ATTR_EX3_NO_CASTING_BAR_TEXT` | 2 |
| `8` | `0x8` | `SPELL_ATTR_EX3_COMPLETELY_BLOCKED` | 3 All effects prevented on block |
| `16` | `0x10` | `SPELL_ATTR_EX3_NO_RES_TIMER` | 4 Corpse reclaim delay does not apply to accepting resurrection |
| `32` | `0x20` | `SPELL_ATTR_EX3_NO_DURABILITY_LOSS` | 5 |
| `64` | `0x40` | `SPELL_ATTR_EX3_NO_AVOIDANCE` | 6 Persistent Area Aura not removed on leaving radius |
| `128` | `0x80` | `SPELL_ATTR_EX3_DOT_STACKING_RULE` | 7 Create a separate (de)buff stack for each caster |
| `256` | `0x100` | `SPELL_ATTR_EX3_ONLY_ON_PLAYER` | 8 Can target only players |
| `512` | `0x200` | `SPELL_ATTR_EX3_NOT_A_PROC` | 9 Aura periodic trigger is not evaluated as triggered |
| `1024` | `0x400` | `SPELL_ATTR_EX3_REQUIRES_MAIN_HAND_WEAPON` | 10 |
| `2048` | `0x800` | `SPELL_ATTR_EX3_ONLY_BATTLEGROUNDS` | 11 |
| `4096` | `0x1000` | `SPELL_ATTR_EX3_ONLY_ON_GHOSTS` | 12 |
| `8192` | `0x2000` | `SPELL_ATTR_EX3_HIDE_CHANNEL_BAR` | 13 Client will not display channeling bar |
| `16384` | `0x4000` | `SPELL_ATTR_EX3_HIDE_IN_RAID_FILTER` | 14 Only "Honorless Target" has this flag |
| `32768` | `0x8000` | `SPELL_ATTR_EX3_NORMAL_RANGED_ATTACK` | 15 Spells with this attribute are processed as ranged attacks in client |
| `65536` | `0x10000` | `SPELL_ATTR_EX3_SUPPRESS_CASTER_PROCS` | 16 |
| `131072` | `0x20000` | `SPELL_ATTR_EX3_SUPPRESS_TARGET_PROCS` | 17 |
| `262144` | `0x40000` | `SPELL_ATTR_EX3_ALWAYS_HIT` | 18 Spell should always hit its target |
| `524288` | `0x80000` | `SPELL_ATTR_EX3_INSTANT_TARGET_PROCS` | 19 Related to spell batching - not an issue for us |
| `1048576` | `0x100000` | `SPELL_ATTR_EX3_ALLOW_AURA_WHILE_DEAD` | 20 Death persistent spells |
| `2097152` | `0x200000` | `SPELL_ATTR_EX3_ONLY_PROC_OUTDOORS` | 21 |
| `4194304` | `0x400000` | `SPELL_ATTR_EX3_CASTING_CANCELS_AUTOREPEAT` | 22 NYI (only Shoot with Wand has it) |
| `8388608` | `0x800000` | `SPELL_ATTR_EX3_NO_DAMAGE_HISTORY` | 23 NYI |
| `16777216` | `0x1000000` | `SPELL_ATTR_EX3_REQUIRES_OFFHAND_WEAPON` | 24 |
| `33554432` | `0x2000000` | `SPELL_ATTR_EX3_TREAT_AS_PERIODIC` | 25 Does not cause spell pushback |
| `67108864` | `0x4000000` | `SPELL_ATTR_EX3_CAN_PROC_FROM_PROCS` | 26 Auras with this attribute can proc off procced spells (periodic triggers etc) |
| `134217728` | `0x8000000` | `SPELL_ATTR_EX3_ONLY_PROC_ON_CASTER` | 27 |
| `268435456` | `0x10000000` | `SPELL_ATTR_EX3_IGNORE_CASTER_AND_TARGET_RESTRICTIONS` | 28 NYI |
| `536870912` | `0x20000000` | `SPELL_ATTR_EX3_IGNORE_CASTER_MODIFIERS` | 29 |
| `1073741824` | `0x40000000` | `SPELL_ATTR_EX3_DO_NOT_DISPLAY_RANGE` | 30 |
| `2147483648` | `0x80000000` | `SPELL_ATTR_EX3_NOT_ON_AOE_IMMUNE` | 31 |

Used by: [`AttributesEx4`](#col-attributesex4)

#### `SpellAttributesEx4`

Kind: `mask`

Source: `src/game/Spells/SpellDefines.h enum SpellAttributesEx4`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `SPELL_ATTR_EX4_IGNORE_RESISTANCES` | 0 From TC 3.3.5, but not present in 1.12 native DBCs. Add it with spell_mod to prevent a spell from being resisted. |
| `2` | `0x2` | `SPELL_ATTR_EX4_CLASS_TRIGGER_ONLY_ON_TARGET` | 1 |
| `4` | `0x4` | `SPELL_ATTR_EX4_AURA_EXPIRES_OFFLINE` | 2 Aura continues to expire while player is offline |
| `8` | `0x8` | `SPELL_ATTR_EX4_NO_HELPFUL_THREAT` | 3 |
| `16` | `0x10` | `SPELL_ATTR_EX4_NO_HARMFUL_THREAT` | 4 |
| `32` | `0x20` | `SPELL_ATTR_EX4_ALLOW_CLIENT_TARGETING` | 5 NYI |
| `64` | `0x40` | `SPELL_ATTR_EX4_CANNOT_BE_STOLEN` | 6 Unused |
| `128` | `0x80` | `SPELL_ATTR_EX4_CAN_CAST_WHILE_CASTING` | 7 NYI (does not seem to work client side either) |
| `256` | `0x100` | `SPELL_ATTR_EX4_IGNORE_DAMAGE_TAKEN_MODIFIERS` | 8 |
| `512` | `0x200` | `SPELL_ATTR_EX4_COMBAT_FEEDBACK_WHEN_USABLE` | 9 Initially disabled / Trigger activate from event (Execute, Riposte, Deep Freeze...) |

Used by: [`AuraInterruptFlags`](#col-aurainterruptflags)

#### `SpellAuraInterruptFlags`

Kind: `mask`

Source: `src/game/Spells/SpellDefines.h enum SpellAuraInterruptFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `AURA_INTERRUPT_FLAG_HITBYSPELL` | Removed when hit by negative spell |
| `2` | `0x2` | `AURA_INTERRUPT_FLAG_DAMAGE` | Removed by any damage |
| `4` | `0x4` | `AURA_INTERRUPT_FLAG_CAST` | Removed on cast |
| `8` | `0x8` | `AURA_INTERRUPT_FLAG_MOVE` | Removed by movement |
| `16` | `0x10` | `AURA_INTERRUPT_FLAG_TURNING` | Removed by turning |
| `32` | `0x20` | `AURA_INTERRUPT_FLAG_ENTER_COMBAT` | Removed on entering combat |
| `64` | `0x40` | `AURA_INTERRUPT_FLAG_NOT_MOUNTED` | Removed by unmounting |
| `128` | `0x80` | `AURA_INTERRUPT_FLAG_NOT_ABOVEWATER` | Removed by entering water |
| `256` | `0x100` | `AURA_INTERRUPT_FLAG_NOT_UNDERWATER` | Removed by leaving water |
| `512` | `0x200` | `AURA_INTERRUPT_FLAG_NOT_SHEATHED` | Removed by unsheathing |
| `1024` | `0x400` | `AURA_INTERRUPT_FLAG_TALK` | Removed on NPC interaction |
| `2048` | `0x800` | `AURA_INTERRUPT_FLAG_USE` | Removed on gameobject interaction |
| `4096` | `0x1000` | `AURA_INTERRUPT_FLAG_MELEE_ATTACK` | Removed by melee attack |
| `8192` | `0x2000` | `AURA_INTERRUPT_FLAG_SPELL_ATTACK` | Removed by spell attack |
| `16384` | `0x4000` | `AURA_INTERRUPT_FLAG_UNK14` | Unused in 1.12 |
| `32768` | `0x8000` | `AURA_INTERRUPT_FLAG_TRANSFORM` | Removed by transform/cast behavior |
| `65536` | `0x10000` | `AURA_INTERRUPT_FLAG_ON_CAST_SPELL` | Removed on casting spell |
| `131072` | `0x20000` | `AURA_INTERRUPT_FLAG_MOUNTING` | Removed by mounting |
| `262144` | `0x40000` | `AURA_INTERRUPT_FLAG_NOT_SEATED` | Removed by standing up |
| `524288` | `0x80000` | `AURA_INTERRUPT_FLAG_CHANGE_MAP` | Removed by map change or teleport |
| `1048576` | `0x100000` | `AURA_INTERRUPT_FLAG_IMMUNE_OR_LOST_SELECTION` | Removed by immunity or lost selection |
| `2097152` | `0x200000` | `AURA_INTERRUPT_FLAG_UNK21` | Unknown |
| `4194304` | `0x400000` | `AURA_INTERRUPT_FLAG_TELEPORTED` | Removed by teleport |
| `8388608` | `0x800000` | `AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT` | Removed by entering PvP combat |
| `16777216` | `0x1000000` | `AURA_INTERRUPT_FLAG_DIRECT_DAMAGE` | Removed by direct damage |

Used by: [`DmgClass`](#col-dmgclass)

#### `SpellDmgClass`

Kind: `enum`

Source: `src/game/Spells/SpellDefines.h enum SpellDmgClass`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `SPELL_DAMAGE_CLASS_NONE` | Damage Class None |
| `1` | `0x1` | `SPELL_DAMAGE_CLASS_MAGIC` | Damage Class Magic |
| `2` | `0x2` | `SPELL_DAMAGE_CLASS_MELEE` | Damage Class Melee |
| `3` | `0x3` | `SPELL_DAMAGE_CLASS_RANGED` | Damage Class Ranged |

Used by: [`InterruptFlags`](#col-interruptflags)

#### `SpellInterruptFlags`

Kind: `mask`

Source: `src/game/Spells/SpellDefines.h enum SpellInterruptFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `SPELL_INTERRUPT_FLAG_MOVEMENT` | Interrupted by movement |
| `2` | `0x2` | `SPELL_INTERRUPT_FLAG_DAMAGE` | Interrupted by damage |
| `4` | `0x4` | `SPELL_INTERRUPT_FLAG_INTERRUPT` | Interrupted by interrupt effects |
| `8` | `0x8` | `SPELL_INTERRUPT_FLAG_AUTOATTACK` | Resets auto attack |
| `16` | `0x10` | `SPELL_INTERRUPT_FLAG_ABORT_ON_DMG` | Complete interrupt on direct damage |

Used by: [`rangeIndex`](#col-rangeindex)

#### `SpellRangeIndex`

Kind: `enum`

Source: `src/game/Spells/SpellDefines.h enum SpellRangeIndex`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `SPELL_RANGE_IDX_SELF_ONLY` | 0.0 |
| `2` | `0x2` | `SPELL_RANGE_IDX_COMBAT` | often ~5.5 (but infact dynamic melee combat range) |
| `13` | `0xD` | `SPELL_RANGE_IDX_ANYWHERE` | 500000 (anywhere) |

### Unmapped Flag-Like Columns

| Column | Type | Guidance |
| --- | --- | --- |
| [`SpellFamilyFlags`](#col-spellfamilyflags) | `bigint(20) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
