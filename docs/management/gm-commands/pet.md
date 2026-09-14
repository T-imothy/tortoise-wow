---
layout: default
title: "GM Command: .pet"
---

# `.pet`

- Security: Developer (3)
- Console: yes
- Subcommands: `.pet learnspell`, `.pet unlearnspell`, `.pet list`, `.pet rename`, `.pet delete`, `.pet loyalty`

Syntax:

```text
.pet <subcommand>
```

Example:

```text
.pet learnspell
```

---

## `.pet learnspell`

- Security: Developer (3)
- Console: no
- Handler: `HandlePetLearnSpellCommand`

Syntax:

```text
.pet learnspell [spell]
```

Example:

```text
.pet learnspell
```

---

## `.pet unlearnspell`

- Security: Developer (3)
- Console: no
- Handler: `HandlePetUnlearnSpellCommand`

Syntax:

```text
.pet unlearnspell [spell]
```

Example:

```text
.pet unlearnspell
```

---

## `.pet list`

- Security: Developer (3)
- Console: yes
- Handler: `HandlePetListCommand`

Syntax:

```text
.pet list [arguments]
```

Example:

```text
.pet list arguments
```

---

## `.pet rename`

- Security: Developer (3)
- Console: yes
- Handler: `HandlePetRenameCommand`

Syntax:

```text
.pet rename <et_id>
```

Example:

```text
.pet rename 1
```

---

## `.pet delete`

- Security: Developer (3)
- Console: yes
- Handler: `HandlePetDeleteCommand`

Syntax:

```text
.pet delete <et_id>
```

Example:

```text
.pet delete 1
```

---

## `.pet loyalty`

- Security: Developer (3)
- Console: no
- Handler: `HandlePetLoyaltyCommand`

Syntax:

```text
.pet loyalty [loyalty_points]
```

Example:

```text
.pet loyalty
```

---

[Back to GM Commands](../gm-commands.md)
