#include <application.h>

// Main entrypoint for StockCalculator executable.
int main(int argc, char* argv[])
{
    return Application::getInstance().run();
}
