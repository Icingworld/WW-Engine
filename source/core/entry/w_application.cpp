#include "w_application.h"

namespace engine
{

WApplication::WApplication()
    : m_isRunning(false)
    , m_isPaused(false)
    , m_isMinimized(false)
    , m_lastFrameTime(0.0f)
    , m_timer()
{
}

WApplication & WApplication::getApplication()
{
    static WApplication app;
    return app;
}

WApplication::~WApplication()
{
}

std::shared_ptr<WWindow> WApplication::getWindow() const
{
    return m_window;
}

} // namespace engine
