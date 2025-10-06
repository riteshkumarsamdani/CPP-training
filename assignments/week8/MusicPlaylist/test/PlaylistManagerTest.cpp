#include "Playlist.h"
#include "MockSong.h"
#include <gtest/gtest.h>

class PlaylistTest : public ::testing::Test 
{
    protected:
        Playlist playlist{"MockPlaylist"};
        MockSong* song1 = new MockSong();
        MockSong* song2 = new MockSong();
        MockSong* song3 = new MockSong();

        void SetUp() override 
        {
            ON_CALL(*song1, getId()).WillByDefault(::testing::Return("1"));
            ON_CALL(*song2, getId()).WillByDefault(::testing::Return("2"));
            ON_CALL(*song3, getId()).WillByDefault(::testing::Return("3"));
        }

        void TearDown() override 
        {
            delete song1;
            delete song2;
            delete song3;
        }
};

TEST_F(PlaylistTest, GetNameTest) 
{
    EXPECT_EQ(playlist.getName(), "MockPlaylist");
}

TEST_F(PlaylistTest, AddSongTest) 
{
    EXPECT_TRUE(playlist.addSong(song1));
}

TEST_F(PlaylistTest, AddSongForNullptrTest) 
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

TEST_F(PlaylistTest, RemoveSongForInvalidTest) 
{
    EXPECT_FALSE(playlist.removeSong(5));
}

TEST_F(PlaylistTest, NextTest) 
{
    playlist.addSong(song1);
    playlist.addSong(song2);
    EXPECT_TRUE(playlist.next());
    EXPECT_EQ(playlist.getCurrentSong(), song2);
}

TEST_F(PlaylistTest, NextAtEndTest) 
{
    playlist.addSong(song1);
    EXPECT_FALSE(playlist.next());
}

TEST_F(PlaylistTest, PreviousTest) 
{
    playlist.addSong(song1);
    playlist.addSong(song2);
    playlist.next();
    EXPECT_TRUE(playlist.previous());
    EXPECT_EQ(playlist.getCurrentSong(), song1);
}

TEST_F(PlaylistTest, MoveSongForValidTest) 
{
    playlist.addSong(song1);
    playlist.addSong(song2);
    playlist.addSong(song3);
    EXPECT_TRUE(playlist.moveSong(0, 2));
}

TEST_F(PlaylistTest, MoveSongForInvalidTest) 
{
    playlist.addSong(song1);
    EXPECT_FALSE(playlist.moveSong(0, 5));
}

TEST_F(PlaylistTest, ResetTest) 
{
    playlist.addSong(song1);
    playlist.addSong(song2);
    playlist.next();
    EXPECT_TRUE(playlist.reset());
    EXPECT_EQ(playlist.getCurrentSong(), song1);
}

TEST_F(PlaylistTest, ResetForEmptyTest) 
{
    EXPECT_FALSE(playlist.reset());
}

TEST_F(PlaylistTest, GetAllSongsTest) 
{
    playlist.addSong(song1);
    playlist.addSong(song2);
    EXPECT_EQ(playlist.getAllSongs().size(), 2);
}
