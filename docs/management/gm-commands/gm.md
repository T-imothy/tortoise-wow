---
layout: default
title: "GM Command: .gm"
---

# `.gm`

- Security: Moderator (2)
- Console: no
- Handler: `HandleGMCommand`
- Subcommands: `.gm list`, `.gm ingame`, `.gm visible`, `.gm options`, `.gm socials`, `.gm setview`, `.gm chat`

Syntax:

```text
.gm <on|off>
```

Example:

```text
.gm on
```

---

## `.gm list`

- Security: Developer (3)
- Console: yes
- Handler: `HandleGMListFullCommand`


---

## `.gm ingame`

- Security: Moderator (2)
- Console: yes
- Handler: `HandleGMOnlineListCommand`


---

## `.gm visible`

- Security: Moderator (2)
- Console: no
- Handler: `HandleGMVisibleCommand`

Syntax:

```text
.gm visible [visibility_level] [on|off]
```

Example:

```text
.gm visible on
```

---

## `.gm options`

- Security: Administrator (4)
- Console: no
- Handler: `HandleGMOptionsCommand`

Syntax:

```text
.gm options <option> [off]
.gm options <option> [option...] [off]
```

Example:

```text
.gm options cooldown
.gm options cooldown cast power
.gm options cooldown off
```

Accepted options:

- `cooldown`, `cd`: toggles no-cooldown mode.
- `cast`: toggles no-cast-time mode.
- `speed`: toggles no-speed-modifier mode.
- `power`, `mana`: toggles no-power-cost mode.
- `crit`: toggles always-crit mode.
- `spellcr`: toggles always-spell-crit mode.
- `checkcast`, `check`: toggles no-cast-check mode.
- `proc`: toggles always-proc mode.
- `nodmgrng`: toggles no-damage-randomness mode.
- `video`: toggles video mode and refreshes visible unit/player flags.
- `god`: toggles invincibility HP threshold.

By default, the option is added. Include `off` anywhere in the command text to
remove the selected option instead.

---

## `.gm socials`

- Security: Moderator (2)
- Console: no
- Handler: `HandleGMSocialsCommand`

Syntax:

```text
.gm socials <on|off>
```

Example:

```text
.gm socials on
```

---

## `.gm setview`

- Security: Developer (3)
- Console: no
- Handler: `HandleSetViewCommand`


---

## `.gm chat`

- Security: Administrator (4)
- Console: no
- Handler: `HandleSetGMChatCommand`


---

[Back to GM Commands](../gm-commands.md)
