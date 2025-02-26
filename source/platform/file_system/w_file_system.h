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
     * @brief 文件或目录是否存在
     */
    static bool exists(const std::filesystem::path & path);

    /**
     * @brief 判断是否为文件
     */
    static bool isFile(const std::filesystem::path & path);

    /**
     * @brief 判断是否为目录
     */
    static bool isDirectory(const std::filesystem::path & path);

    /**
     * @brief 创建目录
     */
    static bool createDirectory(const std::filesystem::path & path);

    /**
     * @brief 创建多级目录
     */
    static bool createDirectories(const std::filesystem::path & path);

    /**
     * @brief 删除文件或目录
     */
    static bool remove(const std::filesystem::path & path);

    /**
     * @brief 复制文件或目录
     */
    static void copy(const std::filesystem::path & from, const std::filesystem::path & to);

    /**
     * @brief 移动文件或目录
     */
    static void move(const std::filesystem::path & from, const std::filesystem::path & to);

    /**
     * @brief 获取文件大小
     */
    static std::size_t getFileSize(const std::filesystem::path & path);

    /**
     * @brief 获取目录下的所有文件
     */
    static std::vector<std::filesystem::path> listFiles(const std::filesystem::path & path);

    /**
     * @brief 获取目录下的所有子目录
     */
    static std::vector<std::filesystem::path> listDirectories(const std::filesystem::path & path);

    /**
     * @brief 获取目录下的所有文件和子目录
     */
    static std::vector<std::filesystem::path> listAll(const std::filesystem::path & path);

    /**
     * @brief 获取当前工作目录
     */
    static std::filesystem::path getCurrentPath();

    /**
     * @brief 获取绝对路径
     */
    static std::filesystem::path getAbsolutePath(const std::filesystem::path & path);

    /**
     * @brief 获取相对路径
     */
    static std::filesystem::path getRelativePath(const std::filesystem::path & path, const std::filesystem::path & base);

    /**
     * @brief 获取文件扩展名
     */
    static std::tuple<std::string, std::string, std::string> getFileExtensions(const std::filesystem::path & path);

    /**
     * @brief 获取父目录
     */
    static std::filesystem::path getParentPath(const std::filesystem::path & path);

    /**
     * @brief 获取文件名
     */
    static std::filesystem::path getFileName(const std::filesystem::path & path);

    /**
     * @brief 获取无后缀的文件名
     */
    static std::filesystem::path getStem(const std::filesystem::path & path);

    /**
     * @brief 读取文本文件
     */
    static std::string readTextFile(const std::filesystem::path & path);

    /**
     * @brief 读取二进制文件
     */
    static std::vector<unsigned char> readBinaryFile(const std::filesystem::path & path);

    /**
     * @brief 写入文本文件
     */
    static void writeTextFile(const std::filesystem::path & path, const std::string & content);

    /**
     * @brief 写入二进制文件
     */
    static void writeBinaryFile(const std::filesystem::path & path, const std::vector<unsigned char> & content);
};

} // namespace engine
