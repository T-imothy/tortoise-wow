---
layout: default
title: "GM Command: .faction atwar"
---

# `.faction atwar`

- Security: Developer (3)
- Console: no
- Handler: `HandleFactionAtWarCommand`

Syntax:

```text
.faction atwar <factionId> on/off
```

Example:

```text
.faction atwar 1 on/off
```

---

## `.banprint`

- Security: Administrator (4)
- Console: no
- Handler: `HandleAnticheatFingerprintAutobanAddCommand`

Syntax:

```text
.banprint <fingerprint>
```

Example:

```text
.banprint 123456
```

---

## `.unbanprint`

- Security: Administrator (4)
- Console: no
- Handler: `HandleAnticheatFingerprintAutobanRemoveCommand`

Syntax:

```text
.unbanprint <fingerprint>
```

Example:

```text
.unbanprint 123456
```

---

## `.bw`

- Security: Moderator (2)
- Console: no
- Handler: `HandleWarnCharacterCommand`

Syntax:

```text
.bw <player>
```

Example:

```text
.bw Thrall
```

---

## `.bi`

- Security: Moderator (2)
- Console: no
- Handler: `HandleBanInfoAccountCommand`

Syntax:

```text
.bi <account>
```

Example:

```text
.bi accountname
```

---

## `.marksuspicious`

- Security: Moderator (2)
- Console: no
- Handler: `HandleMarkSuspiciousCommand`

Syntax:

```text
.marksuspicious <on|off>
```

Example:

```text
.marksuspicious on
```

---

## `.forcejoinchannel`

- Security: Administrator (4)
- Console: no
- Handler: `ForceJoinChannelCommand`


---

## `.toggletrainee`

- Security: Developer (3)
- Console: no
- Handler: `HandleToggleTrainingCommand`

Syntax:

```text
.toggletrainee <account>
```

Example:

```text
.toggletrainee accountname
```

---

## `.toggleinferno`

- Security: Developer (3)
- Console: no
- Handler: `HandleToggleInfernoModeCommand`


---

## `.translate`

- Security: Developer (3)
- Console: no
- Handler: `HandleTranslateCommand`

Syntax:

```text
.translate [arguments]
```

Example:

```text
.translate arguments
```

---

## `.stopapi`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleStopApiServerCommand`


---

## `.hcchat`

- Security: Player (0)
- Console: no
- Handler: `HandleSetHCChatCommand`


---

## `.toggleillusions`

- Security: Developer (3)
- Console: no
- Handler: `HandleToggleIllusionsCommand`


---

## `.tmogdelete`

- Security: Developer (3)
- Console: no
- Handler: `HandleDeleteTransmogCollectionCommand`

Syntax:

```text
.tmogdelete <item> <player>
```

Example:

```text
.tmogdelete 6948 Thrall
```

---

[Back to GM Commands](../gm-commands.md)
