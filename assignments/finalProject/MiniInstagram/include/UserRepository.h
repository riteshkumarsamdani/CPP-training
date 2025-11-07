#ifndef USER_REPOSITORY_H
#define USER_REPOSITORY_H

#include "IUserRepository.h"
#include "nlohmann/json.hpp"
#include <string>

class UserRepository : public IUserRepository
{
    private:
        std::string filePath;
        void initializeFile();
        
        public:
        bool saveUsers(const std::vector<IUser*>& users) override;
        UserRepository(std::string filePath);
        std::vector<IUser*> getAllUsers() override;
};

#endif
