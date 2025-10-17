#include <iostream>
#include "Logger.h"

void Logger::log(const std::string& message)
{
    std::cout << message << std::endl;
}

Logger::Logger(const std::string& filename)
{
    fileStream.open(filename, std::ios::app);
    if (!fileStream.is_open())
    {
        std::cerr << "Error: Could not open log file " << filename << std::endl;
    }
}

Logger::~Logger()
{
    if (fileStream.is_open())
    {
        fileStream.close();
    }
}

void Logger::logToFile(const std::string& message)
{
    if (fileStream.is_open())
    {
        fileStream << "[LOG] " << message << std::endl;
    }
    else
    {
        std::cout << "[LOG] " << message << std::endl;
    }
}
