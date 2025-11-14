#include <iostream>
#include "insta.cpp"

int main()
{
    Repo* repo = new Repo();
    // Insta insta1(repo);
    // std::cout << insta1.val() << std::endl;
    Insta insta(repo);
    std::cout << insta.val() << std::endl;
    std::cout << insta.val1() <<std::endl;
    delete repo;
    return 0;
}