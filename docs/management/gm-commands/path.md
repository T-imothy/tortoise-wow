---
layout: default
title: "GM Command: .path"
---

# `.path`

- Security: Developer (3)
- Console: yes
- Subcommands: `.path setup`, `.path add`, `.path start`

Syntax:

```text
.path <subcommand>
```

Example:

```text
.path setup
```

---

## `.path setup`

- Security: Developer (3)
- Console: no
- Handler: `HandleCreaturePathSetup`


---

## `.path add`

- Security: Developer (3)
- Console: no
- Handler: `HandleCreaturePathAddPoint`


---

## `.path start`

- Security: Developer (3)
- Console: no
- Handler: `HandleCreaturePathLaunch`


---

## `.xp`

- Security: Player (0)
- Console: no
- Handler: `HandleXPCommand`

Syntax:

```text
.xp <on|off>
```

Example:

```text
.xp on
```

---

## `.settime`

- Security: Developer (3)
- Console: no
- Handler: `HandleSetTimeCommand`

Syntax:

```text
.settime <hour>
```

Example:

```text
.settime 1
```

---

## `.play`

- Security: Developer (3)
- Console: no
- Handler: `HandlePlayCommand`

Syntax:

```text
.play sound_id
```

Example:

```text
.play sound_id
```

---

## `.radio`

- Security: Player (0)
- Console: no
- Handler: `HandleRadioCommand`

Syntax:

```text
.radio [arguments]
```

Example:

```text
.radio arguments
```

---

## `.getskillvalue`

- Security: Developer (3)
- Console: no
- Handler: `HandleGetSkillValueCommand`

Syntax:

```text
.getskillvalue [arguments]
```

Example:

```text
.getskillvalue arguments
```

---

[Back to GM Commands](../gm-commands.md)
