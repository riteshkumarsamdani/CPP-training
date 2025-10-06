#ifndef MOCK_PLAYBACK_ENGINE_H
#define MOCK_PLAYBACK_ENGINE_H

#include <gmock/gmock.h>
#include "IPlaybackEngine.h"

class MockPlaybackEngine : public IPlaybackEngine 
{
    public:
        MOCK_METHOD(bool, load, (const std::string&), (override));
        MOCK_METHOD(bool, play, (), (override));
        MOCK_METHOD(bool, pause, (), (override));
        MOCK_METHOD(bool, stop, (), (override));
};

#endif
