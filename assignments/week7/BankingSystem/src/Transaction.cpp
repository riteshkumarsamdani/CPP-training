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

Transaction::Transaction(std::string type, double prevBal, double inputAmount)
    : type(type), previousBalance(prevBal), amount(inputAmount), timestamp(getCurrentDateTime()), currentBalance(prevBal) {}

std::string Transaction::getTransaction() const {
    return "Type: " + type +
           ", Amount: ₹" + std::to_string(amount) +
           ", Previous: ₹" + std::to_string(previousBalance) +
           ", Current: ₹" + std::to_string(currentBalance) +
           ", Time: " + timestamp;
}

void Transaction::setCurrentBalance(double balance)
{
    currentBalance = balance;
}
