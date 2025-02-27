#pragma once

namespace engine
{

#if defined(_WIN32) || defined(_WIN64)
    #define WW_WINDOWS
#elif defined(__linux__)
    #define WW_LINUX
#elif defined(__APPLE__) && defined(__MACH__)
    #define WW_MAC
#elif defined(__ANDROID__)
    #define WW_ANDROID
#elif defined(__unix__) || defined(__unix)
    #define WW_UNIX
#else
    #define WW_UNKNOWN_PLATFORM
#endif

} // namespace engine
