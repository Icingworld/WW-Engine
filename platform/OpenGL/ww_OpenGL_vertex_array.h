#pragma once

#include <render/ww_vertex_array.h>

namespace engine
{

/**
 * @brief OpenGL顶点数组
 */
class OpenGLVertexArray : public VertexArray
{
public:
    OpenGLVertexArray();

    ~OpenGLVertexArray() override;

public:
    void bind() const override;

    void unbind() const override;

    void addVBO(unsigned int vbo) override;

    void bindEBO(unsigned int ebo) override;

    /**
     * @brief 创建顶点数组
     */
    static OpenGLVertexArray create();
};

} // namespace engine
