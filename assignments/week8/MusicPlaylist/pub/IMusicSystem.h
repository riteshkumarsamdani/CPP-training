#ifndef IMUSICSYSTEM_H
#define IMUSICSYSTEM_H

#include "IPlaybackEngine.h"
#include "IPlaylistManager.h"
#include "ISong.h"
#include <vector>
#include <string>

class IMusicSystem {
public:
    virtual ~IMusicSystem() = default;
    virtual const std::vector<ISong*>& getAllSongs() const = 0;
    virtual bool createPlaylist(const std::string& name) = 0;
    virtual bool deletePlaylist(const std::string& name) = 0;
    virtual bool addSongToPlaylist(const std::string& playlistName, ISong* song) = 0;
    virtual bool removeSongFromPlaylist(const std::string& playlistName, int index) = 0;
    virtual bool moveSongToPosition(const std::string& playlistName, int fromIndex, int toIndex) = 0;
    virtual Playlist* getPlaylist(const std::string& name) = 0;
    virtual const std::map<std::string, Playlist*>& getAllPlaylists() const = 0;
    virtual bool selectPlaylist(const std::string& name, int startIndex) = 0;
    virtual bool playSong(ISong* song) = 0;
    virtual bool play() = 0;
    virtual bool pause() = 0;
    virtual bool stop() = 0;
    virtual bool next() = 0;
    virtual bool previous() = 0;
    virtual bool reset() = 0;
    virtual ISong* getCurrentSong() const = 0;

};

#endif
