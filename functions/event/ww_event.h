#pragma once

#include <functional>
#include <iostream>
#include <sstream>

namespace engine
{

/**
 * @brief 事件类型
 */
enum class EventType
{
    None = 0,
    WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
    AppTick, AppUpdate, AppRender,
    KeyPressed, KeyReleased, KeyTyped,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};

/**
 * @brief 事件
 */
class Event
{
protected:
    EventType m_type;           // 事件类型
    bool m_handled = false;     // 是否已处理

public:
    Event();

    explicit Event(EventType type);

    virtual ~Event() = default;

public:
    /**
     * @brief 获取事件类型
     */
    EventType getEventType() const;

    /**
     * @brief 获取事件名称
     */
    virtual const char * getName() const = 0;

    /**
     * @brief 设置事件是否已处理
     */
    void setHandled(bool handled);

    /**
     * @brief 事件是否已处理
     */
    bool isHandled() const;
};

} // namespace engine
