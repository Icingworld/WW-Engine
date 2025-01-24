#pragma once

#include <ww_uuid.h>

namespace engine
{

enum class ResourceType
{
    None = 0,
    Texture,            // 纹理
    Shader,             // 着色器
    Sound,              // 声音
    Font,               // 字体
    Animation,          // 动画
    Material            // 材质
};

enum class ResourceState
{
    None = 0,
    UnLoaded,           // 未加载
    Loading,            // 加载中
    Loaded,             // 已加载
    Failed              // 加载失败
};

/**
 * @brief 资源
 */
class Resource
{
protected:
    UUID m_uuid;            // 资源唯一标识符
    ResourceType m_type;    // 资源类型
    ResourceState m_state;  // 资源状态
    std::string m_name;     // 资源名称
    std::string m_path;     // 资源路径

public:
    Resource(ResourceType type, const std::string & name, const std::string & path);

    virtual ~Resource() = default;

public:
    /**
     * @brief 资源加载
     */
    virtual void load() = 0;

    /**
     * @brief 资源卸载
     */
    virtual void unload() = 0;

    /**
     * @brief 获取资源类型
     */
    ResourceType getType() const;

    /**
     * @brief 获取资源状态
     */
    ResourceState getState() const;

    /**
     * @brief 设置资源状态
     */
    void setState(ResourceState state);
};

} // namespace engine
