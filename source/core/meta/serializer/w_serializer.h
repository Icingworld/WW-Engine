#pragma once

#include "../w_json.h"
#include "../reflection/w_reflection.h"

namespace engine
{

/**
 * @brief 序列化
 */
class WSerializer
{
public:
    static json serialize();
};

} // namespace engine
