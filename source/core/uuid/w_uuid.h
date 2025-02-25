#pragma once

#include <string>
#include <array>

namespace engine
{

/**
 * @brief 唯一标识符
 * @version UUIDv4
 */
class WUUID
{
private:
    std::array<unsigned char, 16> m_UUID;    // 128位唯一标识符

public:
    WUUID();

    virtual ~WUUID() = default;

public:
    /**
     * @brief 生成唯一标识符
     */
    void generate();

    /**
     * @brief 将唯一标识符转换为字符串
     */
    std::string toString() const;

    bool operator==(const WUUID & other) const;

    bool operator!=(const WUUID & other) const;
};

} // namespace engine
