#include <iostream>
#include "Transaction.h"

std::string getCurrentDateTime() 
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buf[32];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", ltm);
    return std::string(buf);
}

Transaction::Transaction(std::string type, double prevBal, double inputAmount) : type(type), previousBalance(prevBal), amount(inputAmount), timestamp(getCurrentDateTime()) 
{
    if(type == "deposit")
    {
        currentBalance = previousBalance + amount;
    }
    else
    {
        currentBalance = previousBalance - amount;
    }
}

void Transaction::showTransactions()
{
    std::cout << "previous balance is: " << previousBalance << "\ncurrent balance is: " << currentBalance << "\ntime: " << timestamp << "\ntype: " << type << "\n";
}

double Transaction::getCurrentBal()
{
    return currentBalance;
}
