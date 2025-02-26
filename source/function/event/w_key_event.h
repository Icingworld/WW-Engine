#pragma once

#include <w_key_code.h>
#include <w_event.h>

namespace engine
{

/**
 * @brief 按键事件
 */
class WKeyEvent
    : public WEvent
{
protected:
    WKeyCode m_keyCode;  // 键码

public:
    explicit WKeyEvent(WKeyCode code, WEventType type = WEventType::None);

    ~WKeyEvent() = default;

public:
    /**
     * @brief 获取键码
     */
    WKeyCode getKeyCode() const;

    const char * getName() const override;
};

/**
 * @brief 按键按下事件
 */
class WKeyPressedEvent
    : public WKeyEvent
{
protected:
    bool m_repeat;  // 是否重复

public:
    WKeyPressedEvent(WKeyCode code, bool repeat);

    ~WKeyPressedEvent() = default;

public:
    const char * getName() const override;

    static WEventType getStaticType();
};

/**
 * @brief 按键释放事件
 */
class WKeyReleasedEvent
    : public WKeyEvent
{
public:
    explicit WKeyReleasedEvent(WKeyCode code);

    ~WKeyReleasedEvent() = default;

public:
    const char * getName() const override;

    static WEventType getStaticType();
};

class WKeyTypedEvent
    : public WKeyEvent
{
public:
    explicit WKeyTypedEvent(WKeyCode code);

    ~WKeyTypedEvent() = default;

public:
    const char * getName() const override;

    static WEventType getStaticType();
};

} // namespace engine
