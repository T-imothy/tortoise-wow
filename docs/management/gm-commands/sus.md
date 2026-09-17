---
layout: default
title: "GM Command: .sus"
---

# `.sus`

- Security: Developer (3)
- Console: no
- Subcommands: `.sus enable`, `.sus movementenable`, `.sus movementdetectvalue`, `.sus fishingenable`, `.sus killednpcenabled`, `.sus whitelist`, `.sus notify`, `.sus fishers`

Syntax:

```text
.sus <subcommand>
```

Example:

```text
.sus enable
```

---

## `.sus enable`

- Security: Developer (3)
- Console: yes
- Handler: `HandleSuspiciousEnable`

Syntax:

```text
.sus enable <on|off>
```

Example:

```text
.sus enable on
```

---

## `.sus movementenable`

- Security: Developer (3)
- Console: yes
- Handler: `HandleSuspiciousMovementEnable`

Syntax:

```text
.sus movementenable <on|off>
```

Example:

```text
.sus movementenable on
```

---

## `.sus movementdetectvalue`

- Security: Developer (3)
- Console: yes
- Handler: `HandleSuspiciousMovementDetectValue`

Syntax:

```text
.sus movementdetectvalue <value>
```

Example:

```text
.sus movementdetectvalue 1
```

---

## `.sus fishingenable`

- Security: Developer (3)
- Console: yes
- Handler: `HandleSuspiciousFishingEnable`

Syntax:

```text
.sus fishingenable <on|off>
```

Example:

```text
.sus fishingenable on
```

---

## `.sus killednpcenabled`

- Security: Developer (3)
- Console: yes
- Handler: `HandleSuspiciousKilledNPC`

Syntax:

```text
.sus killednpcenabled <on|off>
```

Example:

```text
.sus killednpcenabled on
```

---

## `.sus whitelist`

- Security: Developer (3)
- Console: yes
- Handler: `HandleSuspiciousWhitelist`

Syntax:

```text
.sus whitelist [arguments]
```

Example:

```text
.sus whitelist arguments
```

---

## `.sus notify`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleSuspiciousNotify`

Syntax:

```text
.sus notify <on|off>
```

Example:

```text
.sus notify on
```

---

## `.sus fishers`

- Security: Observer (1)
- Console: no
- Handler: `HandleSuspiciousFishers`


---

## `.cartographer`

- Security: Player (0)
- Console: no
- Handler: `HandleCartographerCommand`


---

## `.variable`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleVariableCommand`

Syntax:

```text
.variable [arguments]
```

Example:

```text
.variable arguments
```

---

## `.god`

- Security: Developer (3)
- Console: no
- Handler: `HandleGodCommand`

Syntax:

```text
.god <on|off>
```

Example:

```text
.god on
```

---

## `.aura`

- Security: Developer (3)
- Console: no
- Handler: `HandleAuraCommand`

Syntax:

```text
.aura <spell> [duration]
```

Example:

```text
.aura 133
```

---

## `.unaura`

- Security: Developer (3)
- Console: no
- Handler: `HandleUnAuraCommand`

Syntax:

```text
.unaura <spell>
```

Example:

```text
.unaura 133
```

---

## `.broadcast`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleAnnounceCommand`

Syntax:

```text
.broadcast [arguments]
```

Example:

```text
.broadcast arguments
```

---

## `.notify`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleNotifyCommand`

Syntax:

```text
.notify [arguments]
```

Example:

```text
.notify arguments
```

---

## `.goname`

- Security: Observer (1)
- Console: no
- Handler: `HandleGonameCommand`

Syntax:

```text
.goname <player>
```

Example:

```text
.goname Thrall
```

---

## `.summon`

- Security: Moderator (2)
- Console: no
- Handler: `HandleSummonCommand`

Syntax:

```text
.summon <player>
```

Example:

```text
.summon Thrall
```

---

## `.groupgo`

- Security: Moderator (2)
- Console: no
- Handler: `HandleGroupgoCommand`

Syntax:

```text
.groupgo <player>
```

Example:

```text
.groupgo Thrall
```

---

## `.appear`

- Security: Observer (1)
- Console: no
- Handler: `HandleGonameCommand`

Syntax:

```text
.appear <player>
```

Example:

```text
.appear Thrall
```

---

## `.groupsummon`

- Security: Moderator (2)
- Console: no
- Handler: `HandleGroupgoCommand`

Syntax:

```text
.groupsummon <player>
```

Example:

```text
.groupsummon Thrall
```

---

## `.commands`

- Security: Player (0)
- Console: yes
- Handler: `HandleCommandsCommand`


---

## `.demorph`

- Security: Moderator (2)
- Console: no
- Handler: `HandleDeMorphCommand`


---

## `.die`

- Security: Developer (3)
- Console: no
- Handler: `HandleDieCommand`


---

## `.fear`

- Security: Developer (3)
- Console: no
- Handler: `HandleFearCommand`


---

## `.revive`

- Security: Developer (3)
- Console: yes
- Handler: `HandleReviveCommand`

Syntax:

```text
.revive <player>
```

Example:

```text
.revive Thrall
```

---

## `.replenish`

- Security: Developer (3)
- Console: no
- Handler: `HandleReplenishCommand`


---

## `.dismount`

- Security: Developer (3)
- Console: no
- Handler: `HandleDismountCommand`


---

## `.los`

- Security: Observer (1)
- Console: no
- Handler: `HandleLoSCommand`


---

## `.gps`

- Security: Observer (1)
- Console: no
- Handler: `HandleGPSCommand`

Syntax:

```text
.gps <guid>
```

Example:

```text
.gps 1
```

---

## `.guid`

- Security: Moderator (2)
- Console: no
- Handler: `HandleGUIDCommand`


---

## `.help`

- Security: Observer (1)
- Console: yes
- Handler: `HandleHelpCommand`

Syntax:

```text
.help [arguments]
```

Example:

```text
.help arguments
```

---

## `.itemmove`

- Security: Developer (3)
- Console: no
- Handler: `HandleItemMoveCommand`

Syntax:

```text
.itemmove <arguments>
```

Example:

```text
.itemmove arguments
```

---

## `.cooldown`

- Security: Developer (3)
- Console: no
- Handler: `HandleCooldownCommand`

Syntax:

```text
.cooldown <spell>
```

Example:

```text
.cooldown 133
```

---

## `.unlearn`

- Security: Developer (3)
- Console: no
- Handler: `HandleUnLearnCommand`

Syntax:

```text
.unlearn <spell> [all]
```

Example:

```text
.unlearn 133 all
```

---

## `.unlearnoffline`

- Security: Developer (3)
- Console: no
- Handler: `HandleUnLearnOfflineCommand`

Syntax:

```text
.unlearnoffline <spell> [all] [player]
```

Example:

```text
.unlearnoffline 133 all Thrall
```

---

## `.distance`

- Security: Developer (3)
- Console: no
- Handler: `HandleGetDistanceCommand`

Syntax:

```text
.distance <guid>
```

Example:

```text
.distance 1
```

---

## `.recall`

- Security: Developer (3)
- Console: no
- Handler: `HandleRecallCommand`

Syntax:

```text
.recall <player>
```

Example:

```text
.recall Thrall
```

---

## `.save`

- Security: Developer (3)
- Console: no
- Handler: `HandleSaveCommand`


---

## `.wareffortget`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleGetWarEffortResource`


---

## `.wareffortset`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleSetWarEffortResource`


---

## `.saveall`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleSaveAllCommand`


---

## `.kick`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleKickPlayerCommand`

Syntax:

```text
.kick <player>
```

Example:

```text
.kick Thrall
```

---

[Back to GM Commands](../gm-commands.md)
