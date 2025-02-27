#pragma once

#include <string>

#include "../time/w_time_step.h"
#include "w_event_base.h"

namespace engine
{

/**
 * @brief 图层
 */
class WLayer
{
protected:
    std::string m_layerName;    // 图层名称

public:
    explicit WLayer(const std::string & name);

    virtual ~WLayer() = default;

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
    virtual void onUpdate(WTimeStep ts);

    /**
     * @brief 每帧的 GUI 渲染
     */
    virtual void onImGuiRender();

    /**
     * @brief 每帧的事件调用
     */
    virtual void onEvent(WEvent & event);

    /**
     * @brief 获取图层名称
     */
    const std::string & getName() const;
};

} // namespace engine
