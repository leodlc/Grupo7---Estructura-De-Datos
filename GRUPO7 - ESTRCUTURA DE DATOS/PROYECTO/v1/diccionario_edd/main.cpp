#include "Application.h"

int main()
{
    Application& app = Application::get();
    return app.initialize();
}