#include "ww_window_base.h"

namespace engine
{

WindowData::WindowData(std::string title, int width, int height)
    : m_title(title)
    , m_width(width)
    , m_height(height)
{
}

WindowBase::WindowBase()
    : WindowBase("Untitled", 400, 300)
{ // 默认窗口
}

WindowBase::WindowBase(std::string title, int width, int height)
    : m_windowData(title, width, height)
{
}

void WindowBase::init()
{
}

void WindowBase::close()
{
}

void WindowBase::render()
{
}

const std::string & WindowBase::getTitle() const
{
    return m_windowData.m_title;
}

int WindowBase::getWidth() const
{
    return m_windowData.m_width;
}

int WindowBase::getHeight() const
{
    return m_windowData.m_height;
}

GLFWwindow * WindowBase::getWindow() const
{
    return m_window;
}

void WindowBase::setTitle(const std::string & title)
{
    m_windowData.m_title = title;
}

void WindowBase::setSize(int width, int height)
{
    m_windowData.m_width = width;
    m_windowData.m_height = height;
}

void WindowBase::setWidth(int width)
{
    m_windowData.m_width = width;
}

void WindowBase::setHeight(int height)
{
    m_windowData.m_height = height;
}

void WindowBase::setEventCallback(const std::function<void(Event &)> & callback)
{
    m_windowData.m_eventCallback = callback;
}

} // namespace engine
