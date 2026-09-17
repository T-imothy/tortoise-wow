---
layout: default
title: "GM Command: .go"
---

# `.go`

- Security: Developer (3)
- Console: no
- Handler: `HandleGoCommand`
- Subcommands: `.go creature`, `.go object`, `.go target`, `.go taxinode`, `.go trigger`, `.go xyz`, `.go corpse`, `.go graveyard`, `.go forward`, `.go up`

Syntax:

```text
.go [x] <y> <z> [mapid] <x> <y> <z> [map] [orientation]
```

Example:

```text
.go 0 0 0 0 0 0 0
```

---

## `.go creature`

- Security: Observer (1)
- Console: no
- Handler: `HandleGoCreatureCommand`

Syntax:

```text
.go creature <creature_guid>
.go creature id <creature_template_entry>
```

Example:

```text
.go creature 1
.go creature id 12345
```

The default numeric argument is the spawn GUID from `tw_world.creature.guid`.
Use `id` only when you intentionally want to search by
`tw_world.creature_template.entry`.

---

## `.go object`

- Security: Observer (1)
- Console: no
- Handler: `HandleGoObjectCommand`

Syntax:

```text
.go object <gameobject_guid>
.go object id <gameobject_template_entry>
```

Example:

```text
.go object 1
.go object id 12345
```

The default numeric argument is the spawn GUID from `tw_world.gameobject.guid`.
Use `id` only when you intentionally want to search by
`tw_world.gameobject_template.entry`.

---

## `.go target`

- Security: Observer (1)
- Console: no
- Handler: `HandleGoTargetCommand`


---

## `.go taxinode`

- Security: Observer (1)
- Console: no
- Handler: `HandleGoTaxinodeCommand`

Syntax:

```text
.go taxinode <taxinode>
```

Example:

```text
.go taxinode 1
```

---

## `.go trigger`

- Security: Observer (1)
- Console: no
- Handler: `HandleGoTriggerCommand`

Syntax:

```text
.go trigger [target]
```

Example:

```text
.go trigger
```

---

## `.go xyz`

- Security: Observer (1)
- Console: no
- Handler: `HandleGoXYZCommand`

Syntax:

```text
.go xyz <x> <y> <z> [mapid]
```

Example:

```text
.go xyz 0 0 0
```

---

## `.go corpse`

- Security: Developer (3)
- Console: no
- Handler: `HandleGoCorpseCommand`
- Help: Teleports the user to their corpse.


---

## `.go graveyard`

- Security: Observer (1)
- Console: no
- Handler: `HandleGoGraveyardCommand`

Syntax:

```text
.go graveyard <graveyard_id>
```

Example:

```text
.go graveyard 1
```

---

## `.go forward`

- Security: Observer (1)
- Console: no
- Handler: `HandleGoForwardCommand`

Syntax:

```text
.go forward [arguments]
```

Example:

```text
.go forward arguments
```

---

## `.go up`

- Security: Observer (1)
- Console: no
- Handler: `HandleGoUpCommand`

Syntax:

```text
.go up [arguments]
```

Example:

```text
.go up arguments
```

---

[Back to GM Commands](../gm-commands.md)
