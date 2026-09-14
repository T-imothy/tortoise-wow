---
layout: default
title: "GM Command: .modify"
---

# `.modify`

- Security: Developer (3)
- Console: no
- Subcommands: `.modify hp`, `.modify mana`, `.modify rage`, `.modify energy`, `.modify money`, `.modify aspeed`, `.modify speed`, `.modify scale`, `.modify faction`, `.modify rep`, `.modify drunk`, `.modify morph`, `.modify gender`, `.modify strength`, `.modify agility`, `.modify stamina`, `.modify intellect`, `.modify spirit`, `.modify ap`, `.modify spellpower`, `.modify parry`, `.modify honor`, `.modify xp`, `.modify hairstyle`, `.modify haircolor`, `.modify skincolor`, `.modify face`, `.modify accessories`, `.modify title`

Syntax:

```text
.modify <subcommand>
```

Example:

```text
.modify hp
```

---

## `.modify hp`

- Security: Developer (3)
- Console: no
- Handler: `HandleModifyHPCommand`

Syntax:

```text
.modify hp [hp] [hpm]
```

Example:

```text
.modify hp
```

---

## `.modify mana`

- Security: Developer (3)
- Console: no
- Handler: `HandleModifyManaCommand`

Syntax:

```text
.modify mana [mana] [manam]
```

Example:

```text
.modify mana
```

---

## `.modify rage`

- Security: Developer (3)
- Console: no
- Handler: `HandleModifyRageCommand`

Syntax:

```text
.modify rage <rage_min> <rage_max>
```

Example:

```text
.modify rage 1 1
```

---

## `.modify energy`

- Security: Developer (3)
- Console: no
- Handler: `HandleModifyEnergyCommand`

Syntax:

```text
.modify energy <energy_min> <energy_max>
```

Example:

```text
.modify energy 1 1
```

---

## `.modify money`

- Security: Developer (3)
- Console: no
- Handler: `HandleModifyMoneyCommand`

Syntax:

```text
.modify money [arguments]
```

Example:

```text
.modify money arguments
```

---

## `.modify aspeed`

- Security: Developer (3)
- Console: no
- Handler: `HandleModifyASpeedCommand`

Syntax:

```text
.modify aspeed [arguments]
```

Example:

```text
.modify aspeed arguments
```

---

## `.modify speed`

- Security: Developer (3)
- Console: no
- Handler: `HandleModifyASpeedCommand`

Syntax:

```text
.modify speed [arguments]
```

Example:

```text
.modify speed arguments
```

---

## `.modify scale`

- Security: Developer (3)
- Console: no
- Handler: `HandleModifyScaleCommand`

Syntax:

```text
.modify scale <scale> [on|off]
```

Example:

```text
.modify scale 1 on
```

---

## `.modify faction`

- Security: Developer (3)
- Console: no
- Handler: `HandleModifyFactionCommand`

Syntax:

```text
.modify faction <faction> [flag] [npcflag] [dyflag]
```

Example:

```text
.modify faction 1
```

---

## `.modify rep`

- Security: Developer (3)
- Console: no
- Handler: `HandleModifyRepCommand`

Syntax:

```text
.modify rep <faction> <amount> [delta]
```

Example:

```text
.modify rep 1 1
```

---

## `.modify drunk`

- Security: Developer (3)
- Console: no
- Handler: `HandleModifyDrunkCommand`

Syntax:

```text
.modify drunk [arguments]
```

Example:

```text
.modify drunk arguments
```

---

## `.modify morph`

- Security: Developer (3)
- Console: no
- Handler: `HandleModifyMorphCommand`

Syntax:

```text
.modify morph [arguments]
```

Example:

```text
.modify morph arguments
```

---

## `.modify gender`

- Security: Administrator (4)
- Console: no
- Handler: `HandleModifyGenderCommand`

Syntax:

```text
.modify gender [arguments]
```

Example:

```text
.modify gender arguments
```

---

## `.modify strength`

- Security: Administrator (4)
- Console: no
- Handler: `HandleModifyStrengthCommand`

Syntax:

```text
.modify strength <amount>
```

Example:

```text
.modify strength 1
```

---

## `.modify agility`

- Security: Administrator (4)
- Console: no
- Handler: `HandleModifyAgilityCommand`

Syntax:

```text
.modify agility <amount>
```

Example:

```text
.modify agility 1
```

---

## `.modify stamina`

- Security: Administrator (4)
- Console: no
- Handler: `HandleModifyStaminaCommand`

Syntax:

```text
.modify stamina <amount>
```

Example:

```text
.modify stamina 1
```

---

## `.modify intellect`

- Security: Administrator (4)
- Console: no
- Handler: `HandleModifyIntellectCommand`

Syntax:

```text
.modify intellect <amount>
```

Example:

```text
.modify intellect 1
```

---

## `.modify spirit`

- Security: Administrator (4)
- Console: no
- Handler: `HandleModifySpiritCommand`

Syntax:

```text
.modify spirit <amount>
```

Example:

```text
.modify spirit 1
```

---

## `.modify ap`

- Security: Administrator (4)
- Console: no
- Handler: `HandleModifyMeleeApCommand`

Syntax:

```text
.modify ap <amount>
```

Example:

```text
.modify ap 1
```

---

## `.modify spellpower`

- Security: Administrator (4)
- Console: no
- Handler: `HandleModifySpellPowerCommand`

Syntax:

```text
.modify spellpower <amount>
```

Example:

```text
.modify spellpower 1
```

---

## `.modify parry`

- Security: Administrator (4)
- Console: no
- Handler: `HandleModifyParryCommand`

Syntax:

```text
.modify parry <amount>
```

Example:

```text
.modify parry 1
```

---

## `.modify honor`

- Security: Administrator (4)
- Console: no
- Handler: `HandleModifyHonorCommand`

Syntax:

```text
.modify honor <amount>
```

Example:

```text
.modify honor 1
```

---

## `.modify xp`

- Security: Developer (3)
- Console: no
- Handler: `HandleModifyXpCommand`

Syntax:

```text
.givexp value, where [value] is experience.
```

Example:

```text
.givexp value, where 1 is experience.
```

---

## `.modify hairstyle`

- Security: Developer (3)
- Console: no
- Handler: `HandleModifyHairStyleCommand`

Syntax:

```text
.modify hairstyle [arguments]
```

Example:

```text
.modify hairstyle arguments
```

---

## `.modify haircolor`

- Security: Developer (3)
- Console: no
- Handler: `HandleModifyHairColorCommand`

Syntax:

```text
.modify haircolor [arguments]
```

Example:

```text
.modify haircolor arguments
```

---

## `.modify skincolor`

- Security: Developer (3)
- Console: no
- Handler: `HandleModifySkinColorCommand`

Syntax:

```text
.modify skincolor [arguments]
```

Example:

```text
.modify skincolor arguments
```

---

## `.modify face`

- Security: Developer (3)
- Console: no
- Handler: `HandleModifyFaceCommand`

Syntax:

```text
.modify face [arguments]
```

Example:

```text
.modify face arguments
```

---

## `.modify accessories`

- Security: Developer (3)
- Console: no
- Handler: `HandleModifyAccessoriesCommand`

Syntax:

```text
.modify accessories [arguments]
```

Example:

```text
.modify accessories arguments
```

---

## `.modify title`

- Security: Developer (3)
- Console: no
- Handler: `HandleModifyTitleCommand`

Syntax:

```text
.modify title [arguments]
```

Example:

```text
.modify title arguments
```

---

[Back to GM Commands](../gm-commands.md)
