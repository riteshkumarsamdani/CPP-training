#ifndef ISONG_H
#define ISONG_H

#include <string>

class ISong
{
    public:
        virtual ~ISong() = default;
        virtual std::string getId() const = 0;
        virtual std::string getTitle() const = 0;
        virtual std::string getFilePath() const = 0;
};

#endif 
