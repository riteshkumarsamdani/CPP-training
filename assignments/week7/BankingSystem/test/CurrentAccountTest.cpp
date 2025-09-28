#include <gtest/gtest.h>
#include "CurrentAccount.h"

class CurrentAccountTest : public ::testing::Test 
{
protected:
    CurrentAccount* account;

    void SetUp() override {
        account = new CurrentAccount(1000.0, 12346, 5000.0);
    }
    void TearDown() override {
        delete account;
    }
};

TEST_F(CurrentAccountTest, ConstructorTest) 
{
    EXPECT_EQ(account->getBalance(), 1000.0);
    EXPECT_EQ(account->getAccountNumber(), 12346);
    EXPECT_EQ(account->getAccountType(), "Current");
}

TEST_F(CurrentAccountTest, ConstructorWithDefaultOverdraftTest) 
{
    CurrentAccount defaultOverdraft(2000.0, 12347);
    EXPECT_EQ(defaultOverdraft.getBalance(), 2000.0);
    EXPECT_EQ(defaultOverdraft.getAccountType(), "Current");
}

TEST_F(CurrentAccountTest, DepositValidAmountTest) 
{
    bool result = account->deposit(750.0);
    EXPECT_TRUE(result);
    EXPECT_EQ(account->getBalance(), 1750.0);
}

TEST_F(CurrentAccountTest, WithdrawWithinBalanceTest) 
{
    bool result = account->withdraw(500.0);
    EXPECT_TRUE(result);
    EXPECT_EQ(account->getBalance(), 500.0);
}

TEST_F(CurrentAccountTest, WithdrawWithOverdraftTest) 
{
    bool result = account->withdraw(1200.0); 
    EXPECT_TRUE(result);
    EXPECT_EQ(account->getBalance(), -200.0);
}

TEST_F(CurrentAccountTest, WithdrawExceedingOverdraftLimitTest) 
{
    bool result = account->withdraw(7000.0);
    EXPECT_FALSE(result);
    EXPECT_EQ(account->getBalance(), 1000.0);
}

TEST_F(CurrentAccountTest, WithdrawInvalidAmountTest) 
{
    EXPECT_FALSE(account->withdraw(0.0));
    EXPECT_FALSE(account->withdraw(-100.0));
    EXPECT_EQ(account->getBalance(), 1000.0);
}
