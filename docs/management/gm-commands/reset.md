---
layout: default
title: "GM Command: .reset"
---

# `.reset`

- Security: Developer (3)
- Console: yes
- Subcommands: `.reset honor`, `.reset level`, `.reset spells`, `.reset stats`, `.reset talents`, `.reset all`

Syntax:

```text
.reset <subcommand>
```

Example:

```text
.reset honor
```

---

## `.reset honor`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleResetHonorCommand`

Syntax:

```text
.reset honor <player>
```

Example:

```text
.reset honor Thrall
```

---

## `.reset level`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleResetLevelCommand`

Syntax:

```text
.reset level <player>
```

Example:

```text
.reset level Thrall
```

---

## `.reset spells`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleResetSpellsCommand`

Syntax:

```text
.reset spells <player>
```

Example:

```text
.reset spells Thrall
```

---

## `.reset stats`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleResetStatsCommand`

Syntax:

```text
.reset stats <player>
```

Example:

```text
.reset stats Thrall
```

---

## `.reset talents`

- Security: Developer (3)
- Console: yes
- Handler: `HandleResetTalentsCommand`

Syntax:

```text
.reset talents <player>
```

Example:

```text
.reset talents Thrall
```

---

## `.reset all`

- Security: Console (6)
- Console: yes
- Handler: `HandleResetAllCommand`

Syntax:

```text
.reset all [arguments]
```

Example:

```text
.reset all arguments
```

---

[Back to GM Commands](../gm-commands.md)
