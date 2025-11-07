#include <gtest/gtest.h>
#include <fstream>
#include "UserRepository.h"
#include "User.h"

class UserRepositoryTest : public ::testing::Test
{
    protected:
        std::string testFile = "lib/test_users.json";

        void SetUp() override
        {
            std::ofstream file(testFile);
            file << "[]";
            file.close();
        }
};

TEST_F(UserRepositoryTest, GivenEmptyFile_WhenGetAllUsersIsCalled_ThenReturnsEmptyList)
{
    UserRepository repo(testFile);
    std::vector<IUser*> users = repo.getAllUsers();
    EXPECT_TRUE(users.empty());
}

TEST_F(UserRepositoryTest, GivenValidUsers_WhenSaveUsersIsCalled_ThenReturnsTrue)
{
    UserRepository repo(testFile);
    std::vector<IUser*> users;
    users.push_back(new User("U1", "alice", "pass1"));
    users.push_back(new User("U2", "bob", "pass2"));
    bool result = repo.saveUsers(users);
    EXPECT_TRUE(result);
    for (auto user : users) delete user;
}

TEST_F(UserRepositoryTest, GivenSavedUsers_WhenGetAllUsersIsCalled_ThenReturnsCorrectUserObjects)
{
    nlohmann::json jsonData = {
        {{"userId", "U1"}, {"username", "alice"}, {"password", "pass1"}},
        {{"userId", "U2"}, {"username", "bob"}, {"password", "pass2"}}
    };
    std::ofstream file(testFile);
    file << jsonData.dump(2);
    file.close();

    UserRepository repo(testFile);
    std::vector<IUser*> users = repo.getAllUsers();

    ASSERT_EQ(users.size(), 2);
    EXPECT_EQ(users[0]->getUserId(), "U1");
    EXPECT_EQ(users[0]->getUsername(), "alice");
    EXPECT_EQ(users[0]->getPassword(), "pass1");
    EXPECT_EQ(users[1]->getUserId(), "U2");
    EXPECT_EQ(users[1]->getUsername(), "bob");
    EXPECT_EQ(users[1]->getPassword(), "pass2");

    for (auto user : users) delete user;
}

TEST_F(UserRepositoryTest, GivenMalformedJson_WhenGetAllUsersIsCalled_ThenReturnsEmptyList)
{
    std::ofstream file(testFile);
    file << "{ invalid json }";
    file.close();

    UserRepository repo(testFile);
    std::vector<IUser*> users = repo.getAllUsers();
    EXPECT_TRUE(users.empty());
}
