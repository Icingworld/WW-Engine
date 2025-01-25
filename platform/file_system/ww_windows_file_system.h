#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <ww_file_system.h>

namespace engine
{

/**
 * @brief Windows文件系统
 */
class WindowsFileSystem : public FileSystem
{
public:
    WindowsFileSystem();

    ~WindowsFileSystem() override = default;

public:
    std::string getCurrentDirectory() const override;

    bool exists(const std::string & path, bool isAbsolute = false) const override;

    bool isDirectory(const std::string & path, bool isAbsolute = false) const override;

    bool isFile(const std::string & path, bool isAbsolute = false) const override;

    std::string getExtension(const std::string & path, bool isAbsolute = false) const override;

    std::string getFileName(const std::string & path, bool isAbsolute = false) const override;

    std::string readText(const std::string & path, bool isAbsolute = false) const override;

    void writeText(const std::string & path, const std::string & text, bool isAbsolute = false) const override;

    wwstl::vector<char> readBinary(const std::string & path, bool isAbsolute = false) const override;

    void writeBinary(const std::string & path, const wwstl::vector<char> & content, bool isAbsolute = false) const override;

    void remove(const std::string & path, bool isAbsolute = false) const override;

    std::string toFullPath(const std::string & path) const override;
};

} // namespace engine
