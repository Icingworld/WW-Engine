#include "ww_windows_file_system.h"

#include <stdexcept>
#include <algorithm>
#include <fstream>

namespace engine
{

WindowsFileSystem::WindowsFileSystem()
    : FileSystem()
{
    m_currentDirectory = getCurrentDirectory();
}

std::string WindowsFileSystem::getCurrentDirectory() const
{
    // 获取当前工作目录所需的缓冲区大小
    DWORD bufferSize = GetCurrentDirectoryA(0, nullptr);
    if (bufferSize == 0) {
        throw std::runtime_error("Failed to get the buffer size for current directory.");
    }

    // 分配缓冲区并获取目录
    std::string currentDirectory(bufferSize, '\0');
    if (GetCurrentDirectoryA(bufferSize, &currentDirectory[0]) == 0) {
        throw std::runtime_error("Failed to get the current directory.");
    }

    // 移除字符串末尾的 '\0'
    currentDirectory.pop_back();

    std::replace(currentDirectory.begin(), currentDirectory.end(), '\\', '/');

    return currentDirectory;
}

bool WindowsFileSystem::exists(const std::string & path, bool isAbsolute) const
{
    if (isAbsolute) {
        return GetFileAttributesA(path.c_str()) != INVALID_FILE_ATTRIBUTES;
    }
    else {
        return GetFileAttributesA(toFullPath(path).c_str()) != INVALID_FILE_ATTRIBUTES;
    }
}

bool WindowsFileSystem::isDirectory(const std::string & path, bool isAbsolute) const
{
    // 获取绝对路径
    std::string fullPath = path;
    if (!isAbsolute) {
        fullPath = toFullPath(path);
    }

    // 获取文件属性
    DWORD attributes = GetFileAttributesA(fullPath.c_str());
    if (attributes == INVALID_FILE_ATTRIBUTES) {
        return false; // 无效路径
    }

    // 检查是否为目录
    return (attributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
}

bool WindowsFileSystem::isFile(const std::string & path, bool isAbsolute) const
{
    std::string fullPath = path;
    if (!isAbsolute) {
        fullPath = toFullPath(path);
    }

    // 获取文件属性
    DWORD attributes = GetFileAttributesA(fullPath.c_str());
    if (attributes == INVALID_FILE_ATTRIBUTES) {
        return false; // 无效路径
    }

    // 检查是否为文件（不是目录且路径存在）
    return (attributes & FILE_ATTRIBUTE_DIRECTORY) == 0;
}

std::string WindowsFileSystem::getExtension(const std::string & path, bool isAbsolute) const
{
    std::string fullPath = path;
    if (!isAbsolute) {
        fullPath = toFullPath(path);
    }

    // 找到最后一个点的位置
    size_t dotPos = fullPath.find_last_of('.');
    size_t slashPos = fullPath.find_last_of("\\/");

    // 检查点是否存在且在最后一个斜杠之后
    if (dotPos != std::string::npos && (slashPos == std::string::npos || dotPos > slashPos)) {
        return fullPath.substr(dotPos + 1); // 返回扩展名（不包含点）
    }

    return ""; // 如果没有扩展名，返回空字符串
}

std::string WindowsFileSystem::getFileName(const std::string & path, bool isAbsolute) const
{
    std::string fullPath = path;
    if (!isAbsolute) {
        fullPath = toFullPath(path);
    }

    // 找到最后一个斜杠的位置
    size_t slashPos = fullPath.find_last_of("\\/");
    if (slashPos != std::string::npos) {
        return fullPath.substr(slashPos + 1); // 返回最后一个斜杠后的部分
    }

    return fullPath; // 如果没有斜杠，返回整个路径
}

std::string WindowsFileSystem::readText(const std::string & path, bool isAbsolute) const
{
    std::string fullPath = path;
    if (!isAbsolute) {
        fullPath = toFullPath(path);
    }

    // 打开文件
    std::ifstream file(fullPath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for reading: " + fullPath);
    }

    // 读取文件内容
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    
    file.close();
    return content;
}

void WindowsFileSystem::writeText(const std::string & path, const std::string & text, bool isAbsolute) const
{
    std::string fullPath = path;
    if (!isAbsolute) {
        fullPath = toFullPath(path);
    }

    // 打开文件进行写入（覆盖模式）
    std::ofstream file(fullPath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for writing: " + fullPath);
    }

    // 写入内容
    file << text;

    file.close();
}

wwstl::vector<char> WindowsFileSystem::readBinary(const std::string & path, bool isAbsolute) const
{
    std::string fullPath = path;
    if (!isAbsolute) {
        fullPath = toFullPath(path);
    }

    // 打开文件进行读取
    std::ifstream file(fullPath, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for reading: " + fullPath);
    }

    // 将文件内容读取到vector中
    file.seekg(0, std::ios::end);  // 定位到文件末尾
    size_t fileSize = file.tellg();  // 获取文件大小
    file.seekg(0, std::ios::beg);  // 定位到文件开头

    wwstl::vector<char> buffer(fileSize);
    file.read(buffer.data(), fileSize);  // 读取文件内容到缓冲区

    file.close();
    return buffer;
}

void WindowsFileSystem::writeBinary(const std::string & path, const wwstl::vector<char> & content, bool isAbsolute) const
{
    std::string fullPath = path;
    if (!isAbsolute) {
        fullPath = toFullPath(path);
    }

    // 打开文件进行写入
    std::ofstream file(fullPath, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for writing: " + fullPath);
    }

    // 写入二进制内容
    file.write(content.data(), content.size());

    file.close();
}

void WindowsFileSystem::remove(const std::string & path, bool isAbsolute) const
{
    std::string fullPath = path;
    if (!isAbsolute) {
        fullPath = toFullPath(path);
    }

    // 使用 Windows API 删除文件或目录
    if (isDirectory(fullPath, true)) {
        // 删除目录
        if (!RemoveDirectoryA(fullPath.c_str())) {
            throw std::runtime_error("Failed to remove directory: " + fullPath);
        }
    } else if (isFile(fullPath, true)) {
        // 删除文件
        if (!DeleteFileA(fullPath.c_str())) {
            throw std::runtime_error("Failed to remove file: " + fullPath);
        }
    } else {
        throw std::runtime_error("Path does not exist or is not removable: " + fullPath);
    }
}

std::string WindowsFileSystem::toFullPath(const std::string & path) const
{
    char buffer[MAX_PATH];

    DWORD length = GetFullPathNameA(path.c_str(), MAX_PATH, buffer, nullptr);
    if (length == 0 || length > MAX_PATH) {
        throw std::runtime_error("Failed to resolve absolute path for: " + path);
    }

    return std::string(buffer);
}

} // namespace engine
