#pragma once

#include <OpenGL/ww_OpenGL_vertex_array.h>
#include <glm/glm.hpp>
#include <OpenGL/ww_OpenGL_texture.h>

/**
 * @brief 立方体
 */
class Cube
{
public:
    glm::vec3 m_position;                       // 位置

    float m_angle;                              // 角度
    float m_rotationSpeed;                      // 旋转速度
    glm::vec3 m_axis;                           // 旋转轴

    engine::OpenGLVertexArray m_vertexArray;    // 顶点数组

    engine::OpenGLTexture2D m_texture;          // 纹理

public:
    Cube();

    ~Cube();

public:
    /**
     * @brief 激活纹理
     */
    void activeTexture();

    /**
     * @brief 渲染
     */
    void draw();
};
