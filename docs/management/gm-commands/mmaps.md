---
layout: default
title: "GM Command: .mmaps"
---

# `.mmaps`

- Security: Developer (3)
- Console: no
- Subcommands: `.mmaps path`, `.mmaps near`

Syntax:

```text
.mmaps <subcommand>
```

Example:

```text
.mmaps path
```

---

## `.mmaps path`

- Security: Developer (3)
- Console: no
- Handler: `HandleMmapsPathCommand`

Syntax:

```text
.mmaps path <arguments>
```

Example:

```text
.mmaps path arguments
```

---

## `.mmaps near`

- Security: Developer (3)
- Console: no
- Handler: `HandleMmapsNearCommand`

Syntax:

```text
.mmaps near <distance>
```

Example:

```text
.mmaps near 10
```

---

## `.crash`

- Security: Console (6)
- Console: yes
- Handler: `HandleCrashCommand`


---

## `.who`

- Security: Observer (1)
- Console: yes
- Handler: `HandleWhoCommand`

Syntax:

```text
.who [arguments]
```

Example:

```text
.who arguments
```

---

## `.shellcoin`

- Security: Player (0)
- Console: yes
- Handler: `HandleShellcoinCommand`


---

## `.removecorpses`

- Security: Administrator (4)
- Console: no
- Handler: `HandleRemoveCorpsesCommand`

Syntax:

```text
.removecorpses <distance>
```

Example:

```text
.removecorpses 10
```

---

[Back to GM Commands](../gm-commands.md)
