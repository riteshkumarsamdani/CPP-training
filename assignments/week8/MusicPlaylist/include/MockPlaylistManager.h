#ifndef MOCK_PLAYLIST_MANAGER_H
#define MOCK_PLAYLIST_MANAGER_H

#include <gmock/gmock.h>
#include "IPlaylistManager.h"

class MockPlaylistManager : public IPlaylistManager 
{
    public:
        MOCK_METHOD(bool, createPlaylist, (const std::string&), (override));
        MOCK_METHOD(bool, deletePlaylist, (const std::string&), (override));
        MOCK_METHOD(IPlaylistNavigator*, getPlaylist, (const std::string&), (override));
        MOCK_METHOD((const std::map<std::string, IPlaylistNavigator*>&), getAllPlaylists, (), (const, override));
};

#endif
