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
        void play() override;
        void pause() override;
        void stop() override;
        bool isPlaying() const override;
};

#endif
