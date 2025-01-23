#pragma once

#include <glad/glad.h>
#include "ww_window_base.h"

namespace engine
{

/**
 * @brief Windows窗口
 */
class WindowsWindow : public WindowBase
{
public:
    WindowsWindow();

    WindowsWindow(const std::string & title, int width, int height);

    ~WindowsWindow() override;

public:
    void init() override;

    void close() override;

    void render() override;
};

} // namespace engine
