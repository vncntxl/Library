#include "Book.h"  
Book::Book(const std::string& title, const std::string& author, const std::string& ISBN)
    : title(title), author(author), ISBN(ISBN), available(true) {
}

void Book::borrowBook() {
    if (available) {
        available = false;
        std::cout << "Book borrowed successfully!" << std::endl;
    }
    else {
        std::cout << "Error: Book already borrowed!" << std::endl;
    }
}

void Book::returnBook() {
    available = true;
    std::cout << "Book returned successfully!" << std::endl;
}

bool Book::isAvailable() const { return available; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
std::string Book::getISBN() const { return ISBN; }

void Book::displayDetails() const {
    std::cout << "\nTitle: " << title
        << "\nAuthor: " << author
        << "\nISBN: " << ISBN
        << "\nStatus: " << (available ? "Available" : "Borrowed") << std::endl;
}
