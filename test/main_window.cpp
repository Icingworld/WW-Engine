#include "main_window.h"

#include "sky_layer.h"
#include "object_layer.h"

MainWindow::MainWindow()
    : engine::Window("MainWindow", 600, 600)
    , m_app(engine::Application::getApplication())
{
    glEnable(GL_DEPTH_TEST);            // 启用深度测试
    glEnable(GL_CULL_FACE);             // 启用剔除
    glCullFace(GL_BACK);                // 剔除背面（默认值）
    glfwSwapInterval(1);                // 设置交换缓冲区间隔（开启垂直同步）

    // 添加图层
    SkyLayer * skyLayer = new SkyLayer("SkyLayer");
    m_app.pushLayer(skyLayer);          // 添加天空图层，需要最先渲染

    ObjectLayer * objectLayer = new ObjectLayer("ObjectLayer");
    m_app.pushLayer(objectLayer);       // 添加具体的某个图层
}
