#ifndef IPLAYLIST_MANAGER_H
#define IPLAYLIST_MANAGER_H

#include "Playlist.h"
#include <string>
#include <map>

class IPlaylistManager
{
    public:
        virtual ~IPlaylistManager() = default;
        virtual bool createPlaylist(const std::string& name) = 0;
        virtual bool deletePlaylist(const std::string& name) = 0;
        virtual IPlaylistNavigator* getPlaylist(const std::string& name) = 0;
        virtual const std::map<std::string, IPlaylistNavigator*>& getAllPlaylists() const = 0;
};

#endif
