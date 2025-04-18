#pragma once

#include <chrono>

#include "w_time.h"

namespace engine
{

/**
 * @brief 计时器
 */
class WTimer final
{
private:
    std::chrono::high_resolution_clock::time_point m_start;      // 开始时间

public:
    WTimer();

    ~WTimer() = default;

public:
    /**
     * @brief 重置计时器
     */
    void reset();

    /**
     * @brief 获取计时器秒数
     */
    WTime elapsed();
};

} // namespace engine
