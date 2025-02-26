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
    return "WKeyEvent";
}

WKeyPressedEvent::WKeyPressedEvent(WKeyCode code, bool repeat)
    : WKeyEvent(code, WEventType::WKeyPressed)
    , m_repeat(repeat)
{
}

const char * WKeyPressedEvent::getName() const
{
    return "WKeyPressedEvent";
}

WEventType WKeyPressedEvent::getStaticType()
{
    return WEventType::WKeyPressed;
}

WKeyReleasedEvent::WKeyReleasedEvent(WKeyCode code)
    : WKeyEvent(code, WEventType::WKeyReleased)
{
}

const char * WKeyReleasedEvent::getName() const
{
    return "WKeyReleasedEvent";
}

WEventType WKeyReleasedEvent::getStaticType()
{
    return WEventType::WKeyReleased;
}

WKeyTypedEvent::WKeyTypedEvent(WKeyCode code)
    : WKeyEvent(code, WEventType::WKeyTyped)
{
}

const char * WKeyTypedEvent::getName() const
{
    return "WKeyTypedEvent";
}

WEventType WKeyTypedEvent::getStaticType()
{
    return WEventType::WKeyTyped;
}

} // namespace engine
