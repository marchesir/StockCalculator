#ifndef STOCK_H
#define STOCK_H

#include <string>

typedef enum StockType
{
    ST_COMMON,
    ST_PREFERRED,
} StockType;

// Class that represents Stock enity, with appropiate calculations methods.
class Stock
{
public:
        // Constructor/Destructor.
        Stock(std::string stockSymbol, double stockPrice, double lastDividend, double fixedDividend, double parValue);
        ~Stock() {};

        // Calculations.
        double calculateDividendYield();
        double calculatePeRatio();

        // Getters.
        double getLastDividend();
        double getFixedDividend();
        double getParValue();
        double getStockPrice();
        std::string getStockType(StockType stockType);
        std::string getStockSymbol();

        // Setters.
        void setStockType(StockType stockType);

        // Print to standard output.
        void toStandardOutput();
private:
    std::string m_stockSymbol;
    StockType m_stockType;
    double m_lastDividend;
    double m_fixedDividend;
    double m_parValue;
    double m_stockPrice;

    // Avoid copy constructor.
    Stock& operator=(const Stock&);
};
#endif
