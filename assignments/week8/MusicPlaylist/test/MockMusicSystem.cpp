#include "MusicSystem.h"
#include "MockPlaybackEngine.h"
#include "MockPlaylistManager.h"
#include "MockSong.h"
#include "MockPlaylistNavigator.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class MusicSystemTest : public ::testing::Test
{
    protected:
        MockPlaybackEngine* playback = new MockPlaybackEngine();
        MockPlaylistManager* manager = new MockPlaylistManager();
        MockSong* song1 = new MockSong();
        MockPlaylistNavigator* playlist = new MockPlaylistNavigator();
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
            delete playlist;
        }
};

TEST_F(MusicSystemTest, GetAllSongsSizeTest) 
{
    EXPECT_EQ(system.getAllSongs().size(), 1);
}

TEST_F(MusicSystemTest, GetAllSongsTest) 
{
    EXPECT_EQ(system.getAllSongs()[0], song1);
}

TEST_F(MusicSystemTest, CreatePlaylistTest)
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

TEST_F(MusicSystemTest, AddSongToPlaylistTest)
{
    std::list<ISong*> songs = {};
    EXPECT_CALL(*manager, getPlaylist("Rock")).WillOnce(::testing::Return(playlist));
    EXPECT_CALL(*playlist, getAllSongs()).WillOnce(::testing::ReturnRef(songs));
    EXPECT_CALL(*playlist, addSong(song1)).WillOnce(::testing::Return(true));
    EXPECT_TRUE(system.addSongToPlaylist("Rock", song1));
}

TEST_F(MusicSystemTest, AddSongToPlaylistForDuplicateTest)
{
    std::list<ISong*> songs{song1};
    EXPECT_CALL(*manager, getPlaylist("Rock")).WillOnce(::testing::Return(playlist));
    EXPECT_CALL(*playlist, getAllSongs()).WillOnce(::testing::ReturnRef(songs));
    EXPECT_FALSE(system.addSongToPlaylist("Rock", song1));
}

TEST_F(MusicSystemTest, RemoveSongFromPlaylistTest)
{
    EXPECT_CALL(*manager, getPlaylist("Rock")).WillOnce(::testing::Return(playlist));
    EXPECT_CALL(*playlist, removeSong(0)).WillOnce(::testing::Return(true));
    EXPECT_TRUE(system.removeSongFromPlaylist("Rock", 0));
}

TEST_F(MusicSystemTest, RemoveSongFromInvalidPlaylistTest)
{
    EXPECT_CALL(*manager, getPlaylist("Rock")).WillOnce(::testing::Return(nullptr));
    EXPECT_FALSE(system.removeSongFromPlaylist("Rock", 0));
}

TEST_F(MusicSystemTest, MoveSongToPositionTest)
{
    EXPECT_CALL(*manager, getPlaylist("Rock")).WillOnce(::testing::Return(playlist));
    EXPECT_CALL(*playlist, moveSong(0, 1)).WillOnce(::testing::Return(true));
    EXPECT_TRUE(system.moveSongToPosition("Rock", 0, 1));
}

TEST_F(MusicSystemTest, MoveSongToPositionForInavlidPlaylistTest)
{
    EXPECT_CALL(*manager, getPlaylist("Rock")).WillOnce(::testing::Return(nullptr));
    EXPECT_FALSE(system.moveSongToPosition("Rock", 0, 1));
}

TEST_F(MusicSystemTest, SelectPlaylistTest)
{
    std::list<ISong*> songs{song1};
    EXPECT_CALL(*manager, getPlaylist("Rock")).WillOnce(::testing::Return(playlist));
    EXPECT_CALL(*playlist, getAllSongs()).WillOnce(::testing::ReturnRef(songs));
    EXPECT_CALL(*playlist, resetIterator()).WillOnce(::testing::Return(true));
    EXPECT_CALL(*playlist, getCurrentSong()).WillOnce(::testing::Return(song1));
    EXPECT_CALL(*playback, load("file.wav")).WillOnce(::testing::Return(true));
    EXPECT_CALL(*playback, play()).Times(1);
    EXPECT_TRUE(system.selectPlaylist("Rock", 0));
}

TEST_F(MusicSystemTest, SelectPlaylistForInvalidIndexTest)
{
    std::list<ISong*> songs{song1};
    EXPECT_CALL(*manager, getPlaylist("Rock")).WillOnce(::testing::Return(playlist));
    EXPECT_CALL(*playlist, getAllSongs()).WillOnce(::testing::ReturnRef(songs));
    EXPECT_FALSE(system.selectPlaylist("Rock", 5));
}

TEST_F(MusicSystemTest, PlaySongForValidLibrarySongTest)
{
    EXPECT_CALL(*playback, load("file.wav")).WillOnce(::testing::Return(true));
    EXPECT_CALL(*playback, play());
    EXPECT_TRUE(system.playSong(song1));
}

TEST_F(MusicSystemTest, PlaySongTest)
{
    EXPECT_CALL(*playback, isPlaying()).WillOnce(::testing::Return(false));
    EXPECT_CALL(*playback, play());
    EXPECT_TRUE(system.playSong());
}

TEST_F(MusicSystemTest, PlaySongForAlreadyPlayingTest)
{
    EXPECT_CALL(*playback, isPlaying()).WillOnce(::testing::Return(true));
    EXPECT_FALSE(system.playSong());
}

TEST_F(MusicSystemTest, PauseSongIfPlayingTest)
{
    EXPECT_CALL(*playback, isPlaying()).WillOnce(::testing::Return(true));
    EXPECT_CALL(*playback, pause());
    EXPECT_TRUE(system.pauseSong());
}

TEST_F(MusicSystemTest, PauseSongIfNotPlayingTest)
{
    EXPECT_CALL(*playback, isPlaying()).WillOnce(::testing::Return(false));
    EXPECT_FALSE(system.pauseSong());
}

TEST_F(MusicSystemTest, StopSongIfPlayingTest)
{
    EXPECT_CALL(*playback, isPlaying()).WillOnce(::testing::Return(true));
    EXPECT_CALL(*playback, stop());
    EXPECT_TRUE(system.stopSong());
}

TEST_F(MusicSystemTest, StopSongIfNotPlayingTest)
{
    EXPECT_CALL(*playback, isPlaying()).WillOnce(::testing::Return(false));
    EXPECT_FALSE(system.stopSong());
}

TEST_F(MusicSystemTest, PlayNextSongForLibraryModeTest)
{
    EXPECT_CALL(*playback, load("file.wav")).WillOnce(::testing::Return(true));
    EXPECT_CALL(*playback, play());
    system.playSong(song1);
    EXPECT_FALSE(system.playNextSong());
}

TEST_F(MusicSystemTest, PlayPreviousAtStartTest)
{
    EXPECT_CALL(*playback, load("file.wav")).WillOnce(::testing::Return(true));
    EXPECT_CALL(*playback, play());
    system.playSong(song1);
    EXPECT_FALSE(system.playPreviousSong());
}
