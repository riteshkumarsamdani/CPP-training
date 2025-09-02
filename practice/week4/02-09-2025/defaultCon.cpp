#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    Book() {
        title = "Unknown";
        author = "Unknown";
        std::cout << "Default constructor called." << std::endl;
    }
};

int main() {
    Book myBook; 
    std::cout << "Title: " << myBook.title << ", Author: " << myBook.author << std::endl;
    return 0;
}
