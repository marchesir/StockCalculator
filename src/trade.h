#ifndef TRADE_H
#define TRADE_H

#include <string>
#include <vector>

typedef enum TradeType
{
    TT_BUY,
    TT_SELL,
} TradeType;

typedef struct TradeData
{
    int sharesQuantity;
    double tradedPrice;
    long tradedTimeStamp;
} TradeData;

// Class that represents Trade enity, with appropiate calculations methods.
class Trade
{
public:
  // Constructor/Destructor.
  Trade(double tradedPrice, int sharesQuantity);
  ~Trade() {};

  // Calculations.
  double calculateVolumeWeightedStockPrice();
  double calculateGeometricMeanAllShareIndex();

  // Getters.
  double getTradedPrice();
  int getTradedShares();
  long getTradeTimeStamp();
  std::string getTradeType(TradeType tradeType);

  // Setters.
  void setTradeType(TradeType tradeType);
  void setTradedPrice(double tradedPrice);

  // Print to standard output.
  void toStandardOutput();
  void addTrade();

private:
    TradeType m_tradeType;
    TradeData m_tradeData;
    std::vector<TradeData> s_tradedData;

    long getCurrentTimeStamp();
    // Avoid copy constructor.
    Trade(const Trade&);
    Trade& operator=(const Trade&);
};
#endif
