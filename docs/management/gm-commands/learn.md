---
layout: default
title: "GM Command: .learn"
---

# `.learn`

- Security: Developer (3)
- Console: no
- Handler: `HandleLearnCommand`
- Subcommands: `.learn all_myspells`, `.learn all_recipes`, `.learn all_trainer`, `.learn all_items`

Syntax:

```text
.learn <spell> [all] [force]
```

Example:

```text
.learn 133 all force
```

---

## `.learn all_myspells`

- Security: Developer (3)
- Console: no
- Handler: `HandleLearnAllMySpellsCommand`


---

## `.learn all_recipes`

- Security: Developer (3)
- Console: no
- Handler: `HandleLearnAllRecipesCommand`

Syntax:

```text
.learn all_recipes [arguments]
```

Example:

```text
.learn all_recipes arguments
```

---

## `.learn all_trainer`

- Security: Developer (3)
- Console: no
- Handler: `HandleLearnAllTrainerCommand`

Syntax:

```text
.learn all_trainer [trainer_id]
```

Example:

```text
.learn all_trainer
```

---

## `.learn all_items`

- Security: Developer (3)
- Console: no
- Handler: `HandleLearnAllItemsCommand`


---

[Back to GM Commands](../gm-commands.md)
