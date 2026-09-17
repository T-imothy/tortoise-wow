---
layout: default
title: gm_subsurveys
---

# gm_subsurveys

Player System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 4 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-surveyid"></a>`surveyId` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | non-negative numeric value |
| <a id="col-subsurveyid"></a>`subsurveyId` | `int(10) unsigned` | NO | `PRI` | `0` |  | non-negative numeric value |
| <a id="col-rank"></a>`rank` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-comment"></a>`comment` | `text` | NO |  |  |  | text/string data |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `surveyId`

non-negative numeric value.

### `subsurveyId`

non-negative numeric value.

### `rank`

non-negative numeric value.

### `comment`

text/string data.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `surveyId`, `subsurveyId` |

