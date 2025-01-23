#include "ww_event.h"

namespace engine
{

Event::Event()
    : Event(EventType::None)
{
}

Event::Event(EventType type)
    : m_type(type)
{
}

EventType Event::getEventType() const
{
    return m_type;
}

void Event::setHandled(bool handled)
{
    m_handled = handled;
}

bool Event::isHandled() const
{
    return m_handled;
}

} // namespace engine
