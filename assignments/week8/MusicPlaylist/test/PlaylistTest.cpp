#include "Playlist.h"
#include "Song.h"
#include <gtest/gtest.h>

class PlaylistTest : public ::testing::Test
{
    protected:
        Playlist playlist{"MyPlaylist"};
        ISong* song1 = new Song("1", "Song One", "file1.wav");
        ISong* song2 = new Song("2", "Song Two", "file2.wav");
        ISong* song3 = new Song("3", "Song Three", "file3.wav");

        void TearDown() override 
        {
            delete song1;
            delete song2;
            delete song3;
        }
};

TEST_F(PlaylistTest, AddSongReturnsTrueForValidSong) {
    EXPECT_TRUE(playlist.addSong(song1));
}

TEST_F(PlaylistTest, AddSongReturnsFalseForNullptr) {
    EXPECT_FALSE(playlist.addSong(nullptr));
}

TEST_F(PlaylistTest, GetCurrentSongReturnsFirstAdded) {
    playlist.addSong(song1);
    EXPECT_EQ(playlist.getCurrentSong(), song1);
}

TEST_F(PlaylistTest, RemoveSongReturnsTrueForValidIndex) {
    playlist.addSong(song1);
    EXPECT_TRUE(playlist.removeSong(0));
}

TEST_F(PlaylistTest, RemoveSongReturnsFalseForInvalidIndex) {
    EXPECT_FALSE(playlist.removeSong(5));
}

TEST_F(PlaylistTest, NextReturnsTrueIfNextExists) {
    playlist.addSong(song1);
    playlist.addSong(song2);
    EXPECT_TRUE(playlist.next());
    EXPECT_EQ(playlist.getCurrentSong(), song2);
}

TEST_F(PlaylistTest, NextReturnsFalseIfAtEnd) {
    playlist.addSong(song1);
    EXPECT_FALSE(playlist.next());
}

TEST_F(PlaylistTest, PreviousReturnsTrueIfPreviousExists) {
    playlist.addSong(song1);
    playlist.addSong(song2);
    playlist.next();
    EXPECT_TRUE(playlist.previous());
    EXPECT_EQ(playlist.getCurrentSong(), song1);
}

TEST_F(PlaylistTest, MoveSongReturnsTrueForValidIndices) {
    playlist.addSong(song1);
    playlist.addSong(song2);
    playlist.addSong(song3);
    EXPECT_TRUE(playlist.moveSong(0, 2));
}

TEST_F(PlaylistTest, MoveSongReturnsFalseForInvalidIndices) {
    playlist.addSong(song1);
    EXPECT_FALSE(playlist.moveSong(0, 5));
}

TEST_F(PlaylistTest, ResetReturnsTrueWhenSongsExist) {
    playlist.addSong(song1);
    playlist.addSong(song2);
    playlist.next();
    EXPECT_TRUE(playlist.reset());
    EXPECT_EQ(playlist.getCurrentSong(), song1);
}

TEST_F(PlaylistTest, ResetReturnsFalseWhenEmpty) {
    EXPECT_FALSE(playlist.reset());
}

TEST_F(PlaylistTest, GetAllSongsReturnsCorrectSize) {
    playlist.addSong(song1);
    playlist.addSong(song2);
    EXPECT_EQ(playlist.getAllSongs().size(), 2);
}
