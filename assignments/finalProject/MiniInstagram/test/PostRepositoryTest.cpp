#include <gtest/gtest.h>
#include <fstream>
#include "PostRepository.h"
#include "Post.h"

class PostRepositoryTest : public ::testing::Test
{
    protected:
        std::string testFile = "lib/test_posts.json";

        void SetUp() override
        {
            std::ofstream file(testFile);
            file << "[]";
            file.close();
        }
};

TEST_F(PostRepositoryTest, GivenEmptyFile_WhenGetAllPostsIsCalled_ThenReturnsEmptyList)
{
    PostRepository repo(testFile);
    std::vector<IPost*> posts = repo.getAllPosts();
    EXPECT_TRUE(posts.empty());
}

TEST_F(PostRepositoryTest, GivenValidPosts_WhenSavePostsIsCalled_ThenReturnsTrue)
{
    PostRepository repo(testFile);
    std::vector<IPost*> posts;
    posts.push_back(new Post("U1", "Hello world"));
    posts.push_back(new Post("U2", "Second post"));
    bool result = repo.savePosts(posts);
    EXPECT_TRUE(result);
    for (auto post : posts) delete post;
}

TEST_F(PostRepositoryTest, GivenSavedPosts_WhenGetAllPostsIsCalled_ThenReturnsCorrectPostObjects)
{
    nlohmann::json jsonData = {
        {
            {"postId", "P1"},
            {"userId", "U1"},
            {"content", "Hello world"},
            {"timestamp", "2025-11-07 10:00:00"},
            {"likedByUsers", {"alice", "bob"}}
        },
        {
            {"postId", "P2"},
            {"userId", "U2"},
            {"content", "Second post"},
            {"timestamp", "2025-11-07 11:00:00"},
            {"likedByUsers", {"charlie"}}
        }
    };
    std::ofstream file(testFile);
    file << jsonData.dump(2);
    file.close();

    PostRepository repo(testFile);
    std::vector<IPost*> posts = repo.getAllPosts();

    ASSERT_EQ(posts.size(), 2);

    std::string postId1 = posts[0]->getPostId();
    std::string userId1 = posts[0]->getUserId();
    std::string content1 = posts[0]->getContent();
    std::string timestamp1 = posts[0]->getTimestamp();
    std::vector<std::string> likes1 = posts[0]->getLikedByUsers();

    EXPECT_EQ(postId1, "P1");
    EXPECT_EQ(userId1, "U1");
    EXPECT_EQ(content1, "Hello world");
    EXPECT_EQ(timestamp1, "2025-11-07 10:00:00");
    EXPECT_EQ(likes1.size(), 2);
    EXPECT_EQ(likes1[0], "alice");
    EXPECT_EQ(likes1[1], "bob");
    for (auto post : posts) delete post;
}

TEST_F(PostRepositoryTest, GivenMalformedJson_WhenGetAllPostsIsCalled_ThenReturnsEmptyList)
{
    std::ofstream file(testFile);
    file << "{ invalid json }";
    file.close();
    PostRepository repo(testFile);
    std::vector<IPost*> posts = repo.getAllPosts();
    EXPECT_TRUE(posts.empty());
}
