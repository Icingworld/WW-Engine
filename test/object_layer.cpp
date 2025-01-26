#include "object_layer.h"

#include <imgui.h>

ObjectLayer::ObjectLayer(std::string name)
    : Layer(name)
    , m_shader("cube shader")
{
    m_shader.compileShader("assets/shader/cube.vs", "assets/shader/cube.fs");
}

void ObjectLayer::onUpdate(engine::TimeStep ts)
{
    // 激活纹理
    m_cube.activeTexture();

    // 渲染
    m_shader.bind();    // 激活着色器程序

    // 绘制立方体
    m_cube.draw();
}

void ObjectLayer::onImGuiRender()
{
    ImGui::Text("WW-Engine Test ImGUI");
}