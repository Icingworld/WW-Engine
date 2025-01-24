#pragma once

#include <ww_unordered_map.h>
#include "ww_resource.h"

namespace engine
{

/**
 * @brief 资源注册表
 */
class ResourceRegister
{
protected:
    wwstl::unordered_map<UUID, std::shared_ptr<Resource>> m_umap;       // 资源注册表

protected:
    ResourceRegister();

    ResourceRegister(const ResourceRegister &) = delete;

    ResourceRegister & operator=(const ResourceRegister &) = delete;

    virtual ~ResourceRegister() = default;

public:
    /**
     * @brief 获取资源注册表
     */
    static ResourceRegister & getResourceRegister();

    /**
     * @brief 获取资源
     * @param uuid 资源唯一标识符
     * @return 资源指针
     * @details 当资源不存在时，生成一个空资源并返回
     */
    std::shared_ptr<Resource> getResource(UUID uuid);

    /**
     * @brief 注册资源
     * @param uuid 资源唯一标识符
     * @param resource 资源指针
     */
    void registResource(UUID uuid, std::shared_ptr<Resource> resource);

    /**
     * @brief 移除资源
     * @param uuid 资源唯一标识符
     */
    void unregistResource(UUID uuid);
};

} // namespace engine
