#include "ww_shader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace engine
{

Shader::Shader(std::string name)
    : m_shaderID(0)
    , m_name(name)
{
}

const std::string & Shader::getName() const
{
    return m_name;
}

} // namespace engine
