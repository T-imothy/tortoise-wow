---
layout: default
title: "GM Command: .wp"
---

# `.wp`

- Security: Administrator (4)
- Console: no
- Subcommands: `.wp show`, `.wp add`, `.wp modify`, `.wp export`

Syntax:

```text
.wp <subcommand>
```

Example:

```text
.wp show
```

---

## `.wp show`

- Security: Administrator (4)
- Console: no
- Handler: `HandleWpShowCommand`

Syntax:

```text
.wp show [wp_path_id] [src] <db_guid>
```

Example:

```text
.wp show 1
```

---

## `.wp add`

- Security: Administrator (4)
- Console: no
- Handler: `HandleWpAddCommand`

Syntax:

```text
.wp add <db_guid> [wp_path_id] [src]
```

Example:

```text
.wp add 1
```

---

## `.wp modify`

- Security: Administrator (4)
- Console: no
- Handler: `HandleWpModifyCommand`

Syntax:

```text
.wp modify <db_guid> <wp_id> <waittime> <script_id> <ori>
```

Example:

```text
.wp modify 1 1 1 1 1
```

---

## `.wp export`

- Security: Administrator (4)
- Console: no
- Handler: `HandleWpExportCommand`

Syntax:

```text
.wp export <db_guid> [wp_path_id] [src]
```

Example:

```text
.wp export 1
```

---

[Back to GM Commands](../gm-commands.md)
