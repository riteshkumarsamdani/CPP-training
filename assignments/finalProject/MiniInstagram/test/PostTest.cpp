#include <gtest/gtest.h>
#include "Post.h"

class PostTest : public ::testing::Test
{
    protected:
        std::string userId = "U12345";
        std::string content = "Hello, world!";
        std::string postId = "P98765";
        std::string timestamp = "2025-11-07 10:00:00";
        std::vector<std::string> likedUsers = {"alice", "bob"};
};

TEST_F(PostTest, GivenUserIdAndContent_WhenPostIsCreated_ThenPostIdIsGenerated)
{
    Post post(userId, content);
    std::string id = post.getPostId();
    EXPECT_FALSE(id.empty());
    EXPECT_TRUE(id[0] == 'P');
}

TEST_F(PostTest, GivenUserIdAndContent_WhenPostIsCreated_ThenTimestampIsGenerated)
{
    Post post(userId, content);
    std::string ts = post.getTimestamp();
    EXPECT_FALSE(ts.empty());
}

TEST_F(PostTest, GivenUserIdAndContent_WhenPostIsCreated_ThenUserIdIsStoredCorrectly)
{
    Post post(userId, content);
    std::string result = post.getUserId();
    EXPECT_EQ(result, userId);
}

TEST_F(PostTest, GivenUserIdAndContent_WhenPostIsCreated_ThenContentIsStoredCorrectly)
{
    Post post(userId, content);
    std::string result = post.getContent();
    EXPECT_EQ(result, content);
}

TEST_F(PostTest, GivenFullPostDetails_WhenPostIsConstructed_ThenPostIdIsPreserved)
{
    Post post(postId, userId, content, timestamp, likedUsers);
    std::string result = post.getPostId();
    EXPECT_EQ(result, postId);
}

TEST_F(PostTest, GivenFullPostDetails_WhenPostIsConstructed_ThenTimestampIsPreserved)
{
    Post post(postId, userId, content, timestamp, likedUsers);
    std::string result = post.getTimestamp();
    EXPECT_EQ(result, timestamp);
}

TEST_F(PostTest, GivenFullPostDetails_WhenPostIsConstructed_ThenLikedUsersArePreserved)
{
    Post post(postId, userId, content, timestamp, likedUsers);
    std::vector<std::string> result = post.getLikedByUsers();
    ASSERT_EQ(result.size(), likedUsers.size());
    EXPECT_EQ(result[0], "alice");
    EXPECT_EQ(result[1], "bob");
}

TEST_F(PostTest, GivenUserNotInLikes_WhenAddLikeIsCalled_ThenUserIsAdded)
{
    Post post(userId, content);
    bool added = post.addLike("charlie");
    std::vector<std::string> result = post.getLikedByUsers();
    int count = post.getLikeCount();
    EXPECT_TRUE(added);
    EXPECT_EQ(count, 1);
    EXPECT_EQ(result[0], "charlie");
}

TEST_F(PostTest, GivenUserAlreadyLiked_WhenAddLikeIsCalled_ThenUserIsNotAddedAgain)
{
    Post post(postId, userId, content, timestamp, likedUsers);
    bool added = post.addLike("alice");
    int count = post.getLikeCount();
    EXPECT_FALSE(added);
    EXPECT_EQ(count, 2);
}

TEST_F(PostTest, GivenUserInLikes_WhenRemoveLikeIsCalled_ThenUserIsRemoved)
{
    Post post(postId, userId, content, timestamp, likedUsers);
    bool removed = post.removeLike("alice");
    std::vector<std::string> result = post.getLikedByUsers();
    int count = post.getLikeCount();
    EXPECT_TRUE(removed);
    EXPECT_EQ(count, 1);
    EXPECT_EQ(result[0], "bob");
}

TEST_F(PostTest, GivenUserNotInLikes_WhenRemoveLikeIsCalled_ThenNothingIsRemoved)
{
    Post post(postId, userId, content, timestamp, likedUsers);
    bool removed = post.removeLike("charlie");
    int count = post.getLikeCount();
    EXPECT_FALSE(removed);
    EXPECT_EQ(count, 2);
}

TEST_F(PostTest, GivenPostWithLikes_WhenGetLikeCountIsCalled_ThenCorrectCountIsReturned)
{
    Post post(postId, userId, content, timestamp, likedUsers);
    int count = post.getLikeCount();
    EXPECT_EQ(count, 2);
}

TEST_F(PostTest, GivenPostWithoutLikes_WhenGetLikeCountIsCalled_ThenZeroIsReturned)
{
    Post post(userId, content);
    int count = post.getLikeCount();
    EXPECT_EQ(count, 0);
}
