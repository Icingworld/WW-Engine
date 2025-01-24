#pragma once

#include <layer/ww_layer.h>

/**
 * @brief UI 图层
 */
class ObjectLayer : public engine::Layer
{
public:
    ObjectLayer(std::string name);

    ~ObjectLayer() override = default;

public:
    void onImGuiRender() override;
};