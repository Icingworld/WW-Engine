#include "ww_texture.h"

namespace engine
{

unsigned int Texture::getTexture() const
{
    return m_texture;
}

Texture2D::Texture2D(std::string path)
    : m_width(0)
    , m_height(0)
    , m_path(path)
{
    m_textureType = TextureType::Texture2D;
}

int Texture2D::getWidth() const
{
    return m_width;
}

int Texture2D::getHeight() const
{
    return m_height;
}

} // namespace engine
