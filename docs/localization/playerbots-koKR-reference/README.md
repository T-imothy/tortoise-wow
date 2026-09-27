# Korean PlayerBot strings: reference data

This directory holds community-reviewed Korean text for future PlayerBot localization work. It is **reference data, not a database update**. Nothing here is executed or loaded by the server.

The JSON Lines files contain Korean strings and only the identifiers or hashes needed to compare them with current module data. They omit English-only translation fields and all other locales. `source_id` and `source_name_id` refer to the source collection; **they are not IDs in this repository's databases**. `source_text_sha256` and `source_template_sha256` hash the decoded source English fields without publishing those fields.

| File | Korean records | Contents |
| --- | ---: | --- |
| `ai_playerbot_help_texts.jsonl` | 2,922 | Help text in `text_loc1`; topic key and source-text hashes |
| `ai_playerbot_texts.jsonl` | 1,938 | Chat text in `text_loc1`; lookup key, say/reply types, source-text hash |
| `ai_playerbot_names.jsonl` | 100,000 | Character-name candidates from the legacy bot name pool |
| `ai_playerbot_guild_names.jsonl` | 400 | Guild-name candidates from the legacy bot name pool |
| `ai_playerbot_arena_team_names.jsonl` | 300 | Arena-team-name candidates from the legacy bot name pool |
| `legacy_instance_labels.jsonl` | 32 | Guild, rank, message, and auction-bot labels tied to a particular instance |

The five chat-text rows containing only placeholder tokens were excluded. Translation placeholders and translator attribution are excluded throughout. File counts and SHA-256 checksums are in `manifest.json`.

## Why this is separate from the world-locale SQL update

The documented `TortoiseBots` migration build creates `ai_playerbot_help_texts` and `ai_playerbot_texts`, but its seed rows differ from this reference collection and its IDs are generated at installation time. At the pinned module revision (`e33d3851b7f41ab3646df0cf0bb00ef5e8dfdecc`), only one help-topic name overlaps (its template does not match), and only three chat entries match on key, default text, and say/reply types. Applying source IDs or replacing those rows would attach Korean text to unrelated bot behavior.

The three name pools are defined in the retained `mod-playerbots` reference module, not in the `TortoiseBots` migration schema. The instance labels have no stable target IDs or locale columns. They are included solely so future maintainers can review the Korean wording.

Before turning any record into an executable update, compare its meaning and placeholders with the **current** module text, select a stable target key, and test the result with a Korean client. Do not join on the source IDs.
