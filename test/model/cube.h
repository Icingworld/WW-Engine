#pragma once

#include <OpenGL/ww_OpenGL_vertex_array.h>
#include <glm/glm.hpp>

/**
 * @brief 立方体
 */
class Cube
{
public:
    glm::vec3 m_position;                       // 位置

    engine::OpenGLVertexArray m_vertexArray;    // 顶点数组

public:
    Cube();

    ~Cube();

public:
    /**
     * @brief 渲染
     */
    void draw();
};
