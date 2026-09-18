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
    "struct SoapCommandState" "////////////////////////////////////////////////////////////////////////////////" NativeSoapCommands.inc)
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
foreach(test SoapCommandLifecycleTest TurtleBagStorageTest BalorGossipTest DungeonGossipSelectionTest)
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
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/TravelNode.cpp"
    "void TravelNodeMap::generateTaxiPaths()" "void TravelNodeMap::removeLowNodes()" NativeTaxiGeneration.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/TravelNode.cpp"
    "void TravelNodeMap::generateAll()" "void TravelNodeMap::printMap()" NativeTravelGeneration.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/TravelNode.h"
    "        TravelNodePath* setPathTo(" "        bool hasCompletePathTo(" NativeTravelSetPath.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/TravelNode.h"
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
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/BotDiagnostics.cpp"
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
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/BotDiagnostics.cpp"
    "    class DiagnosticFlightMasterCheck" "    void TraceBehavior(" TaxiInteractionTrace.inc)
add_executable(NpcInteractionTraceTest NpcInteractionTraceTest.cpp)
target_compile_features(NpcInteractionTraceTest PRIVATE cxx_std_17)
target_include_directories(NpcInteractionTraceTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
if(MSVC)
    target_compile_options(NpcInteractionTraceTest PRIVATE /EHsc)
endif()
add_test(NAME NpcInteractionTraceTest COMMAND NpcInteractionTraceTest)
set_tests_properties(NpcInteractionTraceTest PROPERTIES TIMEOUT 20)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/MovementActions.cpp"
    "bool MovementAction::DispatchMovement(" "Unit* MovementAction::GetMover(" BotMoveDispatch.inc)
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
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/WorldPosition.cpp"
    "bool WorldPosition::ClosestCorrectPoint(" "bool WorldPosition::GetReachableRandomPointOnGround(" BotRpgPoint.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/ChooseRpgTargetAction.cpp"
    "std::unordered_map<ObjectGuid, uint32> ChooseRpgTargetAction::GetTargetCounts(" "#define SkipRpgTarget" BotRpgCrowd.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/MoveToRpgTargetAction.cpp"
    "    WorldPosition movePos(mapId, x, y, z);" "    if ((ai->HasStrategy(\"debug rpg\"" BotRpgApproach.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/MoveToRpgTargetAction.cpp"
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
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/Engine.cpp"
    "bool Engine::AllowBackgroundRetry(" "void Engine::DrainQueue(" BotRetryPolicy.inc)
add_executable(BotRetryIntegrationTest BotRetryIntegrationTest.cpp)
target_compile_features(BotRetryIntegrationTest PRIVATE cxx_std_17)
target_include_directories(BotRetryIntegrationTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}" "${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy")
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
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/BroadcastHelper.cpp"
    "bool BroadcastHelper::BroadcastToChannelWithGlobalChance(" "    for (const auto& pair : toChannels)" ForkBroadcastPrefix.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/values/StatsValues.cpp"
    "bool PetIsDeadValue::Calculate()" "bool PetIsHappyValue::Calculate()" ForkPetDead.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/BattleGroundTactics.cpp"
    "        // Ground-level static rays" "        closePlayers =" ForkBannerCandidates.inc)
add_executable(ForkIntegrationTest ForkIntegrationTest.cpp)
target_compile_features(ForkIntegrationTest PRIVATE cxx_std_17)
target_include_directories(ForkIntegrationTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
if(MSVC)
    target_compile_options(ForkIntegrationTest PRIVATE /EHsc)
endif()
add_test(NAME ForkIntegrationTest COMMAND ForkIntegrationTest)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/BattleGroundTactics.cpp"
    "std::vector<uint32> const vFlagsAB" "std::vector<uint32> const vFlagsWS" UpstreamAbEntries.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/BattleGroundTactics.cpp"
    "bool BGTactics::CanAttemptAbCapture()" "bool BGTactics::atFlag(" UpstreamAbThrottle.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/BattleGroundTactics.cpp"
    "        // AB assault banners" "        // Test the cheap side first" UpstreamAbStateGate.inc)
add_executable(UpstreamAbCaptureTest UpstreamAbCaptureTest.cpp)
target_compile_features(UpstreamAbCaptureTest PRIVATE cxx_std_17)
target_include_directories(UpstreamAbCaptureTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME UpstreamAbCaptureTest COMMAND UpstreamAbCaptureTest)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/values/TravelValues.h"
    "inline bool IsTravelSearchPending(" "    typedef std::set<uint32>" TravelPending.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
    "FutureDestinations* future = AI_VALUE(FutureDestinations*, \"future travel destinations\");"
    "        RESET_AI_VALUE2(std::string" TravelReset.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/TravelMgr.cpp"
    "void TravelMgr::GetPartitionsLock(" "bool TravelMgr::IsLocationLevelValid(" TravelPermit.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/TravelMgr.cpp"
    "    sTravelMgr.GetPartitionsLock();" "    PartitionedTravelList pointMap;" TravelPermitScope.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/ChooseTravelTargetAction.cpp"
    "    PartitionedTravelList destinationList;\n    try" "    ai->TellDebug(ai->GetMaster(), \"Got \"" TravelResult.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Objects/Player.h"
    "uint32 GetAIElapsed(" "uint32 BackgroundAIDueAge(" AIClock.inc)
extract_native_fragment("${CORE_ROOT}/modules/mod-playerbots/src/playerbot/PlayerbotScripts.cpp"
    "bool IsAIUpdateDue(" "void OnAIUpdate(" AIDue.inc)
extract_native_fragment("${CORE_ROOT}/modules/mod-playerbots/src/playerbot/PlayerbotAIBase.cpp"
    "void PlayerbotAIBase::AdvanceMinimalUpdateDelay(" "void PlayerbotAIBase::SetAIInternalUpdateDelay(" AIAdvance.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
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

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/WorldPosition.cpp"
    "bool WorldPosition::isBg() const" "std::string WorldPosition::getAreaName(" BotMapClassification.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Battlegrounds/BattleGroundTG.cpp"
    "bool BattleGroundTG::AdmitBotDiagnostic(" "void BattleGroundTG::TraceSnapshot(" ThornBotAdmission.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/BotDiagnostics.cpp"
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
file(READ "${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/AiFactory.cpp" factory_source)
string(FIND "${factory_source}" "    // Battleground switch" factory_bg REVERSE)
string(SUBSTRING "${factory_source}" ${factory_bg} -1 factory_source)
string(FIND "${factory_source}" "Engine* AiFactory::createNonCombatEngine(" factory_end)
string(SUBSTRING "${factory_source}" 0 ${factory_end} factory_source)
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/BattlegroundNonCombatNative.inc" "${factory_source}")
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/AiFactory.cpp")
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
    "bool MovementAction::DispatchMovement(" "Unit* MovementAction::GetMover(" ModuleMovementDispatchNative.inc)
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
    "bool BotPlayerAdapter::IsMachineDriven(" "bool BotPlayerAdapter::IsAIUpdateDue(" ModuleSchedulerTraits.inc)
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

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/PlayerbotRuntimeFacade.cpp"
    "namespace\n{" "void RandomBotFacade::SyncNativePlayers()" ModuleValueStorage.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/PlayerbotRuntimeFacade.cpp"
    "bool RandomBotFacade::LoadPersistentValues()" "void RandomBotFacade::Remove(" ModuleValueMethods.inc)
add_executable(ModulePersistentValuesTest ModulePersistentValuesTest.cpp)
target_compile_features(ModulePersistentValuesTest PRIVATE cxx_std_17)
target_include_directories(ModulePersistentValuesTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(ModulePersistentValuesTest PRIVATE /EHsc)
endif()
add_test(NAME ModulePersistentValuesTest COMMAND ModulePersistentValuesTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/RandomBotService.cpp"
    "void RandomBotService::RefreshPopulationTarget()" "// Deterministic allowed team" ModulePopulationReconcile.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/BotManager.cpp"
    "bool BotManager::HasRandomAdmissionCapacity()" "bool BotManager::AddRandomBot(" ModuleAdmissionCapacity.inc)
add_executable(ModulePopulationReconciliationTest ModulePopulationReconciliationTest.cpp)
target_compile_features(ModulePopulationReconciliationTest PRIVATE cxx_std_17)
target_include_directories(ModulePopulationReconciliationTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(ModulePopulationReconciliationTest PRIVATE /EHsc)
endif()
add_test(NAME ModulePopulationReconciliationTest COMMAND ModulePopulationReconciliationTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/host/BotPlayerAdapter.cpp"
    "bool BotPlayerAdapter::IsAIControlled(" "bool BotPlayerAdapter::IsUpdateCritical(" ModuleNativeRoleHooks.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/LftBotFillService.cpp"
    "bool LftBotFillService::CanFillQueue()" "void LftBotFillService::Initialize()" ModuleLftOwner.inc)
add_executable(ModuleNativeRoleHooksTest ModuleNativeRoleHooksTest.cpp)
target_compile_features(ModuleNativeRoleHooksTest PRIVATE cxx_std_17)
target_include_directories(ModuleNativeRoleHooksTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(ModuleNativeRoleHooksTest PRIVATE /EHsc)
endif()
add_test(NAME ModuleNativeRoleHooksTest COMMAND ModuleNativeRoleHooksTest)

extract_native_fragment("${CORE_ROOT}/src/shared/Database/Database.cpp"
    "void Database::HaltDelayThread()" "void Database::ThreadStart()" DatabasePartialPool.inc)
add_executable(DatabasePartialPoolTest DatabasePartialPoolTest.cpp)
target_compile_features(DatabasePartialPoolTest PRIVATE cxx_std_17)
target_include_directories(DatabasePartialPoolTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(DatabasePartialPoolTest PRIVATE /EHsc)
endif()
add_test(NAME DatabasePartialPoolTest COMMAND DatabasePartialPoolTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/PlayerbotAIStorage.cpp"
    "PlayerbotAIStorage& PlayerbotAIStorage::Instance()" "// End module AI identity registry." ModuleAIIdentity.inc)
add_executable(ModuleAIIdentityTest ModuleAIIdentityTest.cpp)
target_compile_features(ModuleAIIdentityTest PRIVATE cxx_std_17)
target_include_directories(ModuleAIIdentityTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(ModuleAIIdentityTest PRIVATE /EHsc)
endif()
add_test(NAME ModuleAIIdentityTest COMMAND ModuleAIIdentityTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PerformanceMonitor.h"
    "typedef std::vector<std::string> PerformanceStack;" "#define sPerformanceMonitor" ModulePerformanceTypes.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PerformanceMonitor.cpp"
    "namespace bot_perf {" "// The host owns the legacy" ModulePerformanceMethods.inc)
add_executable(ModulePerformanceStateTest ModulePerformanceStateTest.cpp)
target_compile_features(ModulePerformanceStateTest PRIVATE cxx_std_17)
target_include_directories(ModulePerformanceStateTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(ModulePerformanceStateTest PRIVATE /EHsc)
endif()
add_test(NAME ModulePerformanceStateTest COMMAND ModulePerformanceStateTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/host/BotChatAdapter.cpp"
    "std::vector<ChatCommand> BotChatAdapter::GetCommands() const" "// End native module command registrations." ModuleCommandRegistrations.inc)
add_executable(ModuleCommandRegistrationTest ModuleCommandRegistrationTest.cpp)
target_compile_features(ModuleCommandRegistrationTest PRIVATE cxx_std_17)
target_compile_definitions(ModuleCommandRegistrationTest PRIVATE CORE_SOURCE_ROOT="${CORE_ROOT}")
target_include_directories(ModuleCommandRegistrationTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(ModuleCommandRegistrationTest PRIVATE /EHsc)
endif()
add_test(NAME ModuleCommandRegistrationTest COMMAND ModuleCommandRegistrationTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.h"
    "class PacketHandlingHelper" "class ChatCommandHolder" ModulePacketTypes.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
    "void PacketHandlingHelper::AddHandler" "PlayerbotAI::PlayerbotAI()" ModulePacketMethods.inc)
add_executable(ModulePacketDispatchTest ModulePacketDispatchTest.cpp)
target_compile_features(ModulePacketDispatchTest PRIVATE cxx_std_17)
target_include_directories(ModulePacketDispatchTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(ModulePacketDispatchTest PRIVATE /EHsc)
endif()
add_test(NAME ModulePacketDispatchTest COMMAND ModulePacketDispatchTest)
set_tests_properties(ModulePacketDispatchTest PROPERTIES TIMEOUT 15)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/BattleGroundTactics.cpp"
    "GameObject* BGTactics::PreviousAbObjective()" "// End AI-owned Arathi objective memory." ModuleBgObjectiveMemory.inc)
add_executable(ModuleBgObjectiveLifetimeTest ModuleBgObjectiveLifetimeTest.cpp)
target_compile_features(ModuleBgObjectiveLifetimeTest PRIVATE cxx_std_17)
target_include_directories(ModuleBgObjectiveLifetimeTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
add_test(NAME ModuleBgObjectiveLifetimeTest COMMAND ModuleBgObjectiveLifetimeTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/values/SharedValueContext.h"
    "    class SharedObjectContext" "#define sSharedObjectContext" ModuleSharedValueContext.inc)
add_executable(ModuleSharedValueCacheTest ModuleSharedValueCacheTest.cpp)
target_compile_features(ModuleSharedValueCacheTest PRIVATE cxx_std_17)
target_include_directories(ModuleSharedValueCacheTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
add_test(NAME ModuleSharedValueCacheTest COMMAND ModuleSharedValueCacheTest)
set_tests_properties(ModuleSharedValueCacheTest PROPERTIES TIMEOUT 15)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/commands/RandomBotCommands.cpp"
    "bool HandleRandomCommand(" "// End native random-bot command." ModuleRandomAdminCommand.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/RandomBotService.cpp"
    "uint32_t RandomBotService::QueueAdminAction(" "// End bounded random-bot admin requests." ModuleRandomAdminQueue.inc)
foreach(test IN ITEMS ModuleRandomAdminCommandTest ModuleRandomAdminQueueTest)
    add_executable(${test} ${test}.cpp)
    target_compile_features(${test} PRIVATE cxx_std_17)
    target_include_directories(${test} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
    add_test(NAME ${test} COMMAND ${test})
endforeach()

add_executable(ModuleFailureBackoffTest "${CORE_ROOT}/modules/TortoiseBots/tools/test_engine_failure_backoff.cpp")
target_compile_features(ModuleFailureBackoffTest PRIVATE cxx_std_17)
target_include_directories(ModuleFailureBackoffTest PRIVATE "${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy")
add_test(NAME ModuleFailureBackoffTest COMMAND ModuleFailureBackoffTest)

# Packet producers must not mutate owner AI state or race native AI release.
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.h"
    "    struct PendingBotPacket" "    bool UpdateAIReaction" ModuleOwnerPacketTypes.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
    "void PlayerbotAI::HandleBotOutgoingPacket(" "void PlayerbotAI::ProcessBotOutgoingPacket(" ModuleOwnerPacketMethods.inc)
add_executable(ModuleOwnerPacketTest ModuleOwnerPacketTest.cpp)
target_compile_features(ModuleOwnerPacketTest PRIVATE cxx_std_17)
target_include_directories(ModuleOwnerPacketTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(ModuleOwnerPacketTest PRIVATE /EHsc)
endif()
add_test(NAME ModuleOwnerPacketTest COMMAND ModuleOwnerPacketTest)
set_tests_properties(ModuleOwnerPacketTest PROPERTIES TIMEOUT 15)

# A delayed reply belongs to the originating AI, even across same-GUID relogin.
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.h"
    "    struct DelayedPacketMailbox" "    struct PendingBotPacket" ModuleDelayedMailboxTypes.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
    "void PlayerbotAI::SendDelayedPacket(" "std::string PlayerbotAI::InventoryParseOutfitName" ModuleDelayedReplyMethods.inc)
add_executable(ModuleDelayedReplyTest ModuleDelayedReplyTest.cpp)
target_compile_features(ModuleDelayedReplyTest PRIVATE cxx_std_17)
target_include_directories(ModuleDelayedReplyTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(ModuleDelayedReplyTest PRIVATE /EHsc)
endif()
add_test(NAME ModuleDelayedReplyTest COMMAND ModuleDelayedReplyTest)
set_tests_properties(ModuleDelayedReplyTest PROPERTIES TIMEOUT 15)

extract_native_fragment("${CORE_ROOT}/src/game/HeadlessSessionMgr.cpp"
    "void HeadlessSessionMgr::Update(" "void HeadlessSessionMgr::Shutdown(" NativeHeadlessStranded.inc)
add_executable(NativeHeadlessStrandedTest NativeHeadlessStrandedTest.cpp)
target_compile_features(NativeHeadlessStrandedTest PRIVATE cxx_std_17)
target_include_directories(NativeHeadlessStrandedTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
add_test(NAME NativeHeadlessStrandedTest COMMAND NativeHeadlessStrandedTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotTextMgr.cpp"
    "std::string PlayerbotTextMgr::GetBotText(ChatReplyType replyType, std::map" "std::string PlayerbotTextMgr::GetBotText(ChatReplyType replyType, std::string" ModuleReplySelection.inc)
add_executable(ModuleReplySelectionTest ModuleReplySelectionTest.cpp)
target_compile_features(ModuleReplySelectionTest PRIVATE cxx_std_17)
target_include_directories(ModuleReplySelectionTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
add_test(NAME ModuleReplySelectionTest COMMAND ModuleReplySelectionTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/Engine.cpp"
    "bool Engine::ScheduleWorldContinuation(" "bool Engine::DoNextAction(" ModuleEngineContinuation.inc)
# Compile the selected module's real decision/reaction walks and queue helpers.
set(ENGINE_RECOVERY_ROOT "${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy")
extract_native_fragment("${ENGINE_RECOVERY_ROOT}/Engine.cpp"
    "bool Engine::DoNextAction(" "ActionNode* Engine::CreateActionNode" ModuleEngineWalk.inc)
extract_native_fragment("${ENGINE_RECOVERY_ROOT}/Engine.cpp"
    "bool Engine::MultiplyAndPush(NextAction**" "ActionResult Engine::ExecuteAction" ModuleEnginePush.inc)
extract_native_fragment("${ENGINE_RECOVERY_ROOT}/Engine.cpp"
    "void Engine::PushAgain(" "bool Engine::ContainsStrategy" ModuleEnginePushAgain.inc)
extract_native_fragment("${ENGINE_RECOVERY_ROOT}/ReactionEngine.cpp"
    "bool ReactionEngine::FindReaction(" "bool ReactionEngine::StartReaction" ModuleEngineReaction.inc)
extract_native_fragment("${ENGINE_RECOVERY_ROOT}/Queue.cpp"
    "void Queue::Push(" "void Queue::RemoveExpired" ModuleEngineQueue.inc)
extract_native_fragment("${ENGINE_RECOVERY_ROOT}/ReactionEngine.cpp"
    "bool ReactionEngine::StartReaction(" "bool ReactionEngine::ListenAndExecute(" ModuleEngineReactionLifecycle.inc)
add_executable(ModuleEngineRecoveryTest ModuleEngineRecoveryTest.cpp)
target_compile_features(ModuleEngineRecoveryTest PRIVATE cxx_std_17)
target_include_directories(ModuleEngineRecoveryTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
if(MSVC)
    target_compile_options(ModuleEngineRecoveryTest PRIVATE /EHsc)
endif()
add_test(NAME ModuleEngineRecoveryTest COMMAND ModuleEngineRecoveryTest)
set_tests_properties(ModuleEngineRecoveryTest PROPERTIES TIMEOUT 20)

add_executable(ModuleActivityControllerTest ModuleActivityControllerTest.cpp)
target_compile_features(ModuleActivityControllerTest PRIVATE cxx_std_17)
target_include_directories(ModuleActivityControllerTest PRIVATE "${CORE_ROOT}/modules/TortoiseBots/runtime" "${CORE_ROOT}/src/shared")
if(MSVC)
    target_compile_options(ModuleActivityControllerTest PRIVATE /EHsc)
endif()
add_test(NAME ModuleActivityControllerTest COMMAND ModuleActivityControllerTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/PlayerbotRuntimeFacade.cpp"
    "bool RandomBotFacade::InitializeBot(" "bool RandomBotFacade::Refresh(" ModuleBotInitialization.inc)
add_executable(ModuleBotInitializationTest ModuleBotInitializationTest.cpp)
target_compile_features(ModuleBotInitializationTest PRIVATE cxx_std_17)
target_include_directories(ModuleBotInitializationTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(ModuleBotInitializationTest PRIVATE /EHsc)
endif()
add_test(NAME ModuleBotInitializationTest COMMAND ModuleBotInitializationTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/BotManager.cpp"
    "bool BotManager::RelocateRandomBot(" "bool BotManager::RelocateHopelessBot(" ModuleRandomRelocation.inc)
add_executable(ModuleRandomRelocationTest ModuleRandomRelocationTest.cpp)
target_compile_features(ModuleRandomRelocationTest PRIVATE cxx_std_17)
target_include_directories(ModuleRandomRelocationTest PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
if(MSVC)
    target_compile_options(ModuleRandomRelocationTest PRIVATE /EHsc)
endif()
add_test(NAME ModuleRandomRelocationTest COMMAND ModuleRandomRelocationTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/BotManager.cpp"
    "ai::WorldPosition const* PickLevelFittingPoint(" "bool TryRandomTeleport(" ModuleTeleportPicker.inc)
add_executable(ModuleTeleportPickerTest ModuleTeleportPickerTest.cpp)
target_compile_features(ModuleTeleportPickerTest PRIVATE cxx_std_17)
target_include_directories(ModuleTeleportPickerTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME ModuleTeleportPickerTest COMMAND ModuleTeleportPickerTest)
set_tests_properties(ModuleTeleportPickerTest PROPERTIES TIMEOUT 20)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/TravelMgr.cpp"
    "int32 TravelMgr::GetAreaLevel(" "void TravelMgr::LoadAreaLevels(" ModuleAreaLevelCache.inc)
add_executable(ModuleAreaLevelCacheTest ModuleAreaLevelCacheTest.cpp)
target_compile_features(ModuleAreaLevelCacheTest PRIVATE cxx_std_17)
target_include_directories(ModuleAreaLevelCacheTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME ModuleAreaLevelCacheTest COMMAND ModuleAreaLevelCacheTest)
set_tests_properties(ModuleAreaLevelCacheTest PROPERTIES TIMEOUT 20)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
    "bool PlayerbotAI::IsInRealGuild()" "bool PlayerbotAI::HasPlayerRelation()" ModuleSocialGuild.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
    "    // Slow autonomous activity when no humans" "    // real guild always active" ModuleSocialPriority.inc)
extract_native_fragment("${CORE_ROOT}/src/game/SocialMgr.cpp"
    "std::vector<ObjectGuid> PlayerSocial::GetFriendGuids() const" "uint32 PlayerSocial::GetNumberOfSocialsWithFlag(" NativeSocialFriendGuids.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/RandomBotFacade.h"
    "    struct SocialSnapshot" "    // Startup only" ModuleSocialSnapshotDeclaration.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/PlayerbotRuntimeFacade.cpp"
    "void RandomBotFacade::SyncNativePlayers(" "bool RandomBotFacade::IsRandomBot(" ModuleSocialPopulation.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
    "bool PlayerbotAI::HasPlayerRelation(" "void PlayerbotAI::QueueChatResponse(" ModuleSocialRelation.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
    "bool PlayerbotAI::ChannelHasRealPlayer(" "/*\nenum ActivityType" ModuleChannelPresence.inc)
add_executable(ModuleSocialPopulationTest ModuleSocialPopulationTest.cpp)
target_compile_features(ModuleSocialPopulationTest PRIVATE cxx_std_17)
target_include_directories(ModuleSocialPopulationTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME ModuleSocialPopulationTest COMMAND ModuleSocialPopulationTest)
set_tests_properties(ModuleSocialPopulationTest PROPERTIES TIMEOUT 20)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/WorldBuffTravelActions.cpp"
    "bool WorldBuffTravelApplyAction::TrySummonFarAwayMembers(" "    uint8 warlockStep" ModuleWorldBuffCooldown.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/WorldBuffTravelActions.cpp"
    "    if (!didSummon && pendingCount == 0 && remainingToSummon == 0)" "\n}\n\nvoid WorldBuffTravelApplyAction::ApplyBuffsForStep" ModuleWorldBuffCooldownFinish.inc)
add_executable(ModuleWorldBuffCooldownTest ModuleWorldBuffCooldownTest.cpp)
target_compile_features(ModuleWorldBuffCooldownTest PRIVATE cxx_std_17)
target_include_directories(ModuleWorldBuffCooldownTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME ModuleWorldBuffCooldownTest COMMAND ModuleWorldBuffCooldownTest)
set_tests_properties(ModuleWorldBuffCooldownTest PROPERTIES TIMEOUT 20)

# Native lifecycle replacements for retired holder/provisioning implementations.
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/BotManager.cpp"
    "void BotManager::UpdateBots(" "void BotManager::OnWorldUpdate(" ModuleBotDispatch.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Handlers/CharacterCreation.cpp"
    "    WorldSession dummySession(" "\n}\n\n} // namespace CharacterCreation" NativeCharacterMaterialization.inc)
foreach(test ModuleBotDispatchTest NativeCharacterMaterializationTest)
    add_executable(${test} ${test}.cpp)
    target_compile_features(${test} PRIVATE cxx_std_17)
    target_include_directories(${test} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
    if(MSVC)
        target_compile_options(${test} PRIVATE /EHsc)
    endif()
    add_test(NAME ${test} COMMAND ${test})
    set_tests_properties(${test} PROPERTIES TIMEOUT 20)
endforeach()

# Item queries exercise native bodies against immutable populated/missing tables.
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/RandomItemMgr.cpp"
    "RandomItemList RandomItemMgr::Query(uint32 level, uint8" "void RandomItemMgr::BuildAmmoCache(" ModuleItemCacheEquip.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/RandomItemMgr.cpp"
    "uint32 RandomItemMgr::GetAmmo(" "void RandomItemMgr::BuildPotionCache(" ModuleItemCacheAmmo.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/RandomItemMgr.cpp"
    "uint32 RandomItemMgr::GetRandomPotion(" "uint32 RandomItemMgr::GetFood(" ModuleItemCachePotion.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/RandomItemMgr.cpp"
    "uint32 RandomItemMgr::GetRandomFood(" "void RandomItemMgr::BuildTradeCache(" ModuleItemCacheFood.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/RandomItemMgr.cpp"
    "uint32 RandomItemMgr::GetRandomTrade(" "void RandomItemMgr::LoadRandomEnchantments(" ModuleItemCacheTrade.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/RandomItemMgr.cpp"
    "uint32 RandomItemMgr::GetMinLevelFromCache(" "uint32 RandomItemMgr::GetBestRandomEnchantStatWeight(" ModuleItemCacheWeight.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/RandomItemMgr.cpp"
    "bool RandomItemMgr::HasStatWeight(" "bool RandomItemMgr::CanBuyFromVendor(" ModuleItemCacheHasWeight.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/RandomItemMgr.cpp"
    "std::vector<uint32> RandomItemMgr::GetUpgradeList(" "bool RandomItemMgr::HasStatWeight(" ModuleItemCacheUpgrade.inc)
add_executable(ModuleItemCacheReadTest ModuleItemCacheReadTest.cpp)
target_compile_features(ModuleItemCacheReadTest PRIVATE cxx_std_17)
target_include_directories(ModuleItemCacheReadTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}" "${CORE_ROOT}/modules/TortoiseBots/ai/playerbot")
add_test(NAME ModuleItemCacheReadTest COMMAND ModuleItemCacheReadTest)
set_tests_properties(ModuleItemCacheReadTest PROPERTIES TIMEOUT 20)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
    "void PlayerbotAI::SetJumpDestination(" "void PlayerbotAI::UpdateAI(uint32" ModuleJumpLifetime.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.h"
    "    void SetJumpTime(" "    bool CanMove();" ModuleJumpDeadline.inc)
add_executable(ModuleJumpLifetimeTest ModuleJumpLifetimeTest.cpp)
target_compile_features(ModuleJumpLifetimeTest PRIVATE cxx_std_17)
target_include_directories(ModuleJumpLifetimeTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}" "${CORE_ROOT}/src/shared")
add_test(NAME ModuleJumpLifetimeTest COMMAND ModuleJumpLifetimeTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/Event.cpp"
    "namespace ai\n{\nstruct EventOwnerIdentity" "// End event requester lifetime implementation." ModuleEventOwner.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/Trigger.h"
    "        virtual void ExternalEventForce(" "        virtual bool IsActive()" ModuleEventForce.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/triggers/WorldPacketTrigger.h"
    "        virtual void ExternalEvent(" "    };" ModuleEventPacketTrigger.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/triggers/ChatCommandTrigger.h"
    "        virtual void ExternalEvent(" "    };" ModuleEventChatTrigger.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/Engine.cpp"
    "bool Engine::ListenAndExecute(" "    bool actionExecuted = false;" ModuleEventExecuteGate.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/ReactionEngine.cpp"
    "bool ReactionEngine::ListenAndExecute(" "    bool actionExecuted = false;" ModuleEventReactionGate.inc)
add_executable(ModuleEventOwnerLifetimeTest ModuleEventOwnerLifetimeTest.cpp)
target_compile_features(ModuleEventOwnerLifetimeTest PRIVATE cxx_std_17)
target_include_directories(ModuleEventOwnerLifetimeTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/event-fixtures" "${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy")
add_test(NAME ModuleEventOwnerLifetimeTest COMMAND ModuleEventOwnerLifetimeTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.h"
    "class ChatCommandHolder\n" "class PlayerbotAI :" ModuleChatRequester.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
    "void PlayerbotAI::HandleCommands()" "void PlayerbotAI::UpdateAIInternal(" ModuleChatRequesterDrain.inc)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/GuildAcceptAction.cpp"
    "bool GuildAcceptAction::Execute(" "// End native guild actions." ModuleGuildAccept.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/GuildManagementActions.cpp"
    "bool GuildManageNearbyAction::isUseful()" "bool GuildLeaveAction::Execute(" ModuleGuildManageEligibility.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/GuildManagementActions.cpp"
    "bool GuildLeaveAction::Execute(" "// End native guild actions." ModuleGuildLeave.inc)
add_executable(ModuleGuildNativeResultTest ModuleGuildNativeResultTest.cpp)
target_compile_features(ModuleGuildNativeResultTest PRIVATE cxx_std_17)
target_include_directories(ModuleGuildNativeResultTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME ModuleGuildNativeResultTest COMMAND ModuleGuildNativeResultTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/Engine.cpp"
    "ActionResult Engine::ExecuteAction(" "void Engine::addStrategy(" ModuleEngineExplicit.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
    "bool PlayerbotAI::IsSafe(" "bool PlayerbotAI::DoSpecificAction(" ModuleNativeMapSafety.inc)
add_executable(ModuleNativeMapSafetyTest ModuleNativeMapSafetyTest.cpp)
target_compile_features(ModuleNativeMapSafetyTest PRIVATE cxx_std_17)
target_include_directories(ModuleNativeMapSafetyTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME ModuleNativeMapSafetyTest COMMAND ModuleNativeMapSafetyTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/BotWorldActions.cpp"
    "namespace TortoiseBots\n{" "// End bounded world action implementation." ModuleWorldActions.inc)
add_executable(ModuleWorldActionsTest ModuleWorldActionsTest.cpp)
target_compile_features(ModuleWorldActionsTest PRIVATE cxx_std_17)
target_include_directories(ModuleWorldActionsTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/event-fixtures" "${CORE_ROOT}/modules/TortoiseBots/runtime" "${CORE_ROOT}/src/shared")
if(MSVC)
    target_compile_options(ModuleWorldActionsTest PRIVATE /EHsc)
endif()
add_test(NAME ModuleWorldActionsTest COMMAND ModuleWorldActionsTest)
set_tests_properties(ModuleWorldActionsTest PROPERTIES TIMEOUT 20)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/MailAction.cpp"
    "    // Native mail collection result boundary." "    bool After(" ModuleMailCollect.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/InviteToGroupAction.cpp"
    "    bool InviteToGroupAction::Invite(" "    bool JoinGroupAction::Execute(" ModuleGroupInviteResult.inc)
foreach(test ModuleMailNativeResultTest ModuleGroupNativeResultTest)
    add_executable(${test} ${test}.cpp)
    target_compile_features(${test} PRIVATE cxx_std_17)
    target_include_directories(${test} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
    add_test(NAME ${test} COMMAND ${test})
endforeach()

extract_native_fragment("${CORE_ROOT}/src/game/Handlers/MailHandler.cpp"
    "        // Inventory merging can delete" "        CharacterDatabase.BeginTransaction" NativeMailDeliveryLifetime.inc)
add_executable(NativeMailDeliveryLifetimeTest NativeMailDeliveryLifetimeTest.cpp)
target_compile_features(NativeMailDeliveryLifetimeTest PRIVATE cxx_std_17)
target_include_directories(NativeMailDeliveryLifetimeTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
if(MSVC)
    target_compile_options(NativeMailDeliveryLifetimeTest PRIVATE /EHsc)
endif()
add_test(NAME NativeMailDeliveryLifetimeTest COMMAND NativeMailDeliveryLifetimeTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/AhAction.cpp"
    "bool AhAction::Execute(" "bool AhAction::ExecuteCommand(" ModuleAuctionActionOwner.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/GuildShareAhBuyAction.cpp"
    "bool GuildShareAhBuyAction::Execute(" "    std::map<uint32, uint32> neededItems" ModuleGuildAuctionOwner.inc)
add_executable(ModuleAuctionActionOwnerTest ModuleAuctionActionOwnerTest.cpp)
target_compile_features(ModuleAuctionActionOwnerTest PRIVATE cxx_std_17)
target_include_directories(ModuleAuctionActionOwnerTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
if(MSVC)
    target_compile_options(ModuleAuctionActionOwnerTest PRIVATE /EHsc)
endif()
add_test(NAME ModuleAuctionActionOwnerTest COMMAND ModuleAuctionActionOwnerTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/MailAction.cpp"
    "    bool processedAny = false;" "void MailProcessor::RemoveMail(" ModuleMailDispatchResult.inc)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/GuildManagementActions.h"
    "        // Native guild membership queries." "        uint16 opcode;" ModuleGuildMembershipQueries.inc)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/PlayerbotRuntimeFacade.cpp"
    "void RandomBotFacade::LoadAuctionPrices(" "void RandomBotFacade::RefreshAuctionPrices(" ModuleAuctionPricePublish.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/PlayerbotRuntimeFacade.cpp"
    "std::vector<AuctionEntry> RandomBotFacade::GetAhPrices(" "InventoryResult RandomBotFacade::CanEquipUnseenItem(" ModuleAuctionPriceRead.inc)
add_executable(ModuleAuctionPriceSnapshotTest ModuleAuctionPriceSnapshotTest.cpp)
target_compile_features(ModuleAuctionPriceSnapshotTest PRIVATE cxx_std_17)
target_include_directories(ModuleAuctionPriceSnapshotTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
if(MSVC)
    target_compile_options(ModuleAuctionPriceSnapshotTest PRIVATE /EHsc)
endif()
add_test(NAME ModuleAuctionPriceSnapshotTest COMMAND ModuleAuctionPriceSnapshotTest)
set_tests_properties(ModuleAuctionPriceSnapshotTest PROPERTIES TIMEOUT 20)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/BotManager.cpp"
    "void BotManager::DrainPendingBotRemovals(" "BotRecord* BotManager::FindBot(" ModuleNativeRemoval.inc)
add_executable(ModuleNativeRemovalTest ModuleNativeRemovalTest.cpp)
target_compile_features(ModuleNativeRemovalTest PRIVATE cxx_std_17)
target_include_directories(ModuleNativeRemovalTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}" "${CORE_ROOT}/modules/TortoiseBots/runtime")
add_test(NAME ModuleNativeRemovalTest COMMAND ModuleNativeRemovalTest)
set_tests_properties(ModuleNativeRemovalTest PROPERTIES TIMEOUT 20)

extract_native_fragment("${CORE_ROOT}/src/game/WorldSession.cpp"
    "    // No idle kick and no socket-loss disconnect; lifetime is registry-owned." "    if(CharacterScreenIdleKick" NativeHeadlessLogoutUpdate.inc)
extract_native_fragment("${CORE_ROOT}/src/game/WorldSession.h"
    "        bool ShouldLogOut(time_t currTime) const" "        void SetShouldBackupCharacters" NativeLogoutDeadline.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
    "    // Session logout is native state, not a combat stun." "    SC_PHASE(\"UpdateAIInternal.botOutgoingPackets\"" ModuleLogoutPause.inc)
add_executable(NativeHeadlessLogoutTest NativeHeadlessLogoutTest.cpp)
target_compile_features(NativeHeadlessLogoutTest PRIVATE cxx_std_17)
target_include_directories(NativeHeadlessLogoutTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME NativeHeadlessLogoutTest COMMAND NativeHeadlessLogoutTest)

extract_native_fragment("${CORE_ROOT}/src/game/Maps/PathFinder.cpp"
    "bool PathInfo::UpdateForCaster(" "float PathInfo::Length(" NativePathPostProcessing.inc)
add_executable(NativePathPostProcessingTest NativePathPostProcessingTest.cpp)
target_compile_features(NativePathPostProcessingTest PRIVATE cxx_std_17)
target_include_directories(NativePathPostProcessingTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME NativePathPostProcessingTest COMMAND NativePathPostProcessingTest)

file(READ "${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/RandomBotUpdateAction.h" RANDOM_UPDATE_SOURCE)
string(REGEX REPLACE "#pragma once|#include[^\n]*" "" RANDOM_UPDATE_SOURCE "${RANDOM_UPDATE_SOURCE}")
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/ModuleRandomUpdateLeader.inc" "${RANDOM_UPDATE_SOURCE}")
add_executable(ModuleRandomUpdateLeaderTest ModuleRandomUpdateLeaderTest.cpp)
target_compile_features(ModuleRandomUpdateLeaderTest PRIVATE cxx_std_17)
target_include_directories(ModuleRandomUpdateLeaderTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME ModuleRandomUpdateLeaderTest COMMAND ModuleRandomUpdateLeaderTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/PlayerbotAIStorage.h"
    "    PlayerbotAI* GetAI(Player* player) const;" "\nprivate:" ModuleAIIdentityLookup.inc)
file(READ "${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/SecurityCheckAction.h" SECURITY_CHECK_SOURCE)
string(REGEX REPLACE "#pragma once|#include[^\n]*" "" SECURITY_CHECK_SOURCE "${SECURITY_CHECK_SOURCE}")
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/ModuleSecurityCheckClass.inc" "${SECURITY_CHECK_SOURCE}")
file(READ "${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/SecurityCheckAction.cpp" SECURITY_CHECK_SOURCE)
string(FIND "${SECURITY_CHECK_SOURCE}" "bool SecurityCheckAction::isUseful()" SECURITY_CHECK_BEGIN)
string(SUBSTRING "${SECURITY_CHECK_SOURCE}" ${SECURITY_CHECK_BEGIN} -1 SECURITY_CHECK_SOURCE)
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/ModuleSecurityCheck.inc" "${SECURITY_CHECK_SOURCE}")
add_executable(ModuleSecurityCheckTest ModuleSecurityCheckTest.cpp)
target_compile_features(ModuleSecurityCheckTest PRIVATE cxx_std_17)
target_include_directories(ModuleSecurityCheckTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME ModuleSecurityCheckTest COMMAND ModuleSecurityCheckTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/PlayerbotRuntimeFacade.cpp"
    "bool RandomBotFacade::Revive(" "void RandomBotFacade::PrintTeleportCache(" ModuleNativeAdminRevive.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/PlayerbotRuntimeFacade.cpp"
    "bool RandomBotFacade::Refresh(" "bool RandomBotFacade::UpdateGearSpells(" ModuleNativeRefresh.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Objects/Player.cpp"
    "void Player::ModifyMoney(" "void Player::MoneyChanged(" NativeRefreshMoney.inc)
add_executable(ModuleNativeRefreshTest ModuleNativeRefreshTest.cpp)
target_compile_features(ModuleNativeRefreshTest PRIVATE cxx_std_17)
target_include_directories(ModuleNativeRefreshTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME ModuleNativeRefreshTest COMMAND ModuleNativeRefreshTest)


extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
    "void PlayerbotAI::ReconcileMasterAndPosture()" "void PlayerbotAI::ReInitCurrentEngine()" ModuleMasterReconciliation.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
    "    struct ActivityOverrideScope" "    if (!bot->IsInWorld() || bot->IsBeingTeleported() || aiObjectContext" ModuleActivityOverrideScope.inc)
add_executable(ModuleMasterReconciliationTest ModuleMasterReconciliationTest.cpp)
target_compile_features(ModuleMasterReconciliationTest PRIVATE cxx_std_17)
target_include_directories(ModuleMasterReconciliationTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME ModuleMasterReconciliationTest COMMAND ModuleMasterReconciliationTest)

extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/PlayerbotRuntimeFacade.cpp"
    "bool RandomBotFacade::ProcessBot(" "bool RandomBotFacade::GetNamedLocation(" ModuleNativeMaintenanceEligibility.inc)
add_executable(ModuleNativeMaintenanceEligibilityTest ModuleNativeMaintenanceEligibilityTest.cpp)
target_compile_features(ModuleNativeMaintenanceEligibilityTest PRIVATE cxx_std_17)
target_include_directories(ModuleNativeMaintenanceEligibilityTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME ModuleNativeMaintenanceEligibilityTest COMMAND ModuleNativeMaintenanceEligibilityTest)

extract_native_fragment("${CORE_ROOT}/src/game/Handlers/MiscHandler.cpp"
    "void WorldSession::HandleReclaimCorpseOpcode(" "void WorldSession::HandleResurrectResponseOpcode(" NativeCorpseReclaim.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Handlers/NPCHandler.cpp"
    "void WorldSession::SendSpiritResurrect()" "void WorldSession::HandleBinderActivateOpcode(" NativeSpiritResurrection.inc)
extract_native_fragment("${CORE_ROOT}/src/game/Objects/Player.cpp"
    "            ResurrectPlayer(1.0f);\n            if (IsAlive())" "            // Refused resurrection retains" NativeEntryResurrection.inc)
add_executable(NativeResurrectionResultTest NativeResurrectionResultTest.cpp)
target_compile_features(NativeResurrectionResultTest PRIVATE cxx_std_17)
target_include_directories(NativeResurrectionResultTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME NativeResurrectionResultTest COMMAND NativeResurrectionResultTest)


# Copied guild decision facts refresh only on the world owner.
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/Value.h"
    "    template<class T>\n    class Value" "    template <class T> class SingleCalculatedValue" ModuleCalculatedValueBase.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/WorldCalculatedValue.h"
    "namespace ai\n{" "// End world calculated value implementation." ModuleWorldValue.inc)
add_executable(ModuleWorldValueTest ModuleWorldValueTest.cpp)
target_compile_features(ModuleWorldValueTest PRIVATE cxx_std_17)
target_include_directories(ModuleWorldValueTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
if(MSVC)
    target_compile_options(ModuleWorldValueTest PRIVATE /EHsc)
endif()
add_test(NAME ModuleWorldValueTest COMMAND ModuleWorldValueTest)
set_tests_properties(ModuleWorldValueTest PROPERTIES TIMEOUT 15)


extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
    "bool PlayerbotAI::EnterWorldControl(" "void PlayerbotAI::CancelLogout(" ModuleWorldControl.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/values/GuildValues.h"
    "    struct GuildShareTarget" "    class GuildShareTargetValue" ModuleGuildShareTarget.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/GuildShareItemAction.cpp"
    "bool GuildShareItemAction::Execute(" "    std::vector<Item*> items" ModuleGuildRecipientGate.inc)
foreach(native_boundary_test ModuleWorldControlTest ModuleGuildRecipientTest)
    add_executable(${native_boundary_test} ${native_boundary_test}.cpp)
    target_compile_features(${native_boundary_test} PRIVATE cxx_std_17)
    target_include_directories(${native_boundary_test} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
    if(MSVC)
        target_compile_options(${native_boundary_test} PRIVATE /EHsc)
    endif()
    add_test(NAME ${native_boundary_test} COMMAND ${native_boundary_test})
    set_tests_properties(${native_boundary_test} PROPERTIES TIMEOUT 15)
endforeach()


extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/NativeGuildTrades.cpp"
    "namespace TortoiseBots\n{" "// End native guild trade implementation." ModuleNativeGuildTrades.inc)
add_executable(ModuleNativeGuildTradesTest ModuleNativeGuildTradesTest.cpp)
target_compile_features(ModuleNativeGuildTradesTest PRIVATE cxx_std_17)
target_include_directories(ModuleNativeGuildTradesTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}" "${CORE_ROOT}/src/shared" "${CORE_ROOT}/modules/TortoiseBots/runtime")
if(MSVC)
    target_compile_options(ModuleNativeGuildTradesTest PRIVATE /EHsc)
endif()
add_test(NAME ModuleNativeGuildTradesTest COMMAND ModuleNativeGuildTradesTest)
set_tests_properties(ModuleNativeGuildTradesTest PROPERTIES TIMEOUT 15)


extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
    "bool PlayerbotAI::IsSafe(" "bool PlayerbotAI::DoSpecificAction(" ModulePartyIsSafe.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/values/GroupValues.cpp"
    "bool IsNearLeaderValue::Calculate()" "uint32 GroupBoolCountValue::Calculate()" ModulePartyNear.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/values/GroupValues.cpp"
    "uint32 GroupBoolCountValue::Calculate()" "bool GroupBoolANDValue::Calculate()" ModulePartyCount.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/values/StatsValues.cpp"
    "bool IsInCombatValue::Calculate()" "uint8 BagSpaceValue::Calculate()" ModulePartyCombat.inc)
foreach(party_pair "AoeHealValues.cpp|uint8 AoeHealValue::Calculate()|ModulePartyAoe.inc" "LineTargetValue.cpp|Unit* LineTargetValue::Calculate()|ModulePartyLine.inc")
    string(REPLACE "|" ";" party_parts "${party_pair}")
    list(GET party_parts 0 party_source)
    list(GET party_parts 1 party_start)
    list(GET party_parts 2 party_output)
    file(READ "${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/values/${party_source}" party_text)
    string(FIND "${party_text}" "${party_start}" party_begin)
    string(SUBSTRING "${party_text}" ${party_begin} -1 party_text)
    file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/${party_output}" "${party_text}")
endforeach()
add_executable(ModulePartyLocalityTest ModulePartyLocalityTest.cpp)
target_compile_features(ModulePartyLocalityTest PRIVATE cxx_std_17)
target_include_directories(ModulePartyLocalityTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
if(MSVC)
    target_compile_options(ModulePartyLocalityTest PRIVATE /EHsc)
endif()
add_test(NAME ModulePartyLocalityTest COMMAND ModulePartyLocalityTest)


extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/CheckMailAction.cpp"
    "bool CheckMailAction::Execute(" "// End native automatic mail return." ModuleAutomaticMailReturn.inc)
add_executable(ModuleAutomaticMailReturnTest ModuleAutomaticMailReturnTest.cpp)
target_compile_features(ModuleAutomaticMailReturnTest PRIVATE cxx_std_17)
target_include_directories(ModuleAutomaticMailReturnTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME ModuleAutomaticMailReturnTest COMMAND ModuleAutomaticMailReturnTest)


extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/Value.h"
    "    template<class T> class MemoryCalculatedValue" "    template<class T> class LogCalculatedValue" ModuleMemoryCalculatedBase.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
    "void PlayerbotAI::CancelLogout(" "void PlayerbotAI::HandleTeleportAck()" ModuleWorldLogoutCancellation.inc)
add_executable(ModuleWorldLogoutCancellationTest ModuleWorldLogoutCancellationTest.cpp)
target_compile_features(ModuleWorldLogoutCancellationTest PRIVATE cxx_std_17)
target_include_directories(ModuleWorldLogoutCancellationTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME ModuleWorldLogoutCancellationTest COMMAND ModuleWorldLogoutCancellationTest)


extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/FollowActions.cpp"
    "bool FollowAction::RequiresWorldOwner() const" "bool FollowAction::Execute(" ModuleFollowDomain.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/actions/MovementActions.cpp"
    "bool MovementAction::Follow(Unit* target, float distance, float angle)" "    MotionMaster &mm = *bot->GetMotionMaster();" ModuleFollowPositionGate.inc)
add_executable(ModuleFollowDomainTest ModuleFollowDomainTest.cpp)
target_compile_features(ModuleFollowDomainTest PRIVATE cxx_std_17)
target_include_directories(ModuleFollowDomainTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME ModuleFollowDomainTest COMMAND ModuleFollowDomainTest)


extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/runtime/PlayerbotAIAdapter.cpp"
    "bool PlayerbotAIAdapter::CanUpdatePlayer(" "bool PlayerbotAIAdapter::IsUsable()" ModuleNativeMapAdmission.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/host/BotPlayerAdapter.cpp"
    "bool BotPlayerAdapter::IsAIUpdateDue(" "void BotPlayerAdapter::OnLogin(" ModuleNativeMapHooks.inc)
add_executable(ModuleNativeMapHookTest ModuleNativeMapHookTest.cpp)
target_compile_features(ModuleNativeMapHookTest PRIVATE cxx_std_17)
target_include_directories(ModuleNativeMapHookTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME ModuleNativeMapHookTest COMMAND ModuleNativeMapHookTest)


extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
    "bool PlayerbotAI::TellPlayerNoFacing(Player* player, std::string" "    if(!player)" ModuleWorldMessageNoFacing.inc)
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/PlayerbotAI.cpp"
    "bool PlayerbotAI::TellPlayer(Player* player, std::string" "    if (!TellPlayerNoFacing(" ModuleWorldMessageFacing.inc)
add_executable(ModuleWorldMessageTest ModuleWorldMessageTest.cpp)
target_compile_features(ModuleWorldMessageTest PRIVATE cxx_std_17)
target_include_directories(ModuleWorldMessageTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME ModuleWorldMessageTest COMMAND ModuleWorldMessageTest)


file(READ "${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/triggers/GroupInvitationTrigger.h" NATIVE_INVITE_TRIGGER)
string(REGEX REPLACE "#pragma once|#include[^\n]*" "" NATIVE_INVITE_TRIGGER "${NATIVE_INVITE_TRIGGER}")
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/ModulePendingGroupInviteType.inc" "${NATIVE_INVITE_TRIGGER}")
extract_native_fragment("${CORE_ROOT}/modules/TortoiseBots/ai/playerbot/strategy/Trigger.cpp"
    "Event Trigger::Check()" "Value<Unit*>* Trigger::GetTargetValue()" ModulePendingGroupInviteCheck.inc)
add_executable(ModulePendingGroupInviteTest ModulePendingGroupInviteTest.cpp)
target_compile_features(ModulePendingGroupInviteTest PRIVATE cxx_std_17)
target_include_directories(ModulePendingGroupInviteTest PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
add_test(NAME ModulePendingGroupInviteTest COMMAND ModulePendingGroupInviteTest)

# Imported Arch4 storage keeps native Turtle lists and all 231 aura types.
add_executable(Arch4StorageTest Arch4StorageTest.cpp)
target_compile_features(Arch4StorageTest PRIVATE cxx_std_17)
target_include_directories(Arch4StorageTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../src/shared)
add_test(NAME Arch4StorageTest COMMAND Arch4StorageTest)
if(WIN32 AND MANTECH_DEV_DIAGNOSTICS)
  add_executable(Arch4DiagnosticsTest Arch4DiagnosticsTest.cpp ${CMAKE_CURRENT_SOURCE_DIR}/../../src/shared/PerfStats.cpp)
  target_compile_features(Arch4DiagnosticsTest PRIVATE cxx_std_17)
  target_compile_definitions(Arch4DiagnosticsTest PRIVATE MANTECH_DEV_DIAGNOSTICS)
  target_include_directories(Arch4DiagnosticsTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../src/shared)
  target_link_libraries(Arch4DiagnosticsTest PRIVATE psapi)
  add_test(NAME Arch4DiagnosticsTest COMMAND Arch4DiagnosticsTest)
  add_executable(Arch4ExecutorDiagnosticsTest Arch4ExecutorDiagnosticsTest.cpp ${CMAKE_CURRENT_SOURCE_DIR}/../../src/shared/PerfStats.cpp)
  target_compile_features(Arch4ExecutorDiagnosticsTest PRIVATE cxx_std_17)
  target_compile_definitions(Arch4ExecutorDiagnosticsTest PRIVATE MANTECH_DEV_DIAGNOSTICS)
  target_include_directories(Arch4ExecutorDiagnosticsTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../src/shared)
  target_link_libraries(Arch4ExecutorDiagnosticsTest PRIVATE psapi)
  add_test(NAME Arch4ExecutorDiagnosticsTest COMMAND Arch4ExecutorDiagnosticsTest)

endif()
if(WIN32 AND MANTECH_PROFILE_ALLOCATIONS)
  add_executable(Arch4AllocationTest Arch4AllocationTest.cpp ${CMAKE_CURRENT_SOURCE_DIR}/../../src/mangosd/AllocationProfile.cpp)
  target_compile_features(Arch4AllocationTest PRIVATE cxx_std_17)
  target_include_directories(Arch4AllocationTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../src/shared)
  target_link_libraries(Arch4AllocationTest PRIVATE dbghelp)
  add_test(NAME Arch4AllocationTest COMMAND Arch4AllocationTest)
endif()

# Source-extracted Arch4 behavior/lifetime tests; fixtures mock native boundaries.
if(MSVC)
  find_package(Python3 COMPONENTS Interpreter QUIET)
  if(Python3_Interpreter_FOUND)
    add_test(NAME Arch4PortRegressions COMMAND ${Python3_EXECUTABLE}
      ${CMAKE_CURRENT_SOURCE_DIR}/arch4/run_port_regressions.py
      --output ${CMAKE_CURRENT_BINARY_DIR}/arch4-port-tests --cxx ${CMAKE_CXX_COMPILER})
    set_tests_properties(Arch4PortRegressions PROPERTIES TIMEOUT 180 ENVIRONMENT "PYTHONUTF8=1")
  endif()
endif()
if(MSVC AND Python3_Interpreter_FOUND)
  add_test(NAME TurtleBuild90Fixes COMMAND ${Python3_EXECUTABLE}
    ${CMAKE_CURRENT_SOURCE_DIR}/run_turtle_build90_fixes_test.py
    --root ${CMAKE_CURRENT_SOURCE_DIR}/../..
    --output ${CMAKE_CURRENT_BINARY_DIR}/turtle-build90-fixes)
  set_tests_properties(TurtleBuild90Fixes PROPERTIES TIMEOUT 90 ENVIRONMENT "PYTHONUTF8=1")
endif()
