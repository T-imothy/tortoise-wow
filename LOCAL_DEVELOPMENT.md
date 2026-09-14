# Local Turtle development

Authoritative source: `D:\WoW Emu\ManTech\ManTech Turtle`.
Runtime output: `C:\Users\root\Desktop\WorkFolder\turtle`.
Shared MySQL: `127.0.0.1:3306`, installed in `WorkFolder\mysql-server`.
Turtle schemas: `turtle_world`, `turtle_characters`, `turtle_logon`, `turtle_logs`.
Use the database credentials in the local runtime configs; do not copy them into Git.

The active ManTech port uses `powershell -File dev/build-mantech.ps1 -BuildOnly`.
It selects ManTechPlayerbots, disables both other bot implementations, and builds
into `build/mantech-playerbots/bin`. This script currently always stays build-only.
The deployed development executable uses this configuration, with the native
CMaNGOS-policy market from `modules/ManTechPlayerbots/cmangos-ahbot`.
The development population target is 10,000 bots (user-directed September 13), levels 1-60; botActiveAlone is 100 and DisableActivityPriorities is 1. RandomBotAccountCount is 1112. Automatic creation is enabled only while expanding the existing pool, then disabled after provisioning. A configured target is not evidence of stable operation at that population.
See `docs/MANTECH_PLAYERBOTS_PORT.md` for the incomplete gameplay acceptance.

The alternative Sagiroth build remains available for comparison. From this source folder, run `powershell -File dev\build.ps1` to build the native
TortoiseBots Release/SOAP/LTO configuration and copy binaries, symbols and migrations
to the runtime folder. This preserves its local configs and database data. Stop the
Turtle processes before deploying a changed executable. `-ConfigureOnly` configures
the fresh local cache without rebuilding. Dependencies use the existing installed
Visual Studio, CMake and vcpkg runtime outside this repository.

Run `powershell -File dev\test.ps1 -Full` for the architecture regressions.
The relocated repository keeps the original core and module Git histories and all
uncommitted changes. The embedded legacy module is excluded from both local
build configurations and retained read-only as a donor/reference. Native map AI
and the selected module are integrated; detailed runtime receipts and extended
gameplay acceptance limits are in the output folder's reports directory.
Continue following the repository and module AGENTS.md requirements.

Runtime startup: first start shared MySQL using `WorkFolder\start-server.bat` if
it is stopped, then run `turtle\start-realm.bat` and `turtle\start-world.bat`.
The realm listener is local port 3726 and the world listener is local port 8088,
so the other game environments can keep their existing ports. The local client
realmlist endpoint is `127.0.0.1:3726`. No client files were modified by setup.
Use the native world console command `server exit` for clean world shutdown; close
the realm with Ctrl+C. Stop shared MySQL only when the other environments are done.

Game data is local in `turtle\data` (DBC/maps/vmaps/mmaps). SQL snapshots and Turtle
provisioning files are in `turtle\database`; live database files are in the shared
MySQL datadir. Reports are in `turtle\reports` and symbols in `turtle\symbols`.
Never overwrite the other game schemas when restoring a Turtle snapshot.

Build-only options: `dev/build.ps1 -BuildOnly` builds without runtime deployment;
`-WithoutBots` selects the separate optional-core build and always stays build-only.
Intermediate executables are separated into `build/local/bin` and
`build/local-core/bin`, so ON/OFF validation cannot overwrite another candidate.
The normal build deploys only the module-enabled candidate to the output folder.
The script installs missing AH/playerbot configs from templates while preserving
existing operator configs. It imports the VS compiler and SDK tools explicitly
for fresh caches as well as cached builds.


Current ManTech build (September13): use `dev/build-mantech.ps1 -BuildOnly`.
Intermediate output is build/local-mantech/bin; the runtime remains the Turtle
WorkFolder directory above. The active module is modules/ManTechPlayerbots, not
the retained Tortoise reference. Engineering build69 is deployed at ports3726/8088.
The user now requests6000 bots, levels1–60, independently active. Local native map
and idle-bot worker counts are8 each. Live acceptance results belong in the current
ManTech integration audit; the earlier500-bot samples are historical.
The manually applied character-only InnoDB migration is in
sql/custom/characters/20260913_mantech_transactional_character_tables.sql.
Do not run it against other schemas or with Turtle writing character data.


September14 build76: Arch4 ownership accounting and enhanced ManTech diagnostics
are deployed in the Turtle dev runtime. See docs/ARCH4_TURTLE_PORT.md for hashes,
focused test commands, capture controls, actual live results and coverage limits.
The development target remains10,000 bots. Full-population throughput is pending.


September14 02:22 local: build80 deployed to Turtle dev only, SHA256
007F94EA1FE079085B78F949A7D3063CAC91CAAEB2A0ECE47E54F16C41D998C3.
The unchanged build79 20-percent control reached9996 bots with4 pending at its
last recorded sample (174ms average); it was stopped before a10000 sample.
This control reduced load, not the required target. The user reaffirmed10000
bots at100-percent eligibility as the goal. Runtime botActiveAlone=100 and
DisableActivityPriorities=1 are restored. Build80 removes measured per-recipient
MSVC locale-lock contention in bot chat. Full-load acceptance is still pending.
The native channel wrapper-allocation optimization is a separate source change
and is not included in deployed build80. Its source-extracted32-case and10000-
recipient regression passed; preserve that distinction when continuing work.


### September 14: final full-activity acceptance

Build 82 is deployed from build/mantech-playerbots/bin to the Turtle WorkFolder runtime. SHA256: 9A4C61A8443E557E334D17A03A9BA59981F4D552581744082CA830050296530D. The development target is 10,000 bots, botActiveAlone=100, DisableActivityPriorities=1. The unattended full-population interval passed with zero real players and 83–104 ms sampled average ticks; native invite/summon/loot/logout checks passed afterward. See docs/TURTLE_FULL_ACTIVITY_FIXES_2026-09-14.md for the full result, exact observations, behavior correction, and limits. Earlier pending build 76/80/81 throughput notes are historical. Other cores and production were not changed.


### September14 build86: bounded full-load and player-present result

Deployed SHA256 `F2AB45A766401AE3C80C04E8939883A89017DD97D4C9C7BD2A1F3D6AAA2EF630` to the authorized Turtle WorkFolder runtime;
world PID28072, started2026-09-14T09:03:38.0663593-05:00. Target10,000, botActiveAlone100,
DisableActivityPriorities1 remain in the runtime config. Binary hash rechecked.
The final run reached10,000; unattended retained mean ticks167–189ms, Southshore
three-minute player hold188–220ms, no world-action rejections. Native login,
invite(0.719s), cross-map outdoor summon(0.812s), whisper summon, master/FFA/group
loot and group retention/logout passed; isolated fixture positions restored.
The last recorded unattended sample at2026-09-14 09:38:06 has10000 bots,
167ms average and0 world actions pending.
See docs/TURTLE_ACTIVITY_FIXES_2026-09-14.md for exact intervals, queue bursts,
timer-starvation correction, travel admission, service policy and remaining
content/memory limits. This supersedes provisional build82/83/84/85 acceptance
claims; it does not certify every gameplay scenario or a multi-hour soak.
The dev world remains running. No production or other core was changed.
