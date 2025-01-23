#pragma once

#include "ww_timer.h"
#include "ww_task_pool.h"
#include <layer/ww_layer_stack.h>

namespace engine
{

/**
 * @brief 应用
 */
class Application
{
protected:
    // 单例
    static Application m_app;   // 单例

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

protected:
    Application(int argc, char ** argv);

    Application(const Application &) = delete;

    Application & operator=(const Application &) = delete;

    virtual ~Application();

public:
    static Application & createApplication(int argc, char ** argv);

    static Application & getApplication();

public:
};

} // namespace engine
