#include <gtest/gtest.h>
#include "SavingAccount.h"

class AccountTest : public ::testing::Test 
{
protected:
    SavingAccount* account;

    void SetUp() override 
    {
        account = new SavingAccount(2000.0, 99999);
        account->deposit(500.0);
        account->withdraw(200.0);
        account->deposit(100.0);
        account->withdraw(50.0);
        account->deposit(300.0);
        account->withdraw(100.0);
    }

    void TearDown() override 
    {
        delete account;
    }
};

TEST_F(AccountTest, GetAccountSummaryTest) 
{
    std::string summary = account->getAccountSummary();
    EXPECT_TRUE(summary.find("Account No: 99999") != std::string::npos);
    EXPECT_TRUE(summary.find("Type: Saving") != std::string::npos);
    EXPECT_TRUE(summary.find("Balance: ₹") != std::string::npos);
}

TEST_F(AccountTest, SetBalanceTest) 
{
    account->setBalance(3000.0);
    EXPECT_EQ(account->getBalance(), 3000.0);
}

TEST_F(AccountTest, GetTransactionHistoryTest) 
{
    std::vector<std::string> history = account->getTransactionHistory();
    EXPECT_EQ(history.size(), 6);

    int iterator = 0;
    while (iterator < history.size()) {
        EXPECT_FALSE(history[iterator].empty());
        iterator++;
    }
}

TEST_F(AccountTest, GetMiniStatementTest) 
{
    std::vector<std::string> miniStatement = account->getMiniStatement();
    EXPECT_EQ(miniStatement.size(), 5);
}

TEST_F(AccountTest, GetMiniStatementWithFewerTransactions) 
{
    SavingAccount* smallAccount = new SavingAccount(1000.0, 88888);
    smallAccount->deposit(100.0);
    smallAccount->withdraw(50.0);

    std::vector<std::string> smallMini = smallAccount->getMiniStatement();
    EXPECT_EQ(smallMini.size(), 2);

    delete smallAccount;
}

TEST_F(AccountTest, GetMiniStatementEmptyTest) 
{
    SavingAccount* emptyAccount = new SavingAccount(1000.0, 77777);
    std::vector<std::string> emptyMiniStatement = emptyAccount->getMiniStatement();
    EXPECT_EQ(emptyMiniStatement.size(), 0);

    delete emptyAccount;
}

TEST_F(AccountTest, MiniStatementReturnsLastFiveDeposits) 
{
    SavingAccount* acc = new SavingAccount(1000.0, 1);
    int iterator = 0;
    while (iterator < 7) {
        acc->deposit(100.0);
        iterator++;
    }

    std::vector<std::string> miniStatement = acc->getMiniStatement();
    EXPECT_EQ(miniStatement.size(), 5);

    delete acc;
}
