#include "w_key_event.h"

namespace engine
{

WKeyEvent::WKeyEvent(WKeyCode code, WEventType type)
    : WEvent(type)
    , m_keyCode(code)
{ // KeyEvent是抽象父类，默认事件类型为None
}

WKeyCode WKeyEvent::getKeyCode() const
{
    return m_keyCode;
}

const char * WKeyEvent::getName() const
{
    return "KeyEvent";
}

WKeyPressedEvent::WKeyPressedEvent(WKeyCode code, bool repeat)
    : WKeyEvent(code, WEventType::KeyPressed)
    , m_repeat(repeat)
{
}

const char * WKeyPressedEvent::getName() const
{
    return "KeyPressedEvent";
}

WEventType WKeyPressedEvent::getEventType()
{
    return WEventType::KeyPressed;
}

WKeyReleasedEvent::WKeyReleasedEvent(WKeyCode code)
    : WKeyEvent(code, WEventType::KeyReleased)
{
}

const char * WKeyReleasedEvent::getName() const
{
    return "KeyReleasedEvent";
}

WEventType WKeyReleasedEvent::getEventType()
{
    return WEventType::KeyReleased;
}

WKeyTypedEvent::WKeyTypedEvent(WKeyCode code)
    : WKeyEvent(code, WEventType::KeyTyped)
{
}

const char * WKeyTypedEvent::getName() const
{
    return "KeyTypedEvent";
}

WEventType WKeyTypedEvent::getEventType()
{
    return WEventType::KeyTyped;
}

} // namespace engine
