#include <gtest/gtest.h>
#include "Bank.h"
#include "User.h"
#include "SavingAccount.h"
#include "CurrentAccount.h"
#include "Admin.h"

class BankTest : public ::testing::Test 
{
protected:
    Bank* bank;
    Admin* admin;
    User* user1;
    User* user2;

    void SetUp() override 
    {
        bank = new Bank();
        admin = new Admin("bankAdmin", "adminPass");
        bank->setAdmin(admin);

        user1 = new User("bankUser1", "userPass1", new SavingAccount(1500.0, 2001));
        user2 = new User("bankUser2", "userPass2", new CurrentAccount(2500.0, 2002));
        bank->getAllUser().push_back(user1);
        bank->getAllUser().push_back(user2);
    }

    void TearDown() override 
    {
        int iterator = 0;
        while(iterator < bank->getAllUser().size())
        {
            delete bank->getAllUser()[iterator]->getAccount();
            delete bank->getAllUser()[iterator];
            iterator++;
        }
        delete admin;
        delete bank;
    }
};

TEST_F(BankTest, SetAndGetAdminTest) 
{
    EXPECT_EQ(bank->getAdmin(), admin);

    Admin* newAdmin = new Admin("newAdmin", "newPass");
    bank->setAdmin(newAdmin);
    EXPECT_EQ(bank->getAdmin(), newAdmin);

    delete newAdmin;
    bank->setAdmin(admin);
}

TEST_F(BankTest, GetUserValidCredentialsTest) 
{
    User* found = bank->getUser("bankUser1", "userPass1");
    EXPECT_NE(found, nullptr);
    EXPECT_EQ(found->getUserId(), "bankUser1");
}

TEST_F(BankTest, GetUserWrongPasswordTest) 
{
    User* found = bank->getUser("bankUser1", "wrongPass");
    EXPECT_EQ(found, nullptr);
}

TEST_F(BankTest, GetUserNotFoundTest) 
{
    User* found = bank->getUser("nonexistent", "anyPass");
    EXPECT_EQ(found, nullptr);
}

TEST_F(BankTest, GetAllUserTest) 
{
    std::vector<User*>& allUsers = bank->getAllUser();
    EXPECT_EQ(allUsers.size(), 2);
    EXPECT_EQ(allUsers[0]->getUserId(), "bankUser1");
    EXPECT_EQ(allUsers[1]->getUserId(), "bankUser2");
}
