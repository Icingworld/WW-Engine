#include "ww_imgui_layer.h"

#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

namespace engine
{

ImGuiLayer::ImGuiLayer(GLFWwindow * window)
    : Layer("ImGuiLayer")
    , m_window(window)
{
}

void ImGuiLayer::begin()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void ImGuiLayer::end()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiLayer::onAttach()
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

void ImGuiLayer::onDetach()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void ImGuiLayer::onEvent(Event & event)
{
    ImGuiIO & io = ImGui::GetIO();

    // 捕获键盘事件
    event.setHandled((event.getEventType() == EventType::KeyPressed ||
                     event.getEventType() == EventType::KeyReleased ||
                     event.getEventType() == EventType::KeyTyped) &&
                     io.WantCaptureKeyboard);
    
    // 捕获鼠标事件
    event.setHandled((event.getEventType() == EventType::MouseButtonPressed ||
                     event.getEventType() == EventType::MouseButtonReleased ||
                     event.getEventType() == EventType::MouseMoved ||
                     event.getEventType() == EventType::MouseScrolled) &&
                     io.WantCaptureMouse);
}

} // namespace engine
