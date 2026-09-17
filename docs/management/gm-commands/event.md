---
layout: default
title: "GM Command: .event"
---

# `.event`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleEventInfoCommand`
- Subcommands: `.event list`, `.event start`, `.event stop`, `.event enable`, `.event disable`

Syntax:

```text
.event <gameevent>
```

Example:

```text
.event 1
```

---

## `.event list`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleEventListCommand`

Syntax:

```text
.event list [arguments]
```

Example:

```text
.event list arguments
```

---

## `.event start`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleEventStartCommand`

Syntax:

```text
.event start <gameevent>
```

Example:

```text
.event start 1
```

---

## `.event stop`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleEventStopCommand`

Syntax:

```text
.event stop <gameevent>
```

Example:

```text
.event stop 1
```

---

## `.event enable`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleEventEnableCommand`

Syntax:

```text
.event enable <gameevent>
```

Example:

```text
.event enable 1
```

---

## `.event disable`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleEventDisableCommand`

Syntax:

```text
.event disable <gameevent>
```

Example:

```text
.event disable 1
```

---

[Back to GM Commands](../gm-commands.md)
