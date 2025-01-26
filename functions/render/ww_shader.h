#pragma once

#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace engine
{

/**
 * @brief 着色器
 */
class Shader
{
protected:
    unsigned int m_shaderID;    // 着色器程序ID
    std::string m_name;         // 着色器名称

public:
    Shader(std::string name);

    virtual ~Shader() = default;

public:
    /**
     * @brief 使用着色器程序
     */
    virtual void bind() = 0;

    /**
     * @brief 取消使用着色器
     */
    virtual void unbind() = 0;

    virtual void setBool(std::string name, bool value) = 0;

    virtual void setInt(std::string name, int value) = 0;

    virtual void setFloat(std::string name, float value) = 0;

    virtual void setVec2(std::string name, glm::vec2 value) = 0;

    virtual void setVec3(std::string name, glm::vec3 value) = 0;

    virtual void setVec4(std::string name, glm::vec4 value) = 0;

    virtual void setMat3(std::string name, glm::mat3 value) = 0;

    virtual void setMat4(std::string name, glm::mat4 value) = 0;

    const std::string & getName() const;
};

} // namespace engine
