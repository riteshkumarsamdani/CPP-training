#include "../include/XmlParser.h"
#include <sstream>
#include <tinyxml2.h>

std::string XmlParser::parse(const std::string& content) 
{
    tinyxml2::XMLDocument document;
    if (document.Parse(content.c_str()) != tinyxml2::XML_SUCCESS) 
    {
        std::ostringstream err;
        err << "Error: Could not parse XML content.\n"
            << "Reason: " << document.ErrorStr();
        return err.str();
    }
    std::ostringstream output;
    output << "Successfully parsed XML content.\n";
    output << "--- Parsed Content ---\n";
    tinyxml2::XMLElement* root = document.RootElement();
    if (root) 
    {
        output << "Root element: " << root->Name() << "\n";
        formatXmlNode(root, output, 2);
    } 
    else 
    {
        output << "No root element found.\n";
    }
    return output.str();
}

void XmlParser::formatXmlNode(tinyxml2::XMLNode* node, std::ostringstream& output, int indent) 
{
    tinyxml2::XMLElement* element = node->ToElement();
    if (element) 
    {
        std::string padding(indent, ' ');
        output << padding << "Element: " << element->Name();

        const char* text = element->GetText();
        if (text) 
        {
            output << " | Value: " << text;
        }
        output << "\n";
    }
    tinyxml2::XMLNode* child = node->FirstChild();
    while (child != nullptr) 
    {
        formatXmlNode(child, output, indent + 2);
        child = child->NextSibling();
    }
}
