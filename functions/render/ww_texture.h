#pragma once

namespace engine
{

enum class ImageType
{
    None = 0,
    RGB,        // RGB
    RGBA        // RGBA
};

/**
 * @brief 纹理
 */
class Texture
{
protected:
    unsigned int m_texture;         // 纹理ID
    ImageType m_type;               // 纹理类型

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
    int m_width;
    int m_height;

public:
    virtual ~Texture2D() = default;

public:
};

} // namespace engine
