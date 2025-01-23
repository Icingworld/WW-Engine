#pragma once

#include <string>
#include <ww_time_step.h>

namespace engine
{

/**
 * @brief 图层
 */
class Layer
{
protected:
    std::string m_layerName;    // 图层名称

public:
    explicit Layer(const std::string & name);

    virtual ~Layer() = default;

public:
    /**
     * @brief 图层被添加到图层栈
     */
    virtual void onAttach() = 0;

    /**
     * @brief 图层被从图层栈中移除
     */
    virtual void onDetach() = 0;

    /**
     * @brief 每帧的逻辑更新及渲染
     */
    virtual void onUpdate(TimeStep ts) = 0;

    /**
     * @brief 每帧的 GUI 渲染
     */
    virtual void onImGuiRender() = 0;

    /**
     * @brief 每帧的事件调用
     */
    virtual void onEvent() = 0;

    /**
     * @brief 获取图层名称
     */
    const std::string & getName() const;
};

} // namespace engine
