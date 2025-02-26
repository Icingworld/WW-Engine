#pragma once

#include "w_time.h"

namespace engine
{

/**
 * @brief 时间步长
 */
class WTimeStep final
{
private:
    WTime m_step;        // 时间步长

public:
    WTimeStep(WTime step = 0.0f);

    ~WTimeStep() = default;

public:
    /**
     * @brief 获取时间步长
     */
    WTime getStep() const;
};

} // namespace engine
