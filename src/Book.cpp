#include "Book.hpp"

Book::Book(int id, string title, string author, int count)
    : Item(id, title, count), author(author) {}

void Book::display() const {
    cout << "[Book] ID: " << id
         << " | Title: " << title
         << " | Author: " << author
         << " | Available: " << availableCount
         << "\n";
}

string Book::serialize() const {
    return "BOOK," + to_string(id) + "," + title + "," + author + "," +
           to_string(availableCount);
}
