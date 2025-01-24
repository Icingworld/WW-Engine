#pragma once

#include <GLFW/glfw3.h>
#include "../layer/ww_layer.h"

namespace engine
{

class ImGuiLayer : public Layer
{
protected:
    GLFWwindow * m_window;          // GLFW 窗口

public:
    explicit ImGuiLayer(GLFWwindow * window);

    ~ImGuiLayer() override = default;

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

    void onEvent(Event & event) override;
};

} // namespace engine
