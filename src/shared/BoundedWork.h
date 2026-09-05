#pragma once

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <unordered_map>
#include <unordered_set>

// Scheduling metadata only: never owns game objects or crosses map ownership.
namespace BoundedWork
{
inline uint32_t Phase(uint32_t id, uint32_t interval)
{
    id ^= id >> 16;
    id *= 0x7feb352dU;
    id ^= id >> 15;
    id *= 0x846ca68bU;
    id ^= id >> 16;
    return interval ? id % interval : 0;
}

class Deadlines
{
public:
    bool Due(uint32_t id, uint32_t now, uint32_t interval)
    {
        auto entry = m_last.try_emplace(id, now - Phase(id, interval));
        return uint32_t(now - entry.first->second) >= interval;
    }
    void Served(uint32_t id, uint32_t now) { m_last[id] = now; }
    template<class Predicate> void Prune(Predicate present)
    {
        for (auto it = m_last.begin(); it != m_last.end();)
            if (!present(it->first)) it = m_last.erase(it); else ++it;
    }
    size_t Size() const { return m_last.size(); }
private:
    std::unordered_map<uint32_t, uint32_t> m_last;
};

class UniqueQueue
{
public:
    void Push(uint32_t id)
    {
        if (m_present.insert(id).second) m_queue.push_back(id);
    }
    uint32_t Pop()
    {
        uint32_t id = m_queue.front();
        m_queue.pop_front();
        m_present.erase(id);
        return id;
    }
    size_t Size() const { return m_queue.size(); }
    void Clear() { m_queue.clear(); m_present.clear(); }
private:
    std::deque<uint32_t> m_queue;
    std::unordered_set<uint32_t> m_present;
};

class Budget
{
public:
    explicit Budget(uint32_t milliseconds, uint32_t count = 0) :
        m_start(std::chrono::steady_clock::now()), m_ms(milliseconds), m_count(count) {}
    bool Exhausted(size_t completed) const
    {
        // Always admit one job: a small budget must never permanently starve it.
        return completed && ((m_count && completed >= m_count) ||
            (m_ms && std::chrono::steady_clock::now() - m_start >= std::chrono::milliseconds(m_ms)));
    }
private:
    std::chrono::steady_clock::time_point m_start;
    uint32_t m_ms;
    uint32_t m_count;
};
}
