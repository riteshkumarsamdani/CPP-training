#include "PlaylistManager.h"
#include <gtest/gtest.h>

class PlaylistManagerTest : public ::testing::Test
{
    protected:
        PlaylistManager manager;
};

TEST_F(PlaylistManagerTest, CreateNewPlaylistTest)
{
    EXPECT_TRUE(manager.createPlaylist("Rock"));
}

TEST_F(PlaylistManagerTest, CreateDuplicatePlaylistTest)
{
    manager.createPlaylist("Jazz");
    EXPECT_FALSE(manager.createPlaylist("Jazz"));
}

TEST_F(PlaylistManagerTest, DeleteExistingPlaylistTest)
{
    manager.createPlaylist("Pop");
    EXPECT_TRUE(manager.deletePlaylist("Pop"));
}

TEST_F(PlaylistManagerTest, DeleteNonexistentPlaylistTest)
{
    EXPECT_FALSE(manager.deletePlaylist("Classical"));
}

TEST_F(PlaylistManagerTest, GetExistingPlaylistTest)
{
    manager.createPlaylist("HipHop");
    EXPECT_NE(manager.getPlaylist("HipHop"), nullptr);
}

TEST_F(PlaylistManagerTest, GetNonexistentPlaylistTest)
{
    EXPECT_EQ(manager.getPlaylist("Rock"), nullptr);
}

TEST_F(PlaylistManagerTest, AllPlaylistsContainsCreatedPlaylistTest)
{
    manager.createPlaylist("Rock");
    auto& all = manager.getAllPlaylists();
    EXPECT_NE(all.find("Rock"), all.end());
}
