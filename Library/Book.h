#pragma once
#include <string>
#include <iostream>

class Book {
private:
    std::string title;
    std::string author;
    std::string ISBN;
    bool available;

public:
    Book(const std::string& title, const std::string& author, const std::string& ISBN);
    void borrowBook();
    void returnBook();
    bool isAvailable() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getISBN() const;
    void displayDetails() const;
};
