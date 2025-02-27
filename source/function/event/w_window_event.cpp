#include "w_window_event.h"

namespace engine
{

WWindowCloseEvent::WWindowCloseEvent()
    : WEvent(WEventType::WindowClose)
{
}

const char * WWindowCloseEvent::getName() const
{
    return "WindowClose";
}

WEventType WWindowCloseEvent::getEventType()
{
    return WEventType::WindowClose;
}

WWindowResizeEvent::WWindowResizeEvent(int width, int height)
    : WEvent(WEventType::WindowResize)
    , m_width(width)
    , m_height(height)
{
}

const char * WWindowResizeEvent::getName() const
{
    return "WindowResize";
}

WEventType WWindowResizeEvent::getEventType()
{
    return WEventType::WindowResize;
}

int WWindowResizeEvent::getWidth() const
{
    return m_width;
}

int WWindowResizeEvent::getHeight() const
{
    return m_height;
}

} // namespace engine
