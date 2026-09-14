---
layout: default
title: Module Installation
---

# Module Installation

Modules are optional extensions that live in the repository's `modules`
directory. Install modules only from sources you trust and review their
instructions before building them.

Modules published for this core may use the GitHub topic
[`tortoise-module`](https://github.com/topics/tortoise-module).

## Clone a Module

From the repository root, change into the module directory:

```sh
cd modules
```

Clone the module repository:

```sh
git clone <module-repository-url>
```

The module should create a folder under `modules/`, usually named after the
module. A module is discovered by CMake when it contains a `src/` directory.

## Configure the Build

Return to the repository root before running CMake:

```sh
cd ..
```

Build all discovered modules statically:

```sh
cmake -S . -B build -DMODULES=static
cmake --build build --parallel
```

Or build all discovered modules dynamically:

```sh
cmake -S . -B build -DMODULES=dynamic
cmake --build build --parallel
```

Static modules are linked into the server binaries. Dynamic modules are built as
separate loadable module libraries.

## Build a Single Module

Each module also gets a per-module CMake variable generated from its folder
name. For example, a module folder named `mod-example` uses:

```sh
cmake -S . -B build -DMODULE_MOD_EXAMPLE=static
cmake --build build --parallel
```

The supported values are:

| Value | Meaning |
| --- | --- |
| `static` | Build the module into the server binaries. |
| `dynamic` | Build the module as a dynamic module. |
| `disabled` | Do not build the module. |
| `default` | Follow the global `MODULES` setting. |

## Module Config and SQL

If the module ships config files, copy its installed `.conf.dist` file to the
same name without `.dist`, then review the settings before starting the server.

If the module ships database updates, keep database auto-updates enabled and
make sure `Database.AutoUpdate.AllowedModules` in `mangosd.conf` allows the
module. The default `all` value allows every enabled module.

## Next Step

Continue to [Accounts](accounts.md).
