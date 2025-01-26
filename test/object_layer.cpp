#include "object_layer.h"

#include <imgui.h>
#include <glm/gtc/matrix_transform.hpp>

ObjectLayer::ObjectLayer(std::string name)
    : Layer(name)
    , m_shader("cube shader")
{
    m_shader.compileShader("assets/shader/cube.vs", "assets/shader/cube.fs");
}

void ObjectLayer::onUpdate(engine::TimeStep ts)
{
    // 更新逻辑
    // 计算帧率
    m_time[m_frame % 100] = ts.getStepMillis();
    if (m_frame % 100 == 0) {
        float sum = 0.0f;
        for (int i = 0; i < 100; ++i) {
            sum += m_time[i];
        }
        m_fps = 1000.0f * 100.0f / sum;
    }
    ++m_frame;

    // 旋转
    m_cube.m_angle += m_cube.m_rotationSpeed * ts.getStep();
    glm::mat4 model = glm::rotate(glm::mat4(1.0f), m_cube.m_angle, m_cube.m_axis);
    m_shader.setMat4("model", model);

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
    ImGui::Text("FPS: %.2f", m_fps);
}