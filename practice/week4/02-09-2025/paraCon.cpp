#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    Book(std::string bookTitle, std::string bookAuthor) {
        title = bookTitle;
        author = bookAuthor;
        std::cout << "Parameterized constructor called." << std::endl;
    }
};

int main() {
    Book myBook("1984", "George Orwell"); 
    std::cout << "Title: " << myBook.title << ", Author: " << myBook.author << std::endl;
    return 0;
}
