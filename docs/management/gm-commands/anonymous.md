---
layout: default
title: "GM Command: .anonymous"
---

# `.anonymous`

- Security: Developer (3)
- Console: no
- Subcommands: `.anonymous whispers`, `.anonymous mail`

Syntax:

```text
.anonymous <subcommand>
```

Example:

```text
.anonymous whispers
```

---

## `.anonymous whispers`

- Security: Developer (3)
- Console: no
- Handler: `HandleAnonymousWhispers`

Syntax:

```text
.anonymous whispers [arguments]
```

Example:

```text
.anonymous whispers arguments
```

---

## `.anonymous mail`

- Security: Developer (3)
- Console: no
- Handler: `HandleAnonymousMail`


---

## `.hcmessages`

- Security: Player (0)
- Console: no
- Handler: `HandleHCMessagesCommand`

Syntax:

```text
.hcmessages <minlevel>
```

Example:

```text
.hcmessages 1
```

---

[Back to GM Commands](../gm-commands.md)
