#include<iostream>
#include<string.h>

void print(char *ch)
{
    while(*ch != '\0')
    {
        std::cout << *ch <<std::endl;
        ch++;
    }
}

void printIterator(char *ch)
{
    int i = 0;
    while(ch[i] != '\0')
    {
        std::cout << ch[i] <<std::endl;
        i++;
    }
}

int main()
{
    char ch[] = "hello";
    char ch1[] = "hello\0";
    std::cout << strlen(ch) << std::endl;
    std::cout << strlen(ch1) << std::endl;
    print(ch);
    printIterator(ch);
}