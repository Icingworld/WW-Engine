#pragma once

#include <string>
#include <ww_time_step.h>
#include "../event/ww_event.h"

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
    virtual void onAttach();

    /**
     * @brief 图层被从图层栈中移除
     */
    virtual void onDetach();

    /**
     * @brief 每帧的逻辑更新及渲染
     */
    virtual void onUpdate(TimeStep ts);

    /**
     * @brief 每帧的 GUI 渲染
     */
    virtual void onImGuiRender();

    /**
     * @brief 每帧的事件调用
     */
    virtual void onEvent(Event & event);

    /**
     * @brief 获取图层名称
     */
    const std::string & getName() const;
};

} // namespace engine
