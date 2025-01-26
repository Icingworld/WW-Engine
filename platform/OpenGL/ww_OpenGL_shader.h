#pragma once

#include <render/ww_shader.h>

namespace engine
{

/**
 * @brief OpenGL着色器
 */
class OpenGLShader : public Shader
{
public:
    OpenGLShader(std::string name);

    ~OpenGLShader() override;

public:
    void bind() override;

    void unbind() override;

    void setBool(std::string name, bool value) override;

    void setInt(std::string name, int value) override;

    void setFloat(std::string name, float value) override;

    void setVec2(std::string name, glm::vec2 value) override;

    void setVec3(std::string name, glm::vec3 value) override;

    void setVec4(std::string name, glm::vec4 value) override;

    void setMat3(std::string name, glm::mat3 value) override;

    void setMat4(std::string name, glm::mat4 value) override;

public:
    /**
     * @brief 编译顶点着色器和片段着色器
     */
    void compileShader(const std::string & vertexShader, const std::string & fragmentShader);

    /**
     * @brief 创建OpenGL着色器
     */
    static OpenGLShader create(std::string name);

private:
    /**
     * @brief 检查着色器编译错误
     */
    void checkCompileErrors(unsigned int shader, std::string type);
};

} // namespace engine
