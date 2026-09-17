---
layout: default
title: Database Setup
---

# Database Setup

Tortoise WoW uses separate databases for login/auth data, character data, world
data, and logs.

MariaDB is fully supported and is the recommended database server. MySQL may
work, but MySQL 8 and newer may have compatibility issues with older MaNGOS-era
schema and query behavior.

## Requirements

You need:

- MariaDB Server, recommended
- A database user for the server
- The SQL files from this repository
- A built server with `mangosd` and `realmd`

The default database names are:

| Database | Purpose |
| --- | --- |
| `tw_logon` | Accounts, realm list, bans, and authentication data. |
| `tw_char` | Characters, inventories, guilds, mail, and other character state. |
| `tw_world` | Creatures, quests, items, spells, vendors, scripts, and world content. |
| `tw_logs` | Optional logging tables used by server systems. |

## Install MariaDB

Ubuntu and Debian:

```sh
sudo apt update
sudo apt install mariadb-server mariadb-client
```

Fedora:

```sh
sudo dnf install mariadb-server mariadb
sudo systemctl enable --now mariadb
```

Arch Linux:

```sh
sudo pacman -Syu --needed mariadb
sudo mariadb-install-db --user=mysql --basedir=/usr --datadir=/var/lib/mysql
sudo systemctl enable --now mariadb
```

After installing MariaDB, run the secure installation helper if it is available
on your system:

```sh
sudo mariadb-secure-installation
```

## Create a Server Database User

Log in as a database administrator:

```sh
sudo mariadb
```

Create a user and grant access to the Tortoise WoW databases:

```sql
CREATE USER IF NOT EXISTS 'mangos'@'localhost' IDENTIFIED BY 'mangos';
GRANT ALL PRIVILEGES ON `tw_logon`.* TO 'mangos'@'localhost';
GRANT ALL PRIVILEGES ON `tw_char`.* TO 'mangos'@'localhost';
GRANT ALL PRIVILEGES ON `tw_world`.* TO 'mangos'@'localhost';
GRANT ALL PRIVILEGES ON `tw_logs`.* TO 'mangos'@'localhost';
FLUSH PRIVILEGES;
```

You can use a different username or password, but the same values must be used
in `mangosd.conf` and `realmd.conf`.

## Import the Base Databases

From the repository root, import the database creation script:

```sh
mariadb -u root -p < sql/create_databases.sql
```

Then import every base world SQL file:

```sh
for file in sql/base/*.sql; do
  echo "Importing $file"
  mariadb -u root -p tw_world < "$file"
done
```

The base import can take a while.

## Configure Server Connections

Copy the installed config templates to active config files if you have not done
that already:

```sh
cp server/etc/mangosd.conf.dist server/etc/mangosd.conf
cp server/etc/realmd.conf.dist server/etc/realmd.conf
```

In `server/etc/mangosd.conf`, set the database connections:

```ini
LoginDatabase.Info = "127.0.0.1;3306;mangos;mangos;tw_logon"
WorldDatabase.Info = "127.0.0.1;3306;mangos;mangos;tw_world"
CharacterDatabase.Info = "127.0.0.1;3306;mangos;mangos;tw_char"
LogsDatabase.Info = "127.0.0.1;3306;mangos;mangos;tw_logs"
```

In `server/etc/realmd.conf`, set the login database connection:

```ini
LoginDatabaseInfo = "127.0.0.1;3306;mangos;mangos;tw_logon"
```

The connection format is:

```text
host;port;username;password;database
```

## Apply Database Updates

The world server can apply tracked database updates automatically.

Keep these settings enabled in `mangosd.conf`:

```ini
Database.AutoUpdate.Enabled = 1
Database.AutoUpdate.Path = "../../sql/database_updates/"
Database.AutoUpdate.AuthUpdateName = "auth"
Database.AutoUpdate.CharUpdateName = "character"
Database.AutoUpdate.WorldUpdateName = "world"
Database.AutoUpdate.SortByName = 1
```

On first startup, `mangosd` checks the migrations already recorded in each
database, applies missing SQL files from `sql/database_updates`, and records the
applied files.

Make sure `Database.AutoUpdate.Path` points to the `sql/database_updates`
directory inside your source code checkout. The default value works only when
the server is started from the expected installed directory layout. If you move
the server files or start `mangosd` from a different working directory, update
this path to the matching relative or absolute path for your local repository.

## Verify the Import

You can confirm the databases exist with:

```sh
mariadb -u mangos -p -e "SHOW DATABASES LIKE 'tw_%';"
```

You can also check that key tables exist:

```sh
mariadb -u mangos -p -e "SHOW TABLES FROM tw_logon LIKE 'account';"
mariadb -u mangos -p -e "SHOW TABLES FROM tw_char LIKE 'characters';"
mariadb -u mangos -p -e "SHOW TABLES FROM tw_world LIKE 'creature_template';"
```

## Add the First Realm

The login server reads available realms from `tw_logon.realmlist`. Add at least
one realm row before players try to log in.

For a local server, this is enough:

```sql
REPLACE INTO `tw_logon`.`realmlist`
  (`id`, `name`, `address`, `port`, `icon`, `realmflags`, `timezone`, `allowedSecurityLevel`, `population`, `realmbuilds`)
VALUES
  (1, 'Tortoise WoW', '127.0.0.1', 8090, 0, 0, 1, 0, 0, '7272');
```

Make sure `id` matches `RealmID` in `mangosd.conf`:

```ini
RealmID = 1
WorldServerPort = 8090
```

Use the address that clients can actually reach. For a public or LAN server,
replace `127.0.0.1` with the server's public DNS name, public IP address, or LAN
IP address. The `port` value must match `WorldServerPort`, not the `realmd`
login port.

## Troubleshooting

If the server cannot connect, check that:

- MariaDB is running.
- The username and password in the config files match the database user.
- The user has privileges on `tw_logon`, `tw_char`, `tw_world`, and `tw_logs`.
- The host in the config is correct. Use `127.0.0.1` for local TCP connections.

If auto-updates do not run, check that `Database.AutoUpdate.Path` points to the
repository's `sql/database_updates` directory from the server's working
directory.

## Next Step

Continue to [Running the Server](running-the-server.md).
