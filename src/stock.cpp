#include "stock.h"
#include <string>
#include <vector>
#include <iostream>

// Public methods.

// Constructor.
Stock::Stock(std::string stockSymbol, double stockPrice, double lastDividend, double fixedDividend, double parValue)
{
    m_stockSymbol = stockSymbol;
    m_lastDividend = lastDividend;
    m_fixedDividend = fixedDividend;
    m_parValue = parValue;
    m_stockPrice = stockPrice;
    m_stockType = ST_COMMON;
}

// Calculate Dividend Yield.
double Stock::calculateDividendYield()
{
    double dividendYield = -1.00;

    if (m_stockPrice > 0.00)
    {
        if (m_stockType == StockType::ST_COMMON)
        {
    	      dividendYield = m_lastDividend / m_stockPrice;
    	  }
        else if (m_stockType == StockType::ST_PREFERRED)
        {
    	      dividendYield = (m_fixedDividend * m_parValue ) / m_stockPrice;
    	  }
    }
    else
    {
        std::cout << "<-- Stock::calculateDividendYield [ERROR: Stock Price not valid]" << std::endl;
    }

  	return dividendYield;
}

// Calculate PE Ratio.
double Stock::calculatePeRatio()
{
    double peRatio = -1.00;

    if (m_stockPrice > 0.00 && calculateDividendYield() > 0.00)
    {
		        peRatio = m_stockPrice / calculateDividendYield();
    }
    else
    {
        std::cout << "<-- Stock::calculatePeRatio [ERROR: Stock Price not valid]" << std::endl;
    }

		return peRatio;
}

// Get last dividend.
double Stock::getLastDividend()
{
    return (m_lastDividend == -1.00? 0.00: m_lastDividend);
}

// Get fixed dividend.
double Stock::getFixedDividend()
{
    return (m_fixedDividend == -1.00? 0.00: m_fixedDividend);
}

// Get par value.
double Stock::getParValue()
{
    return (m_parValue == -1.00? 0.00: m_parValue);
}

// Get stock price.
double Stock::getStockPrice()
{
    return m_stockPrice;
}

// Get stockSymbol.
std::string Stock::getStockSymbol()
{
    return m_stockSymbol;
}

// Get StockType as string.
std::string Stock::getStockType(StockType stockType)
{
    std::string ret = "UNDEFINED";
    switch(stockType)
    {
        case ST_COMMON:
        {
            ret = "COMMON";
            break;
        }
        case ST_PREFERRED:
        {
            ret = "PREFERRED";
            break;
        }
        default: break;
    }
    return ret;
}

// Set StockType.
void Stock::setStockType(StockType stockType)
{
    m_stockType = stockType;
}

// Print Stock data to standard output.
void Stock::toStandardOutput()
{
    std::cout << "<-- STOCK [STOCK SYMBOL=" << m_stockSymbol
              << ", TYPE=" << getStockType(m_stockType)
              << ", LAST DIVIDEND=" << getLastDividend()
              << ", FIXED DIVIDEND=" << getFixedDividend()
              << ", PAR VALUE=" << getParValue() << "]" << std::endl;
    std::cout << "<-- STOCK [DIVIDEND YIELD=" << calculateDividendYield() << "]" << std::endl;
    std::cout << "<-- STOCK [P/E RATIO=" << calculatePeRatio() << "]" << std::endl;
}
