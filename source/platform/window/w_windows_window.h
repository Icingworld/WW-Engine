#pragma once

#include <GLFW/glfw3.h>

#include <w_window_base.h>

namespace engine
{

/**
 * @brief Windows窗口
 */
class WWindowsWindow
    : public WWindowBase
{
protected:
    GLFWwindow * m_window;          // GLFW窗口

public:
    WWindowsWindow();

    WWindowsWindow(const std::string & title, const int width, const int height);

    ~WWindowsWindow() override;

public:
    void init() override;

    void close() override;

    void render() override;

    void clear() override;

public:
    GLFWwindow * getWindow() const;
};

} // namespace engine
