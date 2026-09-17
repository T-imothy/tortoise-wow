---
layout: default
title: gm_tickets
---

# gm_tickets

Player System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 20 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-ticketid"></a>`ticketId` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | non-negative numeric value |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO |  | `0` |  | Global Unique Identifier of ticket creator; non-negative numeric value; identifier column |
| <a id="col-name"></a>`name` | `varchar(12)` | NO |  |  |  | Name of ticket creator; text/string data |
| <a id="col-message"></a>`message` | `text` | NO |  |  |  | text/string data |
| <a id="col-createtime"></a>`createTime` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-mapid"></a>`mapId` | `smallint(5) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-posx"></a>`posX` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-posy"></a>`posY` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-posz"></a>`posZ` | `float` | NO |  | `0` |  | numeric value |
| <a id="col-lastmodifiedtime"></a>`lastModifiedTime` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |
| <a id="col-closedby"></a>`closedBy` | `int(11)` | NO |  | `0` |  | numeric value |
| <a id="col-assignedto"></a>`assignedTo` | `int(10) unsigned` | NO |  | `0` |  | GUID of admin to whom ticket is assigned; non-negative numeric value |
| <a id="col-comment"></a>`comment` | `text` | NO |  |  |  | text/string data |
| <a id="col-response"></a>`response` | `text` | NO |  |  |  | text/string data |
| <a id="col-completed"></a>`completed` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-escalated"></a>`escalated` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-viewed"></a>`viewed` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-haveticket"></a>`haveTicket` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-tickettype"></a>`ticketType` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-securityneeded"></a>`securityNeeded` | `tinyint(3) unsigned` | NO |  | `0` |  | non-negative numeric value |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `ticketId`

non-negative numeric value.

### `guid`

non-negative numeric value; identifier column.

### `name`

text/string data.

### `message`

text/string data.

### `createTime`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `mapId`

non-negative numeric value.

References: [`map_template`](map_template.md).`entry`.

### `posX`

numeric value.

### `posY`

numeric value.

### `posZ`

numeric value.

### `lastModifiedTime`

non-negative numeric value; time/delay value; confirm unit in server usage.

### `closedBy`

numeric value.

### `assignedTo`

non-negative numeric value.

### `comment`

text/string data.

### `response`

text/string data.

### `completed`

non-negative numeric value.

### `escalated`

non-negative numeric value.

### `viewed`

non-negative numeric value.

### `haveTicket`

non-negative numeric value.

### `ticketType`

non-negative numeric value.

### `securityNeeded`

non-negative numeric value.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `ticketId` |

## Related Tables

### Outgoing References

| Column | Target | Confidence | Notes |
| --- | --- | --- | --- |
| `mapId` | [`map_template`](map_template.md).`entry` | heuristic | inferred from column name |

