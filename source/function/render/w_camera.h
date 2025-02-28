#pragma once

#include <w_math.h>

namespace engine
{

/**
 * @brief 相机
 */
class WCamera
{
protected:
    mat4 m_viewMatrix;                  // 视图矩阵
    mat4 m_projectionMatrix;            // 投影矩阵
    mat4 m_viewProjectionMatrix;        // 视图投影矩阵

    float m_fov;                        // 摄像机视角
    float m_aspect;                     // 摄像机长宽比
    float m_near;                       // 摄像机近平面
    float m_far;                        // 摄像机远平面

    vec3 m_position;                    // 摄像机位置
    vec3 m_front;                       // 摄像机前方向
    vec3 m_up;                          // 摄像机上方向

    bool m_isFirstMouse;                // 是否是第一次移动鼠标

public:
    WCamera();

    explicit WCamera(const vec3 & pos);

    virtual ~WCamera() = default;

public:
    /**
     * @brief 设置摄像机视图矩阵参数
     */
    void setView(const vec3 & pos, const vec3 & front, const vec3 & up);

    /**
     * @brief 设置摄像机视图矩阵参数
     */
    void setView(const mat4 & viewMatrix);

    /**
     * @brief 设置摄像机投影矩阵参数
     */
    void setProjection(float fov, float aspect, float near, float far);

    /**
     * @brief 设置摄像机投影矩阵参数
     */
    void setProjection(const mat4 & projectionMatrix);

    /**
     * @brief 设置摄像机视角
     */
    void setFov(float fov);

    /**
     * @brief 设置摄像机长宽比
     */
    void setAspect(float aspect);

    /**
     * @brief 设置摄像机近平面
     */
    void setNear(float near);

    /**
     * @brief 设置摄像机远平面
     */
    void setFar(float far);

    /**
     * @brief 设置摄像机位置
     */
    void setPosition(const vec3 & pos);

    /**
     * @brief 设置摄像机前方向
     */
    void setFront(const vec3 & front);

    /**
     * @brief 设置摄像机上方向
     */
    void setUp(const vec3 & up);

    /**
     * @brief 设置是否是第一次移动鼠标
     */
    void setIsFirstMouse(bool isFirstMouse);

    /**
     * @brief 获取摄像机视图矩阵
     */
    mat4 getViewMatrix() const;

    /**
     * @brief 获取摄像机投影矩阵
     */
    mat4 getProjectionMatrix() const;

    /**
     * @brief 获取摄像机视图投影矩阵
     */
    mat4 getViewProjectionMatrix() const;

    /**
     * @brief 获取摄像机视角
     */
    float getFov() const;

    /**
     * @brief 获取摄像机长宽比
     */
    float getAspect() const;

    /**
     * @brief 获取摄像机近平面
     */
    float getNear() const;

    /**
     * @brief 获取摄像机远平面
     */
    float getFar() const;

    /**
     * @brief 获取摄像机位置
     */
    vec3 getPosition() const;

    /**
     * @brief 获取摄像机前方向
     */
    vec3 getFront() const;

    /**
     * @brief 获取摄像机上方向
     */
    vec3 getUp() const;

    /**
     * @brief 获取是否是第一次移动鼠标
     */
    bool isFirstMouse() const;

    /**
     * @brief 计算摄像机视图矩阵
     */
    virtual void updateViewMatrix();

    /**
     * @brief 计算摄像机投影矩阵
     */
    virtual void updateProjectionMatrix();

    /**
     * @brief 计算摄像机视图投影矩阵
     */
    virtual void updateViewProjectionMatrix();

    /**
     * @brief 计算摄像机
     */
    virtual void updateCamera();
};

} // namespace engine
