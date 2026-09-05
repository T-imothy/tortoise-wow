#pragma once
#include <atomic>
#include <cstdint>
#include <ctime>

// Object lifetime is independent of the cached calculation's refresh period.
class IdleResidency
{
public:
    explicit IdleResidency(time_t now = time(nullptr)) : m_lastUse(now) {}
    void Touch(time_t now)
    {
        if (m_lastUse.load(std::memory_order_relaxed) != now)
            m_lastUse.store(now, std::memory_order_relaxed);
    }
    bool UnusedFor(time_t now, uint32_t seconds) const
    {
        time_t const used = m_lastUse.load(std::memory_order_relaxed);
        return now >= used && uint64_t(now - used) >= seconds;
    }
private:
    std::atomic<time_t> m_lastUse;
};
