#include <string>
#ifndef IPARSER_H
#define IPARSER_H

class IParser 
{
    public:
        virtual ~IParser() = default;
        virtual std::string parse(const std::string& content) = 0;
};

#endif
