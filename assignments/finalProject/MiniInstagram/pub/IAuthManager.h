#ifndef IAUTH_MANAGER_H
#define IAUTH_MANAGER_H

#include "IUser.h"
#include <string>
#include <vector>

enum class AuthError
{
    None,
    EmptyFields,
    UserExists,
    UserNotFound,
    InvalidPassword
};

struct AuthResult
{
    bool success;
    AuthError error;
};

class IAuthManager
{
    public:
        virtual ~IAuthManager() {}
        virtual AuthResult signUp(const std::string& username, const std::string& password) = 0;
        virtual AuthResult signIn(const std::string& username, const std::string& password) = 0;
        virtual void signOut() = 0;
        virtual bool deleteUser(const std::string& username) = 0;
        virtual std::vector<IUser*> getAllUsers() = 0;
        virtual IUser* getCurrentUser() = 0;
        virtual bool isLoggedIn() = 0;
        virtual IUser* getUserByUsername(const std::string& username) = 0;
};

#endif
