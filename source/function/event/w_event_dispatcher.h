#pragma once

#include "w_event.h"

namespace engine
{

/**
 * @brief 事件分发器
 */
class WEventDispatcher
{
protected:
    const WEvent & m_event;        // 事件对象

public:
    explicit WEventDispatcher(const WEvent & event);

    ~WEventDispatcher() = default;

public:
    /**
     * @brief 分发事件
     * @details 分发事件到事件回调函数
     * @param func 事件回调函数，需接受EventType &作为参数
     * @return 事件是否分发成功
     */
    template <
        class EventType,
        class Function
    > bool dispatch(const Function & func)
    {
        if (m_event.getEventType() == EventType::getEventType()) {
            // 将事件强制转换为具体类型并调用回调函数
            m_event.setHandled(func(static_cast<EventType &>(m_event)));
            return true;
        }
        return false;
    }
};

} // namespace engine
