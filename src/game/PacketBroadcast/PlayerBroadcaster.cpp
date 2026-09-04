#include "PlayerBroadcaster.h"
#include "MovementBroadcaster.h"
#include "World.h"
#include "Player.h"
#include <algorithm>

uint32 PlayerBroadcaster::num_bcaster_created = 0;
uint32 PlayerBroadcaster::num_bcaster_deleted = 0;
std::atomic<uint64> PlayerBroadcaster::s_coalescedPackets{0};
std::atomic<uint64> PlayerBroadcaster::s_droppedPackets{0};

PlayerBroadcaster::PlayerBroadcaster(WorldSocket* w_socket, const ObjectGuid& self, std::size_t max_queue) :
    MAX_QUEUE_SIZE(max_queue), m_socket(w_socket), m_self(self), instanceId(0), lastUpdatePackets(0)
{
    if (m_socket)
        m_socket->AddReference();

    m_queue.reserve(max_queue);
    ++num_bcaster_created;
}

void PlayerBroadcaster::ChangeSocket(WorldSocket* new_socket)
{
    if (m_socket)
        m_socket->RemoveReference();

    if (new_socket)
        new_socket->AddReference();

    m_socket = new_socket;
}

void PlayerBroadcaster::AddListener(Player const* player)
{
    ASSERT(player);
    if (player->GetObjectGuid() == m_self)
        return;

    const std::lock_guard<std::mutex> guard(m_listeners_lock);
    m_listeners[player->GetObjectGuid()] = player->m_broadcaster;
}

void PlayerBroadcaster::RemoveListener(Player const* player)
{
    ASSERT(player);
    const std::lock_guard<std::mutex> guard(m_listeners_lock);
    m_listeners.erase(player->GetObjectGuid());
}

void PlayerBroadcaster::ClearListeners()
{
    const std::lock_guard<std::mutex> guard(m_listeners_lock);
    m_listeners.clear();
}

void PlayerBroadcaster::SendPacket(const WorldPacket& packet)
{
    if (m_socket)
        m_socket->SendPacket(packet);
}

void PlayerBroadcaster::ProcessQueue(uint32& num_packets)
{
    std::scoped_lock lock{ m_queue_lock, m_listeners_lock };
    if (m_queue.empty())
        return;

    auto queue = std::move(m_queue);

    lastUpdatePackets = queue.size() * m_listeners.size();
    num_packets += lastUpdatePackets;

    for (auto& data : queue)
    {
        // Send to self?
        if (data.sendToSelf && data.except != GetGUID())
            SendPacket(data.packet);

        for (const auto& itr : m_listeners)
        {
            if (itr.first == data.except)
                continue;

            itr.second->SendPacket(data.packet);
        }
    }
}

void PlayerBroadcaster::QueuePacket(WorldPacket packet, bool self, ObjectGuid except)
{
    BroadcastData data;
    data.packet = std::move(packet);
    data.sendToSelf = self;
    data.except = except;

    std::scoped_lock guard(m_queue_lock);

    // Keep movement fan-out bounded. Prefer coalescing replaceable movement;
    // if the queue contains only ordering-sensitive packets, discard the oldest
    // broadcast rather than allowing one slow listener to consume unbounded RAM.
    if (m_queue.size() >= MAX_QUEUE_SIZE)
    {
        if (CanSkipPacket(data.packet.GetOpcode()))
        {
            for (auto itr = m_queue.rbegin(); itr != m_queue.rend(); ++itr)
            {
                if (CanSkipPacket(itr->packet.GetOpcode()))
                {
                    *itr = std::move(data);
                    s_coalescedPackets.fetch_add(1, std::memory_order_relaxed);
                    return;
                }
            }
        }

        auto replaceable = std::find_if(m_queue.begin(), m_queue.end(), [](BroadcastData const& queued)
        {
            return CanSkipPacket(queued.packet.GetOpcode());
        });
        if (replaceable != m_queue.end())
            m_queue.erase(replaceable);
        else
            m_queue.erase(m_queue.begin());
        s_droppedPackets.fetch_add(1, std::memory_order_relaxed);
    }

    m_queue.emplace_back(std::move(data));
}

uint64 PlayerBroadcaster::ConsumeCoalescedPackets()
{
    return s_coalescedPackets.exchange(0, std::memory_order_relaxed);
}

uint64 PlayerBroadcaster::ConsumeDroppedPackets()
{
    return s_droppedPackets.exchange(0, std::memory_order_relaxed);
}

ObjectGuid PlayerBroadcaster::GetGUID() const
{
    return m_self;
}

void PlayerBroadcaster::FreeAtLogout()
{
    if (m_socket)
    {
        m_socket->RemoveReference();
        m_socket = nullptr;
    }

    const std::scoped_lock lock{ m_queue_lock, m_listeners_lock };
    m_queue.clear();
    m_listeners.clear();
    
}

PlayerBroadcaster::~PlayerBroadcaster()
{
    if (m_socket)
        m_socket->RemoveReference();

    ++num_bcaster_deleted;
}
