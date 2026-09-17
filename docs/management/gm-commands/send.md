---
layout: default
title: "GM Command: .send"
---

# `.send`

- Security: Developer (3)
- Console: yes
- Subcommands: `.send items`, `.send mail`, `.send message`, `.send money`

Syntax:

```text
.send <subcommand>
```

Example:

```text
.send items
```

---

## `.send items`

- Security: Developer (3)
- Console: yes
- Handler: `HandleSendItemsCommand`

Syntax:

```text
.send items <player>
```

Example:

```text
.send items Thrall
```

---

## `.send mail`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleSendMailCommand`

Syntax:

```text
.send mail <player>
```

Example:

```text
.send mail Thrall
```

---

## `.send message`

- Security: Developer (3)
- Console: yes
- Handler: `HandleSendMessageCommand`

Syntax:

```text
.send message <player>
```

Example:

```text
.send message Thrall
```

---

## `.send money`

- Security: Developer (3)
- Console: yes
- Handler: `HandleSendMoneyCommand`

Syntax:

```text
.send money <player>
```

Example:

```text
.send money Thrall
```

---

## `.mute`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleMuteCommand`

Syntax:

```text
.mute <player> <minutes>
```

Example:

```text
.mute Thrall 1
```

---

## `.pausingmute`

- Security: Moderator (2)
- Console: yes
- Handler: `HandlePausingMuteCommand`

Syntax:

```text
.pausingmute <player> <notspeaktime>
```

Example:

```text
.pausingmute Thrall 1
```

---

## `.unmute`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleUnmuteCommand`

Syntax:

```text
.unmute <player>
```

Example:

```text
.unmute Thrall
```

---

## `.movegens`

- Security: Developer (3)
- Console: no
- Handler: `HandleMovegensCommand`


---

## `.cometome`

- Security: Developer (3)
- Console: no
- Handler: `HandleComeToMeCommand`


---

## `.aoedamage`

- Security: Developer (3)
- Console: no
- Handler: `HandleAoEDamageCommand`

Syntax:

```text
.aoedamage [damage] [range]
```

Example:

```text
.aoedamage 30
```

---

## `.damage`

- Security: Developer (3)
- Console: no
- Handler: `HandleDamageCommand`

Syntax:

```text
.damage <damage> <school> <spell>
```

Example:

```text
.damage 100 0 133
```

---

## `.combatstop`

- Security: Moderator (2)
- Console: no
- Handler: `HandleCombatStopCommand`

Syntax:

```text
.combatstop <player>
```

Example:

```text
.combatstop Thrall
```

---

## `.repairitems`

- Security: Developer (3)
- Console: yes
- Handler: `HandleRepairitemsCommand`

Syntax:

```text
.repairitems <player>
```

Example:

```text
.repairitems Thrall
```

---

## `.waterwalk`

- Security: Developer (3)
- Console: no
- Handler: `HandleWaterwalkCommand`

Syntax:

```text
.waterwalk <on|off>
```

Example:

```text
.waterwalk on
```

---

## `.quit`

- Security: Console (6)
- Console: yes
- Handler: `HandleQuitCommand`


---

## `.freeze`

- Security: Moderator (2)
- Console: no
- Handler: `HandleFreezeCommand`

Syntax:

```text
.freeze <player>
```

Example:

```text
.freeze Thrall
```

---

## `.unfreeze`

- Security: Moderator (2)
- Console: no
- Handler: `HandleUnfreezeCommand`

Syntax:

```text
.unfreeze <player>
```

Example:

```text
.unfreeze Thrall
```

---

[Back to GM Commands](../gm-commands.md)
