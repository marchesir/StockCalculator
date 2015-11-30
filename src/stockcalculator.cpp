#include "application.h"

// Main entrypoint for StockCalculator executable.
int main(int argc, char* argv[])
{
    double stockPrice = Application::getInstance().parseCmdLine(argc, argv);
    if (stockPrice > 0.00)
    {
        Application::getInstance().run(stockPrice);
    }
    else
    {
        std::cout << "<--StockCalculator: ERROR on start-up, shutting down...." << std::endl;
    }
}
