#include <gtest/gtest.h>
#include "Mock.h"

TEST(CalcTest, AddTest) 
{
    MockCalc mock;
    EXPECT_CALL(mock, add(3, 4)).WillOnce(::testing::Return(7));

    int result = mock.add(3, 4);
    EXPECT_EQ(result, 7);
}

TEST(CalcTest, SubTest) {
    MockCalc mock;
    EXPECT_CALL(mock, sub(10, 5)).WillOnce(::testing::Return(5));
    EXPECT_EQ(mock.sub(10, 5), 5);
}

TEST(CalcTest, MulTest) {
    MockCalc mock;
    EXPECT_CALL(mock, multiply(10, 5)).WillOnce(::testing::Return(50));
    EXPECT_EQ(mock.multiply(10, 5), 50);
}

TEST(CalcTest, DivTest) {
    MockCalc mock;
    EXPECT_CALL(mock, division(10, 2)).WillOnce(::testing::Return(5));
    EXPECT_EQ(mock.division(10, 2), 5);
}

TEST(CalcTest, DivByZeroTest) {
    MockCalc mock;
    EXPECT_CALL(mock, division(10, 0)).WillOnce(testing::Throw(std::runtime_error("Division by zero")));
    EXPECT_THROW(mock.division(10, 0), std::runtime_error);
}