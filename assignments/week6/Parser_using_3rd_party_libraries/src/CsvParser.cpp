#include "../include/CsvParser.h"
#include <string>
#include <sstream>

std::string CsvParser::parse(const std::string& inputContent) 
{
    try 
    {
        std::istringstream input(inputContent);
        rapidcsv::Document document(input);
        return formatCsvOutput(document);
    }
    catch (const std::exception& e) 
    {
        return "CSV Parse Error: " + std::string(e.what());
    }
}

std::string CsvParser::formatCsvOutput(const rapidcsv::Document& document) 
{
    std::ostringstream output;
    output << "--- Parsing CSV file ---\n";
    output << "Successfully parsed CSV data.\n";
    output << "--- Parsed Content ---\n";
    std::vector<std::string> columnNames = document.GetColumnNames();
    std::size_t colCount = columnNames.size();
    std::size_t colIndex = 0;
    while (colIndex < colCount) 
    {
        output << columnNames[colIndex] << "\t";
        ++colIndex;
    }
    output << "\n";
    std::size_t rowCount = document.GetRowCount();
    std::size_t rowIndex = 0;
    while (rowIndex < rowCount) 
    {
        colIndex = 0;
        while (colIndex < colCount) 
        {
            std::string cell = document.GetCell<std::string>(columnNames[colIndex], rowIndex);
            output << cell << "\t";
            ++colIndex;
        }
        output << "\n";
        ++rowIndex;
    }
    return output.str();
}
