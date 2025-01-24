#include "ww_application.h"

#include <event/ww_event_dispatcher.h>
#include <event/ww_window_event.h>

namespace engine
{

Application::Application(int argc, char ** argv)
    : m_isRunning(true)
    , m_isPaused(false)
    , m_isMinimized(false)
    , m_lastFrameTime(0.0f)
    , m_timer()
    , m_taskPool()
    , m_layerStack()
    , m_window(nullptr)
{
}

Application::~Application()
{
    delete m_window;
}

Application & Application::getApplication(int argc, char ** argv)
{
    static Application app(argc, argv);
    return app;
}

void Application::bindWindow(Window * window)
{
    m_window = window;

    // 设置窗口回调函数
    m_window->setEventCallback([this](Event & event) {
        this->onEvent(event);
    });
}

void Application::run()
{
    while (m_isRunning) {
        // 计算帧和时间
        float time = m_timer.elapsed();
        TimeStep timestep = time - m_lastFrameTime;
        m_lastFrameTime = time;

        // 执行任务
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

Window * Application::getWindow() const
{
    return m_window;
}

} // namespace engine
