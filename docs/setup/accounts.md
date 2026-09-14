---
layout: default
title: Accounts
---

# Accounts

Tortoise WoW accounts are stored in the `tw_logon` database. Use server
commands for normal account administration so password hashes, realm character
rows, online sessions, and character cleanup are handled consistently.

## Before You Begin

Start `realmd` and `mangosd`, then run account commands from one of these
places:

- The `mangosd` console
- An in-game account with the required permission level
- A configured remote administration console

Commands are shown without the in-game chat prefix. If you run them from an
in-game chat window, use your server's command prefix, usually `.`.

Do not create accounts by inserting password hashes manually unless you are
repairing a database and already know the account hash format.

## Permission Levels

Account permission levels are numeric. Higher levels can use more commands.

| Level | Name | Notes |
| --- | --- | --- |
| `0` | Player | Normal player account. |
| `1` | Observer | Limited staff/view access. |
| `2` | Moderator | Moderation commands. |
| `3` | Developer | Developer and advanced support commands. |
| `4` | Administrator | Administrative commands. |
| `5` | SigmaChad | Reserved internal level. |
| `6` | Console | Server console only. |

The user-facing command is named `gmlevel`, but the current login schema stores
the account's staff level in `tw_logon.account.rank`.

## Create an Account

Use:

```text
account create <username> <password>
```

Example:

```text
account create tester1 "change-this-password"
```

Account names and passwords are normalized by the server. Keep both values at
16 characters or fewer unless the source limit is changed.

New accounts start as player accounts with permission level `0`.

## Set Account Permissions

Use:

```text
account set gmlevel <account> <level>
```

Example:

```text
account set gmlevel tester1 2
```

This makes `tester1` a moderator account.

You cannot raise another account above your own permission level. You also
cannot use this command on your own account.

To remove staff access, set the account back to player level:

```text
account set gmlevel tester1 0
```

## Change a Password

Players can change their own password with:

```text
account password <old-password> <new-password> <new-password>
```

Staff with developer access can reset another account's password with:

```text
account set password <account> <new-password> <new-password>
```

The repeated new password is required so the command can catch typing mistakes.

## Two-Factor Authentication

Two-factor authentication uses a Base32 authenticator secret stored on the
account row in `tw_logon.account.security`.

Administrators can generate and attach a token with:

```text
account twofa <account>
```

The command prints the generated token and updates the account row.

To set a TOTP secret manually, update the account in `tw_logon.account`:

```sql
UPDATE `tw_logon`.`account`
SET `security` = 'BASE32TOTPSECRET',
    `locked` = `locked` | 2
WHERE `username` = 'tester1';
```

Use a valid Base32 secret, using characters `A-Z` and `2-7`. The current login
server reads that secret from `account.security` and validates the authenticator
code when the `locked` bitmask includes `2`.

To force a prompt even when the account is not otherwise locked, also set the
always-enforce bit:

```sql
UPDATE `tw_logon`.`account`
SET `locked` = `locked` | 8
WHERE `username` = 'tester1';
```

The relevant `locked` flags are:

| Value | Name | Meaning |
| --- | --- | --- |
| `1` | `IP_LOCK` | Account is locked to the last known IP address. |
| `2` | `FIXED_PIN` | Current working authenticator-token path used by `account twofa`. |
| `4` | `TOTP` | Named TOTP flag in source; verify current behavior before using directly. |
| `8` | `ALWAYS_ENFORCE` | Prompt for the token even when no lock condition was triggered. |

Successful token checks can add the current IP address to
`tw_logon.account_twofactor_allowed` for 30 days, which lets the account skip
the prompt from that IP until the allowance expires.

## List Characters on an Account

Use:

```text
account characters <account>
```

This lists the characters attached to that account. Use this before destructive
account work so you know what will be affected.

## Remove an Account

Account deletion is console-only and destructive:

```text
account delete <account>
```

When an account is deleted through the server account manager, the server kicks
online characters for that account, deletes those characters from the character
database, removes account tutorial data, deletes the login account row, and
removes realm character counters.

Prefer disabling or banning an account when you only need to block access.
Delete accounts only when you intentionally want to remove the account and its
characters.

## Ban or Unban an Account

To block account access without deleting data, use the ban commands:

```text
ban account <account> <duration> <reason>
unban account <account>
baninfo account <account>
```

Use a duration appropriate for your server policy. Permanent ban duration syntax
depends on the command parser and local command help.

## Related Tables

The most relevant login tables are:

| Table | Purpose |
| --- | --- |
| `tw_logon.account` | Account identity, password hash, rank, login metadata, and security fields. |
| `tw_logon.realmcharacters` | Per-realm character counts for each account. |
| `tw_logon.account_banned` | Account ban history and active bans. |
| `tw_logon.account_twofactor_allowed` | Temporary trusted IP allowances after successful two-factor checks. |
| `tw_logon.rbac_account_permissions` | Account-specific RBAC overrides. |
| `tw_logon.rbac_command_permissions` | Command permission mappings. |

## Next Step

Continue to [Troubleshooting](troubleshooting.md).
