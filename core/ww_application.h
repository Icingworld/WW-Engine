#pragma once

#include "ww_timer.h"
#include "ww_task_pool.h"
#include <layer/ww_layer_stack.h>
#include <window/ww_window.h>

namespace engine
{

/**
 * @brief 应用
 */
class Application
{
protected:
    // 运行状态
    bool m_isRunning;           // 是否正在运行
    bool m_isPaused;            // 是否暂停
    bool m_isMinimized;         // 是否最小化

    // 帧和时间
    float m_lastFrameTime;      // 上一帧的时间
    Timer m_timer;              // 计时器

    // 数据结构
    TaskPool m_taskPool;        // 任务池

    // 图层
    LayerStack m_layerStack;    // 图层栈

    // 窗口
    Window * m_window;          // 窗口

protected:
    Application(int argc = 0, char ** argv = nullptr);

    Application(const Application &) = delete;

    Application & operator=(const Application &) = delete;

    virtual ~Application();

public:
    /**
     * @brief 获取应用单例
     */
    static Application & getApplication(int argc = 0, char ** argv = nullptr);

    /**
     * @brief 设置窗口
     */
    void bindWindow(Window * window);

    /**
     * @brief 主循环
     */
    void run();

    /**
     * @brief 停止循环
     */
    void stop();

    /**
     * @brief 提交任务
     */
    void submitTask(std::function<void()> task);

    /**
     * @brief 执行所有任务
     */
    void executeTasks();

    /**
     * @brief 添加普通图层
     */
    void pushLayer(Layer * layer);

    /**
     * @brief 添加覆盖图层
     */
    void pushOverlay(Layer * layer);

    /**
     * @brief 事件处理
     */
    void onEvent(Event & event);
};

} // namespace engine
