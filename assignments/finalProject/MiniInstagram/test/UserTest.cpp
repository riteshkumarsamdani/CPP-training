#include <gtest/gtest.h>
#include "User.h"

class UserTest : public ::testing::Test
{
    protected:
        std::string sampleUsername = "alice";
        std::string samplePassword = "secure123";
};

TEST_F(UserTest, GivenUsernameAndPassword_WhenUserIsCreated_ThenUserIdIsGenerated)
{
    User user(sampleUsername, samplePassword);
    std::string userId = user.getUserId();
    EXPECT_FALSE(userId.empty());
    EXPECT_TRUE(userId[0] == 'U');
}

TEST_F(UserTest, GivenUsernameAndPassword_WhenUserIsCreated_ThenUsernameIsStored)
{
    User user(sampleUsername, samplePassword);
    std::string username = user.getUsername();
    EXPECT_EQ(username, sampleUsername);
}

TEST_F(UserTest, GivenUsernameAndPassword_WhenUserIsCreated_ThenPasswordIsStored)
{
    User user(sampleUsername, samplePassword);
    std::string password = user.getPassword();
    EXPECT_EQ(password, samplePassword);
}

TEST_F(UserTest, GivenExplicitUserId_WhenUserIsConstructed_ThenUserIdIsPreserved)
{
    std::string customId = "U12345";
    User user(customId, sampleUsername, samplePassword);
    std::string userId = user.getUserId();
    EXPECT_EQ(userId, customId);
}

TEST_F(UserTest, GivenUsername_WhenUserIdIsGenerated_ThenItIncludesUsernamePrefix)
{
    User user(sampleUsername, samplePassword);
    std::string userId = user.getUserId();
    EXPECT_TRUE(userId.find(sampleUsername.substr(0, 2)) != std::string::npos);
}
