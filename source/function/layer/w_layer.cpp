#include "w_layer.h"

namespace engine
{

WLayer::WLayer(const std::string & name)
    : m_layerName(name)
{
}

void WLayer::onAttach()
{
}

void WLayer::onDetach()
{
}

void WLayer::onUpdate(WTimeStep ts)
{
}

void WLayer::onImGuiRender()
{
}

void WLayer::onEvent(WEvent & event)
{
}

const std::string & WLayer::getName() const
{
    return m_layerName;
}

} // namespace engine
