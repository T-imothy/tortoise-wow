---
layout: default
title: "GM Command: .unban"
---

# `.unban`

- Security: Developer (3)
- Console: yes
- Subcommands: `.unban account`, `.unban character`, `.unban ip`, `.unban fingerprint`

Syntax:

```text
.unban <subcommand>
```

Example:

```text
.unban account
```

---

## `.unban account`

- Security: Developer (3)
- Console: yes
- Handler: `HandleUnBanAccountCommand`

Syntax:

```text
.unban account [arguments]
```

Example:

```text
.unban account arguments
```

---

## `.unban character`

- Security: Developer (3)
- Console: yes
- Handler: `HandleUnBanCharacterCommand`

Syntax:

```text
.unban character [arguments]
```

Example:

```text
.unban character arguments
```

---

## `.unban ip`

- Security: Developer (3)
- Console: yes
- Handler: `HandleUnBanIPCommand`

Syntax:

```text
.unban ip [arguments]
```

Example:

```text
.unban ip arguments
```

---

## `.unban fingerprint`

- Security: Developer (3)
- Console: yes
- Handler: `HandleUnBanFingerprintCommand`

Syntax:

```text
.unban fingerprint <fingerprint>
```

Example:

```text
.unban fingerprint 123456
```

---

[Back to GM Commands](../gm-commands.md)
