#include "ww_resource_register.h"

namespace engine
{

ResourceRegister::ResourceRegister()
{
}

ResourceRegister & ResourceRegister::getResourceRegister()
{
    static ResourceRegister resourceRegister;
    return resourceRegister;
}

std::shared_ptr<Resource> ResourceRegister::getResource(UUID uuid)
{
    auto it = m_umap.find(uuid);
    if (it == m_umap.end()) {
        return nullptr;
    }
    return it->second;
}

void ResourceRegister::registResource(UUID uuid, std::shared_ptr<Resource> resource)
{
    m_umap[uuid] = resource;
}

void ResourceRegister::unregistResource(UUID uuid)
{
    m_umap.erase(uuid);
}

} // namespace engine
