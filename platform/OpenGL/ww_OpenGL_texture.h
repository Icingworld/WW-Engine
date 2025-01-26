#pragma once

#include <render/ww_texture.h>

namespace engine
{

class OpenGLTexture2D : public Texture2D
{
public:
    OpenGLTexture2D(std::string path);

    ~OpenGLTexture2D() override;

public:
    void bind(unsigned int slot = 0) const override;
};

} // namespace engine
