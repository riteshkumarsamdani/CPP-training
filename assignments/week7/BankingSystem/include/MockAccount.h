#pragma once
#include <gmock/gmock.h>
#include "IAccount.h"

class MockAccount : public IAccount {
public:
    MOCK_METHOD(int, getAccountNumber, (), (const, override));
    MOCK_METHOD(double, getBalance, (), (const, override));
    MOCK_METHOD(void, transactionHandler, (), (override));
    MOCK_METHOD(void, setBalance, (double balance), (override));
    MOCK_METHOD(bool, deposit, (double amount), (override));
    MOCK_METHOD(bool, withdraw, (double amount), (override));
    MOCK_METHOD(std::string, getAccountSummary, (), (const, override));
    MOCK_METHOD(std::vector<std::string>, getTransactionHistory, (), (const, override));
    MOCK_METHOD(std::vector<std::string>, getMiniStatement, (), (const, override));
    MOCK_METHOD(std::string, getAccountType, (), (const, override));
};
