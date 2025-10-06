#ifndef IPLAYBACK_ENGINE
#define IPLAYBACK_ENGINE

#include <string>

class IPlaybackEngine 
{
    public:
        virtual ~IPlaybackEngine() = default;
        virtual bool load(const std::string& filePath) = 0;
        virtual bool play() = 0;
        virtual bool pause() = 0;
        virtual bool stop() = 0;
};

#endif
