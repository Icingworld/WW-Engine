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

WTime WTimer::elapsed()
{
    return WTime(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - m_start).count() / 1000.0f);
}

} // namespace engine
