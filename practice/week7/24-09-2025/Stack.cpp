#include <iostream>
#include <vector>
#include <gtest/gtest.h>

class Stack
{
    private:
        std::vector<int> vStack;
    public:
        void push(int n)
        {
            vStack.push_back(n);
        }
        int pop()
        {
            if(vStack.size()>0)
            {
                int val = vStack.back();
                vStack.pop_back();
                return val;
            }
            else
            {
                return -1;
            }
        }
        int size()
        {
            return vStack.size();
        }
};

struct StackTest : public testing::Test
{
    Stack s;
    void SetUp()
    {
        int value[] = {1,2,3,4,5,6,7,8,9};
        for(auto i:value)
        {
            s.push(i);
        }
    }
    void TearDown() {}
};

TEST_F(StackTest,popTest)
{
    int lastPoppedValue = 9;
    while(lastPoppedValue != 0)
    {
        ASSERT_EQ(s.pop(),lastPoppedValue--);
    }
}

TEST_F(StackTest,sizeCheck)
{
    int val = s.size();
    for(val;val>0;val--)
    {
        ASSERT_NE(s.pop(),-1);
    }
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
