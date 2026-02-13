#include "../pub/IParser.h"
#include <tinyxml2.h>
#ifndef XML_PARSER_H
#define XML_PARSER_H

class XmlParser : public IParser 
{
    public:
        std::string parse(const std::string& content) override;
    private:
        void formatXmlNode(tinyxml2::XMLNode* node, std::ostringstream& output, int indent);
};

#endif
