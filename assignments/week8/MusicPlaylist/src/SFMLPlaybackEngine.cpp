#include "SFMLPlaybackEngine.h"

SFMLPlaybackEngine::SFMLPlaybackEngine(){}

SFMLPlaybackEngine::~SFMLPlaybackEngine() = default;

bool SFMLPlaybackEngine::load(const std::string& filePath)
{
    return music.openFromFile(filePath);
}

void SFMLPlaybackEngine::play()
{
    music.play();
}

void SFMLPlaybackEngine::pause()
{
    music.pause();
}

void SFMLPlaybackEngine::stop()
{
    music.stop();
}

bool SFMLPlaybackEngine::isPlaying() const
{
    return music.getStatus() == sf::SoundSource::Status::Playing;
}
