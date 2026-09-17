---
layout: default
title: quest_template
---

# quest_template

Quest System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 129 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-method"></a>`Method` | `tinyint(3) unsigned` | NO |  | `2` |  | non-negative numeric value; Uses QuestMethod enum values |
| <a id="col-zoneorsort"></a>`ZoneOrSort` | `smallint(6)` | NO |  | `0` |  | numeric value; Uses QuestSort enum values |
| <a id="col-minlevel"></a>`MinLevel` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-maxlevel"></a>`MaxLevel` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-questlevel"></a>`QuestLevel` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-type"></a>`Type` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses QuestTypes enum values |
| <a id="col-requiredclasses"></a>`RequiredClasses` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-requiredraces"></a>`RequiredRaces` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-requiredskill"></a>`RequiredSkill` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-requiredskillvalue"></a>`RequiredSkillValue` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-requiredcondition"></a>`RequiredCondition` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-repobjectivefaction"></a>`RepObjectiveFaction` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-repobjectivevalue"></a>`RepObjectiveValue` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-requiredminrepfaction"></a>`RequiredMinRepFaction` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-requiredminrepvalue"></a>`RequiredMinRepValue` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-requiredmaxrepfaction"></a>`RequiredMaxRepFaction` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-requiredmaxrepvalue"></a>`RequiredMaxRepValue` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-suggestedplayers"></a>`SuggestedPlayers` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-limittime"></a>`LimitTime` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-questflags"></a>`QuestFlags` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses QuestFlags mask values |
| <a id="col-specialflags"></a>`SpecialFlags` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR; Uses QuestSpecialFlags mask values |
| <a id="col-prevquestid"></a>`PrevQuestId` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-nextquestid"></a>`NextQuestId` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-exclusivegroup"></a>`ExclusiveGroup` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-nextquestinchain"></a>`NextQuestInChain` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-srcitemid"></a>`SrcItemId` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-srcitemcount"></a>`SrcItemCount` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-srcspell"></a>`SrcSpell` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-title"></a>`Title` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-details"></a>`Details` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-objectives"></a>`Objectives` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-offerrewardtext"></a>`OfferRewardText` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-requestitemstext"></a>`RequestItemsText` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-endtext"></a>`EndText` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-objectivetext1"></a>`ObjectiveText1` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-objectivetext2"></a>`ObjectiveText2` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-objectivetext3"></a>`ObjectiveText3` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-objectivetext4"></a>`ObjectiveText4` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-reqitemid1"></a>`ReqItemId1` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqitemid2"></a>`ReqItemId2` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqitemid3"></a>`ReqItemId3` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqitemid4"></a>`ReqItemId4` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqitemcount1"></a>`ReqItemCount1` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqitemcount2"></a>`ReqItemCount2` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqitemcount3"></a>`ReqItemCount3` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqitemcount4"></a>`ReqItemCount4` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqsourceid1"></a>`ReqSourceId1` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqsourceid2"></a>`ReqSourceId2` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqsourceid3"></a>`ReqSourceId3` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqsourceid4"></a>`ReqSourceId4` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqsourcecount1"></a>`ReqSourceCount1` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqsourcecount2"></a>`ReqSourceCount2` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqsourcecount3"></a>`ReqSourceCount3` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqsourcecount4"></a>`ReqSourceCount4` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqcreatureorgoid1"></a>`ReqCreatureOrGOId1` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-reqcreatureorgoid2"></a>`ReqCreatureOrGOId2` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-reqcreatureorgoid3"></a>`ReqCreatureOrGOId3` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-reqcreatureorgoid4"></a>`ReqCreatureOrGOId4` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-reqcreatureorgocount1"></a>`ReqCreatureOrGOCount1` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqcreatureorgocount2"></a>`ReqCreatureOrGOCount2` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqcreatureorgocount3"></a>`ReqCreatureOrGOCount3` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqcreatureorgocount4"></a>`ReqCreatureOrGOCount4` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqspellcast1"></a>`ReqSpellCast1` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqspellcast2"></a>`ReqSpellCast2` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqspellcast3"></a>`ReqSpellCast3` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reqspellcast4"></a>`ReqSpellCast4` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewchoiceitemid1"></a>`RewChoiceItemId1` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewchoiceitemid2"></a>`RewChoiceItemId2` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewchoiceitemid3"></a>`RewChoiceItemId3` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewchoiceitemid4"></a>`RewChoiceItemId4` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewchoiceitemid5"></a>`RewChoiceItemId5` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewchoiceitemid6"></a>`RewChoiceItemId6` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewchoiceitemcount1"></a>`RewChoiceItemCount1` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewchoiceitemcount2"></a>`RewChoiceItemCount2` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewchoiceitemcount3"></a>`RewChoiceItemCount3` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewchoiceitemcount4"></a>`RewChoiceItemCount4` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewchoiceitemcount5"></a>`RewChoiceItemCount5` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewchoiceitemcount6"></a>`RewChoiceItemCount6` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewitemid1"></a>`RewItemId1` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewitemid2"></a>`RewItemId2` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewitemid3"></a>`RewItemId3` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewitemid4"></a>`RewItemId4` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewitemcount1"></a>`RewItemCount1` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewitemcount2"></a>`RewItemCount2` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewitemcount3"></a>`RewItemCount3` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewitemcount4"></a>`RewItemCount4` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewrepfaction1"></a>`RewRepFaction1` | `smallint(5) unsigned` | NO |  | `0` |  | faction id from Faction.dbc in this case; non-negative numeric value |
| <a id="col-rewrepfaction2"></a>`RewRepFaction2` | `smallint(5) unsigned` | NO |  | `0` |  | faction id from Faction.dbc in this case; non-negative numeric value |
| <a id="col-rewrepfaction3"></a>`RewRepFaction3` | `smallint(5) unsigned` | NO |  | `0` |  | faction id from Faction.dbc in this case; non-negative numeric value |
| <a id="col-rewrepfaction4"></a>`RewRepFaction4` | `smallint(5) unsigned` | NO |  | `0` |  | faction id from Faction.dbc in this case; non-negative numeric value |
| <a id="col-rewrepfaction5"></a>`RewRepFaction5` | `smallint(5) unsigned` | NO |  | `0` |  | faction id from Faction.dbc in this case; non-negative numeric value |
| <a id="col-rewrepvalue1"></a>`RewRepValue1` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-rewrepvalue2"></a>`RewRepValue2` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-rewrepvalue3"></a>`RewRepValue3` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-rewrepvalue4"></a>`RewRepValue4` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-rewrepvalue5"></a>`RewRepValue5` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-rewxp"></a>`RewXP` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-reworreqmoney"></a>`RewOrReqMoney` | `int(11)` | NO |  | `0` |  | numeric value; money/cost value, usually copper |
| <a id="col-rewmoneymaxlevel"></a>`RewMoneyMaxLevel` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-rewspell"></a>`RewSpell` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewspellcast"></a>`RewSpellCast` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rewmailtemplateid"></a>`RewMailTemplateId` | `mediumint(9)` | NO |  | `0` |  | numeric value |
| <a id="col-rewmaildelaysecs"></a>`RewMailDelaySecs` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-rewmailmoney"></a>`RewMailMoney` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-pointmapid"></a>`PointMapId` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-pointx"></a>`PointX` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-pointy"></a>`PointY` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-pointopt"></a>`PointOpt` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-detailsemote1"></a>`DetailsEmote1` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Emote enum values |
| <a id="col-detailsemote2"></a>`DetailsEmote2` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Emote enum values |
| <a id="col-detailsemote3"></a>`DetailsEmote3` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Emote enum values |
| <a id="col-detailsemote4"></a>`DetailsEmote4` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Emote enum values |
| <a id="col-detailsemotedelay1"></a>`DetailsEmoteDelay1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-detailsemotedelay2"></a>`DetailsEmoteDelay2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-detailsemotedelay3"></a>`DetailsEmoteDelay3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-detailsemotedelay4"></a>`DetailsEmoteDelay4` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-incompleteemote"></a>`IncompleteEmote` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Emote enum values |
| <a id="col-completeemote"></a>`CompleteEmote` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Emote enum values |
| <a id="col-offerrewardemote1"></a>`OfferRewardEmote1` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Emote enum values |
| <a id="col-offerrewardemote2"></a>`OfferRewardEmote2` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Emote enum values |
| <a id="col-offerrewardemote3"></a>`OfferRewardEmote3` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Emote enum values |
| <a id="col-offerrewardemote4"></a>`OfferRewardEmote4` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Emote enum values |
| <a id="col-offerrewardemotedelay1"></a>`OfferRewardEmoteDelay1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-offerrewardemotedelay2"></a>`OfferRewardEmoteDelay2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-offerrewardemotedelay3"></a>`OfferRewardEmoteDelay3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-offerrewardemotedelay4"></a>`OfferRewardEmoteDelay4` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-startscript"></a>`StartScript` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; script id or script name |
| <a id="col-completescript"></a>`CompleteScript` | `mediumint(8) unsigned` | NO |  | `0` |  | non-negative numeric value; script id or script name |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `Method`

non-negative numeric value.

Value set: `QuestMethod` (enum) from `src/game/QuestDef.h enum QuestMethod`.

### `ZoneOrSort`

numeric value.

Value set: `QuestSort` (enum) from `src/game/SharedDefines.h enum QuestSort`.

### `MinLevel`

non-negative numeric value.

### `MaxLevel`

non-negative numeric value.

### `QuestLevel`

non-negative numeric value.

### `Type`

non-negative numeric value.

Value set: `QuestTypes` (enum) from `src/game/QuestDef.h enum QuestTypes`.

### `RequiredClasses`

non-negative numeric value.

### `RequiredRaces`

non-negative numeric value.

### `RequiredSkill`

non-negative numeric value.

### `RequiredSkillValue`

non-negative numeric value.

### `RequiredCondition`

non-negative numeric value.

References: [`conditions`](conditions.md).`condition_entry`.

### `RepObjectiveFaction`

non-negative numeric value.

### `RepObjectiveValue`

numeric value.

### `RequiredMinRepFaction`

non-negative numeric value.

### `RequiredMinRepValue`

numeric value.

### `RequiredMaxRepFaction`

non-negative numeric value.

### `RequiredMaxRepValue`

numeric value.

### `SuggestedPlayers`

non-negative numeric value.

### `LimitTime`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `QuestFlags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `QuestFlags` (mask) from `src/game/QuestDef.h quest flag constants`.

### `SpecialFlags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

Value set: `QuestSpecialFlags` (mask) from `src/game/QuestDef.h enum QuestSpecialFlags`.

### `PrevQuestId`

numeric value.

References: [`quest_template`](quest_template.md).`entry`.

### `NextQuestId`

numeric value.

References: [`quest_template`](quest_template.md).`entry`.

### `ExclusiveGroup`

numeric value.

### `NextQuestInChain`

non-negative numeric value.

References: [`quest_template`](quest_template.md).`entry`.

### `SrcItemId`

non-negative numeric value.

References: [`item_template`](item_template.md).`entry`.

### `SrcItemCount`

non-negative numeric value.

### `SrcSpell`

non-negative numeric value.

### `Title`

text/string data.

### `Details`

text/string data.

### `Objectives`

text/string data.

### `OfferRewardText`

text/string data.

### `RequestItemsText`

text/string data.

### `EndText`

text/string data.

### `ObjectiveText1`

text/string data.

### `ObjectiveText2`

text/string data.

### `ObjectiveText3`

text/string data.

### `ObjectiveText4`

text/string data.

### `ReqItemId1`

non-negative numeric value.

### `ReqItemId2`

non-negative numeric value.

### `ReqItemId3`

non-negative numeric value.

### `ReqItemId4`

non-negative numeric value.

### `ReqItemCount1`

non-negative numeric value.

### `ReqItemCount2`

non-negative numeric value.

### `ReqItemCount3`

non-negative numeric value.

### `ReqItemCount4`

non-negative numeric value.

### `ReqSourceId1`

non-negative numeric value.

### `ReqSourceId2`

non-negative numeric value.

### `ReqSourceId3`

non-negative numeric value.

### `ReqSourceId4`

non-negative numeric value.

### `ReqSourceCount1`

non-negative numeric value.

### `ReqSourceCount2`

non-negative numeric value.

### `ReqSourceCount3`

non-negative numeric value.

### `ReqSourceCount4`

non-negative numeric value.

### `ReqCreatureOrGOId1`

numeric value.

### `ReqCreatureOrGOId2`

numeric value.

### `ReqCreatureOrGOId3`

numeric value.

### `ReqCreatureOrGOId4`

numeric value.

### `ReqCreatureOrGOCount1`

non-negative numeric value.

### `ReqCreatureOrGOCount2`

non-negative numeric value.

### `ReqCreatureOrGOCount3`

non-negative numeric value.

### `ReqCreatureOrGOCount4`

non-negative numeric value.

### `ReqSpellCast1`

non-negative numeric value.

### `ReqSpellCast2`

non-negative numeric value.

### `ReqSpellCast3`

non-negative numeric value.

### `ReqSpellCast4`

non-negative numeric value.

### `RewChoiceItemId1`

non-negative numeric value.

References: [`item_template`](item_template.md).`entry`.

### `RewChoiceItemId2`

non-negative numeric value.

References: [`item_template`](item_template.md).`entry`.

### `RewChoiceItemId3`

non-negative numeric value.

References: [`item_template`](item_template.md).`entry`.

### `RewChoiceItemId4`

non-negative numeric value.

References: [`item_template`](item_template.md).`entry`.

### `RewChoiceItemId5`

non-negative numeric value.

References: [`item_template`](item_template.md).`entry`.

### `RewChoiceItemId6`

non-negative numeric value.

References: [`item_template`](item_template.md).`entry`.

### `RewChoiceItemCount1`

non-negative numeric value.

### `RewChoiceItemCount2`

non-negative numeric value.

### `RewChoiceItemCount3`

non-negative numeric value.

### `RewChoiceItemCount4`

non-negative numeric value.

### `RewChoiceItemCount5`

non-negative numeric value.

### `RewChoiceItemCount6`

non-negative numeric value.

### `RewItemId1`

non-negative numeric value.

References: [`item_template`](item_template.md).`entry`.

### `RewItemId2`

non-negative numeric value.

References: [`item_template`](item_template.md).`entry`.

### `RewItemId3`

non-negative numeric value.

References: [`item_template`](item_template.md).`entry`.

### `RewItemId4`

non-negative numeric value.

References: [`item_template`](item_template.md).`entry`.

### `RewItemCount1`

non-negative numeric value.

### `RewItemCount2`

non-negative numeric value.

### `RewItemCount3`

non-negative numeric value.

### `RewItemCount4`

non-negative numeric value.

### `RewRepFaction1`

non-negative numeric value.

### `RewRepFaction2`

non-negative numeric value.

### `RewRepFaction3`

non-negative numeric value.

### `RewRepFaction4`

non-negative numeric value.

### `RewRepFaction5`

non-negative numeric value.

### `RewRepValue1`

numeric value.

### `RewRepValue2`

numeric value.

### `RewRepValue3`

numeric value.

### `RewRepValue4`

numeric value.

### `RewRepValue5`

numeric value.

### `RewXP`

non-negative numeric value.

### `RewOrReqMoney`

numeric value; money/cost value, usually copper.

### `RewMoneyMaxLevel`

non-negative numeric value; money/cost value, usually copper.

### `RewSpell`

non-negative numeric value.

### `RewSpellCast`

non-negative numeric value.

### `RewMailTemplateId`

numeric value.

### `RewMailDelaySecs`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `RewMailMoney`

non-negative numeric value; money/cost value, usually copper.

### `PointMapId`

non-negative numeric value.

### `PointX`

numeric value.

### `PointY`

numeric value.

### `PointOpt`

non-negative numeric value.

### `DetailsEmote1`

non-negative numeric value.

Value set: `Emote` (enum) from `src/game/SharedDefines.h enum Emote`.

### `DetailsEmote2`

non-negative numeric value.

Value set: `Emote` (enum) from `src/game/SharedDefines.h enum Emote`.

### `DetailsEmote3`

non-negative numeric value.

Value set: `Emote` (enum) from `src/game/SharedDefines.h enum Emote`.

### `DetailsEmote4`

non-negative numeric value.

Value set: `Emote` (enum) from `src/game/SharedDefines.h enum Emote`.

### `DetailsEmoteDelay1`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `DetailsEmoteDelay2`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `DetailsEmoteDelay3`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `DetailsEmoteDelay4`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `IncompleteEmote`

non-negative numeric value.

Value set: `Emote` (enum) from `src/game/SharedDefines.h enum Emote`.

### `CompleteEmote`

non-negative numeric value.

Value set: `Emote` (enum) from `src/game/SharedDefines.h enum Emote`.

### `OfferRewardEmote1`

non-negative numeric value.

Value set: `Emote` (enum) from `src/game/SharedDefines.h enum Emote`.

### `OfferRewardEmote2`

non-negative numeric value.

Value set: `Emote` (enum) from `src/game/SharedDefines.h enum Emote`.

### `OfferRewardEmote3`

non-negative numeric value.

Value set: `Emote` (enum) from `src/game/SharedDefines.h enum Emote`.

### `OfferRewardEmote4`

non-negative numeric value.

Value set: `Emote` (enum) from `src/game/SharedDefines.h enum Emote`.

### `OfferRewardEmoteDelay1`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `OfferRewardEmoteDelay2`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `OfferRewardEmoteDelay3`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `OfferRewardEmoteDelay4`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `StartScript`

non-negative numeric value; script id or script name.

### `CompleteScript`

non-negative numeric value; script id or script name.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `RequiredCondition` | [`conditions`](conditions.md).`condition_entry` | heuristic | inferred from column name |
| `RewChoiceItemId1` | [`item_template`](item_template.md).`entry` | explicit | choice reward item |
| `RewChoiceItemId2` | [`item_template`](item_template.md).`entry` | explicit | choice reward item |
| `RewChoiceItemId3` | [`item_template`](item_template.md).`entry` | explicit | choice reward item |
| `RewChoiceItemId4` | [`item_template`](item_template.md).`entry` | explicit | choice reward item |
| `RewChoiceItemId5` | [`item_template`](item_template.md).`entry` | explicit | choice reward item |
| `RewChoiceItemId6` | [`item_template`](item_template.md).`entry` | explicit | choice reward item |
| `RewItemId1` | [`item_template`](item_template.md).`entry` | explicit | reward item |
| `RewItemId2` | [`item_template`](item_template.md).`entry` | explicit | reward item |
| `RewItemId3` | [`item_template`](item_template.md).`entry` | explicit | reward item |
| `RewItemId4` | [`item_template`](item_template.md).`entry` | explicit | reward item |
| `SrcItemId` | [`item_template`](item_template.md).`entry` | explicit | source item |
| `NextQuestId` | [`quest_template`](quest_template.md).`entry` | explicit | quest chain |
| `NextQuestInChain` | [`quest_template`](quest_template.md).`entry` | explicit | quest chain |
| `PrevQuestId` | [`quest_template`](quest_template.md).`entry` | explicit | quest chain |

### Incoming References

| Source | Target Column | Confidence | Notes |
| --- | --- | --- | --- |
| [`quest_template`](quest_template.md).`NextQuestId` | `entry` | explicit | quest chain |
| [`quest_template`](quest_template.md).`NextQuestInChain` | `entry` | explicit | quest chain |
| [`quest_template`](quest_template.md).`PrevQuestId` | `entry` | explicit | quest chain |
| [`creature_template`](creature_template.md).`phase_quest_id` | `entry` | explicit | phase quest |
| [`gameobject_template`](gameobject_template.md).`phase_quest_id` | `entry` | explicit | phase quest |
| [`game_event_quest`](game_event_quest.md).`quest` | `entry` | explicit | event quest |
| [`areatrigger_involvedrelation`](areatrigger_involvedrelation.md).`quest` | `entry` | heuristic | inferred from column name |
| [`creature_involvedrelation`](creature_involvedrelation.md).`quest` | `entry` | heuristic | inferred from column name |
| [`creature_questrelation`](creature_questrelation.md).`quest` | `entry` | heuristic | inferred from column name |
| [`game_event_mail`](game_event_mail.md).`quest` | `entry` | heuristic | inferred from column name |
| [`gameobject_involvedrelation`](gameobject_involvedrelation.md).`quest` | `entry` | heuristic | inferred from column name |
| [`gameobject_questrelation`](gameobject_questrelation.md).`quest` | `entry` | heuristic | inferred from column name |
| [`script_escort_data`](script_escort_data.md).`quest` | `entry` | heuristic | inferred from column name |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `Emote` | enum | [`DetailsEmote1`](#col-detailsemote1), [`DetailsEmote2`](#col-detailsemote2), [`DetailsEmote3`](#col-detailsemote3), [`DetailsEmote4`](#col-detailsemote4), [`IncompleteEmote`](#col-incompleteemote), [`CompleteEmote`](#col-completeemote), [`OfferRewardEmote1`](#col-offerrewardemote1), [`OfferRewardEmote2`](#col-offerrewardemote2), [`OfferRewardEmote3`](#col-offerrewardemote3), [`OfferRewardEmote4`](#col-offerrewardemote4) | `src/game/SharedDefines.h enum Emote` | 117 |
| `QuestFlags` | mask | [`QuestFlags`](#col-questflags) | `src/game/QuestDef.h quest flag constants` | 9 |
| `QuestMethod` | enum | [`Method`](#col-method) | `src/game/QuestDef.h enum QuestMethod` | 3 |
| `QuestSort` | enum | [`ZoneOrSort`](#col-zoneorsort) | `src/game/SharedDefines.h enum QuestSort` | 36 |
| `QuestSpecialFlags` | mask | [`SpecialFlags`](#col-specialflags) | `src/game/QuestDef.h enum QuestSpecialFlags` | 10 |
| `QuestTypes` | enum | [`Type`](#col-type) | `src/game/QuestDef.h enum QuestTypes` | 8 |

### Possible Values

Used by: [`DetailsEmote1`](#col-detailsemote1), [`DetailsEmote2`](#col-detailsemote2), [`DetailsEmote3`](#col-detailsemote3), [`DetailsEmote4`](#col-detailsemote4), [`IncompleteEmote`](#col-incompleteemote), [`CompleteEmote`](#col-completeemote), [`OfferRewardEmote1`](#col-offerrewardemote1), [`OfferRewardEmote2`](#col-offerrewardemote2), [`OfferRewardEmote3`](#col-offerrewardemote3), [`OfferRewardEmote4`](#col-offerrewardemote4)

#### `Emote`

Kind: `enum`

Source: `src/game/SharedDefines.h enum Emote`

Values prefixed EMOTE_STATE are persistent looping states; EMOTE_ONESHOT values are one-shot animation/emote triggers.

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `EMOTE_ONESHOT_NONE` | No emote |
| `1` | `0x1` | `EMOTE_ONESHOT_TALK` | Talk once |
| `2` | `0x2` | `EMOTE_ONESHOT_BOW` | Bow once |
| `3` | `0x3` | `EMOTE_ONESHOT_WAVE` | Wave once |
| `4` | `0x4` | `EMOTE_ONESHOT_CHEER` | Cheer once |
| `5` | `0x5` | `EMOTE_ONESHOT_EXCLAMATION` | Exclamation once |
| `6` | `0x6` | `EMOTE_ONESHOT_QUESTION` | Question once |
| `7` | `0x7` | `EMOTE_ONESHOT_EAT` | Eat once |
| `10` | `0xA` | `EMOTE_STATE_DANCE` | Looping dance state |
| `11` | `0xB` | `EMOTE_ONESHOT_LAUGH` | Laugh once |
| `12` | `0xC` | `EMOTE_STATE_SLEEP` | Looping sleep state |
| `13` | `0xD` | `EMOTE_STATE_SIT` | Looping sit state |
| `14` | `0xE` | `EMOTE_ONESHOT_RUDE` | Rude gesture once |
| `15` | `0xF` | `EMOTE_ONESHOT_ROAR` | Roar once |
| `16` | `0x10` | `EMOTE_ONESHOT_KNEEL` | Kneel once |
| `17` | `0x11` | `EMOTE_ONESHOT_KISS` | Kiss once |
| `18` | `0x12` | `EMOTE_ONESHOT_CRY` | Cry once |
| `19` | `0x13` | `EMOTE_ONESHOT_CHICKEN` | Chicken once |
| `20` | `0x14` | `EMOTE_ONESHOT_BEG` | Beg once |
| `21` | `0x15` | `EMOTE_ONESHOT_APPLAUD` | Applaud once |
| `22` | `0x16` | `EMOTE_ONESHOT_SHOUT` | Shout once |
| `23` | `0x17` | `EMOTE_ONESHOT_FLEX` | Flex once |
| `24` | `0x18` | `EMOTE_ONESHOT_SHY` | Shy once |
| `25` | `0x19` | `EMOTE_ONESHOT_POINT` | Point once |
| `26` | `0x1A` | `EMOTE_STATE_STAND` | Looping stand state |
| `27` | `0x1B` | `EMOTE_STATE_READYUNARMED` | Looping ready unarmed state |
| `28` | `0x1C` | `EMOTE_STATE_WORK_SHEATHED` | Looping work sheathed state |
| `29` | `0x1D` | `EMOTE_STATE_POINT` | Looping point state |
| `30` | `0x1E` | `EMOTE_STATE_NONE` | No persistent emote state |
| `33` | `0x21` | `EMOTE_ONESHOT_WOUND` | Wound once |
| `34` | `0x22` | `EMOTE_ONESHOT_WOUNDCRITICAL` | Critical wound once |
| `35` | `0x23` | `EMOTE_ONESHOT_ATTACKUNARMED` | Unarmed attack once |
| `36` | `0x24` | `EMOTE_ONESHOT_ATTACK1H` | One-handed attack once |
| `37` | `0x25` | `EMOTE_ONESHOT_ATTACK2HTIGHT` | Two-handed tight attack once |
| `38` | `0x26` | `EMOTE_ONESHOT_ATTACK2HLOOSE` | Two-handed loose attack once |
| `39` | `0x27` | `EMOTE_ONESHOT_PARRYUNARMED` | Unarmed parry once |
| `43` | `0x2B` | `EMOTE_ONESHOT_PARRYSHIELD` | Shield parry once |
| `44` | `0x2C` | `EMOTE_ONESHOT_READYUNARMED` | Ready unarmed once |
| `45` | `0x2D` | `EMOTE_ONESHOT_READY1H` | Ready one-handed once |
| `48` | `0x30` | `EMOTE_ONESHOT_READYBOW` | Ready bow once |
| `50` | `0x32` | `EMOTE_ONESHOT_SPELLPRECAST` | Spell precast once |
| `51` | `0x33` | `EMOTE_ONESHOT_SPELLCAST` | Spell cast once |
| `53` | `0x35` | `EMOTE_ONESHOT_BATTLEROAR` | Battle roar once |
| `54` | `0x36` | `EMOTE_ONESHOT_SPECIALATTACK1H` | Special one-handed attack once |
| `60` | `0x3C` | `EMOTE_ONESHOT_KICK` | Kick once |
| `61` | `0x3D` | `EMOTE_ONESHOT_ATTACKTHROWN` | Thrown attack once |
| `64` | `0x40` | `EMOTE_STATE_STUN` | Looping stun state |
| `65` | `0x41` | `EMOTE_STATE_DEAD` | Looping dead state |
| `66` | `0x42` | `EMOTE_ONESHOT_SALUTE` | Salute once |
| `68` | `0x44` | `EMOTE_STATE_KNEEL` | Looping kneel state |
| `69` | `0x45` | `EMOTE_STATE_USESTANDING` | Looping standing use state |
| `70` | `0x46` | `EMOTE_ONESHOT_WAVE_NOSHEATHE` | Wave once without sheathing |
| `71` | `0x47` | `EMOTE_ONESHOT_CHEER_NOSHEATHE` | Cheer once without sheathing |
| `92` | `0x5C` | `EMOTE_ONESHOT_EAT_NOSHEATHE` | Eat once without sheathing |
| `93` | `0x5D` | `EMOTE_STATE_STUN_NOSHEATHE` | Looping stun state without sheathing |
| `94` | `0x5E` | `EMOTE_ONESHOT_DANCE` | Dance once |
| `113` | `0x71` | `EMOTE_ONESHOT_SALUTE_NOSHEATH` | Salute once without sheathing |
| `133` | `0x85` | `EMOTE_STATE_USESTANDING_NOSHEATHE` | Looping standing use state without sheathing |
| `153` | `0x99` | `EMOTE_ONESHOT_LAUGH_NOSHEATHE` | Laugh once without sheathing |
| `173` | `0xAD` | `EMOTE_STATE_WORK` | Looping work state |
| `193` | `0xC1` | `EMOTE_STATE_SPELLPRECAST` | Looping spell precast state |
| `213` | `0xD5` | `EMOTE_ONESHOT_READYRIFLE` | Ready rifle once |
| `214` | `0xD6` | `EMOTE_STATE_READYRIFLE` | Looping ready rifle state |
| `233` | `0xE9` | `EMOTE_STATE_WORK_MINING` | Looping mining work state |
| `234` | `0xEA` | `EMOTE_STATE_WORK_CHOPWOOD` | Looping chopping work state |
| `253` | `0xFD` | `EMOTE_STATE_APPLAUD` | Looping applaud state |
| `254` | `0xFE` | `EMOTE_ONESHOT_LIFTOFF` | Lift off once |
| `273` | `0x111` | `EMOTE_ONESHOT_YES` | Yes once |
| `274` | `0x112` | `EMOTE_ONESHOT_NO` | No once |
| `275` | `0x113` | `EMOTE_ONESHOT_TRAIN` | Train once |
| `293` | `0x125` | `EMOTE_ONESHOT_LAND` | Land once |
| `313` | `0x139` | `EMOTE_STATE_AT_EASE` | Looping at-ease state |
| `333` | `0x14D` | `EMOTE_STATE_READY1H` | Looping ready one-handed state |
| `353` | `0x161` | `EMOTE_STATE_SPELLKNEELSTART` | Looping kneeling spell start state |
| `373` | `0x175` | `EMOTE_STATE_SUBMERGED` | Looping submerged state |
| `374` | `0x176` | `EMOTE_ONESHOT_SUBMERGE` | Submerge once |
| `375` | `0x177` | `EMOTE_STATE_READY2H` | Looping ready two-handed state |
| `376` | `0x178` | `EMOTE_STATE_READYBOW` | Looping ready bow state |
| `377` | `0x179` | `EMOTE_ONESHOT_MOUNTSPECIAL` | Mount special once |
| `378` | `0x17A` | `EMOTE_STATE_TALK` | Looping talk state |
| `379` | `0x17B` | `EMOTE_STATE_FISHING` | Looping fishing state |
| `380` | `0x17C` | `EMOTE_ONESHOT_FISHING` | Fishing cast once |
| `381` | `0x17D` | `EMOTE_ONESHOT_LOOT` | Loot once |
| `382` | `0x17E` | `EMOTE_STATE_WHIRLWIND` | Looping whirlwind state |
| `383` | `0x17F` | `EMOTE_STATE_DROWNED` | Looping drowned state |
| `384` | `0x180` | `EMOTE_STATE_HOLD_BOW` | Looping hold bow state |
| `385` | `0x181` | `EMOTE_STATE_HOLD_RIFLE` | Looping hold rifle state |
| `386` | `0x182` | `EMOTE_STATE_HOLD_THROWN` | Looping hold thrown state |
| `387` | `0x183` | `EMOTE_ONESHOT_DROWN` | Drown once |
| `388` | `0x184` | `EMOTE_ONESHOT_STOMP` | Stomp once |
| `389` | `0x185` | `EMOTE_ONESHOT_ATTACKOFF` | Off-hand attack once |
| `390` | `0x186` | `EMOTE_ONESHOT_ATTACKOFFPIERCE` | Off-hand pierce attack once |
| `391` | `0x187` | `EMOTE_STATE_ROAR` | Looping roar state |
| `392` | `0x188` | `EMOTE_STATE_LAUGH` | Looping laugh state |
| `393` | `0x189` | `EMOTE_ONESHOT_CREATURE_SPECIAL` | Creature special once |
| `394` | `0x18A` | `EMOTE_ONESHOT_JUMPLANDRUN` | Jump land run once |
| `395` | `0x18B` | `EMOTE_ONESHOT_JUMPEND` | Jump end once |
| `396` | `0x18C` | `EMOTE_ONESHOT_TALK_NOSHEATHE` | Talk once without sheathing |
| `397` | `0x18D` | `EMOTE_ONESHOT_POINT_NOSHEATHE` | Point once without sheathing |
| `398` | `0x18E` | `EMOTE_STATE_CANNIBALIZE` | Looping cannibalize state |
| `399` | `0x18F` | `EMOTE_ONESHOT_JUMPSTART` | Jump start once |
| `400` | `0x190` | `EMOTE_STATE_DANCESPECIAL` | Looping special dance state |
| `401` | `0x191` | `EMOTE_ONESHOT_DANCESPECIAL` | Special dance once |
| `402` | `0x192` | `EMOTE_ONESHOT_CUSTOMSPELL01` | Custom spell visual 01 once |
| `403` | `0x193` | `EMOTE_ONESHOT_CUSTOMSPELL02` | Custom spell visual 02 once |
| `404` | `0x194` | `EMOTE_ONESHOT_CUSTOMSPELL03` | Custom spell visual 03 once |
| `405` | `0x195` | `EMOTE_ONESHOT_CUSTOMSPELL04` | Custom spell visual 04 once |
| `406` | `0x196` | `EMOTE_ONESHOT_CUSTOMSPELL05` | Custom spell visual 05 once |
| `407` | `0x197` | `EMOTE_ONESHOT_CUSTOMSPELL06` | Custom spell visual 06 once |
| `408` | `0x198` | `EMOTE_ONESHOT_CUSTOMSPELL07` | Custom spell visual 07 once |
| `409` | `0x199` | `EMOTE_ONESHOT_CUSTOMSPELL08` | Custom spell visual 08 once |
| `410` | `0x19A` | `EMOTE_ONESHOT_CUSTOMSPELL09` | Custom spell visual 09 once |
| `411` | `0x19B` | `EMOTE_ONESHOT_CUSTOMSPELL10` | Custom spell visual 10 once |
| `412` | `0x19C` | `EMOTE_STATE_EXCLAIM` | Looping exclaim state |
| `415` | `0x19F` | `EMOTE_STATE_SIT_CHAIR_MED` | Looping medium-chair sit state |
| `422` | `0x1A6` | `EMOTE_STATE_SPELLEFFECT_HOLD` | Looping spell effect hold state |
| `423` | `0x1A7` | `EMOTE_STATE_EAT_NO_SHEATHE` | Looping eat state without sheathing |

Used by: [`QuestFlags`](#col-questflags)

#### `QuestFlags`

Kind: `mask`

Source: `src/game/QuestDef.h quest flag constants`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `QUEST_FLAGS_STAY_ALIVE` | Not currently used |
| `2` | `0x2` | `QUEST_FLAGS_PARTY_ACCEPT` | Party members can receive accept confirmation |
| `4` | `0x4` | `QUEST_FLAGS_EXPLORATION` | Not currently used |
| `8` | `0x8` | `QUEST_FLAGS_SHARABLE` | Quest can be shared |
| `32` | `0x20` | `QUEST_FLAGS_EPIC` | Epic flag; not currently used |
| `64` | `0x40` | `QUEST_FLAGS_RAID` | Raid quest flag |
| `256` | `0x100` | `QUEST_FLAGS_UNK2` | Requires more than normal quest item drops |
| `512` | `0x200` | `QUEST_FLAGS_HIDDEN_REWARDS` | Reward items/money hidden until reward offer |
| `1024` | `0x400` | `QUEST_FLAGS_AUTO_REWARDED` | Automatically rewarded on completion; not shown in quest log |

Used by: [`Method`](#col-method)

#### `QuestMethod`

Kind: `enum`

Source: `src/game/QuestDef.h enum QuestMethod`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `QUEST_METHOD_AUTOCOMPLETE` | Method Autocomplete |
| `1` | `0x1` | `QUEST_METHOD_DISABLED` | Method Disabled |
| `2` | `0x2` | `QUEST_METHOD_DELIVER` | Method Deliver |

Used by: [`ZoneOrSort`](#col-zoneorsort)

#### `QuestSort`

Kind: `enum`

Source: `src/game/SharedDefines.h enum QuestSort`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `QUEST_SORT_EPIC` | Sort Epic |
| `21` | `0x15` | `QUEST_SORT_WAILING_CAVERNS_OLD` | Sort Wailing Caverns Old |
| `22` | `0x16` | `QUEST_SORT_SEASONAL` | Sort Seasonal |
| `23` | `0x17` | `QUEST_SORT_UNDERCITY_OLD` | Sort Undercity Old |
| `24` | `0x18` | `QUEST_SORT_HERBALISM` | Sort Herbalism |
| `25` | `0x19` | `QUEST_SORT_SCARLET_MONASTERY_OLD` | Sort Scarlet Monastery Old |
| `41` | `0x29` | `QUEST_SORT_ULDAMN_OLD` | Sort Uldamn Old |
| `61` | `0x3D` | `QUEST_SORT_WARLOCK` | Sort Warlock |
| `81` | `0x51` | `QUEST_SORT_WARRIOR` | Sort Warrior |
| `82` | `0x52` | `QUEST_SORT_SHAMAN` | Sort Shaman |
| `101` | `0x65` | `QUEST_SORT_FISHING` | Sort Fishing |
| `121` | `0x79` | `QUEST_SORT_BLACKSMITHING` | Sort Blacksmithing |
| `141` | `0x8D` | `QUEST_SORT_PALADIN` | Sort Paladin |
| `161` | `0xA1` | `QUEST_SORT_MAGE` | Sort Mage |
| `162` | `0xA2` | `QUEST_SORT_ROGUE` | Sort Rogue |
| `181` | `0xB5` | `QUEST_SORT_ALCHEMY` | Sort Alchemy |
| `182` | `0xB6` | `QUEST_SORT_LEATHERWORKING` | Sort Leatherworking |
| `201` | `0xC9` | `QUEST_SORT_ENGINEERING` | Sort Engineering |
| `221` | `0xDD` | `QUEST_SORT_TREASURE_MAP` | Sort Treasure Map |
| `241` | `0xF1` | `QUEST_SORT_SUNKEN_TEMPLE_OLD` | Sort Sunken Temple Old |
| `261` | `0x105` | `QUEST_SORT_HUNTER` | Sort Hunter |
| `262` | `0x106` | `QUEST_SORT_PRIEST` | Sort Priest |
| `263` | `0x107` | `QUEST_SORT_DRUID` | Sort Druid |
| `264` | `0x108` | `QUEST_SORT_TAILORING` | Sort Tailoring |
| `284` | `0x11C` | `QUEST_SORT_SPECIAL` | Sort Special |
| `304` | `0x130` | `QUEST_SORT_COOKING` | Sort Cooking |
| `324` | `0x144` | `QUEST_SORT_FIRST_AID` | Sort First Aid |
| `344` | `0x158` | `QUEST_SORT_LEGENDARY` | Sort Legendary |
| `364` | `0x16C` | `QUEST_SORT_DARKMOON_FAIRE` | Sort Darkmoon Faire |
| `365` | `0x16D` | `QUEST_SORT_AHN_QIRAJ_WAR` | Sort Ahn Qiraj War |
| `366` | `0x16E` | `QUEST_SORT_LUNAR_FESTIVAL` | Sort Lunar Festival |
| `367` | `0x16F` | `QUEST_SORT_REPUTATION` | Sort Reputation |
| `368` | `0x170` | `QUEST_SORT_INVASION` | Sort Invasion |
| `369` | `0x171` | `QUEST_SORT_MIDSUMMER` | Sort Midsummer |
| `370` | `0x172` | `QUEST_SORT_BREWFEST` | Sort Brewfest |
| `371` | `0x173` | `QUEST_SORT_JEWELCRAFTING` | Sort Jewelcrafting |

Used by: [`SpecialFlags`](#col-specialflags)

#### `QuestSpecialFlags`

Kind: `mask`

Source: `src/game/QuestDef.h enum QuestSpecialFlags`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `QUEST_SPECIAL_FLAG_REPEATABLE` | Repeatable quest |
| `2` | `0x2` | `QUEST_SPECIAL_FLAG_EXPLORATION_OR_EVENT` | Exploration/event objective |
| `4` | `0x4` | `QUEST_SPECIAL_FLAG_DAILY` | Daily quest |
| `8` | `0x8` | `QUEST_SPECIAL_FLAG_DELIVER` | Internal computed deliver objective |
| `16` | `0x10` | `QUEST_SPECIAL_FLAG_SPEAKTO` | Internal computed speak-to objective |
| `32` | `0x20` | `QUEST_SPECIAL_FLAG_KILL_OR_CAST` | Internal computed kill/cast objective |
| `64` | `0x40` | `QUEST_SPECIAL_FLAG_TIMED` | Internal computed timed objective |
| `128` | `0x80` | `QUEST_SPECIAL_FLAG_HARDCORE_ONLY` | Hardcore-only quest |
| `256` | `0x100` | `QUEST_SPECIAL_FLAG_YEARLY_RESET` | Yearly reset |
| `512` | `0x200` | `QUEST_SPECIAL_FLAG_CAN_SWAP_REWARDS` | Rewards can be swapped |

Used by: [`Type`](#col-type)

#### `QuestTypes`

Kind: `enum`

Source: `src/game/QuestDef.h enum QuestTypes`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `QUEST_TYPE_ELITE` | Type Elite |
| `21` | `0x15` | `QUEST_TYPE_LIFE` | Type Life |
| `41` | `0x29` | `QUEST_TYPE_PVP` | Type Pvp |
| `62` | `0x3E` | `QUEST_TYPE_RAID` | Type Raid |
| `81` | `0x51` | `QUEST_TYPE_DUNGEON` | Type Dungeon |
| `82` | `0x52` | `QUEST_TYPE_WORLD_EVENT` | Type World Event |
| `83` | `0x53` | `QUEST_TYPE_LEGENDARY` | Type Legendary |
| `84` | `0x54` | `QUEST_TYPE_ESCORT` | Type Escort |
