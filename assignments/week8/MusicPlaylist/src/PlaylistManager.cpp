#include "PlaylistManager.h"

PlaylistManager::~PlaylistManager()
{
    for (auto& pair : playlists)
    {
        delete pair.second;
    }
    playlists.clear();
}

bool PlaylistManager::createPlaylist(const std::string& playlistName)
{
    bool created = true;
    if (playlists.find(playlistName) != playlists.end())
    {
        created = false;
    }
    playlists[playlistName] = new Playlist(playlistName);
    return created;
}

bool PlaylistManager::deletePlaylist(const std::string& name)
{
    bool isDeleted = false;
    auto it = playlists.find(name);
    if (it != playlists.end())
    {
        delete it->second;
        playlists.erase(it);
        isDeleted = true;
    }
    return isDeleted;
}

Playlist* PlaylistManager::getPlaylist(const std::string& name)
{
    auto it = playlists.find(name);
    return (it != playlists.end()) ? it->second : nullptr;
}

const std::map<std::string, Playlist*>& PlaylistManager::getAllPlaylists() const
{
    return playlists;
}

