#include <gtest/gtest.h>
#include "Admin.h"
#include "User.h"
#include "SavingAccount.h"
#include "CurrentAccount.h"

class AdminTest : public ::testing::Test 
{
protected:
    Admin* admin;
    std::vector<User*> users;
    User* user1;
    User* user2;

    void SetUp() override {
        admin = new Admin("admin123", "password123");
        user1 = new User("user1", "pass1", new SavingAccount(1000.0, 1001));
        user2 = new User("user2", "pass2", new CurrentAccount(2000.0, 1002));
        users.push_back(user1);
        users.push_back(user2);
    }

    void TearDown() override {
        int iterator = 0;
        while(iterator < users.size())
        {
            delete users[iterator]->getAccount();
            delete users[iterator];
            iterator++;
        }
        users.clear();
        delete admin;
    }
};

TEST_F(AdminTest, ConstructorTest) {
    EXPECT_EQ(admin->getAdminId(), "admin123");
    EXPECT_EQ(admin->getAdminPassword(), "password123");
}

TEST_F(AdminTest, FindUserExistsTest) {
    User* found = admin->findUser(users, "user1");
    EXPECT_NE(found, nullptr);
    EXPECT_EQ(found->getUserId(), "user1");
}

TEST_F(AdminTest, FindUserNotExistsTest) {
    User* found = admin->findUser(users, "nonexistent");
    EXPECT_EQ(found, nullptr);
}

TEST_F(AdminTest, FindUserEmptyVectorTest) {
    std::vector<User*> emptyUsers;
    User* found = admin->findUser(emptyUsers, "user1");
    EXPECT_EQ(found, nullptr);
}

TEST_F(AdminTest, ShowAllUserLogicOnlyTest) {
    admin->showAllUser(users); 
}

TEST_F(AdminTest, ShowAllUserEmptyLogicOnlyTest) {
    std::vector<User*> emptyUsers;
    admin->showAllUser(emptyUsers);
}
