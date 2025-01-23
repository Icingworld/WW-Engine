#pragma once

namespace engine
{

constexpr const char * GetPlatformName()
{
    #if defined(_WIN32) || defined(_WIN64)
        return "Windows";
    #elif defined(__linux__)
        return "Linux";
    #elif defined(__APPLE__) && defined(__MACH__)
        return "macOS";
    #elif defined(__ANDROID__)
        return "Android";
    #elif defined(__unix__) || defined(__unix)
        return "Unix";
    #else
        return "Unknown";
    #endif
}

} // namespace engine
