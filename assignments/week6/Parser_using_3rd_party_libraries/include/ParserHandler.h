#include "../pub/IParser.h"
#include <iostream>
#ifndef PARSER_HANDLER_H
#define PARSER_HANDLER_H

class ParserHandler {
    public:
        bool parseFile(const std::string& filePath);
        void printParsedData(const std::string& data, const std::string& fileType);

    private:
        IParser* createParser(const std::string& fileExtension);
        std::string getFileExtension(const std::string& filePath);
        std::string readFile(const std::string& filePath);
        bool fileExists(const std::string& filePath);
};

#endif
