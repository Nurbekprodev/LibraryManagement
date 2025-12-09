#ifndef BOOK_HPP
#define BOOK_HPP

#include "Item.hpp"
using namespace std;

// Book class (child of Item)
class Book : public Item {
    string author;

public:
    Book(int id, string title, string author, int count);
    void display() const override;
    string serialize() const override;
};

#endif
