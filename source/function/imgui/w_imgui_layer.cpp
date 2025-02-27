#include "w_imgui_layer.h"

#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

namespace engine
{

WImGuiLayer::WImGuiLayer(GLFWwindow * window)
    : WLayer("WImGuiLayer")
    , m_window(window)
{
}

void WImGuiLayer::begin()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void WImGuiLayer::end()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void WImGuiLayer::onAttach()
{
    // 初始化 ImGui
    IMGUI_CHECKVERSION();           // 检查 ImGui 版本
    ImGui::CreateContext();         // 创建 ImGui 上下文
    ImGuiIO & io = ImGui::GetIO();  // 获取 ImGui IO
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // 启用键盘导航

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(m_window, true);
    ImGui_ImplOpenGL3_Init("#version 330 core");
}

void WImGuiLayer::onDetach()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void WImGuiLayer::onEvent(WEvent & event)
{
    ImGuiIO & io = ImGui::GetIO();

    // 捕获键盘事件
    event.setHandled((event.getEventType() == WEventType::KeyPressed ||
                     event.getEventType() == WEventType::KeyReleased ||
                     event.getEventType() == WEventType::KeyTyped) &&
                     io.WantCaptureKeyboard);
    
    // 捕获鼠标事件
    event.setHandled((event.getEventType() == WEventType::MouseButtonPressed ||
                     event.getEventType() == WEventType::MouseButtonReleased ||
                     event.getEventType() == WEventType::MouseMoved ||
                     event.getEventType() == WEventType::MouseScrolled) &&
                     io.WantCaptureMouse);
}

} // namespace engine
