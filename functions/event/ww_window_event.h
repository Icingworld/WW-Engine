#pragma once

#include "ww_event.h"

namespace engine
{

class WindowCloseEvent : public Event
{
public:
    WindowCloseEvent();

    ~WindowCloseEvent() = default;

public:
    const char * getName() const override;

    static EventType getStaticType();
};

class WindowResizeEvent : public Event
{
protected:
    int m_width;
    int m_height;

public:
    WindowResizeEvent(int width, int height);

    ~WindowResizeEvent() = default;

public:
    const char * getName() const override;

    static EventType getStaticType();

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
