---
layout: default
title: "GM Command: .guild"
---

# `.guild`

- Security: Developer (3)
- Console: yes
- Subcommands: `.guild create`, `.guild delete`, `.guild invite`, `.guild uninvite`, `.guild rank`, `.guild rename`, `.guild leader`, `.guild listen`, `.guild house`

Syntax:

```text
.guild <subcommand>
```

Example:

```text
.guild create
```

---

## `.guild create`

- Security: Developer (3)
- Console: yes
- Handler: `HandleGuildCreateCommand`

Syntax:

```text
.guild create <player>
```

Example:

```text
.guild create Thrall
```

---

## `.guild delete`

- Security: Developer (3)
- Console: yes
- Handler: `HandleGuildDeleteCommand`

Syntax:

```text
.guild delete [arguments]
```

Example:

```text
.guild delete arguments
```

---

## `.guild invite`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleGuildInviteCommand`

Syntax:

```text
.guild invite <player>
```

Example:

```text
.guild invite Thrall
```

---

## `.guild uninvite`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleGuildUninviteCommand`

Syntax:

```text
.guild uninvite <player>
```

Example:

```text
.guild uninvite Thrall
```

---

## `.guild rank`

- Security: Developer (3)
- Console: yes
- Handler: `HandleGuildRankCommand`

Syntax:

```text
.guild rank <player> <rank>
```

Example:

```text
.guild rank Thrall 0
```

---

## `.guild rename`

- Security: Developer (3)
- Console: yes
- Handler: `HandleGuildRenameCommand`

Syntax:

```text
.guild rename [arguments]
```

Example:

```text
.guild rename arguments
```

---

## `.guild leader`

- Security: Developer (3)
- Console: no
- Handler: `HandleGuildLeaderCommand`

Syntax:

```text
.guild leader <player>
```

Example:

```text
.guild leader Thrall
```

---

## `.guild listen`

- Security: Developer (3)
- Console: no
- Handler: `HandleGuildListenCommand`

Syntax:

```text
.guild listen [arguments]
```

Example:

```text
.guild listen arguments
```

---

## `.guild house`

- Security: Developer (3)
- Console: no
- Handler: `HandleGuildHouseCommand`

Syntax:

```text
.guild house on / off
```

Example:

```text
.guild house on / off
```

---

[Back to GM Commands](../gm-commands.md)
