#pragma once

#include <w_window.h>
#include <w_application.h>

/**
 * @brief 主窗口
 */
class MainWindow
    : public engine::WWindow
{
public:
    engine::WApplication & m_app;       // app

public:
    MainWindow();

    ~MainWindow() override = default;
};
