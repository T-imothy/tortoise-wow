---
layout: default
title: "GM Command: .account"
---

# `.account`

- Security: Player (0)
- Console: yes
- Handler: `HandleAccountCommand`
- Subcommands: `.account characters`, `.account create`, `.account delete`, `.account email`, `.account getname`, `.account set`, `.account password`, `.account twofa`

Syntax:

```text
.account [arguments]
```

Example:

```text
.account arguments
```

---

## `.account characters`

- Security: Developer (3)
- Console: yes
- Handler: `HandleAccountCharactersCommand`

Syntax:

```text
.account characters <account>
```

Example:

```text
.account characters accountname
```

---

## `.account create`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleAccountCreateCommand`

Syntax:

```text
.account create <account> <password>
```

Example:

```text
.account create accountname "newpass"
```

---

## `.account delete`

- Security: Console (6)
- Console: yes
- Handler: `HandleAccountDeleteCommand`

Syntax:

```text
.account delete <account>
```

Example:

```text
.account delete accountname
```

---

## `.account email`

- Security: Player (0)
- Console: no
- Handler: `HandleAccountEmailCommand`

Syntax:

```text
.account email <old_email> <new_email> <new_email_confirm>
```

Example:

```text
.account email old@example.test new@example.test new@example.test
```

---

## `.account getname`

- Security: Observer (1)
- Console: yes
- Handler: `HandleAccountGetNameCommand`

Syntax:

```text
.account getname <account>
```

Example:

```text
.account getname accountname
```

---

## `.account set`

- Security: Developer (3)
- Console: yes
- Subcommands: `.account set gmlevel`, `.account set password`

Syntax:

```text
.account set <subcommand>
```

Example:

```text
.account set gmlevel
```

---

## `.account set gmlevel`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleAccountSetGmLevelCommand`

Syntax:

```text
.account set gmlevel <account> <gm_level>
```

Example:

```text
.account set gmlevel accountname 3
```

---

## `.account set password`

- Security: Developer (3)
- Console: yes
- Handler: `HandleAccountSetPasswordCommand`

Syntax:

```text
.account set password <account> <password> <password_confirm>
```

Example:

```text
.account set password accountname "newpass" "newpass"
```

---

## `.account password`

- Security: Player (0)
- Console: yes
- Handler: `HandleAccountPasswordCommand`

Syntax:

```text
.account password <old_password> <new_password> <new_password_confirm>
```

Example:

```text
.account password "oldpass" "newpass" "newpass"
```

---

## `.account twofa`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleAccountFaCommand`

Syntax:

```text
.account twofa <account>
```

Example:

```text
.account twofa accountname
```

---

[Back to GM Commands](../gm-commands.md)
