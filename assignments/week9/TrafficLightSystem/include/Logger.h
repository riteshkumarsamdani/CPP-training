#ifndef LOGGER_H
#define LOGGER_H

#include "ILogger.h"
#include <iostream>
#include <fstream>

class Logger : public ILogger
{
    public:
        Logger(const std::string& filename);
        ~Logger();
        void log(const std::string& message) override;
        void logToFile(const std::string& message) override;

    private:
        std::ofstream fileStream;
};

#endif
