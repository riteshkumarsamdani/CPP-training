#include "repo.cpp"
#include <iostream>

class Insta
{
private:
    Repo* repo_;
    bool owns_repo_;

public:
    Insta(Repo* repo = nullptr)
        : repo_(repo ? repo : new Repo()), owns_repo_(repo == nullptr)
    {
        if(owns_repo_)
        {
            std::cout << "created new object" <<std::endl;
        }
    }

    int val()
    {
        return repo_->num();
    }

    bool val1()
    {
        return repo_->success();
    }

    ~Insta()
    {
        if (owns_repo_)
            delete repo_;
    }
};
