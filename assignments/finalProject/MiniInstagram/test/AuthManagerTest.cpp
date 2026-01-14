#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "AuthManager.h"
#include "User.h"

class MockUser : public IUser
{
    public:
        MOCK_METHOD(std::string, getUserId, (), (const, override));
        MOCK_METHOD(std::string, getUsername, (), (const, override));
        MOCK_METHOD(std::string, getPassword, (), (const, override));
};

class AuthManagerTest : public ::testing::Test
{
    protected:
        std::string username = "alice";
        std::string password = "pass123";
        std::string newUsername = "bob";

};

TEST_F(AuthManagerTest, GivenEmptyFields_WhenSignUpIsCalled_ThenReturnsEmptyFieldsError)
{
    std::vector<IUser*> users;
    AuthManager manager(users);
    AuthResult result = manager.signUp("", "");
    EXPECT_FALSE(result.success);
    EXPECT_EQ(result.error, AuthError::EmptyFields);
}

TEST_F(AuthManagerTest, GivenExistingUsername_WhenSignUpIsCalled_ThenReturnsUserExistsError)
{
    MockUser* user = new MockUser();
    EXPECT_CALL(*user, getUsername()).WillRepeatedly(testing::Return(username));
    std::vector<IUser*> users = {user};
    AuthManager manager(users);
    AuthResult result = manager.signUp(username, "newpass");
    EXPECT_FALSE(result.success);
    EXPECT_EQ(result.error, AuthError::UserExists);
}

TEST_F(AuthManagerTest, GivenValidCredentials_WhenSignUpIsCalled_ThenReturnsSuccess)
{
    std::vector<IUser*> users;
    AuthManager manager(users);
    AuthResult result = manager.signUp(username, password);
    EXPECT_TRUE(result.success);
    EXPECT_EQ(result.error, AuthError::None);
}

TEST_F(AuthManagerTest, GivenNonexistentUser_WhenSignInIsCalled_ThenReturnsUserNotFoundError)
{
    std::vector<IUser*> users;
    AuthManager manager(users);
    AuthResult result = manager.signIn(username, password);
    EXPECT_FALSE(result.success);
    EXPECT_EQ(result.error, AuthError::UserNotFound);
}

TEST_F(AuthManagerTest, GivenIncorrectPassword_WhenSignInIsCalled_ThenReturnsInvalidPasswordError)
{
    std::string incorrectPassword = "123";
    MockUser* user = new MockUser();
    EXPECT_CALL(*user, getUsername()).WillRepeatedly(testing::Return(username));
    EXPECT_CALL(*user, getPassword()).WillRepeatedly(testing::Return(password));
    std::vector<IUser*> users = {user};
    AuthManager manager(users);
    AuthResult result = manager.signIn(username, incorrectPassword);
    EXPECT_FALSE(result.success);
    EXPECT_EQ(result.error, AuthError::InvalidPassword);
}

TEST_F(AuthManagerTest, GivenCorrectCredentials_WhenSignInIsCalled_ThenReturnsSuccessAndSetsCurrentUser)
{
    MockUser* user = new MockUser();
    EXPECT_CALL(*user, getUsername()).WillRepeatedly(testing::Return(username));
    EXPECT_CALL(*user, getPassword()).WillRepeatedly(testing::Return(password));
    std::vector<IUser*> users = {user};
    AuthManager manager(users);
    AuthResult result = manager.signIn(username, password);
    IUser* current = manager.getCurrentUser();
    EXPECT_TRUE(result.success);
    EXPECT_EQ(result.error, AuthError::None);
    ASSERT_NE(current, nullptr);
    EXPECT_EQ(current->getUsername(), username);
}

TEST_F(AuthManagerTest, GivenSignedInUser_WhenSignOutIsCalled_ThenCurrentUserIsNull)
{
    MockUser* user = new MockUser();
    EXPECT_CALL(*user, getUsername()).WillRepeatedly(testing::Return(username));
    EXPECT_CALL(*user, getPassword()).WillRepeatedly(testing::Return(password));
    std::vector<IUser*> users = {user};
    AuthManager manager(users);
    manager.signIn(username, password);
    manager.signOut();
    EXPECT_EQ(manager.getCurrentUser(), nullptr);
    EXPECT_FALSE(manager.isLoggedIn());
}

TEST_F(AuthManagerTest, GivenExistingUser_WhenDeleteUserIsCalled_ThenReturnsTrueAndRemovesUser)
{
    MockUser* user = new MockUser();
    EXPECT_CALL(*user, getUsername()).WillRepeatedly(testing::Return(username));
    std::vector<IUser*> users = {user};
    AuthManager manager(users);
    bool result = manager.deleteUser(username);
    EXPECT_TRUE(result);
    EXPECT_TRUE(manager.getAllUsers().empty());
}

TEST_F(AuthManagerTest, GivenSignedInUser_WhenDeleteUserIsCalled_ThenCurrentUserIsReset)
{
    MockUser* user = new MockUser();
    EXPECT_CALL(*user, getUsername()).WillRepeatedly(testing::Return(username));
    EXPECT_CALL(*user, getPassword()).WillRepeatedly(testing::Return(password));
    std::vector<IUser*> users = {user};
    AuthManager manager(users);
    manager.signIn(username, password);
    bool result = manager.deleteUser(username);
    EXPECT_TRUE(result);
    EXPECT_EQ(manager.getCurrentUser(), nullptr);
}

TEST_F(AuthManagerTest, GivenNonexistentUser_WhenDeleteUserIsCalled_ThenReturnsFalse)
{
    std::vector<IUser*> users;
    AuthManager manager(users);
    bool result = manager.deleteUser(username);
    EXPECT_FALSE(result);
}

TEST_F(AuthManagerTest, GivenMultipleUsers_WhenGetUserByUsernameIsCalled_ThenReturnsCorrectUser)
{
    MockUser* user1 = new MockUser();
    MockUser* user2 = new MockUser();
    EXPECT_CALL(*user1, getUsername()).WillRepeatedly(testing::Return(username));
    EXPECT_CALL(*user2, getUsername()).WillRepeatedly(testing::Return(newUsername));
    std::vector<IUser*> users = {user1, user2};
    AuthManager manager(users);
    IUser* result = manager.getUserByUsername(newUsername);
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->getUsername(), newUsername);
}

TEST_F(AuthManagerTest, GivenNoMatch_WhenGetUserByUsernameIsCalled_ThenReturnsNullptr)
{
    std::vector<IUser*> users;
    AuthManager manager(users);
    IUser* result = manager.getUserByUsername(username);
    EXPECT_EQ(result, nullptr);
}
