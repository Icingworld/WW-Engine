#include "object_layer.h"

#include <imgui.h>

ObjectLayer::ObjectLayer(std::string name)
    : Layer(name)
{
}

void ObjectLayer::onImGuiRender() 
{
    ImGui::Text("WW-Engine Test ImGUI");
}