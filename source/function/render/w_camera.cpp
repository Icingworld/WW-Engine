#include "w_camera.h"

namespace engine
{

WCamera::WCamera()
    : WCamera(vec3(0.0f, 0.0f, 3.0f))
{
}

WCamera::WCamera(const glm::vec3 & pos)
    : m_viewMatrix(1.0f)
    , m_projectionMatrix(1.0f)
    , m_viewProjectionMatrix(1.0f)
    , m_fov(45.0f)
    , m_aspect(1.0f)
    , m_near(0.1f)
    , m_far(100.0f)
    , m_position(pos)
    , m_front(0.0f, 0.0f, -1.0f)
    , m_up(0.0f, 1.0f, 0.0f)
    , m_isFirstMouse(true)
{
}

void WCamera::setView(const glm::vec3 & pos, const glm::vec3 & front, const glm::vec3 & up)
{
    m_position = pos;
    m_front = front;
    m_up = up;
}

void WCamera::setView(const glm::mat4 & view)
{
    m_viewMatrix = view;
}

void WCamera::setProjection(float fov, float aspect, float near, float far)
{
    m_fov = fov;
    m_aspect = aspect;
    m_near = near;
    m_far = far;
}

void WCamera::setProjection(const glm::mat4 & projection)
{
    m_projectionMatrix = projection;
}

void WCamera::setFov(float fov)
{
    m_fov = fov;
}

void WCamera::setAspect(float aspect)
{
    m_aspect = aspect;
}

void WCamera::setNear(float near)
{
    m_near = near;
}

void WCamera::setFar(float far)
{
    m_far = far;
}

void WCamera::setPosition(const glm::vec3 & pos)
{
    m_position = pos;
}

void WCamera::setFront(const glm::vec3 & front)
{
    m_front = front;
}

void WCamera::setUp(const glm::vec3 & up)
{
    m_up = up;
}

void WCamera::setIsFirstMouse(bool isFirstMouse)
{
    m_isFirstMouse = isFirstMouse;
}

glm::mat4 WCamera::getViewMatrix() const
{
    return m_viewMatrix;
}

glm::mat4 WCamera::getProjectionMatrix() const
{
    return m_projectionMatrix;
}

glm::mat4 WCamera::getViewProjectionMatrix() const
{
    return m_viewProjectionMatrix;
}

float WCamera::getFov() const
{
    return m_fov;
}

float WCamera::getAspect() const
{
    return m_aspect;
}

float WCamera::getNear() const
{
    return m_near;
}

float WCamera::getFar() const
{
    return m_far;
}

glm::vec3 WCamera::getPosition() const
{
    return m_position;
}

glm::vec3 WCamera::getFront() const
{
    return m_front;
}

glm::vec3 WCamera::getUp() const
{
    return m_up;
}

bool WCamera::isFirstMouse() const
{
    return m_isFirstMouse;
}

void WCamera::updateViewMatrix()
{
    m_viewMatrix = glm::lookAt(m_position, m_position + m_front, m_up);
}

void WCamera::updateProjectionMatrix()
{
    m_projectionMatrix = glm::perspective(glm::radians(m_fov), m_aspect, m_near, m_far);
}

void WCamera::updateViewProjectionMatrix()
{
    m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
}

void WCamera::updateCamera()
{
    updateViewMatrix();
    updateProjectionMatrix();
    updateViewProjectionMatrix();
}

} // namespace engine
