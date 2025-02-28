#include "w_shader.h"

#include <iostream>

#include <w_file_system.h>

namespace engine
{

WShader::WShader()
    : m_shaderID(0)
{
}

WShader::WShader(const std::string & vertexPath, const std::string & fragmentPath)
    : WShader()
{
    compileAndLink(vertexPath, fragmentPath);
}

WShader::~WShader()
{
    glDeleteProgram(m_shaderID);
}

void WShader::use()
{
    glUseProgram(m_shaderID);
}

void WShader::deactivate()
{
    glUseProgram(0);
}

void WShader::setBool(const std::string & name, bool value) const
{
    glUniform1i(glGetUniformLocation(m_shaderID, name.c_str()), static_cast<int>(value));
}

void WShader::setInt(const std::string & name, int value) const
{
    glUniform1i(glGetUniformLocation(m_shaderID, name.c_str()), value);
}

void WShader::setFloat(const std::string & name, float value) const
{
    glUniform1f(glGetUniformLocation(m_shaderID, name.c_str()), value);
}

void WShader::setVec2(const std::string & name, const vec2 & value) const
{
    glUniform2f(glGetUniformLocation(m_shaderID, name.c_str()), value.x, value.y);
}

void WShader::setVec3(const std::string & name, const vec3 & value) const
{
    glUniform3f(glGetUniformLocation(m_shaderID, name.c_str()), value.x, value.y, value.z);
}

void WShader::setVec4(const std::string & name, const vec4 & value) const
{
    glUniform4f(glGetUniformLocation(m_shaderID, name.c_str()), value.x, value.y, value.z, value.w);
}

void WShader::setMat3(const std::string & name, const mat3 & value) const
{
    glUniformMatrix3fv(glGetUniformLocation(m_shaderID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void WShader::setMat4(const std::string & name, const mat4 & value) const
{
    glUniformMatrix4fv(glGetUniformLocation(m_shaderID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void WShader::setIntArray(const std::string & name, int * values, unsigned int count) const
{
    glUniform1iv(glGetUniformLocation(m_shaderID, name.c_str()), count, values);
}

void WShader::setFloatArray(const std::string & name, float * values, unsigned int count) const
{
    glUniform1fv(glGetUniformLocation(m_shaderID, name.c_str()), count, values);
}

void WShader::compileAndLink(const std::string & vertexPath, const std::string & fragmentPath)
{
    // 读取代码
    std::string vertexCode = WFileSystem::readTextFile(vertexPath);
    std::string fragmentCode = WFileSystem::readTextFile(fragmentPath);

    const char * vertexShaderCode = vertexCode.c_str();
    const char * fragmentShaderCode = fragmentCode.c_str();

    // 编译着色器
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderCode, nullptr);
    glCompileShader(vertexShader);
    checkShaderErrors(vertexShader, "VERTEX");

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderCode, nullptr);
    glCompileShader(fragmentShader);
    checkShaderErrors(fragmentShader, "FRAGMENT");

    // 着色器程序
    m_shaderID = glCreateProgram();
    glAttachShader(m_shaderID, vertexShader);
    glAttachShader(m_shaderID, fragmentShader);
    glLinkProgram(m_shaderID);
    checkShaderErrors(m_shaderID, "PROGRAM");

    // 删除着色器
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void WShader::checkShaderErrors(GLuint shader, const std::string & type) const
{
    int success;
    char infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
            std::cerr << "ERROR::SHADER_COMPILATION_ERROR of type: " << type.c_str() << "\n" << infoLog << "\n" << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
            std::cerr << "ERROR::PROGRAM_LINKING_ERROR of type: " << type.c_str() << "\n" << infoLog << "\n" << std::endl;
        }
    }
}

} // namespace engine
