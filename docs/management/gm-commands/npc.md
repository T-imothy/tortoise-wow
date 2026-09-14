---
layout: default
title: "GM Command: .npc"
---

# `.npc`

- Security: Developer (3)
- Console: no
- Subcommands: `.npc add`, `.npc summon`, `.npc additem`, `.npc scale`, `.npc addweapon`, `.npc aiinfo`, `.npc wander`, `.npc delete`, `.npc delitem`, `.npc evade`, `.npc factionid`, `.npc flag`, `.npc follow`, `.npc unfollow`, `.npc info`, `.npc move`, `.npc playemote`, `.npc say`, `.npc speed`, `.npc textemote`, `.npc yell`, `.npc toptarget`, `.npc near`, `.npc group`, `.npc spawn`, `.npc template`

Syntax:

```text
.npc <subcommand>
```

Example:

```text
.npc add
```

---

## `.npc add`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcAddCommand`

Syntax:

```text
.npc add <creature_id>
```

Example:

```text
.npc add 1
```

---

## `.npc summon`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcSummonCommand`

Syntax:

```text
.npc summon <creature_id>
```

Example:

```text
.npc summon 1
```

---

## `.npc additem`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcAddVendorItemCommand`

Syntax:

```text
.npc additem <item> [maxcount] [incrtime] [itemflags]
```

Example:

```text
.npc additem 6948
```

---

## `.npc scale`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcScaleCommand`

Syntax:

```text
.npc scale [arguments]
```

Example:

```text
.npc scale arguments
```

---

## `.npc addweapon`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcAddWeaponCommand`

Syntax:

```text
.npc addweapon <slot> <item>
```

Example:

```text
.npc addweapon 1 6948
```

---

## `.npc aiinfo`

- Security: Administrator (4)
- Console: no
- Handler: `HandleNpcAIInfoCommand`


---

## `.npc wander`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcSetWanderDistanceCommand`

Syntax:

```text
.npc wander <distance>
```

Example:

```text
.npc wander 10
```

---

## `.npc delete`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcDeleteCommand`

Syntax:

```text
.npc delete <creature>
```

Example:

```text
.npc delete 1
```

---

## `.npc delitem`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcDelVendorItemCommand`

Syntax:

```text
.npc delitem <item>
```

Example:

```text
.npc delitem 6948
```

---

## `.npc evade`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcEvadeCommand`


---

## `.npc factionid`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcFactionIdCommand`

Syntax:

```text
.npc factionid [arguments]
```

Example:

```text
.npc factionid arguments
```

---

## `.npc flag`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcFlagCommand`

Syntax:

```text
.npc flag [arguments]
```

Example:

```text
.npc flag arguments
```

---

## `.npc follow`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcFollowCommand`


---

## `.npc unfollow`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcUnfollowCommand`


---

## `.npc info`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcInfoCommand`


---

## `.npc move`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcMoveCommand`

Syntax:

```text
.npc move [arguments]
```

Example:

```text
.npc move arguments
```

---

## `.npc playemote`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcPlayEmoteCommand`

Syntax:

```text
.npc playemote [arguments]
```

Example:

```text
.npc playemote arguments
```

---

## `.npc say`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcSayCommand`

Syntax:

```text
.npc say [arguments]
```

Example:

```text
.npc say arguments
```

---

## `.npc speed`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcSpeedCommand`

Syntax:

```text
.npc speed [arguments]
```

Example:

```text
.npc speed arguments
```

---

## `.npc textemote`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcTextEmoteCommand`

Syntax:

```text
.npc textemote [arguments]
```

Example:

```text
.npc textemote arguments
```

---

## `.npc yell`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcYellCommand`

Syntax:

```text
.npc yell [arguments]
```

Example:

```text
.npc yell arguments
```

---

## `.npc toptarget`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcTopTarget`


---

## `.npc near`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcNearCommand`

Syntax:

```text
.npc near [distance]
```

Example:

```text
.npc near
```

---

## `.npc group`

- Security: Administrator (4)
- Console: no
- Subcommands: `.npc group add`, `.npc group addrel`, `.npc group del`, `.npc group link`

Syntax:

```text
.npc group <subcommand>
```

Example:

```text
.npc group add
```

---

## `.npc group add`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcGroupAddCommand`

Syntax:

```text
.npc group add <leader_guid_counter> [options]
```

Example:

```text
.npc group add 1
```

---

## `.npc group addrel`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcGroupAddRelCommand`

Syntax:

```text
.npc group addrel <leader_guid_counter> [options]
```

Example:

```text
.npc group addrel 1
```

---

## `.npc group del`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcGroupDelCommand`


---

## `.npc group link`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcGroupLinkCommand`

Syntax:

```text
.npc group link <leader_guid_counter> [options]
```

Example:

```text
.npc group link 1
```

---

## `.npc spawn`

- Security: Moderator (2)
- Console: no
- Subcommands: `.npc spawn add`, `.npc spawn addentry`, `.npc spawn delete`, `.npc spawn info`, `.npc spawn set`, `.npc spawn move`

Syntax:

```text
.npc spawn <subcommand>
```

Example:

```text
.npc spawn add
```

---

## `.npc spawn add`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcAddCommand`

Syntax:

```text
.npc spawn add <creature_id>
```

Example:

```text
.npc spawn add 1
```

---

## `.npc spawn addentry`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcAddEntryCommand`

Syntax:

```text
.npc spawn addentry <creature_id>
```

Example:

```text
.npc spawn addentry 1
```

---

## `.npc spawn delete`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcDeleteCommand`

Syntax:

```text
.npc spawn delete <creature>
```

Example:

```text
.npc spawn delete 1
```

---

## `.npc spawn info`

- Security: Moderator (2)
- Console: no
- Handler: `HandleNpcSpawnInfoCommand`


---

## `.npc spawn set`

- Security: Developer (3)
- Console: no
- Subcommands: `.npc spawn set entry`, `.npc spawn set displayid`, `.npc spawn set emotestate`, `.npc spawn set standstate`, `.npc spawn set sheathstate`, `.npc spawn set movetype`, `.npc spawn set wanderdistance`, `.npc spawn set respawntime`, `.npc spawn set deathstate`, `.npc spawn set auras`

Syntax:

```text
.npc spawn set <subcommand>
```

Example:

```text
.npc spawn set entry
```

---

## `.npc spawn set entry`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcSpawnSetEntryCommand`

Syntax:

```text
.npc spawn set entry <reature_id>
```

Example:

```text
.npc spawn set entry 1
```

---

## `.npc spawn set displayid`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcSpawnSetDisplayIdCommand`

Syntax:

```text
.npc spawn set displayid <display_id>
```

Example:

```text
.npc spawn set displayid 1
```

---

## `.npc spawn set emotestate`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcSpawnSetEmoteStateCommand`

Syntax:

```text
.npc spawn set emotestate <emote_id>
```

Example:

```text
.npc spawn set emotestate 1
```

---

## `.npc spawn set standstate`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcSpawnSetStandStateCommand`

Syntax:

```text
.npc spawn set standstate <stand_state>
```

Example:

```text
.npc spawn set standstate 1
```

---

## `.npc spawn set sheathstate`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcSpawnSetSheathStateCommand`

Syntax:

```text
.npc spawn set sheathstate <sheath_state>
```

Example:

```text
.npc spawn set sheathstate 1
```

---

## `.npc spawn set movetype`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcSpawnSetMoveTypeCommand`

Syntax:

```text
.npc spawn set movetype [NODEL]
```

Example:

```text
.npc spawn set movetype
```

---

## `.npc spawn set wanderdistance`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcSpawnWanderDistCommand`

Syntax:

```text
.npc spawn set wanderdistance <wander_distance>
```

Example:

```text
.npc spawn set wanderdistance 1
```

---

## `.npc spawn set respawntime`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcSpawnSetRespawnTimeCommand`

Syntax:

```text
.npc spawn set respawntime <time_min> <time_max>
```

Example:

```text
.npc spawn set respawntime 1 1
```

---

## `.npc spawn set deathstate`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcSpawnSetDeathStateCommand`

Syntax:

```text
.npc spawn set deathstate <on|off>
```

Example:

```text
.npc spawn set deathstate on
```

---

## `.npc spawn set auras`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcSpawnSetAurasCommand`

Syntax:

```text
.npc spawn set auras [arguments]
```

Example:

```text
.npc spawn set auras arguments
```

---

## `.npc spawn move`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcSpawnMoveCommand`

Syntax:

```text
.npc spawn move [arguments]
```

Example:

```text
.npc spawn move arguments
```

---

## `.npc template`

- Security: Developer (3)
- Console: no
- Subcommands: `.npc template set`

Syntax:

```text
.npc template <subcommand>
```

Example:

```text
.npc template set
```

---

## `.npc template set`

- Security: Developer (3)
- Console: no
- Subcommands: `.npc template set displayid`, `.npc template set mountdisplayid`, `.npc template set level`, `.npc template set faction`, `.npc template set scale`, `.npc template set detectionrange`, `.npc template set callforhelprange`, `.npc template set leashrange`

Syntax:

```text
.npc template set <subcommand>
```

Example:

```text
.npc template set displayid
```

---

## `.npc template set displayid`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcTemplateSetDisplayIdCommand`

Syntax:

```text
.npc template set displayid [display_id]
```

Example:

```text
.npc template set displayid
```

---

## `.npc template set mountdisplayid`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcTemplateSetMountDisplayIdCommand`

Syntax:

```text
.npc template set mountdisplayid <mount_display_id>
```

Example:

```text
.npc template set mountdisplayid 1
```

---

## `.npc template set level`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcTemplateSetLevelCommand`

Syntax:

```text
.npc template set level <level_min> [level_max]
```

Example:

```text
.npc template set level 1
```

---

## `.npc template set faction`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcTemplateSetFactionCommand`

Syntax:

```text
.npc template set faction <faction_template_id>
```

Example:

```text
.npc template set faction 1
```

---

## `.npc template set scale`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcTemplateSetScaleCommand`

Syntax:

```text
.npc template set scale <scale>
```

Example:

```text
.npc template set scale 1
```

---

## `.npc template set detectionrange`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcTemplateSetDetectionRangeCommand`

Syntax:

```text
.npc template set detectionrange <range>
```

Example:

```text
.npc template set detectionrange 1
```

---

## `.npc template set callforhelprange`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcTemplateSetCallForHelpRangeCommand`

Syntax:

```text
.npc template set callforhelprange <range>
```

Example:

```text
.npc template set callforhelprange 1
```

---

## `.npc template set leashrange`

- Security: Developer (3)
- Console: no
- Handler: `HandleNpcTemplateSetLeashRangeCommand`

Syntax:

```text
.npc template set leashrange <range>
```

Example:

```text
.npc template set leashrange 1
```

---

[Back to GM Commands](../gm-commands.md)
