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
    Playlist* playlist = playlistManager->getPlaylist(playlistName);
    if (!playlist || !song) return false;
    for (ISong* existing : playlist->getAllSongs())
    {
        if (existing && existing->getId() == song->getId())
        {
            return false; 
        }
    }
    return playlist->addSong(song);
}

bool MusicSystem::removeSongFromPlaylist(const std::string& playlistName, int index)
{
    Playlist* playlist = playlistManager->getPlaylist(playlistName);
    return playlist ? playlist->removeSong(index) : false;
}

bool MusicSystem::moveSongToPosition(const std::string& playlistName, int fromIndex, int toIndex)
{
    Playlist* playlist = playlistManager->getPlaylist(playlistName);
    return playlist ? playlist->moveSong(fromIndex, toIndex) : false;
}


Playlist* MusicSystem::getPlaylist(const std::string& name)
{
    return playlistManager->getPlaylist(name);
}

const std::map<std::string, Playlist*>& MusicSystem::getAllPlaylists() const
{
    return playlistManager->getAllPlaylists();
}

bool MusicSystem::selectPlaylist(const std::string& name, int startIndex)
{
    Playlist* playlist = playlistManager->getPlaylist(name);
    if (!playlist) return false;

    const auto& songs = playlist->getAllSongs();
    if (startIndex < 0 || static_cast<size_t>(startIndex) >= songs.size()) return false;

    auto it = songs.begin();
    std::advance(it, startIndex);
    playlist->reset();
    for (int i = 0; i < startIndex; ++i) playlist->next();

    currentPlaylist = playlist;
    ISong* song = currentPlaylist->getCurrentSong();
    return song && playbackEngine->load(song->getFilePath()) && playbackEngine->play();
}

bool MusicSystem::play()
{
    return playbackEngine->play();
}

bool MusicSystem::pause()
{
    return playbackEngine->pause();
}

bool MusicSystem::stop()
{
    return playbackEngine->stop();
}

bool MusicSystem::playSong(ISong* song)
{
    if (!song) return false;
    auto it = std::find(songLibrary.begin(), songLibrary.end(), song);
    if (it == songLibrary.end()) return false;

    currentPlaylist = nullptr;
    isLibraryMode = true;
    currentLibraryIndex = std::distance(songLibrary.begin(), it);
    return playbackEngine->load(song->getFilePath()) && playbackEngine->play();
}

bool MusicSystem::next()
{
    if (currentPlaylist)
    {
        if (!currentPlaylist->next()) return false;
        ISong* song = currentPlaylist->getCurrentSong();
        return song && playbackEngine->load(song->getFilePath()) && playbackEngine->play();
    } 
    else if (isLibraryMode)
    {
        if (currentLibraryIndex + 1 >= static_cast<int>(songLibrary.size())) return false;
        currentLibraryIndex++;
        ISong* song = songLibrary[currentLibraryIndex];
        return playbackEngine->load(song->getFilePath()) && playbackEngine->play();
    }
    return false;
}

bool MusicSystem::previous()
{
    if (currentPlaylist)
    {
        if (!currentPlaylist->previous()) return false;
        ISong* song = currentPlaylist->getCurrentSong();
        return song && playbackEngine->load(song->getFilePath()) && playbackEngine->play();
    } 
    else if (isLibraryMode)
    {
        if (currentLibraryIndex <= 0) return false;
        currentLibraryIndex--;
        ISong* song = songLibrary[currentLibraryIndex];
        return playbackEngine->load(song->getFilePath()) && playbackEngine->play();
    }
    return false;
}

bool MusicSystem::reset()
{
    if (currentPlaylist)
    {
        if (!currentPlaylist->reset()) return false;
        ISong* song = currentPlaylist->getCurrentSong();
        return song && playbackEngine->load(song->getFilePath()) && playbackEngine->play();
    } 
    else if (isLibraryMode)
    {
        if (songLibrary.empty()) return false;
        currentLibraryIndex = 0;
        ISong* song = songLibrary[currentLibraryIndex];
        return playbackEngine->load(song->getFilePath()) && playbackEngine->play();
    }
    return false;
}

ISong* MusicSystem::getCurrentSong() const
{
    if (currentPlaylist) return currentPlaylist->getCurrentSong();
    if (isLibraryMode && currentLibraryIndex >= 0 && currentLibraryIndex < static_cast<int>(songLibrary.size()))
        return songLibrary[currentLibraryIndex];
    return nullptr;
}
