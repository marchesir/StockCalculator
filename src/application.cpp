#include "application.h"
#include "stock.h"
#include "trade.h"
#include <regex>

// Public methods.

// Singleton Pattern access.
Application& Application::getInstance()
{
    static Application app;
    return app;
}

// Parse passed cmd lines args, acepting obly positive doubles with presion utp 2,
// if not satisfied exit and show usage message and or error message.
double Application::parseCmdLine(int argc, char* argv[])
{
    double ret = 0.00;

    if (argc <= 1 || argc > 2)
    {
        printUsage();
    }
    else
    {
        // Use regex to make sure only positive int are inputted.
        std::regex doubleExp("^[0-9]*\\.[0-9][0-9]$");

        std::string input = argv[1]; // Pointer array to second cmd arg.
        if (regex_match(input, doubleExp))
        {
            // Make sure positive number
            try
            {
                std::string::size_type sz;
                ret = std::stod (input, &sz);
            }
            catch(...)
            {
                std::cout << "<--Application::parseCmdLine: ERROR Input invalid, failed conversion into double" << std::endl;
                printUsage();
            }

            if (ret == 0.00)
            {
                std::cout << "<--Application::parseCmdLine: ERROR: Input invalid, run stockprice must be positive number" << std::endl;
                printUsage();
            }

        }
        else
        {
            std::cout << "<--Application::parseCmdLine: ERROR: Input invalid, stockprice invalid format" << std::endl;
            printUsage();
        }
    }

    return ret;
}

// Program event loop.
int Application::run(double inputPrice)
{
    std::cout << "<-- Application::run [StockCalculator START]" << std::endl;

    double input = inputPrice;

    // Stocks.
    std::vector<Stock> stocks;
    stocks.push_back(Stock("TEA", input, 0.00, 1.00, 100.00));
    stocks.push_back(Stock("POP", input, 8.00, 1.00, 100.00));
    stocks.push_back(Stock("ALE", input, 23.00, 1.00, 60.00));
    stocks.push_back(Stock("GIN", input, 8.00, 0.02, 100.00));
    stocks.push_back(Stock("JOE", input, 13.00, 1.00, 100.00));

    // Trades
    int shareQuantityInitial = 400;
    double tradePriceAcum = 17.77;
    Trade trades(input, shareQuantityInitial);
    trades.addTrade();

    // Loop over stocks.
    for (int i = 0; i < stocks.size(); ++i)
    {
        if (stocks[i].getStockSymbol().compare("GIN"))
        {
            stocks[i].setStockType(ST_PREFERRED);
        }
        // Print stock data and calculations.
        stocks[i].toStandardOutput();

        double tp = input + tradePriceAcum + i;
        trades.setTradedPrice(tp);

        if (i != stocks.size()-1)
        {
            trades.addTrade();
            // Print trade data and calculations.
            trades.toStandardOutput();
        }
    }

    // Calulate GBCE.
    std::cout << "<-- Application::run [Calculating Geometric Mean All Share Index]" << std::endl;
    std::cout << "<-- Application::run [GBCE=" << trades.calculateGeometricMeanAllShareIndex() << "]" << std::endl;
    std::cout << "<-- Application::run [StockCalculator END]" << std::endl;

    return 0;
}

// Private methods.

// Print to std console usage message.
void Application::printUsage()
{
    std::cout << "Usage: stockcalculator stockprice [where stockprice is positive double with precision of 2, eg. 99.99]" << std::endl;
}
