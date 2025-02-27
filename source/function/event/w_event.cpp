#include "w_event.h"

namespace engine
{

WEvent::WEvent(WEventType type)
    : m_type(type)
{
}

WEventType WEvent::getEventType() const
{
    return m_type;
}

void WEvent::setHandled(bool handled)
{
    m_handled = handled;
}

bool WEvent::isHandled() const
{
    return m_handled;
}

} // namespace engine
