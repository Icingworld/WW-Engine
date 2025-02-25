#pragma once

#include <filesystem>
#include <vector>

namespace engine
{

/**
 * @brief 文件系统
 */
class WFileSystem
{
public:
    /**
     * @brief 获取文件列表
     */
    static std::vector<std::filesystem::path> getFiles(const std::filesystem::path & path);
};

} // namespace engine
