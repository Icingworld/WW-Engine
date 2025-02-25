#include "w_file_system.h"

namespace engine
{

std::vector<std::filesystem::path> WFileSystem::getFiles(const std::filesystem::path & path)
{
    std::vector<std::filesystem::path> files;
    for (auto const& directory_entry : std::filesystem::recursive_directory_iterator {path})
    {
        if (directory_entry.is_regular_file())
        {
            files.push_back(directory_entry);
        }
    }
    return files;
}

} // namespace engine
