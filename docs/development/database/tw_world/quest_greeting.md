---
layout: default
title: quest_greeting
---

# quest_greeting

World database table `quest_greeting`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 13 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-entry"></a>`entry` | `mediumint(8) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value; identifier column |
| <a id="col-type"></a>`type` | `tinyint(3) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-content-default"></a>`content_default` | `text` | NO |  |  |  | text/string data |
| <a id="col-content-loc1"></a>`content_loc1` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-content-loc2"></a>`content_loc2` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-content-loc3"></a>`content_loc3` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-content-loc4"></a>`content_loc4` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-content-loc5"></a>`content_loc5` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-content-loc6"></a>`content_loc6` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-content-loc7"></a>`content_loc7` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-content-loc8"></a>`content_loc8` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-emote-id"></a>`emote_id` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Emote enum values |
| <a id="col-emote-delay"></a>`emote_delay` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `entry`

non-negative numeric value; identifier column.

### `type`

non-negative numeric value.

### `content_default`

text/string data.

### `content_loc1`

text/string data.

### `content_loc2`

text/string data.

### `content_loc3`

text/string data.

### `content_loc4`

text/string data.

### `content_loc5`

text/string data.

### `content_loc6`

text/string data.

### `content_loc7`

text/string data.

### `content_loc8`

text/string data.

### `emote_id`

non-negative numeric value.

Value set: `Emote` (enum) from `src/game/SharedDefines.h enum Emote`.

### `emote_delay`

non-negative numeric value; time/delay value; confirm unit in server usage.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `entry`, `type` |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `Emote` | enum | [`emote_id`](#col-emote-id) | `src/game/SharedDefines.h enum Emote` | 117 |

### Possible Values

Used by: [`emote_id`](#col-emote-id)

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
