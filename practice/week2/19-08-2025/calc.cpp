#include<iostream>
#include"calculator.h"

int main()
{
    char choice;
    int a{}, b{};
    std::cout << "enetr choice to perform operation : +, -, *, / :";
    std::cin >> choice;
    do
    {
        switch(choice)
        {
            case '+' :
                std::cout << "enter two numbers to add\n";
                std::cin >> a >> b;
                std::cout << add(a,b);
                break;

            case '-' :
                std::cout << "enter two numbers to subtract\n";
                std::cin >> a >> b;
                std::cout << subtract(a,b);
                break;
            
            case '*' :
                std::cout << "enter two numbers to multiply\n";
                std::cin >> a >> b;
                std::cout << multiply(a,b);
                break;

            case '/' :
                std::cout << "enter two numbers to division\n";
                std::cin >> a >> b;
                std::cout << divide(a,b);
                break;

            default:
                std::cout << "enter valid choice\n";
                break;
        }
        std::cout << "enetr choice to perform operation : +, -, *, / :";
    }
    while(std::cin >> choice);
    return 0;
}