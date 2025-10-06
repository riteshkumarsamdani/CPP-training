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
        explicit Playlist(const std::string& name);
        const std::string& getName() const;
        bool addSong(ISong* song);
        bool removeSong(size_t index);
        ISong* getSongAt(int index) const;
        ISong* getCurrentSong() override;
        bool next() override;
        bool previous() override;
        bool moveSong(int fromIndex, int toIndex) override;
        const std::list<ISong*>& getAllSongs() const;
        bool reset() override;
};

#endif
