            if (guid1 != bot->GetObjectGuid()) // do not reply to self
            {
                // try to always reply to real player
                time_t lastChat = GetAiObjectContext()->GetValue<time_t>("last said", "chat")->Get();
                bool isPaused = time(0) < lastChat;
                bool shouldReply = false;
                bool isFromFreeBot = false;
                sObjectMgr.GetPlayerNameByGUID(guid1, name);
                uint32 accountId = sObjectMgr.GetPlayerAccountIdByGUID(guid1);
                isFromFreeBot = sPlayerbotAIConfig.IsInRandomAccountList(accountId);
                if (!isFromFreeBot)
                {

                    isFromFreeBot = sPlayerbotAIConfig.IsFreeAltBot(guid1);

                    if (isFromFreeBot)
                    {
                        Player* player = sObjectMgr.GetPlayer(guid1);
                        if (player && IsRealPlayer(player))
                            isFromFreeBot = false;
                    }
                }

                bool isMentioned = message.find(bot->GetName()) != std::string::npos;
                

                ChatChannelSource chatChannelSource = GetChatChannelSource(bot, msgtype, chanName);

                if (!isAiChat || isFromFreeBot)
                {
                    // random bot speaks, chat CD
                    if ((isFromFreeBot || isAiChat) && isPaused)
                        return;

                    // BG: react only if mentioned or if not channel and real player spoke
                    if (bot->InBattleGround() && !(isMentioned || (msgtype != CHAT_MSG_CHANNEL && !isFromFreeBot)))
                        return;

                    if (HasRealPlayerMaster() && guid1 != GetMaster()->GetObjectGuid())
                        return;

                    if (lang == LANG_ADDON)
                        return;

                    if (boost::algorithm::istarts_with(message, sPlayerbotAIConfig.toxicLinksPrefix)
                        && (GetChatHelper()->ExtractAllItemIds(message).size() > 0 || GetChatHelper()->ExtractAllQuestIds(message).size() > 0)
                        && sPlayerbotAIConfig.toxicLinksRepliesChance)
                    {
                        if (urand(0, 50) > 0 || urand(1, 100) > sPlayerbotAIConfig.toxicLinksRepliesChance)
                        {
                            return;
                        }
                    }
                    else if ((GetChatHelper()->ExtractAllItemIds(message).count(19019) && sPlayerbotAIConfig.thunderfuryRepliesChance))
                    {
                        if (urand(0, 60) > 0 || urand(1, 100) > sPlayerbotAIConfig.thunderfuryRepliesChance)
                        {
                            return;
                        }
                    }
                    else
                    {
                        if (isFromFreeBot && urand(0, 20))
                            return;

                        if (msgtype == CHAT_MSG_GUILD && (!sPlayerbotAIConfig.guildRepliesRate || urand(1, 100) >= sPlayerbotAIConfig.guildRepliesRate))
                            return;

                        if (!isFromFreeBot)
                        {
                            if (!isMentioned && urand(0, 4))
                                return;
                        }
                        else
                        {
                            if (urand(0, 20 + 10 * isMentioned))
                                return;
                        }
                    }
                }

                MANGOS_ASSERT(!message.empty());     
                QueueChatResponse(msgtype, guid1, ObjectGuid(), message, chanName, name, isAiChat);
                GetAiObjectContext()->GetValue<time_t>("last said", "chat")->Set(time(0) + urand(5, 25));

                return;
            }

