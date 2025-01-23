#pragma once

#include <ww_mouse_code.h>
#include "ww_event.h"

namespace engine
{

/**
 * @brief 鼠标按键事件
 */
class MouseButtonEvent : public Event
{
protected:
    MouseCode m_mouseCode;  // 鼠标码

public:
    MouseButtonEvent(MouseCode code, EventType type = EventType::None);

    ~MouseButtonEvent() = default;

public:
    /**
     * @brief 获取鼠标码
     */
    MouseCode getMouseCode() const;

    const char * getName() const override;
};

/**
 * @brief 鼠标按下事件
 */
class MouseButtonPressedEvent : public MouseButtonEvent
{
public:
    explicit MouseButtonPressedEvent(MouseCode code);

    ~MouseButtonPressedEvent() = default;

public:
    const char * getName() const override;

    static EventType getEventType();
};

/**
 * @brief 鼠标释放事件
 */
class MouseButtonReleasedEvent : public MouseButtonEvent
{
public:
    explicit MouseButtonReleasedEvent(MouseCode code);

    ~MouseButtonReleasedEvent() = default;

public:
    const char * getName() const override;

    static EventType getEventType();
};

/**
 * @brief 鼠标移动事件
 */
class MouseMovedEvent : public Event
{
protected:
    float m_x;
    float m_y;

public:
    MouseMovedEvent(float x, float y);

    ~MouseMovedEvent() = default;

public:
    const char * getName() const override;

    static EventType getEventType();

    /**
     * @brief 获取鼠标坐标 X
     */
    float getX() const;

    /**
     * @brief 获取鼠标坐标 Y
     */
    float getY() const;
};

/**
 * @brief 鼠标滚轮事件
 */
class MouseScrolledEvent : public Event
{
protected:
    float m_xOffset;
    float m_yOffset;

public:
    MouseScrolledEvent(float xOffset, float yOffset);

    ~MouseScrolledEvent() = default;

public:
    const char * getName() const override;

    static EventType getEventType();

    /**
     * @brief 获取鼠标滚轮偏移 X
     */
    float getXOffset() const;

    /**
     * @brief 获取鼠标滚轮偏移 Y
     */
    float getYOffset() const;
};

} // namespace engine
