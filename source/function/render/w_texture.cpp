#include "w_texture.h"

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <w_file_system.h>

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
    auto fullPath = WFileSystem::getAbsolutePath(path);
    unsigned char * data = stbi_load(fullPath.string().c_str(), &m_width, &m_height, &m_channels, 0);

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

void WTexture2D::updateData(const void * data)
{
    glBindTexture(GL_TEXTURE_2D, m_textureID);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, m_width, m_height, m_format, GL_UNSIGNED_BYTE, data);
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

WTexture2DArray::WTexture2DArray(int width, int height, int layers, GLenum format)
    : WTexture(TextureType::Texture2DArray)
    , m_width(width)
    , m_height(height)
    , m_channels(0)
    , m_layers(layers)
    , m_format(format)
{
    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D_ARRAY, m_textureID);

    // 创建空的 2D 纹理数组
    glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, format, width, height, layers, 0, format, GL_UNSIGNED_BYTE, nullptr);

    setTextureParams(GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D_ARRAY, 0);
}

WTexture2DArray::WTexture2DArray(const std::vector<std::string> & paths)
    : WTexture(TextureType::Texture2DArray)
    , m_width(0)
    , m_height(0)
    , m_channels(0)
    , m_layers(paths.size())
    , m_format(0)
{
    stbi_set_flip_vertically_on_load(1);

    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D_ARRAY, m_textureID);

    unsigned char * data = nullptr;
    // 假设所有图像的尺寸相同
    for (int i = 0; i < m_layers; ++i) {
        auto fullPath = WFileSystem::getAbsolutePath(paths[i]);
        data = stbi_load(fullPath.string().c_str(), &m_width, &m_height, &m_channels, 0);

        if (!data) {
            std::cerr << "Error: Failed to load texture: " << paths[i] << std::endl;
            return;
        }

        if (m_channels == 3) {
            m_format = GL_RGB;
        }
        else if (m_channels == 4) {
            m_format = GL_RGBA;
        }

        glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, i, m_width, m_height, 1, m_format, GL_UNSIGNED_BYTE, data);

        stbi_image_free(data);
    }

    glGenerateMipmap(GL_TEXTURE_2D_ARRAY);

    setTextureParams(GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D_ARRAY, 0);
}

WTexture2DArray::WTexture2DArray(const std::vector<void *> & data, int width, int height, GLenum format)
    : WTexture(TextureType::Texture2DArray)
    , m_width(width)
    , m_height(height)
    , m_channels(0)
    , m_layers(data.size())
    , m_format(format)
{
    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D_ARRAY, m_textureID);

    for (int i = 0; i < m_layers; ++i) {
        glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, i, m_width, m_height, 1, m_format, GL_UNSIGNED_BYTE, data[i]);
    }

    glGenerateMipmap(GL_TEXTURE_2D_ARRAY);

    setTextureParams(GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D_ARRAY, 0);
}

WTexture2DArray::~WTexture2DArray()
{
    glDeleteTextures(1, &m_textureID);
}

void WTexture2DArray::bind(unsigned int slot) const
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D_ARRAY, m_textureID);
}

void WTexture2DArray::unbind() const
{
    glBindTexture(GL_TEXTURE_2D_ARRAY, 0);
}

void WTexture2DArray::setTextureParams(GLint wrapS, GLint wrapT, GLint minFilter, GLint magFilter)
{
    glBindTexture(GL_TEXTURE_2D_ARRAY, m_textureID);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, wrapS);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, wrapT);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, minFilter);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, magFilter);
    glBindTexture(GL_TEXTURE_2D_ARRAY, 0);
}

void WTexture2DArray::updateLayerData(const void * data, int layer)
{
    if (layer < 0 || layer >= m_layers) {
        std::cerr << "Error: Invalid layer index" << std::endl;
        return;
    }

    glBindTexture(GL_TEXTURE_2D_ARRAY, m_textureID);
    glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, layer, m_width, m_height, 1, m_format, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D_ARRAY, 0);
}

int WTexture2DArray::getWidth() const
{
    return m_width;
}

int WTexture2DArray::getHeight() const
{
    return m_height;
}

int WTexture2DArray::getChannels() const
{
    return m_channels;
}

int WTexture2DArray::getLayers() const
{
    return m_layers;
}

WTextureCube::WTextureCube(int width, int height, GLenum format)
    : WTexture(TextureType::TextureCube)
    , m_width(width)
    , m_height(height)
    , m_channels(0)
    , m_format(format)
{
    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureID);

    for (GLuint i = 0; i < 6; ++i) {
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, nullptr);
    }

    setTextureParams(GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR);

    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

WTextureCube::WTextureCube(const std::array<std::string, 6> & paths)
    : WTexture(TextureType::TextureCube)
    , m_width(0)
    , m_height(0)
    , m_channels(0)
    , m_format(0)
{
    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureID);

    unsigned char * data = nullptr;
    for (GLuint i = 0; i < 6; ++i) {
        auto fullPath = WFileSystem::getAbsolutePath(paths[i]);
        data = stbi_load(fullPath.string().c_str(), &m_width, &m_height, &m_channels, 0);

        if (!data) {
            std::cerr << "Error: Failed to load texture: " << paths[i] << std::endl;
            return;
        }

        if (m_channels == 3) {
            m_format = GL_RGB;
        }
        else if (m_channels == 4) {
            m_format = GL_RGBA;
        }

        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, m_format, m_width, m_height, 0, m_format, GL_UNSIGNED_BYTE, data);

        stbi_image_free(data);
    }

    setTextureParams(GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR);

    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

WTextureCube::~WTextureCube()
{
    glDeleteTextures(1, &m_textureID);
}

void WTextureCube::bind(unsigned int slot) const
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureID);
}

void WTextureCube::unbind() const
{
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

void WTextureCube::setTextureParams(GLint wrapMode, GLint minFilter, GLint magFilter)
{
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureID);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, wrapMode);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, wrapMode);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, wrapMode);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, minFilter);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, magFilter);
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

int WTextureCube::getWidth() const
{
    return m_width;
}

int WTextureCube::getHeight() const
{
    return m_height;
}

int WTextureCube::getChannels() const
{
    return m_channels;
}

} // namespace engine
