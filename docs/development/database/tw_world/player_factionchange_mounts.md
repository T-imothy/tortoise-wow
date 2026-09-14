---
layout: default
title: player_factionchange_mounts
---

# player_factionchange_mounts

World database table `player_factionchange_mounts`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-raceid"></a>`RaceId` | `int(11)` | NO | `PRI` |  |  | numeric value; Uses Races enum values |
| <a id="col-mountnum"></a>`MountNum` | `int(11)` | NO | `PRI` |  |  | numeric value |
| <a id="col-itementry"></a>`ItemEntry` | `int(11)` | NO |  |  |  | numeric value |
| <a id="col-comment"></a>`Comment` | `varchar(255)` | NO |  | `''` |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `RaceId`

numeric value.

Value set: `Races` (enum) from `src/game/SharedDefines.h enum Races`.

### `MountNum`

numeric value.

### `ItemEntry`

numeric value.

References: [`item_template`](item_template.md).`entry`.

### `Comment`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `RaceId`, `MountNum` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `ItemEntry` | [`item_template`](item_template.md).`entry` | heuristic | inferred from column name |

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `Races` | enum | [`RaceId`](#col-raceid) | `src/game/SharedDefines.h enum Races` | 10 |

### Possible Values

Used by: [`RaceId`](#col-raceid)

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
