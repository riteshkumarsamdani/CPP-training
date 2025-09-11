#include <iostream>
#include <vector>
#include <string>

class Account
{
    int balance;
    public: 
    Account(int balance)
    {
        this->balance = balance;
    }
    int getBalance()
    {
        return balance;
    }
};

class User
{
    private:
        std::string userId;
        Account* account;
    public:
        User(std::string id, Account* ac)
        {
            userId = id;
            account = ac;
        }
        Account* getAccount()
        {
            return account;
        }
};

class Bank
{
    std::vector<User*> x;
    public:
        void setX(User* c)
        {
            x.push_back(c);
        }
        User* showX(int pos)
        {
            return x[pos];
        }
};

class Admin
{
    public:
    void createC(Bank& a, int r)
    {
        Account* c = new Account(r);
        User* user = new User("123", c);
        a.setX(user);
    }
        
};

int main()
{
    Bank bank;
    Admin admin;
    admin.createC(bank,2);
    std::cout << bank.showX(0)->getAccount() ->getBalance();
    return 0;
}
