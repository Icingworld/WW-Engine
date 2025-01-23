#include "sky_layer.h"

#include <glad/glad.h>

SkyLayer::SkyLayer(const std::string & name)
    : Layer(name)
{
}

void SkyLayer::onUpdate(engine::TimeStep ts)
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}