#include "Playlist.h"
#include "MockSong.h"
#include <gtest/gtest.h>

class PlaylistTest : public ::testing::Test
{
    protected:
        Playlist playlist{"MyPlaylist"};
        MockSong* song1 = new MockSong();
        MockSong* song2 = new MockSong();
        MockSong* song3 = new MockSong();

        void TearDown() override {
            delete song1;
            delete song2;
            delete song3;
        }
};

TEST_F(PlaylistTest, AddSongForValidSongTest)
{
    EXPECT_TRUE(playlist.addSong(song1));
}

TEST_F(PlaylistTest, AddSongForInvalidSongTest)
{
    EXPECT_FALSE(playlist.addSong(nullptr));
}

TEST_F(PlaylistTest, GetCurrentSongTest)
{
    playlist.addSong(song1);
    EXPECT_EQ(playlist.getCurrentSong(), song1);
}

TEST_F(PlaylistTest, RemoveSongForValidIndexTest)
{
    playlist.addSong(song1);
    EXPECT_TRUE(playlist.removeSong(0));
}

TEST_F(PlaylistTest, RemoveSongForInvalidIndextest)
{
    EXPECT_FALSE(playlist.removeSong(5));
}

TEST_F(PlaylistTest, NextValidTest)
{
    playlist.addSong(song1);
    playlist.addSong(song2);
    ASSERT_TRUE(playlist.nextIterate());
    EXPECT_EQ(playlist.getCurrentSong(), song2);
}

TEST_F(PlaylistTest, NextForInvalidIndexTest)
{
    playlist.addSong(song1);
    EXPECT_FALSE(playlist.nextIterate());
}

TEST_F(PlaylistTest, PreviousIterateForValidIndexTest)
{
    playlist.addSong(song1);
    playlist.addSong(song2);
    playlist.nextIterate();
    ASSERT_TRUE(playlist.previousIterate());
    EXPECT_EQ(playlist.getCurrentSong(), song1);
}

TEST_F(PlaylistTest, MoveSongForValidIndexTest)
{
    playlist.addSong(song1);
    playlist.addSong(song2);
    playlist.addSong(song3);
    EXPECT_TRUE(playlist.moveSong(0, 2));
}

TEST_F(PlaylistTest, MoveSongForInvalidIndexTest)
{
    playlist.addSong(song1);
    EXPECT_FALSE(playlist.moveSong(0, 5));
}

TEST_F(PlaylistTest, ResetPlaylistTest)
{
    playlist.addSong(song1);
    playlist.addSong(song2);
    playlist.nextIterate();
    ASSERT_TRUE(playlist.resetIterator());
    EXPECT_EQ(playlist.getCurrentSong(), song1);
}

TEST_F(PlaylistTest, ResetForEmptyPlaylistTest)
{
    EXPECT_FALSE(playlist.resetIterator());
}

TEST_F(PlaylistTest, GetAllSongsSizeTest)
{
    playlist.addSong(song1);
    playlist.addSong(song2);
    EXPECT_EQ(playlist.getAllSongs().size(), 2);
}
