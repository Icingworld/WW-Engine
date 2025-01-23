#include "ww_key_event.h"

namespace engine
{

KeyEvent::KeyEvent(KeyCode code, EventType type)
    : Event(type)
    , m_keyCode(code)
{ // KeyEvent是抽象父类，默认事件类型为None
}

KeyCode KeyEvent::getKeyCode() const
{
    return m_keyCode;
}

const char * KeyEvent::getName() const
{
    return "KeyEvent";
}

KeyPressedEvent::KeyPressedEvent(KeyCode code, bool repeat)
    : KeyEvent(code, EventType::KeyPressed)
    , m_repeat(repeat)
{
}

const char * KeyPressedEvent::getName() const
{
    return "KeyPressedEvent";
}

EventType KeyPressedEvent::getStaticType()
{
    return EventType::KeyPressed;
}

KeyReleasedEvent::KeyReleasedEvent(KeyCode code)
    : KeyEvent(code, EventType::KeyReleased)
{
}

const char * KeyReleasedEvent::getName() const
{
    return "KeyReleasedEvent";
}

EventType KeyReleasedEvent::getStaticType()
{
    return EventType::KeyReleased;
}

KeyTypedEvent::KeyTypedEvent(KeyCode code)
    : KeyEvent(code, EventType::KeyTyped)
{
}

const char * KeyTypedEvent::getName() const
{
    return "KeyTypedEvent";
}

EventType KeyTypedEvent::getStaticType()
{
    return EventType::KeyTyped;
}

} // namespace engine
