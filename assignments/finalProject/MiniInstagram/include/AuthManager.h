#ifndef AUTH_MANAGER_H
#define AUTH_MANAGER_H

#include "IAuthManager.h"
#include "IUserRepository.h"

class AuthManager : public IAuthManager
{
    private:
        std::vector<IUser*> users;
        IUser* currentUser;
    
    public:
        IUser* getUserByUsername(const std::string& username) override;
        AuthManager(std::vector<IUser*> users);
        ~AuthManager();
        AuthResult signUp(const std::string& username, const std::string& password) override;
        AuthResult signIn(const std::string& username, const std::string& password) override;
        void signOut() override;
        bool deleteUser(const std::string& username) override;
        std::vector<IUser*> getAllUsers() override;
        IUser* getCurrentUser() override;
        bool isLoggedIn() override;
};

#endif
