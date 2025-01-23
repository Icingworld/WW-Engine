#include "ww_windows_window.h"

#include <event/ww_key_event.h>
#include <event/ww_mouse_event.h>
#include <event/ww_window_event.h>

namespace engine
{

WindowsWindow::WindowsWindow()
    : WindowBase()
{
    init();
}

WindowsWindow::WindowsWindow(const std::string & title, int width, int height)
    : WindowBase(title, width, height)
{
    init();
}

WindowsWindow::~WindowsWindow()
{
    close();
}

void WindowsWindow::init()
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
        std::cerr << "Failed to create GLFW window!" << std::endl;
        return;
    }

    // 设置窗口上下文
    glfwMakeContextCurrent(m_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return;
    }

    // 设置回调函数
    glfwSetWindowUserPointer(m_window, &m_windowData);

    // 窗口关闭回调
    glfwSetWindowCloseCallback(m_window, [](GLFWwindow * window) {
        // 获取 WindowData
        WindowData * data = (WindowData *)glfwGetWindowUserPointer(window);

        // 创建事件并下发
        WindowCloseEvent event;
        data->m_eventCallback(event);
    });

    // 窗口大小回调
    glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow * window, int width, int height) {
        // 获取 WindowData
        WindowData * data = (WindowData *)glfwGetWindowUserPointer(window);
        data->m_width = width;
        data->m_height = height;

        // 创建事件并下发
        WindowResizeEvent event(width, height);
        data->m_eventCallback(event);
    });

    // 窗口按键回调
    glfwSetKeyCallback(m_window, [](GLFWwindow * window, int key, int scancode, int action, int mods) {
        // 创建按键类型
        KeyCode keycode = static_cast<KeyCode>(key);

        // 获取 WindowData
        WindowData * data = (WindowData *)glfwGetWindowUserPointer(window);

        // 创建事件并下发
        if (action == GLFW_PRESS) {
            // 按下按键
            KeyPressedEvent event(keycode, false);
            data->m_eventCallback(event);
        } else if (action == GLFW_RELEASE) {
            // 释放按键
            KeyReleasedEvent event(keycode);
            data->m_eventCallback(event);
        } else if (action == GLFW_REPEAT) {
            // 重复按键
            KeyPressedEvent event(keycode, true);
            data->m_eventCallback(event);
        }
    });

    // 鼠标移动回调
    glfwSetCursorPosCallback(m_window, [](GLFWwindow * window, double x, double y) {
        // 获取 WindowData
        WindowData * data = (WindowData *)glfwGetWindowUserPointer(window);

        // 创建事件并下发
        MouseMovedEvent event(x, y);
        data->m_eventCallback(event);
    });

    // 鼠标滚轮回调
    glfwSetScrollCallback(m_window, [](GLFWwindow * window, double x, double y) {
        // 获取 WindowData
        WindowData * data = (WindowData *)glfwGetWindowUserPointer(window);

        // 创建事件并下发
        MouseScrolledEvent event(x, y);
        data->m_eventCallback(event);
    });
}

void WindowsWindow::close()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void WindowsWindow::render()
{
    glfwPollEvents();
    glfwSwapBuffers(m_window);
}

} // namespace engine
