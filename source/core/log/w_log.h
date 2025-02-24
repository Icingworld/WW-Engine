#pragma once

#include <stdexcept>
#include <spdlog/spdlog.h>

namespace engine
{

/**
 * @brief 日志等级
 */
enum class WLogLevel : unsigned char
{
    trace,
    debug,
    info,
    warn,
    error,
    critical
};

/**
 * @brief 日志系统
 */
class WLog final
{
private:
    std::shared_ptr<spdlog::logger> m_logger;   // 日志

public:
    WLog();

    ~WLog();

public:
    template <typename... Args>
    void log(WLogLevel level, Args&&... args)
    {
        switch (level)
        {
        case WLogLevel::trace:
            m_logger->trace(std::forward<Args>(args)...);
            break;
        case WLogLevel::debug:
            m_logger->debug(std::forward<Args>(args)...);
            break;
        case WLogLevel::info:
            m_logger->info(std::forward<Args>(args)...);
            break;
        case WLogLevel::warn:
            m_logger->warn(std::forward<Args>(args)...);
            break;
        case WLogLevel::error:
            m_logger->error(std::forward<Args>(args)...);
            break;
        case WLogLevel::critical:
            m_logger->critical(std::forward<Args>(args)...);
            criticalCallback(std::forward<Args>(args)...);
            break;
        default:
            break;
        }
    }

    template <typename... Args>
    [[noreturn]] void criticalCallback(Args&&... args) const
    {
        const std::string format = fmt::format(std::forward<Args>(args)...);
        throw std::runtime_error(format);
    }
};

} // namespace engine
