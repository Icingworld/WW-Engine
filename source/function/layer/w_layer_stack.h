#pragma once

#include <vector>

#include "w_layer.h"

namespace engine
{

/**
 * @brief 图层栈
 */
class WLayerStack
{
public:
    using iterator = std::vector<WLayer *>::iterator;
    using const_iterator = std::vector<WLayer *>::const_iterator;
    using reverse_iterator = std::vector<WLayer *>::reverse_iterator;
    using const_reverse_iterator = std::vector<WLayer *>::const_reverse_iterator;

protected:
    std::vector<WLayer *> m_layers;         // 图层栈
    std::size_t m_layerInsertIndex;         // 图层插入索引

public:
    WLayerStack();

    explicit WLayerStack(std::size_t size);

    ~WLayerStack();

public:
    // 迭代器

    iterator begin();

    const_iterator begin() const;

    const_iterator cbegin() const;

    iterator end();

    const_iterator end() const;

    const_iterator cend() const;

    reverse_iterator rbegin();

    const_reverse_iterator rbegin() const;

    const_reverse_iterator crbegin() const;

    reverse_iterator rend();

    const_reverse_iterator rend() const;

    const_reverse_iterator crend() const;

public:
    /**
     * @brief 添加普通图层
     * @details 通常是底层图层，先被渲染
     */
    void pushLayer(WLayer * WLayer);

    /**
     * @brief 添加覆盖图层
     * @details 通常是顶层图层，后被渲染，起覆盖作用
     */
    void pushOverlay(WLayer * WLayer);

    /**
     * @brief 移除普通图层
     */
    void popLayer(WLayer * WLayer);

    /**
     * @brief 移除覆盖图层
     */
    void popOverlay(WLayer * WLayer);
};

} // namespace engine
