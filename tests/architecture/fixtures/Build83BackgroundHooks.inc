        bool IsAIUpdateDue(Player* player, uint32 diff) override
        {
            if (!sPlayerbotAIConfig.enabled)
                return false;
            if (PlayerbotAI* ai = GetBotAI(player))
            {
                // Consume elapsed time here only when no AI call will run.
                // Due work leaves the remaining delay for UpdateAI to consume.
                if (ai->HasPendingTransition() || ai->GetAIInternalUpdateDelay() <= diff)
                    return true;
                ai->AdvanceMinimalUpdateDelay(diff);
                return false;
            }
            return false;
        }

        void OnAIUpdate(Player* player, uint32 diff, bool minimal) override
        {
            ai::WorldActions::MapScope mapOwner;
            if (sPlayerbotAIConfig.enabled)
                if (PlayerbotAI* ai = GetBotAI(player))
                {
                    Map* const map = player->FindMap();
                    ObjectGuid const guid = player->GetObjectGuid();
                    uint64 const generation = player->GetMapWorkGeneration();
                    ai->UpdateAI(diff, minimal);
                    // AI may transfer/unlink its player. Resolve again under
                    // the joined map owner before applying the idle floor.
                    Player* const current = map ? map->GetPlayer(guid) : nullptr;
                    if (minimal && current && current->IsInWorld() && current->FindMap() == map &&
                        current->GetMapWorkGeneration() == generation && GetBotAI(current) == ai &&
                        !current->IsInCombat() && !ai->HasRealPlayerMaster() && !ai->HasPendingTransition())
                    {
                        static uint32 const jitter = uint32(std::max(0, std::min(60000,
                            sConfig.GetIntDefault("MapUpdate.IdleBotJitterMs", 4000))));
                        ai->SetNextCheckDelay(BackgroundAI::NextMinimalDelay(ai->GetAIInternalUpdateDelay(),
                            sPlayerbotAIConfig.passiveDelay, sPlayerbotAIConfig.reactDelay,
                            current->GetGUIDLow(), jitter));
                    }
                }
        }