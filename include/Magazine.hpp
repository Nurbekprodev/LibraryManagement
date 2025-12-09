#ifndef MAGAZINE_HPP
#define MAGAZINE_HPP

#include "Item.hpp"
using namespace std;

class Magazine : public Item {
    int issueNumber;  // issue number

public:
    Magazine(int id, string title, int issue, int count); // make a magazine
    void display() const override; // show magazine info
    string serialize() const override;  // save magazine as text
};

#endif
