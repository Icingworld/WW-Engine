#include "cube.h"

#include <glad/glad.h>

Cube::Cube()
    : m_vertexArray()
{
    // 初始化立方体顶点

    float vertices[216] = {
        // 顶点坐标，        颜色，             纹理坐标    面ID
        // 正面4个点
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,   // 0 左下
        0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,    // 1 右下
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f,     // 2 右上
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,    // 3 左上
        // 左侧4个点
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,  // 4 左下
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,   // 5 右下
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,    // 6 右上
        -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,   // 7 左上
        // 右侧4个点
        0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 2.0f,    // 8 左下
        0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 2.0f,   // 9 右下
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 2.0f,    // 10 右上
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 2.0f,     // 11 左上
        // 上侧4个点
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 3.0f,    // 12 左下
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 3.0f,     // 13 右下
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 3.0f,    // 14 右上
        -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 3.0f,   // 15 左上
        // 下侧4个点
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 4.0f,  // 16 左下
        0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 4.0f,   // 17 右下
        0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 4.0f,    // 18 右上
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 4.0f,   // 19 左上
        // 背面4个点
        0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 5.0f,   // 20 左下
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 5.0f,  // 21 右下
        -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 5.0f,   // 22 右上
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 5.0f,    // 23 左上
    };

    // 立方体索引
    unsigned int indices[36] = {
        // 正面
        0, 1, 3,
        3, 1, 2,
        // 左侧
        4, 5, 7,
        7, 5, 6,
        // 右侧
        8, 9, 11,
        11, 9, 10,
        // 上侧
        12, 13, 15,
        15, 13, 14,
        // 下侧
        16, 17, 19,
        19, 17, 18,
        // 背面
        20, 21, 23,
        23, 21, 22
    };

    // 激活VAO
    m_vertexArray.bind();

    // 创建顶点缓冲对象
    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 设置顶点属性指针

    // 激活位置
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // 激活颜色
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // 绑定到VAO
    m_vertexArray.addVBO(vbo);

    // 创建索引缓冲对象
    unsigned int ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // 绑定到VAO
    m_vertexArray.bindEBO(ebo);

    // 取消激活VAO
    m_vertexArray.unbind();
}

Cube::~Cube()
{
}

void Cube::draw()
{
    m_vertexArray.bind();
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}
