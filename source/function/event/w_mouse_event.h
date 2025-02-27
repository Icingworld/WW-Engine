#pragma once

#include <w_mouse_code.h>
#include <w_event_base.h>

namespace engine
{

/**
 * @brief 鼠标按键事件
 */
class WMouseButtonEvent
    : public WEvent
{
protected:
    WMouseCode m_mouseCode;  // 鼠标码

public:
    explicit WMouseButtonEvent(WMouseCode code, WEventType type = WEventType::None);

    ~WMouseButtonEvent() = default;

public:
    /**
     * @brief 获取鼠标码
     */
    WMouseCode getMouseCode() const;

    const char * getName() const override;
};

/**
 * @brief 鼠标按下事件
 */
class WMouseButtonPressedEvent
    : public WMouseButtonEvent
{
public:
    explicit WMouseButtonPressedEvent(WMouseCode code);

    ~WMouseButtonPressedEvent() = default;

public:
    const char * getName() const override;

    static WEventType getEventType();
};

/**
 * @brief 鼠标释放事件
 */
class WMouseButtonReleasedEvent
    : public WMouseButtonEvent
{
public:
    explicit WMouseButtonReleasedEvent(WMouseCode code);

    ~WMouseButtonReleasedEvent() = default;

public:
    const char * getName() const override;

    static WEventType getEventType();
};

/**
 * @brief 鼠标移动事件
 */
class WMouseMovedEvent
    : public WEvent
{
protected:
    float m_x;
    float m_y;

public:
    WMouseMovedEvent(float x, float y);

    ~WMouseMovedEvent() = default;

public:
    const char * getName() const override;

    static WEventType getEventType();

    /**
     * @brief 获取鼠标坐标 X
     */
    float getX() const;

    /**
     * @brief 获取鼠标坐标 Y
     */
    float getY() const;
};

/**
 * @brief 鼠标滚轮事件
 */
class WMouseScrolledEvent
    : public WEvent
{
protected:
    float m_xOffset;
    float m_yOffset;

public:
    WMouseScrolledEvent(float xOffset, float yOffset);

    ~WMouseScrolledEvent() = default;

public:
    const char * getName() const override;

    static WEventType getEventType();

    /**
     * @brief 获取鼠标滚轮偏移 X
     */
    float getXOffset() const;

    /**
     * @brief 获取鼠标滚轮偏移 Y
     */
    float getYOffset() const;
};

} // namespace engine
