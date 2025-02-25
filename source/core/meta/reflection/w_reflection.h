#pragma once

#include <entt/entt.hpp>

namespace engine
{

/**
 * @brief 反射
 */
class WReflection
{
public:
    /**
     * @brief 注册类
     * @param name 唯一类名
     */
    template <typename Type>
    static auto registClass(const char * name)
    {
        return entt::meta_factory<Type>().type(toHashedString(name));
    }

    /**
     * @brief 通过唯一类名构造一个实例
     * @param name 唯一类名
     */
    static auto resolveClass(const char * name)
    {
        return entt::resolve(toHashedString(name));
    }

    /**
     * @brief 通过已注册类型构造一个实例
     */
    template <typename Type>
    static auto resolveClass()
    {
        return entt::resolve<Type>();
    }

public:
    static entt::hashed_string toHashedString(const char * str)
    {
        return entt::hashed_string{str};
    }
};

} // namespace engine
