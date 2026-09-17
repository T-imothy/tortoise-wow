---
layout: default
title: miraclerace_checkpoint
---

# miraclerace_checkpoint

World database table `miraclerace_checkpoint`.

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| InnoDB | 9 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-id"></a>`id` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value; identifier column |
| <a id="col-raceid"></a>`raceid` | `int(10) unsigned` | NO |  |  |  | non-negative numeric value; Uses Races enum values |
| <a id="col-positionx"></a>`positionx` | `float` | NO |  |  |  | numeric value |
| <a id="col-positiony"></a>`positiony` | `float` | NO |  |  |  | numeric value |
| <a id="col-positionz"></a>`positionz` | `float` | NO |  |  |  | numeric value |
| <a id="col-cameraposx"></a>`cameraposx` | `float` | NO |  |  |  | numeric value |
| <a id="col-cameraposy"></a>`cameraposy` | `float` | NO |  |  |  | numeric value |
| <a id="col-cameraposz"></a>`cameraposz` | `float` | NO |  |  |  | numeric value |
| <a id="col-cameraposorientation"></a>`cameraposorientation` | `float` | NO |  |  |  | numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `id`

non-negative numeric value; identifier column.

### `raceid`

non-negative numeric value.

Value set: `Races` (enum) from `src/game/SharedDefines.h enum Races`.

### `positionx`

numeric value.

### `positiony`

numeric value.

### `positionz`

numeric value.

### `cameraposx`

numeric value.

### `cameraposy`

numeric value.

### `cameraposz`

numeric value.

### `cameraposorientation`

numeric value.

## Keys and Indexes

No keys were declared in the parsed CREATE TABLE statement.

## Masks and Flags

Known enum, ID, mask, and flag definitions are listed here. Mask and flag columns combine values with bitwise OR; enum and ID columns store one listed value.

| Value Set | Kind | Used By | Source | Values |
| --- | --- | --- | --- | --- |
| `Races` | enum | [`raceid`](#col-raceid) | `src/game/SharedDefines.h enum Races` | 10 |

### Possible Values

Used by: [`raceid`](#col-raceid)

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
