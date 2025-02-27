#pragma once

#include <iostream>
#include <functional>

#include "w_event.h"

namespace engine
{

/**
 * @brief 窗口数据
 */
class WWindowData
{
public:
    std::string m_title;                                    // 窗口标题
    int m_width;                                            // 窗口宽度
    int m_height;                                           // 窗口高度

    std::function<void(WEvent &)> m_eventCallback;          // 事件回调

public:
    WWindowData(std::string title, int width, int height);

    ~WWindowData() = default;
};

/**
 * @brief 窗口
 */
class WWindowBase
{
protected:
    WWindowData m_windowData;           // 窗口数据

public:
    WWindowBase();

    WWindowBase(std::string title, int width, int height);

    explicit WWindowBase(const WWindowData & data);

    virtual ~WWindowBase() = default;

public:
    /**
     * @brief 初始化窗口
     */
    virtual void init() = 0;

    /**
     * @brief 关闭窗口
     */
    virtual void close() = 0;

    /**
     * @brief 渲染窗口
     */
    virtual void render() = 0;

    /**
     * @brief 清空窗口
     */
    virtual void clear() = 0;

public:
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
     * @brief 获取窗口数据
     */
    const WWindowData & getWindowData() const;

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
     * @brief 设置窗口数据
     */
    void setWindowData(std::string title, int width, int height);

    /**
     * @brief 设置窗口数据
     */
    void setWindowData(const WWindowData & data);

    /**
     * @brief 设置窗口事件回调
     */
    void setEventCallback(const std::function<void(WEvent &)> & callback);
};

} // namespace engine
