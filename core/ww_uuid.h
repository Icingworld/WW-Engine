#pragma once

#include <string>
#include <sstream>
#include <iomanip>
#include "wwstl/ww_array.h"
#include "ww_random.h"

namespace engine
{

/**
 * @brief 唯一标识符类
 * @details UUIDv4
 */
class UUID
{ 
private:
    wwstl::array<unsigned char, 16> m_UUID;    // 128位唯一标识符

public:
    UUID();

    virtual ~UUID() = default;

public:
    /**
     * @brief 生成唯一标识符
     */
    void generate();

    /**
     * @brief 将唯一标识符转换为字符串
     */
    std::string toString() const;
};

} // namespace engine
