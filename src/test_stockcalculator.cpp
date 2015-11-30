#include "stock.h"
#include "trade.h"

#include <iostream>
#include <assert.h>

int main()
{
    // Test 1: Check Stock enity can be created.
    std::cout << "<-- test_stockcalcuator::main [TEST1: Stock Enity Validity]" << std::endl;
    try
    {

        Stock* stock = new Stock("TEA", 1.00, 0.02, 1.00, 100.00);
        assert(stock != nullptr);
        delete stock;
        std::cout << "<-- test_stockcalcuator::main [TEST1: PASSED]" << std::endl;
    }
    catch(...)
    {
        std::cout << "<-- test_stockcalcuator::main [TEST1: FAILED]" << std::endl;
    }

    // Test 2: Check Trade enity can be created with addTrade called too.
    std::cout << "<-- test_stockcalcuator::main [TEST2: Trade Enity Validity]" << std::endl;
    try
    {
        Trade* trade = new Trade(2.00, 40);
        assert(trade != nullptr);
        trade->addTrade();
        delete trade;
        std::cout << "<-- test_stockcalcuator::main [TEST2: PASSED]" << std::endl;
    }
    catch(...)
    {
        std::cout << "<-- test_stockcalcuator::main [TEST2: FAILED]" << std::endl;
    }

    // Test 3: Check all calculations on Stock enity works by trying to force
    // division by zero by setting all input 0, correct result should be error -1.00.
    std::cout << "<-- test_stockcalcuator::main [TEST3: Stock Calculations Check]" << std::endl;
    try
    {
        Stock stock("TEA", 0.00, 0.00, 0.00, 0.00);
        assert(stock.calculateDividendYield() == -1.00 && stock.calculatePeRatio() == -1.00);
        std::cout << "<-- test_stockcalcuator::main [TEST3: PASSED]" << std::endl;
    }
    catch(...)
    {
        std::cout << "<-- test_stockcalcuator::main [TEST3: FAILED]" << std::endl;
    }

    // Test 4: Check all calculations on Trade enity works by trying to force
    // division by zero by setting all input 0, correct result should be error -1.00.
    std::cout << "<-- test_stockcalcuator::main [TEST4: Trade Calculations Check]" << std::endl;
    try
    {
        Trade trade(0.00, 0);
        assert(trade.calculateGeometricMeanAllShareIndex() == -1.00 &&
               trade.calculateVolumeWeightedStockPrice() == -1.00);
        std::cout << "<-- test_stockcalcuator::main [TEST4: PASSED]" << std::endl;
    }
    catch(...)
    {
        std::cout << "<-- test_stockcalcuator::main [TEST4: FAILED]" << std::endl;
    }

    return 0;
}
