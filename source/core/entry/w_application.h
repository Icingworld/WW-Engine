#pragma once

#include "../time/w_timer.h"
#include <w_window.h>

namespace engine
{

/**
 * @brief 引擎入口
 */
class WApplication
{
protected:
    // 运行状态
    bool m_isRunning;                           // 是否正在运行
    bool m_isPaused;                            // 是否暂停
    bool m_isMinimized;                         // 是否最小化

    // 时间
    WTime m_lastFrameTime;                      // 上一帧时间
    WTimer m_timer;                             // 计时器

    // 窗口
    std::shared_ptr<WWindow> m_window;      // 窗口

protected:
    WApplication();

    WApplication(const WApplication &) = delete;

    WApplication & operator=(const WApplication &) = delete;

    ~WApplication();

public:
    /**
     * @brief 获取引擎入口
     */
    static WApplication & getApplication();

    /**
     * @brief 获取窗口
     */
    std::shared_ptr<WWindow> getWindow() const;
};

} // namespace engine
