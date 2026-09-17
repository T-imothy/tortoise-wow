---
layout: default
title: "GM Command: .gobject"
---

# `.gobject`

- Security: Developer (3)
- Console: no
- Subcommands: `.gobject add`, `.gobject tmpadd`, `.gobject delete`, `.gobject move`, `.gobject rotate`, `.gobject near`, `.gobject target`, `.gobject turn`, `.gobject scale`, `.gobject info`, `.gobject select`, `.gobject despawn`, `.gobject toggle`, `.gobject reset`, `.gobject respawn`, `.gobject set`, `.gobject customanim`

Syntax:

```text
.gobject <subcommand>
```

Example:

```text
.gobject add
```

---

## `.gobject add`

- Security: Developer (3)
- Console: no
- Handler: `HandleGameObjectAddCommand`

Syntax:

```text
.gobject add <gameobject_id> [spawntime_secs]
```

Example:

```text
.gobject add 1
```

---

## `.gobject tmpadd`

- Security: Developer (3)
- Console: no
- Handler: `HandleGameObjectTempAddCommand`

Syntax:

```text
.gobject tmpadd <gameobject_id> <arguments>
```

Example:

```text
.gobject tmpadd 1 arguments
```

---

## `.gobject delete`

- Security: Developer (3)
- Console: no
- Handler: `HandleGameObjectDeleteCommand`

Syntax:

```text
.gobject delete <gameobject> <entry>
```

Example:

```text
.gobject delete 1 1
```

---

## `.gobject move`

- Security: Developer (3)
- Console: no
- Handler: `HandleGameObjectMoveCommand`

Syntax:

```text
.gobject move <gameobject> <x> <y> <z>
```

Example:

```text
.gobject move 1 0 0 0
```

---

## `.gobject rotate`

- Security: Developer (3)
- Console: no
- Handler: `HandleGameObjectRotateCommand`

Syntax:

```text
.gobject rotate <gameobject> <o>
```

Example:

```text
.gobject rotate 1 1
```

---

## `.gobject near`

- Security: Developer (3)
- Console: no
- Handler: `HandleGameObjectNearCommand`

Syntax:

```text
.gobject near [distance]
```

Example:

```text
.gobject near
```

---

## `.gobject target`

- Security: Developer (3)
- Console: no
- Handler: `HandleGameObjectTargetCommand`

Syntax:

```text
.gobject target <gameobject_id>
```

Example:

```text
.gobject target 1
```

---

## `.gobject turn`

- Security: Developer (3)
- Console: no
- Handler: `HandleGameObjectTurnCommand`

Syntax:

```text
.gobject turn <gameobject> [o]
```

Example:

```text
.gobject turn 1
```

---

## `.gobject scale`

- Security: Developer (3)
- Console: no
- Handler: `HandleGameObjectScaleCommand`

Syntax:

```text
.gobject scale <gameobject> [scale]
```

Example:

```text
.gobject scale 1
```

---

## `.gobject info`

- Security: Developer (3)
- Console: no
- Handler: `HandleGameObjectInfoCommand`

Syntax:

```text
.gobject info <gameobject>
```

Example:

```text
.gobject info 1
```

---

## `.gobject select`

- Security: Developer (3)
- Console: no
- Handler: `HandleGameObjectSelectCommand`

Syntax:

```text
.gobject select [distance]
```

Example:

```text
.gobject select
```

---

## `.gobject despawn`

- Security: Developer (3)
- Console: no
- Handler: `HandleGameObjectDespawnCommand`


---

## `.gobject toggle`

- Security: Developer (3)
- Console: no
- Handler: `HandleGameObjectToggleCommand`

Syntax:

```text
.gobject toggle <gameobject>
```

Example:

```text
.gobject toggle 1
```

---

## `.gobject reset`

- Security: Developer (3)
- Console: no
- Handler: `HandleGameObjectResetCommand`


---

## `.gobject respawn`

- Security: Developer (3)
- Console: no
- Handler: `HandleGameObjectRespawnCommand`


---

## `.gobject set`

- Security: Developer (3)
- Console: no
- Subcommands: `.gobject set gostate`, `.gobject set lootstate`, `.gobject set respawntime`

Syntax:

```text
.gobject set <subcommand>
```

Example:

```text
.gobject set gostate
```

---

## `.gobject set gostate`

- Security: Developer (3)
- Console: no
- Handler: `HandleGameObjectSetGoStateCommand`

Syntax:

```text
.gobject set gostate <gameobject> <go_state>
```

Example:

```text
.gobject set gostate 1 1
```

---

## `.gobject set lootstate`

- Security: Developer (3)
- Console: no
- Handler: `HandleGameObjectSetLootStateCommand`

Syntax:

```text
.gobject set lootstate <gameobject> <loot_state>
```

Example:

```text
.gobject set lootstate 1 1
```

---

## `.gobject set respawntime`

- Security: Developer (3)
- Console: no
- Handler: `HandleGameObjectSetRespawnTimeCommand`

Syntax:

```text
.gobject set respawntime <gameobject> <time_min> <time_max>
```

Example:

```text
.gobject set respawntime 1 1 1
```

---

## `.gobject customanim`

- Security: Developer (3)
- Console: no
- Handler: `HandleGameObjectSendCustomAnimCommand`

Syntax:

```text
.gobject customanim <gameobject> [anim]
```

Example:

```text
.gobject customanim 1
```

---

[Back to GM Commands](../gm-commands.md)
