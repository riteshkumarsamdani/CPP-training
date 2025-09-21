#include "../pub/IParser.h"
#include <nlohmann/json.hpp>
#ifndef JSON_PARSER_H
#define JSON_PARSER_H

class JsonParser : public IParser 
{
    public:
        std::string parse(const std::string& content) override;
    private:
        std::string formatJsonOutput(const nlohmann::json& json, int indent = 4);
};

#endif
