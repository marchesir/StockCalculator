#ifndef STOCK_H
#define STOCK_H

#include <string>

typedef enum StockSymbol
{
    TEA,
    POP,
    ALE,
    GIN,
    JOE,
    UNDEFINED
} StockSymbol;

typedef enum StockType
{
    COMMON,
    PREFERRED,
    UNDEFINED
} StockType;

// Class that represents Stock enity, with appropiate calculations methods.
class Stock
{
public:
        // Constructor/Destructor.
        Stock();
        ~Stock() {};

        // Getters.
        StockSymbol getStockSymbol();
        StockType getStockType();
        double getLastDividend(const double& lastDividend);
        double getFixedDividend(const double& fixedDividend);
        double getParValue(const double& peRatio);
        double getStockPrice(const double& stockPrice);

        // Setters.
        void setStockSymbol(const StockSymbol& stockSymbol);
        void setStockType(const StockType& stockType);
        void setLastDividend(const double& lastDividend);
        void setFixedDividend(const double& fixedDividend);
        void setParValue(const double& parValue);
        void setStockPrice(const double& stockPrice);

        // Calculations.
        double calculateDividendYield();
        double calculatePeRatio();

        // Output.
        std::string toString();

private:
    StockSymbol m_stockSymbol;
    StockType m_stockType;
    double m_lastDividend;
    double m_fixedDividend;
    double m_parValue;
    double m_stockPrice;

    // Avoid copy constructor.
    Stock(const Stock&);
    Stock& operator=(const Stock&);
}
#endif
