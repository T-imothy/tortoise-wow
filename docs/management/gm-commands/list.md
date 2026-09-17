---
layout: default
title: "GM Command: .list"
---

# `.list`

- Security: Administrator (4)
- Console: yes
- Subcommands: `.list auras`, `.list creature`, `.list clicktomove`, `.list exploredareas`, `.list object`, `.list buybackitems`, `.list destroyeditems`, `.list hostilerefs`, `.list threat`, `.list battlegrounds`, `.list maps`

Syntax:

```text
.list <subcommand>
```

Example:

```text
.list auras
```

---

## `.list auras`

- Security: Developer (3)
- Console: no
- Handler: `HandleListAurasCommand`


---

## `.list creature`

- Security: Developer (3)
- Console: yes
- Handler: `HandleListCreatureCommand`

Syntax:

```text
.list creature <creature_id> [count]
```

Example:

```text
.list creature 1 1
```

---

## `.list clicktomove`

- Security: Developer (3)
- Console: yes
- Handler: `HandleListClickToMoveCommand`

Syntax:

```text
.list clicktomove <level_min> <level_max>
```

Example:

```text
.list clicktomove 1 1
```

---

## `.list exploredareas`

- Security: Developer (3)
- Console: no
- Handler: `HandleListExploredAreasCommand`


---

## `.list object`

- Security: Developer (3)
- Console: yes
- Handler: `HandleListObjectCommand`

Syntax:

```text
.list object <gameobject_id> [count]
```

Example:

```text
.list object 1 1
```

---

## `.list buybackitems`

- Security: Observer (1)
- Console: yes
- Handler: `HandleListBuybackItemsCommand`

Syntax:

```text
.list buybackitems <player>
```

Example:

```text
.list buybackitems Thrall
```

---

## `.list destroyeditems`

- Security: Observer (1)
- Console: yes
- Handler: `HandleListDestroyedItemsCommand`

Syntax:

```text
.list destroyeditems [arguments]
```

Example:

```text
.list destroyeditems arguments
```

---

## `.list hostilerefs`

- Security: Observer (1)
- Console: no
- Handler: `HandleListHostileRefsCommand`


---

## `.list threat`

- Security: Observer (1)
- Console: no
- Handler: `HandleListThreatCommand`


---

## `.list battlegrounds`

- Security: Developer (3)
- Console: yes
- Handler: `ListBattlegroundsCommand`


---

## `.list maps`

- Security: Developer (3)
- Console: yes
- Handler: `HandleListMapsCommand`


---

[Back to GM Commands](../gm-commands.md)
