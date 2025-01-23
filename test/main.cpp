#include <ww_application.h>
#include "main_window.h"

int main(int argc, char ** argv)
{
    engine::Application & app = engine::Application::getApplication(argc, argv);

    MainWindow * window = new MainWindow();
    app.bindWindow(window);

    app.run();
}
