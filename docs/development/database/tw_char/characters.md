---
layout: default
title: characters
---

# characters

Player System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 72 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO | `PRI` | `0` |  | Global Unique Identifier; non-negative numeric value; identifier column |
| <a id="col-account"></a>`account` | `int(10) unsigned` | NO |  | `0` |  | Account Identifier; non-negative numeric value |
| <a id="col-name"></a>`name` | `varchar(12)` | NO |  | `''` |  | text/string data |
| <a id="col-race"></a>`race` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; race id or race mask; Uses Races enum values |
| <a id="col-class"></a>`class` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; class id or class mask; Uses Classes enum values |
| <a id="col-gender"></a>`gender` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value; Uses Gender enum values |
| <a id="col-level"></a>`level` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-xp"></a>`xp` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-money"></a>`money` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; money/cost value, usually copper |
| <a id="col-playerbytes"></a>`playerBytes` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-playerbytes2"></a>`playerBytes2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-playerflags"></a>`playerFlags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-position-x"></a>`position_x` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-position-y"></a>`position_y` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-position-z"></a>`position_z` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-map"></a>`map` | `int(10) unsigned` | NO |  | `0` |  | Map Identifier; non-negative numeric value |
| <a id="col-orientation"></a>`orientation` | `float` | NO |  | `0` |  | numeric value; world coordinate or orientation |
| <a id="col-taximask"></a>`taximask` | `longtext` | YES |  | `NULL` |  | text/string data; mask/flags column; combine values with bitwise OR |
| <a id="col-online"></a>`online` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-cinematic"></a>`cinematic` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-totaltime"></a>`totaltime` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-leveltime"></a>`leveltime` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-logout-time"></a>`logout_time` | `bigint(20) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-is-logout-resting"></a>`is_logout_resting` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-rest-bonus"></a>`rest_bonus` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-resettalents-multiplier"></a>`resettalents_multiplier` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-resettalents-time"></a>`resettalents_time` | `bigint(20) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-trans-x"></a>`trans_x` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-trans-y"></a>`trans_y` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-trans-z"></a>`trans_z` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-trans-o"></a>`trans_o` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-transguid"></a>`transguid` | `bigint(20) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-extra-flags"></a>`extra_flags` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-stable-slots"></a>`stable_slots` | `tinyint(1) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-at-login"></a>`at_login` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-zone"></a>`zone` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-death-expire-time"></a>`death_expire_time` | `bigint(20) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-taxi-path"></a>`taxi_path` | `text` | YES |  | `NULL` |  | text/string data |
| <a id="col-honorrankpoints"></a>`honorRankPoints` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-honorhighestrank"></a>`honorHighestRank` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-honorstanding"></a>`honorStanding` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-honorlastweekhk"></a>`honorLastWeekHK` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-honorlastweekcp"></a>`honorLastWeekCP` | `decimal(11,1)` | NO |  | `0.0` |  | numeric value |
| <a id="col-honorstoredhk"></a>`honorStoredHK` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-honorstoreddk"></a>`honorStoredDK` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-watchedfaction"></a>`watchedFaction` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-drunk"></a>`drunk` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-health"></a>`health` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-power1"></a>`power1` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-power2"></a>`power2` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-power3"></a>`power3` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-power4"></a>`power4` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-power5"></a>`power5` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-exploredzones"></a>`exploredZones` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-equipmentcache"></a>`equipmentCache` | `longtext` | YES |  | `NULL` |  | text/string data |
| <a id="col-ammoid"></a>`ammoId` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-actionbars"></a>`actionBars` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-deleteinfos-account"></a>`deleteInfos_Account` | `int(10) unsigned` | YES |  | `NULL` |  | non-negative numeric value |
| <a id="col-deleteinfos-name"></a>`deleteInfos_Name` | `varchar(12)` | YES |  | `NULL` |  | text/string data |
| <a id="col-deletedate"></a>`deleteDate` | `bigint(20)` | YES |  | `NULL` |  | numeric value |
| <a id="col-area"></a>`area` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-world-phase-mask"></a>`world_phase_mask` | `int(11)` | YES |  | `0` |  | numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-customflags"></a>`customFlags` | `int(11)` | NO |  | `0` |  | numeric value; mask/flags column; combine values with bitwise OR |
| <a id="col-city-protector"></a>`city_protector` | `tinyint(4)` | NO |  | `0` |  | numeric value |
| <a id="col-regexfiltercount"></a>`regexFilterCount` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-isgmcharacter"></a>`isGMCharacter` | `tinyint(1) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-ignore-titles"></a>`ignore_titles` | `tinyint(4)` | NO |  | `0` |  | numeric value |
| <a id="col-mortality-status"></a>`mortality_status` | `tinyint(4)` | NO |  | `0` |  | numeric value |
| <a id="col-total-deaths"></a>`total_deaths` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-xp-gain"></a>`xp_gain` | `tinyint(3) unsigned` | NO |  | `1` |  | non-negative numeric value |
| <a id="col-active"></a>`active` | `tinyint(3) unsigned` | NO |  | `1` |  | non-negative numeric value |
| <a id="col-extrabonustalentcount"></a>`extraBonusTalentCount` | `int(11)` | NO |  | `0` |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `guid`

non-negative numeric value; identifier column.

### `account`

non-negative numeric value.

### `name`

text/string data.

### `race`

non-negative numeric value; race id or race mask.

Value set: `Races` (enum) from `src/game/SharedDefines.h enum Races`.

### `class`

non-negative numeric value; class id or class mask.

Value set: `Classes` (enum) from `src/game/SharedDefines.h enum Classes`.

### `gender`

non-negative numeric value.

Value set: `Gender` (enum) from `src/game/SharedDefines.h enum Gender`.

### `level`

non-negative numeric value.

### `xp`

non-negative numeric value.

### `money`

non-negative numeric value; money/cost value, usually copper.

### `playerBytes`

non-negative numeric value.

### `playerBytes2`

non-negative numeric value.

### `playerFlags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

### `position_x`

numeric value; world coordinate or orientation.

### `position_y`

numeric value; world coordinate or orientation.

### `position_z`

numeric value; world coordinate or orientation.

### `map`

non-negative numeric value.

References: [`map_template`](../tw_world/map_template.md).`entry`.

### `orientation`

numeric value; world coordinate or orientation.

### `taximask`

text/string data; mask/flags column; combine values with bitwise OR.

### `online`

non-negative numeric value.

### `cinematic`

non-negative numeric value.

### `totaltime`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `leveltime`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `logout_time`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `is_logout_resting`

non-negative numeric value.

### `rest_bonus`

numeric value.

### `resettalents_multiplier`

non-negative numeric value.

### `resettalents_time`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `trans_x`

numeric value.

### `trans_y`

numeric value.

### `trans_z`

numeric value.

### `trans_o`

numeric value.

### `transguid`

non-negative numeric value.

### `extra_flags`

non-negative numeric value; mask/flags column; combine values with bitwise OR.

### `stable_slots`

non-negative numeric value.

### `at_login`

non-negative numeric value.

### `zone`

non-negative numeric value.

References: [`area_template`](../tw_world/area_template.md).`entry`.

### `death_expire_time`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `taxi_path`

text/string data.

### `honorRankPoints`

numeric value.

### `honorHighestRank`

non-negative numeric value.

### `honorStanding`

non-negative numeric value.

### `honorLastWeekHK`

non-negative numeric value.

### `honorLastWeekCP`

numeric value.

### `honorStoredHK`

numeric value.

### `honorStoredDK`

numeric value.

### `watchedFaction`

non-negative numeric value.

### `drunk`

non-negative numeric value.

### `health`

non-negative numeric value.

### `power1`

non-negative numeric value.

### `power2`

non-negative numeric value.

### `power3`

non-negative numeric value.

### `power4`

non-negative numeric value.

### `power5`

non-negative numeric value.

### `exploredZones`

text/string data.

### `equipmentCache`

text/string data.

### `ammoId`

non-negative numeric value.

### `actionBars`

non-negative numeric value.

### `deleteInfos_Account`

non-negative numeric value.

### `deleteInfos_Name`

text/string data.

### `deleteDate`

numeric value.

### `area`

non-negative numeric value.

References: [`area_template`](../tw_world/area_template.md).`entry`.

### `world_phase_mask`

numeric value; mask/flags column; combine values with bitwise OR.

### `customFlags`

numeric value; mask/flags column; combine values with bitwise OR.

### `city_protector`

numeric value.

### `regexFilterCount`

non-negative numeric value.

### `isGMCharacter`

non-negative numeric value.

### `ignore_titles`

numeric value.

### `mortality_status`

numeric value.

### `total_deaths`

numeric value.

### `xp_gain`

non-negative numeric value.

### `active`

non-negative numeric value.

### `extraBonusTalentCount`

numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `guid` |
| KEY | `idx_account` | `account` |
| KEY | `idx_online` | `online` |
| KEY | `idx_name` | `name` |
| KEY | `deleteDate` | `deleteDate` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `area` | [`area_template`](../tw_world/area_template.md).`entry` | heuristic | inferred from column name |
| `zone` | [`area_template`](../tw_world/area_template.md).`entry` | heuristic | inferred from column name |
| `map` | [`map_template`](../tw_world/map_template.md).`entry` | heuristic | inferred from column name |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `Classes` | enum | [`class`](#col-class) | `src/game/SharedDefines.h enum Classes` | 9 |
| `Gender` | enum | [`gender`](#col-gender) | `src/game/SharedDefines.h enum Gender` | 3 |
| `Races` | enum | [`race`](#col-race) | `src/game/SharedDefines.h enum Races` | 10 |

### Possible Values

Used by: [`class`](#col-class)

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

Used by: [`gender`](#col-gender)

#### `Gender`

Kind: `enum`

Source: `src/game/SharedDefines.h enum Gender`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `0` | `0x0` | `GENDER_MALE` | Gender Male |
| `1` | `0x1` | `GENDER_FEMALE` | Gender Female |
| `2` | `0x2` | `GENDER_NONE` | Gender None |

Used by: [`race`](#col-race)

#### `Races`

Kind: `enum`

Source: `src/game/SharedDefines.h enum Races`

| Decimal | Hex | Name | Meaning |
| --- | --- | --- | --- |
| `1` | `0x1` | `RACE_HUMAN` | Human |
| `2` | `0x2` | `RACE_ORC` | Orc |
| `3` | `0x3` | `RACE_DWARF` | Dwarf |
| `4` | `0x4` | `RACE_NIGHTELF` | Night elf |
| `5` | `0x5` | `RACE_UNDEAD_PLAYER` | Undead player |
| `6` | `0x6` | `RACE_TAUREN` | Tauren |
| `7` | `0x7` | `RACE_GNOME` | Gnome |
| `8` | `0x8` | `RACE_TROLL` | Troll |
| `9` | `0x9` | `RACE_GOBLIN` | Goblin |
| `10` | `0xA` | `RACE_HIGH_ELF` | High elf |

### Unmapped Flag-Like Columns

| Column | Type | Guidance |
| --- | --- | --- |
| [`playerFlags`](#col-playerflags) | `int(10) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
| [`taximask`](#col-taximask) | `longtext` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
| [`extra_flags`](#col-extra-flags) | `int(10) unsigned` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
| [`world_phase_mask`](#col-world-phase-mask) | `int(11)` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
| [`customFlags`](#col-customflags) | `int(11)` | Mask/flags column identified by name, but no server enum overlay has been mapped yet. Confirm definitions in code before editing values. |
