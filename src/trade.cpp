#include "trade.h"
#include <string>
#include <vector>
#include <ctime>
#include <iostream>

// Static methods.

static const long s_fiftenMinutes = 900;
std::vector<TradeData> s_tradedData;

// Public methods.

// Constructor default to empty Trade entity.
Trade::Trade(double tradedPrice, int sharesQuantity)
{
    m_tradeData.tradedPrice = tradedPrice;
    m_tradeData.sharesQuantity = sharesQuantity;
    m_tradeData.tradedTimeStamp = getCurrentTimeStamp();
    m_tradeType = TT_BUY;
}

// Add trade to static container required for tracing all trades.
void Trade::addTrade()
{
    s_tradedData.push_back(m_tradeData);

}

// Calculate volume weighted stock price, based on all recorded trades
// in the last 15 minutes.
double Trade::calculateVolumeWeightedStockPrice()
{
    double stockPrice = -1.00;

    // Calculate the summation
    double shareQuantityAcum = 0.00;
    double tradePriceAcum = 0.00;

    for (int i = 0; i < s_tradedData.size(); ++i)
    {
        // Only trades int he last 15 minutes.
        if (s_tradedData[i].tradedTimeStamp >= (getCurrentTimeStamp() - s_fiftenMinutes))
        {
            // Calculate the summation of Trade Price x Quantity
            tradePriceAcum += (s_tradedData[i].tradedPrice * s_tradedData[i].sharesQuantity);
            // Acumulate Quantity
            shareQuantityAcum += s_tradedData[i].sharesQuantity;
        }
    }

    // calculate the stock price.
    if (shareQuantityAcum > 0.00)
    {
        stockPrice = tradePriceAcum / shareQuantityAcum;
    }

    return stockPrice;
}

// Calculate geometric mean for all traded prices.
double Trade::calculateGeometricMeanAllShareIndex()
{
    double gmIndex = -1.00;
    double tpTotal = 0.00;

    // Get all traded shares and calculate geometric mean.
    for (int i = 0; i < s_tradedData.size(); ++i)
    {
        tpTotal = tpTotal + s_tradedData[i].tradedPrice;
    }

    if (s_tradedData.size() > 0)  // Avoid zero division.
    {
        gmIndex = tpTotal / s_tradedData.size();
    }
    else
    {
        std::cout << "<-- Trade::calculateGeometricMeanAllShareIndex [ERROR: No Trades]" << std::endl;
    }

    return gmIndex;
}

// Get current traded price.
double Trade::getTradedPrice()
{
    return m_tradeData.tradedPrice;
}

// Get traded shares quantity.
int Trade::getTradedShares()
{
    return m_tradeData.sharesQuantity;
}

// Get current trade timestamp.
long Trade::getTradeTimeStamp()
{
    return m_tradeData.tradedTimeStamp;
}

std::string Trade::getTradeType(TradeType tradeType)
{
    std::string ret = "UNDEFINED";
    switch(tradeType)
    {
        case TT_BUY:
        {
            ret = "BUY";
            break;
        }
        case TT_SELL:
        {
            ret = "SELL";
            break;
        }
        default: break;
    }
    return ret;
}

// Set StockType.
void Trade::setTradeType(TradeType tradeType)
{
    m_tradeType = tradeType;
}

// Set traded price.
void Trade::setTradedPrice(double tradedPrice)
{
    m_tradeData.tradedPrice = tradedPrice;
}

// Print Trade data to standard output.
void Trade::toStandardOutput()
{
    std::cout << "<-- TRADE [TRADE TYPE=" << getTradeType(m_tradeType)
              << ", STOCK PRICE=" << getTradedPrice()
              << ", TIMESTAMP=" << getTradeTimeStamp()
              << ", SHARES QUANTITY=" << getTradedShares() << std::endl;
    std::cout << "<-- TRADE [VOLUME WEIGHTED STOCK PRICE=" << calculateVolumeWeightedStockPrice() << "]" << std::endl;
}

// Private methods.

// Get current UNIX timestamp.
long Trade::getCurrentTimeStamp()
{
    std::time_t ts = std::time(nullptr);
    long ret = ts;
    return ret;
}
