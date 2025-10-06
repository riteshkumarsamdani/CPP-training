#ifndef SFML_PLAYBACK_ENGINE_H
#define SFML_PLAYBACK_ENGINE_H

#include "IPlaybackEngine.h"
#include <SFML/Audio.hpp>

class SFMLPlaybackEngine : public IPlaybackEngine
{
    private:
        sf::Music music;
    
    public:
        SFMLPlaybackEngine();
        ~SFMLPlaybackEngine();
        bool load(const std::string& filePath) override;
        bool play() override;
        bool pause() override;
        bool stop() override;
};

#endif
