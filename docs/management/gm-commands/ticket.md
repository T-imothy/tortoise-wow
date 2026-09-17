---
layout: default
title: "GM Command: .ticket"
---

# `.ticket`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleGMTicketGetByIdOrNameCommand`
- Subcommands: `.ticket assign`, `.ticket unassign`, `.ticket close`, `.ticket list`, `.ticket onlinelist`

Syntax:

```text
.ticket [arguments]
```

Example:

```text
.ticket arguments
```

---

## `.ticket assign`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleGMTicketAssignToCommand`

Syntax:

```text
.ticket assign <arguments>
```

Example:

```text
.ticket assign arguments
```

---

## `.ticket unassign`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleGMTicketUnAssignCommand`

Syntax:

```text
.ticket unassign [arguments]
```

Example:

```text
.ticket unassign arguments
```

---

## `.ticket close`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleGMTicketCloseByIdCommand`

Syntax:

```text
.ticket close [arguments]
```

Example:

```text
.ticket close arguments
```

---

## `.ticket list`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleGMTicketListCommand`

Syntax:

```text
.ticket list [arguments]
```

Example:

```text
.ticket list arguments
```

---

## `.ticket onlinelist`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleGMTicketsOnlineListCommand`


---

## `.maxskill`

- Security: Developer (3)
- Console: no
- Handler: `HandleMaxSkillCommand`


---

## `.setskill`

- Security: Developer (3)
- Console: no
- Handler: `HandleSetSkillCommand`

Syntax:

```text
.setskill <skill> <level> [max_skill]
```

Example:

```text
.setskill 95 60 300
```

---

## `.whispers`

- Security: Moderator (2)
- Console: no
- Handler: `HandleWhispersCommand`

Syntax:

```text
.whispers <on|off>
```

Example:

```text
.whispers on
```

---

## `.pinfo`

- Security: Moderator (2)
- Console: yes
- Handler: `HandlePInfoCommand`

Syntax:

```text
.pinfo <player>
```

Example:

```text
.pinfo Thrall
```

---

## `.groupinfo`

- Security: Developer (3)
- Console: yes
- Handler: `HandleGroupInfoCommand`

Syntax:

```text
.groupinfo <player>
```

Example:

```text
.groupinfo Thrall
```

---

## `.addons`

- Security: Developer (3)
- Console: no
- Handler: `HandleListAddonsCommand`


---

## `.respawn`

- Security: Developer (3)
- Console: no
- Handler: `HandleRespawnCommand`


---

[Back to GM Commands](../gm-commands.md)
