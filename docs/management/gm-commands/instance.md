---
layout: default
title: "GM Command: .instance"
---

# `.instance`

- Security: Administrator (4)
- Console: yes
- Subcommands: `.instance continents`, `.instance listbinds`, `.instance unbind`, `.instance groupunbind`, `.instance stats`, `.instance perfinfos`

Syntax:

```text
.instance <subcommand>
```

Example:

```text
.instance continents
```

---

## `.instance continents`

- Security: Developer (3)
- Console: yes
- Handler: `HandleInstanceContinentsCommand`


---

## `.instance listbinds`

- Security: Developer (3)
- Console: no
- Handler: `HandleInstanceListBindsCommand`


---

## `.instance unbind`

- Security: Developer (3)
- Console: no
- Handler: `HandleInstanceUnbindCommand`

Syntax:

```text
.instance unbind [arguments]
```

Example:

```text
.instance unbind arguments
```

---

## `.instance groupunbind`

- Security: Developer (3)
- Console: no
- Handler: `HandleInstanceGroupUnbindCommand`

Syntax:

```text
.instance groupunbind [arguments]
```

Example:

```text
.instance groupunbind arguments
```

---

## `.instance stats`

- Security: Developer (3)
- Console: yes
- Handler: `HandleInstanceStatsCommand`


---

## `.instance perfinfos`

- Security: Developer (3)
- Console: no
- Handler: `HandleInstancePerfInfosCommand`


---

[Back to GM Commands](../gm-commands.md)
