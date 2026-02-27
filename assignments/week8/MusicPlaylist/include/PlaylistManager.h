#ifndef PLAYLIST_MANAGER_H
#define PLAYLIST_MANAGER_H
#include "IPlaylistManager.h"

class PlaylistManager : public IPlaylistManager
{
    private:
        std::map<std::string, IPlaylistNavigator*> playlists;
    
    public:
        ~PlaylistManager();
        bool createPlaylist(const std::string& name) override;
        bool deletePlaylist(const std::string& name) override;
        IPlaylistNavigator* getPlaylist(const std::string& name) override;
        const std::map<std::string, IPlaylistNavigator*>& getAllPlaylists() const override;    
};

#endif
