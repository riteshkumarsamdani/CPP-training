#include <gtest/gtest.h>
#include "bankAccount.h"
#include <stdexcept>

TEST(BankAccountTest, WithdrawValidAmount) 
{
    BankAccount account(100.0);
    EXPECT_NO_THROW(account.withdraw(50.0));
}

TEST(BankAccountTest, WithdrawNegativeAmountThrows) 
{
    BankAccount account(100.0);
    EXPECT_THROW(account.withdraw(-10.0), std::invalid_argument);
}

TEST(BankAccountTest, WithdrawExceedingBalanceThrows) 
{
    BankAccount account(100.0);
    EXPECT_THROW(account.withdraw(150.0), InsufficientFundsException);
}
