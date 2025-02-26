#include "w_timer.h"

namespace engine
{

WTimer::WTimer()
{
    reset();
}

void WTimer::reset()
{
    m_start = std::chrono::high_resolution_clock::now();
}

float WTimer::elapsed()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - m_start).count() / 1000.0f;
}

float WTimer::elapsedMillis()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - m_start).count();
}

} // namespace engine
