#include "MusicSystem.h"
#include "SFMLPlaybackEngine.h"
#include "PlaylistManager.h"
#include "Song.h"
#include "InputHandler.h"
#include <iostream>

void showMainMenu();
void handleViewSongs(IMusicSystem& system);
void handleCreatePlaylist(IMusicSystem& system, InputHandler& input);
void handleManagePlaylists(IMusicSystem& system, InputHandler& input);
void handlePlaybackControl(IMusicSystem& system, InputHandler& input);

int main() 
{
    std::vector<ISong*> songLibrary = 
    {
        new Song("1", "Song One", "Music/blues.00000.wav"),
        new Song("2", "Song Two", "Music/blues.00001.wav"),
        new Song("3", "Song Three", "Music/blues.00002.wav")
    };

    IPlaybackEngine* playbackEngine = new SFMLPlaybackEngine();
    IPlaylistManager* playlistManager = new PlaylistManager();
    MusicSystem system(playbackEngine, playlistManager, songLibrary);

    InputHandler input;
    int choice;
    do {
        showMainMenu();
        input.getUserInput("Enter your choice: ", choice);
    
        switch (choice) {
            case 1: handleViewSongs(system); break;
            case 2: handleCreatePlaylist(system, input); break;
            case 3: handleManagePlaylists(system, input); break;
            case 4: handlePlaybackControl(system, input); break;
            case 5: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid option.\n"; break;
        }
    } 
    while (choice != 5);
    for (ISong* song : songLibrary) delete song;
    return 0;
}

void showMainMenu() {
    std::cout << "\n=== Music System Menu ===\n";
    std::cout << "1. View All Songs\n";
    std::cout << "2. Create Playlist\n";
    std::cout << "3. Manage Playlists\n";
    std::cout << "4. Playback Control\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

void handleViewSongs(IMusicSystem& system) {
    const auto& songs = system.getAllSongs();
    std::cout << "\n--- All Songs ---\n";
    for (int i = 0; i < songs.size(); ++i) {
        std::cout << i << ". " << songs[i]->getTitle() << "\n";
    }
}

void handleCreatePlaylist(IMusicSystem& system, InputHandler& input)
{
    std::string name;
    input.getUserInput("Enter playlist name: ", name);
    if (system.createPlaylist(name))
        std::cout << "Playlist created.\n";
    else
        std::cout << "Playlist already exists.\n";
}

void displayPlaylistMenu()
{
    std::cout << "\n--- Playlist Management ---\n";
    std::cout << "1. View All Playlists\n";
    std::cout << "2. Delete Playlist\n";
    std::cout << "3. Add Song to Playlist\n";
    std::cout << "4. Remove Song from Playlist\n";
    std::cout << "5. View Playlist Contents\n";
    std::cout << "6. Move Song Up/Down\n";
    std::cout << "0. Back to Main Menu\n";
}
void handleManagePlaylists(IMusicSystem& system, InputHandler& input) {
    bool back = false;
    while (!back) {
        int option;
        displayPlaylistMenu();
        input.getUserInput("Enter option: ", option);

        std::string name;
        switch (option) {
            case 1: {
                const auto& playlists = system.getAllPlaylists();
                for (const auto& [name, pl] : playlists)
                    std::cout << "- " << name << "\n";
                break;
            }
            case 2:
                input.getUserInput("Enter playlist name to delete: ", name);
                std::cout << (system.deletePlaylist(name) ? "Deleted.\n" : "Not found.\n");
                break;
            case 3: {
                input.getUserInput("Enter playlist name: ", name);
                handleViewSongs(system);
                int songIndex;
                input.getUserInput("Enter song index to add: ", songIndex);
                const auto& songs = system.getAllSongs();
                if (songIndex >= 0 && songIndex < songs.size())
                    std::cout << (system.addSongToPlaylist(name, songs[songIndex]) ? "Added.\n" : "Failed.\n");
                else
                    std::cout << "Invalid song index.\n";
                break;
            }
            case 4:
                input.getUserInput("Enter playlist name: ", name);
                int index;
                input.getUserInput("Enter song index to remove: ", index);
                std::cout << (system.removeSongFromPlaylist(name, index) ? "Removed.\n" : "Failed.\n");
                break;
            case 5: {
                input.getUserInput("Enter playlist name: ", name);
                Playlist* pl = system.getPlaylist(name);
                if (!pl) break;
                int i = 0;
                for (ISong* song : pl->getAllSongs())
                    std::cout << i++ << ". " << song->getTitle() << "\n";
                break;
            }
            case 6:
            {
                input.getUserInput("Enter playlist name: ", name);
                int fromIdx, toIdx;
                input.getUserInput("Enter current song index: ", fromIdx);
                input.getUserInput("Enter new position index: ", toIdx);
                std::cout << (system.moveSongToPosition(name, fromIdx, toIdx) ? "Moved.\n" : "Failed.\n");
                break;
            }
            case 0: back = true; break;
            default: std::cout << "Invalid option.\n";
        }
    }
}

void displaySubPlaybackMenu()
{
    std::cout << "\n--- Playback Controls ---\n";
    std::cout << "1. Play\n";
    std::cout << "2. Pause\n";
    std::cout << "3. Stop\n";
    std::cout << "4. Next\n";
    std::cout << "5. Previous\n";
    std::cout << "6. Reset\n";
    std::cout << "0. Back to Playback Menu\n";
}

void playbackSubMenu(IMusicSystem& system, InputHandler& input)
{
    bool back = false;
    while (!back) {
        int option;
        displaySubPlaybackMenu();
        input.getUserInput("Enter option: ", option);

        switch (option) {
            case 1: std::cout << (system.play() ? "Playing.\n" : "Failed.\n"); break;
            case 2: std::cout << (system.pause() ? "Paused.\n" : "Failed.\n"); break;
            case 3: std::cout << (system.stop() ? "Stopped.\n" : "Failed.\n"); break;
            case 4: std::cout << (system.next() ? "Next song.\n" : "Failed.\n"); break;
            case 5: std::cout << (system.previous() ? "Previous song.\n" : "Failed.\n"); break;
            case 6: std::cout << (system.reset() ? "Reset.\n" : "Failed.\n"); break;
            case 0: back = true; break;
            default: std::cout << "Invalid option.\n";
        }
    }
}

void handlePlaybackControl(IMusicSystem& system, InputHandler& input)
{
    bool back = false;
    while (!back) {
        int option;
        std::cout << "\n--- Playback Control ---\n";
        std::cout << "1. Play Song from Library\n";
        std::cout << "2. Select & Play Playlist\n";
        std::cout << "0. Back to Main Menu\n";
        input.getUserInput("Enter option: ", option);
        std::string name;
        int index;
        switch (option) {
            case 1: {
                handleViewSongs(system);
                input.getUserInput("Enter song index to play: ", index);
                const auto& songs = system.getAllSongs();
                if (index >= 0 && index < songs.size()) {
                    ISong* song = songs[index];
                    if (song && system.playSong(song)) {
                        std::cout << "Playing: " << song->getTitle() << "\n";
                        playbackSubMenu(system, input);
                    } else {
                        std::cout << "Failed to play song.\n";
                    }
                } else {
                    std::cout << "Invalid index.\n";
                }
                break;
            }
            case 2: {
                input.getUserInput("Enter playlist name: ", name);
                input.getUserInput("Enter song index to start: ", index);
                if (system.selectPlaylist(name, index)) {
                    std::cout << "Playing...\n";
                    playbackSubMenu(system, input);
                } else {
                    std::cout << "Failed to play from playlist.\n";
                }
                break;
            }
            case 0: back = true; break;
            default: std::cout << "Invalid option.\n";
        }
    }
}
