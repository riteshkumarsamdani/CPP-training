#include "../../include/ParserHandler.h"
#include "../../include/InputHandler.h"
#include <iostream>

int main() 
{
    ParserHandler* handler = new ParserHandler();
    InputHandler* inputHandler = new InputHandler();
    std::cout << "=== Multi-Format File Parser ===\n";
    std::cout << "Supported formats: JSON, CSV, XML\n\n";
    std::string filePath;
    bool run = true;
    while(run)
    {
        inputHandler->getUserInput("Enter file path to parse (or 'quit'/'q' to exit):", filePath);
        if (filePath == "quit" || filePath == "q") {
            run = false;
            break;
        }
        if (!filePath.empty()) 
        {
            std::cout << "\n";
            try
            {
                bool success = handler->parseFile(filePath);
                if (success) 
                {
                    std::cout << "\nFile parsed successfully!\n";
                } 
                else 
                {
                    std::cout << "\nFailed to parse file.\n";
                }
            }
            catch(const std::string& e)
            {
                std::cerr << e << '\n';
            }
            catch(...)
            {
                std::cerr << "unexpected error occured!!";
                break;
            }
        }
    }
    delete handler;
    delete inputHandler;
    std::cout << "Parser application terminated.\n";
    return 0;
}
