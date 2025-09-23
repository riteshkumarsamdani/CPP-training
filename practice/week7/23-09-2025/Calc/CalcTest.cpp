#include <gtest/gtest.h>
#include "Calc.h"

TEST(CalcTest,addition)
{
    Calc c;
    ASSERT_EQ(c.add(2,3),5);
    ASSERT_EQ(c.add(-1,-3),-4);
}

TEST(CalcTest,multiply)
{
    Calc c;
    ASSERT_EQ(c.multiply(2,3),6);
    ASSERT_EQ(c.multiply(6,7),42);
}

TEST(CalcTest,division)
{
    Calc c;
    ASSERT_EQ(c.division(2,1),2);
    ASSERT_EQ(c.division(6,3),2);
    ASSERT_THROW(c.division(3,0),std::runtime_error);
}

TEST(CalcTest,subtraction)
{
    Calc c;
    ASSERT_EQ(c.sub(12,3),9);
    ASSERT_EQ(c.sub(6,7),-1);
}

