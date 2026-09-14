---
layout: default
title: "GM Command: .trigger"
---

# `.trigger`

- Security: Observer (1)
- Console: yes
- Handler: `HandleTriggerCommand`
- Subcommands: `.trigger active`, `.trigger near`

Syntax:

```text
.trigger <areatrigger>
```

Example:

```text
.trigger 1
```

---

## `.trigger active`

- Security: Observer (1)
- Console: no
- Handler: `HandleTriggerActiveCommand`


---

## `.trigger near`

- Security: Observer (1)
- Console: no
- Handler: `HandleTriggerNearCommand`

Syntax:

```text
.trigger near [arguments]
```

Example:

```text
.trigger near arguments
```

---

[Back to GM Commands](../gm-commands.md)
