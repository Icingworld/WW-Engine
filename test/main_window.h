#pragma once

#include <window/ww_window.h>
#include <ww_application.h>

/**
 * @brief 主窗口
 */
class MainWindow : public engine::Window
{
protected:
    engine::Application & m_app;

public:
    MainWindow();
};
