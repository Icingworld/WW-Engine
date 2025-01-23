#pragma once

#include <iostream>
#include <cstdlib>

namespace engine
{

#ifdef WW_DEBUG
    #define ASSERT(condition) \
        if (!(condition)) { \
            std::cerr << "Assertion failed: " << #condition \
                    << ", file " << __FILE__ \
                    << ", line " << __LINE__ << std::endl; \
            std::abort(); \
        }

    #define ASSERT_MSG(condition, message) \
        if (!(condition)) { \
            std::cerr << "Assertion failed: " << #condition \
                    << ", message: " << message \
                    << ", file " << __FILE__ \
                    << ", line " << __LINE__ << std::endl; \
            std::abort(); \
        }
#else
    #define WW_ASSERT(condition)
    #define WW_ASSERT_MSG(condition, message)
#endif

} // namespace engine
