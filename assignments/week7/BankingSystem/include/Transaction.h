#include <string>
#ifndef TRANSECTION_H
#define TRANSECTION_H

class Transaction
{
    private:
        std::string type;
        double previousBalance;
        double currentBalance;
        double amount;
        std::string timestamp;
    public:
        Transaction(std::string type, double prevBalance,double amount);
        std::string getTransaction() const;
        void setCurrentBalance(double balance);
};

#endif
