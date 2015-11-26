#include <application.h>

// Singleton Pattern.
Application& Foo::getInstance()
{
    static Application app;
    return app;
}

void Application::parseCmdLine()
{

}
void Application::printOutput()
{

}
