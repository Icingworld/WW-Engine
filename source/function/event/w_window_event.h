#pragma once

#include <w_event_base.h>

namespace engine
{

/**
 * @brief 窗口关闭事件
 */
class WWindowCloseEvent
    : public WEvent
{
public:
    WWindowCloseEvent();

    ~WWindowCloseEvent() = default;

public:
    const char * getName() const override;

    static WEventType getEventType();
};

/**
 * @brief 窗口修改大小事件
 */
class WWindowResizeEvent
    : public WEvent
{
protected:
    int m_width;
    int m_height;

public:
    WWindowResizeEvent(int width, int height);

    ~WWindowResizeEvent() = default;

public:
    const char * getName() const override;

    static WEventType getEventType();

    /**
     * @brief 获取窗口宽度
     */
    int getWidth() const;

    /**
     * @brief 获取窗口高度
     */
    int getHeight() const;
};

} // namespace engine
