#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "PostManager.h"
#include "Post.h"

class MockPost : public IPost
{
    public:
        MOCK_METHOD(std::string, getPostId, (), (const, override));
        MOCK_METHOD(std::string, getUserId, (), (const, override));
        MOCK_METHOD(std::string, getContent, (), (const, override));
        MOCK_METHOD(std::string, getTimestamp, (), (const, override));
        MOCK_METHOD(std::vector<std::string>, getLikedByUsers, (), (const, override));
        MOCK_METHOD(bool, addLike, (std::string), (override));
        MOCK_METHOD(bool, removeLike, (std::string), (override));
        MOCK_METHOD(int, getLikeCount, (), (const, override));
};

class PostManagerTest : public ::testing::Test
{
    protected:
        std::string userId = "U1";
        std::string otherUserId = "U2";
        std::string content = "Test post";
        std::string postId = "P123";
};

TEST_F(PostManagerTest, GivenValidContent_WhenCreatePostIsCalled_ThenReturnsSuccess)
{
    std::vector<IPost*> posts;
    PostManager manager(posts);
    PostResult result = manager.createPost(userId, content);
    EXPECT_TRUE(result.success);
    EXPECT_EQ(result.error, PostError::None);
}

TEST_F(PostManagerTest, GivenEmptyContent_WhenCreatePostIsCalled_ThenReturnsEmptyContentError)
{
    std::vector<IPost*> posts;
    PostManager manager(posts);
    PostResult result = manager.createPost(userId, "");
    EXPECT_FALSE(result.success);
    EXPECT_EQ(result.error, PostError::EmptyContent);
}

TEST_F(PostManagerTest, GivenOwnedPost_WhenDeletePostIsCalled_ThenReturnsSuccess)
{
    auto* post = new MockPost();
    EXPECT_CALL(*post, getPostId()).WillRepeatedly(testing::Return(postId));
    EXPECT_CALL(*post, getUserId()).WillRepeatedly(testing::Return(userId));
    std::vector<IPost*> posts = {post};
    PostManager manager(posts);
    PostResult result = manager.deletePost(postId, userId);
    EXPECT_TRUE(result.success);
    EXPECT_EQ(result.error, PostError::None);
}

TEST_F(PostManagerTest, GivenUnownedPost_WhenDeletePostIsCalled_ThenReturnsUnauthorizedError)
{
    auto* post = new MockPost();
    EXPECT_CALL(*post, getPostId()).WillRepeatedly(testing::Return(postId));
    EXPECT_CALL(*post, getUserId()).WillRepeatedly(testing::Return(userId));
    std::vector<IPost*> posts = {post};
    PostManager manager(posts);
    PostResult result = manager.deletePost(postId, otherUserId);
    EXPECT_FALSE(result.success);
    EXPECT_EQ(result.error, PostError::Unauthorized);
}

TEST_F(PostManagerTest, GivenNonexistentPost_WhenDeletePostIsCalled_ThenReturnsNotFoundError)
{
    std::vector<IPost*> posts;
    PostManager manager(posts);
    PostResult result = manager.deletePost("invalid", userId);
    EXPECT_FALSE(result.success);
    EXPECT_EQ(result.error, PostError::NotFound);
}

TEST_F(PostManagerTest, GivenMultiplePostsByUser_WhenDeletePostsByUserIsCalled_ThenReturnsCorrectCount)
{
    auto* post1 = new MockPost();
    auto* post2 = new MockPost();
    auto* post3 = new MockPost();
    EXPECT_CALL(*post1, getUserId()).WillOnce(testing::Return(userId));
    EXPECT_CALL(*post2, getUserId()).WillOnce(testing::Return(userId));
    EXPECT_CALL(*post3, getUserId()).WillOnce(testing::Return(otherUserId));
    std::vector<IPost*> posts = {post1, post2, post3};
    PostManager manager(posts);
    int count = manager.deletePostsByUser(userId);
    EXPECT_EQ(count, 2);
}

TEST_F(PostManagerTest, GivenPosts_WhenGetAllPostsIsCalled_ThenReturnsAllPosts)
{
    auto* post1 = new MockPost();
    auto* post2 = new MockPost();
    std::vector<IPost*> posts = {post1, post2};
    PostManager manager(posts);
    std::vector<IPost*> result = manager.getAllPosts();
    EXPECT_EQ(result.size(), 2);
}

TEST_F(PostManagerTest, GivenPostsByUser_WhenGetPostsByUserIsCalled_ThenReturnsFilteredPosts)
{
    auto* post1 = new MockPost();
    auto* post2 = new MockPost();
    EXPECT_CALL(*post1, getUserId()).WillRepeatedly(testing::Return(userId));
    EXPECT_CALL(*post2, getUserId()).WillRepeatedly(testing::Return(otherUserId));
    std::vector<IPost*> posts = {post1, post2};
    PostManager manager(posts);
    std::vector<IPost*> result = manager.getPostsByUser(userId);
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0]->getUserId(), userId);
}

TEST_F(PostManagerTest, GivenPost_WhenLikePostIsCalled_ThenReturnsSuccess)
{
    auto* post = new MockPost();
    EXPECT_CALL(*post, getPostId()).WillRepeatedly(testing::Return(postId));
    EXPECT_CALL(*post, addLike("alice")).WillOnce(testing::Return(true));
    std::vector<IPost*> posts = {post};
    PostManager manager(posts);
    PostResult result = manager.likePost(postId, "alice");
    EXPECT_TRUE(result.success);
    EXPECT_EQ(result.error, PostError::None);
}

TEST_F(PostManagerTest, GivenAlreadyLikedPost_WhenLikePostIsCalled_ThenReturnsAlreadyLikedError)
{
    auto* post = new MockPost();
    EXPECT_CALL(*post, getPostId()).WillRepeatedly(testing::Return(postId));
    EXPECT_CALL(*post, addLike("alice")).WillOnce(testing::Return(false));
    std::vector<IPost*> posts = {post};
    PostManager manager(posts);
    PostResult result = manager.likePost(postId, "alice");
    EXPECT_FALSE(result.success);
    EXPECT_EQ(result.error, PostError::AlreadyLiked);
}

TEST_F(PostManagerTest, GivenLikedPost_WhenUnlikePostIsCalled_ThenReturnsSuccess)
{
    auto* post = new MockPost();
    EXPECT_CALL(*post, getPostId()).WillRepeatedly(testing::Return(postId));
    EXPECT_CALL(*post, removeLike("alice")).WillOnce(testing::Return(true));
    std::vector<IPost*> posts = {post};
    PostManager manager(posts);
    PostResult result = manager.unlikePost(postId, "alice");
    EXPECT_TRUE(result.success);
    EXPECT_EQ(result.error, PostError::None);
}

TEST_F(PostManagerTest, GivenUnlikedPost_WhenUnlikePostIsCalled_ThenReturnsNotLikedError)
{
    auto* post = new MockPost();
    EXPECT_CALL(*post, getPostId()).WillRepeatedly(testing::Return(postId));
    EXPECT_CALL(*post, removeLike("alice")).WillOnce(testing::Return(false));
    std::vector<IPost*> posts = {post};
    PostManager manager(posts);
    PostResult result = manager.unlikePost(postId, "alice");
    EXPECT_FALSE(result.success);
    EXPECT_EQ(result.error, PostError::NotLiked);
}

TEST_F(PostManagerTest, GivenPost_WhenGetLikeCountIsCalled_ThenReturnsCorrectCount)
{
    auto* post = new MockPost();
    EXPECT_CALL(*post, getPostId()).WillRepeatedly(testing::Return(postId));
    EXPECT_CALL(*post, getLikeCount()).WillOnce(testing::Return(3));
    std::vector<IPost*> posts = {post};
    PostManager manager(posts);
    int count = manager.getPostLikeCount(postId);
    EXPECT_EQ(count, 3);
}

TEST_F(PostManagerTest, GivenPost_WhenGetUsersWhoLikedIsCalled_ThenReturnsUserList)
{
    auto* post = new MockPost();
    EXPECT_CALL(*post, getPostId()).WillRepeatedly(testing::Return(postId));
    EXPECT_CALL(*post, getLikedByUsers()).WillOnce(testing::Return(std::vector<std::string>{"alice", "bob"}));
    std::vector<IPost*> posts = {post};
    PostManager manager(posts);
    std::vector<std::string> users = manager.getUsersWhoLiked(postId);
    EXPECT_EQ(users.size(), 2);
    EXPECT_EQ(users[0], "alice");
    EXPECT_EQ(users[1], "bob");
}

TEST_F(PostManagerTest, GivenNonexistentPost_WhenGetUsersWhoLikedIsCalled_ThenReturnsEmptyList)
{
    std::vector<IPost*> posts;
    PostManager manager(posts);
    std::vector<std::string> users = manager.getUsersWhoLiked("invalid");
    EXPECT_TRUE(users.empty());
}

TEST_F(PostManagerTest, GivenExistingPost_WhenGetPostByIdIsCalled_ThenReturnsPost)
{
    auto* post = new MockPost();
    EXPECT_CALL(*post, getPostId()).WillRepeatedly(testing::Return(postId));
    std::vector<IPost*> posts = {post};
    PostManager manager(posts);
    IPost* result = manager.getPostById(postId);
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->getPostId(), postId);
}

TEST_F(PostManagerTest, GivenNonexistentPost_WhenGetPostByIdIsCalled_ThenReturnsNullptr)
{
    std::vector<IPost*> posts;
    PostManager manager(posts);
    IPost* result = manager.getPostById("nonexistent");
    EXPECT_EQ(result, nullptr);
}

TEST_F(PostManagerTest, GivenNonexistentPost_WhenUnlikePostIsCalled_ThenReturnsNotFoundError)
{
    std::vector<IPost*> posts;
    PostManager manager(posts);
    PostResult result = manager.unlikePost("invalid", "alice");
    EXPECT_FALSE(result.success);
    EXPECT_EQ(result.error, PostError::NotFound);
}

TEST_F(PostManagerTest, GivenNonexistentPost_WhenLikePostIsCalled_ThenReturnsNotFoundError)
{
    std::vector<IPost*> posts;
    PostManager manager(posts);
    PostResult result = manager.likePost("invalid", "alice");
    EXPECT_FALSE(result.success);
    EXPECT_EQ(result.error, PostError::NotFound);
}

TEST_F(PostManagerTest, GivenValidContent_WhenCreatePostIsCalled_ThenPostIsAddedToList)
{
    std::vector<IPost*> posts;
    PostManager manager(posts);
    manager.createPost(userId, content);
    std::vector<IPost*> result = manager.getAllPosts();
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0]->getUserId(), userId);
    EXPECT_EQ(result[0]->getContent(), content);
}
