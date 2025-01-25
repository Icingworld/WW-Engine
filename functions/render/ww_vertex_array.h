#pragma once

#include <ww_vector.h>

namespace engine
{

/**
 * @brief 顶点数组
 */
class VertexArray
{
protected:
    unsigned int m_vao;                     // 顶点数组对象
    wwstl::vector<unsigned int> m_vbos;     // 顶点缓冲对象
    unsigned int m_ebo;                     // 索引缓冲对象

public:
    VertexArray();

    virtual ~VertexArray() = default;

public:
    /**
     * @brief 使用顶点数组
     */
    virtual void bind() const = 0;

    /**
     * @brief 释放顶点数组
     */
    virtual void unbind() const = 0;

    /**
     * @brief 添加顶点缓冲对象
     */
    virtual void addVBO(unsigned int vbo) = 0;

    /**
     * @brief 绑定索引缓冲对象
     */
    virtual void bindEBO(unsigned int ebo) = 0;
};

} // namespace engine
