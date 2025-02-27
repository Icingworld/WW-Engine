#include "w_window.h"

namespace engine
{

WWindowData::WWindowData(std::string title, int width, int height)
    : m_title(title)
    , m_width(width)
    , m_height(height)
{
}

WWindowBase::WWindowBase()
    : WWindowBase("Untitled", 800, 600)
{ // 默认窗口标题和大小
}

WWindowBase::WWindowBase(std::string title, int width, int height)
    : m_windowData(title, width, height)
{
}

WWindowBase::WWindowBase(const WWindowData & data)
    : m_windowData(data)
{
}

const std::string & WWindowBase::getTitle() const
{
    return m_windowData.m_title;
}

int WWindowBase::getWidth() const
{
    return m_windowData.m_width;
}

int WWindowBase::getHeight() const
{
    return m_windowData.m_height;
}

const WWindowData & WWindowBase::getWindowData() const
{
    return m_windowData;
}

void WWindowBase::setTitle(const std::string & title)
{
    m_windowData.m_title = title;
}

void WWindowBase::setSize(int width, int height)
{
    m_windowData.m_width = width;
    m_windowData.m_height = height;
}

void WWindowBase::setWidth(int width)
{
    m_windowData.m_width = width;
}

void WWindowBase::setHeight(int height)
{
    m_windowData.m_height = height;
}

void WWindowBase::setWindowData(std::string title, int width, int height)
{
    m_windowData = WWindowData(title, width, height);
}

void WWindowBase::setWindowData(const WWindowData & data)
{
    m_windowData = data;
}

void WWindowBase::setEventCallback(const std::function<void(WEvent &)> & callback)
{
    m_windowData.m_eventCallback = callback;
}

} // namespace engine
