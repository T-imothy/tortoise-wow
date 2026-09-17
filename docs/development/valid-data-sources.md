---
layout: default
title: Valid Data Sources
---

# Valid Data Sources

When restoring or verifying Tortoise WoW data, prefer evidence captured closest
to the original live server behavior. Sources lower in this list can help fill
gaps, but they should not override stronger sources above them.

## Source Priority

1. Original Turtle WoW packet captures made after April 2026. These are the
   strongest source because they capture actual server responses from the target
   era.
2. Original Turtle WoW video references, such as [Turtle WoW Quest Archive](https://www.youtube.com/@TurtleWoWQuests).
   Video can verify quest text, NPC behavior, object placement, dialogue, and
   other visible gameplay details.
3. Packet captures made from Capycraft. These are useful while Capycraft appears
   to preserve original data, but their value may change if Capycraft begins
   altering content.
4. The dumped Turtle WoW web database. Use this only as a supporting reference
   when stronger evidence is unavailable.

## Third-Party Implementations

Third-party implementations cannot be used as a source of truth unless it can be
proven that they were given direct database access or direct database copies from
the original Turtle WoW project.

They may still be useful for comparison, but matching another implementation is
not enough to prove that data is correct.

## Turtle WoW Web Database

The dumped Turtle WoW web database is useful as a reference, but it is the least
authoritative source listed here.

Treat it carefully. The web database was either not kept up to date or had data
purposefully omitted, so it should not override newer packet captures, video
evidence, or other stronger references.
