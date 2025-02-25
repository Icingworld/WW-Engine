#pragma once

#include <random>

#include "../assert/w_assert.h"

namespace engine
{

template <typename NumberType>
class WUniformDistribution
{
    // 非int和real类型无效
    WW_ASSERT_MSG(false, "invalid type for uniform distribution, int and real only");
};

template <>
class WUniformDistribution<short>
{
public:
    using type = std::uniform_int_distribution<short>;
};

template <>
class WUniformDistribution<int>
{
public:
    using type = std::uniform_int_distribution<int>;
};

template <>
class WUniformDistribution<long>
{
public:
    using type = std::uniform_int_distribution<long>;
};

template <>
class WUniformDistribution<long long>
{
public:
    using type = std::uniform_int_distribution<long long>;
};

template <>
class WUniformDistribution<unsigned short>
{
public:
    using type = std::uniform_int_distribution<unsigned short>;
};

template <>
class WUniformDistribution<unsigned int>
{
public:
    using type = std::uniform_int_distribution<unsigned int>;
};

template <>
class WUniformDistribution<unsigned long>
{
public:
    using type = std::uniform_int_distribution<unsigned long>;
};

template <>
class WUniformDistribution<unsigned long long>
{
public:
    using type = std::uniform_int_distribution<unsigned long long>;
};

template <>
class WUniformDistribution<float>
{
public:
    using type = std::uniform_real_distribution<float>;
};

template <>
class WUniformDistribution<double>
{
public:
    using type = std::uniform_real_distribution<double>;
};

template <>
class WUniformDistribution<long double>
{
public:
    using type = std::uniform_real_distribution<long double>;
};

/**
 * @brief 随机数发生器
 */
template <typename RandomEngine = std::default_random_engine>
class WRandomGenerator
{
protected:
    RandomEngine m_engine;      // 随机数引擎

public:
    template <typename... Args>
    explicit WRandomGenerator(Args&&... args)
        : m_engine(std::forward<Args>(args)...)
    {
    }

    virtual ~WRandomGenerator() = default;

public:
    /**
     * @brief 设置随机数种子
     */
    template <typename... Args>
    void seed(Args&&... args)
    {
        m_engine.seed(std::forward<Args>(args)...);
    }

    /**
     * @brief 获取指定分布的随机数
     */
    template <
        typename DistributionType, 
        typename... Args
    > typename DistributionType::result_type distribution(Args&&... args)
    {
        DistributionType dist(std::forward<Args>(args)...);
        return dist(m_engine);
    }

    /**
     * @brief 获取指定范围内均匀分布的随机数
     */
    template <typename NumberType>
    NumberType uniformDistribution(NumberType min, NumberType max)
    {
        // 根据类型选择分布
        return distribution<typename WUniformDistribution<NumberType>::type>(min, max);
    }

    /**
     * @brief 获取指定概率下伯努利分布的随机数
     */
    bool bernoulliDistribution(double p)
    {
        return distribution<std::bernoulli_distribution>(p);
    }

    /**
     * @brief 获取指定均值和标准差下正态（高斯）分布的随机数
     */
    float normalDistribution(float mean, float stddev)
    {
        return distribution<std::normal_distribution<float>>(mean, stddev);
    }
};

/**
 * @brief 指定分布的随机数发生器
 */
template <
    typename DistributionType,
    typename RandomEngine = std::default_random_engine
    > class WDistributionRandomGenerator
{
public:
    using result_type = typename DistributionType::result_type;

protected:
    RandomEngine m_engine;      // 随机数引擎
    DistributionType m_dist;    // 分布

public:
    template <typename SeedType, typename... Args>
    WDistributionRandomGenerator(SeedType && seed, Args&&... args)
        : m_engine(std::forward<SeedType>(seed))
        , m_dist(std::forward<Args>(args)...)
    {
    }

    virtual ~WDistributionRandomGenerator() = default;

public:
    /**
     * @brief 设置随机数种子
     */
    template <typename... Args>
    void seed(Args&&... args)
    {
        m_engine.seed(std::forward<Args>(args)...);
    }

    /**
     * @brief 获取随机数
     */
    result_type generate()
    {
        return m_dist(m_engine);
    }
};

} // namespace engine
