#include <w_application.h>

#include "mainwindow.h"

int main()
{
    engine::WApplication & app = engine::WApplication::getApplication();
    MainWindow * mainWindow = new MainWindow();
    app.bindWindow(mainWindow);

    app.run();

    return 0;
}
