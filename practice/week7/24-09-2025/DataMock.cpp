#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class DataBaseConnect
{
    public:
        virtual bool login(std::string userName, std::string password) = 0;
        virtual bool logout(std::string userName) = 0;
        virtual int fetchRecord() = 0;
};

class MockDB : public DataBaseConnect
{
    public:
        // MOCK_METHOD(int, fetchRecord, (), (override));
        // MOCK_METHOD(bool, login, (std::string userName, std::string password), (override));
        // MOCK_METHOD(bool, logout, (std::string userName), (override));
        MOCK_METHOD0(fetchRecord,int());
        MOCK_METHOD2(login,bool(std::string userName, std::string password));
        MOCK_METHOD1(logout,bool(std::string userName));

};

class MyDataBase
{
    private:
        DataBaseConnect* dbc;
    public:
        MyDataBase(DataBaseConnect* _dbc):dbc(_dbc){}
        int Init(std::string userName, std::string password)
        {
            if(dbc->login(userName,password) != true)
            {
                std::cout << "User not logedIn!!\n";
                return -1;
            }
            else
            {
                std::cout << "Login success!!\n";
                return 1;
            }
        }
};

TEST(MyDBTest, loginTest) 
{
    MockDB mdb;
    MyDataBase db(&mdb);

    EXPECT_CALL(mdb, login("abc", "abc"))
        .Times(1)
        .WillOnce(::testing::Return(true));

    int returnVal = db.Init("abc", "abc");
    EXPECT_EQ(returnVal, 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
