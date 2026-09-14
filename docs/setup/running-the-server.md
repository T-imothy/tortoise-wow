---
layout: default
title: Running the Server
---

# Running the Server

> [!CAUTION]
> Running this software should be treated as an educational exercise for learning how MaNGOS emulators work.  
> You are responsible for how you choose to use this software.  

This guide assumes the project has already been built, configured, and imported
into MariaDB. Before starting the server, make sure:

- `realmd.conf` points to `tw_logon`.
- `mangosd.conf` points to `tw_logon`, `tw_char`, `tw_world`, and `tw_logs`.
- `mangosd.conf` has the correct `DataDir`.
- `tw_logon.realmlist` has a realm row that matches `RealmID`.
- `realmd` and `mangosd` can reach the database server.

The examples below use `/opt/tortoise-wow/server/bin` as the server directory
and `tortoise` as the Linux service user. Replace those values with the path
and user used by your installation.

## Start Order

Start the login server first:

```sh
cd /opt/tortoise-wow/server/bin
./realmd
```

Then start the world server:

```sh
cd /opt/tortoise-wow/server/bin
./mangosd
```

Keep both processes running. Players log in through `realmd`, then connect to
the realm served by `mangosd`.

## Running Interactively

For a private test server, running the daemons directly from a terminal is the
simplest option. This also leaves the `mangosd` command console available.

For a long-running terminal session over SSH, use `screen`:

```sh
screen -S realmd
cd /opt/tortoise-wow/server/bin
./realmd
```

Detach with `Ctrl-a`, then `d`. Create a second session for `mangosd`:

```sh
screen -S mangosd
cd /opt/tortoise-wow/server/bin
./mangosd
```

Reattach later with:

```sh
screen -r realmd
screen -r mangosd
```

## Console Output and Services

Running `mangosd` as a service while the interactive console is enabled can
cause issues. Service managers do not provide a normal console for server
commands, and console output/input handling can behave poorly outside an
interactive terminal.

Use one of these approaches:

- If running under a service manager, set `Console.Enable = 0` in
  `mangosd.conf`.
- If you need the interactive `mangosd` console, run `mangosd` inside `screen`
  instead of a service.

## systemd

Most modern Linux distributions use systemd.

The examples use `mariadb.service` as the database dependency. On some
distributions, the service may be named `mysql.service` instead.

Create `/etc/systemd/system/tortoise-realmd.service`:

```ini
[Unit]
Description=Tortoise WoW Login Server
After=network.target mariadb.service

[Service]
Type=simple
User=tortoise
Group=tortoise
WorkingDirectory=/opt/tortoise-wow/server/bin
ExecStart=/opt/tortoise-wow/server/bin/realmd
Restart=on-failure
RestartSec=5

[Install]
WantedBy=multi-user.target
```

Create `/etc/systemd/system/tortoise-mangosd.service`:

```ini
[Unit]
Description=Tortoise WoW World Server
After=network.target mariadb.service tortoise-realmd.service
Requires=tortoise-realmd.service

[Service]
Type=simple
User=tortoise
Group=tortoise
WorkingDirectory=/opt/tortoise-wow/server/bin
ExecStart=/opt/tortoise-wow/server/bin/mangosd
Restart=on-failure
RestartSec=5

[Install]
WantedBy=multi-user.target
```

Enable and start both services:

```sh
sudo systemctl daemon-reload
sudo systemctl enable --now tortoise-realmd
sudo systemctl enable --now tortoise-mangosd
```

Check status and logs with:

```sh
systemctl status tortoise-realmd
systemctl status tortoise-mangosd
journalctl -u tortoise-realmd -f
journalctl -u tortoise-mangosd -f
```

## OpenRC

OpenRC is common on Alpine, Gentoo, and some other distributions.

Create `/etc/init.d/tortoise-realmd`:

```sh
#!/sbin/openrc-run

name="Tortoise WoW Login Server"
command="/opt/tortoise-wow/server/bin/realmd"
command_user="tortoise:tortoise"
directory="/opt/tortoise-wow/server/bin"
pidfile="/run/tortoise-realmd.pid"
command_background="yes"
depend() {
    need net
    after mariadb
}
```

Create `/etc/init.d/tortoise-mangosd`:

```sh
#!/sbin/openrc-run

name="Tortoise WoW World Server"
command="/opt/tortoise-wow/server/bin/mangosd"
command_user="tortoise:tortoise"
directory="/opt/tortoise-wow/server/bin"
pidfile="/run/tortoise-mangosd.pid"
command_background="yes"
depend() {
    need net tortoise-realmd
    after mariadb
}
```

Enable and start the services:

```sh
sudo chmod +x /etc/init.d/tortoise-realmd /etc/init.d/tortoise-mangosd
sudo rc-update add tortoise-realmd default
sudo rc-update add tortoise-mangosd default
sudo rc-service tortoise-realmd start
sudo rc-service tortoise-mangosd start
```

## runit

For runit-based systems, each service has a directory containing a `run` script.

Create `/etc/sv/tortoise-realmd/run`:

```sh
#!/bin/sh
cd /opt/tortoise-wow/server/bin || exit 1
exec chpst -u tortoise:tortoise ./realmd
```

Create `/etc/sv/tortoise-mangosd/run`:

```sh
#!/bin/sh
cd /opt/tortoise-wow/server/bin || exit 1
exec chpst -u tortoise:tortoise ./mangosd
```

Enable the services:

```sh
sudo chmod +x /etc/sv/tortoise-realmd/run /etc/sv/tortoise-mangosd/run
sudo ln -s /etc/sv/tortoise-realmd /var/service/
sudo ln -s /etc/sv/tortoise-mangosd /var/service/
```

Manage them with:

```sh
sudo sv status tortoise-realmd
sudo sv status tortoise-mangosd
sudo sv restart tortoise-realmd
sudo sv restart tortoise-mangosd
```

## SysVinit

Older distributions may still use SysVinit scripts.

Create `/etc/init.d/tortoise-realmd`:

```sh
#!/bin/sh
### BEGIN INIT INFO
# Provides:          tortoise-realmd
# Required-Start:    $network mysql
# Required-Stop:     $network mysql
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: Tortoise WoW login server
### END INIT INFO

case "$1" in
  start)
    start-stop-daemon --start --background --chuid tortoise:tortoise \
      --chdir /opt/tortoise-wow/server/bin \
      --exec /opt/tortoise-wow/server/bin/realmd
    ;;
  stop)
    start-stop-daemon --stop --exec /opt/tortoise-wow/server/bin/realmd
    ;;
  restart)
    "$0" stop
    "$0" start
    ;;
  *)
    echo "Usage: $0 {start|stop|restart}"
    exit 1
    ;;
esac
```

Create a matching `/etc/init.d/tortoise-mangosd` script by replacing `realmd`
with `mangosd`. Enable both services with the service tools provided by your
distribution, usually:

```sh
sudo chmod +x /etc/init.d/tortoise-realmd /etc/init.d/tortoise-mangosd
sudo update-rc.d tortoise-realmd defaults
sudo update-rc.d tortoise-mangosd defaults
sudo service tortoise-realmd start
sudo service tortoise-mangosd start
```

## Stopping the Server

If running interactively, stop `mangosd` from its console:

```text
server shutdown 0
```

Then stop `realmd` with `Ctrl-c`.

If running as services, stop the world server first, then the login server:

```sh
sudo systemctl stop tortoise-mangosd
sudo systemctl stop tortoise-realmd
```

Use the matching commands for OpenRC, runit, or SysVinit if you are not using
systemd.

## Next Step

Continue to [realmd.conf](realmd-configuration.md).
