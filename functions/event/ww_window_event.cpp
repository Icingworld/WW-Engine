#include "ww_window_event.h"

namespace engine
{

WindowCloseEvent::WindowCloseEvent()
    : Event(EventType::WindowClose)
{
}

const char * WindowCloseEvent::getName() const
{
    return "WindowClose";
}

EventType WindowCloseEvent::getStaticType()
{
    return EventType::WindowClose;
}

WindowResizeEvent::WindowResizeEvent(int width, int height)
    : Event(EventType::WindowResize)
    , m_width(width)
    , m_height(height)
{
}

const char * WindowResizeEvent::getName() const
{
    return "WindowResize";
}

EventType WindowResizeEvent::getStaticType()
{
    return EventType::WindowResize;
}

int WindowResizeEvent::getWidth() const
{
    return m_width;
}

int WindowResizeEvent::getHeight() const
{
    return m_height;
}

} // namespace engine
