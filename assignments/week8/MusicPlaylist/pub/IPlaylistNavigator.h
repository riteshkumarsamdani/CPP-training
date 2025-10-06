#ifndef IPLAYLIST_NAVIGATOR_H
#define IPLAYLIST_NAVIGATOR_H

#include "ISong.h"

class IPlaylistNavigator
{
    public:
        virtual ~IPlaylistNavigator() = default;
        virtual bool next() = 0;
        virtual bool previous() = 0;
        virtual ISong* getCurrentSong() = 0;
        virtual bool moveSong(int fromIndex, int toIndex) = 0;
        virtual bool reset() = 0;
};

#endif
