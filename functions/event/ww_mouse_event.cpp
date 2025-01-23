#include "ww_mouse_event.h"

namespace engine
{

MouseButtonEvent::MouseButtonEvent(MouseCode code, EventType type)
    : Event(type)
    , m_mouseCode(code)
{ // MouseButtonEvent是抽象父类，默认事件类型为None
}

MouseCode MouseButtonEvent::getMouseCode() const
{
    return m_mouseCode;
}

const char * MouseButtonEvent::getName() const
{
    return "MouseButtonEvent";
}

MouseButtonPressedEvent::MouseButtonPressedEvent(MouseCode code)
    : MouseButtonEvent(code, EventType::MouseButtonPressed)
{
}

const char * MouseButtonPressedEvent::getName() const
{
    return "MouseButtonPressedEvent";
}

EventType MouseButtonPressedEvent::getEventType()
{
    return EventType::MouseButtonPressed;
}

MouseButtonReleasedEvent::MouseButtonReleasedEvent(MouseCode code)
    : MouseButtonEvent(code, EventType::MouseButtonReleased)
{
}

const char * MouseButtonReleasedEvent::getName() const
{
    return "MouseButtonReleasedEvent";
}

EventType MouseButtonReleasedEvent::getEventType()
{
    return EventType::MouseButtonReleased;
}

MouseMovedEvent::MouseMovedEvent(float x, float y)
    : Event(EventType::MouseMoved)
    , m_x(x)
    , m_y(y)
{
}

const char * MouseMovedEvent::getName() const
{
    return "MouseMovedEvent";
}

EventType MouseMovedEvent::getEventType()
{
    return EventType::MouseMoved;
}

float MouseMovedEvent::getX() const
{
    return m_x;
}

float MouseMovedEvent::getY() const
{
    return m_y;
}

MouseScrolledEvent::MouseScrolledEvent(float xOffset, float yOffset)
    : Event(EventType::MouseScrolled)
    , m_xOffset(xOffset)
    , m_yOffset(yOffset)
{
}

const char * MouseScrolledEvent::getName() const
{
    return "MouseScrolledEvent";
}

EventType MouseScrolledEvent::getEventType()
{
    return EventType::MouseScrolled;
}

float MouseScrolledEvent::getXOffset() const
{
    return m_xOffset;
}

float MouseScrolledEvent::getYOffset() const
{
    return m_yOffset;
}

} // namespace engine
