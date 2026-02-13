#include "../pub/IParser.h"
#include <rapidcsv.h>
#include <sstream>
#ifndef CSV_PARSER_H
#define CSV_PARSER_H

class CsvParser : public IParser 
{
    public:
        std::string parse(const std::string& content) override;
    private:
        std::string formatCsvOutput(const rapidcsv::Document& document);
};

#endif
