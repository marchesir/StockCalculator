#include "stock.h"

// Constructor default to empty Stock entity.
Stock::Stock()
{
    m_stockSymbol = StockSymbol::UNDEFINED;
    m_stockType = StockType::UNDEFINED;
    m_lastDividend = 0.0;
    m_fixedDividend = 0.0;
    m_parValue = 0.0;
    m_stockPrice = 0.0
}

// Get Stock Symbol.
StockSymbol Stock::getStockSymbol()
{
    return m_stockSymbol;
}
// Set Stock Symbol.
void Stock::setStockSymbol(const StockSymbol& stockSymbol)
{
    m_stockSymbol = stockSymbol;
}

// Get Stock Type.
StockType Stock::getStockType()
{
    return m_stockType;
}
// Set Stock Type.
void Stock::setStockType(const StockType& stockType)
{
    m_stockType = stockType;
}

// Get Last Dividend.
double Stock::getLastDividend(const double& lastDividend)
{
    return m_lastDividend;
}
// Set Last Dividend.
void Stock::setLastDividend(const double& lastDividend)
{
    m_lastDividend = lastDividend;
}

// Get Fixed Dividend.
double Stock::getFixedDividend(const double& fixedDividend)
{
    return m_fixedDividend;
}
// Set Fixed Dividend.
void Stock::setFixedDividend(const double& fixedDividend)
{
    m_fixedDividend = fixedDividend;
}

// Get Par Value
double Stock::getParValue(const double& parValue)
{
    return m_parValue
}
// Set PE Ratio.
void Stock::setPeRatio(const double& peRatio)
{
    m_peRatio = peRatio;
}

// Get Stock Price.
double Stock::getStockPrice(const double& stockPrice)
{
    m_stockPrice = stockPrice;
}
// Set Stock Price.
void setStockPrice(const double& stockPrice)
{
    m_stockPrice = stockPrice;
}

// Calculate Dividend Yield.
double Stock::alculateDividendYield()
{
    double dividendYield = -1.0;
    if (m_stockPrice > 0.0) // Avoid zero division.
    {
  	    if (m_stockType == StockType::COMMON)
        {
  		      dividendYield = m_lastDividend / stockPrice;
  			}
        else if (m_stockType == StockType::PREFERRED)
        {
  			    dividendYield = (m_fixedDividend * parValue ) / m_stockPrice;
  			}
  		}
  		return dividendYield;
}

double calculatePeValue();
