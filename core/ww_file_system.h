#pragma once

#include <string>
#include <ww_vector.h>

namespace engine
{

/**
 * @brief 文件系统
 */
class FileSystem
{
public:
    virtual ~FileSystem() = default;

public:
    /**
     * @brief 获取当前工作目录绝对路径
     */
    virtual std::string getCurrentDirectory() const = 0;

    /**
     * @brief 判断文件是否存在
     */
    virtual bool exists(const std::string & path, bool isAbsolute = false) const = 0;

    /**
     * @brief 判断文件是否为目录
     */
    virtual bool isDirectory(const std::string & path, bool isAbsolute = false) const = 0;

    /**
     * @brief 判断文件是否为文件
     */
    virtual bool isFile(const std::string & path, bool isAbsolute = false) const = 0;

    /**
     * @brief 获取文件扩展名
     */
    virtual std::string getExtension(const std::string & path, bool isAbsolute = false) const = 0;

    /**
     * @brief 获取文件名
     */
    virtual std::string getFileName(const std::string & path, bool isAbsolute = false) const = 0;

    /**
     * @brief 读取文本文件内容
     */
    virtual std::string readText(const std::string & path, bool isAbsolute = false) const = 0;

    /**
     * @brief 写入文本文件内容
     */
    virtual void writeText(const std::string & path, const std::string & content, bool isAbsolute = false) const = 0;

    /**
     * @brief 读取二进制文件内容
     */
    virtual wwstl::vector<char> readBinary(const std::string & path, bool isAbsolute = false) const = 0;

    /**
     * @brief 写入二进制文件内容
     */
    virtual void writeBinary(const std::string & path, const wwstl::vector<char> & content, bool isAbsolute = false) const = 0;

    /**
     * @brief 删除文件
     */
    virtual void remove(const std::string & path, bool isAbsolute = false) const = 0;
};

} // namespace engine
