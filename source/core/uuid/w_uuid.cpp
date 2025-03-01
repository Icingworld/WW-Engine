#include "w_uuid.h"

#include <iomanip>
#include <sstream>

#include "../random/w_random.h"

namespace engine
{

static std::random_device s_random_device;
static WDistributionRandomGenerator<std::uniform_int_distribution<>> s_dist(s_random_device(), 0, 255);

WUUID::WUUID()
{
    generate();
}

void WUUID::generate()
{
    for (auto & byte : m_UUID) {
        byte = static_cast<unsigned char>(s_dist.generate());
    }

    m_UUID[6] = (m_UUID[6] & 0x0F) | 0x40;  // 设置版本号为 4
    m_UUID[8] = (m_UUID[8] & 0x3F) | 0x80;  // 设置变体为 RFC4122
}

std::string WUUID::toString() const
{
    std::stringstream ss;
    for (int i = 0; i < 16; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(m_UUID[i]);
        if (i == 3 || i == 5 || i == 7 || i == 9) {
            ss << "-";
        }
    }
    return ss.str();
}

bool WUUID::operator==(const WUUID & other) const
{
    return m_UUID == other.m_UUID;
}

bool WUUID::operator!=(const WUUID & other) const
{
    return !(*this == other);
}

} // namespace engine
