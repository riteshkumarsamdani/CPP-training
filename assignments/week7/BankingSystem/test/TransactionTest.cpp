#include <gtest/gtest.h>
#include "Transaction.h"

class TransactionTest : public ::testing::Test 
{
protected:
    Transaction* depositTransaction;
    Transaction* withdrawTransaction;
    Transaction* zeroTransaction;
    Transaction* negativeTransaction;
    Transaction* emptyTypeTransaction;
    Transaction* transferTransaction;

    void SetUp() override 
    {
        depositTransaction = new Transaction("deposit", 1000.0, 500.0);
        withdrawTransaction = new Transaction("withdraw", 1500.0, 300.0);
        zeroTransaction = new Transaction("deposit", 100.0, 0.0);
        negativeTransaction = new Transaction("withdraw", 100.0, -50.0);
        emptyTypeTransaction = new Transaction("", 100.0, 50.0);
        transferTransaction = new Transaction("transfer", 2000.0, 750.0);
        transferTransaction->setCurrentBalance(2750.0);
    }

    void TearDown() override 
    {
        delete depositTransaction;
        delete withdrawTransaction;
        delete zeroTransaction;
        delete negativeTransaction;
        delete emptyTypeTransaction;
        delete transferTransaction;
    }
};

TEST_F(TransactionTest, ConstructorTest) 
{
    std::string result = depositTransaction->getTransaction();
    EXPECT_TRUE(result.find("deposit") != std::string::npos);
    EXPECT_TRUE(result.find("500") != std::string::npos);
    EXPECT_TRUE(result.find("1000") != std::string::npos);
}

TEST_F(TransactionTest, GetTransactionTest) 
{
    std::string result = withdrawTransaction->getTransaction();
    EXPECT_TRUE(result.find("Type: withdraw") != std::string::npos);
    EXPECT_TRUE(result.find("Amount: ₹300") != std::string::npos);
    EXPECT_TRUE(result.find("Previous: ₹1500") != std::string::npos);
    EXPECT_TRUE(result.find("Current: ₹1500") != std::string::npos);
    EXPECT_TRUE(result.find("Time: ") != std::string::npos);
}

TEST_F(TransactionTest, SetCurrentBalanceTest) 
{
    depositTransaction->setCurrentBalance(1500.0);
    std::string result = depositTransaction->getTransaction();
    EXPECT_TRUE(result.find("Current: ₹1500") != std::string::npos);
}

TEST_F(TransactionTest, EdgeCasesTest) 
{
    std::string result = zeroTransaction->getTransaction();
    EXPECT_TRUE(result.find("Amount: ₹0") != std::string::npos);

    result = negativeTransaction->getTransaction();
    EXPECT_TRUE(result.find("Amount: ₹-50") != std::string::npos);

    result = emptyTypeTransaction->getTransaction();
    EXPECT_TRUE(result.find("Type: ") != std::string::npos);
}

TEST_F(TransactionTest, TimestampIsPresent) 
{
    std::string result = depositTransaction->getTransaction();
    EXPECT_TRUE(result.find("Time: ") != std::string::npos);
}

TEST_F(TransactionTest, TransactionFormatIncludesAllFields) 
{
    std::string result = transferTransaction->getTransaction();
    EXPECT_TRUE(result.find("Type: transfer") != std::string::npos);
    EXPECT_TRUE(result.find("Amount: ₹750") != std::string::npos);
    EXPECT_TRUE(result.find("Previous: ₹2000") != std::string::npos);
    EXPECT_TRUE(result.find("Current: ₹2750") != std::string::npos);
}
