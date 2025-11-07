#ifndef POST_REPOSITORY_H
#define POST_REPOSITORY_H

#include "IPostRepository.h"
#include "nlohmann/json.hpp"
#include <string>

class PostRepository : public IPostRepository
{
    private:
        std::string filePath;
        void initializeFile();
        
    public:
        bool savePosts(const std::vector<IPost*>& posts) override;
        PostRepository(std::string filePath);
        std::vector<IPost*> getAllPosts() override;
};

#endif
