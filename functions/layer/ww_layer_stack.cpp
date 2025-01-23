#include "ww_layer_stack.h"

namespace engine
{

LayerStack::~LayerStack()
{
    for (Layer * layer : m_layers) {
        layer->onDetach();
        delete layer;
    }
}

LayerStack::iterator LayerStack::begin()
{
    return m_layers.begin();
}

LayerStack::const_iterator LayerStack::begin() const
{
    return m_layers.begin();
}

LayerStack::const_iterator LayerStack::cbegin() const
{
    return m_layers.cbegin();
}

LayerStack::iterator LayerStack::end()
{
    return m_layers.end();
}

LayerStack::const_iterator LayerStack::end() const
{
    return m_layers.end();
}

LayerStack::const_iterator LayerStack::cend() const
{
    return m_layers.cend();
}

LayerStack::reverse_iterator LayerStack::rbegin()
{
    return m_layers.rbegin();
}

LayerStack::const_reverse_iterator LayerStack::rbegin() const
{
    return m_layers.rbegin();
}

LayerStack::const_reverse_iterator LayerStack::crbegin() const
{
    return m_layers.crbegin();
}

LayerStack::reverse_iterator LayerStack::rend()
{
    return m_layers.rend();
}

LayerStack::const_reverse_iterator LayerStack::rend() const
{
    return m_layers.rend();
}

LayerStack::const_reverse_iterator LayerStack::crend() const
{
    return m_layers.crend();
}

void LayerStack::pushLayer(Layer * layer)
{
    m_layers.emplace(m_layers.begin() + m_layerInsertIndex, layer);
    layer->onAttach();
    ++m_layerInsertIndex;
}

void LayerStack::pushOverlay(Layer * layer)
{
    m_layers.emplace_back(layer);
    layer->onAttach();
}

void LayerStack::popLayer(Layer * layer)
{
    auto it = std::find(m_layers.begin(), m_layers.begin() + m_layerInsertIndex, layer);
    if (it != m_layers.begin() + m_layerInsertIndex) {
        layer->onDetach();
        m_layers.erase(it);
        --m_layerInsertIndex;
    }
}

void LayerStack::popOverlay(Layer * layer)
{
    auto it = std::find(m_layers.begin() + m_layerInsertIndex, m_layers.end(), layer);
    if (it != m_layers.end()) {
        layer->onDetach();
        m_layers.erase(it);
    }
}

} // namespace engine
