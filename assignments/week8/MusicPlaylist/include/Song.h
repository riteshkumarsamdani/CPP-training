#ifndef SONG_H
#define SONG_H

#include "ISong.h"

class Song : public ISong 
{
    private:
        std::string id;
        std::string title;
        std::string filePath;
    
    public:
        Song(const std::string& id, const std::string& title, const std::string& filePath);
        std::string getId() const override;
        std::string getTitle() const override;
        std::string getFilePath() const override;
};

#endif 