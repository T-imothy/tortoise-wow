---
layout: default
title: "GM Command: .tele"
---

# `.tele`

- Security: Observer (1)
- Console: no
- Handler: `HandleTeleCommand`
- Subcommands: `.tele add`, `.tele del`, `.tele name`, `.tele group`

Syntax:

```text
.tele <teleport_name>
```

Example:

```text
.tele Stormwind
```

---

## `.tele add`

- Security: Developer (3)
- Console: no
- Handler: `HandleTeleAddCommand`

Syntax:

```text
.tele add [arguments]
```

Example:

```text
.tele add arguments
```

---

## `.tele del`

- Security: Developer (3)
- Console: yes
- Handler: `HandleTeleDelCommand`

Syntax:

```text
.tele del [arguments]
```

Example:

```text
.tele del arguments
```

---

## `.tele name`

- Security: Developer (3)
- Console: yes
- Handler: `HandleTeleNameCommand`

Syntax:

```text
.tele name <player> <teleport_name>
```

Example:

```text
.tele name Thrall Stormwind
```

---

## `.tele group`

- Security: Developer (3)
- Console: no
- Handler: `HandleTeleGroupCommand`

Syntax:

```text
.tele group <teleport_name>
```

Example:

```text
.tele group Stormwind
```

---

[Back to GM Commands](../gm-commands.md)
