-- Token 61111 is also supplied by 20260903233000 with identical mappings.
-- ==============================================
-- FILE: custom_skin_mappings.sql
-- GENERATED: 20260906113303
-- ==============================================

INSERT INTO `custom_character_skins`
(
    `token_id`,
    `skin_male`,
    `skin_female`
)
VALUES
(61111, 19, 18),
(61112, 1, 15),
(81256, 21, 13)
ON DUPLICATE KEY UPDATE `skin_male`=VALUES(`skin_male`), `skin_female`=VALUES(`skin_female`);
