void Channel::SendToAll(WorldPacket *data, ObjectGuid guid)
{
    MANTECH_DIAG_SCOPE(Packet, 32, "channel_broadcast");
    for (const auto& itr : m_players)
    {
        if (PlayerPointer pPlayer = GetPlayer(itr.first))
            if (!pPlayer->GetSocial()->HasIgnore(guid))
                pPlayer->GetSession()->SendPacket(data);
    }
}
