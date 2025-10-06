#include "Song.h"
#include <gtest/gtest.h>

class SongTest : public ::testing::Test
{
    protected:
        Song song{"001", "blues.00000", "Music/blues.00000.wav"};
};

TEST_F(SongTest, GetIdTest)
{
    EXPECT_EQ(song.getId(), "001");
}

TEST_F(SongTest, GetTitleTest)
{
    EXPECT_EQ(song.getTitle(), "blues.00000");
}

TEST_F(SongTest, GetFilePathTest)
{
    EXPECT_EQ(song.getFilePath(), "Music/blues.00000.wav");
}
