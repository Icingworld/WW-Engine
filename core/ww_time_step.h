#pragma once

namespace engine
{

/**
 * @brief 时间步长类
 * @details 用于提供固定帧率下的时间步长
 */
class TimeStep
{
private:
    float m_step;        // 时间步长

public:
    TimeStep(float step = 0.0f);

public:
    /**
     * @brief 获取时间步长秒数
     */
    float getStep() const;

    /**
     * @brief 获取时间步长毫秒数
     */
    float getStepMillis() const;
};

} // namespace engine
