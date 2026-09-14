---
layout: default
title: mangosd.conf
---

# mangosd.conf

`mangosd.conf` configures the world server. The world server loads game data,
accepts realm connections from authenticated clients, runs maps, saves
characters, applies database updates, and controls most gameplay behavior.

Start from the distributed template:

```sh
cp server/etc/mangosd.conf.dist server/etc/mangosd.conf
```

Most local servers only need to change database connection strings, paths, and
possibly the realm port or bind address.

## Identity and Paths

| Setting | Default | Description |
| --- | --- | --- |
| `RealmID` | `1` | Realm id. Must match the matching row in `tw_logon.realmlist`. |
| `DataDir` | `"../data"` | Directory containing extracted client data such as DBC, maps, vmaps, and mmaps. |
| `LogsDir` | `"../logs"` | Directory for server logs. The directory must exist unless logs are disabled. |
| `HonorDir` | `"../honor"` | Directory for weekly honor calculation files. |
| `PDumpDir` | `"../pdump"` | Directory for character dump files. |
| `PidFile` | `"twlive.pid"` | PID file written by the world daemon. |
| `HardcoreModeLogFile` | `"hardcore.log"` | Hardcore mode log file name. |

## Databases

| Setting | Default | Description |
| --- | --- | --- |
| `LoginDatabase.Info` | `"127.0.0.1;3306;mangos;mangos;tw_logon"` | Login/auth database connection. |
| `WorldDatabase.Info` | `"127.0.0.1;3306;mangos;mangos;tw_world"` | World content database connection. |
| `CharacterDatabase.Info` | `"127.0.0.1;3306;mangos;mangos;tw_char"` | Character state database connection. |
| `LogsDatabase.Info` | `"127.0.0.1;3306;mangos;mangos;tw_logs"` | Logs database connection. |
| `*.Connections` | varies | Synchronous read connection counts for each database. |
| `*.WorkerThreads` | varies | Async worker thread counts for each database. |
| `MaxPingTime` | `30` | Minutes between database pings used to keep connections alive. |

Connection strings use:

```text
host;port;username;password;database
```

## Database Updates

| Setting | Default | Description |
| --- | --- | --- |
| `Database.AutoUpdate.Enabled` | `1` | Apply pending SQL updates on startup. |
| `Database.AutoUpdate.Path` | `"../../sql/database_updates/"` | Directory containing database update SQL files. |
| `Database.AutoUpdate.AuthUpdateName` | `"auth"` | Auth/login update stream name. |
| `Database.AutoUpdate.CharUpdateName` | `"character"` | Character update stream name. |
| `Database.AutoUpdate.WorldUpdateName` | `"world"` | World update stream name. |
| `Database.AutoUpdate.AllowedModules` | `"all"` | Module update names to include, or `all`. |
| `Database.AutoUpdate.SortByName` | `1` | `1` sorts updates by file name; `0` sorts by modification time. |

Make sure `Database.AutoUpdate.Path` points to the `sql/database_updates`
directory inside your source checkout from the working directory where
`mangosd` is started.

## Network and Login Flow

| Setting | Default | Description |
| --- | --- | --- |
| `WorldServerPort` | `8090` | TCP port used by the world server. |
| `BindIP` | `"0.0.0.0"` | IP address or hostname to bind. Use `0.0.0.0` to listen on all interfaces. |
| `HttpApi.Enable` | `0` | Enables the HTTP API used by character transfers. |
| `Compression` | `1` | Update packet compression level, from `1` to `9`. |
| `PlayerLimit` | `0` | Initial realm capacity, excluding staff. `0` disables the soft limit. |
| `PlayerHardLimit` | `4000` | Maximum players after queue growth. |
| `LoginPerTick` | `8` | Players admitted from queue per world update tick. |
| `LoginVIPQueue` | `0` | Enables VIP queue bypass checks. |
| `LoginVIPQueueLevelThreshold` | `55` | Character level required for VIP queue bypass when enabled. |
| `LoginQueue.GracePeriodSecs` | `300` | Recent logout grace period for queue bypass. |
| `CharacterScreenMaxIdleTime` | `900` | Seconds allowed at character select before disconnect. |

## Process and Runtime

| Setting | Default | Description |
| --- | --- | --- |
| `UseProcessors` | `0` | Windows-only processor affinity bitmask. |
| `ProcessPriority` | `1` | Windows-only process priority setting. |
| `Console.Enable` | `1` | Enables the world server console. |
| `WaitAtStartupError` | `0` | Wait before continuing after startup errors. |
| `BeepAtStart` | `1` | Beep after startup on supported systems. |
| `ShowProgressBars` | `0` | Show startup progress bars. |
| `MaxCoreStuckTime` | `0` | Seconds before forcing a crash if the core appears frozen. `0` disables. |
| `AutoRestart.MaxServerUptime` | `259200` | Schedule restart after this many seconds. |
| `AutoRestart.HourMin` / `AutoRestart.HourMax` | `4` / `6` | Preferred auto-restart hour window. |

## Maps, Terrain, and Movement

| Setting | Default | Description |
| --- | --- | --- |
| `GridUnload` | `0` | Unload inactive grids to save memory. |
| `CleanupTerrain` | `1` | Enable terrain cleanup. |
| `GridCleanUpDelay` | `300000` | Grid cleanup delay in milliseconds. |
| `MapUpdateInterval` | `50` | Map update interval in milliseconds. |
| `MapUpdate.*` | varies | Map update threading, visibility, grid activation, and timing controls. |
| `Terrain.Preload.Continents` / `Terrain.Preload.Instances` | `0` / `0` | Preload terrain data at startup. |
| `vmap.enableLOS` / `vmap.enableHeight` | `1` / `1` | Enable vmap line-of-sight and height checks. |
| `vmap.enableIndoorCheck` | `1` | Use vmaps for indoor checks. |
| `vmap.ignoreSpellIds` | `"7720"` | Spell ids ignored for vmap line-of-sight checks. |
| `mmap.enabled` | `1` | Enable mmap pathfinding. |
| `DetectPosCollision` | `1` | Check final movement and summon positions against collision. |
| `Movement.*` | varies | Movement validation, interpolation, and pending ACK timing settings. |

If you enable multiple map update threads, terrain preloading is recommended by
the template to avoid startup or runtime crashes.

## Logging

| Setting | Default | Description |
| --- | --- | --- |
| `LogLevel` | `1` | Console log level. `0` minimum, `1` basic/error, `2` detail, `3` full/debug. |
| `LogTime` | `0` | Include timestamps in console output. |
| `LogFile` | `"server.log"` | Main log file name. |
| `LogTimestamp` | `1` | Include startup timestamp in log file names. |
| `LogFileLevel` | `1` | File log level. |
| `LogColors` | `""` | Console color override. |
| `LogSQL` | `1` | Log GM command SQL. |
| `LogFilter_*` | varies | Enable or disable specific detailed log filters. |

Specialized log files include `HonorLogFile`, `RaidLogFile`,
`AnticheatLogFile`, `WardenLogFile`, `WorldLogFile`, `DBErrorLogFile`,
`CharLogFile`, `ChatLogFile`, `BgLogFile`, `GmLogFile`, `RaLogFile`,
`LootsLogFile`, `RareLootsLogFile`, `LevelupLogFile`, `PerformanceLog.File`,
and others.

## Realm and Character Rules

| Setting | Default | Description |
| --- | --- | --- |
| `GameType` | `6` | Realm style. `0` normal, `1` PvP, `6` RP, `8` RP-PvP, `16` FFA PvP. |
| `RealmZone` | `1` | Realm zone and name alphabet rules. Changing this can affect client realm visibility. |
| `TimeZoneOffset` | `0` | Realm time-zone offset in hours. |
| `DBC.Locale` | `255` | DBC locale. Template lists `0` English through `6` Spanish. |
| `LoadLocales` | `1` | Load database locale tables. |
| `StrictPlayerNames`, `StrictCharterNames`, `StrictPetNames` | `1` | Enforce locale-specific naming rules. |
| `MinPlayerName`, `MinCharterName`, `MinPetName` | `2` | Minimum name lengths. |
| `CharactersCreatingDisabled` | `0` | Disable character creation for a faction or for all players. |
| `CharactersPerAccount` | `50` | Maximum characters per account. |
| `CharactersPerRealm` | `10` | Maximum characters per realm. |
| `MaxPlayerLevel` | `60` | Maximum level from experience. |
| `StartPlayerLevel` | `1` | Starting character level. |
| `StartPlayerMoney` | `0` | Starting money in copper. |
| `Motd` | configured message | Message of the day shown on login. |

## Gameplay Systems

| Setting Group | Examples | Purpose |
| --- | --- | --- |
| Progression | `Progression.ContentPhase`, `Progression.AccuratePVEEvents`, `Progression.NoQuestXpToGold` | Controls phase and historical progression behavior. |
| PvP and honor | `PvP.AccurateTimeline`, `MaxHonorPoints`, `WeeklyHonorCap`, `MaintenanceDay`, `AutoHonorRestart` | PvP ranks, honor limits, and honor restart behavior. |
| Instances | `Instance.IgnoreLevel`, `Instance.IgnoreRaid`, `Instance.ResetTimeHour`, `Instance.UnloadDelay` | Instance entry and reset behavior. |
| Quests | `Quests.LowLevelHideDiff`, `Quests.HighLevelHideDiff`, `Quests.IgnoreRaid` | Quest visibility and raid quest rules. |
| Mail | `MailDeliveryDelay`, `MailMaxPerHour`, `Mails.COD.ForceTag.MaxLevel`, `MassMailer.SendPerTick` | Mail delivery and anti-abuse behavior. |
| Pets | `PetUnsummonAtMount`, `PetDefaultLoyalty` | Pet mount and loyalty behavior. |
| Creatures | `ThreatRadius`, `Rate.Creature.Aggro`, `CreatureFamilyAssistanceRadius`, `Corpse.Decay.*` | Aggro, assist, loot, and corpse behavior. |
| Chat | `PlayerCommands`, `ChatFlood.*`, `WorldChan.*`, `WhisperTargets.*`, `SayMinLevel`, `YellMinLevel` | Command parsing and chat restrictions. |
| Cross-faction | `AllowTwoSide.*`, `GM.JoinOppositeFactionChannels` | Cross-faction account, chat, group, guild, trade, auction, mail, and social rules. |

## Rates and Economy

| Setting Group | Examples | Purpose |
| --- | --- | --- |
| Recovery and resources | `Rate.Health`, `Rate.Mana`, `Rate.Rage.*`, `Rate.Energy`, `Rate.Focus`, `Rate.Loyalty` | Regeneration and resource rates. |
| Drops and money | `Rate.Drop.Item.*`, `Rate.Drop.Money` | Item quality and money drop rates. |
| XP and rest | `Rate.XP.Kill`, `Rate.XP.Quest`, `Rate.XP.Explore`, `Rate.Rest.*` | Experience and rested XP rates. |
| Skills | `SkillGain.*`, `SkillChance.*`, `SkillFail.*`, `Rate.Skill.Discovery` | Skill gain and profession chance behavior. |
| Reputation and honor | `Rate.Reputation.*`, `Rate.Honor` | Reputation and honor multipliers. |
| Auction house | `Rate.Auction.*`, `Auction.Deposit.Min`, `Auction.AccountConcurrentLimit` | Auction timing, costs, cuts, and account limits. |
| Durability and death | `DurabilityLossChance.*`, `Death.*`, `Corpses.UpdateMinutes`, `Bones.ExpireMinutes` | Durability loss, resurrection, corpses, and bones. |
| Dynamic respawn | `DynamicRespawn.*` | Respawn reduction based on nearby player activity. |

## GM and Tickets

| Setting | Default | Description |
| --- | --- | --- |
| `GM.LoginState` | `1` | GM mode state at login. |
| `GM.Visible` | `0` | GM visibility state at login. |
| `GM.AcceptTickets` | `1` | Whether GMs accept tickets by default. |
| `GM.Chat` | `1` | GM chat mode at login. |
| `GM.WhisperingTo` | `1` | Whether GMs accept player whispers by default. |
| `GM.InGMList.Level` | `3` | Maximum GM level shown in GM list while visible and `.gm off`. |
| `GM.InWhoList.Level` | `3` | Maximum GM level shown in `/who` while visible. |
| `GM.LogTrade` | `1` | Include GM trade operations in GM logs. |
| `GM.StartLevel` | `60` | Starting level for GM accounts. |
| `GM.LowerSecurity` | `1` | Restrict lower-security staff from acting on higher-security accounts. |
| `GM.AllowTrades` | `1` | Allow GM trades, mail, and auction house use. |
| `GM.AllowPublicChannels` | `1` | Allow GM speech in public channels. |
| `GM.StartOnGMIsland` | `1` | Spawn GM account characters on GM Island. |
| `GMTickets.Enable` | `1` | Enable support tickets. |
| `GMTickets.MinLevel` | `1` | Minimum level to open a ticket. |
| `GMTickets.Admin.Security` | `7` | Security rank required for ticket escalation assignment. |

## Visibility

| Setting | Default | Description |
| --- | --- | --- |
| `Visibility.GroupMode` | `0` | Group visibility behavior. |
| `Visibility.Distance.Continents` | `250` | Visibility distance on continents. |
| `Visibility.Distance.Instances` | `250` | Visibility distance in instances. |
| `Visibility.Distance.BG` | `533` | Visibility distance in battlegrounds. |
| `Visibility.Distance.Continents.Min` | `60` | Reduced minimum continent visibility distance under load. |
| `Visibility.Distance.InFlight` | `120` | Visibility distance while in flight. |
| `Visibility.Distance.Grey.Unit` | `1` | Grey distance for creatures and players. |
| `Visibility.Distance.Grey.Object` | `10` | Grey distance for objects and corpses. |
| `Visibility.RelocationLowerLimit` | `10` | Movement threshold before visibility refresh. |
| `Visibility.AIRelocationNotifyDelay` | `1000` | Delay between AI reactions to nearby movement. |
| `Visibility.ForceActiveObjects` | `1` | Force high-visibility template objects to stay active. |

## Warden and Anticheat

| Setting Group | Examples | Purpose |
| --- | --- | --- |
| Warden | `Warden.WinEnabled`, `Warden.OSXEnabled`, `Warden.PlayersOnly`, `Warden.DefaultPenalty`, `Warden.ModuleDir` | Client integrity checks and penalties. |
| Anticheat core | `Anticheat.Enable`, `Anticheat.PlayersOnly`, `Anticheat.NotifyCheaters`, `Anticheat.BanDuration`, `Anticheat.LogData` | Global movement anticheat behavior. |
| Movement checks | `Anticheat.SpeedHack.*`, `Anticheat.FlyHack.*`, `Anticheat.WallClimb.*`, `Anticheat.Teleport.*`, `Anticheat.WaterWalk.*` | Specific movement checks, thresholds, rejection, and penalties. |
| Suspicious manager | `Suspicious.*` | Movement, fishing, and NPC-killing suspicious activity reporting. |

Be conservative with anticheat thresholds on test realms. Low thresholds can
create false positives when latency, transports, or scripted movement are
involved.

## Battlegrounds and Outdoor PvP

| Setting Group | Examples | Purpose |
| --- | --- | --- |
| Battleground flow | `Battleground.CastDeserter`, `Battleground.InvitationType`, `BattleGround.PrematureFinishTimer`, `BattleGround.GroupQueueLimit` | Queue, deserter, invitation, and finish behavior. |
| Queue announcements | `Battleground.QueueAnnouncer.Join`, `Battleground.QueueAnnouncer.Start` | Chat announcements for queue and start events. |
| Battleground rates | `BattleGround.Rate.Reputation.*`, `BattleGround.Rate.Honor.*` | Reputation and honor multipliers per battleground. |
| Alterac Valley | `Alterac.MinPlayersInQueue`, `Alterac.InitMaxPlayers` | AV queue and startup sizing. |
| Outdoor PvP | `OutdoorPvp.SIEnabled`, `OutdoorPvp.EPEnabled` | Silithus and Eastern Plaguelands outdoor PvP. |

## Optional Systems

| Setting Group | Examples | Purpose |
| --- | --- | --- |
| Player bots | `PlayerBot.*` | Player bot enabling, refresh, counts, and logout delay. |
| Beginners guilds | `BeginnersGuilds`, `BeginnersGuildHorde`, `BeginnersGuildAlliance` | Automatically invite new players to beginner guilds. |
| Transmog | `Transmog.*` | Enable transmog and configure item or money cost. |
| Mail spam | `MailSpam.*` | Mail spam thresholds and restrictions. |
| Hardcore | `Hardcore.Disable.Duel` | Hardcore duel restrictions. |
| PTR | `PTR` | Marks the realm as PTR-style behavior where supported. |
| Shop | `Shop.RefundWindow` | Refund request window for shop items. |
| Performance reporting | `Perf.Enable`, `Perf.ReportInterval` | Performance logging into the logs database. |

## Common Local Example

For a local development server, the most commonly changed settings are:

```ini
RealmID = 1
DataDir = "../data"
LogsDir = "../logs"

LoginDatabase.Info = "127.0.0.1;3306;mangos;mangos;tw_logon"
WorldDatabase.Info = "127.0.0.1;3306;mangos;mangos;tw_world"
CharacterDatabase.Info = "127.0.0.1;3306;mangos;mangos;tw_char"
LogsDatabase.Info = "127.0.0.1;3306;mangos;mangos;tw_logs"

Database.AutoUpdate.Enabled = 1
Database.AutoUpdate.Path = "../../sql/database_updates/"

WorldServerPort = 8090
BindIP = "0.0.0.0"
```

If the world server starts but clients cannot enter the realm, confirm that
`RealmID` matches `tw_logon.realmlist.id`, the realm row points at the correct
world server address and port, and the database connection strings match your
local MariaDB credentials.

## Next Step

Continue to [Module Installation](module-installation.md).
