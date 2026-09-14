---
layout: default
title: "GM Command: .character"
---

# `.character`

- Security: Developer (3)
- Console: yes
- Subcommands: `.character deleted`, `.character erase`, `.character getname`, `.character diffitems`, `.character reputation`, `.character hasitem`, `.character fillflys`, `.character clean`, `.character itemlog`, `.character mail`, `.character inactivity`

Syntax:

```text
.character <subcommand>
```

Example:

```text
.character deleted
```

---

## `.character deleted`

- Security: Developer (3)
- Console: yes
- Subcommands: `.character deleted list`, `.character deleted restore`

Syntax:

```text
.character deleted <subcommand>
```

Example:

```text
.character deleted list
```

---

## `.character deleted list`

- Security: Developer (3)
- Console: yes
- Subcommands: `.character deleted list name`

Syntax:

```text
.character deleted list <subcommand>
```

Example:

```text
.character deleted list name
```

---

## `.character deleted list name`

- Security: Developer (3)
- Console: yes
- Handler: `HandleCharacterDeletedListNameCommand`

Syntax:

```text
.character deleted list name [arguments]
```

Example:

```text
.character deleted list name arguments
```

---

## `.character deleted restore`

- Security: Developer (3)
- Console: yes
- Handler: `HandleCharacterDeletedRestoreCommand`

Syntax:

```text
.character deleted restore [arguments]
```

Example:

```text
.character deleted restore arguments
```

---

## `.character erase`

- Security: Console (6)
- Console: yes
- Handler: `HandleCharacterEraseCommand`

Syntax:

```text
.character erase <player>
```

Example:

```text
.character erase Thrall
```

---

## `.character getname`

- Security: Observer (1)
- Console: yes
- Handler: `HandleCharacterGetNameCommand`

Syntax:

```text
.character getname <guid_low>
```

Example:

```text
.character getname 1
```

---

## `.character diffitems`

- Security: Observer (1)
- Console: yes
- Handler: `HandleCharacterDiffItemsCommand`

Syntax:

```text
.character diffitems <player>
```

Example:

```text
.character diffitems Thrall
```

---

## `.character reputation`

- Security: Developer (3)
- Console: yes
- Handler: `HandleCharacterReputationCommand`

Syntax:

```text
.character reputation <player>
```

Example:

```text
.character reputation Thrall
```

---

## `.character hasitem`

- Security: Developer (3)
- Console: yes
- Handler: `HandleCharacterHasItemCommand`

Syntax:

```text
.character hasitem <item> <player>
```

Example:

```text
.character hasitem 6948 Thrall
```

---

## `.character fillflys`

- Security: Developer (3)
- Console: yes
- Handler: `HandleCharacterFillFlysCommand`


---

## `.character clean`

- Security: Console (6)
- Console: yes
- Subcommands: `.character clean todelete`, `.character clean items`

Syntax:

```text
.character clean <subcommand>
```

Example:

```text
.character clean todelete
```

---

## `.character clean todelete`

- Security: Console (6)
- Console: yes
- Handler: `HandleCleanCharactersToDeleteCommand`


---

## `.character clean items`

- Security: Console (6)
- Console: yes
- Handler: `HandleCleanCharactersItemsCommand`


---

## `.character itemlog`

- Security: Developer (3)
- Console: yes
- Handler: `HandleItemLogCommand`

Syntax:

```text
.character itemlog <player> <item>
```

Example:

```text
.character itemlog Thrall 6948
```

---

## `.character mail`

- Security: Developer (3)
- Console: yes
- Subcommands: `.character mail list`, `.character mail delete`

Syntax:

```text
.character mail <subcommand>
```

Example:

```text
.character mail list
```

---

## `.character mail list`

- Security: Developer (3)
- Console: yes
- Handler: `HandleCharacterMailListCommand`

Syntax:

```text
.character mail list <player>
```

Example:

```text
.character mail list Thrall
```

---

## `.character mail delete`

- Security: Developer (3)
- Console: yes
- Handler: `HandleCharacterMailDeleteCommand`

Syntax:

```text
.character mail delete <player> <mail_id>
```

Example:

```text
.character mail delete Thrall 1
```

---

## `.character inactivity`

- Security: Observer (1)
- Console: no
- Handler: `HandleCharacterInactivityDataCommand`


---

## `.rename`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleCharacterRenameCommand`

Syntax:

```text
.rename <player>
```

Example:

```text
.rename Thrall
```

---

[Back to GM Commands](../gm-commands.md)
