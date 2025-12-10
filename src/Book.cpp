#include "Book.hpp"

Book::Book(int id, string title, string author, int count) // book constructor
    : Item(id, title, count), author(author) {}

// show book info
void Book::display() const {
    cout << "[Book] ID: " << id
         << " | Title: " << title
         << " | Author: " << author
         << " | Available: " << availableCount
         << "\n";
}

// convert book to text
string Book::serialize() const {
    return "BOOK," + to_string(id) + "," + title + "," + author + "," +
           to_string(availableCount);
}
