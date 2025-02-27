#include "w_application.h"

#include <w_event_dispatcher.h>
#include <w_window_event.h>

namespace engine
{

WApplication::WApplication()
    : m_isRunning(true)
    , m_isPaused(false)
    , m_isMinimized(false)
    , m_lastFrameTime(0.0f)
    , m_timer()
    , m_window(nullptr)
    , m_layerStack()
    , m_imguiLayer(nullptr)
    , m_log()
{
}

WApplication & WApplication::getApplication()
{
    static WApplication app;
    return app;
}

WApplication::~WApplication()
{
    if (m_imguiLayer)
        delete m_imguiLayer;

    if (m_window)
        delete m_window;
}

void WApplication::run()
{
    while (m_isRunning) {
        WTime time = m_timer.elapsed();
        WTimeStep timestep = time - m_lastFrameTime;
        m_lastFrameTime = time;

        // 渲染更新
        if (!m_isMinimized) {
            // 清除上一帧画面
            m_window->clear();

            // 更新并渲染图层
            for (auto & layer : m_layerStack) {
                layer->onUpdate(timestep);
            }

            // 渲染 ImGui 图层
            m_imguiLayer->begin();
            for (auto & layer : m_layerStack) {
                layer->onImGuiRender();
            }
            // 结束渲染 ImGui 图层
            m_imguiLayer->end();
        }
        // 渲染到屏幕
        m_window->render();
    }
}

void WApplication::stop()
{
    m_isRunning = false;
}

void WApplication::pushLayer(WLayer * layer)
{
    m_layerStack.pushLayer(layer);
}

void WApplication::pushOverlay(WLayer * layer)
{
    m_layerStack.pushOverlay(layer);
}

void WApplication::onEvent(WEvent & event)
{
    // 分发事件
    WEventDispatcher dispatcher(event);

    // 窗口关闭事件
    dispatcher.dispatch<WWindowCloseEvent>([this](WWindowCloseEvent & e) {
        stop();
        return true;
    });

    // 窗口大小调整事件
    dispatcher.dispatch<WWindowResizeEvent>([this](WWindowResizeEvent & e) {
        glViewport(0, 0, e.getWidth(), e.getHeight());
        return true;
    });

    // 传递给图层栈消费
    for (auto rit = m_layerStack.rbegin(); rit != m_layerStack.rend(); ++rit) {
        if (event.isHandled()) {
            // 上个图层已经处理过了
            break;
        }
        (*rit)->onEvent(event);
    }
}

void WApplication::bindWindow(WWindow * window)
{
    m_window = window;

    // 设置窗口回调函数
    m_window->setEventCallback([this](WEvent & event) {
        this->onEvent(event);
    });

    // 绑定到 ImGui 图层
    m_imguiLayer = new WImGuiLayer(m_window->getWindow());
    pushOverlay(m_imguiLayer);
}

WWindow * WApplication::getWindow() const
{
    return m_window;
}

} // namespace engine
