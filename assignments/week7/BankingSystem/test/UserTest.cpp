#include <gtest/gtest.h>
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
