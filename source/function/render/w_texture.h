#pragma once

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

class Texture
{
protected:
    unsigned int m_id;      // 纹理 ID
    TextureType m_type;     // 纹理类型

public:
    Texture();

    virtual ~Texture() = default;
};

} // namespace engine
