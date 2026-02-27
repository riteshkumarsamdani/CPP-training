#ifndef MOCK_SONG_H
#define MOCK_SONG_H

#include <gmock/gmock.h>
#include "ISong.h"

class MockSong : public ISong
{
    public:
        MOCK_METHOD(std::string, getId, (), (const, override));
        MOCK_METHOD(std::string, getTitle, (), (const, override));
        MOCK_METHOD(std::string, getFilePath, (), (const, override));
};

#endif
