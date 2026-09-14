---
layout: default
title: "GM Command: .wareffort"
---

# `.wareffort`

- Security: Developer (3)
- Console: yes
- Subcommands: `.wareffort info`, `.wareffort setgongtime`, `.wareffort setstage`

Syntax:

```text
.wareffort <subcommand>
```

Example:

```text
.wareffort info
```

---

## `.wareffort info`

- Security: Developer (3)
- Console: yes
- Handler: `HandleWarEffortInfoCommand`


---

## `.wareffort setgongtime`

- Security: Developer (3)
- Console: yes
- Handler: `HandleWarEffortSetGongTimeCommand`

Syntax:

```text
.wareffort setgongtime <unix_time>
```

Example:

```text
.wareffort setgongtime 1798761600
```

---

## `.wareffort setstage`

- Security: Developer (3)
- Console: yes
- Handler: `HandleWarEffortSetStageCommand`

Syntax:

```text
.wareffort setstage <stage>
```

Example:

```text
.wareffort setstage 1
```

---

[Back to GM Commands](../gm-commands.md)
