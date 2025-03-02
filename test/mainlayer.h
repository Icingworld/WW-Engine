#pragma once

#include <w_layer.h>
#include <w_camera.h>
#include <w_key_event.h>
#include <w_mouse_event.h>

#include "cube.h"
#include "skybox.h"

/**
 * @brief 主图层
 */
class MainLayer
    : public engine::WLayer
{
private:
    SandCube m_sandCube;            // 沙子
    Skybox m_skyBox;                // 天空盒
    engine::WCamera m_camera;       // 相机

    float m_lastX = 400;
    float m_lastY = 300;
    float yaw   = -90.0f;           // 摄像机的水平角度
    float pitch =  0.0f;            // 摄像机的俯仰角

public:
    MainLayer(const std::string & name);

    ~MainLayer() override;

public:
    void onAttach() override;

    void onDetach() override;

    void onUpdate(engine::WTimeStep ts) override;

    void onImGuiRender() override;

    void onEvent(engine::WEvent & event) override;

private:
    bool onMouseMovedCallback(engine::WMouseMovedEvent & e);

    bool onMouseScrollCallback(engine::WMouseScrolledEvent & e);
};
