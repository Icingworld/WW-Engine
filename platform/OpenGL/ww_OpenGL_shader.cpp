#include "ww_OpenGL_shader.h"

#include <glad/glad.h>
#include <sstream>
#include <iostream>
#include <fstream>

namespace engine
{

OpenGLShader::OpenGLShader(std::string name)
    : Shader(name)
{
}

OpenGLShader::~OpenGLShader()
{
    if (m_shaderID != 0) {
        glDeleteProgram(m_shaderID);
    }
}

void OpenGLShader::bind()
{
    glUseProgram(m_shaderID);
}

void OpenGLShader::unbind()
{
    glUseProgram(0);
}

void OpenGLShader::setBool(bool value)
{
    glUniform1i(glGetUniformLocation(m_shaderID, m_name.c_str()), static_cast<int>(value));
}

void OpenGLShader::setInt(int value)
{
    glUniform1i(glGetUniformLocation(m_shaderID, m_name.c_str()), value);
}

void OpenGLShader::setFloat(float value)
{
    glUniform1f(glGetUniformLocation(m_shaderID, m_name.c_str()), value);
}

void OpenGLShader::setVec2(glm::vec2 value)
{
    glUniform2f(glGetUniformLocation(m_shaderID, m_name.c_str()), value.x, value.y);
}

void OpenGLShader::setVec3(glm::vec3 value)
{
    glUniform3f(glGetUniformLocation(m_shaderID, m_name.c_str()), value.x, value.y, value.z);
}

void OpenGLShader::setVec4(glm::vec4 value)
{
    glUniform4f(glGetUniformLocation(m_shaderID, m_name.c_str()), value.x, value.y, value.z, value.w);
}

void OpenGLShader::setMat3(glm::mat3 value)
{
    glUniformMatrix3fv(glGetUniformLocation(m_shaderID, m_name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void OpenGLShader::setMat4(glm::mat4 value)
{
    glUniformMatrix4fv(glGetUniformLocation(m_shaderID, m_name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void OpenGLShader::compileShader(const std::string & vertexPath, const std::string & fragmentPath)
{
    std::string vertexCode;
    std::string fragmentCode;

    std::ifstream vertexShaderFile;
    std::ifstream fragmentShaderFile;
    
    vertexShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fragmentShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    try {
        vertexShaderFile.open(vertexPath);
        fragmentShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << vertexShaderFile.rdbuf();
        fShaderStream << fragmentShaderFile.rdbuf();

        vertexShaderFile.close();
        fragmentShaderFile.close();

        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    } catch (std::ifstream::failure& e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
    }

    const char* vertexShaderCode = vertexCode.c_str();
    const char * fragmentShaderCode = fragmentCode.c_str();

    // 编译着色器
    unsigned int vertex, fragment;

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexShaderCode, nullptr);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentShaderCode, nullptr);
    glCompileShader(fragment);
    checkCompileErrors(vertex, "FRAGMENT");

    // 着色器程序
    m_shaderID = glCreateProgram();
    glAttachShader(m_shaderID, vertex);
    glAttachShader(m_shaderID, fragment);
    glLinkProgram(m_shaderID);
    checkCompileErrors(vertex, "PROGRAM");

    // 删除着色器
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void OpenGLShader::checkCompileErrors(unsigned int shader, std::string type)
{
    int success;
    char infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}

} // namespace engine
