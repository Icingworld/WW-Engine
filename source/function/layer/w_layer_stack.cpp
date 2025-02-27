#include "w_layer_stack.h"

#include <algorithm>

namespace engine
{

WLayerStack::WLayerStack()
    : WLayerStack(8)
{
}

WLayerStack::WLayerStack(std::size_t size)
    : m_layers()
    , m_layerInsertIndex(0)
{
    m_layers.reserve(size);
}

WLayerStack::~WLayerStack()
{
    for (WLayer * layer : m_layers) {
        layer->onDetach();
        delete layer;
    }
}

WLayerStack::iterator WLayerStack::begin()
{
    return m_layers.begin();
}

WLayerStack::const_iterator WLayerStack::begin() const
{
    return m_layers.begin();
}

WLayerStack::const_iterator WLayerStack::cbegin() const
{
    return m_layers.cbegin();
}

WLayerStack::iterator WLayerStack::end()
{
    return m_layers.end();
}

WLayerStack::const_iterator WLayerStack::end() const
{
    return m_layers.end();
}

WLayerStack::const_iterator WLayerStack::cend() const
{
    return m_layers.cend();
}

WLayerStack::reverse_iterator WLayerStack::rbegin()
{
    return m_layers.rbegin();
}

WLayerStack::const_reverse_iterator WLayerStack::rbegin() const
{
    return m_layers.rbegin();
}

WLayerStack::const_reverse_iterator WLayerStack::crbegin() const
{
    return m_layers.crbegin();
}

WLayerStack::reverse_iterator WLayerStack::rend()
{
    return m_layers.rend();
}

WLayerStack::const_reverse_iterator WLayerStack::rend() const
{
    return m_layers.rend();
}

WLayerStack::const_reverse_iterator WLayerStack::crend() const
{
    return m_layers.crend();
}

void WLayerStack::pushLayer(WLayer * layer)
{
    m_layers.emplace(m_layers.begin() + m_layerInsertIndex, layer);
    layer->onAttach();
    ++m_layerInsertIndex;
}

void WLayerStack::pushOverlay(WLayer * layer)
{
    m_layers.emplace_back(layer);
    layer->onAttach();
}

void WLayerStack::popLayer(WLayer * layer)
{
    auto it = std::find(m_layers.begin(), m_layers.begin() + m_layerInsertIndex, layer);
    if (it != m_layers.begin() + m_layerInsertIndex) {
        layer->onDetach();
        m_layers.erase(it);
        --m_layerInsertIndex;
    }
}

void WLayerStack::popOverlay(WLayer * layer)
{
    auto it = std::find(m_layers.begin() + m_layerInsertIndex, m_layers.end(), layer);
    if (it != m_layers.end()) {
        layer->onDetach();
        m_layers.erase(it);
    }
}

} // namespace engine
