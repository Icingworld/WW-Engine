#pragma once

#include <glad/glad.h>

#include <w_math.h>

namespace engine
{

/**
 * @brief 着色器
 */
class WShader
{
protected:
    GLuint m_shaderID;      // 着色器程序ID

public:
    WShader();

    WShader(const std::string & vertexPath, const std::string & fragmentPath);

    virtual ~WShader();

public:
    /**
     * @brief 激活着色器
     */
    void use();

    /**
     * @brief 取消激活着色器
     */
    void deactivate();

    /**
     * @brief 设置布尔值
     */
    void setBool(const std::string & name, bool value) const;

    /**
     * @brief 设置整数
     */
    void setInt(const std::string & name, int value) const;

    /**
     * @brief 设置浮点数
     */
    void setFloat(const std::string & name, float value) const;

    /**
     * @brief 设置2D向量
     */
    void setVec2(const std::string & name, const vec2 & value) const;

    /**
     * @brief 设置3D向量
     */
    void setVec3(const std::string & name, const vec3 & value) const;

    /**
     * @brief 设置4D向量
     */
    void setVec4(const std::string & name, const vec4 & value) const;

    /**
     * @brief 设置3x3矩阵
     */
    void setMat3(const std::string & name, const mat3 & value) const;

    /**
     * @brief 设置4x4矩阵
     */
    void setMat4(const std::string & name, const mat4 & value) const;

    /**
     * @brief 设置整型数组
     */
    void setIntArray(const std::string & name, int * values, unsigned int count) const;

    /**
     * @brief 设置浮点型数组
     */
    void setFloatArray(const std::string & name, float * values, unsigned int count) const;

    /**
     * @brief 编译、链接着色器
     * @param vertexPath 顶点着色器路径
     * @param fragmentPath 片段着色器路径
     */
    void compileAndLink(const std::string & vertexPath, const std::string & fragmentPath);

    /**
     * @brief 检查着色器编译、链接是否成功
     */
    void checkShaderErrors(GLuint shader, const std::string & type) const;
};

} // namespace engine
