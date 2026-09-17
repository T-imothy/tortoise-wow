---
layout: default
title: "GM Command: .server"
---

# `.server`

- Security: Player (0)
- Console: yes
- Subcommands: `.server corpses`, `.server exit`, `.server idlerestart`, `.server idleshutdown`, `.server info`, `.server resetallraids`, `.server restart`, `.server shutdown`

Syntax:

```text
.server <subcommand>
```

Example:

```text
.server corpses
```

---

## `.server corpses`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleServerCorpsesCommand`


---

## `.server exit`

- Security: Console (6)
- Console: yes
- Handler: `HandleServerExitCommand`


---

## `.server idlerestart`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleServerIdleRestartCommand`
- Subcommands: `.server idlerestart cancel`

Syntax:

```text
.server idlerestart <delay> [exit_code]
```

Example:

```text
.server idlerestart 60 0
```

---

## `.server idlerestart cancel`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleServerShutDownCancelCommand`


---

## `.server idleshutdown`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleServerIdleShutDownCommand`
- Subcommands: `.server idleshutdown cancel`

Syntax:

```text
.server idleshutdown <delay> [exit_code]
```

Example:

```text
.server idleshutdown 60 0
```

---

## `.server idleshutdown cancel`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleServerShutDownCancelCommand`


---

## `.server info`

- Security: Player (0)
- Console: yes
- Handler: `HandleServerInfoCommand`


---

## `.server resetallraids`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleServerResetAllRaidCommand`


---

## `.server restart`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleServerRestartCommand`
- Subcommands: `.server restart cancel`

Syntax:

```text
.server restart <delay> [exit_code]
```

Example:

```text
.server restart 60 0
```

---

## `.server restart cancel`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleServerShutDownCancelCommand`


---

## `.server shutdown`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleServerShutDownCommand`
- Subcommands: `.server shutdown cancel`

Syntax:

```text
.server shutdown <delay> [exit_code]
```

Example:

```text
.server shutdown 60 0
```

---

## `.server shutdown cancel`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleServerShutDownCancelCommand`


---

[Back to GM Commands](../gm-commands.md)
