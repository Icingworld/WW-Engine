#include "mainwindow.h"

MainWindow::MainWindow()
    : engine::WWindow("Hello WW-Engine", 1280, 720)
    , m_app(engine::WApplication::getApplication())
{
}