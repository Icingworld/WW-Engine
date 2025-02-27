#pragma once

#include <GLFW/glfw3.h>
#include "../layer/w_layer.h"

namespace engine
{

/**
 * @brief ImGui图层
 */
class WImGuiLayer
    : public WLayer
{
protected:
    GLFWwindow * m_window;          // GLFW 窗口

public:
    explicit WImGuiLayer(GLFWwindow * window);

    ~WImGuiLayer() override = default;

public:
    /**
     * @brief 每帧的 GUI 渲染起始
     */
    void begin();

    /**
     * @brief 每帧的 GUI 渲染结束
     */
    void end();

    void onAttach() override;

    void onDetach() override;

    void onEvent(WEvent & event) override;
};

} // namespace engine
