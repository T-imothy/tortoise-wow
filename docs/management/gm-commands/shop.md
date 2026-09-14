---
layout: default
title: "GM Command: .shop"
---

# `.shop`

- Security: Developer (3)
- Console: yes
- Subcommands: `.shop log`, `.shop refund`

Syntax:

```text
.shop <subcommand>
```

Example:

```text
.shop log
```

---

## `.shop log`

- Security: Developer (3)
- Console: no
- Handler: `HandleGetShopLogs`

Syntax:

```text
.shop log [arguments]
```

Example:

```text
.shop log arguments
```

---

## `.shop refund`

- Security: Developer (3)
- Console: no
- Handler: `HandleShopRefundCommand`

Syntax:

```text
.shop refund [shop_id]
```

Example:

```text
.shop refund
```

---

[Back to GM Commands](../gm-commands.md)
