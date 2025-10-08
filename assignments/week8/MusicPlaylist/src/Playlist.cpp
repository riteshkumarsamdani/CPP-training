#include "Playlist.h"
#include <iostream>

Playlist::Playlist(const std::string& name) : name(name)
{
    currentIterator = songs.end();
}

const std::string& Playlist::getPlaylistName() const
{
    return name;
}

bool Playlist::addSong(ISong* song)
{
    bool isSongAdded = false;
    if (song)
    {
        songs.push_back(song);
        if (songs.size() == 1) currentIterator = songs.begin();
        isSongAdded = true;
    }
    return isSongAdded;
}

bool Playlist::removeSong(int index)
{
    bool isSongRemoved = false;
    if (index <= songs.size())
    {
        std::list<ISong*>::iterator it = songs.begin();
        std::advance(it, index);
        if (it == currentIterator)
        {
            currentIterator = songs.end();
        }
        songs.erase(it);
        if (!songs.empty())
        {
            currentIterator = songs.begin();
        }
        isSongRemoved = true;
    }
    return isSongRemoved;
}

ISong* Playlist::getCurrentSong()
{
    return (currentIterator != songs.end()) ? *currentIterator : nullptr;
}

bool Playlist::nextIterate()
{
    bool nextSong = false;
    if (!songs.empty() || currentIterator != songs.end())
    {
        auto nextIt = std::next(currentIterator);
        if (nextIt != songs.end())
        {
            currentIterator = nextIt;
            nextSong = true;
        }
    }
    return nextSong;
}

bool Playlist::previousIterate()
{
    bool previousSong = false;
    if (!songs.empty() || currentIterator != songs.begin())
    {
        currentIterator = std::prev(currentIterator);
        previousSong = true;
    }
    return previousSong;
}

bool Playlist::moveSong(int fromIndex, int toIndex)
{
    bool move = true;
    if (fromIndex < 0 || toIndex < 0 || fromIndex >= songs.size() || toIndex >= songs.size())
    {
        move = false;
    }
    else if (fromIndex != toIndex)
    {
        auto fromIt = songs.begin();
        std::advance(fromIt, fromIndex);
        ISong* songToMove = *fromIt;
        songs.erase(fromIt);
        auto toIt = songs.begin();
        std::advance(toIt, toIndex);
        songs.insert(toIt, songToMove);
        if (!songs.empty()) currentIterator = songs.begin();
    }
    return move;
}   

const std::list<ISong*>& Playlist::getAllSongs() const
{
    return songs;
}

bool Playlist::resetIterator()
{
    bool resetList = false;
    if (!songs.empty())
    {
        currentIterator = songs.begin();
        resetList = true;
    }
    return resetList;
}
