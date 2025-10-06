#include "SFMLPlaybackEngine.h"

SFMLPlaybackEngine::SFMLPlaybackEngine(){}

SFMLPlaybackEngine::~SFMLPlaybackEngine() = default;

bool SFMLPlaybackEngine::load(const std::string& filePath)
{
    return music.openFromFile(filePath);
}

bool SFMLPlaybackEngine::play()
{
    bool playMusic = false;
    if (music.getStatus() != sf::SoundSource::Status::Playing)
    {
        music.play();
        playMusic = true;
    }
    return playMusic;
}

bool SFMLPlaybackEngine::pause()
{
    bool isPaused = false;
    if (music.getStatus() == sf::SoundSource::Status::Playing)
    {
        music.pause();
        isPaused= true;
    }
    return isPaused;
}

bool SFMLPlaybackEngine::stop()
{
    music.stop();
    return true;
}

