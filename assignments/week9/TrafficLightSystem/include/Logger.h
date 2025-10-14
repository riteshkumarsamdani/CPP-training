#ifndef LOGGER_H
#define LOGGER_H

#include "ILogger.h"
#include <iostream>

class Logger : public ILogger
{
    public:
        void log(const std::string& message) override;
};

#endif
