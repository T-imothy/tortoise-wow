-- ==============================================
-- FILE: mending_light.sql
-- GENERATED: 20260916091628
-- ==============================================
UPDATE `spell_template`
SET `script_name` = 'spell_paladin_mending_light',
    `effectBonusCoefficient2` = 0.05
WHERE `entry` IN (
    51324, 51875, 51876, 51877, 51878, 51879, 51880, 51881
    );

UPDATE `spell_affect`
SET `SpellFamilyMask` = 137438953472
WHERE `entry` IN (
    51317, 51318, 51319, 51320, 51321
    );
-- ==============================================
-- FILE: zeljeb_text_fix.sql
-- GENERATED: 20260916091628
-- ==============================================
UPDATE `broadcast_text` SET `chat_type` = 1
WHERE `entry` IN (6249501, 6249502, 6249503) AND `chat_type` = 12;

UPDATE `broadcast_text` SET `chat_type` = 0
WHERE `entry` IN (6271501, 6271502) AND `chat_type` = 11;
