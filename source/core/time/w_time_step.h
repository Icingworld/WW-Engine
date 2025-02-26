#pragma once

namespace engine
{

/**
 * @brief 时间步长类
 */
class WTimeStep
{
private:
    float m_step;        // 时间步长

public:
    WTimeStep(float step = 0.0f);

    ~WTimeStep() = default;

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
