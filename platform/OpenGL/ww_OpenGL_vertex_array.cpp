#include "ww_OpenGL_vertex_array.h"

#include <glad/glad.h>

namespace engine
{

OpenGLVertexArray::OpenGLVertexArray()
    : VertexArray()
{
    glGenVertexArrays(1, &m_vao);
}

OpenGLVertexArray::~OpenGLVertexArray()
{
    for (auto vbo : m_vbos) {
        if (vbo != 0) {
            glDeleteBuffers(1, &vbo);
        }
    }

    if (m_ebo != 0) {
        glDeleteBuffers(1, &m_ebo);
    }

    glDeleteVertexArrays(1, &m_vao);
}

void OpenGLVertexArray::bind() const
{
    glBindVertexArray(m_vao);
}

void OpenGLVertexArray::unbind() const
{
    glBindVertexArray(0);
}

void OpenGLVertexArray::addVBO(unsigned int vbo)
{
    m_vbos.emplace_back(vbo);
}

void OpenGLVertexArray::bindEBO(unsigned int ebo)
{
    m_ebo = ebo;
}

OpenGLVertexArray OpenGLVertexArray::create()
{
    return OpenGLVertexArray();
}

} // namespace engine
