#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "IPlaylistNavigator.h"
#include "Song.h"
#include <list>
#include <string>

class Playlist : public IPlaylistNavigator 
{
    private:
        std::string name;
        std::list<ISong*> songs;
        std::list<ISong*>::iterator currentIterator;

    public:
        Playlist(const std::string& name);
        const std::string& getPlaylistName() const override;
        bool addSong(ISong* song) override;
        bool removeSong(int index) override;
        ISong* getCurrentSong() override;
        bool nextIterate() override;
        bool previousIterate() override;
        bool moveSong(int fromIndex, int toIndex) override;
        const std::list<ISong*>& getAllSongs() const override;
        bool resetIterator() override;
};

#endif
