#include "ww_application.h"

#include <event/ww_event_dispatcher.h>
#include <event/ww_window_event.h>

namespace engine
{

Application::Application(Window * window = nullptr, int argc = 0, char ** argv = nullptr)
    : m_isRunning(true)
    , m_isPaused(false)
    , m_isMinimized(false)
    , m_lastFrameTime(0.0f)
    , m_timer()
    , m_taskPool()
    , m_layerStack()
    , m_window(window)
{
    if (m_window == nullptr) {
        // 没有传入窗口，使用默认窗口
        m_window = new Window();
    }

    // 注册回调函数
    m_window->setEventCallback([this](Event & event) {
        this->onEvent(event);
    });
}

Application::~Application()
{
    delete m_window;
}

Application & Application::getApplication(Window * window, int argc, char ** argv)
{
    static Application app(window, argc, argv);
    return app;
}

void Application::run()
{
    while (m_isRunning) {
        // 计算帧和时间
        float time = m_timer.elapsed();
        TimeStep timestep = time - m_lastFrameTime;
        m_lastFrameTime = time;

        // 逻辑更新
        executeTasks();

        // 渲染更新
        if (!m_isMinimized) {
            // 更新并渲染图层
            for (auto & layer : m_layerStack) {
                layer->onUpdate(timestep);
            }
        }
        // 渲染到屏幕
        m_window->render();
    }
}

void Application::stop()
{
    m_isRunning = false;
}

void Application::submitTask(std::function<void()> task)
{
    m_taskPool.submitTask(task);
}

void Application::executeTasks()
{
    m_taskPool.executeTasks();
}

void Application::pushLayer(Layer * layer)
{
    m_layerStack.pushLayer(layer);
}

void Application::pushOverlay(Layer * layer)
{
    m_layerStack.pushOverlay(layer);
}

void Application::onEvent(Event & event)
{
    // 分发事件
    EventDispatcher dispatcher(event);

    // 窗口关闭事件
    dispatcher.dispatch<WindowCloseEvent>([this](WindowCloseEvent & e) {
        m_isRunning = false;
        return true;
    });

    // 窗口大小调整事件
    dispatcher.dispatch<WindowResizeEvent>([this](WindowResizeEvent & e) {
        glViewport(0, 0, e.getWidth(), e.getHeight());
        return true;
    });

    // 传递给图层栈消费
    for (auto rit = m_layerStack.rbegin(); rit != m_layerStack.rend(); ++rit) {
        if (event.isHandled()) {
            break;
        }
        (*rit)->onEvent(event);
    }
}

} // namespace engine
