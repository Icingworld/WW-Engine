#pragma once

#include <ww_input.h>
#include <ww_application.h>
#include <GLFW/glfw3.h>

namespace engine
{

bool Input::isKeyPressed(KeyCode code)
{
    Application & app = Application::getApplication();
    GLFWwindow * window = app.getWindow()->getWindow();
    return glfwGetKey(window, static_cast<int>(code)) == GLFW_PRESS;
}

bool Input::isMouseButtonPressed(MouseCode code)
{
    Application & app = Application::getApplication();
    GLFWwindow * window = app.getWindow()->getWindow();
    return glfwGetMouseButton(window, static_cast<int>(code)) == GLFW_PRESS;
}

glm::vec2 Input::getMousePosition()
{
    Application & app = Application::getApplication();
    GLFWwindow * window = app.getWindow()->getWindow();
    double x, y;
    glfwGetCursorPos(window, &x, &y);
    return glm::vec2(x, y);
}

float Input::getMouseX()
{
    return getMousePosition().x;
}

float Input::getMouseY()
{
    return getMousePosition().y;
}

} // namespace engine
