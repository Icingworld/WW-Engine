#pragma once

#include <algorithm>
#include <ww_vector.h>
#include "ww_layer.h"

namespace engine
{

/**
 * @brief 图层栈
 */
class LayerStack
{
public:
    using iterator = wwstl::vector<Layer *>::iterator;
    using const_iterator = wwstl::vector<Layer *>::const_iterator;
    using reverse_iterator = wwstl::vector<Layer *>::reverse_iterator;
    using const_reverse_iterator = wwstl::vector<Layer *>::const_reverse_iterator;

protected:
    wwstl::vector<Layer *> m_layers;        // 图层栈
    std::size_t m_layerInsertIndex = 0;     // 图层插入索引

public:
    LayerStack() = default;
    
    ~LayerStack();

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
    void pushLayer(Layer * layer);

    /**
     * @brief 添加覆盖图层
     * @details 通常是顶层图层，后被渲染，起覆盖作用
     */
    void pushOverlay(Layer * layer);

    /**
     * @brief 移除普通图层
     */
    void popLayer(Layer * layer);

    /**
     * @brief 移除覆盖图层
     */
    void popOverlay(Layer * layer);
};

} // namespace engine
