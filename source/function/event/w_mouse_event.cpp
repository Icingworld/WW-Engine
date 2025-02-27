#include "w_mouse_event.h"

namespace engine
{

WMouseButtonEvent::WMouseButtonEvent(WMouseCode code, WEventType type)
    : WEvent(type)
    , m_mouseCode(code)
{ // MouseButtonEvent是抽象父类，默认事件类型为None
}

WMouseCode WMouseButtonEvent::getMouseCode() const
{
    return m_mouseCode;
}

const char * WMouseButtonEvent::getName() const
{
    return "MouseButtonEvent";
}

WMouseButtonPressedEvent::WMouseButtonPressedEvent(WMouseCode code)
    : WMouseButtonEvent(code, WEventType::MouseButtonPressed)
{
}

const char * WMouseButtonPressedEvent::getName() const
{
    return "MouseButtonPressedEvent";
}

WEventType WMouseButtonPressedEvent::getEventType()
{
    return WEventType::MouseButtonPressed;
}

WMouseButtonReleasedEvent::WMouseButtonReleasedEvent(WMouseCode code)
    : WMouseButtonEvent(code, WEventType::MouseButtonReleased)
{
}

const char * WMouseButtonReleasedEvent::getName() const
{
    return "WMouseButtonReleasedEvent";
}

WEventType WMouseButtonReleasedEvent::getEventType()
{
    return WEventType::MouseButtonReleased;
}

WMouseMovedEvent::WMouseMovedEvent(float x, float y)
    : WEvent(WEventType::MouseMoved)
    , m_x(x)
    , m_y(y)
{
}

const char * WMouseMovedEvent::getName() const
{
    return "WMouseMovedEvent";
}

WEventType WMouseMovedEvent::getEventType()
{
    return WEventType::MouseMoved;
}

float WMouseMovedEvent::getX() const
{
    return m_x;
}

float WMouseMovedEvent::getY() const
{
    return m_y;
}

WMouseScrolledEvent::WMouseScrolledEvent(float xOffset, float yOffset)
    : WEvent(WEventType::MouseScrolled)
    , m_xOffset(xOffset)
    , m_yOffset(yOffset)
{
}

const char * WMouseScrolledEvent::getName() const
{
    return "MouseScrolledEvent";
}

WEventType WMouseScrolledEvent::getEventType()
{
    return WEventType::MouseScrolled;
}

float WMouseScrolledEvent::getXOffset() const
{
    return m_xOffset;
}

float WMouseScrolledEvent::getYOffset() const
{
    return m_yOffset;
}

} // namespace engine
