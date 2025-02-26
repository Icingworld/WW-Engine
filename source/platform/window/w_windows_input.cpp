#include <GLFW/glfw3.h>

#include <w_application.h>
#include <w_input.h>

namespace engine
{

float WInput::getMouseX()
{
    return getMousePosition().x;
}

float WInput::getMouseY()
{
    return getMousePosition().y;
}

} // namespace engine
