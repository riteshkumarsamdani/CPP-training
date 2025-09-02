#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    Book(std::string bookTitle, std::string bookAuthor) {
        title = bookTitle;
        author = bookAuthor;
    }
    Book(const Book& sourceBook) {
        title = sourceBook.title;
        author = sourceBook.author;
        std::cout << "Copy constructor called." << std::endl;
    }
};

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams");
    Book book2 = book1; 
    std::cout << "Book 1: " << book1.title << std::endl;
    std::cout << "Book 2: " << book2.title << std::endl;
    return 0;
}
