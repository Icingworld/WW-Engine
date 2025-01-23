#include "ww_layer.h"

namespace engine
{

Layer::Layer(const std::string & name)
    : m_layerName(name)
{
}

void Layer::onAttach()
{
}

void Layer::onDetach()
{
}

void Layer::onUpdate(TimeStep ts)
{
}

void Layer::onImGuiRender()
{
}

void Layer::onEvent(Event & event)
{
}

const std::string & Layer::getName() const
{
    return m_layerName;
}

} // namespace engine
