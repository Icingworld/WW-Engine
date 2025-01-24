#include "ww_uuid.h"

namespace engine
{

UUID::UUID()
{
    generate();
}

void UUID::generate()
{
    for (auto & byte : m_UUID) {
        byte = static_cast<uint8_t>(s_dist(s_gen));
    }

    m_UUID[6] = (m_UUID[6] & 0x0F) | 0x40;  // 设置版本号为 4
    m_UUID[8] = (m_UUID[8] & 0x3F) | 0x80;  // 设置变体为 RFC4122
}

std::string UUID::toString() const
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

} // namespace engine
