#include "w_windows_window.h"

#include <glad/glad.h>

#include <w_key_event.h>
#include <w_mouse_event.h>
#include <w_window_event.h>

namespace engine
{

WWindowsWindow::WWindowsWindow()
    : WWindowsWindow("Untitled", 800, 600)
{
}

WWindowsWindow::WWindowsWindow(const std::string & title, const int width, const int height)
    : WWindowBase(title, width, height)
    , m_window(nullptr)
{
    init();
}

WWindowsWindow::~WWindowsWindow()
{
    close();
}

void WWindowsWindow::init()
{
    // 初始化GLFW
    if (!glfwInit()) {
        std::cout << "GLFW init failed" << std::endl;
        return;
    }

    // 配置 OpenGL 版本和核心模式
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                  // OpenGL 主版本号
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);                  // OpenGL 次版本号
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 使用核心模式

    // 创建窗口
    m_window = glfwCreateWindow(getWidth(), getHeight(), getTitle().c_str(), nullptr, nullptr);
    if (!m_window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    // 设置窗口上下文
    glfwMakeContextCurrent(m_window);

    // 初始化 GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }

    // 设置窗口用户指针
    glfwSetWindowUserPointer(m_window, &m_windowData);

    // 窗口关闭回调
    glfwSetWindowCloseCallback(m_window, [](GLFWwindow * window) {
        // 获取 WindowData
        WWindowData * data = static_cast<WWindowData*>(glfwGetWindowUserPointer(window));

        // 创建事件并下发
        WWindowCloseEvent event;
        data->m_eventCallback(event);
    });

    // 窗口大小回调
    glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow * window, int width, int height) {
        // 获取 WindowData
        WWindowData * data = static_cast<WWindowData*>(glfwGetWindowUserPointer(window));
        data->m_width = width;
        data->m_height = height;

        // 创建事件并下发
        WWindowResizeEvent event(width, height);
        data->m_eventCallback(event);
    });

    // 窗口按键回调
    glfwSetKeyCallback(m_window, [](GLFWwindow * window, int key, int scancode, int action, int mods) {
        // 创建按键类型
        WKeyCode keycode = static_cast<WKeyCode>(key);

        // 获取 WindowData
        WWindowData * data = static_cast<WWindowData*>(glfwGetWindowUserPointer(window));

        // 创建事件并下发
        switch (action) {
            case GLFW_RELEASE: {
                // 释放按键
                WKeyReleasedEvent event(keycode);
                data->m_eventCallback(event);
                break;
            }
            case GLFW_PRESS: {
                // 按下按键
                WKeyPressedEvent event(keycode, false);
                data->m_eventCallback(event);
                break;
            }
            case GLFW_REPEAT: {
                // 重复按键
                WKeyPressedEvent event(keycode, true);
                data->m_eventCallback(event);
                break;
            }
            default:
                break;
        }
    });

    // 鼠标移动回调
    glfwSetCursorPosCallback(m_window, [](GLFWwindow * window, double x, double y) {
        // 获取 WindowData
        WWindowData * data = static_cast<WWindowData*>(glfwGetWindowUserPointer(window));

        // 创建事件并下发
        WMouseMovedEvent event(x, y);
        data->m_eventCallback(event);
    });

    // 鼠标滚轮回调
    glfwSetScrollCallback(m_window, [](GLFWwindow * window, double x, double y) {
        // 获取 WindowData
        WWindowData * data = static_cast<WWindowData*>(glfwGetWindowUserPointer(window));

        // 创建事件并下发
        WMouseScrolledEvent event(x, y);
        data->m_eventCallback(event);
    });
}

void WWindowsWindow::close()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void WWindowsWindow::render()
{
    glfwPollEvents();
    glfwSwapBuffers(m_window);
}

void WWindowsWindow::clear()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);   // 暂时使用一种颜色来清屏
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

GLFWwindow * WWindowsWindow::getWindow() const
{
    return m_window;
}

} // namespace engine
