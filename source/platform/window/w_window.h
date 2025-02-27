#pragma once

#include "../w_platform.h"
#include "w_windows_window.h"

namespace engine
{

#ifdef WW_WINDOWS
    using WWindow = WWindowsWindow;
#else
    #error "Platform not support"
#endif

} // namespace engine
