---
layout: default
title: "GM Command: .gold remove"
---

# `.gold remove`

- Security: Developer (3)
- Console: no
- Handler: `HandleGoldRemoval`

Syntax:

```text
.gold remove [arguments]
```

Example:

```text
.gold remove arguments
```

---

## `.balance`

- Security: Developer (3)
- Console: yes
- Handler: `HandleBalanceCommand`

Syntax:

```text
.balance <account> [oins_arg]
```

Example:

```text
.balance accountname
```

---

## `.mailbox`

- Security: Developer (3)
- Console: no
- Handler: `HandleMailboxCommand`


---

## `.mount`

- Security: Developer (3)
- Console: no
- Handler: `HandleMountCommand`


---

## `.transfer`

- Security: Developer (3)
- Console: no
- Handler: `HandleTransferCommand`

Syntax:

```text
.transfer player_name account_name
```

Example:

```text
.transfer player_name account_name
```

---

## `.bgtest`

- Security: Administrator (4)
- Console: no
- Handler: `HandleBgTestCommand`


---

## `.cinematic`

- Security: Administrator (4)
- Console: no
- Handler: `HandleTurtleCinematic`

Syntax:

```text
.cinematic <cinematic_id>
```

Example:

```text
.cinematic 1
```

---

## `.dbghard`

- Security: Administrator (4)
- Console: no
- Handler: `HandleFastDebugCommand`


---

## `.debugloot`

- Security: Developer (3)
- Console: yes
- Handler: `HandleDebugLootTableCommand`

Syntax:

```text
.debugloot [arguments]
```

Example:

```text
.debugloot arguments
```

---

## `.loothelper`

- Security: Developer (3)
- Console: no
- Handler: `HandleLootHelperCommand`

Syntax:

```text
.loothelper <entry>
```

Example:

```text
.loothelper 1
```

---

## `.anim`

- Security: Developer (3)
- Console: no
- Handler: `HandleDebugAnimCommand`

Syntax:

```text
.anim <emote_id>
```

Example:

```text
.anim 1
```

---

## `.copy`

- Security: Player (0)
- Console: no
- Handler: `HandleCopyCommand`

Syntax:

```text
.copy [arguments]
```

Example:

```text
.copy arguments
```

---

## `.guildname`

- Security: Player (0)
- Console: no
- Handler: `HandleGuildNameCommand`

Syntax:

```text
.guildname [arguments]
```

Example:

```text
.guildname arguments
```

---

## `.petname`

- Security: Player (0)
- Console: no
- Handler: `HandlePetNameCommand`

Syntax:

```text
.petname [arguments]
```

Example:

```text
.petname arguments
```

---

## `.sendpacket`

- Security: Administrator (4)
- Console: no
- Handler: `HandleSendPacketCommand`


---

[Back to GM Commands](../gm-commands.md)
