---
layout: default
title: "GM Command: .cast"
---

# `.cast`

- Security: Developer (3)
- Console: no
- Handler: `HandleCastCommand`
- Subcommands: `.cast self`, `.cast target`

Syntax:

```text
.cast <spell> [triggered]
```

Example:

```text
.cast 133 triggered
```

---

## `.cast self`

- Security: Developer (3)
- Console: no
- Handler: `HandleCastSelfCommand`

Syntax:

```text
.cast self <spell> [triggered]
```

Example:

```text
.cast self 133 triggered
```

---

## `.cast target`

- Security: Developer (3)
- Console: no
- Handler: `HandleCastTargetCommand`

Syntax:

```text
.cast target <spell> [triggered]
```

Example:

```text
.cast target 133 triggered
```

---

## `.castcustom`

- Security: Developer (3)
- Console: no
- Handler: `HandleCastCustomCommand`

Syntax:

```text
.castcustom <spell> [basepoint0]
```

Example:

```text
.castcustom 133
```

---

[Back to GM Commands](../gm-commands.md)
