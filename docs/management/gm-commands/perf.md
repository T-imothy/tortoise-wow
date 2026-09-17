---
layout: default
title: "GM Command: .perf"
---

# `.perf`

- Security: Administrator (4)
- Console: yes
- Subcommands: `.perf enable`, `.perf intervalreport`, `.perf resources`, `.perf cpu`, `.perf memory`

Syntax:

```text
.perf <subcommand>
```

Example:

```text
.perf enable
```

---

## `.perf enable`

- Security: Administrator (4)
- Console: yes
- Handler: `HandlePerfEnable`


---

## `.perf intervalreport`

- Security: Administrator (4)
- Console: yes
- Handler: `HandlePerfIntervalReport`


---

## `.perf resources`

- Security: Developer (3)
- Console: yes
- Handler: `HandlePerfStatsCommand`


---

## `.perf cpu`

- Security: Developer (3)
- Console: yes
- Handler: `HandlePerfReportCPU`


---

## `.perf memory`

- Security: Developer (3)
- Console: yes
- Handler: `HandlePerfReportMemory`


---

## `.blockegg`

- Security: Developer (3)
- Console: no
- Handler: `HandleBlockEggsCommand`

Syntax:

```text
.blockegg <account>
```

Example:

```text
.blockegg accountname
```

---

## `.cleaninventory`

- Security: Developer (3)
- Console: no
- Handler: `HandleCleanInventoryCommand`


---

## `.showborders`

- Security: Developer (3)
- Console: no
- Handler: `HandleShowBordersCommand`


---

## `.queststatuses`

- Security: Player (0)
- Console: no
- Handler: `HandleQuestStatusesCommand`

[Back to GM Commands](../gm-commands.md)
