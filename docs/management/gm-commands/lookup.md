---
layout: default
title: "GM Command: .lookup"
---

# `.lookup`

- Security: Moderator (2)
- Console: yes
- Subcommands: `.lookup creature`, `.lookup faction`, `.lookup item`, `.lookup object`, `.lookup quest`, `.lookup player`, `.lookup skill`, `.lookup spell`, `.lookup itemset`, `.lookup event`, `.lookup guild`, `.lookup hwprint`

Syntax:

```text
.lookup <subcommand>
```

Example:

```text
.lookup creature
```

---

## `.lookup creature`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleLookupCreatureCommand`

Syntax:

```text
.lookup creature [arguments]
```

Example:

```text
.lookup creature arguments
```

---

## `.lookup faction`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleLookupFactionCommand`

Syntax:

```text
.lookup faction [arguments]
```

Example:

```text
.lookup faction arguments
```

---

## `.lookup item`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleLookupItemCommand`

Syntax:

```text
.lookup item [arguments]
```

Example:

```text
.lookup item arguments
```

---

## `.lookup object`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleLookupObjectCommand`

Syntax:

```text
.lookup object [arguments]
```

Example:

```text
.lookup object arguments
```

---

## `.lookup quest`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleLookupQuestCommand`

Syntax:

```text
.lookup quest [arguments]
```

Example:

```text
.lookup quest arguments
```

---

## `.lookup player`

- Security: Moderator (2)
- Console: yes
- Subcommands: `.lookup player account`, `.lookup player email`, `.lookup player ip`, `.lookup player name`, `.lookup player character`

Syntax:

```text
.lookup player <subcommand>
```

Example:

```text
.lookup player account
```

---

## `.lookup player account`

- Security: Moderator (2)
- Console: no
- Handler: `HandleLookupPlayerAccountCommand`

Syntax:

```text
.lookup player account [limit]
```

Example:

```text
.lookup player account
```

---

## `.lookup player email`

- Security: Moderator (2)
- Console: no
- Handler: `HandleLookupPlayerEmailCommand`

Syntax:

```text
.lookup player email [limit]
```

Example:

```text
.lookup player email
```

---

## `.lookup player ip`

- Security: Moderator (2)
- Console: no
- Handler: `HandleLookupPlayerIpCommand`

Syntax:

```text
.lookup player ip [limit]
```

Example:

```text
.lookup player ip
```

---

## `.lookup player name`

- Security: Moderator (2)
- Console: no
- Handler: `HandleLookupPlayerNameCommand`

Syntax:

```text
.lookup player name [limit]
```

Example:

```text
.lookup player name
```

---

## `.lookup player character`

- Security: Moderator (2)
- Console: no
- Handler: `HandleLookupPlayerCharacterCommand`

Syntax:

```text
.lookup player character [limit]
```

Example:

```text
.lookup player character
```

---

## `.lookup skill`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleLookupSkillCommand`

Syntax:

```text
.lookup skill [arguments]
```

Example:

```text
.lookup skill arguments
```

---

## `.lookup spell`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleLookupSpellCommand`

Syntax:

```text
.lookup spell [arguments]
```

Example:

```text
.lookup spell arguments
```

---

## `.lookup itemset`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleLookupItemSetCommand`

Syntax:

```text
.lookup itemset [arguments]
```

Example:

```text
.lookup itemset arguments
```

---

## `.lookup event`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleLookupEventCommand`

Syntax:

```text
.lookup event [arguments]
```

Example:

```text
.lookup event arguments
```

---

## `.lookup guild`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleLookupGuildCommand`

Syntax:

```text
.lookup guild [arguments]
```

Example:

```text
.lookup guild arguments
```

---

## `.lookup hwprint`

- Security: Developer (3)
- Console: no
- Handler: `HandleLookupHwPrintCommand`

Syntax:

```text
.lookup hwprint [arguments]
```

Example:

```text
.lookup hwprint arguments
```

---

[Back to GM Commands](../gm-commands.md)
