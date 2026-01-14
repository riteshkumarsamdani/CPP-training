#ifndef INSTA_CONTROLLER_H
#define INSTA_CONTROLLER_H

#include <iostream>
#include "IAuthManager.h"
#include "IPostManager.h"
#include "InputHandler.h"
#include "AuthManager.h"
#include "PostManager.h"
#include "UserRepository.h"
#include "PostRepository.h"

class InstaController
{
    private:
        IAuthManager* authManager;
        IPostManager* postManager;
        IUserRepository* userRepo;
        IPostRepository* postRepo;
        bool running;
        InputHandler input;

        void handleSignUp();
        void handleSignIn();
        void handleCreatePost();
        void handleViewTimeline();
        void handleViewMyPosts();
        void handleLikePost();
        void handleUnlikePost();
        void handleViewPostLikes();
        void handleDeleteUser();
        void handleDeletePost();

    public:
        InstaController(const std::string& userFilePath, const std::string& postFilePath);
        ~InstaController();
        void run();
        void mainMenuHandler();
        void userMenuHandler();
};

#endif
