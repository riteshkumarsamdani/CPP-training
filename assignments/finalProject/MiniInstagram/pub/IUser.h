#ifndef IUSER_H
#define IUSER_H

#include <string>

class IUser
{
    public:
        virtual ~IUser() {}
        virtual std::string getUserId() const = 0;
        virtual std::string getUsername() const = 0;
        virtual std::string getPassword() const = 0;
};

#endif
