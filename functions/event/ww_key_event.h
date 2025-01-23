#pragma once

#include <ww_key_code.h>
#include "ww_event.h"

namespace engine
{

/**
 * @brief 按键事件
 */
class KeyEvent : public Event
{
protected:
    KeyCode m_keyCode;  // 键码

public:
    KeyEvent(KeyCode code, EventType type = EventType::None);

    ~KeyEvent() = default;

public:
    /**
     * @brief 获取键码
     */
    KeyCode getKeyCode() const;

    const char * getName() const override;
};

/**
 * @brief 按键按下事件
 */
class KeyPressedEvent : public KeyEvent
{
protected:
    bool m_repeat;  // 是否重复

public:
    KeyPressedEvent(KeyCode code, bool repeat);

    ~KeyPressedEvent() = default;

public:
    const char * getName() const override;

    static EventType getStaticType();
};

/**
 * @brief 按键释放事件
 */
class KeyReleasedEvent : public KeyEvent
{
public:
    explicit KeyReleasedEvent(KeyCode code);

    ~KeyReleasedEvent() = default;

public:
    const char * getName() const override;

    static EventType getStaticType();
};

class KeyTypedEvent : public KeyEvent
{
public:
    explicit KeyTypedEvent(KeyCode code);

    ~KeyTypedEvent() = default;

public:
    const char * getName() const override;

    static EventType getStaticType();
};

} // namespace engine
