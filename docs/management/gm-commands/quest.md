---
layout: default
title: "GM Command: .quest"
---

# `.quest`

- Security: Developer (3)
- Console: no
- Subcommands: `.quest add`, `.quest complete`, `.quest status`, `.quest remove`, `.quest test`

Syntax:

```text
.quest <subcommand>
```

Example:

```text
.quest add
```

---

## `.quest add`

- Security: Developer (3)
- Console: no
- Handler: `HandleQuestAddCommand`

Syntax:

```text
.quest add <quest> <player>
```

Example:

```text
.quest add 1 Thrall
```

---

## `.quest complete`

- Security: Developer (3)
- Console: no
- Handler: `HandleQuestCompleteCommand`

Syntax:

```text
.quest complete <quest> <player>
```

Example:

```text
.quest complete 1 Thrall
```

---

## `.quest status`

- Security: Moderator (2)
- Console: no
- Handler: `HandleQuestStatusCommand`

Syntax:

```text
.quest status <quest> <player>
```

Example:

```text
.quest status 1 Thrall
```

---

## `.quest remove`

- Security: Developer (3)
- Console: no
- Handler: `HandleQuestRemoveCommand`

Syntax:

```text
.quest remove <quest> <player>
```

Example:

```text
.quest remove 1 Thrall
```

---

## `.quest test`

- Security: Developer (3)
- Console: no
- Handler: `HandleQuestTestCommand`


---

[Back to GM Commands](../gm-commands.md)
