#include "MusicSystem.h"
#include "MockPlaybackEngine.h"
#include "MockPlaylistManager.h"
#include "MockSong.h"
#include <gtest/gtest.h>

class MusicSystemTest : public ::testing::Test 
{
    protected:
        MockPlaybackEngine* playback = new MockPlaybackEngine();
        MockPlaylistManager* manager = new MockPlaylistManager();
        MockSong* song1 = new MockSong();
        std::vector<ISong*> library{song1};
        MusicSystem system{playback, manager, library};

        void SetUp() override 
        {
            ON_CALL(*song1, getId()).WillByDefault(::testing::Return("1"));
            ON_CALL(*song1, getFilePath()).WillByDefault(::testing::Return("file.wav"));
        }

        void TearDown() override 
        {
            delete song1;
            delete playback;
            delete manager;
        }
};

TEST_F(MusicSystemTest, GetAllSongsTest) 
{
    EXPECT_EQ(system.getAllSongs().size(), 1);
    EXPECT_EQ(system.getAllSongs()[0], song1);
}

TEST_F(MusicSystemTest, CreatePlaylistDTest) 
{
    EXPECT_CALL(*manager, createPlaylist("Rock")).WillOnce(::testing::Return(true));
    EXPECT_TRUE(system.createPlaylist("Rock"));
}

TEST_F(MusicSystemTest, DeletePlaylistTest) 
{
    EXPECT_CALL(*manager, deletePlaylist("Rock")).WillOnce(::testing::Return(true));
    EXPECT_TRUE(system.deletePlaylist("Rock"));
}

TEST_F(MusicSystemTest, AddSongToPlaylistForNullPlaylistTest) 
{
    EXPECT_CALL(*manager, getPlaylist("Rock")).WillOnce(::testing::Return(nullptr));
    EXPECT_FALSE(system.addSongToPlaylist("Rock", song1));
}

TEST_F(MusicSystemTest, PlaySongTestForLibrary) 
{
    EXPECT_CALL(*playback, load("file.wav")).WillOnce(::testing::Return(true));
    EXPECT_CALL(*playback, play()).WillOnce(::testing::Return(true));
    EXPECT_TRUE(system.playSong(song1));
}

TEST_F(MusicSystemTest, PlayCallTest) 
{
    EXPECT_CALL(*playback, play()).WillOnce(::testing::Return(true));
    EXPECT_TRUE(system.play());
}

TEST_F(MusicSystemTest, PauseCallTest) 
{
    EXPECT_CALL(*playback, pause()).WillOnce(::testing::Return(true));
    EXPECT_TRUE(system.pause());
}

TEST_F(MusicSystemTest, StopCallTest) 
{
    EXPECT_CALL(*playback, stop()).WillOnce(::testing::Return(true));
    EXPECT_TRUE(system.stop());
}

TEST_F(MusicSystemTest, GetCurrentSongTest) 
{
    EXPECT_CALL(*playback, load("file.wav")).WillOnce(::testing::Return(true));
    EXPECT_CALL(*playback, play()).WillOnce(::testing::Return(true));
    system.playSong(song1);
    EXPECT_EQ(system.getCurrentSong(), song1);
}
