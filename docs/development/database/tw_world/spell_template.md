---
layout: default
title: spell_template
---

# spell_template

World database table `spell_template`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 149 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-school"></a>`school` | `int(10) unsigned` | NO |  | `0` |  | Resistances.dbc; non-negative numeric value; Uses SpellSchools enum values |
| <a id="col-category"></a>`category` | `int(10) unsigned` | NO |  | `0` |  | SpellCategory.dbc; non-negative numeric value |
| <a id="col-castui"></a>`castUI` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-dispel"></a>`dispel` | `int(10) unsigned` | NO |  | `0` |  | SpellDispelType.dbc; non-negative numeric value; Uses DispelType enum values |
| <a id="col-mechanic"></a>`mechanic` | `int(10) unsigned` | NO |  | `0` |  | SpellMechanic.dbc; non-negative numeric value; Uses Mechanics enum values |
| <a id="col-attributes"></a>`attributes` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellAttributes mask values |
| <a id="col-attributesex"></a>`attributesEx` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellAttributesEx mask values |
| <a id="col-attributesex2"></a>`attributesEx2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellAttributesEx2 mask values |
| <a id="col-attributesex3"></a>`attributesEx3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellAttributesEx3 mask values |
| <a id="col-attributesex4"></a>`attributesEx4` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellAttributesEx4 mask values |
| <a id="col-stances"></a>`stances` | `int(10) unsigned` | NO |  | `0` |  | SpellShapeshiftForm.dbc; non-negative numeric value |
| <a id="col-stancesnot"></a>`stancesNot` | `int(10) unsigned` | NO |  | `0` |  | SpellShapeshiftForm.dbc; non-negative numeric value |
| <a id="col-targets"></a>`targets` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellCastTargetFlags mask values |
| <a id="col-targetcreaturetype"></a>`targetCreatureType` | `int(10) unsigned` | NO |  | `0` |  | CreatureType.dbc; non-negative numeric value |
| <a id="col-requiresspellfocus"></a>`requiresSpellFocus` | `int(10) unsigned` | NO |  | `0` |  | SpellFocusObject.dbc; non-negative numeric value |
| <a id="col-casteraurastate"></a>`casterAuraState` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses AuraState enum values |
| <a id="col-targetaurastate"></a>`targetAuraState` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses AuraState enum values |
| <a id="col-castingtimeindex"></a>`castingTimeIndex` | `int(10) unsigned` | NO |  | `0` |  | SpellCastTimes.dbc; non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-recoverytime"></a>`recoveryTime` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-categoryrecoverytime"></a>`categoryRecoveryTime` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-interruptflags"></a>`interruptFlags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses SpellInterruptFlags mask values |
| <a id="col-aurainterruptflags"></a>`auraInterruptFlags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses SpellAuraInterruptFlags mask values |
| <a id="col-channelinterruptflags"></a>`channelInterruptFlags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses ChannelInterruptFlags mask values |
| <a id="col-procflags"></a>`procFlags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses ProcFlags mask values |
| <a id="col-procchance"></a>`procChance` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-proccharges"></a>`procCharges` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-maxlevel"></a>`maxLevel` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-baselevel"></a>`baseLevel` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spelllevel"></a>`spellLevel` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-durationindex"></a>`durationIndex` | `int(10) unsigned` | NO |  | `0` |  | SpellDuration.dbc; non-negative numeric value |
| <a id="col-powertype"></a>`powerType` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Powers enum values |
| <a id="col-manacost"></a>`manaCost` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-mancostperlevel"></a>`manCostPerLevel` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-manapersecond"></a>`manaPerSecond` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-manapersecondperlevel"></a>`manaPerSecondPerLevel` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rangeindex"></a>`rangeIndex` | `int(10) unsigned` | NO |  | `0` |  | SpellRange.dbc; non-negative numeric value; Uses SpellRangeIndex enum values |
| <a id="col-speed"></a>`speed` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-modelnextspell"></a>`modelNextSpell` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-stackamount"></a>`stackAmount` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-totem1"></a>`totem1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-totem2"></a>`totem2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reagent1"></a>`reagent1` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-reagent2"></a>`reagent2` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-reagent3"></a>`reagent3` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-reagent4"></a>`reagent4` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-reagent5"></a>`reagent5` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-reagent6"></a>`reagent6` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-reagent7"></a>`reagent7` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-reagent8"></a>`reagent8` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-reagentcount1"></a>`reagentCount1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reagentcount2"></a>`reagentCount2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reagentcount3"></a>`reagentCount3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reagentcount4"></a>`reagentCount4` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reagentcount5"></a>`reagentCount5` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reagentcount6"></a>`reagentCount6` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reagentcount7"></a>`reagentCount7` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reagentcount8"></a>`reagentCount8` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-equippeditemclass"></a>`equippedItemClass` | `int(11)` | NO |  | `0` |  | ItemClass.dbc; numeric value; Uses ItemClass enum values |
| <a id="col-equippeditemsubclassmask"></a>`equippedItemSubClassMask` | `int(11)` | NO |  | `0` |  | ItemSubClass.dbc; numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-equippediteminventorytypemask"></a>`equippedItemInventoryTypeMask` | `int(11)` | NO |  | `0` |  | numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-effect1"></a>`effect1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellEffects enum values |
| <a id="col-effect2"></a>`effect2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellEffects enum values |
| <a id="col-effect3"></a>`effect3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellEffects enum values |
| <a id="col-effectdiesides1"></a>`effectDieSides1` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-effectdiesides2"></a>`effectDieSides2` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-effectdiesides3"></a>`effectDieSides3` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-effectbasedice1"></a>`effectBaseDice1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-effectbasedice2"></a>`effectBaseDice2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-effectbasedice3"></a>`effectBaseDice3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-effectdiceperlevel1"></a>`effectDicePerLevel1` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-effectdiceperlevel2"></a>`effectDicePerLevel2` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-effectdiceperlevel3"></a>`effectDicePerLevel3` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-effectrealpointsperlevel1"></a>`effectRealPointsPerLevel1` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-effectrealpointsperlevel2"></a>`effectRealPointsPerLevel2` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-effectrealpointsperlevel3"></a>`effectRealPointsPerLevel3` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-effectbasepoints1"></a>`effectBasePoints1` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-effectbasepoints2"></a>`effectBasePoints2` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-effectbasepoints3"></a>`effectBasePoints3` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-effectbonuscoefficient1"></a>`effectBonusCoefficient1` | `float` | NO |  | `-1` |  | numeric value |
| <a id="col-effectbonuscoefficient2"></a>`effectBonusCoefficient2` | `float` | NO |  | `-1` |  | numeric value |
| <a id="col-effectbonuscoefficient3"></a>`effectBonusCoefficient3` | `float` | NO |  | `-1` |  | numeric value |
| <a id="col-effectmechanic1"></a>`effectMechanic1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Mechanics enum values |
| <a id="col-effectmechanic2"></a>`effectMechanic2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Mechanics enum values |
| <a id="col-effectmechanic3"></a>`effectMechanic3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Mechanics enum values |
| <a id="col-effectimplicittargeta1"></a>`effectImplicitTargetA1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellTarget enum values |
| <a id="col-effectimplicittargeta2"></a>`effectImplicitTargetA2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellTarget enum values |
| <a id="col-effectimplicittargeta3"></a>`effectImplicitTargetA3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellTarget enum values |
| <a id="col-effectimplicittargetb1"></a>`effectImplicitTargetB1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellTarget enum values |
| <a id="col-effectimplicittargetb2"></a>`effectImplicitTargetB2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellTarget enum values |
| <a id="col-effectimplicittargetb3"></a>`effectImplicitTargetB3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellTarget enum values |
| <a id="col-effectradiusindex1"></a>`effectRadiusIndex1` | `int(10) unsigned` | NO |  | `0` |  | SpellRadius.dbc; non-negative numeric value |
| <a id="col-effectradiusindex2"></a>`effectRadiusIndex2` | `int(10) unsigned` | NO |  | `0` |  | SpellRadius.dbc; non-negative numeric value |
| <a id="col-effectradiusindex3"></a>`effectRadiusIndex3` | `int(10) unsigned` | NO |  | `0` |  | SpellRadius.dbc; non-negative numeric value |
| <a id="col-effectapplyauraname1"></a>`effectApplyAuraName1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses AuraType enum values |
| <a id="col-effectapplyauraname2"></a>`effectApplyAuraName2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses AuraType enum values |
| <a id="col-effectapplyauraname3"></a>`effectApplyAuraName3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses AuraType enum values |
| <a id="col-effectamplitude1"></a>`effectAmplitude1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-effectamplitude2"></a>`effectAmplitude2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-effectamplitude3"></a>`effectAmplitude3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-effectmultiplevalue1"></a>`effectMultipleValue1` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-effectmultiplevalue2"></a>`effectMultipleValue2` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-effectmultiplevalue3"></a>`effectMultipleValue3` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-effectchaintarget1"></a>`effectChainTarget1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-effectchaintarget2"></a>`effectChainTarget2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-effectchaintarget3"></a>`effectChainTarget3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-effectitemtype1"></a>`effectItemType1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-effectitemtype2"></a>`effectItemType2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-effectitemtype3"></a>`effectItemType3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-effectmiscvalue1"></a>`effectMiscValue1` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-effectmiscvalue2"></a>`effectMiscValue2` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-effectmiscvalue3"></a>`effectMiscValue3` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-effecttriggerspell1"></a>`effectTriggerSpell1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-effecttriggerspell2"></a>`effectTriggerSpell2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-effecttriggerspell3"></a>`effectTriggerSpell3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-effectpointspercombopoint1"></a>`effectPointsPerComboPoint1` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-effectpointspercombopoint2"></a>`effectPointsPerComboPoint2` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-effectpointspercombopoint3"></a>`effectPointsPerComboPoint3` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-spellvisual1"></a>`spellVisual1` | `int(10) unsigned` | NO |  | `0` |  | SpellVisual.dbc; non-negative numeric value |
| <a id="col-spellvisual2"></a>`spellVisual2` | `int(10) unsigned` | NO |  | `0` |  | SpellVisual.dbc; non-negative numeric value |
| <a id="col-spelliconid"></a>`spellIconId` | `int(10) unsigned` | NO |  | `0` |  | SpellIcon.dbc; non-negative numeric value |
| <a id="col-activeiconid"></a>`activeIconId` | `int(10) unsigned` | NO |  | `0` |  | SpellIcon.dbc; non-negative numeric value |
| <a id="col-spellpriority"></a>`spellPriority` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-name"></a>`name` | `varchar(256)` | NO |  | `''` |  | text/string data |
| <a id="col-nameflags"></a>`nameFlags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-namesubtext"></a>`nameSubtext` | `varchar(256)` | NO |  | `''` |  | text/string data |
| <a id="col-namesubtextflags"></a>`nameSubtextFlags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-description"></a>`description` | `varchar(1024)` | NO |  | `''` |  | text/string data; script id or script name |
| <a id="col-descriptionflags"></a>`descriptionFlags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; script id or script name |
| <a id="col-auradescription"></a>`auraDescription` | `varchar(512)` | NO |  | `''` |  | text/string data; script id or script name |
| <a id="col-auradescriptionflags"></a>`auraDescriptionFlags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; script id or script name |
| <a id="col-manacostpercentage"></a>`manaCostPercentage` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-startrecoverycategory"></a>`startRecoveryCategory` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-startrecoverytime"></a>`startRecoveryTime` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-mintargetlevel"></a>`minTargetLevel` | `int(10) unsigned` | NO |  | `0` |  | Custom Field; non-negative numeric value |
| <a id="col-maxtargetlevel"></a>`maxTargetLevel` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-spellfamilyname"></a>`spellFamilyName` | `int(10) unsigned` | NO |  | `0` |  | ChrClasses.dbc; non-negative numeric value |
| <a id="col-spellfamilyflags"></a>`spellFamilyFlags` | `bigint(20) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-maxaffectedtargets"></a>`maxAffectedTargets` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-dmgclass"></a>`dmgClass` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellDmgClass enum values |
| <a id="col-preventiontype"></a>`preventionType` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses SpellPreventionType enum values |
| <a id="col-stancebarorder"></a>`stanceBarOrder` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-dmgmultiplier1"></a>`dmgMultiplier1` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-dmgmultiplier2"></a>`dmgMultiplier2` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-dmgmultiplier3"></a>`dmgMultiplier3` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-minfactionid"></a>`minFactionId` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-minreputation"></a>`minReputation` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-requiredauravision"></a>`requiredAuraVision` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-customflags"></a>`customFlags` | `int(10) unsigned` | NO |  | `0` |  | Custom Field; non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses SpellAttributesCustom mask values |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `school`

non-negative numeric value.

Value set: `SpellSchools` (enum) from `src/game/Spells/SpellDefines.h enum SpellSchools`.

### `category`

non-negative numeric value.

### `castUI`

non-negative numeric value.

### `dispel`

non-negative numeric value.

Value set: `DispelType` (enum) from `src/game/Spells/SpellDefines.h enum DispelType`.

### `mechanic`

non-negative numeric value.

Value set: `Mechanics` (enum) from `src/game/Spells/SpellDefines.h enum Mechanics`.

### `attributes`

non-negative numeric value.

Value set: `SpellAttributes` (mask) from `src/game/Spells/SpellDefines.h enum SpellAttributes`.

### `attributesEx`

non-negative numeric value.

Value set: `SpellAttributesEx` (mask) from `src/game/Spells/SpellDefines.h enum SpellAttributesEx`.

### `attributesEx2`

non-negative numeric value.

Value set: `SpellAttributesEx2` (mask) from `src/game/Spells/SpellDefines.h enum SpellAttributesEx2`.

### `attributesEx3`

non-negative numeric value.

Value set: `SpellAttributesEx3` (mask) from `src/game/Spells/SpellDefines.h enum SpellAttributesEx3`.

### `attributesEx4`

non-negative numeric value.

Value set: `SpellAttributesEx4` (mask) from `src/game/Spells/SpellDefines.h enum SpellAttributesEx4`.

### `stances`

non-negative numeric value.

### `stancesNot`

non-negative numeric value.

### `targets`

non-negative numeric value.

Value set: `SpellCastTargetFlags` (mask) from `src/game/Database/DBCEnums.h enum SpellCastTargetFlags`.

### `targetCreatureType`

non-negative numeric value.

### `requiresSpellFocus`

non-negative numeric value.

### `casterAuraState`

non-negative numeric value.

Value set: `AuraState` (enum) from `src/game/Spells/SpellDefines.h enum AuraState`.

### `targetAuraState`

non-negative numeric value.

Value set: `AuraState` (enum) from `src/game/Spells/SpellDefines.h enum AuraState`.

### `castingTimeIndex`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `recoveryTime`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `categoryRecoveryTime`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `interruptFlags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `SpellInterruptFlags` (mask) from `src/game/Spells/SpellDefines.h enum SpellInterruptFlags`.

### `auraInterruptFlags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `SpellAuraInterruptFlags` (mask) from `src/game/Spells/SpellDefines.h enum SpellAuraInterruptFlags`.

### `channelInterruptFlags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `ChannelInterruptFlags` (mask) from `src/game/Spells/SpellDefines.h channel interrupt constants`.

### `procFlags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `ProcFlags` (mask) from `src/game/Spells/SpellDefines.h enum ProcFlags`.

### `procChance`

non-negative numeric value.

### `procCharges`

non-negative numeric value.

### `maxLevel`

non-negative numeric value.

### `baseLevel`

non-negative numeric value.

### `spellLevel`

non-negative numeric value.

### `durationIndex`

non-negative numeric value.

### `powerType`

non-negative numeric value.

Value set: `Powers` (enum) from `src/game/SharedDefines.h enum Powers`.

### `manaCost`

non-negative numeric value; money/cost value, usually copper.

### `manCostPerLevel`

non-negative numeric value; money/cost value, usually copper.

### `manaPerSecond`

non-negative numeric value.

### `manaPerSecondPerLevel`

non-negative numeric value.

### `rangeIndex`

non-negative numeric value.

Value set: `SpellRangeIndex` (enum) from `src/game/Spells/SpellDefines.h enum SpellRangeIndex`.

### `speed`

numeric value.

### `modelNextSpell`

non-negative numeric value.

### `stackAmount`

non-negative numeric value.

### `totem1`

non-negative numeric value.

### `totem2`

non-negative numeric value.

### `reagent1`

numeric value.

### `reagent2`

numeric value.

### `reagent3`

numeric value.

### `reagent4`

numeric value.

### `reagent5`

numeric value.

### `reagent6`

numeric value.

### `reagent7`

numeric value.

### `reagent8`

numeric value.

### `reagentCount1`

non-negative numeric value.

### `reagentCount2`

non-negative numeric value.

### `reagentCount3`

non-negative numeric value.

### `reagentCount4`

non-negative numeric value.

### `reagentCount5`

non-negative numeric value.

### `reagentCount6`

non-negative numeric value.

### `reagentCount7`

non-negative numeric value.

### `reagentCount8`

non-negative numeric value.

### `equippedItemClass`

numeric value.

Value set: `ItemClass` (enum) from `src/game/Objects/ItemPrototype.h enum ItemClass`.

### `equippedItemSubClassMask`

numeric value; mask/flags column; combine values with bitwise OR.

### `equippedItemInventoryTypeMask`

numeric value; mask/flags column; combine values with bitwise OR.

### `effect1`

non-negative numeric value.

Value set: `SpellEffects` (enum) from `src/game/Spells/SpellDefines.h enum SpellEffects`.

### `effect2`

non-negative numeric value.

Value set: `SpellEffects` (enum) from `src/game/Spells/SpellDefines.h enum SpellEffects`.

### `effect3`

non-negative numeric value.

Value set: `SpellEffects` (enum) from `src/game/Spells/SpellDefines.h enum SpellEffects`.

### `effectDieSides1`

numeric value.

### `effectDieSides2`

numeric value.

### `effectDieSides3`

numeric value.

### `effectBaseDice1`

non-negative numeric value.

### `effectBaseDice2`

non-negative numeric value.

### `effectBaseDice3`

non-negative numeric value.

### `effectDicePerLevel1`

numeric value.

### `effectDicePerLevel2`

numeric value.

### `effectDicePerLevel3`

numeric value.

### `effectRealPointsPerLevel1`

numeric value.

### `effectRealPointsPerLevel2`

numeric value.

### `effectRealPointsPerLevel3`

numeric value.

### `effectBasePoints1`

numeric value.

### `effectBasePoints2`

numeric value.

### `effectBasePoints3`

numeric value.

### `effectBonusCoefficient1`

numeric value.

### `effectBonusCoefficient2`

numeric value.

### `effectBonusCoefficient3`

numeric value.

### `effectMechanic1`

non-negative numeric value.

Value set: `Mechanics` (enum) from `src/game/Spells/SpellDefines.h enum Mechanics`.

### `effectMechanic2`

non-negative numeric value.

Value set: `Mechanics` (enum) from `src/game/Spells/SpellDefines.h enum Mechanics`.

### `effectMechanic3`

non-negative numeric value.

Value set: `Mechanics` (enum) from `src/game/Spells/SpellDefines.h enum Mechanics`.

### `effectImplicitTargetA1`

non-negative numeric value.

Value set: `SpellTarget` (enum) from `src/game/Spells/SpellDefines.h enum SpellTarget`.

### `effectImplicitTargetA2`

non-negative numeric value.

Value set: `SpellTarget` (enum) from `src/game/Spells/SpellDefines.h enum SpellTarget`.

### `effectImplicitTargetA3`

non-negative numeric value.

Value set: `SpellTarget` (enum) from `src/game/Spells/SpellDefines.h enum SpellTarget`.

### `effectImplicitTargetB1`

non-negative numeric value.

Value set: `SpellTarget` (enum) from `src/game/Spells/SpellDefines.h enum SpellTarget`.

### `effectImplicitTargetB2`

non-negative numeric value.

Value set: `SpellTarget` (enum) from `src/game/Spells/SpellDefines.h enum SpellTarget`.

### `effectImplicitTargetB3`

non-negative numeric value.

Value set: `SpellTarget` (enum) from `src/game/Spells/SpellDefines.h enum SpellTarget`.

### `effectRadiusIndex1`

non-negative numeric value.

### `effectRadiusIndex2`

non-negative numeric value.

### `effectRadiusIndex3`

non-negative numeric value.

### `effectApplyAuraName1`

non-negative numeric value.

Value set: `AuraType` (enum) from `src/game/Spells/SpellAuraDefines.h enum AuraType`.

### `effectApplyAuraName2`

non-negative numeric value.

Value set: `AuraType` (enum) from `src/game/Spells/SpellAuraDefines.h enum AuraType`.

### `effectApplyAuraName3`

non-negative numeric value.

Value set: `AuraType` (enum) from `src/game/Spells/SpellAuraDefines.h enum AuraType`.

### `effectAmplitude1`

non-negative numeric value.

### `effectAmplitude2`

non-negative numeric value.

### `effectAmplitude3`

non-negative numeric value.

### `effectMultipleValue1`

numeric value.

### `effectMultipleValue2`

numeric value.

### `effectMultipleValue3`

numeric value.

### `effectChainTarget1`

non-negative numeric value.

### `effectChainTarget2`

non-negative numeric value.

### `effectChainTarget3`

non-negative numeric value.

### `effectItemType1`

non-negative numeric value.

### `effectItemType2`

non-negative numeric value.

### `effectItemType3`

non-negative numeric value.

### `effectMiscValue1`

numeric value.

### `effectMiscValue2`

numeric value.

### `effectMiscValue3`

numeric value.

### `effectTriggerSpell1`

non-negative numeric value.

### `effectTriggerSpell2`

non-negative numeric value.

### `effectTriggerSpell3`

non-negative numeric value.

### `effectPointsPerComboPoint1`

numeric value.

### `effectPointsPerComboPoint2`

numeric value.

### `effectPointsPerComboPoint3`

numeric value.

### `spellVisual1`

non-negative numeric value.

### `spellVisual2`

non-negative numeric value.

### `spellIconId`

non-negative numeric value.

### `activeIconId`

non-negative numeric value.

### `spellPriority`

non-negative numeric value.

### `name`

text/string data.

### `nameFlags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

### `nameSubtext`

text/string data.

### `nameSubtextFlags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

### `description`

text/string data; script id or script name.

### `descriptionFlags`

non-negative numeric value; mask/flags column; combine values with bitwise OR; script id or script name.

### `auraDescription`

text/string data; script id or script name.

### `auraDescriptionFlags`

non-negative numeric value; mask/flags column; combine values with bitwise OR; script id or script name.

### `manaCostPercentage`

non-negative numeric value; money/cost value, usually copper.

### `startRecoveryCategory`

non-negative numeric value.

### `startRecoveryTime`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `minTargetLevel`

non-negative numeric value.

### `maxTargetLevel`

non-negative numeric value.

### `spellFamilyName`

non-negative numeric value.

### `spellFamilyFlags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

### `maxAffectedTargets`

non-negative numeric value.

### `dmgClass`

non-negative numeric value.

Value set: `SpellDmgClass` (enum) from `src/game/Spells/SpellDefines.h enum SpellDmgClass`.

### `preventionType`

non-negative numeric value.

Value set: `SpellPreventionType` (enum) from `src/game/Spells/SpellDefines.h enum SpellPreventionType`.

### `stanceBarOrder`

numeric value.

### `dmgMultiplier1`

numeric value.

### `dmgMultiplier2`

numeric value.

### `dmgMultiplier3`

numeric value.

### `minFactionId`

non-negative numeric value.

### `minReputation`

non-negative numeric value.

### `requiredAuraVision`

non-negative numeric value.

### `customFlags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `SpellAttributesCustom` (mask) from `src/game/Spells/SpellDefines.h enum SpellAttributesCustom`.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`spell_learn_spell`](spell_learn_spell.md).`SpellID` | `entry` | heuristic | inferred from column name |
| [`playercreateinfo_spell`](playercreateinfo_spell.md).`spell` | `entry` | heuristic | spell id |
| [`spell_area`](spell_area.md).`spell` | `entry` | heuristic | spell id |
| [`spell_pet_auras`](spell_pet_auras.md).`spell` | `entry` | heuristic | spell id |
| [`npc_trainer`](npc_trainer.md).`spell` | `entry` | explicit | trained spell |
| [`npc_trainer_template`](npc_trainer_template.md).`spell` | `entry` | explicit | trained spell |
| [`petcreateinfo_spell`](petcreateinfo_spell.md).`spell1` | `entry` | heuristic | spell id |
| [`petcreateinfo_spell`](petcreateinfo_spell.md).`spell2` | `entry` | heuristic | spell id |
| [`petcreateinfo_spell`](petcreateinfo_spell.md).`spell3` | `entry` | heuristic | spell id |
| [`petcreateinfo_spell`](petcreateinfo_spell.md).`spell4` | `entry` | heuristic | spell id |
| [`collection_mount`](collection_mount.md).`spellId` | `entry` | heuristic | inferred from column name |
| [`collection_pet`](collection_pet.md).`spellId` | `entry` | heuristic | inferred from column name |
| [`collection_toy`](collection_toy.md).`spellId` | `entry` | heuristic | inferred from column name |
| [`creature_spells`](creature_spells.md).`spellId_1` | `entry` | explicit | AI spell slot |
| [`creature_spells`](creature_spells.md).`spellId_2` | `entry` | explicit | AI spell slot |
| [`creature_spells`](creature_spells.md).`spellId_3` | `entry` | explicit | AI spell slot |
| [`creature_spells`](creature_spells.md).`spellId_4` | `entry` | explicit | AI spell slot |
| [`creature_spells`](creature_spells.md).`spellId_5` | `entry` | explicit | AI spell slot |
| [`creature_spells`](creature_spells.md).`spellId_6` | `entry` | explicit | AI spell slot |
| [`creature_spells`](creature_spells.md).`spellId_7` | `entry` | explicit | AI spell slot |
| [`creature_spells`](creature_spells.md).`spellId_8` | `entry` | explicit | AI spell slot |
| [`instance_buff_removal`](instance_buff_removal.md).`spell_id` | `entry` | heuristic | spell id |
| [`quest_cast_objective`](quest_cast_objective.md).`spell_id` | `entry` | heuristic | spell id |
| [`skill_line_ability`](skill_line_ability.md).`spell_id` | `entry` | heuristic | spell id |
| [`spell_chain`](spell_chain.md).`spell_id` | `entry` | heuristic | spell id |
| [`spell_group`](spell_group.md).`spell_id` | `entry` | heuristic | spell id |
| [`creature_template`](creature_template.md).`spell_id1` | `entry` | heuristic | spell id |
| [`pet_spell_data`](pet_spell_data.md).`spell_id1` | `entry` | heuristic | spell id |
| [`creature_template`](creature_template.md).`spell_id2` | `entry` | heuristic | spell id |
| [`pet_spell_data`](pet_spell_data.md).`spell_id2` | `entry` | heuristic | spell id |
| [`creature_template`](creature_template.md).`spell_id3` | `entry` | heuristic | spell id |
| [`pet_spell_data`](pet_spell_data.md).`spell_id3` | `entry` | heuristic | spell id |
| [`creature_template`](creature_template.md).`spell_id4` | `entry` | heuristic | spell id |
| [`pet_spell_data`](pet_spell_data.md).`spell_id4` | `entry` | heuristic | spell id |
| [`spell_check`](spell_check.md).`spellid` | `entry` | heuristic | inferred from column name |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `AuraState` | enum | [`casterAuraState`](#col-casteraurastate), [`targetAuraState`](#col-targetaurastate) | `src/game/Spells/SpellDefines.h enum AuraState` | 16 |
| `AuraType` | enum | [`effectApplyAuraName1`](#col-effectapplyauraname1), [`effectApplyAuraName2`](#col-effectapplyauraname2), [`effectApplyAuraName3`](#col-effectapplyauraname3) | `src/game/Spells/SpellAuraDefines.h enum AuraType` | 228 |
| `ChannelInterruptFlags` | mask | [`channelInterruptFlags`](#col-channelinterruptflags) | `src/game/Spells/SpellDefines.h channel interrupt constants` | 1 |
| `DispelType` | enum | [`dispel`](#col-dispel) | `src/game/Spells/SpellDefines.h enum DispelType` | 11 |
| `ItemClass` | enum | [`equippedItemClass`](#col-equippeditemclass) | `src/game/Objects/ItemPrototype.h enum ItemClass` | 16 |
| `Mechanics` | enum | [`mechanic`](#col-mechanic), [`effectMechanic1`](#col-effectmechanic1), [`effectMechanic2`](#col-effectmechanic2), [`effectMechanic3`](#col-effectmechanic3) | `src/game/Spells/SpellDefines.h enum Mechanics` | 32 |
| `Powers` | enum | [`powerType`](#col-powertype) | `src/game/SharedDefines.h enum Powers` | 6 |
| `ProcFlags` | mask | [`procFlags`](#col-procflags) | `src/game/Spells/SpellDefines.h enum ProcFlags` | 24 |
| `SpellAttributes` | mask | [`attributes`](#col-attributes) | `src/game/Spells/SpellDefines.h enum SpellAttributes` | 32 |
| `SpellAttributesCustom` | mask | [`customFlags`](#col-customflags) | `src/game/Spells/SpellDefines.h enum SpellAttributesCustom` | 24 |
| `SpellAttributesEx` | mask | [`attributesEx`](#col-attributesex) | `src/game/Spells/SpellDefines.h enum SpellAttributesEx` | 32 |
| `SpellAttributesEx2` | mask | [`attributesEx2`](#col-attributesex2) | `src/game/Spells/SpellDefines.h enum SpellAttributesEx2` | 32 |
| `SpellAttributesEx3` | mask | [`attributesEx3`](#col-attributesex3) | `src/game/Spells/SpellDefines.h enum SpellAttributesEx3` | 32 |
| `SpellAttributesEx4` | mask | [`attributesEx4`](#col-attributesex4) | `src/game/Spells/SpellDefines.h enum SpellAttributesEx4` | 10 |
| `SpellAuraInterruptFlags` | mask | [`auraInterruptFlags`](#col-aurainterruptflags) | `src/game/Spells/SpellDefines.h enum SpellAuraInterruptFlags` | 25 |
| `SpellCastTargetFlags` | mask | [`targets`](#col-targets) | `src/game/Database/DBCEnums.h enum SpellCastTargetFlags` | 18 |
| `SpellDmgClass` | enum | [`dmgClass`](#col-dmgclass) | `src/game/Spells/SpellDefines.h enum SpellDmgClass` | 4 |
| `SpellEffects` | enum | [`effect1`](#col-effect1), [`effect2`](#col-effect2), [`effect3`](#col-effect3) | `src/game/Spells/SpellDefines.h enum SpellEffects` | 136 |
| `SpellInterruptFlags` | mask | [`interruptFlags`](#col-interruptflags) | `src/game/Spells/SpellDefines.h enum SpellInterruptFlags` | 5 |
| `SpellPreventionType` | enum | [`preventionType`](#col-preventiontype) | `src/game/Spells/SpellDefines.h enum SpellPreventionType` | 3 |
| `SpellRangeIndex` | enum | [`rangeIndex`](#col-rangeindex) | `src/game/Spells/SpellDefines.h enum SpellRangeIndex` | 3 |
| `SpellSchools` | enum | [`school`](#col-school) | `src/game/Spells/SpellDefines.h enum SpellSchools` | 7 |
| `SpellTarget` | enum | [`effectImplicitTargetA1`](#col-effectimplicittargeta1), [`effectImplicitTargetA2`](#col-effectimplicittargeta2), [`effectImplicitTargetA3`](#col-effectimplicittargeta3), [`effectImplicitTargetB1`](#col-effectimplicittargetb1), [`effectImplicitTargetB2`](#col-effectimplicittargetb2), [`effectImplicitTargetB3`](#col-effectimplicittargetb3) | `src/game/Spells/SpellDefines.h enum SpellTarget` | 64 |

### Possible Values

Used by: [`casterAuraState`](#col-casteraurastate), [`targetAuraState`](#col-targetaurastate)

#### `AuraState`

Kind: `enum`

Source: `src/game/Spells/SpellDefines.h enum AuraState`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `AURA_STATE_DEFENSE` | C   &#124; |
| `2` | `0x2` | `AURA_STATE_HEALTHLESS_20_PERCENT` | C T &#124; |
| `3` | `0x3` | `AURA_STATE_BERSERKING` | C   &#124; |
| `4` | `0x4` | `AURA_STATE_FROZEN` | &#124; frozen target (but not used for any spells in 1.12.1 at client side) |
| `5` | `0x5` | `AURA_STATE_JUDGEMENT` | C   &#124; |
| `6` | `0x6` | `AURA_STATE_CRIT` | C   &#124; caster recently critically hit |
| `7` | `0x7` | `AURA_STATE_HUNTER_PARRY` | C   &#124; |
| `8` | `0x8` | `AURA_STATE_ROGUE_ATTACK_FROM_STEALTH` | C   &#124; FIX ME: not implemented yet! |
| `9` | `0x9` | `AURA_STATE_HEALTHLESS_15_PERCENT` | State Healthless 15 Percent |
| `10` | `0xA` | `AURA_STATE_HEALTHLESS_10_PERCENT` | State Healthless 10 Percent |
| `11` | `0xB` | `AURA_STATE_HEALTHLESS_5_PERCENT` | State Healthless 5 Percent |
| `12` | `0xC` | `AURA_STATE_HEALTHLESS_35_PERCENT` | custom |
| `13` | `0xD` | `AURA_STATE_SPELL_RESISTED` | custom: recently had a spell resist |
| `14` | `0xE` | `AURA_STATE_TARGET_DODGED` | custom: target recently dodged caster attack |
| `15` | `0xF` | `AURA_STATE_PET_CRIT` | custom: caster's pet recently critically hit |
| `16` | `0x10` | `AURA_STATE_SHAPESHIFTED` | custom: shapeshift form active |

Used by: [`effectApplyAuraName1`](#col-effectapplyauraname1), [`effectApplyAuraName2`](#col-effectapplyauraname2), [`effectApplyAuraName3`](#col-effectapplyauraname3)

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

Used by: [`channelInterruptFlags`](#col-channelinterruptflags)

#### `ChannelInterruptFlags`

Kind: `mask`

Source: `src/game/Spells/SpellDefines.h channel interrupt constants`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `4` | `0x4` | `CHANNEL_FLAG_INTERRUPT` | Interrupt channeled spell |

Used by: [`dispel`](#col-dispel)

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

Used by: [`equippedItemClass`](#col-equippeditemclass)

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

Used by: [`mechanic`](#col-mechanic), [`effectMechanic1`](#col-effectmechanic1), [`effectMechanic2`](#col-effectmechanic2), [`effectMechanic3`](#col-effectmechanic3)

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

Used by: [`powerType`](#col-powertype)

#### `Powers`

Kind: `enum`

Source: `src/game/SharedDefines.h enum Powers`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `POWER_MANA` | UNIT_FIELD_POWER1 |
| `1` | `0x1` | `POWER_RAGE` | UNIT_FIELD_POWER2 |
| `2` | `0x2` | `POWER_FOCUS` | UNIT_FIELD_POWER3 |
| `3` | `0x3` | `POWER_ENERGY` | UNIT_FIELD_POWER4 |
| `4` | `0x4` | `POWER_HAPPINESS` | UNIT_FIELD_POWER5 |
| `4294967294` | `0xFFFFFFFE` | `POWER_HEALTH` | (-2 as signed value) |

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

Used by: [`attributes`](#col-attributes)

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

Used by: [`customFlags`](#col-customflags)

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

Used by: [`attributesEx`](#col-attributesex)

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

Used by: [`attributesEx2`](#col-attributesex2)

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

Used by: [`attributesEx3`](#col-attributesex3)

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

Used by: [`attributesEx4`](#col-attributesex4)

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

Used by: [`auraInterruptFlags`](#col-aurainterruptflags)

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

Used by: [`targets`](#col-targets)

#### `SpellCastTargetFlags`

Kind: `mask`

Source: `src/game/Database/DBCEnums.h enum SpellCastTargetFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `TARGET_FLAG_SELF` | Target Flag Self |
| `1` | `0x1` | `TARGET_FLAG_UNUSED1` | not used in any spells (can be set dynamically) |
| `2` | `0x2` | `TARGET_FLAG_UNIT` | pguid |
| `4` | `0x4` | `TARGET_FLAG_UNUSED2` | not used in any spells (can be set dynamically) |
| `8` | `0x8` | `TARGET_FLAG_UNUSED3` | not used in any spells (can be set dynamically) |
| `16` | `0x10` | `TARGET_FLAG_ITEM` | pguid |
| `32` | `0x20` | `TARGET_FLAG_SOURCE_LOCATION` | 3 float |
| `64` | `0x40` | `TARGET_FLAG_DEST_LOCATION` | 3 float |
| `128` | `0x80` | `TARGET_FLAG_OBJECT_UNK` | used in 7 spells only |
| `256` | `0x100` | `TARGET_FLAG_UNIT_UNK` | looks like self target (389 spells) |
| `512` | `0x200` | `TARGET_FLAG_PVP_CORPSE` | pguid |
| `1024` | `0x400` | `TARGET_FLAG_UNIT_CORPSE` | 10 spells (gathering professions) |
| `2048` | `0x800` | `TARGET_FLAG_OBJECT` | pguid, 0 spells |
| `4096` | `0x1000` | `TARGET_FLAG_TRADE_ITEM` | pguid, 0 spells |
| `8192` | `0x2000` | `TARGET_FLAG_STRING` | string, 0 spells |
| `16384` | `0x4000` | `TARGET_FLAG_UNK1` | 199 spells, opening object/lock |
| `32768` | `0x8000` | `TARGET_FLAG_CORPSE` | pguid, resurrection spells |
| `65536` | `0x10000` | `TARGET_FLAG_UNK2` | pguid, not used in any spells (can be set dynamically) |

Used by: [`dmgClass`](#col-dmgclass)

#### `SpellDmgClass`

Kind: `enum`

Source: `src/game/Spells/SpellDefines.h enum SpellDmgClass`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `SPELL_DAMAGE_CLASS_NONE` | Damage Class None |
| `1` | `0x1` | `SPELL_DAMAGE_CLASS_MAGIC` | Damage Class Magic |
| `2` | `0x2` | `SPELL_DAMAGE_CLASS_MELEE` | Damage Class Melee |
| `3` | `0x3` | `SPELL_DAMAGE_CLASS_RANGED` | Damage Class Ranged |

Used by: [`effect1`](#col-effect1), [`effect2`](#col-effect2), [`effect3`](#col-effect3)

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

Used by: [`interruptFlags`](#col-interruptflags)

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

Used by: [`preventionType`](#col-preventiontype)

#### `SpellPreventionType`

Kind: `enum`

Source: `src/game/Spells/SpellDefines.h enum SpellPreventionType`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `SPELL_PREVENTION_TYPE_NONE` | Prevention Type None |
| `1` | `0x1` | `SPELL_PREVENTION_TYPE_SILENCE` | Prevention Type Silence |
| `2` | `0x2` | `SPELL_PREVENTION_TYPE_PACIFY` | Prevention Type Pacify |

Used by: [`rangeIndex`](#col-rangeindex)

#### `SpellRangeIndex`

Kind: `enum`

Source: `src/game/Spells/SpellDefines.h enum SpellRangeIndex`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `SPELL_RANGE_IDX_SELF_ONLY` | 0.0 |
| `2` | `0x2` | `SPELL_RANGE_IDX_COMBAT` | often ~5.5 (but infact dynamic melee combat range) |
| `13` | `0xD` | `SPELL_RANGE_IDX_ANYWHERE` | 500000 (anywhere) |

Used by: [`school`](#col-school)

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

Used by: [`effectImplicitTargetA1`](#col-effectimplicittargeta1), [`effectImplicitTargetA2`](#col-effectimplicittargeta2), [`effectImplicitTargetA3`](#col-effectimplicittargeta3), [`effectImplicitTargetB1`](#col-effectimplicittargetb1), [`effectImplicitTargetB2`](#col-effectimplicittargetb2), [`effectImplicitTargetB3`](#col-effectimplicittargetb3)

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

### Unmapped Flag-Like Columns

| Column | Type | Guidance |
| --- | --- | --- |
| [`equippedItemSubClassMask`](#col-equippeditemsubclassmask) | `int(11)` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
| [`equippedItemInventoryTypeMask`](#col-equippediteminventorytypemask) | `int(11)` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
| [`nameFlags`](#col-nameflags) | `int(10) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
| [`nameSubtextFlags`](#col-namesubtextflags) | `int(10) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
| [`descriptionFlags`](#col-descriptionflags) | `int(10) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
| [`auraDescriptionFlags`](#col-auradescriptionflags) | `int(10) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
| [`spellFamilyFlags`](#col-spellfamilyflags) | `bigint(20) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
