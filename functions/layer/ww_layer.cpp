#include "ww_layer.h"

namespace engine
{

Layer::Layer(const std::string & name)
    : m_layerName(name)
{
}

const std::string & Layer::getName() const
{
    return m_layerName;
}

} // namespace engine
