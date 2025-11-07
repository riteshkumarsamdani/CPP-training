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
        std::string otherUsername = "bob";

        IUser* createMockUser(const std::string& name, const std::string& pass, bool useMock = false)
        {
            if (useMock)
            {
                auto* mock = new MockUser();
                EXPECT_CALL(*mock, getUsername()).WillRepeatedly(testing::Return(name));
                EXPECT_CALL(*mock, getPassword()).WillRepeatedly(testing::Return(pass));
                EXPECT_CALL(*mock, getUserId()).WillRepeatedly(testing::Return("U_" + name));
                return mock;
            }
            return new User(name, pass);
        }
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
    IUser* user = createMockUser(username, password);
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
    IUser* user = createMockUser(username, "wrongpass");
    std::vector<IUser*> users = {user};
    AuthManager manager(users);
    AuthResult result = manager.signIn(username, password);
    EXPECT_FALSE(result.success);
    EXPECT_EQ(result.error, AuthError::InvalidPassword);
}

TEST_F(AuthManagerTest, GivenCorrectCredentials_WhenSignInIsCalled_ThenReturnsSuccessAndSetsCurrentUser)
{
    IUser* user = createMockUser(username, password);
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
    IUser* user = createMockUser(username, password);
    std::vector<IUser*> users = {user};
    AuthManager manager(users);
    manager.signIn(username, password);
    manager.signOut();
    EXPECT_EQ(manager.getCurrentUser(), nullptr);
    EXPECT_FALSE(manager.isLoggedIn());
}

TEST_F(AuthManagerTest, GivenExistingUser_WhenDeleteUserIsCalled_ThenReturnsTrueAndRemovesUser)
{
    IUser* user = createMockUser(username, password);
    std::vector<IUser*> users = {user};
    AuthManager manager(users);
    bool result = manager.deleteUser(username);
    EXPECT_TRUE(result);
    EXPECT_TRUE(manager.getAllUsers().empty());
}

TEST_F(AuthManagerTest, GivenSignedInUser_WhenDeleteUserIsCalled_ThenCurrentUserIsReset)
{
    IUser* user = createMockUser(username, password);
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
    IUser* user1 = createMockUser(username, password);
    IUser* user2 = createMockUser(otherUsername, "xyz");
    std::vector<IUser*> users = {user1, user2};
    AuthManager manager(users);
    IUser* result = manager.getUserByUsername(otherUsername);
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->getUsername(), otherUsername);
}

TEST_F(AuthManagerTest, GivenNoMatch_WhenGetUserByUsernameIsCalled_ThenReturnsNullptr)
{
    std::vector<IUser*> users;
    AuthManager manager(users);
    IUser* result = manager.getUserByUsername(username);
    EXPECT_EQ(result, nullptr);
}
