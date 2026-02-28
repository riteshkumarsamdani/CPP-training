#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "User.h"
#include "MockAccount.h"

class UserTestFixture : public ::testing::Test 
{
protected:
    MockAccount* mockAccount;
    User* user;

    void SetUp() override 
    {
        mockAccount = new MockAccount();
        user = new User("testUser", "testPass", mockAccount);
    }

    void TearDown() override 
    {
        delete user;
        delete mockAccount;
    }
};

TEST_F(UserTestFixture, ConstructorTest) 
{
    EXPECT_EQ(user->getUserId(), "testUser");
    EXPECT_EQ(user->getPassword(), "testPass");
    EXPECT_EQ(user->getAccount(), mockAccount);
}

TEST_F(UserTestFixture, GetUserIdTest) 
{
    EXPECT_EQ(user->getUserId(), "testUser");
    User emptyUser("", "pass", mockAccount);
    EXPECT_EQ(emptyUser.getUserId(), "");
}

TEST_F(UserTestFixture, GetPasswordTest) 
{
    EXPECT_EQ(user->getPassword(), "testPass");
    User emptyPassUser("user", "", mockAccount);
    EXPECT_EQ(emptyPassUser.getPassword(), "");
}

TEST_F(UserTestFixture, GetAccountTest) 
{
    EXPECT_EQ(user->getAccount(), mockAccount);
    User nullAccountUser("user", "pass", nullptr);
    EXPECT_EQ(nullAccountUser.getAccount(), nullptr);
}

TEST_F(UserTestFixture, MultipleUsersTest) 
{
    User user1("userA", "passA", mockAccount);
    User user2("userB", "passB", mockAccount);
    EXPECT_EQ(user1.getUserId(), "userA");
    EXPECT_EQ(user2.getUserId(), "userB");
    EXPECT_EQ(user1.getPassword(), "passA");
    EXPECT_EQ(user2.getPassword(), "passB");
    EXPECT_EQ(user1.getAccount(), mockAccount);
    EXPECT_EQ(user2.getAccount(), mockAccount);
}

TEST_F(UserTestFixture, PointerConsistencyTest) 
{
    IAccount* accountPtr = user->getAccount();
    EXPECT_EQ(accountPtr, mockAccount);
}

TEST_F(UserTestFixture, GetBalanceDelegatesToAccount) 
{
    EXPECT_CALL(*mockAccount, getBalance()).WillOnce(::testing::Return(1000.0));
    EXPECT_EQ(user->getAccount()->getBalance(), 1000.0);
}

TEST_F(UserTestFixture, SetBalanceDelegatesToAccount) 
{
    EXPECT_CALL(*mockAccount, setBalance(2000.0)).Times(1);
    user->getAccount()->setBalance(2000.0);
}

TEST_F(UserTestFixture, DepositDelegatesToAccount) 
{
    EXPECT_CALL(*mockAccount, deposit(500.0)).WillOnce(::testing::Return(true));
    EXPECT_TRUE(user->getAccount()->deposit(500.0));
}

TEST_F(UserTestFixture, WithdrawFailsWhenInsufficientFunds) 
{
    EXPECT_CALL(*mockAccount, withdraw(1500.0)).WillOnce(::testing::Return(false));
    EXPECT_FALSE(user->getAccount()->withdraw(1500.0));
}

TEST_F(UserTestFixture, MiniStatementReturnsExpectedEntries) 
{
    std::vector<std::string> mockStatement = {
        "Type: deposit, Amount: ₹500",
        "Type: withdraw, Amount: ₹200"
    };
    EXPECT_CALL(*mockAccount, getMiniStatement()).WillOnce(::testing::Return(mockStatement));
    auto statement = user->getAccount()->getMiniStatement();
    EXPECT_EQ(statement.size(), 2);
    EXPECT_EQ(statement[0], "Type: deposit, Amount: ₹500");
}

TEST_F(UserTestFixture, DepositAndBalanceCheckSequence) 
{
    ::testing::InSequence seq;
    EXPECT_CALL(*mockAccount, deposit(500.0)).WillOnce(::testing::Return(true));
    EXPECT_CALL(*mockAccount, getBalance()).WillOnce(::testing::Return(1500.0));
    EXPECT_TRUE(user->getAccount()->deposit(500.0));
    EXPECT_EQ(user->getAccount()->getBalance(), 1500.0);
}

TEST_F(UserTestFixture, WithdrawDynamicBehaviorBasedOnAmount) 
{
    EXPECT_CALL(*mockAccount, withdraw(::testing::_))
        .WillRepeatedly([](double amount) { return amount <= 1000.0; });
    EXPECT_TRUE(user->getAccount()->withdraw(500.0));
    EXPECT_FALSE(user->getAccount()->withdraw(1500.0));
}

TEST_F(UserTestFixture, AccountSummaryCalledAfterBalanceUpdate) 
{
    EXPECT_CALL(*mockAccount, setBalance(3000.0)).Times(1);
    EXPECT_CALL(*mockAccount, getAccountSummary()).WillOnce(::testing::Return("Account Summary"));
    user->getAccount()->setBalance(3000.0);
    EXPECT_EQ(user->getAccount()->getAccountSummary(), "Account Summary");
}

TEST_F(UserTestFixture, MultipleDepositsAndBalanceCheck) 
{
    EXPECT_CALL(*mockAccount, deposit(::testing::_)).Times(5).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(*mockAccount, getBalance()).Times(5).WillRepeatedly(::testing::Return(1000.0));
    int iterator = 0;
    while(iterator < 5)
    {
        EXPECT_TRUE(user->getAccount()->deposit(100.0));
        EXPECT_EQ(user->getAccount()->getBalance(), 1000.0);
        iterator++;
    }
}

TEST_F(UserTestFixture, DepositTriggersTransactionHistoryCheck) 
{
    EXPECT_CALL(*mockAccount, deposit(500.0)).WillOnce(::testing::Return(true));
    EXPECT_CALL(*mockAccount, getTransactionHistory()).WillOnce(::testing::Return(std::vector<std::string>{"Tx1"}));
    user->getAccount()->deposit(500.0);
    auto history = user->getAccount()->getTransactionHistory();
    EXPECT_EQ(history.size(), 1);
}

TEST_F(UserTestFixture, MiniStatementHandlesEmptyAndMalformedEntries) 
{
    std::vector<std::string> mockStatement = {
        "", "Type: deposit", "Amount: ₹", "InvalidFormat"
    };
    EXPECT_CALL(*mockAccount, getMiniStatement()).WillOnce(::testing::Return(mockStatement));
    auto statement = user->getAccount()->getMiniStatement();
    EXPECT_EQ(statement.size(), 4);
    EXPECT_EQ(statement[0], "");
    EXPECT_TRUE(statement[1].find("deposit") != std::string::npos);
}

TEST_F(UserTestFixture, SaveArgCapturesDepositAmount) 
{
    double capturedAmount;
    EXPECT_CALL(*mockAccount, deposit(::testing::_))
        .WillOnce(::testing::DoAll(::testing::SaveArg<0>(&capturedAmount), ::testing::Return(true)));
    EXPECT_TRUE(user->getAccount()->deposit(750.0));
    EXPECT_EQ(capturedAmount, 750.0);
}

TEST(UserStrictMockTest, EnforceStrictCallExpectations) 
{
    ::testing::StrictMock<MockAccount>* strictAccount = new ::testing::StrictMock<MockAccount>();
    User strictUser("strictUser", "pass", strictAccount);
    EXPECT_CALL(*strictAccount, getBalance()).WillOnce(::testing::Return(1000.0));
    EXPECT_EQ(strictUser.getAccount()->getBalance(), 1000.0);
    delete strictAccount;
}
