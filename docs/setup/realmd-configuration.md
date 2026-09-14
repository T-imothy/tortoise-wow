---
layout: default
title: realmd.conf
---

# realmd.conf

`realmd.conf` configures the login server. The login server accepts client login
connections, authenticates accounts, serves the realm list, and can provide
client patch files.

Start from the distributed template:

```sh
cp server/etc/realmd.conf.dist server/etc/realmd.conf
```

Adjust paths and database credentials for your local install before starting
`realmd`.

## Database

| Setting | Default | Description |
| --- | --- | --- |
| `LoginDatabaseInfo` | `"127.0.0.1;3306;mangos;mangos;tw_logon"` | Login database connection string in `host;port;user;password;database` format. |

The login database is usually `tw_logon`. It stores accounts, bans, realm list
entries, two-factor authentication data, and login metadata.

## Network

| Setting | Default | Description |
| --- | --- | --- |
| `RealmServerPort` | `3724` | TCP port used by the login server. Vanilla clients normally connect to `3724`. |
| `BindIP` | `"0.0.0.0"` | IP address or hostname to bind. Use `0.0.0.0` to listen on all interfaces. |
| `MinRealmListDelay` | `1` | Minimum seconds between realm-list requests from the same connection before the request is treated as too frequent. |
| `RealmsStateUpdateDelay` | `10` | Seconds between realm list refreshes from the login database. |
| `HostAddressOverride` | `"0.0.0.0"` | Overrides every address from the `realmlist` table when set to another address. Useful for proxy setups. |
| `MaxSessionDuration` | `300` | Maximum login socket session duration in seconds before the connection is closed. |

Only use `HostAddressOverride` when every realm should advertise the same
external address. For ordinary local or single-realm setups, keep it at
`0.0.0.0` and configure realm addresses in the database.

## Paths

| Setting | Default | Description |
| --- | --- | --- |
| `LogsDir` | `"../logs/"` | Directory where log files are written. |
| `PatchesDir` | `"./patches"` | Directory used to serve client patch files. |
| `PidFile` | `"twrealmd.pid"` | PID file written by the daemon. Leave empty to disable PID file creation. |

Patch files should be MPQ files in the patch directory. The template notes the
format `<build><locale>.mpq`, such as `65535enGB.mpq`; the current login code
also checks for Turtle WoW patch names such as `twpatch.mpq`.

## Logging

| Setting | Default | Description |
| --- | --- | --- |
| `LogLevel` | `1` | Console log level. `0` minimum, `1` error, `2` detail, `3` full/debug. |
| `LogTime` | `0` | Include timestamps in console output. |
| `LogFile` | `"Realmd.log"` | Log file name. |
| `LogTimestamp` | `0` | Include the server start timestamp in the log file name. |
| `LogFileLevel` | `1` | File log level. `0` minimum, `1` error, `2` detail, `3` full/debug. |
| `LogColors` | `""` | Console color override in `normal detail debug error` order. |

`LogColors` uses numeric color ids from the template: `0` black, `1` red, `2`
green, `3` brown, `4` blue, `5` magenta, `6` cyan, `7` grey, `8` yellow, `9`
light red, `10` light green, `11` light blue, `12` light magenta, `13` light
cyan, and `14` white.

## Process Settings

| Setting | Default | Description |
| --- | --- | --- |
| `UseProcessors` | `0` | Windows-only processor affinity bitmask. `0` means no custom affinity. |
| `ProcessPriority` | `1` | Windows-only high-priority process setting. |
| `WaitAtStartupError` | `0` | Wait before continuing after startup errors, useful when running from a console window. |
| `MaxPingTime` | `3` | Minutes between database pings used to keep the login database connection alive. |

## Login Security

| Setting | Default | Description |
| --- | --- | --- |
| `WrongPass.MaxCount` | `10` | Failed password attempts before autoban logic runs. Set `0` to disable. |
| `WrongPass.BanTime` | `300` | Autobans duration in seconds. |
| `WrongPass.BanType` | `0` | Autobans target. `0` bans the IP address; `1` bans the account. |
| `ReqEmailVerification` | `0` | Require verified email before allowing login. |
| `ReqEmailSince` | `0` | Unix timestamp cutoff for email verification enforcement. Accounts joined before this timestamp are exempt. |
| `GeoLocking` | `0` | Block or challenge account logins when a geographical location change is detected. Requires populated `geoip` data. |
| `StrictVersionCheck` | `1` | Reject modified or unexpected client versions. |
| `ForcePinAccountRank` | `1` | Require PIN or two-factor authentication for accounts at this rank or higher. |

When `GeoLocking` is enabled, `realmd` requires the `geoip` table to contain
data. If it is empty, startup fails.

## Mail

| Setting | Default | Description |
| --- | --- | --- |
| `SendMail` | `0` | Allow the server to send email. Requires a build with SendGrid support. |
| `MailFrom` | `"no-reply@turtle-wow.org"` | Sender address for outgoing login-server email. |
| `MailCertChecks` | `1` | Validate mail server certificates. |
| `SendGridKey` | `""` | SendGrid API key. Required if SendGrid email is enabled. |
| `GeolockGUID` | `""` | SendGrid template GUID for geolock emails. |

## Advanced Settings

These settings are read by the login server but are not present in the default
template.

| Setting | Default | Description |
| --- | --- | --- |
| `Proxy.PassIp` | `0` | Read the client IP from a proxy-provided header or packet data path instead of the socket address. Use only with trusted proxy infrastructure. |
| `Network.CN` | `0` | Enables special handling for build `7070` login challenges. Leave disabled unless you intentionally run that network mode. |

## Runtime Patch Speed Settings

Patch download speed is controlled from the `tw_logon.config` table rather than
from `realmd.conf`. The login server periodically reloads these values.

| Config ID | Meaning |
| --- | --- |
| `1` | Patch download speed limit in KB/s. |
| `2` | Hard patch download speed limit mode. |

## Common Local Example

For a local development server, the most commonly changed settings are:

```ini
LoginDatabaseInfo = "127.0.0.1;3306;mangos;mangos;tw_logon"
RealmServerPort = 3724
BindIP = "0.0.0.0"
LogsDir = "../logs/"
PatchesDir = "./patches"
```

If clients can log in but see the wrong realm address, check the `realmlist`
table first. Use `HostAddressOverride` only when every realm should advertise a
single forced address.

## Next Step

Continue to [mangosd.conf](mangosd-configuration.md).
