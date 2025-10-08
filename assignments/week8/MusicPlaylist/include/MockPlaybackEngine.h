#ifndef MOCK_PLAYBACK_ENGINE_H
#define MOCK_PLAYBACK_ENGINE_H

#include <gmock/gmock.h>
#include "IPlaybackEngine.h"

class MockPlaybackEngine : public IPlaybackEngine 
{
    public:
        MOCK_METHOD(bool, load, (const std::string&), (override));
        MOCK_METHOD(void, play, (), (override));
        MOCK_METHOD(void, pause, (), (override));
        MOCK_METHOD(void, stop, (), (override));
        MOCK_METHOD(bool, isPlaying, (), (const, override));
};

#endif
