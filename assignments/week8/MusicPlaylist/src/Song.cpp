#include "Song.h"

Song::Song(const std::string& id, const std::string& title, const std::string& filePath)
    : id(id), title(title), filePath(filePath) {}

std::string Song::getId() const 
{ 
    return id;
}

std::string Song::getTitle() const
{ 
    return title; 
}

std::string Song::getFilePath() const
{ 
    return filePath; 
}
