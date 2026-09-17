---
layout: default
title: Troubleshooting
---

# Troubleshooting

This page collects common recovery steps for Tortoise WoW server setup and
maintenance.

## Resetting the Database

If your local database gets into a bad state during setup or testing, the
simplest reset is to reimport the base SQL files and then start the server so it
can apply database updates again.

This will replace existing database data. Back up anything you want to keep
before continuing.

From the repository root, recreate the base databases:

```sh
mariadb -u root -p < sql/create_databases.sql
```

Then reimport all base world SQL files:

```sh
for file in sql/base/*.sql; do
  echo "Importing $file"
  mariadb -u root -p tw_world < "$file"
done
```

After the import finishes, start `mangosd`. On startup, the server checks
`sql/database_updates`, applies any missing migrations, and records them in the
database.

Make sure `Database.AutoUpdate.Path` in `mangosd.conf` points to the
`sql/database_updates` directory inside your source checkout.

## Cannot Learn Spells from Trainers

If a staff or test character can open a trainer but cannot learn spells, check
whether GM state is interfering with normal trainer behavior.

Run these commands on the affected character:

```text
.gm off
.gm visible on
```

After disabling GM mode and making sure GM invisibility is off, close and reopen
the trainer window, then try learning the spell again.

## Boats or Zeppelins Are Missing or Misplaced

If boats or zeppelins do not appear, appear in the wrong place, or seem out of
sync with their docks or towers, clear the client's cached world data.

Close the game client, then delete the `WDB` folder from your client directory.
Start the client again and log back in. The client will rebuild the cache with
fresh data from the server.

## Next Step

Return to the [documentation index](../index.md).
