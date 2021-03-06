# Introduction
1) For a given stock:<br>
  a. Given any price as input, calculate the dividend yield;<br>
  b. Given any price as input, calculate the P/E Ratio;<br>
  c. Record a trade, with timestamp, quantity of shares, buy or sell indicator and traded price;<br>
  d. Calculate Volume Weighted Stock Price based on trades in past 15 minutes;<br>
2) Calculate the GBCE All Share Index using the geometric mean of prices for all stocks;<br>

# Compile and Run
g++ -std=c++0x -o stockcalculator stock.cpp trade.cpp application.cpp stockcalculator.cpp<br>
Make sure test_stockcalcultor does not exist.

# Tests
To compile and run test program which follows basic TDD (Test Driven Design):<br>
g++ -std=c++0x -o test_stockcalculator stock.cpp trade.cpp test_stockcalculator.cpp<br>
Make sure stockcalcultor does not exist.

# Design
The design is simple and modular, with clean seperation of the various program actors as such:
![](https://github.com/marchesir/StockCalculator/blob/master/res/StockCalculatorArch.png)<br>
The above architecture diagram shows a simple overview of the program.
