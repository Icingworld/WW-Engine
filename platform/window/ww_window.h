#pragma once

#include "ww_windows_window.h"

namespace engine
{

#if defined(_WIN32) || defined(_WIN64)
    using Window = WindowsWindow;
#endif

} // namespace engine
