#include "w_file_system.h"

#include <fstream>

namespace engine
{

bool WFileSystem::exists(const std::filesystem::path & path)
{
    return std::filesystem::exists(path);
}

bool WFileSystem::isFile(const std::filesystem::path & path)
{
    return std::filesystem::is_regular_file(path);
}

bool WFileSystem::isDirectory(const std::filesystem::path & path)
{
    return std::filesystem::is_directory(path);
}

bool WFileSystem::createDirectory(const std::filesystem::path & path)
{
    return std::filesystem::create_directory(path);
}

bool WFileSystem::createDirectories(const std::filesystem::path & path)
{
    return std::filesystem::create_directories(path);
}

bool WFileSystem::remove(const std::filesystem::path & path)
{
    return std::filesystem::remove(path);
}

void WFileSystem::copy(const std::filesystem::path & from, const std::filesystem::path & to)
{
    std::filesystem::copy(from, to);
}

void WFileSystem::move(const std::filesystem::path & from, const std::filesystem::path & to)
{
    std::filesystem::rename(from, to);
}

std::size_t WFileSystem::getFileSize(const std::filesystem::path & path)
{
    return std::filesystem::file_size(path);
}

std::vector<std::filesystem::path> WFileSystem::listFiles(const std::filesystem::path & path)
{
    std::vector<std::filesystem::path> files;
    for (const auto & entry : std::filesystem::directory_iterator(path))
    {
        files.push_back(entry.path());
    }
    return files;
}

std::vector<std::filesystem::path> WFileSystem::listDirectories(const std::filesystem::path & path)
{
    std::vector<std::filesystem::path> directories;
    for (const auto & entry : std::filesystem::directory_iterator(path))
    {
        if (std::filesystem::is_directory(entry.path()))
        {
            directories.push_back(entry.path());
        }
    }
    return directories;
}

std::vector<std::filesystem::path> WFileSystem::listAll(const std::filesystem::path & path)
{
    std::vector<std::filesystem::path> all;
    for (const auto & entry : std::filesystem::directory_iterator(path))
    {
        all.push_back(entry.path());
    }
    return all;
}

std::filesystem::path WFileSystem::getCurrentPath()
{
    return std::filesystem::current_path();
}

std::filesystem::path WFileSystem::getAbsolutePath(const std::filesystem::path & path)
{
    return std::filesystem::absolute(path);
}

std::filesystem::path WFileSystem::getRelativePath(const std::filesystem::path & path, const std::filesystem::path & base)
{
    return std::filesystem::relative(path, base);
}

std::tuple<std::string, std::string, std::string> WFileSystem::getFileExtensions(const std::filesystem::path & path)
{
    return std::make_tuple(path.extension().generic_string(),
            path.stem().extension().generic_string(),
            path.stem().stem().extension().generic_string());
}

std::filesystem::path WFileSystem::getParentPath(const std::filesystem::path & path)
{
    return path.parent_path();
}

std::filesystem::path WFileSystem::getFileName(const std::filesystem::path & path)
{
    return path.filename();
}

std::filesystem::path WFileSystem::getStem(const std::filesystem::path & path)
{
    return path.stem();
}

std::string WFileSystem::readTextFile(const std::filesystem::path & path)
{
    std::ifstream file(path);
    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

std::vector<unsigned char> WFileSystem::readBinaryFile(const std::filesystem::path & path)
{
    std::ifstream file(path, std::ios::binary);
    return std::vector<unsigned char>((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

void WFileSystem::writeTextFile(const std::filesystem::path & path, const std::string & content)
{
    std::ofstream file(path);
    file << content;
}

void WFileSystem::writeBinaryFile(const std::filesystem::path & path, const std::vector<unsigned char> & content)
{
    std::ofstream file(path, std::ios::binary);
    file.write(reinterpret_cast<const char*>(content.data()), content.size());
}

} // namespace engine
