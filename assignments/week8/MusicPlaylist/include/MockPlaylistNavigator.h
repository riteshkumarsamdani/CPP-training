#ifndef MOCK_PLAYLIST_NAVIGATOR_H
#define MOCK_PLAYLIST_NAVIGATOR_H

#include <gmock/gmock.h>
#include "IPlaylistNavigator.h"

class MockPlaylistNavigator : public IPlaylistNavigator 
{
    public:
        MOCK_METHOD(bool, nextIterate, (), (override));
        MOCK_METHOD(bool, previousIterate, (), (override));
        MOCK_METHOD(ISong*, getCurrentSong, (), (override));
        MOCK_METHOD(bool, moveSong, (int, int), (override));
        MOCK_METHOD(bool, resetIterator, (), (override));
        MOCK_METHOD(const std::string&, getPlaylistName, (), (const, override));
        MOCK_METHOD(bool, addSong, (ISong*), (override));
        MOCK_METHOD(bool, removeSong, (int), (override));
        MOCK_METHOD(const std::list<ISong*>&, getAllSongs, (), (const, override));
};

#endif
