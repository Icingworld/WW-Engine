#pragma once

#include <string>
#include <iostream>
#include <GLFW/glfw3.h>
#include <event/ww_event.h>

namespace engine
{

/**
 * @brief GLFW 窗口数据
 */
class WindowData
{
public:
    std::string m_title;                                    // 窗口标题
    int m_width, m_height;                                  // 窗口尺寸

    /**
     * 当窗口捕获事件后，传递给该事件回调，该事件回调应该由App注册
     * 因此发生事件后，传递到App中逐个图层分发、处理事件
     */
    std::function<void(Event &)> m_eventCallback;           // 事件回调

public:
    WindowData(std::string title, int width, int height);
};

/**
 * @brief 窗口基类
 */
class WindowBase
{
protected:
    WindowData m_windowData;                                // 窗口数据
    GLFWwindow * m_window;                                  // GLFW 窗口

public:
    WindowBase();

    WindowBase(std::string title, int width, int height);

    virtual ~WindowBase() = default;

public:
    /**
     * @brief 初始化窗口
     */
    virtual void init();

    /**
     * @brief 关闭窗口
     */
    virtual void close();

    /**
     * @brief 渲染窗口
     */
    virtual void render();

    /**
     * @brief 获取窗口标题
     */
    const std::string & getTitle() const;

    /**
     * @brief 获取窗口宽度
     */
    int getWidth() const;

    /**
     * @brief 获取窗口高度
     */
    int getHeight() const;

    /**
     * @brief 获取GLFW窗口
     */
    GLFWwindow * getWindow() const;

    /**
     * @brief 设置窗口标题
     */
    void setTitle(const std::string & title);

    /**
     * @brief 设置窗口大小
     */
    void setSize(int width, int height);

    /**
     * @brief 设置窗口宽度
     */
    void setWidth(int width);

    /**
     * @brief 设置窗口高度
     */
    void setHeight(int height);

    /**
     * @brief 设置事件回调
     */
    void setEventCallback(const std::function<void(Event &)> & callback);
};

} // namespace engine
