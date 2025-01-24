#pragma once

#include <render/ww_shader.h>

namespace engine
{

class OpenGLShader : public Shader
{
public:
    OpenGLShader(std::string name);

    ~OpenGLShader() override;

public:
    void bind() override;

    void unbind() override;

    void setBool(bool value) override;

    void setInt(int value) override;

    void setFloat(float value) override;

    void setVec2(glm::vec2 value) override;

    void setVec3(glm::vec3 value) override;

    void setVec4(glm::vec4 value) override;

    void setMat3(glm::mat3 value) override;

    void setMat4(glm::mat4 value) override;

public:
    /**
     * @brief 编译顶点着色器和片段着色器
     */
    void compileShader(const std::string & vertexShader, const std::string & fragmentShader); 

private:
    /**
     * @brief 检查着色器编译错误
     */
    void checkCompileErrors(unsigned int shader, std::string type);
};

} // namespace engine
