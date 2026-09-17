---
layout: default
title: "GM Command: .banlist"
---

# `.banlist`

- Security: Developer (3)
- Console: yes
- Subcommands: `.banlist account`, `.banlist character`, `.banlist ip`

Syntax:

```text
.banlist <subcommand>
```

Example:

```text
.banlist account
```

---

## `.banlist account`

- Security: Developer (3)
- Console: yes
- Handler: `HandleBanListAccountCommand`

Syntax:

```text
.banlist account [arguments]
```

Example:

```text
.banlist account arguments
```

---

## `.banlist character`

- Security: Developer (3)
- Console: yes
- Handler: `HandleBanListCharacterCommand`

Syntax:

```text
.banlist character [arguments]
```

Example:

```text
.banlist character arguments
```

---

## `.banlist ip`

- Security: Developer (3)
- Console: yes
- Handler: `HandleBanListIPCommand`

Syntax:

```text
.banlist ip [arguments]
```

Example:

```text
.banlist ip arguments
```

---

## `.start`

- Security: Developer (3)
- Console: no
- Handler: `HandleStartCommand`


---

## `.unstuck`

- Security: Moderator (2)
- Console: no
- Handler: `HandleUnstuckCommand`


---

## `.taxicheat`

- Security: Developer (3)
- Console: no
- Handler: `HandleTaxiCheatCommand`

Syntax:

```text
.taxicheat <on|off>
```

Example:

```text
.taxicheat on
```

---

## `.linkgrave`

- Security: Administrator (4)
- Console: no
- Handler: `HandleLinkGraveCommand`

Syntax:

```text
.linkgrave <guid>
```

Example:

```text
.linkgrave 1
```

---

## `.neargrave`

- Security: Developer (3)
- Console: no
- Handler: `HandleNearGraveCommand`

Syntax:

```text
.neargrave [arguments]
```

Example:

```text
.neargrave arguments
```

---

## `.explorecheat`

- Security: Developer (3)
- Console: no
- Handler: `HandleExploreCheatCommand`

Syntax:

```text
.explorecheat [arguments]
```

Example:

```text
.explorecheat arguments
```

---

## `.hover`

- Security: Administrator (4)
- Console: no
- Handler: `HandleHoverCommand`

Syntax:

```text
.hover [flag]
```

Example:

```text
.hover
```

---

## `.levelup`

- Security: Developer (3)
- Console: no
- Handler: `HandleLevelUpCommand`

Syntax:

```text
.levelup <addlevel> <player>
```

Example:

```text
.levelup 1 Thrall
```

---

## `.showarea`

- Security: Administrator (4)
- Console: no
- Handler: `HandleShowAreaCommand`

Syntax:

```text
.showarea [arguments]
```

Example:

```text
.showarea arguments
```

---

## `.hidearea`

- Security: Administrator (4)
- Console: no
- Handler: `HandleHideAreaCommand`

Syntax:

```text
.hidearea [arguments]
```

Example:

```text
.hidearea arguments
```

---

## `.additem`

- Security: Developer (3)
- Console: no
- Handler: `HandleAddItemCommand`

Syntax:

```text
.additem <item> [count]
```

Example:

```text
.additem 6948 1
```

---

## `.deleteitem`

- Security: Developer (3)
- Console: no
- Handler: `HandleDeleteItemCommand`

Syntax:

```text
.deleteitem <item> [count] <player>
```

Example:

```text
.deleteitem 6948 1 Thrall
```

---

## `.additemset`

- Security: Developer (3)
- Console: no
- Handler: `HandleAddItemSetCommand`

Syntax:

```text
.additemset <itemset>
```

Example:

```text
.additemset 1
```

---

## `.bank`

- Security: Developer (3)
- Console: no
- Handler: `HandleBankCommand`


---

## `.wchange`

- Security: Developer (3)
- Console: no
- Handler: `HandleChangeWeatherCommand`

Syntax:

```text
.wchange <type> <value>
```

Example:

```text
.wchange 1 1
```

---

[Back to GM Commands](../gm-commands.md)
