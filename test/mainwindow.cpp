#include "mainwindow.h"

#include "mainlayer.h"

MainWindow::MainWindow()
    : engine::WWindow("Hello WW-Engine", 800, 800)
    , m_app(engine::WApplication::getApplication())
{
    // 设置GL参数
    glfwSwapInterval(1);        // 开启垂直同步
    glEnable(GL_DEPTH_TEST);    // 开启深度测试
    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // 隐藏鼠标

    m_app.pushLayer(new MainLayer("MainLayer"));
}