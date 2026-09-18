-- ==============================================
-- FILE: an_ill_omen.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `conditions`
(
    `condition_entry`,
    `type`,
    `value1`,
    `value2`,
    `value3`,
    `value4`,
    `flags`
)
VALUES
(41912, 9, 41912, 1, 0, 0, 0);

INSERT INTO `broadcast_text`
(
    `entry`,
    `male_text`,
    `female_text`,
    `chat_type`,
    `sound_id`,
    `language_id`,
    `emote_id1`,
    `emote_id2`,
    `emote_id3`,
    `emote_delay1`,
    `emote_delay2`,
    `emote_delay3`
)
VALUES
(4292003, 'What does the chieftan''s son have to do with a Parash''ka? These are truly dire times. Still, I will not deny my student''s request, he would not disturb his master for trivialities.', 'What does the chieftan''s son have to do with a Parash''ka? These are truly dire times. Still, I will not deny my student''s request, he would not disturb his master for trivialities.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(4292004, 'Riftmaster Ral''pekta inspects the red crystal.', 'Riftmaster Ral''pekta inspects the red crystal.', 2, 0, 0, 0, 0, 0, 0, 0, 0),
(4292005, 'This crystal is...! No, it couldn''t... I have to make sure I am wrong!', 'This crystal is...! No, it couldn''t... I have to make sure I am wrong!', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(4292006, 'Riftmaster Ral''pekta channels arcane energy into the crystal.', 'Riftmaster Ral''pekta channels arcane energy into the crystal.', 2, 0, 0, 0, 0, 0, 0, 0, 0),
(4292007, 'Gah!', 'Gah!', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(4292008, 'Impossible, slay this fiend!', 'Impossible, slay this fiend!', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6298901, 'He hungers...', 'He hungers...', 0, 0, 0, 0, 0, 0, 0, 0, 0);

UPDATE `gossip_menu_option`
SET `action_menu_id` = -1,
    `action_script_id` = 6292002,
    `condition_id` = 41912
WHERE `menu_id` = 62920
AND `id` = 0;

INSERT INTO `gossip_scripts`
(
    `id`,
    `delay`,
    `priority`,
    `command`,
    `datalong`,
    `datalong2`,
    `datalong3`,
    `datalong4`,
    `target_param1`,
    `target_param2`,
    `target_type`,
    `data_flags`,
    `dataint`,
    `dataint2`,
    `dataint3`,
    `dataint4`,
    `x`,
    `y`,
    `z`,
    `o`,
    `condition_id`,
    `comments`
)
VALUES
(6292002, 0, 0, 4, 147, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'An Ill Omen - Riftmaster Ral''pekta Becomes Uninteractible'),
(6292002, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4292003, 0, 0, 0, 0, 0, 0, 0, 0, 'An Ill Omen - Riftmaster Ral''pekta Say 1'),
(6292002, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4292004, 0, 0, 0, 0, 0, 0, 0, 0, 'An Ill Omen - Riftmaster Ral''pekta Inspects Crystal'),
(6292002, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4292005, 0, 0, 0, 0, 0, 0, 0, 0, 'An Ill Omen - Riftmaster Ral''pekta Say 2'),
(6292002, 30, 0, 15, 23017, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'An Ill Omen - Riftmaster Ral''pekta Cast Arcane Channel'),
(6292002, 30, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4292006, 0, 0, 0, 0, 0, 0, 0, 0, 'An Ill Omen - Riftmaster Ral''pekta Channels Crystal'),
(6292002, 37, 0, 5, 0, 23017, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'An Ill Omen - Riftmaster Ral''pekta Stop Casting'),
(6292002, 37, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4292007, 0, 0, 0, 0, 0, 0, 0, 0, 'An Ill Omen - Riftmaster Ral''pekta Say 3'),
(6292002, 37, 2, 10, 62989, 120000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 6749.655762, -6160.727051, 32.459267, 2.704545, 0, 'An Ill Omen - Summon Crystal Entity'),
(6292002, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4292008, 0, 0, 0, 0, 0, 0, 0, 0, 'An Ill Omen - Riftmaster Ral''pekta Say 4'),
(6292002, 40, 1, 4, 147, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'An Ill Omen - Riftmaster Ral''pekta Becomes Interactible');

INSERT INTO `creature_ai_events`
(
    `id`,
    `creature_id`,
    `condition_id`,
    `event_type`,
    `event_inverse_phase_mask`,
    `event_chance`,
    `event_flags`,
    `event_param1`,
    `event_param2`,
    `event_param3`,
    `event_param4`,
    `action1_script`,
    `action2_script`,
    `action3_script`,
    `comment`
)
VALUES
(6298901, 62989, 0, 11, 0, 100, 0, 0, 0, 0, 0, 6298901, 0, 0, 'Crystal Entity - Say line on spawn');

INSERT INTO `creature_ai_scripts`
(
    `id`,
    `delay`,
    `priority`,
    `command`,
    `datalong`,
    `datalong2`,
    `datalong3`,
    `datalong4`,
    `target_param1`,
    `target_param2`,
    `target_type`,
    `data_flags`,
    `dataint`,
    `dataint2`,
    `dataint3`,
    `dataint4`,
    `x`,
    `y`,
    `z`,
    `o`,
    `condition_id`,
    `comments`
)
VALUES
(6298901, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6298901, 0, 0, 0, 0, 0, 0, 0, 0, 'An Ill Omen - Crystal Entity Say');

-- ==============================================
-- FILE: answers_from_father.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `conditions`
(
    `condition_entry`,
    `type`,
    `value1`,
    `value2`,
    `value3`,
    `value4`,
    `flags`
)
VALUES
(41915, 9, 41915, 1, 0, 0, 0);

INSERT INTO `broadcast_text`
(
    `entry`,
    `male_text`,
    `female_text`,
    `chat_type`,
    `sound_id`,
    `language_id`,
    `emote_id1`,
    `emote_id2`,
    `emote_id3`,
    `emote_delay1`,
    `emote_delay2`,
    `emote_delay3`
)
VALUES
(6285003, 'My son? What is the meaning of this?', 'My son? What is the meaning of this?', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6285004, 'Ar''lia, just what are you talking about? What are you accusing me of?', 'Ar''lia, just what are you talking about? What are you accusing me of?', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6285005, 'Son, your words are bold and unruly towards me, your father. They cut deep, but can only do so because they are the truth. Yes, I hid things from you, out of shame and in fear of my own weakness.', 'Son, your words are bold and unruly towards me, your father. They cut deep, but can only do so because they are the truth. Yes, I hid things from you, out of shame and in fear of my own weakness.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6285006, 'Bhu''robi had always been critical of out ways, especially after our escape to this world. Our inaction towards the advances of the demonic orcs, while posessing the power of the Draenethyst, is a flaw that he was deeply revolted by.', 'Bhu''robi had always been critical of out ways, especially after our escape to this world. Our inaction towards the advances of the demonic orcs, while posessing the power of the Draenethyst, is a flaw that he was deeply revolted by.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6285007, 'My son, tell me: if you were in mortal danger, would you not do everything you can to survive? In such situations, rationality often subsides in favor of our instincts. Bhu''robi knew this all too well. I still remember his last words to me as if they were uttered mere moments ago.', 'My son, tell me: if you were in mortal danger, would you not do everything you can to survive? In such situations, rationality often subsides in favor of our instincts. Bhu''robi knew this all too well. I still remember his last words to me as if they were uttered mere moments ago.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6285008, 'You are shackled by your traditions, stuck in the mire of your self-inflicted lethargy. If you wish to rot dwelling on the past, so be it. But I will usher in a new dawn for our people. And then you will see the truth yourself.', 'You are shackled by your traditions, stuck in the mire of your self-inflicted lethargy. If you wish to rot dwelling on the past, so be it. But I will usher in a new dawn for our people. And then you will see the truth yourself.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6285009, 'Ar''lia...', 'Ar''lia...', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(57101, 'Father, you haven''t told me the truth, have you?', 'Father, you haven''t told me the truth, have you?', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(57102, 'Don''t deny it, Father. We have discovered Bhu''robi''s true goal. It was never merely a simple dispute about out traditions and beliefs, was it? Tell us what really happened that night you talked.', 'Don''t deny it, Father. We have discovered Bhu''robi''s true goal. It was never merely a simple dispute about out traditions and beliefs, was it? Tell us what really happened that night you talked.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(57103, 'But the Draenethyst are sacred relics to the draenei. Out of all people, he should''ve known this ths the most as an Elder.', 'But the Draenethyst are sacred relics to the draenei. Out of all people, he should''ve known this ths the most as an Elder.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(57104, 'Bhu''robi...', 'Bhu''robi...', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(57105, 'I have much to comtemplate, father. Before I leave, let me say this: The father I knew would have taken action in the face of danger. Just like he braved the horrors of Draenor. With resolve and determination.', 'I have much to comtemplate, father. Before I leave, let me say this: The father I knew would have taken action in the face of danger. Just like he braved the horrors of Draenor. With resolve and determination.', 0, 0, 0, 0, 0, 0, 0, 0, 0);

UPDATE `gossip_menu_option`
SET `action_menu_id` = -1,
    `action_script_id` = 6285002,
    `condition_id` = 41915
WHERE `menu_id` = 62850
AND `id` = 0;

INSERT INTO `gossip_scripts`
(
    `id`,
    `delay`,
    `priority`,
    `command`,
    `datalong`,
    `datalong2`,
    `datalong3`,
    `datalong4`,
    `target_param1`,
    `target_param2`,
    `target_type`,
    `data_flags`,
    `dataint`,
    `dataint2`,
    `dataint3`,
    `dataint4`,
    `x`,
    `y`,
    `z`,
    `o`,
    `condition_id`,
    `comments`
)
VALUES
(6285002, 0, 0, 4, 147, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Answers from Father - Moro''gai K''la Becomes Uninteractible'),
(6285002, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6285003, 0, 0, 0, 0, 0, 0, 0, 0, 'Answers from Father - Moro''gai K''la Say 1'),
(6285002, 0, 2, 10, 571, 0, 0, 0, 0, 0, 0, 0, 2, 57100, -1, 8, 6776.019043, -6146.787109, 68.918442, 0.612012, 0, 'Answers from Father - Summon Ar''lia'),
(6285002, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6285004, 0, 0, 0, 0, 0, 0, 0, 0, 'Answers from Father - Moro''gai K''la Say 2'),
(6285002, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6285005, 0, 0, 0, 0, 0, 0, 0, 0, 'Answers from Father - Moro''gai K''la Say 3'),
(6285002, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6285006, 0, 0, 0, 0, 0, 0, 0, 0, 'Answers from Father - Moro''gai K''la Say 4'),
(6285002, 54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6285007, 0, 0, 0, 0, 0, 0, 0, 0, 'Answers from Father - Moro''gai K''la Say 5'),
(6285002, 69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6285008, 0, 0, 0, 0, 0, 0, 0, 0, 'Answers from Father - Moro''gai K''la Say 6'),
(6285002, 102, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6285009, 0, 0, 0, 0, 0, 0, 0, 0, 'Answers from Father - Moro''gai K''la Say 7'),
(6285002, 105, 0, 8, 60083, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41915, 'Answers from Father - Confronted Moro''gai K''la Credit'),
(6285002, 105, 1, 4, 147, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Answers from Father - Moro''gai K''la Becomes Interactible');

INSERT INTO `generic_scripts`
(
    `id`,
    `delay`,
    `priority`,
    `command`,
    `datalong`,
    `datalong2`,
    `datalong3`,
    `datalong4`,
    `target_param1`,
    `target_param2`,
    `target_type`,
    `data_flags`,
    `dataint`,
    `dataint2`,
    `dataint3`,
    `dataint4`,
    `x`,
    `y`,
    `z`,
    `o`,
    `condition_id`,
    `comments`
)
VALUES
(57100, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57101, 0, 0, 0, 0, 0, 0, 0, 0, 'Answers from Father - Ar''lia Say 1'),
(57100, 4, 1, 3, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6781.931152, -6143.032227, 68.918442, 0, 0, 'Answers from Father - Ar''lia Move Forward'),
(57100, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57102, 0, 0, 0, 0, 0, 0, 0, 0, 'Answers from Father - Ar''lia Say 2'),
(57100, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57103, 0, 0, 0, 0, 0, 0, 0, 0, 'Answers from Father - Ar''lia Say 3'),
(57100, 89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57104, 0, 0, 0, 0, 0, 0, 0, 0, 'Answers from Father - Ar''lia Say 4'),
(57100, 92, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57105, 0, 0, 0, 0, 0, 0, 0, 0, 'Answers from Father - Ar''lia Say 5'),
(57100, 102, 0, 3, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6776.019043, -6146.787109, 68.918442, 0.612012, 0, 'Answers from Father - Ar''lia Move Back'),
(57100, 110, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Answers from Father - Ar''lia Despawn');

-- ==============================================
-- FILE: arlia_quests.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `creature_questrelation`
(
    `id`,
    `quest`
)
VALUES
(62986, 41912),
(62986, 41915),
(62986, 41911);

INSERT INTO `creature_involvedrelation`
(
    `id`,
    `quest`
)
VALUES
(62986, 41917),
(62986, 41910),
(62986, 41914),
(62986, 41911);

-- ==============================================
-- FILE: blackroot_totems.sql
-- GENERATED: 20260915075403
-- ==============================================
UPDATE `quest_template`
SET `SpecialFlags` = `SpecialFlags` | 1
WHERE `entry` = 41899;

-- ==============================================
-- FILE: bound_in_stone.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `creature_questrelation`
(
    `id`,
    `quest`
)
VALUES
(62981, 42051);

INSERT INTO `creature_involvedrelation`
(
    `id`,
    `quest`
)
VALUES
(62981, 42051);

UPDATE `spell_template`
SET `script_name` = 'spell_moonwhisper_bundle_of_beads'
WHERE `entry` = 37098;

-- ==============================================
-- FILE: cook_remsai_quests.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `creature_involvedrelation`
(
    `id`,
    `quest`
)
VALUES
(62861, 41944);

-- ==============================================
-- FILE: delivery_from_talendris.sql
-- GENERATED: 20260915075403
-- ==============================================
UPDATE `creature_template`
SET `scale` = 1,
    `dmg_min` = 102.267876,
    `dmg_max` = 131.14238,
    `attack_power` = 206,
    `ranged_dmg_min` = 75.210083,
    `ranged_dmg_max` = 103.413864,
    `ranged_attack_power` = 144
WHERE `entry` = 63160;

INSERT INTO `creature`
(
    `guid`,
    `id`,
    `id2`,
    `id3`,
    `id4`,
    `map`,
    `position_x`,
    `position_y`,
    `position_z`,
    `orientation`,
    `spawntimesecsmin`,
    `spawntimesecsmax`,
    `wander_distance`,
    `health_percent`,
    `mana_percent`,
    `movement_type`,
    `spawn_flags`,
    `visibility_mod`
)
VALUES
(2596626, 63160, 0, 0, 0, 1, 2694, -3888.459961, 109.014999, 1.2837400436401367, 300, 300, 0, 100, 100, 0, 0, 0);

-- ==============================================
-- FILE: elder_krasheen_quests.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `creature_questrelation`
(
    `id`,
    `quest`
)
VALUES
(62863, 41922);

INSERT INTO `creature_involvedrelation`
(
    `id`,
    `quest`
)
VALUES
(62863, 41921);

-- ==============================================
-- FILE: elder.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `creature_addon`
(
    `guid`,
    `display_id`,
    `mount_display_id`,
    `equipment_id`,
    `stand_state`,
    `sheath_state`,
    `emote_state`,
    `auras`
)
VALUES
(2597153, 0, 0, -1, 7, 1, 0, NULL);

INSERT INTO `creature`
(
    `guid`,
    `id`,
    `id2`,
    `id3`,
    `id4`,
    `map`,
    `position_x`,
    `position_y`,
    `position_z`,
    `orientation`,
    `spawntimesecsmin`,
    `spawntimesecsmax`,
    `wander_distance`,
    `health_percent`,
    `mana_percent`,
    `movement_type`,
    `spawn_flags`,
    `visibility_mod`
)
VALUES
(2593826, 62923, 0, 0, 0, 1, 6783.370117, -6139.529785, 43.655399, 5.8744401931762695, 300, 300, 0, 100, 100, 0, 0, 0),
(2597153, 63177, 0, 0, 0, 1, 6786.189941, -6142.830078, 44.298901, 4.1876702308654785, 300, 300, 0, 100, 100, 0, 0, 0);

INSERT INTO `creature_equip_template`
(
    `entry`,
    `equipentry1`,
    `equipentry2`,
    `equipentry3`
)
VALUES
(62923, 19570, 0, 0);

INSERT INTO `creature_template`
(
    `entry`,
    `display_id1`,
    `display_id2`,
    `display_id3`,
    `display_id4`,
    `mount_display_id`,
    `name`,
    `subname`,
    `gossip_menu_id`,
    `level_min`,
    `level_max`,
    `health_min`,
    `health_max`,
    `mana_min`,
    `mana_max`,
    `armor`,
    `faction`,
    `npc_flags`,
    `speed_walk`,
    `speed_run`,
    `scale`,
    `detection_range`,
    `call_for_help_range`,
    `leash_range`,
    `rank`,
    `xp_multiplier`,
    `dmg_min`,
    `dmg_max`,
    `dmg_school`,
    `attack_power`,
    `dmg_multiplier`,
    `base_attack_time`,
    `ranged_attack_time`,
    `unit_class`,
    `unit_flags`,
    `dynamic_flags`,
    `beast_family`,
    `trainer_type`,
    `trainer_spell`,
    `trainer_class`,
    `trainer_race`,
    `ranged_dmg_min`,
    `ranged_dmg_max`,
    `ranged_attack_power`,
    `type`,
    `type_flags`,
    `loot_id`,
    `pickpocket_loot_id`,
    `skinning_loot_id`,
    `holy_res`,
    `fire_res`,
    `nature_res`,
    `frost_res`,
    `shadow_res`,
    `arcane_res`,
    `spell_id1`,
    `spell_id2`,
    `spell_id3`,
    `spell_id4`,
    `spell_list_id`,
    `pet_spell_list_id`,
    `spawn_spell_id`,
    `auras`,
    `gold_min`,
    `gold_max`,
    `ai_name`,
    `movement_type`,
    `inhabit_type`,
    `civilian`,
    `racial_leader`,
    `regeneration`,
    `equipment_id`,
    `trainer_id`,
    `vendor_id`,
    `mechanic_immune_mask`,
    `school_immune_mask`,
    `immunity_flags`,
    `flags_extra`,
    `phase_quest_id`,
    `script_name`
)
VALUES
(62923, 18575, 0, 0, 0, 0, 'Elder Sage Azh''okar', 'Reagents', 62923, 58, 58, 4263, 4263, 0, 0, 1754, 160, 7, 1, 1.14286, 1, 18, 5, 30, 0, 1, 108.555725, 134.351151, 0, 242, 1, 2000, 2000, 1, 32768, 0, 0, 0, 0, 0, 0, 88.388618, 121.53434, 172, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, 0, 0, 'EventAI', 0, 3, 0, 0, 3, 62923, 0, 0, 0, 0, 0, 0, 0, '');

INSERT INTO `creature_questrelation`
(
    `id`,
    `quest`
)
VALUES
(62993, 41918),
(62923, 41919);

INSERT INTO `creature_involvedrelation`
(
    `id`,
    `quest`
)
VALUES
(62923, 41918),
(62923, 41919);

UPDATE `quest_template`
SET `SpecialFlags` = `SpecialFlags` | 1
WHERE `entry` = 41919;

INSERT INTO `npc_vendor`
(
    `entry`,
    `slot`,
    `item`,
    `maxcount`,
    `incrtime`,
    `itemflags`,
    `condition_id`
)
VALUES
(62923, 1, 17019, 0, 0, 0, 0),
(62923, 2, 17034, 0, 0, 0, 0),
(62923, 3, 17035, 0, 0, 0, 0),
(62923, 4, 17036, 0, 0, 0, 0),
(62923, 5, 17037, 0, 0, 0, 0),
(62923, 6, 17038, 0, 0, 0, 0),
(62923, 7, 17031, 0, 0, 0, 0),
(62923, 8, 17032, 0, 0, 0, 0),
(62923, 9, 17020, 0, 0, 0, 0),
(62923, 10, 17030, 0, 0, 0, 0),
(62923, 11, 17033, 0, 0, 0, 0),
(62923, 12, 17028, 0, 0, 0, 0),
(62923, 13, 17029, 0, 0, 0, 0),
(62923, 14, 17021, 0, 0, 0, 0),
(62923, 15, 17026, 0, 0, 0, 0),
(62923, 16, 5565, 0, 0, 0, 0),
(62923, 17, 16583, 0, 0, 0, 0),
(62923, 18, 21177, 0, 0, 0, 0);

-- ==============================================
-- FILE: expedition_gone_wrong.sql
-- GENERATED: 20260915075403
-- ==============================================
-- Expedition Gone Wrong (42068)

UPDATE `creature_template`
SET `gossip_menu_id` = 6311901
WHERE `entry` = 63119;

DELETE FROM `gossip_menu_option`
WHERE `menu_id` = 63119;

DELETE FROM `gossip_menu`
WHERE `entry` = 63119;

DELETE FROM `npc_text`
WHERE `ID` = 6311901;

DELETE FROM `broadcast_text`
WHERE `entry` IN (
    6311901, 6311902, 6311903
    );

INSERT INTO `broadcast_text`
(
    `entry`,
    `male_text`,
    `female_text`,
    `chat_type`,
    `sound_id`,
    `language_id`,
    `emote_id1`,
    `emote_id2`,
    `emote_id3`,
    `emote_delay1`,
    `emote_delay2`,
    `emote_delay3`
)
VALUES
(6311901, 'Truly a disaster, to be sent here by that fool of a cousin of mine. Of all the places one might be assigned, it had to be this - so distant, so very odd.$B$BThese lands are strange, yes, but do not mistake my displeasure for weakness. I did not come all this way to fail. Whatever trials await, I will endure them, and I will see my mission done..', 'Truly a disaster, to be sent here by that fool of a cousin of mine. Of all the places one might be assigned, it had to be this - so distant, so very odd.$B$BThese lands are strange, yes, but do not mistake my displeasure for weakness. I did not come all this way to fail. Whatever trials await, I will endure them, and I will see my mission done..', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6311902, 'Tell me your story, Andanil', 'Tell me your story, Andanil', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6311903, 'My venerable cousin, in what he no doubt considers unmatched wisdom, sent us to this forsaken place chasing draenethyst. Promises of abundance. Of answers. Of being remembered as saviors.$B$BYes, the crystals are impressive. Potent, refined, useful. They keep our people standing a little longer. They quiet the hunger. But that is all they do. Sustenance. Not salvation. I did not cross half the world to return to Alah’thalas carrying crates of arcane crystals.$B$BSo I pushed further. Against advice. Against caution. Against that quiet voice that suggests restraint.', 'My venerable cousin, in what he no doubt considers unmatched wisdom, sent us to this forsaken place chasing draenethyst. Promises of abundance. Of answers. Of being remembered as saviors.$B$BYes, the crystals are impressive. Potent, refined, useful. They keep our people standing a little longer. They quiet the hunger. But that is all they do. Sustenance. Not salvation. I did not cross half the world to return to Alah’thalas carrying crates of arcane crystals.$B$BSo I pushed further. Against advice. Against caution. Against that quiet voice that suggests restraint.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6311904, '<continue>', '<continue>', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6311905, 'North of here lies an old Barrow Den. Forgotten. Abandoned. Or so it appeared. The place bled magic. Not wild, not crude, but dense. Ancient. The sort that makes your skin prickle even before a spell is cast.$B$BMaelion took a sizeable force and went inside. Capable soldiers. Trained arcanists. People I trusted. Then we heard it. An explosion. Not sound alone. A pressure in the air, like the world itself flinched.$B$BWhen we reached the den, there was nothing left of them. Not truly. Their bodies remained, but the mana was gone. Drained clean. Empty shells, withered beyond recognition. Worse than the withered back home. Those at least remember who they were. These ones do not remember anything. Not their names. Not their purpose. Not even fear.', 'North of here lies an old Barrow Den. Forgotten. Abandoned. Or so it appeared. The place bled magic. Not wild, not crude, but dense. Ancient. The sort that makes your skin prickle even before a spell is cast.$B$BMaelion took a sizeable force and went inside. Capable soldiers. Trained arcanists. People I trusted. Then we heard it. An explosion. Not sound alone. A pressure in the air, like the world itself flinched.$B$BWhen we reached the den, there was nothing left of them. Not truly. Their bodies remained, but the mana was gone. Drained clean. Empty shells, withered beyond recognition. Worse than the withered back home. Those at least remember who they were. These ones do not remember anything. Not their names. Not their purpose. Not even fear.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6311906, '<continue>', '<continue>', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6311907, 'They did not leave the den. They still roam it. Searching. Or guarding. I cannot tell which is more unsettling.$B$BWhatever happened there involved power far beyond draenethyst. Power that can wither a mage in moments. And that is precisely why it matters. If something can do this, so completely and so quickly, then it stands to reason that it might do the opposite as well.$B$BYes, I know. Theory. Speculation. Desperation, if you prefer honesty. But desperation is where breakthroughs are born.$B$BI will not return to Alah’thalas empty handed. Not with excuses. Not with crystals anyone could have gathered. Whatever lies within that Barrow Den is the reason we are here. I can feel it.$B$BAnd I intend to claim it, whatever the cost.', 'They did not leave the den. They still roam it. Searching. Or guarding. I cannot tell which is more unsettling.$B$BWhatever happened there involved power far beyond draenethyst. Power that can wither a mage in moments. And that is precisely why it matters. If something can do this, so completely and so quickly, then it stands to reason that it might do the opposite as well.$B$BYes, I know. Theory. Speculation. Desperation, if you prefer honesty. But desperation is where breakthroughs are born.$B$BI will not return to Alah’thalas empty handed. Not with excuses. Not with crystals anyone could have gathered. Whatever lies within that Barrow Den is the reason we are here. I can feel it.$B$BAnd I intend to claim it, whatever the cost.', 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO `npc_text`
(
    `ID`,
    `BroadcastTextID0`,
    `Probability0`,
    `BroadcastTextID1`,
    `Probability1`,
    `BroadcastTextID2`,
    `Probability2`,
    `BroadcastTextID3`,
    `Probability3`,
    `BroadcastTextID4`,
    `Probability4`,
    `BroadcastTextID5`,
    `Probability5`,
    `BroadcastTextID6`,
    `Probability6`,
    `BroadcastTextID7`,
    `Probability7`
)
VALUES
(6311901, 6311901, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(6311903, 6311903, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(6311905, 6311905, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(6311907, 6311907, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0);

INSERT INTO `gossip_menu`
(
    `entry`,
    `text_id`,
    `script_id`,
    `condition_id`
)
VALUES
(6311901, 6311901, 0, 0),
(6311902, 6311903, 0, 0),
(6311903, 6311905, 0, 0),
(6311904, 6311907, 0, 0);

INSERT INTO `gossip_menu_option`
(
    `menu_id`,
    `id`,
    `option_icon`,
    `option_text`,
    `option_broadcast_text`,
    `option_id`,
    `npc_option_npcflag`,
    `action_menu_id`,
    `action_poi_id`,
    `action_script_id`,
    `box_coded`,
    `box_money`,
    `box_text`,
    `box_broadcast_text`,
    `condition_id`
)
VALUES
(6311901, 0, 0, 'Tell me your story, Andanil', 6311902, 1, 1, 6311902, 0, 0, 0, 0, '', 0, 0),
(6311902, 0, 0, '<continue>', 6311904, 1, 1, 6311903, 0, 0, 0, 0, '', 0, 0),
(6311903, 0, 0, '<continue>', 6311906, 1, 1, 6311904, 0, 6311906, 0, 0, '', 0, 0);

INSERT INTO `gossip_scripts`
(
    `id`,
    `delay`,
    `priority`,
    `command`,
    `datalong`,
    `datalong2`,
    `datalong3`,
    `datalong4`,
    `target_param1`,
    `target_param2`,
    `target_type`,
    `data_flags`,
    `dataint`,
    `dataint2`,
    `dataint3`,
    `dataint4`,
    `x`,
    `y`,
    `z`,
    `o`,
    `condition_id`,
    `comments`
)
VALUES
(6311906, 0, 0, 8, 60089, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Expedition Gone Wrong - Andanil Sunsworn story heard');

-- ==============================================
-- FILE: facing_the_elder.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `conditions`
(
    `condition_entry`,
    `type`,
    `value1`,
    `value2`,
    `value3`,
    `value4`,
    `flags`
)
VALUES
(42073, 9, 42073, 1, 0, 0, 0);

INSERT INTO `broadcast_text`
(
    `entry`,
    `male_text`,
    `female_text`,
    `chat_type`,
    `sound_id`,
    `language_id`,
    `emote_id1`,
    `emote_id2`,
    `emote_id3`,
    `emote_delay1`,
    `emote_delay2`,
    `emote_delay3`
)
VALUES
(2947902, 'Elder, we must speak.', 'Elder, we must speak.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947903, 'Must we? You have become rather familiar with both I and my tribe, hordeling. Do not mistake my patience for acceptance. Yours was a required aid, no matter how dreadful it was to take this decision. In truth we have forsaken our alliance with the Children of the Moon in favor of your barbaric allies.$B$BA decision I did not take lightly. And one I might end up regretting. I have seen you plot with those that’d see me dictatorial, somehow you have even tamed my son in your delusions.', 'Must we? You have become rather familiar with both I and my tribe, hordeling. Do not mistake my patience for acceptance. Yours was a required aid, no matter how dreadful it was to take this decision. In truth we have forsaken our alliance with the Children of the Moon in favor of your barbaric allies.$B$BA decision I did not take lightly. And one I might end up regretting. I have seen you plot with those that’d see me dictatorial, somehow you have even tamed my son in your delusions.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947904, 'Then perhaps your sight is growing dim.', 'Then perhaps your sight is growing dim.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947905, 'How bold. Your arrogance knows no end, you dare mock me in my own home? You have no idea how much our tribe has sacrificed to leave our hoofsteps on these plains. We were nomads before yet never without a home, for our home was the entire Kalimdor under the guise of the Earthmother and the light of both An’she and Mu’sha.$B$BAs testament to our connection to the Mother of Night, youngbloods of our tribe began to be born with a crescent moon under their hoof, treading marks upon this land its mud and everything there was, is and will be with our bond. How could you even begin to understand? My people were chosen.', 'How bold. Your arrogance knows no end, you dare mock me in my own home? You have no idea how much our tribe has sacrificed to leave our hoofsteps on these plains. We were nomads before yet never without a home, for our home was the entire Kalimdor under the guise of the Earthmother and the light of both An’she and Mu’sha.$B$BAs testament to our connection to the Mother of Night, youngbloods of our tribe began to be born with a crescent moon under their hoof, treading marks upon this land its mud and everything there was, is and will be with our bond. How could you even begin to understand? My people were chosen.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947906, 'By An’she and Mu’sha, yet what of Lo’sho?', 'By An’she and Mu’sha, yet what of Lo’sho?', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947907, 'Do not attempt to quote our culture to me, hordeling. You can’t even try to understand our connections to the Celestial Siblings. As of Lo’sho. A rebellious child, one that speaks to you, some of my tribesmen and even my son. Is it he who sold you this information?', 'Do not attempt to quote our culture to me, hordeling. You can’t even try to understand our connections to the Celestial Siblings. As of Lo’sho. A rebellious child, one that speaks to you, some of my tribesmen and even my son. Is it he who sold you this information?', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947908, 'So to follow Lo’sho is to be granted death by the Moonhoofs.', 'So to follow Lo’sho is to be granted death by the Moonhoofs.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947909, 'Ah, you blame me. For something you did. Indeed I set you on the path to slay the Shade Mother and her minions. Indeed they were followers of Lo’sho, but they were just pawns in a much grander scheme. And after you so eagerly shed blood for me, I found out what his true intentions were.', 'Ah, you blame me. For something you did. Indeed I set you on the path to slay the Shade Mother and her minions. Indeed they were followers of Lo’sho, but they were just pawns in a much grander scheme. And after you so eagerly shed blood for me, I found out what his true intentions were.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947910, 'Speak then. Seek my aid once more.', 'Speak then. Seek my aid once more.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947911, 'Arrogant whelp. Yet you have proven yourself time and time again. All right.$BBefore the Riverhorn Village was burnt to ash by the Draenei, the Grove of the Moon was led by Archdruid Mothshroud and his apprentice Ireth Moondancer. That grove, much like the Grove the Sun on the isle of Tyrandas, was a place of study and friendship between us and the night elves. Mothshroud was a benevolent and kind leader, and a friend to me. He would worship both moons side by side in this grove, both Mu’sha and the youngest, Lo’sho.', 'Arrogant whelp. Yet you have proven yourself time and time again. All right.$BBefore the Riverhorn Village was burnt to ash by the Draenei, the Grove of the Moon was led by Archdruid Mothshroud and his apprentice Ireth Moondancer. That grove, much like the Grove the Sun on the isle of Tyrandas, was a place of study and friendship between us and the night elves. Mothshroud was a benevolent and kind leader, and a friend to me. He would worship both moons side by side in this grove, both Mu’sha and the youngest, Lo’sho.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947912, 'Go on.', 'Go on.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947913, 'In that time of peace Mothshroud spoke of Lo’sho as a symbol of hope, born out of hardship and suffering. You should know, Lo’sho is the tear of Mu’sha, and he was born when the Earthmother felt such sorrow that through Mu’sha she wept for us. I did not see it coming, truly. Not the attack on Riverhorn, nor my friend’s spiral into anger and loss of his own mind.$B$BOnce Riverhorn turned to ash I did not seek to take vengeance on the Draenei. I thought about the flow of nature and prayed to my patron. And when I received signs that He too was of the same mind, I refused to allow those who felt a thirst for blood to sate it.', 'In that time of peace Mothshroud spoke of Lo’sho as a symbol of hope, born out of hardship and suffering. You should know, Lo’sho is the tear of Mu’sha, and he was born when the Earthmother felt such sorrow that through Mu’sha she wept for us. I did not see it coming, truly. Not the attack on Riverhorn, nor my friend’s spiral into anger and loss of his own mind.$B$BOnce Riverhorn turned to ash I did not seek to take vengeance on the Draenei. I thought about the flow of nature and prayed to my patron. And when I received signs that He too was of the same mind, I refused to allow those who felt a thirst for blood to sate it.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947914, 'Continue.', 'Continue.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947915, 'Mothshroud had lost his spark. What makes man lose all that he valued in the blink of an eye? The death of a lover, a parent, a sibling, a child? Who knows which was the last straw. He had lost it all. Once he knew of my stance, he grew distant and bitter. I do not blame him for that, but for what he did afterwards.', 'Mothshroud had lost his spark. What makes man lose all that he valued in the blink of an eye? The death of a lover, a parent, a sibling, a child? Who knows which was the last straw. He had lost it all. Once he knew of my stance, he grew distant and bitter. I do not blame him for that, but for what he did afterwards.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947916, 'What was it?', 'What was it?', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947917, 'He took the survivors of Riverhorn and others who were willing and told them to foster a new name, the Shadewalkers. And he named a common and valued friend of ours as their leader. They were meant to summon our ancestors and use them as means of vengeance.$B$BAfter, he returned to the Grove of the Moon. An ultimatum was made, the Druids there would abandon Mu’sha and swear fealty to Lo’sho, to a Lo’sho that would not turn a blind eye to their need of vengeance. He named the night elves Druids of the Moth while the tauren Disciples of Lo’sho.', 'He took the survivors of Riverhorn and others who were willing and told them to foster a new name, the Shadewalkers. And he named a common and valued friend of ours as their leader. They were meant to summon our ancestors and use them as means of vengeance.$B$BAfter, he returned to the Grove of the Moon. An ultimatum was made, the Druids there would abandon Mu’sha and swear fealty to Lo’sho, to a Lo’sho that would not turn a blind eye to their need of vengeance. He named the night elves Druids of the Moth while the tauren Disciples of Lo’sho.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947918, 'Go on.', 'Go on.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947919, 'Mothshroud had lost his spark. What makes man lose all that he valued in the blink of an eye? The death of a lover, a parent, a sibling, a child? Who knows which was the last straw. He had lost it all.$B$BOnce he knew of my stance, he grew distant and bitter. I do not blame him for that.$B$BI do blame him for what he did. He took the survivors of Riverhorn and others who were willing and told them to foster a new name, the Shadewalkers you have dealt with before. And he named a common and valued friend of ours as their leader. They were meant to summon our ancestors and use them as means of vengeance.$B$BAfter, he returned to the Grove of the Moon. An ultimatum was made, the Druids there would abandon Mu’sha and swear fealty to Lo’sho, to a Lo’sho that would not turn a blind eye to their need of vengeance. He named the night elves Druids of the Moth while the tauren Disciples of Lo’sho.', 'Mothshroud had lost his spark. What makes man lose all that he valued in the blink of an eye? The death of a lover, a parent, a sibling, a child? Who knows which was the last straw. He had lost it all.$B$BOnce he knew of my stance, he grew distant and bitter. I do not blame him for that.$B$BI do blame him for what he did. He took the survivors of Riverhorn and others who were willing and told them to foster a new name, the Shadewalkers you have dealt with before. And he named a common and valued friend of ours as their leader. They were meant to summon our ancestors and use them as means of vengeance.$B$BAfter, he returned to the Grove of the Moon. An ultimatum was made, the Druids there would abandon Mu’sha and swear fealty to Lo’sho, to a Lo’sho that would not turn a blind eye to their need of vengeance. He named the night elves Druids of the Moth while the tauren Disciples of Lo’sho.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947920, 'It can’t end there.', 'It can’t end there.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947921, 'It does not. The Druids of the grove that didn’t willingly commit to his rule were forced into it. Mothshroud fell for the words of a satyr, one who claimed was, like him, a follower of Lo’sho. And so with the aid of the satyr you have found in the depths of the Barrows, he bent the minds of those that were unwilling to follow.$B$BAnd so he left, with his agents ready to brew chaos that would keep us unfocused. His hoofsteps were last seen in the ruins of Maras’ethil, seeking an artifact he had heard of from the satyr. Whether his task was a succes or not, it is something that you must find out.', 'It does not. The Druids of the grove that didn’t willingly commit to his rule were forced into it. Mothshroud fell for the words of a satyr, one who claimed was, like him, a follower of Lo’sho. And so with the aid of the satyr you have found in the depths of the Barrows, he bent the minds of those that were unwilling to follow.$B$BAnd so he left, with his agents ready to brew chaos that would keep us unfocused. His hoofsteps were last seen in the ruins of Maras’ethil, seeking an artifact he had heard of from the satyr. Whether his task was a succes or not, it is something that you must find out.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947922, 'This barely changes what you did.', 'This barely changes what you did.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947923, 'To think you so judgemental, as if you are in any position to question me. Alas, I could not care less about your feelings on the matter. I hid from responsibility in the face of death, my choice led to a brewing hatred. And ever since I have tried to dismantle that hatred by making it go away. At the end of the day, what do I have?$B$BA conscience burdened that I had another spill blood for me and the displeasement I feel from my tribe, from my own family. I know what I did, hordeling. I know what happens after this all ends. I know how I must pay.', 'To think you so judgemental, as if you are in any position to question me. Alas, I could not care less about your feelings on the matter. I hid from responsibility in the face of death, my choice led to a brewing hatred. And ever since I have tried to dismantle that hatred by making it go away. At the end of the day, what do I have?$B$BA conscience burdened that I had another spill blood for me and the displeasement I feel from my tribe, from my own family. I know what I did, hordeling. I know what happens after this all ends. I know how I must pay.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947924, 'And how will you be paying, Elder?', 'And how will you be paying, Elder?', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947925, 'With my own death.', 'With my own death.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947926, 'We will see if that is for you to decide.', 'We will see if that is for you to decide.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(2947927, 'I have told you all I know, and the future has yet to happen. You asked me to seek your aid, and now I am.', 'I have told you all I know, and the future has yet to happen. You asked me to seek your aid, and now I am.', 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO `npc_text`
(
    `ID`,
    `BroadcastTextID0`,
    `Probability0`,
    `BroadcastTextID1`,
    `Probability1`,
    `BroadcastTextID2`,
    `Probability2`,
    `BroadcastTextID3`,
    `Probability3`,
    `BroadcastTextID4`,
    `Probability4`,
    `BroadcastTextID5`,
    `Probability5`,
    `BroadcastTextID6`,
    `Probability6`,
    `BroadcastTextID7`,
    `Probability7`
)
VALUES
(2947903, 2947903, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(2947905, 2947905, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(2947907, 2947907, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(2947909, 2947909, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(2947911, 2947911, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(2947913, 2947913, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(2947915, 2947915, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(2947917, 2947917, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(2947919, 2947919, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(2947921, 2947921, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(2947923, 2947923, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(2947925, 2947925, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(2947927, 2947927, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0);

INSERT INTO `gossip_menu`
(
    `entry`,
    `text_id`,
    `script_id`,
    `condition_id`
)
VALUES
(2947902, 2947903, 0, 0),
(2947903, 2947905, 0, 0),
(2947904, 2947907, 0, 0),
(2947905, 2947909, 0, 0),
(2947906, 2947911, 0, 0),
(2947907, 2947913, 0, 0),
(2947908, 2947915, 0, 0),
(2947909, 2947917, 0, 0),
(2947910, 2947919, 0, 0),
(2947911, 2947921, 0, 0),
(2947912, 2947923, 0, 0),
(2947913, 2947925, 0, 0),
(2947914, 2947927, 0, 0);

INSERT INTO `gossip_menu_option`
(
    `menu_id`,
    `id`,
    `option_icon`,
    `option_text`,
    `option_broadcast_text`,
    `option_id`,
    `npc_option_npcflag`,
    `action_menu_id`,
    `action_poi_id`,
    `action_script_id`,
    `box_coded`,
    `box_money`,
    `box_text`,
    `box_broadcast_text`,
    `condition_id`
)
VALUES
(29479, 0, 0, 'Elder, we must speak.', 2947902, 1, 1, 2947902, 0, 0, 0, 0, '', 0, 42073),
(2947902, 0, 0, 'Then perhaps your sight is growing dim.', 2947904, 1, 1, 2947903, 0, 0, 0, 0, '', 0, 0),
(2947903, 0, 0, 'By An’she and Mu’sha, yet what of Lo’sho?', 2947906, 1, 1, 2947904, 0, 0, 0, 0, '', 0, 0),
(2947904, 0, 0, 'So to follow Lo’sho is to be granted death by the Moonhoofs.', 2947908, 1, 1, 2947905, 0, 0, 0, 0, '', 0, 0),
(2947905, 0, 0, 'Speak then. Seek my aid once more.', 2947910, 1, 1, 2947906, 0, 0, 0, 0, '', 0, 0),
(2947906, 0, 0, 'Go on.', 2947912, 1, 1, 2947907, 0, 0, 0, 0, '', 0, 0),
(2947907, 0, 0, 'Continue.', 2947914, 1, 1, 2947908, 0, 0, 0, 0, '', 0, 0),
(2947908, 0, 0, 'What was it?', 2947916, 1, 1, 2947909, 0, 0, 0, 0, '', 0, 0),
(2947909, 0, 0, 'Go on.', 2947918, 1, 1, 2947910, 0, 0, 0, 0, '', 0, 0),
(2947910, 0, 0, 'It can’t end there.', 2947920, 1, 1, 2947911, 0, 0, 0, 0, '', 0, 0),
(2947911, 0, 0, 'This barely changes what you did.', 2947922, 1, 1, 2947912, 0, 0, 0, 0, '', 0, 0),
(2947912, 0, 0, 'And how will you be paying, Elder?', 2947924, 1, 1, 2947913, 0, 0, 0, 0, '', 0, 0),
(2947913, 0, 0, 'We will see if that is for you to decide.', 2947926, 1, 1, 2947914, 0, 2947926, 0, 0, '', 0, 0);

INSERT INTO `gossip_scripts`
(
    `id`,
    `delay`,
    `priority`,
    `command`,
    `datalong`,
    `datalong2`,
    `datalong3`,
    `datalong4`,
    `target_param1`,
    `target_param2`,
    `target_type`,
    `data_flags`,
    `dataint`,
    `dataint2`,
    `dataint3`,
    `dataint4`,
    `x`,
    `y`,
    `z`,
    `o`,
    `condition_id`,
    `comments`
)
VALUES
(2947926, 0, 0, 8, 60090, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42073, 'Facing the Elder - Elder Moonhoof listened');

-- ==============================================
-- FILE: farmer_denphar_quests.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `creature_questrelation`
(
    `id`,
    `quest`
)
VALUES
(62922, 41946);

INSERT INTO `creature_involvedrelation`
(
    `id`,
    `quest`
)
VALUES
(62922, 41946);

-- ==============================================
-- FILE: farm_raiders.sql
-- GENERATED: 20260915075403
-- ==============================================
UPDATE `quest_template`
SET `StartScript` = 41946
WHERE `entry` = 41946;

INSERT INTO `creature_template`
(
    `entry`,
    `display_id1`,
    `display_id2`,
    `display_id3`,
    `display_id4`,
    `mount_display_id`,
    `name`,
    `subname`,
    `gossip_menu_id`,
    `level_min`,
    `level_max`,
    `health_min`,
    `health_max`,
    `mana_min`,
    `mana_max`,
    `armor`,
    `faction`,
    `npc_flags`,
    `speed_walk`,
    `speed_run`,
    `scale`,
    `detection_range`,
    `call_for_help_range`,
    `leash_range`,
    `rank`,
    `xp_multiplier`,
    `dmg_min`,
    `dmg_max`,
    `dmg_school`,
    `attack_power`,
    `dmg_multiplier`,
    `base_attack_time`,
    `ranged_attack_time`,
    `unit_class`,
    `unit_flags`,
    `dynamic_flags`,
    `beast_family`,
    `trainer_type`,
    `trainer_spell`,
    `trainer_class`,
    `trainer_race`,
    `ranged_dmg_min`,
    `ranged_dmg_max`,
    `ranged_attack_power`,
    `type`,
    `type_flags`,
    `loot_id`,
    `pickpocket_loot_id`,
    `skinning_loot_id`,
    `holy_res`,
    `fire_res`,
    `nature_res`,
    `frost_res`,
    `shadow_res`,
    `arcane_res`,
    `spell_id1`,
    `spell_id2`,
    `spell_id3`,
    `spell_id4`,
    `spell_list_id`,
    `pet_spell_list_id`,
    `spawn_spell_id`,
    `auras`,
    `gold_min`,
    `gold_max`,
    `ai_name`,
    `movement_type`,
    `inhabit_type`,
    `civilian`,
    `racial_leader`,
    `regeneration`,
    `equipment_id`,
    `trainer_id`,
    `vendor_id`,
    `mechanic_immune_mask`,
    `school_immune_mask`,
    `immunity_flags`,
    `flags_extra`,
    `phase_quest_id`,
    `script_name`
)
VALUES
(63089, 20685, 0, 0, 0, 0, 'Ghin''taru', '', 0, 53, 53, 3507, 3507, 0, 0, 3136, 51, 0, 1, 1.14286, 1.399999976158142, 18, 5, 40, 0, 1, 261.243683, 364.571442, 0, 218, 1, 2000, 2000, 1, 32768, 12, 0, 0, 0, 0, 0, 80.209602, 110.2882, 154, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, 0, 0, 'EventAI', 0, 3, 0, 0, 3, 63089, 0, 0, 0, 0, 0, 0, 0, '');

INSERT INTO `creature_equip_template`
(
    `entry`,
    `equipentry1`,
    `equipentry2`,
    `equipentry3`
)
VALUES
(63089, 12983, 0, 0);

INSERT INTO `broadcast_text`
(
    `entry`,
    `male_text`,
    `female_text`,
    `chat_type`,
    `sound_id`,
    `language_id`,
    `emote_id1`,
    `emote_id2`,
    `emote_id3`,
    `emote_delay1`,
    `emote_delay2`,
    `emote_delay3`
)
VALUES
(6292202, 'They''re coming!', 'They''re coming!', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6292203, 'Another group, brace yourself!', 'Another group, brace yourself!', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6292204, 'Look at that brute! This must be their leader!', 'Look at that brute! This must be their leader!', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6292205, 'We did it! Parash''ka, you are my savior!', 'We did it! Parash''ka, you are my savior!', 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO `quest_start_scripts`
(
    `id`,
    `delay`,
    `priority`,
    `command`,
    `datalong`,
    `datalong2`,
    `datalong3`,
    `datalong4`,
    `target_param1`,
    `target_param2`,
    `target_type`,
    `data_flags`,
    `dataint`,
    `dataint2`,
    `dataint3`,
    `dataint4`,
    `x`,
    `y`,
    `z`,
    `o`,
    `condition_id`,
    `comments`
)
VALUES
(41946, 0, 0, 4, 147, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Farm Raiders - Farmer Denphar Becomes Uninteractible'),
(41946, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6292202, 0, 0, 0, 0, 0, 0, 0, 0, 'Farm Raiders - Farmer Denphar Say 1'),
(41946, 0, 2, 10, 63082, 180000, 0, 0, 0, 0, 0, 0, 2, 0, 6, 10, 6515.681641, -6431.706055, 29.636063, 0.8989319801330566, 0, 'Farm Raiders - Wave 1 Fallen One Raider 1'),
(41946, 0, 3, 10, 63082, 180000, 0, 0, 0, 0, 0, 0, 2, 0, 6, 10, 6511.609863, -6427.594238, 29.776131, 0.7457789778709412, 0, 'Farm Raiders - Wave 1 Fallen One Raider 2'),
(41946, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6292203, 0, 0, 0, 0, 0, 0, 0, 0, 'Farm Raiders - Farmer Denphar Say 2'),
(41946, 60, 1, 10, 63082, 180000, 0, 0, 0, 0, 0, 0, 2, 0, 6, 10, 6515.681641, -6431.706055, 29.636063, 0.8989319801330566, 0, 'Farm Raiders - Wave 2 Fallen One Raider 1'),
(41946, 60, 2, 10, 63082, 180000, 0, 0, 0, 0, 0, 0, 2, 0, 6, 10, 6511.609863, -6427.594238, 29.776131, 0.7457789778709412, 0, 'Farm Raiders - Wave 2 Fallen One Raider 2'),
(41946, 60, 3, 10, 63082, 180000, 0, 0, 0, 0, 0, 0, 2, 0, 6, 10, 6516.873047, -6426.465332, 29.302973, 0.8596619963645935, 0, 'Farm Raiders - Wave 2 Fallen One Raider 3'),
(41946, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6292204, 0, 0, 0, 0, 0, 0, 0, 0, 'Farm Raiders - Farmer Denphar Say 3'),
(41946, 120, 1, 10, 63082, 180000, 0, 0, 0, 0, 0, 0, 2, 0, 6, 10, 6515.681641, -6431.706055, 29.636063, 0.8989319801330566, 0, 'Farm Raiders - Wave 3 Fallen One Raider 1'),
(41946, 120, 2, 10, 63082, 180000, 0, 0, 0, 0, 0, 0, 2, 0, 6, 10, 6511.609863, -6427.594238, 29.776131, 0.7457789778709412, 0, 'Farm Raiders - Wave 3 Fallen One Raider 2'),
(41946, 120, 3, 10, 63089, 180000, 0, 0, 0, 0, 0, 0, 2, 0, 6, 10, 6516.873047, -6426.465332, 29.302973, 0.8596619963645935, 0, 'Farm Raiders - Wave 3 Ghin''taru');

INSERT INTO `creature_ai_events`
(
    `id`,
    `creature_id`,
    `condition_id`,
    `event_type`,
    `event_inverse_phase_mask`,
    `event_chance`,
    `event_flags`,
    `event_param1`,
    `event_param2`,
    `event_param3`,
    `event_param4`,
    `action1_script`,
    `action2_script`,
    `action3_script`,
    `comment`
)
VALUES
(6308901, 63089, 0, 6, 0, 100, 0, 0, 0, 0, 0, 6308901, 0, 0, 'Farm Raiders - Ghin''taru Dies');

INSERT INTO `creature_ai_scripts`
(
    `id`,
    `delay`,
    `priority`,
    `command`,
    `datalong`,
    `datalong2`,
    `datalong3`,
    `datalong4`,
    `target_param1`,
    `target_param2`,
    `target_type`,
    `data_flags`,
    `dataint`,
    `dataint2`,
    `dataint3`,
    `dataint4`,
    `x`,
    `y`,
    `z`,
    `o`,
    `condition_id`,
    `comments`
)
VALUES
(6308901, 0, 0, 0, 0, 0, 0, 0, 62922, 100, 8, 2, 6292205, 0, 0, 0, 0, 0, 0, 0, 0, 'Farm Raiders - Farmer Denphar Victory Say'),
(6308901, 0, 1, 4, 147, 3, 1, 0, 62922, 100, 8, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Farm Raiders - Farmer Denphar Becomes Interactible');

-- ==============================================
-- FILE: fena_madar_quests.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `creature_questrelation`
(
    `id`,
    `quest`
)
VALUES
(62852, 41945);

INSERT INTO `creature_involvedrelation`
(
    `id`,
    `quest`
)
VALUES
(62852, 41945);

-- ==============================================
-- FILE: hamaam_quests.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `creature_questrelation`
(
    `id`,
    `quest`
)
VALUES
(63047, 41949);

INSERT INTO `creature_involvedrelation`
(
    `id`,
    `quest`
)
VALUES
(63047, 41947),
(63047, 41948),
(63047, 41949);

-- ==============================================
-- FILE: helhala_quests.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `creature_questrelation`
(
    `id`,
    `quest`
)
VALUES
(62851, 41908),
(62851, 41909);

INSERT INTO `creature_involvedrelation`
(
    `id`,
    `quest`
)
VALUES
(62851, 41908),
(62851, 41909),
(62851, 42012);

UPDATE `quest_template`
SET `SpecialFlags` = `SpecialFlags` | 1
WHERE `entry` IN (41908, 41909);

-- ==============================================
-- FILE: homecoming.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `creature_involvedrelation`
(
    `id`,
    `quest`
)
VALUES
(91781, 41922);

-- ==============================================
-- FILE: huntmaster_fan_dhera_quests.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `creature_questrelation`
(
    `id`,
    `quest`
)
VALUES
(63046, 41944);

-- ==============================================
-- FILE: maghan_quests.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `creature_questrelation`
(
    `id`,
    `quest`
)
VALUES
(62994, 41920),
(62994, 41952);

INSERT INTO `creature_involvedrelation`
(
    `id`,
    `quest`
)
VALUES
(62994, 41951);

-- ==============================================
-- FILE: missing_gossips.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `broadcast_text`
(
    `entry`,
    `male_text`,
    `female_text`,
    `chat_type`,
    `sound_id`,
    `language_id`,
    `emote_id1`,
    `emote_id2`,
    `emote_id3`,
    `emote_delay1`,
    `emote_delay2`,
    `emote_delay3`
)
VALUES
(62994, 'These brutes are everywhere. I really wish the chieftain would finally do something about it.', 'These brutes are everywhere. I really wish the chieftain would finally do something about it.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6305701, 'Alert: Challenger approaches.$B$BProcessing.$B$BTarget has been acknowledged as harmless. Proceed.', 'Alert: Challenger approaches.$B$BProcessing.$B$BTarget has been acknowledged as harmless. Proceed.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6306001, 'I have travelled all the way from Sparkwater Port to offer my help to this tribe, and yet they refused to allow me entry into their village. Thankfully, this elder allowed me to rest in his hut. Perhaps he took pity on me, since he too feels like an outsider among them.', 'I have travelled all the way from Sparkwater Port to offer my help to this tribe, and yet they refused to allow me entry into their village. Thankfully, this elder allowed me to rest in his hut. Perhaps he took pity on me, since he too feels like an outsider among them.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6305901, 'Another outsider. Come, rest under my roof. I hope you do not mind company. This goblin and his odd companion were refused entry, and so they too were in need of rest.', 'Another outsider. Come, rest under my roof. I hope you do not mind company. This goblin and his odd companion were refused entry, and so they too were in need of rest.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6284001, 'Such beauty can be found in this land, but also danger. You must keep your wits about you these days, even when traveling the roads.', 'Such beauty can be found in this land, but also danger. You must keep your wits about you these days, even when traveling the roads.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6284601, 'It has been a while since we have seen outsiders venture into Moonwhisper Coast. What brings you to these lands?', 'It has been a while since we have seen outsiders venture into Moonwhisper Coast. What brings you to these lands?', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6319801, 'Lok''tar. A fine day to spill dragon blood, is it not? You seem uncertain and un eager. Fret not. While I am of the Dragonmaw, I fly my colors with the Horde, under the Scalereaver Warband. Mischief and mayhem may seem to live at our core, but I tell you, wanderer, we are those who raise arms against the stronger inhabitants of Azeroth when the time for action comes.', 'Lok''tar. A fine day to spill dragon blood, is it not? You seem uncertain and un eager. Fret not. While I am of the Dragonmaw, I fly my colors with the Horde, under the Scalereaver Warband. Mischief and mayhem may seem to live at our core, but I tell you, wanderer, we are those who raise arms against the stronger inhabitants of Azeroth when the time for action comes.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6298401, 'I can still smell the smoke emanating from Riverhorn Village. It clings to the air, reminding me of that terrible tragedy.', 'I can still smell the smoke emanating from Riverhorn Village. It clings to the air, reminding me of that terrible tragedy.', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6290201, 'An unexpected visitor. I have not much to offer, but please, let me be as hospitable as I can be. My name is Zarazar Sagewind, from the esteemed capital of magic Dalaran. I know that title may be far-fetched, but our architects are making good strides in restoring our great city to its former glory.$B$BThulio and I journeyed to this coast alongside the Sentinel expedition. Regrettably, they are a bit apprehensive when it comes to those mastering the arcane practices. While they allowed me to accompany them here, they forbade me from resting with them in their base camp. A bit shortsighted, if you ask me, but I am more than capable of fending more myself.$B$BNow then, how may I assist you?','An unexpected visitor. I have not much to offer, but please, let me be as hospitable as I can be. My name is Zarazar Sagewind, from the esteemed capital of magic Dalaran. I know that title may be far-fetched, but our architects are making good strides in restoring our great city to its former glory.$B$BThulio and I journeyed to this coast alongside the Sentinel expedition. Regrettably, they are a bit apprehensive when it comes to those mastering the arcane practices. While they allowed me to accompany them here, they forbade me from resting with them in their base camp. A bit shortsighted, if you ask me, but I am more than capable of fending more myself.$B$BNow then, how may I assist you?', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6316301, 'Our ancestors have been disturbed. The grounds are no longer a safe place to mourn those who have left us behind.', 'Our ancestors have been disturbed. The grounds are no longer a safe place to mourn those who have left us behind.', 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO `gossip_menu`
(
    `entry`,
    `text_id`,
    `script_id`,
    `condition_id`
)
VALUES
(63057, 6305701, 0, 0),
(63059, 6305901, 0, 0),
(63060, 6306001, 0, 0),
(62840, 6284001, 0, 0),
(62846, 6284601, 0, 0),
(63163, 6316301, 0, 0),
(62984, 6298401, 0, 0),
(62902, 6290201, 0, 0),
(63198, 6319801, 0, 0);

INSERT INTO `npc_text`
(
    `ID`,
    `BroadcastTextID0`,
    `Probability0`,
    `BroadcastTextID1`,
    `Probability1`,
    `BroadcastTextID2`,
    `Probability2`,
    `BroadcastTextID3`,
    `Probability3`,
    `BroadcastTextID4`,
    `Probability4`,
    `BroadcastTextID5`,
    `Probability5`,
    `BroadcastTextID6`,
    `Probability6`,
    `BroadcastTextID7`,
    `Probability7`
)
VALUES
(62994, 62994, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(6305701, 6305701, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(6305901, 6305901, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(6306001, 6306001, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(6284001, 6284001, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(6284601, 6284601, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(6316301, 6316301, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(6298401, 6298401, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(6290201, 6290201, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(6319801, 6319801, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0);

UPDATE `creature_template`
SET `gossip_menu_id` = `entry`
WHERE `entry` IN (
    63057, 63059, 63060, 62840, 62846, 63163, 63198, 62984, 62902
    );

-- ==============================================
-- FILE: morogai_kla_quests.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `creature_questrelation`
(
    `id`,
    `quest`
)
VALUES
(62850, 41917),
(62850, 41910),
(62850, 41916);

INSERT INTO `creature_involvedrelation`
(
    `id`,
    `quest`
)
VALUES
(62850, 41915),
(62850, 41916);

-- ==============================================
-- FILE: pli_quests.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `creature_involvedrelation`
(
    `id`,
    `quest`
)
VALUES
(62854, 41920);

-- ==============================================
-- FILE: powerless_runestones.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `gameobject`
(
    `guid`,
    `id`,
    `map`,
    `position_x`,
    `position_y`,
    `position_z`,
    `orientation`,
    `rotation0`,
    `rotation1`,
    `rotation2`,
    `rotation3`,
    `spawntimesecsmin`,
    `spawntimesecsmax`,
    `animprogress`,
    `state`,
    `spawn_flags`,
    `visibility_mod`
)
VALUES
(5030836, 2020334, 1, 5719.1298828125, -4828.60986328125, 776.9110107421875, 4.389999866485596, 0, 0, 0.81142883, -0.584451242, 300, 300, 100, 1, 0, 0),
(5030837, 2020334, 1, 5689.93994140625, -4889.1298828125, 798.2659912109375, 3.5213499069213867, 0, 0, 0.98202715, -0.188739704, 300, 300, 100, 1, 0, 0),
(5030838, 2020334, 1, 5708.72021484375, -4943.4501953125, 803.6099853515625, 5.0395097732543945, 0, 0, 0.582529897, -0.812809276, 300, 300, 100, 1, 0, 0),
(5030839, 2020334, 1, 5673.68994140625, -5012.5498046875, 807.1309814453125, 4.206200122833252, 0, 0, 0.861640167, -0.507519676, 300, 300, 100, 1, 0, 0),
(5030840, 2020334, 1, 5664.759765625, -4968.830078125, 806.7069702148438, 1.797379970550537, 0, 0, 0.78251192, 0.622635604, 300, 300, 100, 1, 0, 0),
(5030841, 2020334, 1, 5591.5400390625, -4947.93017578125, 823.2670288085938, 4.064620018005371, 0, 0, 0.895379475, -0.445303937, 300, 300, 100, 1, 0, 0),
(5030842, 2020334, 1, 5536.93017578125, -4977.60009765625, 844.6069946289062, 0.9842849969863892, 0, 0, 0.472515203, 0.881322519, 300, 300, 100, 1, 0, 0),
(5030843, 2020334, 1, 5496.35009765625, -4945.08984375, 849.8359985351562, 2.8303399085998535, 0, 0, 0.987914638, 0.154998932, 300, 300, 100, 1, 0, 0),
(5030844, 2020334, 1, 5570.18017578125, -4883.3798828125, 847.9349975585938, 0.17647600173950195, 0, 0, 0.0881235427, 0.996109553, 300, 300, 100, 1, 0, 0),
(5030845, 2020334, 1, 5478.85986328125, -4926.08984375, 862.9130249023438, 5.825850009918213, 0, 0, 0.226680056, -0.973969277, 300, 300, 100, 1, 0, 0),
(5030846, 2020334, 1, 5721.31982421875, -4993.18017578125, 808.2100219726562, 5.586289882659912, 0, 0, 0.341439218, -0.939903857, 300, 300, 100, 1, 0, 0);

UPDATE `gameobject_template`
SET `flags` = 4,
    `size` = 1.4
WHERE `entry` = 2020334;


-- ==============================================
-- FILE: riftmaster_ralpekta_quests.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `creature_questrelation`
(
    `id`,
    `quest`
)
VALUES
(62920, 41913),
(62920, 41953),
(62920, 41914),
(62920, 41951);

INSERT INTO `creature_involvedrelation`
(
    `id`,
    `quest`
)
VALUES
(62920, 41912),
(62920, 41913),
(62920, 41953),
(62920, 41952),
(62920, 41950);

-- ==============================================
-- FILE: the_missing_caravans.sql
-- GENERATED: 20260915075403
-- ==============================================
-- The Missing Caravans (41970)

INSERT INTO `scripted_areatrigger` (`entry`, `script_name`) VALUES
(5660, 'at_moonwhisper_missing_caravans'),
(5661, 'at_moonwhisper_missing_caravans');

-- ==============================================
-- FILE: uztuk_quests.sql
-- GENERATED: 20260915075403
-- ==============================================
INSERT INTO `creature_questrelation`
(
    `id`,
    `quest`
)
VALUES
(62980, 42049),
(62980, 42001);

INSERT INTO `creature_involvedrelation`
(
    `id`,
    `quest`
)
VALUES
(62980, 42050),
(62980, 42001);

-- ==============================================
-- FILE: wolf_in_sheeps_clothing.sql
-- GENERATED: 20260915075403
-- ==============================================
UPDATE `creature_template`
SET `gossip_menu_id` = 6298701
WHERE `entry` = 62987;

INSERT INTO `conditions`
(
    `condition_entry`,
    `type`,
    `value1`,
    `value2`,
    `value3`,
    `value4`,
    `flags`
)
VALUES
(41911, 9, 41911, 1, 0, 0, 0);

UPDATE `broadcast_text`
SET `male_text` = '<The draenei has been beaten and lies motionless on the ground.>',
    `female_text` = '<The draenei has been beaten and lies motionless on the ground.>',
    `chat_type` = 0,
    `sound_id` = 0,
    `language_id` = 0,
    `emote_id1` = 0,
    `emote_id2` = 0,
    `emote_id3` = 0,
    `emote_delay1` = 0,
    `emote_delay2` = 0,
    `emote_delay3` = 0
WHERE `entry` = 6298701;

INSERT INTO `broadcast_text`
(
    `entry`,
    `male_text`,
    `female_text`,
    `chat_type`,
    `sound_id`,
    `language_id`,
    `emote_id1`,
    `emote_id2`,
    `emote_id3`,
    `emote_delay1`,
    `emote_delay2`,
    `emote_delay3`
)
VALUES
(6298702, '<Inspect the hunter''s body>', '<Inspect the hunter''s body>', 0, 0, 0, 0, 0, 0, 0, 0, 0),
(6298703, '<Countless lesions and cuts are strewn about the draenei''s body. His left arm is contorted into an unnatural shape. You can''t discern whether the red trails under his eyes were caused by tears or blood. He fought to the very end.>', '<Countless lesions and cuts are strewn about the draenei''s body. His left arm is contorted into an unnatural shape. You can''t discern whether the red trails under his eyes were caused by tears or blood. He fought to the very end.>', 0, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO `npc_text`
(
    `ID`,
    `BroadcastTextID0`,
    `Probability0`,
    `BroadcastTextID1`,
    `Probability1`,
    `BroadcastTextID2`,
    `Probability2`,
    `BroadcastTextID3`,
    `Probability3`,
    `BroadcastTextID4`,
    `Probability4`,
    `BroadcastTextID5`,
    `Probability5`,
    `BroadcastTextID6`,
    `Probability6`,
    `BroadcastTextID7`,
    `Probability7`
)
VALUES
(6298701, 6298701, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0),
(6298703, 6298703, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0, 0, 0.0);

INSERT INTO `gossip_menu`
(
    `entry`,
    `text_id`,
    `script_id`,
    `condition_id`
)
VALUES
(6298701, 6298701, 0, 0),
(6298702, 6298703, 0, 0);

INSERT INTO `gossip_menu_option`
(
    `menu_id`,
    `id`,
    `option_icon`,
    `option_text`,
    `option_broadcast_text`,
    `option_id`,
    `npc_option_npcflag`,
    `action_menu_id`,
    `action_poi_id`,
    `action_script_id`,
    `box_coded`,
    `box_money`,
    `box_text`,
    `box_broadcast_text`,
    `condition_id`
)
VALUES
(6298701, 0, 0, '<Inspect the hunter''s body>', 6298702, 1, 1, 6298702, 0, 6298702, 0, 0, '', 0, 41911);

INSERT INTO `gossip_scripts`
(
    `id`,
    `delay`,
    `priority`,
    `command`,
    `datalong`,
    `datalong2`,
    `datalong3`,
    `datalong4`,
    `target_param1`,
    `target_param2`,
    `target_type`,
    `data_flags`,
    `dataint`,
    `dataint2`,
    `dataint3`,
    `dataint4`,
    `x`,
    `y`,
    `z`,
    `o`,
    `condition_id`,
    `comments`
)
VALUES
(6298702, 0, 0, 8, 60082, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41911, 'Wolf in Sheep''s Clothing - Nar''lan found');
