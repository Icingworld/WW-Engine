#pragma once

#include <layer/ww_layer.h>

/**
 * @brief 天空图层
 */
class SkyLayer : public engine::Layer
{
public:
    explicit SkyLayer(const std::string & name);

    ~SkyLayer() override = default;

public:
    void onUpdate(engine::TimeStep ts) override;
};
