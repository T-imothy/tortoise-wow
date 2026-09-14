# Native ManTech Turtle production deployment — 2026-09-14

The tested build86 world server, matching login server, symbols and six runtime
DLLs were installed together with the migrated bot and core configuration.
All 14 installed files passed SHA-256 comparison against the staged release.
Production was left stopped; no production gameplay acceptance run was performed.

## Population and runtime policy

- 6,000 minimum/maximum random bots; 10% background activity.
- `AiPlayerbot.DisableActivityPriorities = 0` permits the 10% policy to apply.
- Existing `RNDBOT` accounts are reused; account creation and deletion are off.
- Random levels are 1–60 and the configuration contains 27 Turtle talent paths.
- Production world/login ports remain 8088/3727. Database connections, realm
  address, data directory, authentication configuration and AH configuration
  were preserved. Administrator credentials were not written to runtime config.
- Native background AI/world scheduling and the tested asynchronous settings
  were carried over. Existing production game rules and custom battleground
  settings were retained.
- Native Turtle spell data is loaded from SQL as in the tested development run.
- SQL updates were applied explicitly while stopped. Automatic updates are
  disabled for this release to prevent replaying old module update directories.

## Database changes and preservation

69 remaining MyISAM character-schema tables, including bot caches and retained
legacy tables, were converted to InnoDB with dynamic row format. Each table's
exact row count was checked before and after its conversion. No character-schema
base table remains nontransactional; this enables the core's guarded transaction
retry path. All 9,013 characters, including 9,000 existing bot characters, remain.
The existing unique owner/bot/event index was retained without adding a duplicate.

The native `migrations.Module` metadata column was added to the character and
login migration tables. Core world updates `20260910042434_world` and
`20260910103417_world` were applied and recorded. The additive Turtle race/RPG
destination migration brought the destination table from 441 to 480 rows;
Twinkie Boomstick's missing hunter trainer list was restored to 125 rows.

No development characters, accounts or bot caches were imported. The inactive
TortoiseBots-only value/ownership tables were not created. Existing equipment and
item caches were preserved. Production spell, talent, race, class, starting outfit
and taxi DBC files matched the tested development files.

A private compressed character-database rollback dump and affected world-table
dump were captured before modification; both completed successfully. Runtime
credentials and these data dumps are excluded from Git.

## Source and validation

- Native core hooks and Arch4 changes: `79f65630c50ab62753972f8a989155543f447b9f`.
- Core/module integration: `b100eb360b71739a0dff6de550040547c665d273`.
- ManTech playerbots port: `84d1e0ffafa2d82e6afa54d0aebbe9c975cfdfba`.
- World executable SHA-256:
  `F2AB45A766401AE3C80C04E8939883A89017DD97D4C9C7BD2A1F3D6AAA2EF630`.

The release uses the same executable tested at 10,000 bots with 100% activity
eligibility. That bounded development run passed native login, invitation,
summon, loot-policy and scheduling checks; it does not establish long-term
production stability or exhaustive encounter correctness. The two binaries can
be started manually after deployment. Development remains independently configured
for its existing 10,000-bot, 100% activity run.

GitHub publication is a separate step requiring the exact destination approval
requested during deployment. Local commits alone do not establish publication.

### Production startup NULL event payload fix (build87, September14)

The first production boot of build86 stopped while restoring saved random-bot
state. The production event table contained 60,110 rows with SQL NULL payloads;
its nullable `data` column is valid legacy schema. Native `Field::GetString()`
returns nullptr for SQL NULL. The lazy loader assigned that pointer to a
std::string, and the bulk loader had the same unsafe conversion. The crash dump's
stack candidates resolve to EnsureEventCacheLoaded at the payload assignment.

Both loaders now use native `Field::GetCppString()`, mapping absent optional
payloads to empty strings and preserving existing event names, numeric values,
timestamps and expiration intervals. No characters, accounts or event rows need
to be deleted or rewritten. A source-derived C++ regression covers both loaders
with NULL/empty/populated payloads, multiple bots, cache reuse and empty stores.
This corrects a migration compatibility gap missed by the initial deployment
checks; the earlier build86 deployment receipt is not proof of production startup.
