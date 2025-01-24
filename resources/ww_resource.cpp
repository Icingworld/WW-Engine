#include "ww_resource.h"

namespace engine
{

Resource::Resource(ResourceType type, const std::string & name, const std::string & path)
    : m_uuid()
    , m_type(type)
    , m_state(ResourceState::UnLoaded)
    , m_name(name)
    , m_path(path)
{
}

ResourceType Resource::getType() const
{
    return m_type;
}

ResourceState Resource::getState() const
{
    return m_state;
}

void Resource::setState(ResourceState state)
{
    m_state = state;
}

} // namespace engine
