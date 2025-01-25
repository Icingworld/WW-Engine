#pragma once

#include <layer/ww_layer.h>
#include <OpenGL/ww_OpenGL_shader.h>
#include "model/cube.h"

/**
 * @brief UI 图层
 */
class ObjectLayer : public engine::Layer
{
public:
    engine::OpenGLShader m_shader;
    Cube m_cube;        // 示例立方体

public:
    ObjectLayer(std::string name);

    ~ObjectLayer() override = default;

public:
    void onUpdate(engine::TimeStep ts) override;

    void onImGuiRender() override;
};