#include "../include/ParserHandler.h"
#include "../include/JsonParser.h"
#include "../include/CsvParser.h"
#include "../include/XmlParser.h"
#include <string>

bool ParserHandler::parseFile(const std::string& filePath) 
{
    bool status = true;
    std::cout << "Processing file: " << filePath << std::endl;
    std::string error;
    if (!fileExists(filePath))
    {
        throw "Error: File does not exist: " + filePath;
    }
    std::string extension = getFileExtension(filePath);
    if (extension.empty()) 
    {
        throw "Error: Unable to determine file type from extension.";
    }
    IParser* parser = createParser(extension);
    if (!parser) 
    {
        delete parser;
        throw "Error: Unsupported file type: " + extension;
    }
    std::string content = readFile(filePath);
    if (content.empty()) 
    {
        std::cout << "Unable to read file or file is empty.";
        status = false;
    }
    std::string parsedData = parser->parse(content);
    printParsedData(parsedData, extension);
    delete parser;
    return status;
}

std::string ParserHandler::getFileExtension(const std::string& filePath) 
{
    int lastDot = filePath.find_last_of('.'); 
    std::string output;
    if (lastDot == -1) 
    { 
        output = "";
    }
    else
    {
        output = filePath.substr(lastDot + 1);
    }
    return output;
}

IParser* ParserHandler::createParser(const std::string& fileExtension) 
{
    std::string extension = fileExtension;
    std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
    IParser* parser = nullptr;
    if (extension == "json") 
    {
        parser = new JsonParser();
    } 
    else if (extension == "csv") 
    {
        parser = new CsvParser();
    } 
    else if (extension == "xml") 
    {
        parser = new XmlParser();
    }
    return parser;
}

bool ParserHandler::fileExists(const std::string& filePath) 
{
    return std::filesystem::exists(filePath);
}

void ParserHandler::printParsedData(const std::string& data, const std::string& fileType) 
{
    std::cout << "PARSED " << fileType << " DATA" << std::endl;
    std::cout << data << std::endl;
}

std::string ParserHandler::readFile(const std::string& filePath) 
{
    std::ifstream file(filePath);
    std::string output;
    if (!file.is_open()) 
    {
        output = "";
    }
    else
    {
        std::ostringstream buffer;
        buffer << file.rdbuf();
        file.close();
        output = buffer.str();
    }
    return output;
}
