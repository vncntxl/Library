#include "Book.h"  
#include <vector>

void showMenu() {
    std::cout << "\n===== LIBRARY MENU ====="
        << "\n1. Add Book"
        << "\n2. List All Books"
        << "\n3. Borrow Book"
        << "\n4. Return Book"
        << "\n5. Exit"
        << "\nEnter choice (1-5): ";
}

int main() {
    std::vector<Book> library;

    // Sample books (like your To-Do list initialization)
    library.emplace_back("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565");
    library.emplace_back("1984", "George Orwell", "9780451524935");

    while (true) {
        showMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: { // Add Book
            std::string title, author, isbn;
            std::cin.ignore();
            std::cout << "Enter title: "; std::getline(std::cin, title);
            std::cout << "Enter author: "; std::getline(std::cin, author);
            std::cout << "Enter ISBN: "; std::getline(std::cin, isbn);
            library.emplace_back(title, author, isbn);
            break;
        }
        case 2: // List Books
            for (const auto& book : library) {
                book.displayDetails();
            }
            break;
        case 3: { // Borrow
            std::string isbn;
            std::cout << "Enter ISBN: ";
            std::cin >> isbn;
            for (auto& book : library) {
                if (book.getISBN() == isbn) {
                    book.borrowBook();
                    break;
                }
            }
            break;
        }
        case 4: { // Return
            std::string isbn;
            std::cout << "Enter ISBN: ";
            std::cin >> isbn;
            for (auto& book : library) {
                if (book.getISBN() == isbn) {
                    book.returnBook();
                    break;
                }
            }
            break;
        }
        case 5: // Exit
            return 0;
        default:
            std::cout << "Invalid choice!" << std::endl;
        }
    }
}