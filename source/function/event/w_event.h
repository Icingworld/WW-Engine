#pragma once

namespace engine
{

/**
 * @brief 事件类型
 */
enum class WEventType
{
    None = 0,
    WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
    AppTick, AppUpdate, AppRender,
    KeyPressed, KeyReleased, KeyTyped,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};

/**
 * @brief 事件
 */
class WEvent
{
protected:
    WEventType m_type;          // 事件类型
    bool m_handled = false;     // 是否已处理

public:
    explicit WEvent(WEventType type);

    virtual ~WEvent() = default;

public:
    /**
     * @brief 获取事件类型
     */
    WEventType getEventType() const;

    /**
     * @brief 获取事件名称
     */
    virtual const char * getName() const = 0;

    /**
     * @brief 设置事件是否已处理
     */
    void setHandled(bool handled);

    /**
     * @brief 事件是否已处理
     */
    bool isHandled() const;
};

} // namespace engine
