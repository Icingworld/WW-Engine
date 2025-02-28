#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <w_file_system.h>

namespace engine
{

/**
 * @brief 纹理类型
 * @details 后续需要扩展
 */
enum class TextureType
{
    None = 0,
    Texture2D,              // 2D 纹理
    Texture2DArray,         // 2D 纹理数组
    TextureCube,            // 立方体纹理
    Texture3D,              // 3D 纹理
    TextureNormalMap,       // 法线纹理
    TextureDepth            // 深度纹理
};

/**
 * @brief 纹理基类
 */
class WTexture
{
protected:
    TextureType m_type;         // 纹理类型
    GLuint m_textureID;         // 纹理 ID

public:
    explicit WTexture(TextureType type);

    WTexture(const WTexture &) = delete;

    WTexture &operator=(const WTexture &) = delete;

    virtual ~WTexture() = default;

public:
    /**
     * @brief 绑定纹理
     * @param slot 纹理槽
     */
    virtual void bind(unsigned int slot = 0) const = 0;

    /**
     * @brief 解绑纹理
     */
    virtual void unbind() const = 0;

    /**
     * @brief 获取纹理 ID
     * @return 纹理 ID
     */
    GLuint getTextureId() const;
};

/**
 * @brief 2D 纹理
 */
class WTexture2D
    : public WTexture
{
protected:
    int m_width;       // 纹理宽度
    int m_height;      // 纹理高度
    int m_channels;    // 纹理通道数
    GLenum m_format;   // 纹理格式

public:
    WTexture2D(int width, int height, GLenum format);

    explicit WTexture2D(const std::string & path);

    WTexture2D(const void * data, int width, int height, GLenum format);

    ~WTexture2D() override;

public:
    void bind(unsigned int slot = 0) const override;

    void unbind() const override;

    /**
     * @brief 设置纹理参数
     * @param wrapS 横向纹理环绕方式
     * @param wrapT 纵向纹理环绕方式
     * @param minFilter 最小过滤方式
     * @param magFilter 最大过滤方式
     */
    void setTextureParams(GLint wrapS, GLint wrapT, GLint minFilter, GLint magFilter);

    int getWidth() const;

    int getHeight() const;

    int getChannels() const;
};

} // namespace engine
