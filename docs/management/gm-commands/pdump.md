---
layout: default
title: "GM Command: .pdump"
---

# `.pdump`

- Security: Administrator (4)
- Console: yes
- Subcommands: `.pdump list`, `.pdump load`, `.pdump write`

Syntax:

```text
.pdump <subcommand>
```

Example:

```text
.pdump list
```

---

## `.pdump list`

- Security: Administrator (4)
- Console: yes
- Handler: `HandlePDumpListCommand`

Syntax:

```text
.pdump list <guid_low>
```

Example:

```text
.pdump list 1
```

---

## `.pdump load`

- Security: Administrator (4)
- Console: yes
- Handler: `HandlePDumpLoadCommand`

Syntax:

```text
.pdump load <account> <lowguid>
```

Example:

```text
.pdump load accountname 1
```

---

## `.pdump write`

- Security: Administrator (4)
- Console: yes
- Handler: `HandlePDumpWriteCommand`

Syntax:

```text
.pdump write [arguments]
```

Example:

```text
.pdump write arguments
```

---

[Back to GM Commands](../gm-commands.md)
