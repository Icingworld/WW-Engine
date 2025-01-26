#include "ww_OpenGL_texture.h"

#include <glad/glad.h>
#include "../file_system/ww_windows_file_system.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace engine
{

OpenGLTexture2D::OpenGLTexture2D(std::string path)
    : Texture2D(path)
{
    // 获取完整路径
    WindowsFileSystem fileSystem;
    std::string fullPath = fileSystem.toFullPath(path);

    // 加载纹理文件
    stbi_set_flip_vertically_on_load(true);
    int width, height, channels;
    unsigned char * data = stbi_load(fullPath.c_str(), &width, &height, &channels, 0);

    if (data != nullptr) {
        // 设置图片类型
        GLenum format = GL_RGB;
        if (channels == 3) {
            m_imageType = ImageType::RGB;
        } else if (channels == 4) {
            m_imageType = ImageType::RGBA;
            format = GL_RGBA;
        }

        // 生成纹理
        glGenTextures(1, &m_texture);
        glBindTexture(GL_TEXTURE_2D, m_texture);

        // 设置纹理环绕方式
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        // 设置纹理过滤方式
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // 加载图片到纹理
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

        // 生成 mipmap
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);
    }
}

OpenGLTexture2D::~OpenGLTexture2D()
{
    if (m_texture != 0) {
        glDeleteTextures(1, &m_texture);
        m_texture = 0;
    }
}

void OpenGLTexture2D::bind(unsigned int slot) const
{
    // in OpenGL3.3
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, m_texture);
}

} // namespace engine
