#pragma once

#include <string>

namespace engine
{

enum class ImageType
{
    None = 0,
    RGB,        // RGB
    RGBA        // RGBA
};

enum class TextureType
{
    None = 0,
    Texture2D,          // 2D纹理
    Texture2DArray,     // 2D纹理数组
    TextureCube,        // 立方体纹理
    Texture3D           // 3D纹理
};

/**
 * @brief 纹理
 */
class Texture
{
protected:
    unsigned int m_texture;         // 纹理ID
    TextureType m_textureType;      // 纹理类型
    ImageType m_imageType;          // 纹理图片类型

public:
    virtual ~Texture() = default;

public:
    /**
     * @brief 绑定纹理
     */
    virtual void bind(unsigned int slot = 0) const = 0;

    /**
     * @brief 获取纹理ID
     */
    unsigned int getTexture() const;
};

class Texture2D : public Texture
{
protected:
    int m_width;        // 纹理宽度
    int m_height;       // 纹理高度
    std::string m_path; // 纹理路径

public:
    Texture2D(std::string path);

    virtual ~Texture2D() = default;

public:
    void bind(unsigned int slot = 0) const = 0;

    int getWidth() const;

    int getHeight() const;
};

} // namespace engine
