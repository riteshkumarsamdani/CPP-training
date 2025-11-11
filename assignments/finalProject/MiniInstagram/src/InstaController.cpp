#include "InstaController.h"
#include "InputHandler.h"
#include <iostream>

InstaController::InstaController(const std::string& userFilePath, const std::string& postFilePath)
{
    userRepo = new UserRepository(userFilePath);
    postRepo = new PostRepository(postFilePath);
    std::vector<IPost*> posts = postRepo->getAllPosts();
    std::vector<IUser*> users = userRepo->getAllUsers();
    authManager = new AuthManager(users);
    postManager = new PostManager(posts);
}

InstaController::~InstaController()
{
    std::vector<IPost*> posts = postManager->getAllPosts();
    std::vector<IUser*> users = authManager->getAllUsers();
    postRepo->savePosts(posts);
    userRepo->saveUsers(users);
    delete postRepo;
    delete userRepo;
    delete authManager;
    delete postManager;
}

void InstaController::run()
{
    running = true;
    while (running)
    {
        if (!authManager->isLoggedIn())
        {
            mainMenuHandler();
        }
        else
        {
            userMenuHandler();
        }
    }
}

void InstaController::mainMenuHandler()
{
    std::cout << "\n========== INSTAGRAM ==========\n";
    std::cout << "1. Sign Up\n";
    std::cout << "2. Sign In\n";
    std::cout << "3. Exit\n";
    int userChoice;
    input.getUserInput("Enter your choice: ", userChoice);
    switch (userChoice)
    {
        case 1: 
            handleSignUp(); 
            break;
        case 2: 
            handleSignIn(); 
            break;
        case 3: 
            running = false;
            break;
        default: 
            std::cout << "Invalid choice!\n";
    }
}

void InstaController::userMenuHandler()
{
    std::cout << "\n========== WELCOME " << authManager->getCurrentUser()->getUsername() << " ==========\n";
    std::cout << "1. Create Post\n";
    std::cout << "2. View Timeline (All Posts)\n";
    std::cout << "3. View My Posts\n";
    std::cout << "4. Like a Post\n";
    std::cout << "5. Unlike a Post\n";
    std::cout << "6. View Post Likes\n";
    std::cout << "7. Delete My Account\n";
    std::cout << "8. Delete a Post\n";
    std::cout << "9. Sign Out\n";
    int userChoice;
    input.getUserInput("Enter your choice: ", userChoice);
    switch (userChoice)
    {
        case 1: 
            handleCreatePost(); 
            break;
        case 2: 
            handleViewTimeline();
            break;
        case 3: 
            handleViewMyPosts(); 
            break;
        case 4: 
            handleLikePost(); 
            break;
        case 5: 
            handleUnlikePost(); 
            break;
        case 6: 
            handleViewPostLikes(); 
            break;
        case 7: 
            handleDeleteUser(); 
            break;
        case 8: 
            handleDeletePost(); 
            break;
        case 9:
            authManager->signOut(); 
            break;
        default: 
            std::cout << "Invalid choice!\n";
    }
}

void InstaController::handleSignUp()
{
    std::string username, password;
    input.getUserInput("Enter username: ", username);
    input.getUserInput("Enter password: ", password);

    AuthResult result = authManager->signUp(username, password);
    switch (result.error)
    {
        case AuthError::None:
            std::cout << "Sign up successful!\n";
            break;
        case AuthError::EmptyFields:
            std::cout << "Username and password cannot be empty!\n";
            break;
        case AuthError::UserExists:
            std::cout << "Username already exists!\n";
            break;
        default:
            std::cout << "Unknown error during sign up.\n";
    }
}

void InstaController::handleSignIn()
{
    std::string username, password;
    input.getUserInput("Enter username: ", username);
    input.getUserInput("Enter password: ", password);

    AuthResult result = authManager->signIn(username, password);
    switch (result.error)
    {
        case AuthError::None:
            std::cout << "Sign in successful!\n";
            break;
        case AuthError::UserNotFound:
            std::cout << "User not found!\n";
            break;
        case AuthError::InvalidPassword:
            std::cout << "Invalid password!\n";
            break;
        default:
            std::cout << "Unknown error during sign in.\n";
    }
}

void InstaController::handleCreatePost()
{
    std::string content;
    input.getLineInput("Enter post content: ", content);
    PostResult result = postManager->createPost(authManager->getCurrentUser()->getUserId(), content);
    switch (result.error)
    {
        case PostError::None:
            std::cout << "Post created successfully!\n";
            break;
        case PostError::EmptyContent:
            std::cout << "Post content cannot be empty!\n";
            break;
        default:
            std::cout << "Failed to create post.\n";
    }
}


void InstaController::handleViewTimeline()
{
    std::vector<IPost*> posts = postManager->getAllPosts();
    if (posts.empty())
    {
        std::cout << "No posts available.\n";
    }
    else
    {
        std::cout << "\n========== TIMELINE ==========\n";
        std::vector<IUser*> allUsers = authManager->getAllUsers();
        for (auto post : posts)
        {
            std::string authorName = "Unknown";
            for (auto user : allUsers)
            {
                if (user->getUserId() == post->getUserId())
                {
                    authorName = user->getUsername();
                    break;
                }
            }
            std::cout << "\n[Post ID: " << post->getPostId() << "]\n";
            std::cout << "Author: " << authorName << "\n";
            std::cout << "Content: " << post->getContent() << "\n";
            std::cout << "Time: " << post->getTimestamp() << "\n";
            std::cout << "Likes: " << post->getLikeCount() << "\n";
            std::cout << "----------------------------\n";
        }
    }
}

void InstaController::handleViewMyPosts()
{
    std::vector<IPost*> posts = postManager->getPostsByUser(authManager->getCurrentUser()->getUserId());
    if (posts.empty())
    {
        std::cout << "You haven't posted anything yet.\n";
    }
    else
    {
        std::cout << "\n========== MY POSTS ==========\n";
        for (auto post : posts)
        {
            std::cout << "\n[Post ID: " << post->getPostId() << "]\n";
            std::cout << "Content: " << post->getContent() << "\n";
            std::cout << "Time: " << post->getTimestamp() << "\n";
            std::cout << "Likes: " << post->getLikeCount() << "\n";
            std::cout << "----------------------------\n";
        }
    }
}

void InstaController::handleLikePost()
{
    std::string postId;
    input.getUserInput("Enter post ID to like: ", postId);

    PostResult result = postManager->likePost(postId, authManager->getCurrentUser()->getUsername());
    switch (result.error)
    {
        case PostError::None:
            std::cout << "Post liked successfully!\n";
            break;
        case PostError::AlreadyLiked:
            std::cout << "You have already liked this post!\n";
            break;
        case PostError::NotFound:
            std::cout << "Post not found!\n";
            break;
        default:
            std::cout << "Failed to like post.\n";
    }
}

void InstaController::handleUnlikePost()
{
    std::string postId;
    input.getUserInput("Enter post ID to unlike: ", postId);

    PostResult result = postManager->unlikePost(postId, authManager->getCurrentUser()->getUsername());
    switch (result.error) {
        case PostError::None:
            std::cout << "Post unliked successfully!\n";
            break;
        case PostError::NotLiked:
            std::cout << "You haven't liked this post!\n";
            break;
        case PostError::NotFound:
            std::cout << "Post not found!\n";
            break;
        default:
            std::cout << "Failed to unlike post.\n";
    }
}

void InstaController::handleViewPostLikes()
{
    std::string postId;
    input.getUserInput("Enter post ID: ", postId);
    std::vector<std::string> likedByUsers = postManager->getUsersWhoLiked(postId);
    int likeCount = postManager->getPostLikeCount(postId);
    std::cout << "\nTotal Likes: " << likeCount << "\n";
    if (likedByUsers.empty())
    {
        std::cout << "No likes yet.\n";
    }
    else
    {
        std::cout << "Liked by:\n";
        for(const auto& username : likedByUsers)
        {
            std::cout << "  -" << username << std::endl;
        }
    }
}

void InstaController::handleDeleteUser() 
{
    IUser* currentUser = authManager->getCurrentUser();
    if (!currentUser)
    {
        std::cout << "No user is currently signed in.\n";
    }
    else
    {
        std::string username = currentUser->getUsername();
        std::string userId = currentUser->getUserId();
        if (authManager->deleteUser(username))
        {
            postManager->deletePostsByUser(userId);
            std::cout << "User and all associated posts deleted successfully.\n";
            authManager->signOut();
        }
        else
        {
            std::cout << "Failed to delete user.\n";
        }
    }
}

void InstaController::handleDeletePost()
{
    std::string postId;
    input.getUserInput("Enter post ID to delete: ", postId);
    std::string userId = authManager->getCurrentUser()->getUserId();
    PostResult result = postManager->deletePost(postId, userId);
    switch (result.error)
    {
        case PostError::None:
            std::cout << "Post deleted successfully.\n";
            break;
        case PostError::Unauthorized:
            std::cout << "You are not authorized to delete this post!\n";
            break;
        case PostError::NotFound:
            std::cout << "Post not found!\n";
            break;
        default:
            std::cout << "Failed to delete post.\n";
    }
}
