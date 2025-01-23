#include "ww_timer.h"

namespace engine
{

Timer::Timer()
{
    reset();
}

void Timer::reset()
{
    m_start = std::chrono::high_resolution_clock::now();
}

float Timer::elapsed()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - m_start).count() / 1000.0f;
}

float Timer::elapsedMillis()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - m_start).count();
}

} // namespace engine
