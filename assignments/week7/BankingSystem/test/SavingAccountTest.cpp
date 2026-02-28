#include <gtest/gtest.h>
#include "SavingAccount.h"

class SavingAccountTest : public ::testing::Test 
{
protected:
    SavingAccount* account;

    void SetUp() override 
    {
        account = new SavingAccount(1000.0, 12345);
    }
    void TearDown() override {
        delete account;
    }
};

TEST_F(SavingAccountTest, ConstructorTest) 
{
    EXPECT_EQ(account->getBalance(), 1000.0);
    EXPECT_EQ(account->getAccountNumber(), 12345);
    EXPECT_EQ(account->getAccountType(), "Saving");
}

TEST_F(SavingAccountTest, DepositValidAmountTest) 
{
    bool result = account->deposit(500.0);
    EXPECT_TRUE(result);
    EXPECT_EQ(account->getBalance(), 1500.0);

    auto history = account->getTransactionHistory();
    EXPECT_EQ(history.size(), 1);
    EXPECT_TRUE(history[0].find("deposit") != std::string::npos);
}

TEST_F(SavingAccountTest, DepositInvalidAmountTest) 
{
    EXPECT_FALSE(account->deposit(0.0));
    EXPECT_EQ(account->getBalance(), 1000.0);

    EXPECT_FALSE(account->deposit(-100.0));
    EXPECT_EQ(account->getBalance(), 1000.0);
}

TEST_F(SavingAccountTest, WithdrawValidAmountTest) 
{
    bool result = account->withdraw(300.0);
    EXPECT_TRUE(result);
    EXPECT_EQ(account->getBalance(), 700.0);
}

TEST_F(SavingAccountTest, WithdrawInsufficientFundsTest) {
    bool result = account->withdraw(1500.0);
    EXPECT_FALSE(result);
    EXPECT_EQ(account->getBalance(), 1000.0);
}

TEST_F(SavingAccountTest, WithdrawInvalidAmountTest) 
{
    EXPECT_FALSE(account->withdraw(0.0));
    EXPECT_EQ(account->getBalance(), 1000.0);

    EXPECT_FALSE(account->withdraw(-100.0));
    EXPECT_EQ(account->getBalance(), 1000.0);
}

TEST_F(SavingAccountTest, WithdrawExactBalanceTest) 
{
    EXPECT_TRUE(account->withdraw(1000.0));
    EXPECT_EQ(account->getBalance(), 0.0);
}
