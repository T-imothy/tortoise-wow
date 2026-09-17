---
layout: default
title: "GM Command: .debug"
---

# `.debug`

- Security: Developer (3)
- Console: no
- Subcommands: `.debug condition`, `.debug instancedata`, `.debug packetstats`, `.debug fields`, `.debug leakreport`, `.debug coeffs`

Syntax:

```text
.debug <subcommand>
```

Example:

```text
.debug condition
```

---

## `.debug condition`

- Security: Developer (3)
- Console: no
- Handler: `HandleDebugConditionCommand`

Syntax:

```text
.debug condition <ondition_id>
```

Example:

```text
.debug condition 1
```

---

## `.debug instancedata`

- Security: Developer (3)
- Console: no
- Handler: `HandleDebugSetInstanceDataCommand`

Syntax:

```text
.debug instancedata <param1> <param2>
```

Example:

```text
.debug instancedata 1 1
```

---

## `.debug packetstats`

- Security: Developer (3)
- Console: yes
- Handler: `HandleDebugPacketStatsCommand`

Syntax:

```text
.debug packetstats <on|off>
```

Example:

```text
.debug packetstats on
```

---

## `.debug fields`

- Security: Developer (3)
- Console: no
- Subcommands: `.debug fields show`, `.debug fields modify`

Syntax:

```text
.debug fields <subcommand>
```

Example:

```text
.debug fields show
```

---

## `.debug fields show`

- Security: Developer (3)
- Console: no
- Handler: `HandleDebugFieldsShowCommand`

Syntax:

```text
.debug fields show [arguments]
```

Example:

```text
.debug fields show arguments
```

---

## `.debug fields modify`

- Security: Developer (3)
- Console: no
- Handler: `HandleDebugFieldsModifyCommand`

Syntax:

```text
.debug fields modify [arguments]
```

Example:

```text
.debug fields modify arguments
```

---

## `.debug leakreport`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleDebugLeakReportCommand`


---

## `.debug coeffs`

- Security: Developer (3)
- Console: yes
- Handler: `HandleDebugCoeffsCommand`

Syntax:

```text
.debug coeffs [arguments]
```

Example:

```text
.debug coeffs arguments
```

---

[Back to GM Commands](../gm-commands.md)
