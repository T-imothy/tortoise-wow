---
layout: default
title: GM Commands
---

# GM Commands

This page lists the core `mangosd` GM command tree. In-game commands normally use the configured command prefix, commonly `.`. Server console commands are entered without the in-game prefix.

Syntax is generated from the core command table and the command handler argument parsing in `src/game/Chat/Chat.cpp`, `src/game/Commands/Commands.cpp`, and `src/mangosd/CliRunnable.cpp`. Optional arguments are shown in square brackets, required arguments are shown in angle brackets, and commands that pass their full trailing text to a handler are shown with `[arguments]`.

Module-provided commands can add additional entries at runtime. Anticheat-related subcommands can also differ when the core is built with `USE_ANTICHEAT`.

## Security Levels

| Level | Name |
| --- | --- |
| `0` | Player |
| `1` | Observer |
| `2` | Moderator |
| `3` | Developer |
| `4` | Administrator |
| `5` | SigmaChad |
| `6` | Console |

## Command Groups

- [`.account`](gm-commands/account.md): Manage accounts, passwords, permissions, 2FA, and account lookup.
- [`.blacklist name`](gm-commands/blacklist-name.md): Add character names to the name blacklist.
- [`.cast`](gm-commands/cast.md): Cast spells on yourself, a target, or custom targets.
- [`.character`](gm-commands/character.md): Inspect, restore, clean, rename, and manage character data.
- [`.event`](gm-commands/event.md): View and control game events.
- [`.gm`](gm-commands/gm.md): Toggle GM state, visibility, chat, socials, and GM option flags.
- [`.honor`](gm-commands/honor.md): Inspect or modify honor and rank progress.
- [`.go`](gm-commands/go.md): Teleport to coordinates, creatures, gameobjects, triggers, graveyards, and nearby locations.
- [`.gobject`](gm-commands/gobject.md): Add, move, inspect, despawn, and modify gameobject spawns.
- [`.guild`](gm-commands/guild.md): Create, rename, delete, and manage guild membership or leadership.
- [`.instance`](gm-commands/instance.md): Inspect instance state, binds, continents, and performance data.
- [`.learn`](gm-commands/learn.md): Teach spells, trainer spells, recipes, and item-related spells.
- [`.list`](gm-commands/list.md): List nearby objects, creatures, maps, auras, threat, and player item records.
- [`.lookup`](gm-commands/lookup.md): Search world, account, character, and DBC-backed records.
- [`.modify`](gm-commands/modify.md): Change player stats, money, speed, reputation, appearance, titles, and XP.
- [`.npc`](gm-commands/npc.md): Add, move, inspect, script, and edit creature spawns and templates.
- [`.unit`](gm-commands/unit.md): Inspect selected unit statistics.
- [`.pdump`](gm-commands/pdump.md): List, load, and write player dump files.
- [`.quest`](gm-commands/quest.md): Add, remove, complete, inspect, and test quests.
- [`.reload`](gm-commands/reload.md): Reload configuration, scripts, caches, and database-backed world data.
- [`.reset`](gm-commands/reset.md): Reset player spells, talents, stats, level, honor, or broad reset categories.
- [`.server`](gm-commands/server.md): Inspect server status and control shutdown, restart, corpse cleanup, and raid resets.
- [`.tele`](gm-commands/tele.md): Use, create, delete, and apply named teleport locations.
- [`.trigger`](gm-commands/trigger.md): Inspect or teleport to area triggers.
- [`.wp`](gm-commands/wp.md): Show, add, modify, and export creature waypoints.
- [`.service del_characters`](gm-commands/service-del-characters.md): Run service cleanup for deleted characters.
- [`.worldstate test`](gm-commands/worldstate-test.md): Test or update world state values.
- [`.bg`](gm-commands/bg.md): Inspect, start, stop, or customize battleground state.
- [`.debug`](gm-commands/debug.md): Run developer diagnostics for conditions, fields, packets, leaks, and spell coefficients.
- [`.wareffort`](gm-commands/wareffort.md): Inspect and control war effort stage and gong timing.
- [`.sus`](gm-commands/sus.md): Configure suspicious activity detection and related notifications.
- [`.ban`](gm-commands/ban.md): Ban accounts, characters, IPs, fingerprints, and issue warnings.
- [`.unban`](gm-commands/unban.md): Remove account, character, IP, or fingerprint bans.
- [`.baninfo`](gm-commands/baninfo.md): Inspect ban details.
- [`.banlist`](gm-commands/banlist.md): Search ban lists.
- [`.ticket`](gm-commands/ticket.md): List, assign, unassign, view, and close GM tickets.
- [`.send`](gm-commands/send.md): Send mail, messages, items, money, packets, or spell visuals.
- [`.anticheat info`](gm-commands/anticheat-info.md): Show anticheat information for a selected player.
- [`.pet`](gm-commands/pet.md): List, rename, delete, teach, unteach, and adjust pets.
- [`.gold remove`](gm-commands/gold-remove.md): Remove gold from a player.
- [`.shop`](gm-commands/shop.md): Inspect shop logs and refund shop purchases.
- [`.path`](gm-commands/path.md): Set up and launch creature path editing.
- [`.anonymous`](gm-commands/anonymous.md): Toggle anonymous whisper and mail behavior.
- [`.discbot stop`](gm-commands/discbot-stop.md): Stop the Discord bot integration.
- [`.mmaps`](gm-commands/mmaps.md): Inspect movement map pathing and nearby mmap data.
- [`.faction atwar`](gm-commands/faction-atwar.md): Toggle faction at-war state for a selected player.
- [`.perf`](gm-commands/perf.md): Enable performance tracking and inspect CPU, memory, resource, and interval reports.
