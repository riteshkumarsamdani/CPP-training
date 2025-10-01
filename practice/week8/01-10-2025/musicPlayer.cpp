#include <SFML/Audio.hpp>
#include <iostream>

int main() {
    // Create a music object
    sf::Music music;

    // Load the WAV file.
    if (!music.openFromFile("blues.00000.wav")) {
        std::cerr << "Error: Failed to load WAV file." << std::endl;
        return -1; // Exit if the file fails to load
    }

    // Play the music
    std::cout << "Playing music from WAV file..." << std::endl;
    music.play();

    // Keep the program running as long as the music is playing
    while (music.getStatus() == sf::Music::Playing) {
        // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "Music playback finished." << std::endl;

    return 0;
}
