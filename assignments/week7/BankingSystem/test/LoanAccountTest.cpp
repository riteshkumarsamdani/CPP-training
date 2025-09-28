#include <gtest/gtest.h>
#include "LoanAccount.h"

class LoanAccountTest : public ::testing::Test {
protected:
    LoanAccount* account;

    void SetUp() override {
        account = new LoanAccount(-5000.0, 12348);
    }
    void TearDown() override {
        delete account;
    }
};

TEST_F(LoanAccountTest, ConstructorTest) 
{
    EXPECT_EQ(account->getBalance(), -5000.0);
    EXPECT_EQ(account->getAccountNumber(), 12348);
    EXPECT_EQ(account->getAccountType(), "Loan");
}

TEST_F(LoanAccountTest, DepositValidAmountTest) 
{
    bool result = account->deposit(1000.0);
    EXPECT_TRUE(result);
    EXPECT_EQ(account->getBalance(), -4000.0);

    auto history = account->getTransactionHistory();
    EXPECT_EQ(history.size(), 1);
    EXPECT_TRUE(history[0].find("deposit") != std::string::npos);
}

TEST_F(LoanAccountTest, WithdrawNotAllowedTest) 
{
    bool result = account->withdraw(100.0);
    EXPECT_FALSE(result);
    EXPECT_EQ(account->getBalance(), -5000.0);
}

TEST_F(LoanAccountTest, DepositInvalidAmountTest) 
{
    EXPECT_FALSE(account->deposit(0.0));
    EXPECT_EQ(account->getBalance(), -5000.0);

    EXPECT_FALSE(account->deposit(-100.0));
    EXPECT_EQ(account->getBalance(), -5000.0);
}

TEST_F(LoanAccountTest, WithdrawInvalidAmountTest) 
{
    EXPECT_FALSE(account->withdraw(0.0));
    EXPECT_FALSE(account->withdraw(-100.0));
    EXPECT_EQ(account->getBalance(), -5000.0);
}
