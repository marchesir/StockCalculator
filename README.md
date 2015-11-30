# StockCalculator
The problem is as such:

1) For a given stock,
  i. Given any price as input, calculate the dividend yield
  ii. Given any price as input, calculate the P/E Ratio
  iii. Record a trade, with timestamp, quantity of shares, buy or sell indicator and traded price
  iv. Calculate Volume Weighted Stock Price based on trades in past 15 minutes
2) Calculate the GBCE All Share Index using the geometric mean of prices for all stocks

# Compile and Run
g++ -std=c++0x -o stockcalculator stock.cpp trade.cpp application.cpp stockcalculator.cpp
Make sure test_stockcalcultor does not exist.

# Tests
To compile and run test program whcih follows basic TDD (Test Driven Design):
g++ -std=c++0x -o test_stockcalculator stock.cpp trade.cpp application.cpp stockcalculator.cpp
Make sure stockcalcultor does not exist.

# Design
TODO


