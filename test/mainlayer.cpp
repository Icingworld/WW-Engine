#include "mainlayer.h"

#include <w_imgui.h>
#include <w_event_dispatcher.h>
#include <w_input.h>

MainLayer::MainLayer(const std::string & name)
    : engine::WLayer(name)
    , m_sandCube()
    , m_dirtCube()
    , m_skyBox()
    , m_camera()
{
}

MainLayer::~MainLayer()
{
}

void MainLayer::onAttach()
{
    m_sandCube.init();
    m_skyBox.init();
}

void MainLayer::onDetach()
{
}

void MainLayer::onUpdate(engine::WTimeStep ts)
{
    float cameraSpeed = 0.001f * ts.getStep().milliseconds();
    if (engine::WInput::isKeyPressed(engine::WKeyCode::W)) {
        m_camera.setPosition(m_camera.getPosition() + m_camera.getFront() * cameraSpeed);
    } else if (engine::WInput::isKeyPressed(engine::WKeyCode::S)) {
        m_camera.setPosition(m_camera.getPosition() - m_camera.getFront() * cameraSpeed);
    } else if (engine::WInput::isKeyPressed(engine::WKeyCode::A)) {
        m_camera.setPosition(m_camera.getPosition() - glm::normalize(glm::cross(m_camera.getFront(), m_camera.getUp())) * cameraSpeed);
    } else if (engine::WInput::isKeyPressed(engine::WKeyCode::D)) {
        m_camera.setPosition(m_camera.getPosition() + glm::normalize(glm::cross(m_camera.getFront(), m_camera.getUp())) * cameraSpeed);
    }
    // 更新摄像机
    m_camera.updateViewMatrix();
    m_camera.updateProjectionMatrix();

    // 设置泥土参数
    m_dirtCube.m_dirtCubeShader.use();
    engine::mat4 model = engine::mat4(1.0f);
    m_dirtCube.m_dirtCubeShader.setMat4("model", engine::translate(model, engine::vec3(2.0f, 2.0f, 2.0f)));
    m_dirtCube.m_dirtCubeShader.setMat4("view", m_camera.getViewMatrix());
    m_dirtCube.m_dirtCubeShader.setMat4("projection", m_camera.getProjectionMatrix());

    // 绘制泥土
    m_dirtCube.draw();

    // 设置沙子参数
    m_sandCube.m_sandCubeShader.use();
    m_sandCube.m_sandCubeShader.setMat4("model", engine::mat4(1.0f));
    m_sandCube.m_sandCubeShader.setMat4("view", m_camera.getViewMatrix());
    m_sandCube.m_sandCubeShader.setMat4("projection", m_camera.getProjectionMatrix());

    // 绘制沙子
    // m_sandCube.draw();

    glDepthFunc(GL_LEQUAL);

    // 设置天空盒参数
    m_skyBox.m_skyBoxShader.use();
    m_skyBox.m_skyBoxShader.setMat4("view", engine::mat4(engine::mat3(m_camera.getViewMatrix())));
    m_skyBox.m_skyBoxShader.setMat4("projection", m_camera.getProjectionMatrix());

    // 绘制天空盒
    m_skyBox.draw();

    glDepthFunc(GL_LESS);
}

void MainLayer::onImGuiRender()
{
    // ImGui::Text("Hello, world!");
}

void MainLayer::onEvent(engine::WEvent & event)
{
    engine::WEventDispatcher dispatcher(event);

    dispatcher.dispatch<engine::WMouseMovedEvent>([this](engine::WMouseMovedEvent & e) {
        return onMouseMovedCallback(e);
    });

    dispatcher.dispatch<engine::WMouseScrolledEvent>([this](engine::WMouseScrolledEvent & e) {
        return onMouseScrollCallback(e);
    });
}

bool MainLayer::onMouseMovedCallback(engine::WMouseMovedEvent & e)
{
    if (m_camera.isFirstMouse())
    {
        m_lastX = e.getX();
        m_lastY = e.getY();
        m_camera.setIsFirstMouse(false);
    }

    float xoffset = e.getX() - m_lastX; // 鼠标X轴是正向的
    float yoffset = m_lastY - e.getY(); // 鼠标Y轴是反向的

    m_lastX = e.getX();
    m_lastY = e.getY();

    float sensitivity = 0.03f; // 鼠标灵敏度
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw   += xoffset;
    pitch += yoffset;

    // 限制俯仰角范围
    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    // 根据 yaw 和 pitch 更新摄像机的前向量
    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    m_camera.setFront(glm::normalize(front));
    return true;
}

bool MainLayer::onMouseScrollCallback(engine::WMouseScrolledEvent & e)
{
    m_camera.setFov(m_camera.getFov() - e.getYOffset());
    if (m_camera.getFov() < 1.0f)
        m_camera.setFov(1.0f);
    if (m_camera.getFov() > 89.0f)
        m_camera.setFov(89.0f);
    return true;
}