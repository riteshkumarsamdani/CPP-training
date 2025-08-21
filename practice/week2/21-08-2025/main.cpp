#include<iostream>
#include"add.h"
#include"subtract.h"

int main()
{
    std::cout << "enter the choice + for addition or - for subtration\n";
    char choice;
    double a, b;
    double ans;
    std::cin >> choice;

    switch(choice)
    {
        case '+':
            std::cout << "enter number for addition\n";
            std::cin >> a >> b;
            ans = add(a, b);
            std::cout << "\nans is : " << ans <<"\n";
            break;

        case '-':
            std::cout << "enter number for subtraction\n";
            std::cin >> a >> b;
            ans = subtract(a, b);
            std::cout << "\nans is : " << ans << "\n";
            break;

        default:
            std::cout << "not valid choice\n";
            break;
    }
    return 0;
}
