#pragma once

#include "ww_event.h"

namespace engine
{

/**
 * @brief 事件分发器
 */
class EventDispatcher
{
protected:
    Event & m_event;        // 事件对象

public:
    explicit EventDispatcher(Event & event);

    virtual ~EventDispatcher() = default;

public:
    /**
     * @brief 分发事件
     * @details 分发事件到事件回调函数
     */
    template <
        class EventType,
        class Fn
    > bool dispatch(const Fn & fn)
    {
        if (m_event.getEventType() == EventType::getStaticType()) {
            // 将事件强制转换为具体类型并调用回调函数
            m_event.setHandled(fn(static_cast<EventType &>(m_event)));
            return true;
        }
        return false;
    }
};

} // namespace engine
