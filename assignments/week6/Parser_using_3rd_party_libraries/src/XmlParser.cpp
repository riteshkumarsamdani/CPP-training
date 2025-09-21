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
        for (tinyxml2::XMLElement* child = root->FirstChildElement(); child != nullptr; child = child->NextSiblingElement()) 
        {
            output << "  Child element: " << child->Name() << "\n";
        }
    } 
    else 
    {
        output << "No root element found.\n";
    }
    return output.str();
}
