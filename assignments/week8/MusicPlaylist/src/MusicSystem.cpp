#include "MusicSystem.h"
#include <iostream>
#include <algorithm>

MusicSystem::MusicSystem(IPlaybackEngine* engine, IPlaylistManager* manager, const std::vector<ISong*>& library)
    : playbackEngine(engine), playlistManager(manager), songLibrary(library), currentPlaylist(nullptr) {}

const std::vector<ISong*>& MusicSystem::getAllSongs() const
{
    return songLibrary;
}

bool MusicSystem::createPlaylist(const std::string& name)
{
    return playlistManager->createPlaylist(name);
}

bool MusicSystem::deletePlaylist(const std::string& name)
{
    return playlistManager->deletePlaylist(name);
}

bool MusicSystem::addSongToPlaylist(const std::string& playlistName, ISong* song)
{
    bool songAdded = false;
    bool isExisting = false;
    IPlaylistNavigator* playlist = playlistManager->getPlaylist(playlistName);
    if (playlist && song)
    {
        for (ISong* existingSong : playlist->getAllSongs())
        {
            if (existingSong->getId() == song->getId())
            {
                isExisting = true;
                break;
            }
        }
        if(!isExisting)
        {
            playlist->addSong(song);
            songAdded = true;
        }
    }
    return songAdded;
}

bool MusicSystem::removeSongFromPlaylist(const std::string& playlistName, int index)
{
    IPlaylistNavigator* playlist = playlistManager->getPlaylist(playlistName);
    return playlist ? playlist->removeSong(index) : false;
}

bool MusicSystem::moveSongToPosition(const std::string& playlistName, int fromIndex, int toIndex)
{
    IPlaylistNavigator* playlist = playlistManager->getPlaylist(playlistName);
    return playlist ? playlist->moveSong(fromIndex, toIndex) : false;
}


IPlaylistNavigator* MusicSystem::getPlaylist(const std::string& name)
{
    return playlistManager->getPlaylist(name);
}

const std::map<std::string, IPlaylistNavigator*>& MusicSystem::getAllPlaylists() const
{
    return playlistManager->getAllPlaylists();
}

bool MusicSystem::selectPlaylist(const std::string& name, int startIndex)
{
    bool success = false;
    IPlaylistNavigator* playlist = playlistManager->getPlaylist(name);
    if (playlist)
    {
        const auto& songs = playlist->getAllSongs();
        if (startIndex >= 0 && (startIndex < songs.size()))
        {
            playlist->resetIterator();
            int iterate = 0;
            while(iterate < startIndex)
            {
                playlist->nextIterate();
                iterate++;
            }
            currentPlaylist = playlist;
            ISong* song = currentPlaylist->getCurrentSong();
            if (song && playbackEngine->load(song->getFilePath()))
            {
                playbackEngine->play();
                success = true;
            }
        }
    }
    return success;
}


bool MusicSystem::playSong()
{
    bool isPlay = false;
    if(!playbackEngine->isPlaying())
    {
        playbackEngine->play();
        isPlay = true;
    }
    return isPlay;
}

bool MusicSystem::pauseSong()
{
    bool isPaused = false;
    if(playbackEngine->isPlaying())
    {
        playbackEngine->pause();
        isPaused = true;
    }
    return isPaused;
}

bool MusicSystem::stopSong()
{
    bool isStopped = false;
    if(playbackEngine->isPlaying())
    {
        playbackEngine->stop();
        isStopped = true;
    }
    return isStopped;
}

bool MusicSystem::playSong(ISong* song)
{
    bool isSongPlayed = false;
    if (song)
    {
        auto it = std::find(songLibrary.begin(), songLibrary.end(), song);
        if (it != songLibrary.end())
        {
            currentPlaylist = nullptr;
            isLibraryMode = true;
            currentLibraryIndex = std::distance(songLibrary.begin(), it);
            if(playbackEngine->load(song->getFilePath()))
            {
                playbackEngine->play();
                isSongPlayed = true;
            }
        }
    }
    return isSongPlayed;
}

bool MusicSystem::playNextSong()
{
    bool playNext = false;
    if (currentPlaylist)
    {
        if (currentPlaylist->nextIterate())
        {
            ISong* song = currentPlaylist->getCurrentSong();
            if(song && playbackEngine->load(song->getFilePath()))
            {
                playbackEngine->play();
                playNext = true;
            }
        }
    } 
    else if (isLibraryMode)
    {
        if (currentLibraryIndex + 1 < songLibrary.size())
        {
            currentLibraryIndex++;
            ISong* song = songLibrary[currentLibraryIndex];
            if(playbackEngine->load(song->getFilePath()))
            {
                playbackEngine->play();
                playNext = true;
            }
        }
    }
    return playNext;
}

bool MusicSystem::playPreviousSong()
{
    bool playPrevious;
    if (currentPlaylist)
    {
        if (currentPlaylist->previousIterate())
        {
            ISong* song = currentPlaylist->getCurrentSong();
            if(song && playbackEngine->load(song->getFilePath()))
            {
                playbackEngine->play();
                playPrevious = true;
            }
        }
    } 
    else if (isLibraryMode)
    {
        if (currentLibraryIndex > 0)
        {
            currentLibraryIndex--;
            ISong* song = songLibrary[currentLibraryIndex];
            if(playbackEngine->load(song->getFilePath()))
            {
                playbackEngine->play();
                playPrevious = true;
            }
        }
    }
    return playPrevious;
}

bool MusicSystem::reset()
{
    bool resetSuccess = false;
    if (currentPlaylist)
    {
        if (currentPlaylist->resetIterator())
        {
            ISong* song = currentPlaylist->getCurrentSong();
            if (song && playbackEngine->load(song->getFilePath()))
            {
                playbackEngine->play();
                resetSuccess = true;
            }
        }
    }
    else if (isLibraryMode)
    {
        if (!songLibrary.empty())
        {
            currentLibraryIndex = 0;
            ISong* song = songLibrary[currentLibraryIndex];
            if (playbackEngine->load(song->getFilePath()))
            {
                playbackEngine->play();
                resetSuccess = true;
            }
        }
    }
    return resetSuccess;
}
