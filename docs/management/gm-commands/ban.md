---
layout: default
title: "GM Command: .ban"
---

# `.ban`

- Security: Moderator (2)
- Console: yes
- Subcommands: `.ban account`, `.ban allip`, `.ban character`, `.ban fingerprint`, `.ban ip`, `.ban warn`, `.ban removewarn`

Syntax:

```text
.ban <subcommand>
```

Example:

```text
.ban account
```

---

## `.ban account`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleBanAccountCommand`

Syntax:

```text
.ban account [arguments]
```

Example:

```text
.ban account arguments
```

---

## `.ban allip`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleBanAllIPCommand`

Syntax:

```text
.ban allip [arguments]
```

Example:

```text
.ban allip arguments
```

---

## `.ban character`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleBanCharacterCommand`

Syntax:

```text
.ban character [arguments]
```

Example:

```text
.ban character arguments
```

---

## `.ban fingerprint`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleBanFingerprintCommand`

Syntax:

```text
.ban fingerprint <fingerprint>
```

Example:

```text
.ban fingerprint 123456
```

---

## `.ban ip`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleBanIPCommand`

Syntax:

```text
.ban ip [arguments]
```

Example:

```text
.ban ip arguments
```

---

## `.ban warn`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleWarnCharacterCommand`

Syntax:

```text
.ban warn <player>
```

Example:

```text
.ban warn Thrall
```

---

## `.ban removewarn`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleRemoveWarnCommand`

Syntax:

```text
.ban removewarn <warning_id>
```

Example:

```text
.ban removewarn 1
```

---

[Back to GM Commands](../gm-commands.md)
