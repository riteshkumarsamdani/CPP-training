#ifndef IPLAYBACK_ENGINE
#define IPLAYBACK_ENGINE

#include <string>

class IPlaybackEngine 
{
    public:
        virtual ~IPlaybackEngine() = default;
        virtual bool load(const std::string& filePath) = 0;
        virtual void play() = 0;
        virtual void pause() = 0;
        virtual void stop() = 0;
        virtual bool isPlaying() const = 0;
};

#endif
