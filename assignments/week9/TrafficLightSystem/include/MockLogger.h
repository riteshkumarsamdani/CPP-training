#ifndef MOCK_LOGGER_H
#define MOCK_LOGGER_H

#include "ILogger.h"
#include <gmock/gmock.h>

class MockLogger : public ILogger
{
    public:
        MOCK_METHOD(void, log, (const std::string& message), (override));
        MOCK_METHOD(void, logToFile, (const std::string& message), (override));
};

#endif
