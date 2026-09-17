---
layout: default
title: "GM Command: .baninfo"
---

# `.baninfo`

- Security: Moderator (2)
- Console: no
- Subcommands: `.baninfo account`, `.baninfo character`, `.baninfo ip`

Syntax:

```text
.baninfo <subcommand>
```

Example:

```text
.baninfo account
```

---

## `.baninfo account`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleBanInfoAccountCommand`

Syntax:

```text
.baninfo account <account>
```

Example:

```text
.baninfo account accountname
```

---

## `.baninfo character`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleBanInfoCharacterCommand`

Syntax:

```text
.baninfo character <player>
```

Example:

```text
.baninfo character Thrall
```

---

## `.baninfo ip`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleBanInfoIPCommand`

Syntax:

```text
.baninfo ip [arguments]
```

Example:

```text
.baninfo ip arguments
```

---

[Back to GM Commands](../gm-commands.md)
