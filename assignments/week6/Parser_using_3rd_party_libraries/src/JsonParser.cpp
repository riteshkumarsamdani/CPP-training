#include "../include/JsonParser.h"
#include <iostream>

std::string JsonParser::parse(const std::string& content) 
{
    try
    {
        nlohmann::json json = nlohmann::json::parse(content);
        return formatJsonOutput(json);
    } 
    catch (const nlohmann::json::parse_error& e) 
    {
        return "JSON Parse Error: " + std::string(e.what());
    } 
    catch (const std::exception& e) 
    {
        return "Error parsing JSON: " + std::string(e.what());
    }
}

std::string JsonParser::formatJsonOutput(const nlohmann::json& json, int indent) 
{
    std::ostringstream output;
    output << json.dump(indent);
    return output.str();
}
