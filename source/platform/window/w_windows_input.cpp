#include <GLFW/glfw3.h>

#include <w_application.h>
#include <w_input.h>

namespace engine
{

bool WInput::isKeyPressed(WKeyCode code)
{
    WApplication & app = WApplication::getApplication();
    GLFWwindow * window = static_cast<GLFWwindow *>(app.getWindow()->getWindow());
    return glfwGetKey(window, static_cast<int>(code)) == GLFW_PRESS;
}

bool WInput::isMouseButtonPressed(WMouseCode code)
{
    WApplication & app = WApplication::getApplication();
    GLFWwindow * window = static_cast<GLFWwindow *>(app.getWindow()->getWindow());
    return glfwGetMouseButton(window, static_cast<int>(code)) == GLFW_PRESS;
}

vec2 WInput::getMousePosition()
{
    WApplication & app = WApplication::getApplication();
    GLFWwindow * window = static_cast<GLFWwindow *>(app.getWindow()->getWindow());
    double x, y;
    glfwGetCursorPos(window, &x, &y);
    return vec2(x, y);
}

float WInput::getMouseX()
{
    return getMousePosition().x;
}

float WInput::getMouseY()
{
    return getMousePosition().y;
}

} // namespace engine
