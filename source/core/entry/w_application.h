#pragma once

#include <w_window.h>
#include <w_layer_stack.h>
#include <w_imgui_layer.h>

#include "../time/w_timer.h"

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
    std::shared_ptr<WWindow> m_window;          // 窗口

    // 图层
    WLayerStack m_layerStack;                   // 图层栈
    std::shared_ptr<WImGuiLayer> m_imguiLayer;  // ImGui 图层

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
     * @brief 主循环
     */
    void run();

    /**
     * @brief 停止循环
     */
    void stop();

    /**
     * @brief 添加普通图层
     */
    void pushLayer(WLayer * layer);

    /**
     * @brief 添加覆盖图层
     */
    void pushOverlay(WLayer * layer);

    /**
     * @brief 事件处理
     */
    void onEvent(WEvent & event);

    /**
     * @brief 绑定窗口
     */
    void bindWindow(std::shared_ptr<WWindow> window);

    /**
     * @brief 获取窗口
     */
    std::shared_ptr<WWindow> getWindow() const;
};

} // namespace engine
