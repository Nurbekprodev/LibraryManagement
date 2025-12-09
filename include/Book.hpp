#ifndef BOOK_HPP
#define BOOK_HPP

#include "Item.hpp"
using namespace std;

// Book class (child of Item)
class Book : public Item {
    string author;

public:
    Book(int id, string title, string author, int count);  // make a book
    void display() const override; // show book info
    string serialize() const override; //save book as text
};

#endif
