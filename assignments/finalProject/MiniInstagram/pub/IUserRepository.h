#ifndef IUSER_REPOSITORY_H
#define IUSER_REPOSITORY_H

#include "IUser.h"
#include <vector>
#include <string>

class IUserRepository
{
    public:
        virtual ~IUserRepository() {};
        virtual std::vector<IUser*> getAllUsers() = 0;
        virtual bool saveUsers(const std::vector<IUser*>& users) = 0;
};

#endif
