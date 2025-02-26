#include "w_time.h"

namespace engine
{

WTime::WTime()
    : WTime(0.0f)
{
}

WTime::WTime(float time)
    : m_time(time)
{
}

float WTime::seconds() const noexcept
{
    return m_time;
}

float WTime::milliseconds() const noexcept
{
    return m_time * 1000.0f;
}

float WTime::minutes() const noexcept
{
    return m_time / 60.0f;
}

WTime WTime::operator+(const WTime & other) const noexcept
{
    return WTime(m_time + other.m_time);
}

WTime WTime::operator-(const WTime & other) const noexcept
{
    return WTime(m_time - other.m_time);
}

WTime WTime::operator*(const float scale) const noexcept
{
    return WTime(m_time * scale);
}

WTime WTime::operator/(const float scale) const noexcept
{
    return WTime(m_time / scale);
}

WTime & WTime::operator+=(const WTime & other) noexcept
{
    m_time += other.m_time;
    return *this;
}

WTime & WTime::operator-=(const WTime & other) noexcept
{
    m_time -= other.m_time;
    return *this;
}

WTime & WTime::operator*=(const float scale) noexcept
{
    m_time *= scale;
    return *this;
}

WTime & WTime::operator/=(const float scale) noexcept
{
    m_time /= scale;
    return *this;
}

bool WTime::operator==(const WTime & other) const noexcept
{
    return m_time == other.m_time;
}

bool WTime::operator!=(const WTime & other) const noexcept
{
    return !(*this == other);
}

bool WTime::operator<(const WTime & other) const noexcept
{
    return m_time < other.m_time;
}

bool WTime::operator<=(const WTime & other) const noexcept
{
    return !(other < *this);
}

bool WTime::operator>(const WTime & other) const noexcept
{
    return other < *this;
}

bool WTime::operator>=(const WTime & other) const noexcept
{
    return !(*this < other);
}

} // namespace engine
