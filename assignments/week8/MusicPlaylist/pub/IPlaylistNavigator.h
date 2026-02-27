#ifndef IPLAYLIST_NAVIGATOR_H
#define IPLAYLIST_NAVIGATOR_H

#include "ISong.h"
#include <list>

class IPlaylistNavigator
{
    public:
        virtual ~IPlaylistNavigator() = default;
        virtual bool nextIterate() = 0;
        virtual bool previousIterate() = 0;
        virtual ISong* getCurrentSong() = 0;
        virtual bool moveSong(int fromIndex, int toIndex) = 0;
        virtual bool resetIterator() = 0;
        virtual const std::string& getPlaylistName() const = 0;
        virtual bool addSong(ISong* song) = 0;
        virtual bool removeSong(int index) = 0;
        virtual const std::list<ISong*>& getAllSongs() const = 0;
};

#endif
