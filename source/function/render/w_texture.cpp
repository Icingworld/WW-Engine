#include "w_texture.h"

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace engine
{

WTexture::WTexture(TextureType type)
    : m_type(type)
    , m_textureID(0)
{
}

GLuint WTexture::getTextureId() const
{
    return m_textureID;
}

WTexture2D::WTexture2D(int width, int height, GLenum format)
    : WTexture(TextureType::Texture2D)
    , m_width(width)
    , m_height(height)
    , m_channels(0)
    , m_format(format)
{
    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D, m_textureID);

    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, nullptr);

    setTextureParams(GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);
}

WTexture2D::WTexture2D(const std::string & path)
    : WTexture(TextureType::Texture2D)
    , m_width(0)
    , m_height(0)
    , m_channels(0)
    , m_format(0)
{
    // 加载图像
    stbi_set_flip_vertically_on_load(1);
    unsigned char * data = stbi_load(path.c_str(), &m_width, &m_height, &m_channels, 0);

    if (!data) {
        std::cerr << "Failed to load texture: " << path << std::endl;
        return;
    }

    if (m_channels == 3) {
        m_format = GL_RGB;
    } else {
        m_format = GL_RGBA;
    }

    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D, m_textureID);

    glTexImage2D(GL_TEXTURE_2D, 0, m_format, m_width, m_height, 0, m_format, GL_UNSIGNED_BYTE, data);

    glGenerateMipmap(GL_TEXTURE_2D);

    setTextureParams(GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

    stbi_image_free(data);

    glBindTexture(GL_TEXTURE_2D, 0);
}

WTexture2D::WTexture2D(const void * data, int width, int height, GLenum format)
    : WTexture(TextureType::Texture2D)
{
    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D, m_textureID);

    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

    glGenerateMipmap(GL_TEXTURE_2D);

    setTextureParams(GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);
}

WTexture2D::~WTexture2D()
{
    glDeleteTextures(1, &m_textureID);
}

void WTexture2D::bind(unsigned int slot) const
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, m_textureID);
}

void WTexture2D::unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

void WTexture2D::setTextureParams(GLint wrapS, GLint wrapT, GLint minFilter, GLint magFilter)
{
    glBindTexture(GL_TEXTURE_2D, m_textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
    glBindTexture(GL_TEXTURE_2D, 0);
}

int WTexture2D::getWidth() const
{
    return m_width;
}

int WTexture2D::getHeight() const
{
    return m_height;
}

int WTexture2D::getChannels() const
{
    return m_channels;
}

} // namespace engine
