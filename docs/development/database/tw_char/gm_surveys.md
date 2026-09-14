---
layout: default
title: gm_surveys
---

# gm_surveys

Player System

| Engine | Columns | Charset | Row Format |
| --- | --- | --- | --- |
| MyISAM | 5 | utf8mb3 | DYNAMIC |

## Field Definitions

| Field | Type | Null | Key | Default | Extra | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| <a id="col-surveyid"></a>`surveyId` | `int(10) unsigned` | NO | `PRI` |  | AUTO_INCREMENT | non-negative numeric value |
| <a id="col-guid"></a>`guid` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; identifier column |
| <a id="col-mainsurvey"></a>`mainSurvey` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value |
| <a id="col-overallcomment"></a>`overallComment` | `longtext` | NO |  |  |  | text/string data |
| <a id="col-createtime"></a>`createTime` | `int(10) unsigned` | NO |  | `0` |  | non-negative numeric value; time/delay value; confirm unit in server usage |

## Value Semantics

This section is generated from schema types, column names, comments, and inferred relationships. Treat heuristic references as review candidates.

### `surveyId`

non-negative numeric value.

### `guid`

non-negative numeric value; identifier column.

### `mainSurvey`

non-negative numeric value.

### `overallComment`

text/string data.

### `createTime`

non-negative numeric value; time/delay value; confirm unit in server usage.

## Keys and Indexes

| Kind | Name | Columns |
| --- | --- | --- |
| PRIMARY | `PRIMARY` | `surveyId` |
