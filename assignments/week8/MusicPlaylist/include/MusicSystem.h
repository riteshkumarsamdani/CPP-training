#ifndef MUSICSYSTEM_H
#define MUSICSYSTEM_H

#include "IMusicSystem.h"

class MusicSystem : public IMusicSystem {
    private:
        IPlaybackEngine* playbackEngine;
        IPlaylistManager* playlistManager;
        std::vector<ISong*> songLibrary;
        Playlist* currentPlaylist;
        bool isLibraryMode = false;
        int currentLibraryIndex = -1;

    public:
        MusicSystem(IPlaybackEngine* engine, IPlaylistManager* manager, const std::vector<ISong*>& library);
        const std::vector<ISong*>& getAllSongs() const override;
        bool createPlaylist(const std::string& name) override;
        bool deletePlaylist(const std::string& name) override;
        bool addSongToPlaylist(const std::string& playlistName, ISong* song) override;
        bool removeSongFromPlaylist(const std::string& playlistName, int index) override;
        bool moveSongToPosition(const std::string& playlistName, int fromIndex, int toIndex) override;
        Playlist* getPlaylist(const std::string& name) override;
        const std::map<std::string, Playlist*>& getAllPlaylists() const override;
        bool playSong(ISong* song) override;
        bool selectPlaylist(const std::string& name, int startIndex) override;
        bool play() override;
        bool pause() override;
        bool stop() override;
        bool next() override;
        bool previous() override;
        bool reset() override;
        ISong* getCurrentSong() const override;
};

#endif
