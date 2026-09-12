cmake_minimum_required(VERSION 3.16)
project(TurtleArchitectureTests LANGUAGES C CXX)
enable_testing()
add_executable(ThornGorgeRulesTest ThornGorgeRulesTest.cpp)
target_compile_features(ThornGorgeRulesTest PRIVATE cxx_std_17)
target_include_directories(ThornGorgeRulesTest PRIVATE ../../src/game/Battlegrounds)
if(MSVC)
    target_compile_options(ThornGorgeRulesTest PRIVATE /EHsc)
endif()
add_test(NAME ThornGorgeRulesTest COMMAND ThornGorgeRulesTest)
set_tests_properties(ThornGorgeRulesTest PROPERTIES TIMEOUT 60)
add_executable(BoundedBotTraceTest BoundedBotTraceTest.cpp)
target_compile_features(BoundedBotTraceTest PRIVATE cxx_std_17)
target_include_directories(BoundedBotTraceTest PRIVATE ../../src/shared)
if(MSVC)
    target_compile_options(BoundedBotTraceTest PRIVATE /EHsc)
endif()
add_test(NAME BoundedBotTraceTest COMMAND BoundedBotTraceTest)
set_tests_properties(BoundedBotTraceTest PROPERTIES TIMEOUT 20)

function(extract_native_fragment source start end output)
    set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${source}")
    file(READ "${source}" body)
    string(FIND "${body}" "${start}" first)
    if(first LESS 0)
        message(FATAL_ERROR "Cannot find native regression start: ${output}")
    endif()
    string(SUBSTRING "${body}" ${first} -1 body)
    string(FIND "${body}" "${end}" length)
    if(length LESS 0)
        message(FATAL_ERROR "Cannot extract native regression fragment: ${output}")
    endif()
    string(SUBSTRING "${body}" 0 ${length} fragment)
    file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/${output}" "${fragment}")
endfunction()
set(CORE_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../..")
extract_native_fragment("${CORE_ROOT}/src/game/Battlegrounds/BattleGroundTG.cpp"
    "bool BattleGroundTG::OwnFlagObject(" "void BattleGroundTG::AddPlayer(" ThornGorgeFlagNative.inc)
add_executable(ThornGorgeFlagTest ThornGorgeFlagTest.cpp)
target_compile_features(ThornGorgeFlagTest PRIVATE cxx_std_17)
target_include_directories(ThornGorgeFlagTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR} ../../src/game/Battlegrounds)
if(MSVC)
    target_compile_options(ThornGorgeFlagTest PRIVATE /EHsc)
endif()
add_test(NAME ThornGorgeFlagTest COMMAND ThornGorgeFlagTest)
set_tests_properties(ThornGorgeFlagTest PROPERTIES TIMEOUT 60)
set(TRAVEL_ROOT "${CORE_ROOT}/modules/mod-playerbots/src/playerbot")
extract_native_fragment("${CORE_ROOT}/src/game/Handlers/AuctionHouseHandler.cpp"
    "void WorldSession::SendAuctionOwnerNotification(" "void WorldSession::SendAuctionRemovedNotification(" NativeAuctionOwnerNotification.inc)
extract_native_fragment("${CORE_ROOT}/src/game/AuctionHouse/AuctionHouseMgr.cpp"
    "void AuctionHouseMgr::SendAuctionSuccessfulMail(" "AuctionHouseObject* AuctionHouseMgr::MakeNewAuctionHouseObject()" NativeAuctionOwnerMail.inc)
add_executable(AuctionOwnerNotificationTest AuctionOwnerNotificationTest.cpp)
target_compile_features(AuctionOwnerNotificationTest PRIVATE cxx_std_17)
target_include_directories(AuctionOwnerNotificationTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
if(MSVC)
    target_compile_options(AuctionOwnerNotificationTest PRIVATE /EHsc)
endif()
add_test(NAME AuctionOwnerNotificationTest COMMAND AuctionOwnerNotificationTest)
set_tests_properties(AuctionOwnerNotificationTest PROPERTIES TIMEOUT 20)
extract_native_fragment("${CORE_ROOT}/src/mangosd/MaNGOSsoap.cpp"
    "namespace\n{" "////////////////////////////////////////////////////////////////////////////////" NativeSoapCommands.inc)
extract_native_fragment("${TRAVEL_ROOT}/PlayerbotMgr.cpp"
    "namespace\n{\n    std::mutex& HolderRegistryLock()" "void PlayerbotHolder::NotePlayerDestroyed" NativeHolderRegistry.inc)
extract_native_fragment("${TRAVEL_ROOT}/PlayerbotMgr.cpp"
    "void PlayerbotHolder::UpdateAllHolderSessions(" "PlayerbotHolder::PlayerbotHolder()" NativeHolderDispatch.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Objects/ItemPrototype.h"
    "enum BagFamily" "enum ItemSubclassWeapon" NativeBagEnums.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Objects/ItemPrototype.h"
    "enum ItemSubclassQuiver" "#define MAX_ITEM_SUBCLASS_QUIVER" NativeQuiverEnums.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Objects/Item.cpp"
    "bool ItemCanGoIntoBag(" "Item::Item()" NativeBagStorage.inc)
extract_native_fragment("${CORE_ROOT}/src/scripts/world/balor.cpp"
    "enum BalorExplosives" "void AddSC_balor()" NativeBalorGossip.inc)
extract_native_fragment("${CORE_ROOT}/modules/mod-dungeon-clear/src/Ai/Dungeon/DungeonClear/Util/DungeonEventExecutor.cpp"
    "bool DungeonEventExecutor::SelectGossip(" "StepResult DungeonEventExecutor::RunStep(" NativeDungeonGossip.inc)
foreach(test SoapCommandLifecycleTest BotHolderDispatchTest TurtleBagStorageTest BalorGossipTest DungeonGossipSelectionTest)
    add_executable(${test} ${test}.cpp)
    target_compile_features(${test} PRIVATE cxx_std_17)
    target_include_directories(${test} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
    if(MSVC)
        target_compile_options(${test} PRIVATE /EHsc)
    endif()
    add_test(NAME ${test} COMMAND ${test})
    set_tests_properties(${test} PROPERTIES TIMEOUT 20)
endforeach()

extract_native_fragment("${CORE_ROOT}/src/game/Objects/Unit.cpp"
    "void Unit::SetSpeedRate(" "void Unit::SetSpeedRateReal(" SocketlessSpeedNative.inc)
add_executable(SocketlessSpeedUpdateTest SocketlessSpeedUpdateTest.cpp)
target_compile_features(SocketlessSpeedUpdateTest PRIVATE cxx_std_17)
target_include_directories(SocketlessSpeedUpdateTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(SocketlessSpeedUpdateTest PRIVATE /EHsc)
endif()
add_test(NAME SocketlessSpeedUpdateTest COMMAND SocketlessSpeedUpdateTest)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/commands/BotCommands.cpp"
    "static bool HandleAhBot(ChatHandler* handler" "// pi-lens-ignore:" NativeAhBotChatDispatch.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ahbot/AhBot.cpp"
    "bool AhBot::HandleAhBotCommand(ChatHandler* handler, char const* args)" "uint32 AhBot::auctionIds" NativeAhBotModuleDispatch.inc)
add_executable(AhBotChatDispatchTest AhBotChatDispatchTest.cpp)
target_compile_features(AhBotChatDispatchTest PRIVATE cxx_std_17)
target_include_directories(AhBotChatDispatchTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
if(MSVC)
    target_compile_options(AhBotChatDispatchTest PRIVATE /EHsc)
endif()
add_test(NAME AhBotChatDispatchTest COMMAND AhBotChatDispatchTest)
# Replace tests for the retired category engine with production CMaNGOS paths.
set(AHBOT_ROOT "${CORE_ROOT}/modules/TortoiseBots/ahbot")
extract_native_fragment("${AHBOT_ROOT}/AhBot.cpp"
    "bool AhBot::Publish(" "void AhBot::ScanOne(" NativeAuctionPublish.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Objects/Item.cpp"
    "void Item::SetItemRandomProperties(" "uint8 Item::GetBagSlot()" NativeAuctionItemQueue.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Objects/Item.cpp"
    "void Item::SetEnchantment(" "void Item::SetEnchantmentDuration(" NativeAuctionEnchantment.inc)
add_executable(AuctionStockOwnershipTest AuctionStockOwnershipTest.cpp)
target_compile_features(AuctionStockOwnershipTest PRIVATE cxx_std_17)
target_include_directories(AuctionStockOwnershipTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}" "${AHBOT_ROOT}")
if(MSVC)
    target_compile_options(AuctionStockOwnershipTest PRIVATE /EHsc)
endif()
add_test(NAME AuctionStockOwnershipTest COMMAND AuctionStockOwnershipTest)
set_tests_properties(AuctionStockOwnershipTest PROPERTIES TIMEOUT 30)
extract_native_fragment("${AHBOT_ROOT}/AhBot.h"
    "namespace ahbot" "#define auctionbot" NativeMarketDeclarations.inc)
extract_native_fragment("${AHBOT_ROOT}/AhBot.cpp"
    "bool ReadNumbers(" "bool QueryIds(" NativeMarketParser.inc)
extract_native_fragment("${AHBOT_ROOT}/AhBot.cpp"
    "bool AhBot::IsBotOwner(" "void AhBot::Status(" NativeMarketWork.inc)
# Commands include item parsing through EOF, isolated with the end marker.
extract_native_fragment("${AHBOT_ROOT}/AhBot.cpp"
    "bool AhBot::HandleCommand(" "// End market command implementation." NativeMarketCommands.inc)
extract_native_fragment("${CORE_ROOT}/src/game/AuctionHouse/AuctionHouseMgr.cpp"
    "void AuctionHouseObject::ExpireAuction(" "void AuctionHouseObject::Update()" NativeMarketExpiry.inc)
extract_native_fragment("${CORE_ROOT}/src/game/AuctionHouse/AuctionHouseMgr.cpp"
    "void AuctionHouseMgr::SendAuctionOutbiddedMail(" "void AuctionHouseObject::BuildListBidderItems(" NativeMarketRefund.inc)
extract_native_fragment("${CORE_ROOT}/src/game/AuctionHouse/AuctionHouseMgr.cpp"
    "std::vector<AuctionSnapshot> AuctionHouseObject::GetAuctionsSnapshotPage(" "AuctionHouseMgr::AuctionHouseMgr()" NativeMarketPage.inc)
foreach(test AhBotMarketTest AuctionSettlementTest)
    add_executable(${test} ${test}.cpp)
    target_compile_features(${test} PRIVATE cxx_std_17)
    target_include_directories(${test} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}" "${AHBOT_ROOT}" "${CORE_ROOT}/src/shared")
    if(MSVC)
        target_compile_options(${test} PRIVATE /EHsc)
    endif()
    add_test(NAME ${test} COMMAND ${test})
    set_tests_properties(${test} PROPERTIES TIMEOUT 30)
endforeach()
extract_native_fragment("${TRAVEL_ROOT}/TravelNode.cpp"
    "void TravelNodeMap::generateTaxiPaths()" "void TravelNodeMap::removeLowNodes()" NativeTaxiGeneration.inc)
extract_native_fragment("${TRAVEL_ROOT}/TravelNode.cpp"
    "void TravelNodeMap::generateAll()" "void TravelNodeMap::printMap()" NativeTravelGeneration.inc)
extract_native_fragment("${TRAVEL_ROOT}/TravelNode.h"
    "        TravelNodePath* setPathTo(" "        bool hasCompletePathTo(" NativeTravelSetPath.inc)
extract_native_fragment("${TRAVEL_ROOT}/TravelNode.h"
    "        void setPathAndCost(" "        //void setPortal(" NativeTravelSetCost.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Database/DBCStructure.h"
    "struct TaxiPathNodePtr" "typedef Path<TaxiPathNodePtr" NativeTaxiNodePtr.inc)
add_executable(BotTaxiCacheRefreshTest BotTaxiCacheRefreshTest.cpp)
target_compile_features(BotTaxiCacheRefreshTest PRIVATE cxx_std_17)
target_include_directories(BotTaxiCacheRefreshTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
if(MSVC)
    target_compile_options(BotTaxiCacheRefreshTest PRIVATE /EHsc)
endif()
add_test(NAME BotTaxiCacheRefreshTest COMMAND BotTaxiCacheRefreshTest)
set_tests_properties(BotTaxiCacheRefreshTest PROPERTIES TIMEOUT 20)
extract_native_fragment("${TRAVEL_ROOT}/BotDiagnostics.cpp"
    "    void TraceBehavior(" "    void TraceThornBehavior(" BotTraceBody.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Movement/spline/MoveSpline.h"
    "int32 Duration() const" "int32 Duration(int first" BotNativeSplineDuration.inc)
add_executable(BotTraceSnapshotTest BotTraceSnapshotTest.cpp)
target_compile_features(BotTraceSnapshotTest PRIVATE cxx_std_17)
target_include_directories(BotTraceSnapshotTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}" "${CORE_ROOT}/src/shared")
if(MSVC)
    target_compile_options(BotTraceSnapshotTest PRIVATE /EHsc)
endif()
add_test(NAME BotTraceSnapshotTest COMMAND BotTraceSnapshotTest)
set_tests_properties(BotTraceSnapshotTest PROPERTIES TIMEOUT 20)
extract_native_fragment("${CORE_ROOT}/src/game/Objects/Player.cpp"
    "bool Player::CanInteractWithNPC(" "GameObject* Player::GetGameObjectIfCanInteractWith(" NativeNpcInteraction.inc)
extract_native_fragment("${TRAVEL_ROOT}/BotDiagnostics.cpp"
    "    class DiagnosticFlightMasterCheck" "    void TraceBehavior(" TaxiInteractionTrace.inc)
add_executable(NpcInteractionTraceTest NpcInteractionTraceTest.cpp)
target_compile_features(NpcInteractionTraceTest PRIVATE cxx_std_17)
target_include_directories(NpcInteractionTraceTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
if(MSVC)
    target_compile_options(NpcInteractionTraceTest PRIVATE /EHsc)
endif()
add_test(NAME NpcInteractionTraceTest COMMAND NpcInteractionTraceTest)
set_tests_properties(NpcInteractionTraceTest PROPERTIES TIMEOUT 20)
extract_native_fragment("${TRAVEL_ROOT}/strategy/actions/MovementActions.cpp"
    "void MovementAction::DispatchMovement(" "Unit* MovementAction::GetMover(" BotMoveDispatch.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Movement/MotionMaster.cpp"
    "void MotionMaster::MovePath(" "void MotionMaster::MoveWaypointAsDefault(" BotNativeMovePath.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Movement/PointMovementGenerator.cpp"
    "template<class T>\nvoid PointMovementGenerator<T>::Initialize(" "template<class T>\nvoid PointMovementGenerator<T>::Finalize(" BotNativePointInit.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Movement/PointMovementGenerator.cpp"
    "template<class T>\nbool PointMovementGenerator<T>::Update(" "template<>\nvoid PointMovementGenerator<Player>::MovementInform(" BotNativePointUpdate.inc)
add_executable(BotMovementDispatchTest BotMovementDispatchTest.cpp)
target_compile_features(BotMovementDispatchTest PRIVATE cxx_std_17)
target_compile_definitions(BotMovementDispatchTest PRIVATE MANGOSBOT_ZERO)
target_include_directories(BotMovementDispatchTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
if(MSVC)
    target_compile_options(BotMovementDispatchTest PRIVATE /EHsc)
endif()
add_test(NAME BotMovementDispatchTest COMMAND BotMovementDispatchTest)
set_tests_properties(BotMovementDispatchTest PROPERTIES TIMEOUT 20)
extract_native_fragment("${TRAVEL_ROOT}/RandomPlayerbotFactory.cpp"
    "    std::vector<std::future<void>> account_creations;" "    //LoginDatabase.PExecute" BotAccountCreation.inc)
extract_native_fragment("${TRAVEL_ROOT}/RandomPlayerbotFactory.cpp"
    "    std::vector<std::future<void>> bot_creations;" "    std::vector<Player*> players;" BotCreationSaves.inc)
add_executable(BotCreationLifecycleTest BotCreationLifecycleTest.cpp)
target_compile_features(BotCreationLifecycleTest PRIVATE cxx_std_17)
target_compile_definitions(BotCreationLifecycleTest PRIVATE MANGOSBOT_ZERO)
target_include_directories(BotCreationLifecycleTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
if(MSVC)
    target_compile_options(BotCreationLifecycleTest PRIVATE /EHsc)
endif()
add_test(NAME BotCreationLifecycleTest COMMAND BotCreationLifecycleTest)
set_tests_properties(BotCreationLifecycleTest PROPERTIES TIMEOUT 60)
extract_native_fragment("${TRAVEL_ROOT}/WorldPosition.cpp"
    "bool WorldPosition::ClosestCorrectPoint(" "bool WorldPosition::GetReachableRandomPointOnGround(" BotRpgPoint.inc)
extract_native_fragment("${TRAVEL_ROOT}/strategy/actions/ChooseRpgTargetAction.cpp"
    "std::unordered_map<ObjectGuid, uint32> ChooseRpgTargetAction::GetTargetCounts(" "#define SkipRpgTarget" BotRpgCrowd.inc)
extract_native_fragment("${TRAVEL_ROOT}/strategy/actions/MoveToRpgTargetAction.cpp"
    "    WorldPosition movePos(mapId, x, y, z);" "    if ((ai->HasStrategy(\"debug rpg\"" BotRpgApproach.inc)
extract_native_fragment("${TRAVEL_ROOT}/strategy/actions/MoveToRpgTargetAction.cpp"
    "bool MoveToRpgTargetAction::isUseful()" "    if(MEM_AI_VALUE" BotRpgUsefulPrefix.inc)
add_executable(BotRpgMovementTest BotRpgMovementTest.cpp)
target_compile_features(BotRpgMovementTest PRIVATE cxx_std_17)
target_include_directories(BotRpgMovementTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
if(MSVC)
    target_compile_options(BotRpgMovementTest PRIVATE /EHsc)
endif()
add_test(NAME BotRpgMovementTest COMMAND BotRpgMovementTest)
set_tests_properties(BotRpgMovementTest PROPERTIES TIMEOUT 20)
add_executable(StableTargetPositionTest StableTargetPositionTest.cpp)
target_compile_features(StableTargetPositionTest PRIVATE cxx_std_17)
if(MSVC)
    target_compile_options(StableTargetPositionTest PRIVATE /EHsc)
endif()
add_test(NAME StableTargetPositionTest COMMAND StableTargetPositionTest)
set_tests_properties(StableTargetPositionTest PROPERTIES TIMEOUT 20)
add_executable(TravelRoutePolicyTest TravelRoutePolicyTest.cpp)
target_compile_features(TravelRoutePolicyTest PRIVATE cxx_std_17)
if(MSVC)
    target_compile_options(TravelRoutePolicyTest PRIVATE /EHsc)
endif()
add_test(NAME TravelRoutePolicyTest COMMAND TravelRoutePolicyTest)
set_tests_properties(TravelRoutePolicyTest PROPERTIES TIMEOUT 20)
extract_native_fragment("${TRAVEL_ROOT}/strategy/Engine.cpp"
    "void Engine::UpdateActionFailureCachePeak(" "std::string Engine::GetFailureKey(" BotRetryPeak.inc)
extract_native_fragment("${TRAVEL_ROOT}/strategy/Engine.cpp"
    "bool Engine::IsFailureBackedOff(" "bool Engine::AllowBackgroundRetry(" BotRetryCache.inc)
extract_native_fragment("${TRAVEL_ROOT}/strategy/Engine.cpp"
    "bool Engine::AllowBackgroundRetry(" "Engine::Engine(" BotRetryPolicy.inc)
add_executable(BotRetryIntegrationTest BotRetryIntegrationTest.cpp)
target_compile_features(BotRetryIntegrationTest PRIVATE cxx_std_17)
target_include_directories(BotRetryIntegrationTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME BotRetryIntegrationTest COMMAND BotRetryIntegrationTest)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/MovementActions.cpp"
    "bool MovementAction::UseTaxi(" "bool MovementAction::MoveOnTransport(" BotTaxiUse.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/MovementActions.cpp"
    "    //Taxi handling: Start taxi" "   //Transport handling:" BotTaxiLeg.inc)
add_executable(BotTaxiIntegrationTest BotTaxiIntegrationTest.cpp)
target_compile_features(BotTaxiIntegrationTest PRIVATE cxx_std_17)
target_include_directories(BotTaxiIntegrationTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME BotTaxiIntegrationTest COMMAND BotTaxiIntegrationTest)
set_tests_properties(BotRetryIntegrationTest BotTaxiIntegrationTest PROPERTIES TIMEOUT 20)
if(MSVC)
    target_compile_options(BotRetryIntegrationTest PRIVATE /EHsc)
    target_compile_options(BotTaxiIntegrationTest PRIVATE /EHsc)
endif()
extract_native_fragment("${CORE_ROOT}/src/game/Maps/PathFinder.cpp"
    "bool PathInfo::calculate(float" "bool PathInfo::calculate(Vector3" ForkPathFloat.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Maps/PathFinder.cpp"
    "bool PathInfo::calculate(Vector3" "    TurtleDiagnostics::Scope diagnosticPath" ForkPathVectorPrefix.inc)
extract_native_fragment("${TRAVEL_ROOT}/BroadcastHelper.cpp"
    "bool BroadcastHelper::BroadcastToChannelWithGlobalChance(" "    for (const auto& pair : toChannels)" ForkBroadcastPrefix.inc)
extract_native_fragment("${TRAVEL_ROOT}/strategy/values/StatsValues.cpp"
    "bool PetIsDeadValue::Calculate()" "bool PetIsHappyValue::Calculate()" ForkPetDead.inc)
extract_native_fragment("${TRAVEL_ROOT}/strategy/actions/BattleGroundTactics.cpp"
    "        // Ground-level static rays" "        closePlayers =" ForkBannerCandidates.inc)
add_executable(ForkIntegrationTest ForkIntegrationTest.cpp)
target_compile_features(ForkIntegrationTest PRIVATE cxx_std_17)
target_include_directories(ForkIntegrationTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
if(MSVC)
    target_compile_options(ForkIntegrationTest PRIVATE /EHsc)
endif()
add_test(NAME ForkIntegrationTest COMMAND ForkIntegrationTest)
extract_native_fragment("${TRAVEL_ROOT}/strategy/actions/BattleGroundTactics.cpp"
    "std::vector<uint32> const vFlagsAB" "std::vector<uint32> const vFlagsWS" UpstreamAbEntries.inc)
extract_native_fragment("${TRAVEL_ROOT}/strategy/actions/BattleGroundTactics.cpp"
    "bool BGTactics::CanAttemptAbCapture()" "bool BGTactics::atFlag(" UpstreamAbThrottle.inc)
extract_native_fragment("${TRAVEL_ROOT}/strategy/actions/BattleGroundTactics.cpp"
    "        // AB assault banners" "        // Test the cheap side first" UpstreamAbStateGate.inc)
add_executable(UpstreamAbCaptureTest UpstreamAbCaptureTest.cpp)
target_compile_features(UpstreamAbCaptureTest PRIVATE cxx_std_17)
target_include_directories(UpstreamAbCaptureTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME UpstreamAbCaptureTest COMMAND UpstreamAbCaptureTest)
extract_native_fragment("${TRAVEL_ROOT}/strategy/values/TravelValues.h"
    "inline bool IsTravelSearchPending(" "    typedef std::set<uint32>" TravelPending.inc)
extract_native_fragment("${TRAVEL_ROOT}/PlayerbotAI.cpp"
    "FutureDestinations* future = AI_VALUE(FutureDestinations*, \"future travel destinations\");"
    "        RESET_AI_VALUE2(std::string" TravelReset.inc)
extract_native_fragment("${TRAVEL_ROOT}/TravelMgr.cpp"
    "void TravelMgr::GetPartitionsLock(" "bool TravelMgr::IsLocationLevelValid(" TravelPermit.inc)
extract_native_fragment("${TRAVEL_ROOT}/TravelMgr.cpp"
    "    sTravelMgr.GetPartitionsLock();" "    PartitionedTravelList pointMap;" TravelPermitScope.inc)
extract_native_fragment("${TRAVEL_ROOT}/strategy/actions/ChooseTravelTargetAction.cpp"
    "    PartitionedTravelList destinationList;\n    try" "    ai->TellDebug(ai->GetMaster(), \"Got \"" TravelResult.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Objects/Player.h"
    "uint32 GetAIElapsed(" "uint32 BackgroundAIDueAge(" AIClock.inc)
extract_native_fragment("${CORE_ROOT}/modules/mod-playerbots/src/playerbot/PlayerbotScripts.cpp"
    "bool IsAIUpdateDue(" "void OnAIUpdate(" AIDue.inc)
extract_native_fragment("${CORE_ROOT}/modules/mod-playerbots/src/playerbot/PlayerbotAIBase.cpp"
    "void PlayerbotAIBase::AdvanceMinimalUpdateDelay(" "void PlayerbotAIBase::SetAIInternalUpdateDelay(" AIAdvance.inc)
extract_native_fragment("${CORE_ROOT}/modules/mod-playerbots/src/playerbot/PlayerbotAI.cpp"
    "bool PlayerbotAI::HasSpell(uint32 spellid) const" "SpellCastResult PlayerbotAI::CheckSpellTargetAlignment(" AICapability.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Objects/Player.cpp"
    "bool Player::HasSpell(uint32 spell) const" "bool Player::HasActiveSpell(" NativeHasSpell.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Objects/Player.cpp"
    "void Player::SendQuestUpdateAddItem(" "void Player::SendQuestUpdateAddCreatureOrGo(" QuestItemUpdate.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Objects/Player.cpp"
    "void Player::RewardRage(" "void Player::HandleFoodEmotes(" NativeRewardRage.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Objects/Unit.cpp"
    "float Unit::GetTotalAuraMultiplier(" "int32 Unit::GetMaxPositiveAuraModifier(" NativeAuraMultiplier.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Objects/Unit.cpp"
    "float Unit::GetTotalAuraMultiplierByMiscMask(" "int32 Unit::GetTotalAuraModifierByMiscValue(" NativeAuraMaskMultiplier.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Objects/Object.cpp"
    "// Native periodic-damage bonus:" "// Add pct bonus from spell damage versus" NativePeriodicBonus.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Objects/Unit.cpp"
    "// Native chain avoidance" "if (damagetype == DOT)" NativeChainSpell.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Objects/Unit.cpp"
    "// Weapon-based chain spells" "if (spellProto && damagetype == DOT)" NativeChainWeapon.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Spells/SpellEntry.cpp"
    "// Native skill-specific cast-time auras" "        }\n    }\n\n    if (Attributes & SPELL_ATTR_RANGED" NativeSkillCastTime.inc)
foreach(test AIClockAccountingTest NativeSpellCapabilityTest QuestItemUpdateTest NativeCustomAuraTest TravelFutureLifecycleTest)
    add_executable(${test} ${test}.cpp)
    target_compile_features(${test} PRIVATE cxx_std_17)
    target_include_directories(${test} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}" "${CORE_ROOT}/src/game/Spells")
    if(MSVC)
        target_compile_options(${test} PRIVATE /EHsc)
    endif()
    add_test(NAME ${test} COMMAND ${test})
endforeach()
set_tests_properties(TravelFutureLifecycleTest PROPERTIES TIMEOUT 20)

# Exercise the actual trainer purchase handler with deterministic stand-ins for
# its native services. This tests dispatch/payment, not the Spell engine itself.
set(TRAINER_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/../../src/game/Handlers/NPCHandler.cpp")
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${TRAINER_SOURCE}")
file(READ "${TRAINER_SOURCE}" trainerSource)
string(FIND "${trainerSource}" "void WorldSession::HandleTrainerBuySpellOpcode(" trainerStart)
string(FIND "${trainerSource}" "void WorldSession::HandleGossipHelloOpcode(" trainerEnd)
if(trainerStart LESS 0 OR trainerEnd LESS trainerStart)
    message(FATAL_ERROR "Cannot isolate the native trainer handler for its regression test")
endif()
math(EXPR trainerLength "${trainerEnd} - ${trainerStart}")
string(SUBSTRING "${trainerSource}" ${trainerStart} ${trainerLength} trainerHandler)
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/TrainerPurchaseHandler.inc" "${trainerHandler}")
add_executable(TrainerPurchaseTest TrainerPurchaseTest.cpp)
target_compile_features(TrainerPurchaseTest PRIVATE cxx_std_17)
if(MSVC)
    target_compile_options(TrainerPurchaseTest PRIVATE /EHsc)
endif()
target_include_directories(TrainerPurchaseTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME TrainerPurchaseTest COMMAND TrainerPurchaseTest)

foreach(test AreaLookupIndexTest IncrementalFilterTest StaticLocationIndexTest TickDiffWindowTest UpstreamIntegrationTest)
    add_executable(${test} ${test}.cpp)
    target_compile_features(${test} PRIVATE cxx_std_17)
    target_include_directories(${test} PRIVATE ../../src/shared)
    if(MSVC)
        target_compile_options(${test} PRIVATE /EHsc /O2)
    endif()
    add_test(NAME ${test} COMMAND ${test})
endforeach()
add_executable(WeightedPermutationTest WeightedPermutationTest.cpp)
target_compile_features(WeightedPermutationTest PRIVATE cxx_std_17)
target_include_directories(WeightedPermutationTest PRIVATE ../../src/shared)
if(MSVC)
    target_compile_options(WeightedPermutationTest PRIVATE /EHsc /O2)
endif()
add_test(NAME WeightedPermutationTest COMMAND WeightedPermutationTest)
set_tests_properties(WeightedPermutationTest PROPERTIES TIMEOUT 60)
add_executable(PopulationSpatialIndexTest PopulationSpatialIndexTest.cpp)
target_compile_features(PopulationSpatialIndexTest PRIVATE cxx_std_17)
target_include_directories(PopulationSpatialIndexTest PRIVATE ../../src/shared)
if(MSVC)
    target_compile_options(PopulationSpatialIndexTest PRIVATE /EHsc /O2)
endif()
add_test(NAME PopulationSpatialIndexTest COMMAND PopulationSpatialIndexTest)
set_tests_properties(PopulationSpatialIndexTest PROPERTIES TIMEOUT 60)
add_executable(WorkSliceTest WorkSliceTest.cpp)
target_compile_features(WorkSliceTest PRIVATE cxx_std_17)
target_include_directories(WorkSliceTest PRIVATE ../../src/shared)
if(MSVC)
    target_compile_options(WorkSliceTest PRIVATE /EHsc)
endif()
add_test(NAME WorkSliceTest COMMAND WorkSliceTest)
set_tests_properties(WorkSliceTest PROPERTIES TIMEOUT 60)
find_package(Threads REQUIRED)
add_subdirectory(../../dep/libdeflate libdeflate)
foreach(test PacketCompressionContextTest MovementViewerSetTest)
    add_executable(${test} ${test}.cpp)
    target_compile_features(${test} PRIVATE cxx_std_17)
    target_include_directories(${test} PRIVATE ../../src/shared)
    target_link_libraries(${test} PRIVATE libdeflate Threads::Threads)
    if(MSVC)
        target_compile_options(${test} PRIVATE /EHsc /O2)
    endif()
    add_test(NAME ${test} COMMAND ${test})
    set_tests_properties(${test} PROPERTIES TIMEOUT 60)
endforeach()
add_executable(ThreadPoolBatchTest ThreadPoolBatchTest.cpp ../../src/shared/ThreadPool.cpp)
target_compile_features(ThreadPoolBatchTest PRIVATE cxx_std_17)
if(MSVC)
    target_compile_options(ThreadPoolBatchTest PRIVATE /EHsc)
endif()
target_compile_definitions(ThreadPoolBatchTest PRIVATE THREADPOOL_STANDALONE_TEST)
target_include_directories(ThreadPoolBatchTest PRIVATE ../../src/shared)
target_link_libraries(ThreadPoolBatchTest PRIVATE Threads::Threads)
add_test(NAME ThreadPoolBatchTest COMMAND ThreadPoolBatchTest)
set_tests_properties(ThreadPoolBatchTest PROPERTIES TIMEOUT 60)
add_test(NAME ContentHookContract COMMAND ${CMAKE_COMMAND}
    -DSOURCE_ROOT=${CMAKE_CURRENT_SOURCE_DIR}/../.. -P ${CMAKE_CURRENT_SOURCE_DIR}/ContentHookContract.cmake)
add_test(NAME AuctionQueryLifetimeContract COMMAND ${CMAKE_COMMAND}
    -DSOURCE_ROOT=${CMAKE_CURRENT_SOURCE_DIR}/../.. -P ${CMAKE_CURRENT_SOURCE_DIR}/AuctionQueryLifetimeContract.cmake)

add_executable(MapDiscoveryTest MapDiscoveryTest.cpp)
target_compile_features(MapDiscoveryTest PRIVATE cxx_std_17)
target_include_directories(MapDiscoveryTest PRIVATE ../../src/shared)
target_link_libraries(MapDiscoveryTest PRIVATE Threads::Threads)
if(MSVC)
    target_compile_options(MapDiscoveryTest PRIVATE /EHsc)
endif()
add_test(NAME MapDiscoveryTest COMMAND MapDiscoveryTest)
set_tests_properties(MapDiscoveryTest PROPERTIES TIMEOUT 60)

add_executable(BackgroundWorldSchedulingTest BackgroundWorldSchedulingTest.cpp)
target_compile_features(BackgroundWorldSchedulingTest PRIVATE cxx_std_17)
target_include_directories(BackgroundWorldSchedulingTest PRIVATE ../../src/shared)
if(MSVC)
    target_compile_options(BackgroundWorldSchedulingTest PRIVATE /EHsc)
endif()
add_test(NAME BackgroundWorldSchedulingTest COMMAND BackgroundWorldSchedulingTest)
set_tests_properties(BackgroundWorldSchedulingTest PROPERTIES TIMEOUT 60)

set(DETOUR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../dep/recastnavigation/Detour)
add_executable(NavMeshLifetimeTest NavMeshLifetimeTest.cpp
    ${DETOUR_DIR}/Source/DetourAlloc.cpp ${DETOUR_DIR}/Source/DetourAssert.cpp
    ${DETOUR_DIR}/Source/DetourCommon.cpp ${DETOUR_DIR}/Source/DetourNavMesh.cpp
    ${DETOUR_DIR}/Source/DetourNavMeshBuilder.cpp ${DETOUR_DIR}/Source/DetourNavMeshQuery.cpp
    ${DETOUR_DIR}/Source/DetourNode.cpp)
target_compile_features(NavMeshLifetimeTest PRIVATE cxx_std_17)
target_compile_definitions(NavMeshLifetimeTest PRIVATE DT_VIRTUAL_QUERYFILTER=1)
target_include_directories(NavMeshLifetimeTest PRIVATE ${DETOUR_DIR}/Include)
target_link_libraries(NavMeshLifetimeTest PRIVATE Threads::Threads)
if(MSVC)
    target_compile_options(NavMeshLifetimeTest PRIVATE /EHsc)
endif()
add_test(NAME NavMeshLifetimeTest COMMAND NavMeshLifetimeTest)
add_executable(ThornGorgeAssetProbe ThornGorgeAssetProbe.cpp
    ${DETOUR_DIR}/Source/DetourAlloc.cpp ${DETOUR_DIR}/Source/DetourAssert.cpp
    ${DETOUR_DIR}/Source/DetourCommon.cpp ${DETOUR_DIR}/Source/DetourNavMesh.cpp
    ${DETOUR_DIR}/Source/DetourNavMeshBuilder.cpp ${DETOUR_DIR}/Source/DetourNavMeshQuery.cpp
    ${DETOUR_DIR}/Source/DetourNode.cpp)
target_compile_features(ThornGorgeAssetProbe PRIVATE cxx_std_17)
target_compile_definitions(ThornGorgeAssetProbe PRIVATE DT_VIRTUAL_QUERYFILTER=1)
target_include_directories(ThornGorgeAssetProbe PRIVATE ${DETOUR_DIR}/Include)
target_link_libraries(ThornGorgeAssetProbe PRIVATE Threads::Threads)
if(MSVC)
    target_compile_options(ThornGorgeAssetProbe PRIVATE /EHsc)
endif()
set_tests_properties(NavMeshLifetimeTest PROPERTIES TIMEOUT 90)

add_executable(ThornGorgeDiagnosticsTest ThornGorgeDiagnosticsTest.cpp)
target_compile_features(ThornGorgeDiagnosticsTest PRIVATE cxx_std_17)
target_include_directories(ThornGorgeDiagnosticsTest PRIVATE ../../src/game/Battlegrounds)
add_test(NAME ThornGorgeDiagnosticsTest COMMAND ThornGorgeDiagnosticsTest)

extract_native_fragment("${CORE_ROOT}/src/game/Battlegrounds/BattleGroundTG.cpp"
    "void BattleGroundTG::RewardVictoryQuests(" "WorldSafeLocsEntry const* BattleGroundTG::GetClosestGraveYard" ThornGorgeRewardsNative.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Battlegrounds/BattleGroundTG.cpp"
    "void BattleGroundTG::FillInitialWorldStates(" "void BattleGroundTG::SendStates()" ThornGorgePresentationNative.inc)
add_executable(ThornGorgePresentationTest ThornGorgePresentationTest.cpp)
target_compile_features(ThornGorgePresentationTest PRIVATE cxx_std_17)
target_include_directories(ThornGorgePresentationTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR} ../../src/game/Battlegrounds)
if(MSVC)
    target_compile_options(ThornGorgePresentationTest PRIVATE /EHsc)
endif()
add_test(NAME ThornGorgePresentationTest COMMAND ThornGorgePresentationTest)

extract_native_fragment("${TRAVEL_ROOT}/WorldPosition.cpp"
    "bool WorldPosition::isBg() const" "std::string WorldPosition::getAreaName(" BotMapClassification.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Battlegrounds/BattleGroundTG.cpp"
    "bool BattleGroundTG::AdmitBotDiagnostic(" "void BattleGroundTG::TraceSnapshot(" ThornBotAdmission.inc)
extract_native_fragment("${TRAVEL_ROOT}/BotDiagnostics.cpp"
    "    void TraceThornBehavior(" "\n}}" ThornBotTrace.inc)
add_executable(ThornBotDiagnosticsTest ThornBotDiagnosticsTest.cpp)
target_compile_features(ThornBotDiagnosticsTest PRIVATE cxx_std_17)
target_include_directories(ThornBotDiagnosticsTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR} ../../src/game/Battlegrounds)
if(MSVC)
    target_compile_options(ThornBotDiagnosticsTest PRIVATE /EHsc)
endif()
add_test(NAME ThornBotDiagnosticsTest COMMAND ThornBotDiagnosticsTest)

extract_native_fragment("${CORE_ROOT}/src/game/AccountMgr.cpp"
    "bool AccountMgr::GetName(" "uint32 AccountMgr::GetCharactersCount(" AccountNameNative.inc)
extract_native_fragment("${CORE_ROOT}/src/game/AccountMgr.cpp"
    "AccountOpResult AccountMgr::ChangePassword(" "uint32 AccountMgr::GetId(" AccountPasswordNative.inc)
add_executable(AccountNameCacheTest AccountNameCacheTest.cpp)
target_compile_features(AccountNameCacheTest PRIVATE cxx_std_17)
target_include_directories(AccountNameCacheTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(AccountNameCacheTest PRIVATE /EHsc)
endif()
add_test(NAME AccountNameCacheTest COMMAND AccountNameCacheTest)

extract_native_fragment("${CORE_ROOT}/src/game/Movement/spline/MoveSpline.cpp"
    "MoveSpline::UpdateResult MoveSpline::_updateState(" "std::string MoveSpline::ToString(" SplineAdvanceNative.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Movement/spline/MoveSpline.cpp"
    "void MoveSpline::_Finalize()" "int32 MoveSpline::currentPathIdx()" SplineFinalizeNative.inc)
add_executable(SplineAdvanceGuardTest SplineAdvanceGuardTest.cpp)
target_compile_features(SplineAdvanceGuardTest PRIVATE cxx_std_17)
target_include_directories(SplineAdvanceGuardTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(SplineAdvanceGuardTest PRIVATE Threads::Threads)
if(MSVC)
    target_compile_options(SplineAdvanceGuardTest PRIVATE /EHsc)
endif()
add_test(NAME SplineAdvanceGuardTest COMMAND SplineAdvanceGuardTest)

# These three native functions occupy the tail of ObjectMgr.cpp.
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${CORE_ROOT}/src/game/ObjectMgr.cpp")
file(READ "${CORE_ROOT}/src/game/ObjectMgr.cpp" channel_source)
string(FIND "${channel_source}" "void ObjectMgr::LoadChatChannels()" channel_start)
if(channel_start LESS 0)
    message(FATAL_ERROR "Cannot find native chat channel loader")
endif()
string(SUBSTRING "${channel_source}" ${channel_start} -1 channel_source)
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/ChatChannelsNative.inc" "${channel_source}")
add_executable(ChatChannelLookupTest ChatChannelLookupTest.cpp)
target_compile_features(ChatChannelLookupTest PRIVATE cxx_std_17)
target_include_directories(ChatChannelLookupTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(ChatChannelLookupTest PRIVATE /EHsc)
endif()
add_test(NAME ChatChannelLookupTest COMMAND ChatChannelLookupTest)
find_package(Python3 COMPONENTS Interpreter QUIET)
if(Python3_Interpreter_FOUND)
    add_test(NAME PenqleMigrationTest COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/PenqleMigrationTest.py)
endif()

extract_native_fragment("${CORE_ROOT}/src/game/Movement/spline/packet_builder.cpp"
    "int32 WriteLinearPath(" "void PacketBuilder::WriteCreate(" SplinePacketNative.inc)
add_executable(SplinePacketContinuationTest SplinePacketContinuationTest.cpp)
target_compile_features(SplinePacketContinuationTest PRIVATE cxx_std_17)
target_include_directories(SplinePacketContinuationTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(SplinePacketContinuationTest PRIVATE /EHsc)
endif()
add_test(NAME SplinePacketContinuationTest COMMAND SplinePacketContinuationTest)

extract_native_fragment("${CORE_ROOT}/src/game/Handlers/BattleGroundHandler.cpp"
    "void WorldSession::HandleBattleGroundPlayerPositionsOpcode(" "void WorldSession::HandlePVPLogDataOpcode(" BattlegroundPositionsNative.inc)
# Extract the actual final BG block of the noncombat factory, including its
# closing function brace; the harness supplies only pre-BG strategy state.
file(READ "${TRAVEL_ROOT}/AiFactory.cpp" factory_source)
string(FIND "${factory_source}" "    // Battleground switch" factory_bg REVERSE)
string(SUBSTRING "${factory_source}" ${factory_bg} -1 factory_source)
string(FIND "${factory_source}" "Engine* AiFactory::createNonCombatEngine(" factory_end)
string(SUBSTRING "${factory_source}" 0 ${factory_end} factory_source)
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/BattlegroundNonCombatNative.inc" "${factory_source}")
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${TRAVEL_ROOT}/AiFactory.cpp")
add_executable(BattlegroundPlayerPresentationTest BattlegroundPlayerPresentationTest.cpp)
target_compile_features(BattlegroundPlayerPresentationTest PRIVATE cxx_std_17)
target_include_directories(BattlegroundPlayerPresentationTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(BattlegroundPlayerPresentationTest PRIVATE /EHsc)
endif()
add_test(NAME BattlegroundPlayerPresentationTest COMMAND BattlegroundPlayerPresentationTest)

extract_native_fragment("${CORE_ROOT}/src/game/Maps/PathFinder.cpp"
    "uint32 PathInfo::fixupCorridor(" "// Nostalrius\nbool PathInfo::UpdateForCaster(" NativePathSmoothing.inc)
target_include_directories(ThornGorgeAssetProbe PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

extract_native_fragment("${CORE_ROOT}/src/game/Battlegrounds/BattleGroundTG.cpp"
    "void BattleGroundTG::TraceMovement(" "// End Thorn Gorge movement observations." ThornMovementNative.inc)
add_executable(ThornMovementDiagnosticsTest ThornMovementDiagnosticsTest.cpp)
target_compile_features(ThornMovementDiagnosticsTest PRIVATE cxx_std_17)
target_include_directories(ThornMovementDiagnosticsTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(ThornMovementDiagnosticsTest PRIVATE /EHsc)
endif()
add_test(NAME ThornMovementDiagnosticsTest COMMAND ThornMovementDiagnosticsTest)
extract_native_fragment("${CORE_ROOT}/src/game/Battlegrounds/BattleGround.cpp"
    "bool BattleGround::AddObject(" "//some doors aren't despawned" BattlegroundObjectScaleNative.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/triggers/PvpTriggers.cpp"
    "bool ThornFlagDelivery::IsActive()" "#endif" ThornCarrierTriggerNative.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/generic/BattlegroundStrategy.cpp"
    "void ThornGorgeStrategy::InitNonCombatTriggers(" "#endif" ThornCarrierStrategyNative.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Battlegrounds/BattleGroundTG.cpp"
    "bool BattleGroundTG::GetObjective(" "void BattleGroundTG::Trace(" ThornObjectiveNative.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Battlegrounds/BattleGroundTG.cpp"
    "void BattleGroundTG::SendClientState(" "// End Thorn Gorge client state." ThornClientStateNative.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Maps/PathFinder.cpp"
    "void PathInfo::createFilter()" "void PathInfo::updateFilter()" PlayerWalkableFilterNative.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Maps/PathFinder.cpp"
    "dtPolyRef PathInfo::getPolyByLocation(" "void PathInfo::BuildPolyPath(" PlayerWalkableLookupNative.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/MovementActions.cpp"
    "bool JumpAction::TryGroundTraversal(" "bool JumpAction::Execute(" GroundTraversalNative.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/WorldPosition.cpp"
    "std::vector<WorldPosition> WorldPosition::getPathFromPath(" "bool WorldPosition::ClosestCorrectPoint(" MovementPathProgressNative.inc)
foreach(test IN ITEMS BattlegroundObjectScaleTest ThornCarrierStrategyTest ThornObjectiveAssignmentTest ThornClientStateTest PlayerWalkableFilterTest GroundTraversalTest MovementPathProgressTest)
    add_executable(${test} ${test}.cpp)
    target_compile_features(${test} PRIVATE cxx_std_17)
    target_include_directories(${test} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
    target_include_directories(${test} PRIVATE ../../src/game/Battlegrounds)
    if(MSVC)
        target_compile_options(${test} PRIVATE /EHsc)
    endif()
    add_test(NAME ${test} COMMAND ${test})
endforeach()

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/MovementActions.cpp"
    "TravelPath MovementAction::ResolveMovePath(" "bool MovementAction::HandleSpecialMovement(" StrictResolverNative.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Movement/spline/MoveSplineInit.cpp"
    "void MoveSplineInit::Move(PathFinder const*" "// A map can change workers" StrictSplineMoveNative.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Movement/spline/MoveSplineInit.h"
    "    inline void MoveSplineInit::MoveTo(float" "    inline void MoveSplineInit::SetFacing(Vector3" StrictSplineToNative.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/CheckMountStateAction.cpp"
    "    if (hasEnemy)" "    bool IsMounted" MountTargetDecisionNative.inc)
foreach(test IN ITEMS StrictPathHandoffTest MountTargetDecisionTest)
    add_executable(${test} ${test}.cpp)
    target_compile_features(${test} PRIVATE cxx_std_17)
    target_include_directories(${test} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
    if(MSVC)
        target_compile_options(${test} PRIVATE /EHsc)
    endif()
    add_test(NAME ${test} COMMAND ${test})
endforeach()

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/MovementActions.cpp"
    "bool MovementAction::TryMountForTravel(" "bool MovementAction::MoveTo2(" TravelMountPreparationNative.inc)
add_executable(TravelMountPreparationTest TravelMountPreparationTest.cpp)
target_compile_features(TravelMountPreparationTest PRIVATE cxx_std_17)
target_include_directories(TravelMountPreparationTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(TravelMountPreparationTest PRIVATE /EHsc)
endif()
add_test(NAME TravelMountPreparationTest COMMAND TravelMountPreparationTest)

# Execute the selected module's taxi refresh against sparse native DBC fixtures.
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/TravelNode.cpp"
    "void TravelNodeMap::generateTaxiPaths()" "void TravelNodeMap::removeLowNodes()" ModuleTaxiGeneration.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/TravelNode.h"
    "        void setPathAndCost(" "        //void setPortal(" ModuleTravelSetCost.inc)
add_executable(ModuleTaxiCacheRefreshTest ModuleTaxiCacheRefreshTest.cpp)
target_compile_features(ModuleTaxiCacheRefreshTest PRIVATE cxx_std_17)
target_include_directories(ModuleTaxiCacheRefreshTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
if(MSVC)
    target_compile_options(ModuleTaxiCacheRefreshTest PRIVATE /EHsc)
endif()
add_test(NAME ModuleTaxiCacheRefreshTest COMMAND ModuleTaxiCacheRefreshTest)
set_tests_properties(ModuleTaxiCacheRefreshTest PROPERTIES TIMEOUT 20)

extract_native_fragment("${CORE_ROOT}/src/game/Chat/Chat.h"
    "        bool IsCommandAvailable(" "        bool isValidChatMessage(" NativeModulePermissionQuery.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Chat/Chat.cpp"
    "bool ChatHandler::isAvailable(" "std::string ChatHandler::GetNameLink()" NativeGameCommandPermission.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Chat/Chat.cpp"
    "bool CliHandler::isAvailable(" "void CliHandler::SendSysMessage(" NativeCliCommandPermission.inc)
add_executable(NativeModuleCommandPermissionTest NativeModuleCommandPermissionTest.cpp)
target_compile_features(NativeModuleCommandPermissionTest PRIVATE cxx_std_17)
target_include_directories(NativeModuleCommandPermissionTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
if(MSVC)
    target_compile_options(NativeModuleCommandPermissionTest PRIVATE /EHsc)
endif()
add_test(NAME NativeModuleCommandPermissionTest COMMAND NativeModuleCommandPermissionTest)

# Active module dispatch must choose a single native movement owner.
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/MovementActions.cpp"
    "void MovementAction::DispatchMovement(" "Unit* MovementAction::GetMover(" ModuleMovementDispatchNative.inc)
add_executable(ModuleMovementDispatchTest ModuleMovementDispatchTest.cpp)
target_compile_features(ModuleMovementDispatchTest PRIVATE cxx_std_17)
target_include_directories(ModuleMovementDispatchTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(ModuleMovementDispatchTest PRIVATE /EHsc)
endif()
add_test(NAME ModuleMovementDispatchTest COMMAND ModuleMovementDispatchTest)

extract_native_fragment("${CORE_ROOT}/src/game/Maps/PathFinder.h"
    "#define MAX_PATH_LENGTH" "#endif" CoordinatePathClass.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Maps/PathFinder.cpp"
    "PathInfo::PathInfo(const Unit*" "// Nostalrius\nbool PathInfo::UpdateForCaster(" CoordinatePathImplementation.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Maps/PathFinder.cpp"
    "bool PathInfo::inRangeYZX(" "// End native path math." CoordinatePathMath.inc)
extract_native_fragment("${CMAKE_CURRENT_SOURCE_DIR}/NavMeshLifetimeTest.cpp"
    "static dtTileRef AddFlatTile(" "static void CheckGate(" CoordinatePathFlatTile.inc)
add_executable(CoordinatePathTest CoordinatePathTest.cpp
    ${DETOUR_DIR}/Source/DetourAlloc.cpp ${DETOUR_DIR}/Source/DetourAssert.cpp
    ${DETOUR_DIR}/Source/DetourCommon.cpp ${DETOUR_DIR}/Source/DetourNavMesh.cpp
    ${DETOUR_DIR}/Source/DetourNavMeshBuilder.cpp ${DETOUR_DIR}/Source/DetourNavMeshQuery.cpp
    ${DETOUR_DIR}/Source/DetourNode.cpp)
target_compile_features(CoordinatePathTest PRIVATE cxx_std_17)
target_compile_definitions(CoordinatePathTest PRIVATE DT_VIRTUAL_QUERYFILTER=1)
target_include_directories(CoordinatePathTest PRIVATE ${DETOUR_DIR}/Include ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(CoordinatePathTest PRIVATE Threads::Threads)
if(MSVC)
    target_compile_options(CoordinatePathTest PRIVATE /EHsc)
endif()
add_test(NAME CoordinatePathTest COMMAND CoordinatePathTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/TravelNode.cpp"
    "void TravelNodeMap::generateAll()" "void TravelNodeMap::printMap()" ModuleGenerateAll.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/TravelNode.cpp"
    "void TravelNodeMap::calculatePathCosts()" "void TravelNodeMap::generatePaths(" ModulePathCosts.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/TravelNode.cpp"
    "bool TravelNodePath::recalculateGeometry()" "//The cost to travel this path." ModuleGeometry.inc)
add_executable(ModuleTravelGenerationTest ModuleTravelGenerationTest.cpp)
target_compile_features(ModuleTravelGenerationTest PRIVATE cxx_std_17)
target_include_directories(ModuleTravelGenerationTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(ModuleTravelGenerationTest PRIVATE /EHsc)
endif()
add_test(NAME ModuleTravelGenerationTest COMMAND ModuleTravelGenerationTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
    "bool PlayerbotAI::HasPlayerNearby(WorldPosition pos," "bool PlayerbotAI::HasPlayerNearby(float" ModuleHumanInterest.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/host/BotPlayerAdapter.cpp"
    "bool BotPlayerAdapter::IsMachineDriven(" "void BotPlayerAdapter::OnLogin(" ModuleSchedulerTraits.inc)
add_executable(ModuleHumanInterestTest ModuleHumanInterestTest.cpp)
target_compile_features(ModuleHumanInterestTest PRIVATE cxx_std_17)
target_include_directories(ModuleHumanInterestTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(ModuleHumanInterestTest PRIVATE /EHsc)
endif()
add_test(NAME ModuleHumanInterestTest COMMAND ModuleHumanInterestTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/MovementActions.cpp"
    "    int32 const destinationCellX" "    bool detailedMove" ModulePathFailureGate.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/values/LastMovementValue.h"
    "        void clearPathFailure()" "        void Set(Unit*" ModuleClearPathFailure.inc)
add_executable(ModulePathRetryTest ModulePathRetryTest.cpp)
target_compile_features(ModulePathRetryTest PRIVATE cxx_std_17)
target_include_directories(ModulePathRetryTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(ModulePathRetryTest PRIVATE /EHsc)
endif()
add_test(NAME ModulePathRetryTest COMMAND ModulePathRetryTest)

extract_native_fragment("${CORE_ROOT}/src/shared/Database/AutoUpdater.cpp"
    "    bool AutoUpdater::ProcessUpdates()" "    // End configured migration dispatch." NativeModuleMigrationDispatch.inc)
add_executable(ModuleMigrationDispatchTest ModuleMigrationDispatchTest.cpp)
target_compile_features(ModuleMigrationDispatchTest PRIVATE cxx_std_17)
target_include_directories(ModuleMigrationDispatchTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(ModuleMigrationDispatchTest PRIVATE /EHsc)
endif()
add_test(NAME ModuleMigrationDispatchTest COMMAND ModuleMigrationDispatchTest)

extract_native_fragment("${CORE_ROOT}/src/game/HeadlessSessionMgr.cpp"
    "bool HeadlessSessionMgr::ReclaimForNetwork(" "void HeadlessSessionMgr::PromotePending()" NativeHeadlessReclaim.inc)
add_executable(NativeHeadlessReclaimTest NativeHeadlessReclaimTest.cpp)
target_compile_features(NativeHeadlessReclaimTest PRIVATE cxx_std_17)
target_include_directories(NativeHeadlessReclaimTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(NativeHeadlessReclaimTest PRIVATE /EHsc)
endif()
add_test(NAME NativeHeadlessReclaimTest COMMAND NativeHeadlessReclaimTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/RandomBotService.cpp"
    "void RandomBotService::UpdateMaintenance(" "void RandomBotService::Update(uint32_t diff)" ModulePopulationMaintenance.inc)
add_executable(ModulePopulationMaintenanceTest ModulePopulationMaintenanceTest.cpp)
target_compile_features(ModulePopulationMaintenanceTest PRIVATE cxx_std_17)
target_include_directories(ModulePopulationMaintenanceTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(ModulePopulationMaintenanceTest PRIVATE /EHsc)
endif()
add_test(NAME ModulePopulationMaintenanceTest COMMAND ModulePopulationMaintenanceTest)
