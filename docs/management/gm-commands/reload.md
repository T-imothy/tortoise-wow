---
layout: default
title: "GM Command: .reload"
---

# `.reload`

- Security: Administrator (4)
- Console: yes
- Subcommands: `.reload shop`, `.reload bgplayers`, `.reload gmlevels`, `.reload gm_ticket_template`, `.reload housing`, `.reload visibilities`, `.reload areatrigger_involvedrelation`, `.reload areatrigger_tavern`, `.reload areatrigger_teleport`, `.reload character_pet`, `.reload conditions`, `.reload config`, `.reload creature`, `.reload creature_ai_events`, `.reload creature_battleground`, `.reload creature_involvedrelation`, `.reload creature_loot_template`, `.reload creature_questrelation`, `.reload creature_spells`, `.reload creature_spells_scripts`, `.reload creature_template`, `.reload disenchant_loot_template`, `.reload event_scripts`, `.reload fishing_loot_template`, `.reload game_graveyard_zone`, `.reload game_tele`, `.reload taxi_path_transitions`, `.reload gameobject`, `.reload gameobject_involvedrelation`, `.reload gameobject_loot_template`, `.reload gameobject_questrelation`, `.reload gameobject_requirement`, `.reload gameobject_scripts`, `.reload gameobject_battleground`, `.reload gossip_menu`, `.reload gossip_menu_option`, `.reload generic_scripts`, `.reload gossip_scripts`, `.reload item_enchantment_template`, `.reload item_loot_template`, `.reload item_required_target`, `.reload item_template`, `.reload locales_creature`, `.reload locales_gameobject`, `.reload locales_gossip_menu_option`, `.reload locales_item`, `.reload locales_page_text`, `.reload locales_points_of_interest`, `.reload locales_quest`, `.reload mail_loot_template`, `.reload mangos_string`, `.reload module_string`, `.reload module_string_locale`, `.reload npc_gossip`, `.reload npc_text`, `.reload npc_trainer`, `.reload npc_vendor`, `.reload page_text`, `.reload pickpocketing_loot_template`, `.reload points_of_interest`, `.reload quest_end_scripts`, `.reload quest_start_scripts`, `.reload quest_template`, `.reload quest_greeting`, `.reload trainer_greeting`, `.reload reference_loot_template`, `.reload reserved_name`, `.reload reputation_reward_rate`, `.reload reputation_spillover_template`, `.reload skill_fishing_base_level`, `.reload skinning_loot_template`, `.reload spell_affect`, `.reload spell_area`, `.reload spell_chain`, `.reload spell_elixir`, `.reload spell_learn_spell`, `.reload spell_pet_auras`, `.reload spell_proc_event`, `.reload spell_proc_item_enchant`, `.reload spell_script_target`, `.reload spell_scripts`, `.reload spell_target_position`, `.reload spell_threats`, `.reload spell_disabled`, `.reload autobroadcast`, `.reload spell_mod`, `.reload map_loot_disabled`, `.reload cinematic_waypoints`, `.reload variables`, `.reload spell_group`, `.reload spell_group_stack_rules`, `.reload creature_groups`, `.reload exploration_basexp`, `.reload pet_name_generation`, `.reload creature_onkill_reputation`, `.reload game_weather`, `.reload player_factionchange_reputations`, `.reload player_factionchange_spells`, `.reload player_factionchange_items`, `.reload player_factionchange_quests`, `.reload player_factionchange_mounts`, `.reload creature_display_info_addon`, `.reload ip_banned`, `.reload account_banned`, `.reload instance_buff_removal`, `.reload petitions`

Syntax:

```text
.reload <subcommand>
```

Example:

```text
.reload shop
```

---

## `.reload shop`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadShopCommand`


---

## `.reload bgplayers`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadBgAmounts`


---

## `.reload gmlevels`

- Security: Developer (3)
- Console: yes
- Handler: `HandleReloadGmLevelsCommand`

Syntax:

```text
.reload gmlevels [arguments]
```

Example:

```text
.reload gmlevels arguments
```

---

## `.reload gm_ticket_template`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadGmTicketTemplatesCommand`


---

## `.reload housing`

- Security: Developer (3)
- Console: yes
- Handler: `HandleReloadHousingCommand`


---

## `.reload visibilities`

- Security: Developer (3)
- Console: yes
- Handler: `HandleReloadDynamicVisibilityCommand`


---

## `.reload areatrigger_involvedrelation`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadQuestAreaTriggersCommand`


---

## `.reload areatrigger_tavern`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadAreaTriggerTavernCommand`


---

## `.reload areatrigger_teleport`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadAreaTriggerTeleportCommand`


---

## `.reload character_pet`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadCharacterPetCommand`

Syntax:

```text
.reload character_pet <et_id>
```

Example:

```text
.reload character_pet 1
```

---

## `.reload conditions`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadConditionsCommand`


---

## `.reload config`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadConfigCommand`


---

## `.reload creature`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadCreatureCommand`


---

## `.reload creature_ai_events`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadEventAIEventsCommand`

Syntax:

```text
.reload creature_ai_events [arguments]
```

Example:

```text
.reload creature_ai_events arguments
```

---

## `.reload creature_battleground`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadBattleEventCommand`


---

## `.reload creature_involvedrelation`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadCreatureQuestInvRelationsCommand`


---

## `.reload creature_loot_template`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadLootTemplatesCreatureCommand`


---

## `.reload creature_questrelation`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadCreatureQuestRelationsCommand`


---

## `.reload creature_spells`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadCreatureSpellsCommand`


---

## `.reload creature_spells_scripts`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadCreatureSpellScriptsCommand`

Syntax:

```text
.reload creature_spells_scripts [arguments]
```

Example:

```text
.reload creature_spells_scripts arguments
```

---

## `.reload creature_template`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadCreatureTemplateCommand`

Syntax:

```text
.reload creature_template [entry]
```

Example:

```text
.reload creature_template
```

---

## `.reload disenchant_loot_template`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadLootTemplatesDisenchantCommand`


---

## `.reload event_scripts`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadEventScriptsCommand`

Syntax:

```text
.reload event_scripts [arguments]
```

Example:

```text
.reload event_scripts arguments
```

---

## `.reload fishing_loot_template`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadLootTemplatesFishingCommand`


---

## `.reload game_graveyard_zone`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadGameGraveyardZoneCommand`


---

## `.reload game_tele`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadGameTeleCommand`


---

## `.reload taxi_path_transitions`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadTaxiPathTransitionsCommand`


---

## `.reload gameobject`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadGameObjectCommand`


---

## `.reload gameobject_involvedrelation`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadGOQuestInvRelationsCommand`


---

## `.reload gameobject_loot_template`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadLootTemplatesGameobjectCommand`


---

## `.reload gameobject_questrelation`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadGOQuestRelationsCommand`


---

## `.reload gameobject_requirement`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadGORequirementsCommand`


---

## `.reload gameobject_scripts`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadGameObjectScriptsCommand`

Syntax:

```text
.reload gameobject_scripts [arguments]
```

Example:

```text
.reload gameobject_scripts arguments
```

---

## `.reload gameobject_battleground`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadBattleEventCommand`


---

## `.reload gossip_menu`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadGossipMenuCommand`


---

## `.reload gossip_menu_option`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadGossipMenuOptionCommand`


---

## `.reload generic_scripts`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadGenericScriptsCommand`

Syntax:

```text
.reload generic_scripts [arguments]
```

Example:

```text
.reload generic_scripts arguments
```

---

## `.reload gossip_scripts`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadGossipScriptsCommand`

Syntax:

```text
.reload gossip_scripts [arguments]
```

Example:

```text
.reload gossip_scripts arguments
```

---

## `.reload item_enchantment_template`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadItemEnchantementsCommand`


---

## `.reload item_loot_template`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadLootTemplatesItemCommand`


---

## `.reload item_required_target`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadItemRequiredTragetCommand`


---

## `.reload item_template`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadItemTemplate`


---

## `.reload locales_creature`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadLocalesCreatureCommand`


---

## `.reload locales_gameobject`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadLocalesGameobjectCommand`


---

## `.reload locales_gossip_menu_option`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadLocalesGossipMenuOptionCommand`


---

## `.reload locales_item`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadLocalesItemCommand`


---

## `.reload locales_page_text`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadLocalesPageTextCommand`


---

## `.reload locales_points_of_interest`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadLocalesPointsOfInterestCommand`


---

## `.reload locales_quest`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadLocalesQuestCommand`


---

## `.reload mail_loot_template`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadLootTemplatesMailCommand`


---

## `.reload mangos_string`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadMangosStringCommand`


---

## `.reload module_string`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadModuleStringCommand`


---

## `.reload module_string_locale`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadModuleStringCommand`


---

## `.reload npc_gossip`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadNpcGossipCommand`


---

## `.reload npc_text`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadNpcTextCommand`


---

## `.reload npc_trainer`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadNpcTrainerCommand`


---

## `.reload npc_vendor`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadNpcVendorCommand`


---

## `.reload page_text`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadPageTextsCommand`


---

## `.reload pickpocketing_loot_template`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadLootTemplatesPickpocketingCommand`


---

## `.reload points_of_interest`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadPointsOfInterestCommand`


---

## `.reload quest_end_scripts`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadQuestEndScriptsCommand`

Syntax:

```text
.reload quest_end_scripts [arguments]
```

Example:

```text
.reload quest_end_scripts arguments
```

---

## `.reload quest_start_scripts`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadQuestStartScriptsCommand`

Syntax:

```text
.reload quest_start_scripts [arguments]
```

Example:

```text
.reload quest_start_scripts arguments
```

---

## `.reload quest_template`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadQuestTemplateCommand`


---

## `.reload quest_greeting`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadQuestGreetingCommand`


---

## `.reload trainer_greeting`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadTrainerGreetingCommand`


---

## `.reload reference_loot_template`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadLootTemplatesReferenceCommand`


---

## `.reload reserved_name`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadReservedNameCommand`


---

## `.reload reputation_reward_rate`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadReputationRewardRateCommand`


---

## `.reload reputation_spillover_template`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadReputationSpilloverTemplateCommand`


---

## `.reload skill_fishing_base_level`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadSkillFishingBaseLevelCommand`


---

## `.reload skinning_loot_template`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadLootTemplatesSkinningCommand`


---

## `.reload spell_affect`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadSpellAffectCommand`


---

## `.reload spell_area`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadSpellAreaCommand`


---

## `.reload spell_chain`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadSpellChainCommand`


---

## `.reload spell_elixir`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadSpellElixirCommand`


---

## `.reload spell_learn_spell`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadSpellLearnSpellCommand`


---

## `.reload spell_pet_auras`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadSpellPetAurasCommand`


---

## `.reload spell_proc_event`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadSpellProcEventCommand`


---

## `.reload spell_proc_item_enchant`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadSpellProcItemEnchantCommand`


---

## `.reload spell_script_target`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadSpellScriptTargetCommand`


---

## `.reload spell_scripts`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadSpellScriptsCommand`

Syntax:

```text
.reload spell_scripts [arguments]
```

Example:

```text
.reload spell_scripts arguments
```

---

## `.reload spell_target_position`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadSpellTargetPositionCommand`


---

## `.reload spell_threats`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadSpellThreatsCommand`


---

## `.reload spell_disabled`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadSpellDisabledCommand`


---

## `.reload autobroadcast`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadAutoBroadcastCommand`


---

## `.reload spell_mod`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadSpellModsCommand`


---

## `.reload map_loot_disabled`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadMapLootDisabledCommand`


---

## `.reload cinematic_waypoints`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadCinematicWaypointsCommand`


---

## `.reload variables`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadVariablesCommand`


---

## `.reload spell_group`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadSpellGroupCommand`


---

## `.reload spell_group_stack_rules`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadSpellGroupStackRulesCommand`


---

## `.reload creature_groups`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadCreatureGroupsCommand`


---

## `.reload exploration_basexp`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadExplorationBaseXp`


---

## `.reload pet_name_generation`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadPetNameGeneration`


---

## `.reload creature_onkill_reputation`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadCreatureOnKillReputation`


---

## `.reload game_weather`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadGameWeather`


---

## `.reload player_factionchange_reputations`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadFactionChangeReputations`


---

## `.reload player_factionchange_spells`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadFactionChangeSpells`


---

## `.reload player_factionchange_items`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadFactionChangeItems`


---

## `.reload player_factionchange_quests`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadFactionChangeQuests`


---

## `.reload player_factionchange_mounts`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadFactionChangeMounts`


---

## `.reload creature_display_info_addon`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadCreatureDisplayInfoAddon`


---

## `.reload ip_banned`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadIPBanList`


---

## `.reload account_banned`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadAccountBanList`


---

## `.reload instance_buff_removal`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadInstanceBuffRemoval`


---

## `.reload petitions`

- Security: Administrator (4)
- Console: yes
- Handler: `HandleReloadPetitions`


---

[Back to GM Commands](../gm-commands.md)
