#pragma once

namespace engine
{

/**
 * @brief 时间
 */
class WTime final
{
private:
    float m_time;   // 秒数

public:
    WTime();

    WTime(float time);

    ~WTime() = default;

public:
    /**
     * @brief 以秒数获取时间
     */
    float seconds() const noexcept;

    /**
     * @brief 以毫秒数获取时间
     */
    float milliseconds() const noexcept;

    /**
     * @brief 以分钟数获取时间
     */
    float minutes() const noexcept;

public:
    WTime operator+(const WTime & other) const noexcept;

    WTime operator-(const WTime & other) const noexcept;

    WTime operator*(const float scale) const noexcept;

    WTime operator/(const float scale) const noexcept;

    WTime & operator+=(const WTime & other) noexcept;

    WTime & operator-=(const WTime & other) noexcept;

    WTime & operator*=(const float scale) noexcept;

    WTime & operator/=(const float scale) noexcept;

    bool operator==(const WTime & other) const noexcept;

    bool operator!=(const WTime & other) const noexcept;

    bool operator<(const WTime & other) const noexcept;

    bool operator<=(const WTime & other) const noexcept;

    bool operator>(const WTime & other) const noexcept;

    bool operator>=(const WTime & other) const noexcept;
};

} // namespace engine
